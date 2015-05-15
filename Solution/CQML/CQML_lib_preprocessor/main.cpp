#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>


#include "parameter_handling.h"


extern vector<ClassContainer*> defaultClasses;
extern unordered_map<string, int> defaultClassMap;

extern vector<PrimitiveType*> primitiveTypes;
extern unordered_map<string, int> primitiveTypeMap;

extern int totalClassCnt;

FILE *file;


/**
 * Function for printing main source file.
 * Prints main source file which includes generated Get and Updates methods, and also hash functions initialization.
 */
void makeMainSource()
{
	fopen_s(&file,"preparser_output.cpp","w");
	
	fprintf(file,"// print default constructors;\n");
	for(unsigned int i=0;i<defaultClasses.size();i++)
	{
		ClassContainer * cont =defaultClasses[i];
		fprintf(file,"CQMLGUI::%s::%s()\n{\n",cont->className.c_str(),cont->className.c_str());
		
		fprintf(file,"\tclassID=%d;\n",cont->classID);

		ClassContainer * parCont=cont;

		{
			for(unsigned int j=0;j<parCont->props.size();j++)
			{
				if(parCont->props[j].IsPrimitive())
				{
					fprintf(file,"\t%s=%s;\n",parCont->props[j].name.c_str(), parCont->props[j].value.c_str());
				}
				else if(parCont->props[j].IsReference())
				{
					fprintf(file,"\t%s=%s;\n",parCont->props[j].name.c_str(), parCont->props[j].value.c_str());
				
				}
				if(!parCont->props[j].isDefault)
				{
					fprintf(file,"\t%s_Update=0;\n",parCont->props[j].name.c_str());
					fprintf(file,"\t%s_context=0;\n",parCont->props[j].name.c_str());
				}
			}
			for(unsigned int j=0;j<parCont->handlers.size();j++)
			{
					fprintf(file,"\t%s=0;\n",parCont->handlers[j].name.c_str());
					fprintf(file,"\t%s_context=0;\n",parCont->handlers[j].name.c_str());
			}
		}
		fprintf(file,"\tInit();\n");
		
		fprintf(file,"}\n");
	}

	
	for(unsigned int i=0;i<defaultClasses.size();i++)
	{
		fprintf(file,"CQMLObject* CQMLGUI::%s::Copy()\n",defaultClasses[i]->className.c_str());
		
		fprintf(file,"{\n");
		fprintf(file,"\treturn new CQMLGUI::%s(*this);\n",defaultClasses[i]->className.c_str());
		fprintf(file,"}\n\n");
	}
	
	for(unsigned int i=0;i<defaultClasses.size();i++)
	{
		fprintf(file,"VariantRef CQMLGUI::%s::Get(const char* s)\n{\n",defaultClasses[i]->className.c_str());
		
		fprintf(file,"\tint hash=GetHash(classID,s);\n");
		fprintf(file,"\tif(hash<0) \n\t{\n\t\tthrow(0); \n\t\treturn VariantRef();\n\t}\n");
		fprintf(file,"\tswitch(hash)\n\t{\n");
		PerfectHashData * hashData = defaultClasses[i]->hashData;
		for(int j=0;j<hashData->m;j++)
		{
			PropertyAndType * prop=defaultClasses[i]->CheckExistence(hashData->keys[j]);

			fprintf(file,"\tcase %d:\n",j);
			if(prop->IsPrimitive())
				fprintf(file,"\t\treturn VariantRef(%s,&%s_Update);\n",hashData->keys[j].c_str(),hashData->keys[j].c_str());
			else
			{
				ClassContainer * tCont=GetDefaultClassContainer(prop->type);
				//
				//if(!tCont)
				//	continue;
				if(tCont->isReferencable)
				{
					fprintf(file,"\t\treturn VariantRef((CQMLObject**)&%s,&%s_Update);\n",hashData->keys[j].c_str(),hashData->keys[j].c_str());
				}
				else
				{
					fprintf(file,"\t\treturn VariantRef((CQMLObject*)&%s,&%s_Update);\n",hashData->keys[j].c_str(),hashData->keys[j].c_str());
				}
			}
		}
		
		fprintf(file,"\tdefault: break;\n");
		fprintf(file,"\t}\n");
		
		fprintf(file,"\treturn VariantRef();\n");

		fprintf(file,"}\n");
	}
	
	fprintf(file, "using namespace CQMLGUI;\n");
	for(unsigned int i=0;i<defaultClasses.size();i++)
		{
			ClassContainer * cont=defaultClasses[i];
			ClassContainer * parentCont=cont->GetAncestor();
			if(defaultClasses[i]->isReferencable && parentCont)
			{
				fprintf(file, "void %s::Update()\n{\n",cont->className.c_str());
				
				fprintf(file, "\tif(!enabled)\n\t\treturn;\n");
			
				for(unsigned int j=0;j<cont->props.size();j++)
				{
					PropertyAndType * prop = &cont->props[j];
					if(prop->IsPrimitive())
					{
						fprintf(file, "\tif(%s_Update)%s_Update",prop->name.c_str(),prop->name.c_str());
						fprintf(file, "(%s_context);\n",prop->name.c_str()); 
					}
					else
					{
						ClassContainer * tCont=GetDefaultClassContainer(prop->type);
						
						if(tCont->isReferencable)
						{
							fprintf(file, "\tif(%s_Update)%s_Update",prop->name.c_str(),prop->name.c_str());
							fprintf(file, "(%s_context);\n",prop->name.c_str()); 
						}
						else
						{
							// non referencable struct
							fprintf(file, "\tif(%s_Update)%s_Update",prop->name.c_str(),prop->name.c_str());
							fprintf(file, "(%s_context);\n",prop->name.c_str()); 
							fprintf(file, "\telse\n\t{\n");

							for(unsigned int k=0;k<tCont->props.size();k++)
							{
								const char * tName=tCont->props[k].name.c_str();
								fprintf(file, "\t\tif(%s.%s_Update)%s.%s_Update",prop->name.c_str(),tName,prop->name.c_str(),tName);
								fprintf(file, "(%s.%s_context);\n",prop->name.c_str(),tName); 
							}

							fprintf(file, "\t}\n");
				
						}
					}
				}


				fprintf(file, "\t %s::Update();\nDefaultUpdate();\n",parentCont->className.c_str());
				fprintf(file, "}\n");
			}
		}

	
	PrintDefaultClassHashTabs(file);
	PrintDefaultValueTypeAssignment(file);

	fclose(file);
}


/**
 * main function
 *
 * @return returns 0
 */
int main()
{
	processBasicTypes();

	
	MakeAllHashes();
	makeMainSource();

	return 0;
}
