#include "src_processor.h"
#include "parameter_handling.h"
#include "elements.h"
#include "parser_tree.h"
#include "utils.h"

extern GUIElement * elements;
//extern std::unordered_map<string, int>* idMaps;
extern std::unordered_map<std::string, int> idMaps[100];


extern vector<ClassContainer*> classes[100];
extern unordered_map<string, int> classMaps[100];
extern vector<PrimitiveType*> primitiveTypes;
extern unordered_map<string, int> primitiveTypeMap;
extern vector<ClassContainer*> defaultClasses;
extern unordered_map<string, int> defaultClassMap;


void ConstructRecursion(SourceTokenContainer * cont, SrcNode * node);

void fillIds(SrcNode * node, SourceDotToken * container)
{
	if(node->text!=0)
	{
		container->PushToken(new SourceStringToken(node));
	}

	if(node->type==NODE_TYPE_ID)
	{
		container->PushIdToken(new SourceIdToken(node));
	}
	else
	{
		for(int i=0;i<node->childrenCount;i++)
		{		
			fillIds(node->children[i],container);
		}
	}
}


SourceDotToken::SourceDotToken(SrcNode * node)
{
	isVarReplaced=false;
	fillIds(node, this);
}
SourceStringToken::SourceStringToken(SrcNode * node)
{
	str=string(node->text);
}
SourceIdToken::SourceIdToken(SrcNode * node)
{
	str=string(node->text);
	isElement=false;
}
SourceExprToken::SourceExprToken(SrcNode * node)
{
	ConstructRecursion(this,node);
}

void SourceExprToken::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}

void SourceAssignmentToken::PushSubNode(SrcNode * node)
{
	nodes.push_back(new SourceExprToken(node));
}
void SourceAssignmentToken::PushOperator(AssignmentOperator op)
{
	ops.push_back(op);
}


void SourceAssignmentToken::Construct(SrcNode* node)
{
	if(node->childrenCount==3)
	{
		this->PushSubNode(node->children[0]);
		AssignmentOperator op;
		op.str=string(node->children[1]->text);
		this->PushOperator(op);
		Construct(node->children[2]);
	}
	else // one child
	{
		this->PushSubNode(node->children[0]);
	}

}

SourceAssignmentToken::SourceAssignmentToken(SrcNode * node)
{
	Construct(node);
}

void SourceDotToken::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}
void SourceDotToken::PushIdToken(SourceIdToken * t)
{
	identifiers.push_back(t);
}
void SourceStatementToken::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}
void SourceHandler::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}


void ConstructRecursion(SourceTokenContainer * cont, SrcNode * node)
{
	bool processChildren=true;
	if(node->type==NODE_TYPE_STATM)
	{
		SourceStatementToken * sToken=new SourceStatementToken();
		cont->PushToken(sToken);
		cont = sToken;
	}
	else if(node->type==NODE_TYPE_ASSIGN)
	{
		cont->PushToken(new SourceAssignmentToken(node));
		processChildren=false;
	}
	else if(node->type==NODE_TYPE_ID)
	{
		cont->PushToken(new SourceIdToken(node));
		processChildren=false;
	}
	else if(node->type==NODE_TYPE_DOT)
	{
		cont->PushToken(new SourceDotToken(node));
		processChildren=false;
	}
	else if(node->text!=0)
		cont->PushToken(new SourceStringToken(node));

	if(processChildren)
	{
		for(int i=0;i<node->childrenCount;i++)
		{
			ConstructRecursion(cont,node->children[i]);
		}
	}
}

SourceHandler* ExprToHandler(SrcNode * node)
{
	SourceHandler * srcHandler= new SourceHandler();
	SourceStatementToken * t=new SourceStatementToken();
	srcHandler->PushToken(t);
	ConstructRecursion(t,node);
	return srcHandler;
}

SourceHandler* SourceToHandler(SrcNode * node)
{
	SourceHandler * srcHandler= new SourceHandler();
	ConstructRecursion(srcHandler,node);
	return srcHandler;
}

void SourceHandler::Print(string& dest)
{
	for(int i=0;i<tokens.size();i++)
		tokens[i]->Print(dest);
	
}
void SourceStringToken::Print(string& dest)
{
	dest+=str;
	if(str==";")
		dest+="\n";
}
void SourceStatementToken::Print(string& dest)
{
	string s;
	/*for(int i=0;i<setGetters.size();i++)
	{
		setGetters[i]->Print(s);
	}*/
	dest+=s;
	for(int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->Print(dest);
	}
}
void SourceIdToken::PrintZeroUpdaters(string& dest)
{
	if(this->isElement)
	{
		//dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
		//"_QML_element"+INTTOSTR(this->elementId)+")";
	}
	else if(this->isVar)
	{
		//dest+="_QVar"+INTTOSTR(this->variableId);
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_QML_element"+INTTOSTR(this->elementId)+")."+this->str+"_Update=0;\n";
	}
}
void SourceIdToken::Print(string& dest)
{
	//this->
	if(this->isElement)
	{
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
		"_QML_element"+INTTOSTR(this->elementId)+")";
	}
	else if(this->isVar)
	{
		//dest+="_QVar"+INTTOSTR(this->variableId);
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_QML_element"+INTTOSTR(this->elementId)+")."+this->str;
	}
	else
		dest+=str;
}
void SourceDotToken::PrintZeroUpdaters(string& dest)
{
	//this->
	if(this->isVarReplaced)
	{
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_QML_element"+INTTOSTR(this->variableId)+")";
		for(int i=0;i<this->isStatic.size();i++)
		{
			if(this->isStatic[i])
			{
				if(isStatic.size()-1==i)
					dest+=string(".")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+"_Update=0;\n";
				else
					dest+=string(".")+identifiers[identifiers.size()-isStatic.size()+i]->GetId();
			}
			else
			{
				if(isStatic.size()-1==i)
				dest+=string(".Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\").SetUpdater(0);\n");
				else
				dest+=string(".Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\")");
			}
		}
		//dest+="_QVar"+INTTOSTR(this->variableId);
		
	}
}
void SourceDotToken::Print(string& dest)
{
	//this->
	if(this->isVarReplaced)
	{
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_QML_element"+INTTOSTR(this->variableId)+")";
		for(int i=0;i<this->isStatic.size();i++)
		{
			if(this->isStatic[i])
			{
				dest+=string(".")+identifiers[identifiers.size()-isStatic.size()+i]->GetId();
			}
			else
			{
				dest+=string(".Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\")");
			}
		}
		//dest+="_QVar"+INTTOSTR(this->variableId);
		
	}
	else
	{
		for(int i=0;i<tokens.size();i++)
		{
			this->tokens[i]->Print(dest);
		}
	}
}
void SourceExprToken::PrintZeroUpdaters(string& dest)
{
	for(int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->PrintZeroUpdaters(dest);
	}
}
void SourceExprToken::Print(string& dest)
{
	for(int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->Print(dest);
	}
}
void SourceAssignmentToken::Print(string& dest)
{
	//this->nodes[nodes.size()-1]->Print(dest);
	this->nodes[0]->Print(dest);

	for(int i=1;i<nodes.size();i++)
	{
		dest+=this->ops[i-1].str;
		this->nodes[i]->Print(dest);
	}
	if(nodes.size()>1)dest+=";\n";
	for(int i=0;i<nodes.size()-1;i++)
	{
		this->nodes[i]->PrintZeroUpdaters(dest);
	}
	/*this->nodes[0]->Print(dest);

	for(int i=1;i<nodes.size();i++)
	{
		dest+=this->ops[i-1].str;
		this->nodes[i]->Print(dest);
	}*/
}

void SourceToken::PrintZeroUpdaters(string&){}

int varId=0;
int lastRightVarId=0;
void ProcessSource(SourceHandler * handler,int treeInd, int currentElementId)
{
	varId=0;
	handler->Process(treeInd,currentElementId);
}

void SourceHandler::Process(int treeInd, int currentElementId)
{
	for(int i=0;i<tokens.size();i++)
	{
		tokens[i]->Process(treeInd,currentElementId,0,true);
	}
}

void SourceToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{

}


void SourceIdToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	bool isOtherId=idMaps[treeInd].count(this->str)!=0;
	int curId=currentElementId;
	isElement=false;
	isVar=false;

	if(isOtherId)
	{
		fileId=treeInd;
		elementId=curId;
		isElement=true;
		//sprintf(str,"(*((GUI_Rootoutput%d *)context->root)->_QML_element%d)",treeInd,curId);
	}
	else
	{
			curId=currentElementId;
			ClassContainer * cont=elements[curId].classContainer;
			PropertyAndType * prop=cont->CheckExistence(this->str);
			if(prop!=0)
			{
		fileId=treeInd;
		elementId=curId;
				//this->variableId=curId;
				//this->isVarReplaced=true;
				isVar=true;
			}
			else
				return;

			/*if(prop!=0)
			{
				//fileId=treeInd;
				//elementId=curId;
				//isElement=true;
				if(isRightVal)
				{
					isVar=true;
			//		lastStatement->PushSetGetter(new GetterFromElement(treeInd,curId,this->str,varId));
					variableId=varId;
					varId++;
				}
				else
				{
					lastStatement->PushSetGetter(new SetterFromElement(treeInd,curId,this->str,lastRightVarId));
				}
			}
			else
			{
				// leave alone. might be user's global
			}*/
	}
}

void SourceDotToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	bool isOtherId=idMaps[treeInd].count(identifiers[0]->GetId())!=0;
	int curId=currentElementId;
	int prevVarId=varId;
	
	fileId=treeInd;
	
	if(isOtherId)
	{
		curId=idMaps[treeInd][identifiers[0]->GetId()];
		
		int cnt=this->identifiers.size();
		int i;
		for(i=1;i<cnt;i++)
		{
			if(identifiers[i]->GetId()==string("parent"))
			{
				curId=elements[curId].parentId;
				if(curId==-1)
				{
					//error
					printf("element has no parent\n");
					getchar();
					exit(0);
				}
			}
			else
				break;
		}

		this->variableId=curId;
		this->isVarReplaced=true;
		ClassContainer * cont=elements[curId].classContainer;


		bool isReference=false;
		bool prevIsPrimitive=false;
		for(;i<cnt;i++)
		{


			if(!isReference)
			{
				if(prevIsPrimitive)//cont==0)
				{
					// error primitive type
					printf("primitive doesnt have members");
					getchar();
					exit(0);
				}
				//check existence
				PropertyAndType * prop=cont->CheckExistence(identifiers[i]->GetId());

				if(prop==0)
				{
					//error does not exist
				}
				string typeName=prop->type;

				// is type a class defined in same file
				if(prop->cont->fileId!=-1 && classMaps[prop->cont->fileId].count(prop->type)>0)
				{
					cont=classes[prop->cont->fileId][classMaps[prop->cont->fileId][prop->type]];
				}
				else
				{
					// is default class
					if(defaultClassMap.count(prop->type)>0)
					{
						cont=defaultClasses[defaultClassMap[prop->type]];
					}
					else
					{
						// is primitive
						prevIsPrimitive=true;
						cont=0;
					}
				}



				if(cont!=0 && cont->isReferencable)
				{
					isReference=true;
				}
				this->isStatic.push_back(true);
				// print t.thing

				
			}
			else
			{
				// print getter
				this->isStatic.push_back(false);

			}
		}
	}
	else
	{
		//PropertyAndType * prop=cont->CheckExistence(identifiers[0]->GetId());

		int cnt=this->identifiers.size();

		int i;
		for(i=0;i<cnt;i++)
		{
			if(identifiers[i]->GetId()==string("parent"))
			{
				curId=elements[curId].parentId;
				if(curId==-1)
				{
					//error
					printf("element has no parent\n");
					getchar();
					exit(0);
				}
			}
			else
				break;
		}
		ClassContainer * cont=elements[curId].classContainer;

		if(cont->CheckExistence(identifiers[0]->GetId())!=0)
		{
			this->variableId=curId;
			this->isVarReplaced=true;
		}
		else
			return; //could be user stuff
		

		bool isReference=false;
		bool prevIsPrimitive=false;
		for(;i<cnt;i++)
		{


			if(!isReference)
			{
				if(prevIsPrimitive)//cont==0)
				{
					// error primitive type
					printf("primitive does doesnt have mmbers");
					getchar();
					exit(0);
				}
				//check existence
				PropertyAndType * prop=cont->CheckExistence(identifiers[i]->GetId());

				if(prop!=0)
				{
					//error does not exist
				}
				string typeName=prop->type;

				// is type a class defined in same file
				if(prop->cont->fileId!=-1 && classMaps[prop->cont->fileId].count(prop->type)>0)
				{
					cont=classes[prop->cont->fileId][classMaps[prop->cont->fileId][prop->type]];
				}
				else
				{
					// is default class
					if(defaultClassMap.count(prop->type)>0)
					{
						cont=defaultClasses[defaultClassMap[prop->type]];
					}
					else
					{
						// is primitive
						prevIsPrimitive=true;
						cont=0;
					}
				}



				if(cont!=0 && cont->isReferencable)
				{
					isReference=true;
				}
				// print t.thing
				this->isStatic.push_back(true);

				
			}
			else
			{
				// print getter
				this->isStatic.push_back(false);

			}
		}
	}
//	this->isVarReplaced=true;
//	this->variableId=varId;

}

void SourceStatementToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	for(int i=0;i<this->tokens.size();i++)
	{
		this->tokens[i]->Process(treeInd,currentElementId,this,isRightVal);
	}
}

void SourceExprToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	for(int i=0;i<this->tokens.size();i++)
	{
		this->tokens[i]->Process(treeInd,currentElementId,lastStatement,isRightVal);
	}
	/*if(isRightVal)
	{
		varId++;
		isVar=true;
		variableId=varId;
		lastStatement->PushSetGetter(new ExprSetter(variableId,this));
	}*/
}

void SourceAssignmentToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	nodes[nodes.size()-1]->Process(treeInd, currentElementId,lastStatement, true);

	
	//lastRightVarId=varId;

	for(int i=nodes.size()-2;i>=0;i--)
	{
		nodes[i]->Process(treeInd, currentElementId,lastStatement, true);
		//nodes[i]->Process(treeInd, currentElementId,lastStatement, false);
	}

}



void SourceStatementToken::PushSetGetter(SetGetter* sg)
{
	setGetters.push_back(sg);
}


GetterFromElement::GetterFromElement(int fileId, int elementId, string propName, int getToId)
{
	this->fileId=fileId;
	this->elementId=elementId;
	this->propName=propName;
	this->getToId=getToId;
}

GetterFromVar::GetterFromVar(int srcId, string propName, int getToId)
{
	this->srcId=srcId;
	this->propName=propName;
	this->getToId=getToId;
}

SetterFromElement::SetterFromElement(int fileId, int elementId, string propName, int setFromId)
{
	this->fileId=fileId;
	this->elementId=elementId;
	this->propName=propName;
	this->setFromId=setFromId;
}


SetterFromVar::SetterFromVar(int srcId, string propName, int setFromId)
{
	this->srcId=srcId;
	this->propName=propName;
	this->setFromId=setFromId;
}

string SourceIdToken::GetId()
{
	return this->str;
}

void GetterFromElement::Print(string& dest)
{
	dest+=string("QEGET(")
		+"(*((CQMLGUI::Rootoutput"+INTTOSTR(fileId)+"*)context->root)->"
		+"_QML_element"+INTTOSTR(elementId)+")"
		+","
		+"\""+propName+"\""
		+","
		+"_QVar"+INTTOSTR(getToId)
		+")\n";
}



void GetterFromVar::Print(string& dest)
{
	dest+=string("QVGET(")
		+"_QVar"+INTTOSTR(srcId)
		+","
		+"\""+propName+"\""
		+","
		+"_QVar"+INTTOSTR(getToId)
		+")\n";
}

void SetterFromElement::Print(string& dest)
{
	dest+=string("QESET(")
		+"(*((CQMLGUI::Rootoutput"+INTTOSTR(fileId)+"*)context->root)->"
		+"_QML_element"+INTTOSTR(elementId)+")"
		+","
		+"\""+propName+"\""
		+","
		+"_QVar"+INTTOSTR(this->setFromId)
		+")\n";
}

void SetterFromVar::Print(string& dest)
{
	dest+=string("QVSET(")
		+"_QVar"+INTTOSTR(srcId)
		+","
		+"\""+propName+"\""
		+","
		+"_QVar"+INTTOSTR(setFromId)
		+")\n";
}

ExprSetter::ExprSetter(int v, SourceExprToken* t)
{
	variableId=v;
	token=t;
}

void ExprSetter::Print(string& dest)
{
	string s("");

	s+=string("_QVar") + INTTOSTR(variableId) + "=";
	token->Print(s);
	s+=";\n";
	dest+=s;
}

