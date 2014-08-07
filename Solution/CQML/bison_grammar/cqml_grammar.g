%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER PROPERTY
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start start_point

%union {
	struct
	{
	int* val;
	char * lexem;
	} data;
}
%%

start_point
	:	element_list
	{  makeParseTree($<data.val>1); }
	;

element_list
	:	element element_list
	{ $<data.val>$ = createList( $<data.val>1 , 'L', $<data.val>2, 0); }
	|	element
	{ $<data.val>$ = createList( $<data.val>1 , 'l', 0, 0);  }
	;
	
element
	:	IDENTIFIER '{' attribute_or_subelement_list '}'
	{ $<data.val>$ = createElement( $<data.val>1 , 'R', $<data.val>3, $<data.lexem>1 ); }
	|	IDENTIFIER '{' '}'
	{ $<data.val>$ = createElement( $<data.val>1 , 'r', 0, $<data.lexem>1); }
	;

attribute_or_subelement_list
	: attribute_or_element ';' attribute_or_subelement_list
	{ $<data.val>$ = createList( $<data.val>1 , 'L', $<data.val>3, 0); }
	| attribute_or_element ';'
	{ $<data.val>$ = createList( $<data.val>1 , 'l', 0, 0);  }
;


attribute_or_element
	: element
	{ $<data.val>$ = $<data.val>1; }
	| event_handler
	{ $<data.val>$ = $<data.val>1; }
	| attribute
	{ $<data.val>$ = $<data.val>1; }
	| property
	{ $<data.val>$ = $<data.val>1; }
;

event_handler
	: IDENTIFIER ':' compound_statement
	{ $<data.val>$ = createHandler( $<data.val>1 , 'l', $<data.lexem>1, $<data.val>3);  }
;

property
	: PROPERTY IDENTIFIER attribute
	{ $<data.val>$ = createPropertyInit( $<data.val>2 , $<data.val>3 , $<data.lexem>2);  }
	| PROPERTY IDENTIFIER IDENTIFIER
	{ $<data.val>$ = createProperty( $<data.val>2 , $<data.lexem>2 , $<data.lexem>3);  }
;

attribute
	:	IDENTIFIER ':' expression
	{ $<data.val>$ = createAttribute( $<data.val>1 , 'l', $<data.lexem>1, $<data.val>3);  }
;

primary_expression
	: IDENTIFIER
	{ $<data.val>$ = MakeNode0ID($<data.lexem>1); }
	| CONSTANT
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| STRING_LITERAL
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| '(' expression ')'
	{ $<data.val>$ = MakeNode3(MakeNode0("("), $<data.val>2 ,MakeNode0(")")); }
	;

postfix_expression
	: primary_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| postfix_expression '[' expression ']'
	{ $<data.val>$ = MakeNode4($<data.val>1, MakeNode0("["), $<data.val>3,MakeNode0("]")); }
	| postfix_expression '(' ')'
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("(") ,MakeNode0(")")); }
	| postfix_expression '(' argument_expression_list ')'
	{ $<data.val>$ = MakeNode4($<data.val>1, MakeNode0("("), $<data.val>3, MakeNode0(")")); }
	| postfix_expression '.' IDENTIFIER
	{ $<data.val>$ = MakeNode3Dot($<data.val>1, MakeNode0("."), MakeNode0ID($<data.lexem>3)); }
	| postfix_expression PTR_OP IDENTIFIER
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), MakeNode0ID($<data.lexem>3)); }
	| postfix_expression INC_OP
	{ $<data.val>$ = MakeNode2($<data.val>1, MakeNode0($<data.lexem>2)); }
	| postfix_expression DEC_OP
	{ $<data.val>$ = MakeNode2($<data.val>1, MakeNode0($<data.lexem>2)); }
	;

argument_expression_list
	: assignment_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| argument_expression_list ',' assignment_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(","), $<data.val>3); }
	;

unary_expression
	: postfix_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| INC_OP unary_expression
	{ $<data.val>$ = MakeNode2(MakeNode0($<data.lexem>1), $<data.val>2); }
	| DEC_OP unary_expression
	{ $<data.val>$ = MakeNode2(MakeNode0($<data.lexem>1), $<data.val>2); }
	| unary_operator cast_expression
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	| SIZEOF unary_expression
	{ $<data.val>$ = MakeNode2(MakeNode0($<data.lexem>1), $<data.val>2); }
	| SIZEOF '(' type_name ')'
	{ $<data.val>$ = MakeNode4(MakeNode0($<data.lexem>1), MakeNode0("("), $<data.val>3, MakeNode0(")")); }
	;

unary_operator
	: '&'
	{ $<data.val>$ = MakeNode0("&"); }
	| '*'
	{ $<data.val>$ = MakeNode0("*"); }
	| '+'
	{ $<data.val>$ = MakeNode0("+"); }
	| '-'
	{ $<data.val>$ = MakeNode0("-"); }
	| '~'
	{ $<data.val>$ = MakeNode0("~"); }
	| '!'
	{ $<data.val>$ = MakeNode0("!"); }
	;

cast_expression
	: unary_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| '(' type_name ')' cast_expression
	{ $<data.val>$ = MakeNode4(MakeNode0("("), $<data.val>2, MakeNode0(")"), $<data.val>4); }
	
	;

multiplicative_expression
	: cast_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| multiplicative_expression '*' cast_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("*"), $<data.val>3); }
	| multiplicative_expression '/' cast_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("/"), $<data.val>3); }
	| multiplicative_expression '%' cast_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("%"), $<data.val>3); }
	;

additive_expression
	: multiplicative_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| additive_expression '+' multiplicative_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("+"), $<data.val>3); }
	| additive_expression '-' multiplicative_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("-"), $<data.val>3); }
	;

shift_expression
	: additive_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| shift_expression LEFT_OP additive_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	| shift_expression RIGHT_OP additive_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	;

relational_expression
	: shift_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| relational_expression '<' shift_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("<"), $<data.val>3); }
	| relational_expression '>' shift_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(">"), $<data.val>3); }
	| relational_expression LE_OP shift_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	| relational_expression GE_OP shift_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	;

equality_expression
	: relational_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| equality_expression EQ_OP relational_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	| equality_expression NE_OP relational_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	;

and_expression
	: equality_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| and_expression '&' equality_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("&"), $<data.val>3); }
	;

exclusive_or_expression
	: and_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| exclusive_or_expression '^' and_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("^"), $<data.val>3); }
	;

inclusive_or_expression
	: exclusive_or_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| inclusive_or_expression '|' exclusive_or_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("|"), $<data.val>3); }
	;

logical_and_expression
	: inclusive_or_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| logical_and_expression AND_OP inclusive_or_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	;

logical_or_expression
	: logical_and_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| logical_or_expression OR_OP logical_and_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0($<data.lexem>2), $<data.val>3); }
	;

conditional_expression
	: logical_or_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| logical_or_expression '?' expression ':' conditional_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("?"), MakeNode3($<data.val>3, MakeNode0(":"),$<data.val>5)); }
	;

assignment_expression
	: conditional_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| unary_expression assignment_operator assignment_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, $<data.val>2, $<data.val>3); }
	;

assignment_operator
	: '='
	{ $<data.val>$ = MakeNode0("="); }
	| MUL_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| DIV_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| MOD_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| ADD_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| SUB_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| LEFT_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| RIGHT_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| AND_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| XOR_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| OR_ASSIGN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	;

expression
	: assignment_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| expression ',' assignment_expression
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(","), $<data.val>3); }
	;

constant_expression
	: conditional_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	;

declaration
	: declaration_specifiers ';'
	{ $<data.val>$ = MakeNode2($<data.val>1, MakeNode0(";")); }
	| declaration_specifiers init_declarator_list ';'
	{ $<data.val>$ = MakeNode3($<data.val>1, $<data.val>2, MakeNode0(";")); }
	;

declaration_specifiers
	: storage_class_specifier
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| storage_class_specifier declaration_specifiers
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	| type_specifier
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| type_specifier declaration_specifiers
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	| type_qualifier
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| type_qualifier declaration_specifiers
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;

init_declarator_list
	: init_declarator
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| init_declarator_list ',' init_declarator
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(","), $<data.val>3); }
	;

init_declarator
	: declarator
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| declarator '=' initializer
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("="), $<data.val>3); }
	;

storage_class_specifier
	: TYPEDEF
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| EXTERN
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| STATIC
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| AUTO
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| REGISTER
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	;

type_specifier
	: VOID
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| CHAR
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| SHORT
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| INT
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| LONG
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| FLOAT
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| DOUBLE
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| SIGNED
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| UNSIGNED
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| struct_or_union_specifier
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| enum_specifier
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| TYPE_NAME
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| VOLATILE
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	;

declarator
	: pointer direct_declarator
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	| direct_declarator
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	{ $<data.val>$ = MakeNode3(MakeNode0("("), $<data.val>2, MakeNode0(")")); }
	| direct_declarator '[' constant_expression ']'
	{ $<data.val>$ = MakeNode4($<data.val>1, MakeNode0("["), $<data.val>3, MakeNode0("]")); }
	| direct_declarator '[' ']'
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("["), MakeNode0("]")); }
	| direct_declarator '(' parameter_type_list ')'
	{ $<data.val>$ = MakeNode4($<data.val>1, MakeNode0("("), $<data.val>3, MakeNode0(")")); }
	| direct_declarator '(' identifier_list ')'
	{ $<data.val>$ = MakeNode4($<data.val>1, MakeNode0("("), $<data.val>3, MakeNode0(")")); }
	| direct_declarator '(' ')'
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("("), MakeNode0(")")); }
	;

pointer
	: '*'
	{ $<data.val>$ = MakeNode0("*"); }
	| '*' type_qualifier_list
	{ $<data.val>$ = MakeNode2(MakeNode0("*"), $<data.val>2); }
	| '*' pointer
	{ $<data.val>$ = MakeNode2(MakeNode0("*"), $<data.val>2); }
	| '*' type_qualifier_list pointer
	{ $<data.val>$ = MakeNode3(MakeNode0("*"), $<data.val>2, $<data.val>3); }
	;

type_qualifier_list
	: type_qualifier
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| type_qualifier_list type_qualifier
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;


parameter_type_list
	: parameter_list
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| parameter_list ',' ELLIPSIS
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(","),  MakeNode0($<data.lexem>3)); }
	;

parameter_list
	: parameter_declaration
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| parameter_list ',' parameter_declaration
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(","),  $<data.val>3); }
	;

parameter_declaration
	: declaration_specifiers declarator
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	| declaration_specifiers abstract_declarator
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	| declaration_specifiers
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	;

identifier_list
	: IDENTIFIER
	{ $<data.val>$ = MakeNode0($<data.lexem>1); }
	| identifier_list ',' IDENTIFIER
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(","), $<data.val>3); }
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| direct_abstract_declarator
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| pointer direct_abstract_declarator
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	{ $<data.val>$ = MakeNode3(MakeNode0("("), $<data.val>2, MakeNode0(")")); }
	| '[' ']'
	{ $<data.val>$ = MakeNode2(MakeNode0("["), MakeNode0("]")); }
	| '[' constant_expression ']'
	{ $<data.val>$ = MakeNode3(MakeNode0("["), $<data.val>2, MakeNode0("]")); }
	| direct_abstract_declarator '[' ']'
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("["), MakeNode0("]")); }
	| direct_abstract_declarator '[' constant_expression ']'
	{ $<data.val>$ = MakeNode4($<data.val>1, MakeNode0("["), $<data.val>3, MakeNode0("]")); }
	| '(' ')'
	{ $<data.val>$ = MakeNode2(MakeNode0("("), MakeNode0(")")); }
	| '(' parameter_type_list ')'
	{ $<data.val>$ = MakeNode3(MakeNode0("("), $<data.val>2, MakeNode0(")")); }
	| direct_abstract_declarator '(' ')'
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("("), MakeNode0(")")); }
	| direct_abstract_declarator '(' parameter_type_list ')'
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0("("), $<data.val>3, MakeNode0(")")); }
	;

initializer
	: assignment_expression
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| '{' initializer_list '}'
	{ $<data.val>$ = MakeNode3(MakeNode0("{"), $<data.val>2, MakeNode0("}")); }
	| '{' initializer_list ',' '}'
	{ $<data.val>$ = MakeNode4(MakeNode0("{"), $<data.val>2, MakeNode0(","), MakeNode0("}")); }
	;

initializer_list
	: initializer
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| initializer_list ',' initializer
	{ $<data.val>$ = MakeNode3($<data.val>1, MakeNode0(","), $<data.val>3); }
	;

statement
	: labeled_statement
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| compound_statement
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| expression_statement
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| selection_statement
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| iteration_statement
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| jump_statement
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	;

labeled_statement
	: IDENTIFIER ':' statement
	{ $<data.val>$ = MakeNode3($<data.lexem>1, MakeNode0(":"), $<data.val>3); }
	| CASE constant_expression ':' statement
	{ $<data.val>$ = MakeNode4($<data.lexem>1, $<data.val>2, MakeNode0(":"), $<data.val>4); }
	| DEFAULT ':' statement
	{ $<data.val>$ = MakeNode3($<data.lexem>1, MakeNode0(":"), $<data.val>3); }
	;

compound_statement
	: '{' '}'
	{ $<data.val>$ = MakeNode2(MakeNode0("{"), MakeNode0("}")); }
	| '{' statement_list '}'
	{ $<data.val>$ = MakeNode3(MakeNode0("{"), $<data.val>2, MakeNode0("}")); }
	| '{' declaration_list '}'
	{ $<data.val>$ = MakeNode3(MakeNode0("{"), $<data.val>2, MakeNode0("}")); }
	| '{' declaration_list statement_list '}'
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;

declaration_list
	: declaration
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| declaration_list declaration
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;

statement_list
	: statement
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| statement_list statement
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;

expression_statement
	: ';'
	{ $<data.val>$ = MakeNode0(";"); }
	| expression ';'
	{ $<data.val>$ = MakeNode2($<data.val>1, MakeNode0(";")); }
	;

selection_statement
	: IF '(' expression ')' statement
	{ $<data.val>$ = MakeNode5($<data.lexem>1, MakeNode0("("), $<data.val>3, MakeNode0(")"), $<data.val>5); }
	| IF '(' expression ')' statement ELSE statement
	{ $<data.val>$ = MakeNode7($<data.lexem>1, MakeNode0("("), $<data.val>3, MakeNode0(")"), $<data.val>5, $<data.lexem>6, $<data.val>7); }
	| SWITCH '(' expression ')' statement
	{ $<data.val>$ = MakeNode5($<data.lexem>1, MakeNode0("("), $<data.val>3, MakeNode0(")"), $<data.val>5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement
	{ $<data.val>$ = MakeNode5($<data.lexem>1, MakeNode0("("), $<data.val>3, MakeNode0(")"), $<data.val>5); }
	| DO statement WHILE '(' expression ')' ';'
	{ $<data.val>$ = MakeNode7($<data.lexem>1, $<data.val>2, $<data.lexem>3, MakeNode0("("), $<data.val>5, MakeNode0(")"),  MakeNode0(";")); }
	| FOR '(' expression_statement expression_statement ')' statement
	{ $<data.val>$ = MakeNode6($<data.lexem>1, MakeNode0("("), $<data.val>3, $<data.val>4, MakeNode0(")"), $<data.val>6); }
	| FOR '(' expression_statement expression_statement expression ')' statement
	{ $<data.val>$ = MakeNode7($<data.lexem>1, MakeNode0("("), $<data.val>3, $<data.val>4, $<data.val>5, MakeNode0(")"), $<data.val>7); }
	;

jump_statement
	: GOTO IDENTIFIER ';'
	{ $<data.val>$ = MakeNode3($<data.lexem>1, $<data.lexem>2, MakeNode0(";")); }
	| CONTINUE ';'
	{ $<data.val>$ = MakeNode2($<data.lexem>1, MakeNode0(";")); }
	| BREAK ';'
	{ $<data.val>$ = MakeNode2($<data.lexem>1, MakeNode0(";")); }
	| RETURN ';'
	{ $<data.val>$ = MakeNode2($<data.lexem>1, MakeNode0(";")); }
	| RETURN expression ';'
	{ $<data.val>$ = MakeNode3($<data.lexem>1, $<data.val>2, MakeNode0(";")); }
	;

pure_c_code
	: external_declaration
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| pure_c_code external_declaration
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;

external_declaration
	: function_definition
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	| declaration
	{ $<data.val>$ = MakeNode1($<data.val>1); }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	{ $<data.val>$ = MakeNode4($<data.val>1, $<data.val>2, $<data.val>3, $<data.val>4); }
	| declaration_specifiers declarator compound_statement
	{ $<data.val>$ = MakeNode3($<data.val>1, $<data.val>2, $<data.val>3); }
	| declarator declaration_list compound_statement
	{ $<data.val>$ = MakeNode3($<data.val>1, $<data.val>2, $<data.val>3); }
	| declarator compound_statement
	{ $<data.val>$ = MakeNode2($<data.val>1, $<data.val>2); }
	;

%%

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
