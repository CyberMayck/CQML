#include "parameter_handling.h"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
//#include "string.h"

static unsigned long crc32_tab[] = {
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
	0xe963a535, 0x9e6495a3,	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
	0xf3b97148, 0x84be41de,	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,	0x14015c4f, 0x63066cd9,
	0xfa0f3d63, 0x8d080df5,	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,	0x35b5a8fa, 0x42b2986c,
	0xdbbbc9d6, 0xacbcf940,	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
	0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,	0x76dc4190, 0x01db7106,
	0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
	0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
	0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
	0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
	0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
	0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
	0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
	0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
	0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
	0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
	0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
	0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
	0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
	0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
	0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
	0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

unsigned long CRC32(const char * str)
{
	const char *p;
	unsigned long crc =0xffffffff;
	int size=strlen(str);
	p = str;
	crc = crc ^ ~0U;

	while (size--)
		crc = crc32_tab[(crc ^ *p++) & 0xFF] ^ (crc >> 8);

	return crc ^ ~0U;
}

ClassContainer::ClassContainer(string str, int fileId, int classID)
{
	this->ancestor=0;
	this->className=str;
	this->classHash=CRC32(str.c_str());
	this->fileId=fileId;
	this->classID=classID;
}

void ClassContainer::AddProp(PropertyAndType prop)
{
	prop.nameHash=CRC32(prop.name.c_str());
	prop.cont=this;
	this->props.push_back(prop);
}

void ClassContainer::AddHandler(HandlerAndType handler)
{
	this->handlers.push_back(handler);
}

void ClassContainer::SetAncestor(ClassContainer * ancestor)
{
	this->ancestor=ancestor;
}

bool PropertyAndType::IsReference()
{
	return '*'==type[type.length()-1];
}

ClassContainer * ClassContainer::GetAncestor()
{
	return this->ancestor;
}
PropertyAndType* ClassContainer::CheckExistence(string s)
{
	for(int i=0;i<props.size();i++)
	{
		if(props[i].name==s)
		{
			return &props[i];
		}
	}
	if(ancestor!=0)
		return ancestor->CheckExistence(s);
	return 0;
}

HandlerAndType* ClassContainer::CheckHExistence(string s)
{
	for(int i=0;i<handlers.size();i++)
	{
		if(handlers[i].name==s)
		{
			return &handlers[i];
		}
	}
	if(ancestor!=0)
		return ancestor->CheckHExistence(s);
	return 0;
}

vector<ClassContainer*> defaultClasses;
unordered_map<string, int> defaultClassMap;


vector<PrimitiveType*> primitiveTypes;
unordered_map<string, int> primitiveTypeMap;

vector<ClassContainer*> classes[100];
unordered_map<string, int> classMaps[100];

int totalClassCnt=0;

void registerStruct(const char* name, const char* parent);
void registerPrimitive(const char* name);
void parserDeclare(const char* type, const char* name, const char* value);
void parserDeclareFunc(const char* , const char* , const char*, const char * s);
#define CQML_PARSER
#include "..\CQML\struct_definition_macros.h"

ClassContainer * curCont;

void registerPrimitive(const char* name)
{
	string s=string(name);
	PrimitiveType * cont=new PrimitiveType(s);
	primitiveTypeMap[s]=primitiveTypes.size();
	primitiveTypes.push_back(cont);
}

PrimitiveType::PrimitiveType(string s)
{
	name=s;
}

void registerStruct(const char* name, const char* parent)
{
	string s=string(name);
	ClassContainer * cont= new ClassContainer(s,-1,totalClassCnt++);
	defaultClassMap[s]=defaultClasses.size();
	defaultClasses.push_back(cont);

	curCont=cont;
	cont->isReferencable=false;

	if(parent!=0)
	{
		string sp=string(parent);
		cont->SetAncestor(defaultClasses[defaultClassMap[sp]]);

		ClassContainer * ancestor= cont->GetAncestor();
		while(ancestor!=0)
		{
			cont->isReferencable=ancestor->isReferencable;

			ancestor=ancestor->GetAncestor();

		}
	}
}

void registerStructRef(const char* name, const char* parent)
{
	string s=string(name);
	ClassContainer * cont= new ClassContainer(s,-1,totalClassCnt++);
	defaultClassMap[s]=defaultClasses.size();
	defaultClasses.push_back(cont);

	curCont=cont;

	if(parent!=0)
	{
		string sp=string(parent);
		cont->SetAncestor(defaultClasses[defaultClassMap[sp]]);
	}
	cont->isReferencable=true;
}


void parserDeclareFunc(const char* type, const char* name, const char* value, const char* args)
{
	//M(int, MousePressed, 0, GUI_Element*, int, int, int) 
	string sType=string(type);
	string sName=string(name);

	string sArgs=string(args);

	ClassContainer * cont= curCont;
	HandlerAndType temp;
	temp.name=name;
	temp.returnType=type;

	vector<string> arguments;

	int prevInd=0;
	int n_args=0;
	for(int i=0,j=sArgs.length();i<j;i++)
	{
		if(sArgs[i]==',')
		{
			arguments.push_back(sArgs.substr(prevInd,i-prevInd));
			prevInd=i+1;
		}
	}
	arguments.push_back(sArgs.substr(prevInd,sArgs.length()-prevInd));

	//va_list ap;
    //va_start(ap, n_args);

    for(int i = 0; i < n_args; i++)
	{
		//const char* s = va_arg(ap, const char*);
		string str=arguments[i];//string(s);
		int spaceInd=-1;
		bool nonSpaceFound=false;
		for(int j=str.length()-1;j>=0;j--)
		{
			if(str[j]==' ' && nonSpaceFound)
			{
				spaceInd=j;
				break;
			}
			else
			{
				nonSpaceFound=true;
			}
		}
		if(spaceInd!=-1)
		{
			string s1 = str.substr(0,spaceInd);
			string s2 = str.substr(spaceInd+1,str.length()-spaceInd-1);
		//	string s2 = string.substr
			temp.paramTypes.push_back(s1);
			temp.paramNames.push_back(s2);
		}
		else
		{
			temp.paramTypes.push_back(str);
			temp.paramNames.push_back(string(""));
		}

    }
    //va_end(ap);

	cont->AddHandler(temp);

}

void parserDeclare(const char* type, const char* name, const char* value)
{
	string sType=string(type);
	string sName=string(name);

	ClassContainer * cont= curCont;

	PropertyAndType temp;
	temp.name=name;
	temp.type=type;

	cont->AddProp(temp);
}

void PrintHashTab(FILE * file, int classID, PerfectHashData * data)
{
	fprintf(file,"data=&hashTabs[%d]\n",classID);
	fprintf(file,"InitHashTab(&data,%d,%d);\n",data->n,data->m);
	for(int i=0;i<data->m;i++)
	{
		fprintf(file,"data->keys[%d]=(char *)malloc(sizeof(char) * %d);\n",i,data->keys[i].length()+1);
		fprintf(file,"strcpy(data->keys[%d],\"%s\");\n",i,data->keys[i].c_str());
	}
	fprintf(file,"\n");
	for(int i=0;i<data->m;i++)
	{
		fprintf(file,"data->T1[%d]=%d;\n",i,data->T1[i]);
	}
	fprintf(file,"\n");
	for(int i=0;i<data->m;i++)
	{
		fprintf(file,"data->T2[%d]=%d;\n",i,data->T2[i]);
	}
	fprintf(file,"\n");
	for(int i=0;i<data->n;i++)
	{
		fprintf(file,"data->g[%d]=%d;\n",i,data->g[i]);
	}
	fprintf(file,"\n\n");

}

void PrintClassHashTabs(FILE * file, int classCnt)
{
	int classID=0;
	PerfectHashData * data;
	
	fprintf(file,"void InitHashTabs(ClassHashTable * hashTabs)\n{\n");
	fprintf(file,"ClassHashTable * data;");

	int size=defaultClasses.size();
	for(int i=0;i<classCnt;i++)
	{
		size+=classes[i].size();
	}
	fprintf(file,"InitClassesSize(%d);\n\n",size);

	
	PrintClassTabs(file, classCnt);



	for(int i=0;i<defaultClasses.size();i++)
	{
		data=defaultClasses[i]->hashData;
		PrintHashTab(file,classID,data);
		classID++;
	}
	for(int j=0;j<classCnt;j++)
	{
		for(int i=0;i<classes[j].size();i++)
		{
			data=classes[j][i]->hashData;
			PrintHashTab(file,classID,data);
			classID++;
		}
	}
	fprintf(file,"}\n\n");
}

void PrintClassTabs(FILE * file, int classCnt)
{
	fprintf(file,"\n //PrintClassTabs()\n");

	//return;
	int ind=0;
	int pInd=0;
	ClassContainer * c;
	for(int i=0;i<defaultClasses.size();i++)
	{
		c= defaultClasses[i]->GetAncestor();
		if(c==0)
			pInd=-1;
		else
			pInd=c->classID;
		fprintf(file,"InitAttribCnt(%d,%d,%d);\n",ind,defaultClasses[i]->props.size(),pInd);
		ind++;
	}
	for(int j=0;j<classCnt;j++)
	{
		for(int i=0;i<classes[j].size();i++)
		{
			c= classes[j][i]->GetAncestor();

			if(c==0)
				pInd=-1;
			else
				pInd=c->classID;
			fprintf(file,"InitAttribCnt(%d,%d,%d);\n",ind,classes[j][i]->props.size(),pInd);
			ind++;
		}
	}
	ind=0;

	

	
	for(int i=0;i<defaultClasses.size();i++)
	{
		for(int k=0;k<defaultClasses[i]->props.size();k++)
		{
			PropertyAndType& p=defaultClasses[i]->props[k];
			
			fprintf(file,"AddAttribute(%d,%d,offsetof(%s,%s),\"%s\",member_size(%s,%s));\n",
				ind,p.nameHash,p.cont->className.c_str(),p.name.c_str(),p.type.c_str(),p.cont->className.c_str(),p.name.c_str());
		}
		ind++;
	}

	for(int j=0;j<classCnt;j++)
	{
		for(int i=0;i<classes[j].size();i++)
		{
			for(int k=0;k<classes[j][i]->props.size();k++)
			{
				PropertyAndType& p=classes[j][i]->props[k];
			
				fprintf(file,"AddAttribute(offsetof(%s,%s),\"%s\",member_size(%s,%s));\n",
					ind,p.nameHash,p.cont->className.c_str(),p.name.c_str(),p.type.c_str(),p.cont->className.c_str(),p.name.c_str());
			}
			ind++;
		}
	}
	fprintf(file,"\n");

}

int processBasicTypes()
{
	DefaultDeclaration();
	return 1;
	
	FILE *file;
	file = fopen("basic_types.cfg","r");
	if (file == NULL)
	{
		perror ("Error opening file basic_types.cfg");
		exit(-1);
	}
	char str [256];
	
	bool hasAncestor=false;
	ClassContainer * cont=0;
	while(fgets(str, 256, file)!=NULL)
	{
		if(str[0]=='@')
		{
			if(cont!=0)
			{
				//close prev class
				hasAncestor=false;
			}
			string s=string(str);
			s=s.substr(1,s.length()-2);
			cont= new ClassContainer(s,-1, totalClassCnt++);
			defaultClassMap[string(s)]=defaultClasses.size();
			defaultClasses.push_back(cont);
			//open class
		}
		else if(str[0]=='$')
		{
			//ancestor
			if(hasAncestor)
			{
				perror("Multiple Ancestry");
				exit(-1);
			}
			hasAncestor=true;
			string s=string(str);
			s=s.substr(1,s.length()-2);
			cont->SetAncestor(defaultClasses[defaultClassMap[s]]);
		}
		else if(str[0]=='#')
		{
			string s=string(str);
			string type;
			string name;
			bool splitFound=false;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]==' ')
				{
					type = s.substr(1,i-1);
					name = s.substr(i+1,s.length()-i-2);
					splitFound=true;
					break;
				}
			}
			if(splitFound==false)
			{
				perror("syntaxError in basic_type.cfg");
				exit(-1);
			}

			PropertyAndType temp;
			temp.name=name;
			temp.type=type;

			cont->AddProp(temp);
			// calc hash?
		}
	}
	fclose(file);
	return 1;
}

