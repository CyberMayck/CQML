#include "src_processor.h"
#include "parameter_handling.h"
#include "elements.h"
#include "parser_tree.h"
#include "utils.h"

extern GUIElement * elements;
//extern std::unordered_map<string, int>* idMaps;
extern std::unordered_map<std::string, int> idMaps[100];


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
	if(node->text!=0)
		cont->PushToken(new SourceStringToken(node));
	if(node->type==NODE_TYPE_STATM)
	{
		SourceStatementToken * sToken=new SourceStatementToken();
		cont->PushToken(sToken);
		cont = sToken;
	}
	if(node->type==NODE_TYPE_ASSIGN)
	{
		cont->PushToken(new SourceAssignmentToken(node));
		processChildren=false;
	}
	if(node->type==NODE_TYPE_ID)
	{
		cont->PushToken(new SourceIdToken(node));
		processChildren=false;
	}
	if(node->type==NODE_TYPE_DOT)
	{
		cont->PushToken(new SourceDotToken(node));
		processChildren=false;
	}

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
}
void SourceStatementToken::Print(string& dest)
{
	string s;
	for(int i=0;i<setGetters.size();i++)
	{
		setGetters[i]->Print(s);
	}
	dest+=s;
	for(int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->Print(dest);
	}
	/*for(int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->Print(dest);
	}*/
}
void SourceIdToken::Print(string& dest)
{
	//this->
	if(this->isElement)
	{
		dest+="(*((GUI_Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
		"_QML_element"+INTTOSTR(this->elementId)+")";
	}
	else if(this->isVar)
	{
		dest+="_QVar"+INTTOSTR(this->variableId);
	}
	else
		dest+=str;
}
void SourceDotToken::Print(string& dest)
{
	if(this->isVarReplaced)
	{
		dest+="_QVar"+INTTOSTR(this->variableId);
	}
	else
	{
		for(int i=0;i<tokens.size();i++)
		{
			this->tokens[i]->Print(dest);
		}
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
	/*this->nodes[0]->Print(dest);

	for(int i=1;i<nodes.size();i++)
	{
		dest+=this->ops[i-1].str;
		this->nodes[i]->Print(dest);
	}*/
}

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
				//fileId=treeInd;
				//elementId=curId;
				//isElement=true;
				if(isRightVal)
				{
					isVar=true;
					lastStatement->PushSetGetter(new GetterFromElement(treeInd,curId,this->str,varId));
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
			}
	}
}

void SourceDotToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	bool isOtherId=idMaps[treeInd].count(identifiers[0]->GetId())!=0;
	int curId=currentElementId;
	int prevVarId=varId;
	
	if(isOtherId)
	{
		curId=idMaps[treeInd][identifiers[0]->GetId()];
		
		int cnt=this->identifiers.size();
		for(int i=1;i<cnt;i++)
		{
			if(isRightVal || i<cnt-1)
			{
				prevVarId=varId;
				varId++;
				if(i==1)
		lastStatement->PushSetGetter(new GetterFromElement(treeInd,curId,identifiers[i]->GetId(),varId));
					//ap.addGetter(std::string(str),std::string(node->text),varId);
				else
		lastStatement->PushSetGetter(new GetterFromVar(prevVarId,identifiers[i]->GetId(),varId));
					//ap.addGetter(prevVarId,std::string(node->text),varId);
			}
			else
			{
				if(i==1)
		lastStatement->PushSetGetter(new SetterFromElement(treeInd,curId,identifiers[i]->GetId(),lastRightVarId));
					//ap.addSetter(std::string(str),std::string(node->text),lastVar);
				else
		lastStatement->PushSetGetter(new SetterFromVar(varId,identifiers[i]->GetId(),lastRightVarId));
					//ap.addSetter(prevVarId,std::string(node->text),lastVar);
			}
		}
	}
	else
	{
		ClassContainer * cont=elements[curId].classContainer;
		PropertyAndType * prop=cont->CheckExistence(identifiers[0]->GetId());
		//PropertyAndType * prop=elements[curId].classContainer->CheckExistence(identifiers[0]->GetId());
		int cnt=this->identifiers.size();

		if(prop!=0)
		{
			//start from this
			// if this
			for(int i=0;i<cnt;i++)
			{
				if(isRightVal || i<cnt-1)
				{
				prevVarId=varId;
				varId++;
					if(i==0)
		lastStatement->PushSetGetter(new GetterFromElement(treeInd,curId,identifiers[i]->GetId(),varId));
					//ap.addGetter(std::string(str),std::string(node->text),varId);
				else
		lastStatement->PushSetGetter(new GetterFromVar(prevVarId,identifiers[i]->GetId(),varId));
					//ap.addGetter(prevVarId,std::string(node->text),varId);
				}
				else
				{
				if(i==0)
		lastStatement->PushSetGetter(new SetterFromElement(treeInd,curId,identifiers[i]->GetId(),lastRightVarId));
					//ap.addSetter(std::string(str),std::string(node->text),lastVar);
				else
		lastStatement->PushSetGetter(new SetterFromVar(varId,identifiers[i]->GetId(),lastRightVarId));
					//ap.addSetter(prevVarId,std::string(node->text),lastVar);
				}
			}
		}
		else
		{
			return;
		}
	}
	this->isVarReplaced=true;
	this->variableId=varId;

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
	if(isRightVal)
	{
		varId++;
		isVar=true;
		variableId=varId;
		lastStatement->PushSetGetter(new ExprSetter(variableId,this));
	}
}

void SourceAssignmentToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	//SrcApendix * ap=node->apendix;
	nodes[nodes.size()-1]->Process(treeInd, currentElementId,lastStatement, true);

	
	//printSubnodesToStr(node,expStr);
	//ap->addExpr(varId,expStr);
	//varId++;

	lastRightVarId=varId;

	for(int i=nodes.size()-2;i>=0;i--)
	{
		nodes[i]->Process(treeInd, currentElementId,lastStatement, false);
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
		+"(*((GUI_Rootoutput"+INTTOSTR(fileId)+"*)context->root)->"
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
		+"(*((GUI_Rootoutput"+INTTOSTR(fileId)+"*)context->root)->"
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
	s+="\n";
	dest+=s;
}

