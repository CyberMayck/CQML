#include "src_processor.h"
#include "parameter_handling.h"
#include "elements.h"
#include "parser_tree.h"
#include "utils.h"

extern GUIElement * elements;

extern std::unordered_map<std::string, int> idMaps[100];


extern vector<ClassContainer*> classes[100];
extern unordered_map<string, int> classMaps[100];
extern vector<PrimitiveType*> primitiveTypes;
extern unordered_map<string, int> primitiveTypeMap;
extern vector<ClassContainer*> defaultClasses;
extern unordered_map<string, int> defaultClassMap;


void ConstructRecursion(SourceTokenContainer * cont, SrcNode * node);

/**
 * Puts ids into arrays in form of strigns
 * 
 *
 * @param source node
 * @param token with id tokens
 */
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


/**
 * Constructor.
 * Creates dot token from syntax tree node
 *
 * @param syntax tree node
 */
SourceDotToken::SourceDotToken(SrcNode * node)
{
	isVarReplaced=false;
	fillIds(node, this);
}
/**
 * Constructor.
 * Creates string token from syntax tree node
 *
 * @param syntax tree node
 */
SourceStringToken::SourceStringToken(SrcNode * node)
{
	str=string(node->text);
}
/**
 * Constructor.
 * Creates ID token from syntax tree node
 *
 * @param syntax tree node
 */
SourceIdToken::SourceIdToken(SrcNode * node)
{
	str=string(node->text);
	isElement=false;
}
/**
 * Constructor.
 * Creates expression token from syntax tree node
 *
 * @param syntax tree node
 */
SourceExprToken::SourceExprToken(SrcNode * node)
{
	ConstructRecursion(this,node);
}

/**
 * Pushes source token into expression token
 * 
 *
 * @param source token
 */
void SourceExprToken::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}

/**
 * Pushes new expression token created from syntax tree node into assignement token
 * 
 *
 * @param syntax tree node
 */
void SourceAssignmentToken::PushSubNode(SrcNode * node)
{
	nodes.push_back(new SourceExprToken(node));
}
/**
 * Pushes assingment operator to assignment token
 * 
 *
 * @param operator
 */
void SourceAssignmentToken::PushOperator(AssignmentOperator op)
{
	ops.push_back(op);
}


/**
 * Constructs assignment token from syntax tree node.
 * 
 *
 * @param  syntax tree node.
 */
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

/**
 * Constructor.
 * Creates source assignment token from syntax tree node.
 *
 * @param syntax tree node.
 */
SourceAssignmentToken::SourceAssignmentToken(SrcNode * node)
{
	Construct(node);
}

/**
 * Pushes source token to statement token
 * 
 *
 * @param pushed token
 */
void SourceDotToken::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}
/**
 * Pushes ID token to dot token
 * 
 *
 * @param pushed token
 */
void SourceDotToken::PushIdToken(SourceIdToken * t)
{
	identifiers.push_back(t);
}
/**
 * Pushes source token to statement token
 * 
 *
 * @param pushed token
 */
void SourceStatementToken::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}
/**
 * Pushes source token to handler
 * 
 *
 * @param pushed token
 */
void SourceHandler::PushToken(SourceToken * t)
{
	tokens.push_back(t);
}


/**
 * Constructs source representation with tokens from syntax tree node.
 * 
 *
 * @param container for source tokens
 * @param syntax tree node
 */
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

/**
 * Creates source handler from syntax tree node of expression.
 * 
 *
 * @param syntax tree node
 *
 * @return source handler
 */
SourceHandler* ExprToHandler(SrcNode * node)
{
	SourceHandler * srcHandler= new SourceHandler();
	SourceStatementToken * t=new SourceStatementToken();
	srcHandler->PushToken(t);
	ConstructRecursion(t,node);
	return srcHandler;
}

/**
 * Creates source handler from syntax tree node.
 * 
 *
 * @param syntax tree node
 *
 * @return source handler
 */
SourceHandler* SourceToHandler(SrcNode * node)
{
	SourceHandler * srcHandler= new SourceHandler();
	ConstructRecursion(srcHandler,node);
	return srcHandler;
}

/**
 * Prints source handler to string
 * 
 *
 * @param output string
 */
void SourceHandler::Print(string& dest)
{
	for(unsigned int i=0;i<tokens.size();i++)
		tokens[i]->Print(dest);
	
}
/**
 * Prints source token to string
 * 
 *
 * @param output string
 */
void SourceStringToken::Print(string& dest)
{
	dest+=str;
	if(str==";")
		dest+="\n";
}
/**
 * Prints statement token to string
 * 
 *
 * @param output string
 */
void SourceStatementToken::Print(string& dest)
{
	string s;

	dest+=s;
	for(unsigned int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->Print(dest);
	}
}
/**
 * Prints updaters of attributes inside ID token to string
 * 
 *
 * @param output string
 */
void SourceIdToken::PrintZeroUpdaters(string& dest)
{
	if(this->isElement)
	{
	}
	else if(this->isVar)
	{
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_CQML_element"+INTTOSTR(this->elementId)+")."+this->str+"_Update=0;\n";
	}
}
/**
 * Prints ID token to string
 * 
 *
 * @param output string
 */
void SourceIdToken::Print(string& dest)
{
	if(this->isElement)
	{
		dest+="(((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
		"_CQML_element"+INTTOSTR(this->elementId)+")";
	}
	else if(this->isVar)
	{
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_CQML_element"+INTTOSTR(this->elementId)+")."+this->str;
	}
	else
		dest+=str;
}
/**
 * Prints updaters of attributes inside dot token to string
 * 
 *
 * @param output string
 */
void SourceDotToken::PrintZeroUpdaters(string& dest)
{
	if(this->isVarReplaced)
	{
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_CQML_element"+INTTOSTR(this->variableId)+")";
		bool wasStatic=true;
		for(unsigned int i=0;i<this->isStatic.size();i++)
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
				{
					if(wasStatic)
						dest+=string("->Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\").SetUpdater(0);\n");
					else
						dest+=string(".Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\").SetUpdater(0);\n");

				}
				else
				{
					if(wasStatic)
						dest+=string("->Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\")");
					else
						dest+=string(".Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\")");
				}
			}
			wasStatic=this->isStatic[i];
		}
		
	}
}
/**
 * Prints dot token to string
 * 
 *
 * @param output string
 */
void SourceDotToken::Print(string& dest)
{
	if(this->isVarReplaced)
	{
		dest+="(*((CQMLGUI::Rootoutput"+INTTOSTR(this->fileId)+"*)context->root)->"+
			"_CQML_element"+INTTOSTR(this->variableId)+")";
		bool wasStatic=true;
		for(unsigned int i=0;i<this->isStatic.size();i++)
		{
			if(this->isStatic[i])
			{
				dest+=string(".")+identifiers[identifiers.size()-isStatic.size()+i]->GetId();
			}
			else
			{
				if(wasStatic)
					dest+=string("->Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\")");
				else
					dest+=string(".Get(\"")+identifiers[identifiers.size()-isStatic.size()+i]->GetId()+string("\")");
			}
			wasStatic=isStatic[i];
		}
		
	}
	else
	{
		for(unsigned int i=0;i<tokens.size();i++)
		{
			this->tokens[i]->Print(dest);
		}
	}
}
/**
 * Prints updaters of attributes inside expression token to string
 * 
 *
 * @param output string
 */
void SourceExprToken::PrintZeroUpdaters(string& dest)
{
	for(unsigned int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->PrintZeroUpdaters(dest);
	}
}
/**
 * Prints expression token to string
 * 
 *
 * @param output string
 */
void SourceExprToken::Print(string& dest)
{
	for(unsigned int i=0;i<tokens.size();i++)
	{
		this->tokens[i]->Print(dest);
	}
}
/**
 * Prints assignment token to string
 * 
 *
 * @param output string
 */
void SourceAssignmentToken::Print(string& dest)
{
	this->nodes[0]->Print(dest);

	for(unsigned int i=1;i<nodes.size();i++)
	{
		dest+=this->ops[i-1].str;
		this->nodes[i]->Print(dest);
	}
	if(nodes.size()>1)dest+=";\n";
	for(unsigned int i=0;i<nodes.size()-1;i++)
	{
		this->nodes[i]->PrintZeroUpdaters(dest);
	}

}

void SourceToken::PrintZeroUpdaters(string&){}

int varId=0;
int lastRightVarId=0;
/**
 * Processes source of a handler.
 * 
 *
 * @param handler pointer
 * @param component index
 * @param current element index
 */
void ProcessSource(SourceHandler * handler,int treeInd, int currentElementId)
{
	varId=0;
	handler->Process(treeInd,currentElementId);
}

/**
 * Processes source handler.
 * 
 *
 * @param component index
 * @param current element index
 */
void SourceHandler::Process(int treeInd, int currentElementId)
{
	for(unsigned int i=0;i<tokens.size();i++)
	{
		tokens[i]->Process(treeInd,currentElementId,0,true);
	}
}

/**
 * Processes source token
 * 
 *
 * @param component index
 * @param current element index
 * @param last statement token
 * @param is r-value
 */
void SourceToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{

}


/**
 * Processes ID token
 * 
 *
 * @param component index
 * @param current element index
 * @param last statement token
 * @param is r-value
 */
void SourceIdToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	bool isOtherId=idMaps[treeInd].count(this->str)!=0;
	int curId=currentElementId;
	isElement=false;
	isVar=false;

	if(isOtherId)
	{
		fileId=treeInd;
		elementId=idMaps[treeInd][this->str];
		isElement=true;
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

				isVar=true;
			}
			else
				return;
	}
}

/**
 * Processes dot token
 * 
 *
 * @param component index
 * @param current element index
 * @param last statement token
 * @param is r-value
 */
void SourceDotToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	bool isOtherId=idMaps[treeInd].count(identifiers[0]->GetId())!=0;
	int curId=currentElementId;
	int prevVarId=varId;
	
	fileId=treeInd;
	
	if(isOtherId)
	{
		if(identifiers[0]->GetId()=="thisButton")
		{
			int a=400;
		}
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
					printf("primitive type doesnt have members");
					exit(0);
				}
				//check existence
				PropertyAndType * prop=cont->CheckExistence(identifiers[i]->GetId());

				if(prop==0)
				{
					printf("nonexistent attribute %d",identifiers[i]->GetId().c_str());
					exit(0);
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
					printf("primitive does doesnt have members");
					exit(0);
				}
				//check existence
				PropertyAndType * prop=cont->CheckExistence(identifiers[i]->GetId());

				if(prop==0)
				{
					//error does not exist
					printf("nonexistent attribute %d",identifiers[i]->GetId().c_str());
					exit(0);
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

/**
 * Processes statement token
 * 
 *
 * @param component index
 * @param current element index
 * @param last statement token
 * @param is r-value
 */
void SourceStatementToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	for(unsigned int i=0;i<this->tokens.size();i++)
	{
		this->tokens[i]->Process(treeInd,currentElementId,this,isRightVal);
	}
}

/**
 * Processes expression token
 * 
 *
 * @param component index
 * @param current element index
 * @param last statement token
 * @param is r-value
 */
void SourceExprToken::Process(int treeInd, int currentElementId, SourceStatementToken* lastStatement, bool isRightVal)
{
	for(unsigned int i=0;i<this->tokens.size();i++)
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

/**
 * Processes assignment token
 * 
 *
 * @param component index
 * @param current element index
 * @param last statement token
 * @param is r-value
 */
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




/**
 * Gets identificator of token
 * 
 *
 * @return identificator
 */
string SourceIdToken::GetId()
{
	return this->str;
}

