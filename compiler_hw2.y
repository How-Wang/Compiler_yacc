/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    typedef struct symtable_node symtable_type;
    struct symtable_node{
        int level;
        int index;
        char* name;
        char* type;
        int address;
        int lineno;
        char* func_sig;
        symtable_type* next;
    };

    typedef struct symtable_stack_node symtable_stack_type;
    struct symtable_stack_node{
        symtable_type* table;
        int level;
        symtable_stack_type* next;
    };

    static void create_symbol();
    static void insert_symbol(char* name, char* type, char* Func_sig, int para_type);
    static symtable_type* lookup_symbol(char * name);
    static void dump_symbol();
    static char* find_para(char* name);

    /* Global variables */
    bool HAS_ERROR = false;
    int global_level = -1;
    int global_address = 0;
    char *str_funct_name;
    char *funct_parameter;
    char *funct_parameterUp;
    char *funct_parameterIn;
    char *funct_parameterDown;
    char *funct_parameterReturn;

%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    struct{
	union{
 		int i_val;
		float f_val;
		char *s_val;
		bool b_val;
        }value;
    	char * type;
    }item;   
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING
%token INC DEC GEQ LOR LAND EQ LEQ NEQ
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token IF ELSE FOR SWITCH CASE FUNC
%token PRINT PACKAGE RETURN PRINTLN
/*%token Type*/ 

%token DEFAULT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT
%token <b_val> BOOL_LIT
%token <f_val> FLOAT_LIT
%token <s_val> IDENT


/* Nonterminal with return, which need to sepcify type */
%type <s_val> ReturnType Type INT FLOAT BOOL STRING 

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    	: GlobalStatementList	{dump_symbol();}
;

GlobalStatementList 
    	: GlobalStatementList GlobalStatement
    	| GlobalStatement
;

GlobalStatement
        : PackageStmt NEWLINE 
        | FunctionDeclStmt
        | NEWLINE
;

PackageStmt
        : PACKAGE IDENT		{create_symbol(); printf("package: %s\n", $<item.value.s_val>2);}
;

FunctionDeclStmt
        : FuncOpen FuncParameter ReturnType FuncBlock
;

FuncParameter
        : '(' ParameterList ')'  {      
                                        funct_parameterUp = (char*)malloc(sizeof(char)*1);
                                        funct_parameterUp[0] = '(';
					funct_parameterIn = (char*)malloc(sizeof($<item.value.s_val>2) + 1);
					strcpy(funct_parameterIn, $<item.value.s_val>2);
					funct_parameterDown = (char*)malloc(sizeof(char)*1);
					funct_parameterDown[0] = ')';
                                 }
;

FuncOpen
        : FUNC IDENT {
			printf("func: %s\n", $<item.value.s_val>2);
			create_symbol();
			str_funct_name = (char *)malloc( strlen($<item.value.s_val>2) + 1);
			strcpy(str_funct_name, $<item.value.s_val>2);
		     }
;

FuncBlock
	: FunctionUpBlock StatementList '}' { dump_symbol(); }
;

FunctionUpBlock
	: '{' 				/*{ insert_symbol(str_funct_name,"func","()V"); }*/
;

UnaryExpr
	: PrimaryExpr {$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| UnaryExpr INC {printf("INC\n");$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| UnaryExpr DEC {printf("DEC\n");$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| unary_op cast_expression {printf("%s\n", $<item.value.s_val>1);$<item.type>$=$<item.type>2; $<item.value>$=$<item.value>2;}
;

cast_expression
	: UnaryExpr {$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| '(' Type ')' cast_expression {$<item.type>$=$<item.type>2; $<item.value>$=$<item.value>2;}

multiplicative_expression
	: cast_expression				{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| multiplicative_expression mul_op cast_expression { 	if( !strcmp($<item.value.s_val>2,"REM") && strcmp($<item.type>1,"int32")){
                                                                        printf("error:%d: invalid operation: (operator REM not defined on %s)\n",yylineno,$<item.type>1);
                                                                }
								else if( !strcmp($<item.value.s_val>2,"REM") && strcmp($<item.type>3,"int32")){
                                                                        printf("error:%d: invalid operation: (operator REM not defined on %s)\n",yylineno,$<item.type>3);
                                                                }

								else if( strcmp($<item.type>1,$<item.type>3)!=0 ){
									printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n"
									,yylineno ,$<item.value.s_val>2, $<item.type>1,$<item.type>3);
								}
								
								$<item.type>$=$<item.type>3;
								printf("%s\n", $<item.value.s_val>2);}
;

additive_expression
	: multiplicative_expression				{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| additive_expression add_op multiplicative_expression {if( strcmp($<item.type>1,$<item.type>3)!=0 ){
                                                                        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n"
                                                                        ,yylineno ,$<item.value.s_val>2, $<item.type>1,$<item.type>3);
                                                                }
                                                                $<item.type>$=$<item.type>3;
								printf("%s\n", $<item.value.s_val>2);}
;

relational_expression
	: additive_expression					{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| relational_expression rel_op additive_expression {	if( strcmp($<item.type>1,$<item.type>3)!=0 ){
                                                                        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n"
                                                                        ,yylineno ,$<item.value.s_val>2, $<item.type>1,$<item.type>3);
                                                                }
                                                                $<item.type>$="bool";
								printf("%s\n", $<item.value.s_val>2);}
;

equality_expression
	: relational_expression					{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| equality_expression equ_op relational_expression {if( strcmp($<item.type>1,$<item.type>3)!=0 ){
                                                                        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n"
                                                                        ,yylineno ,$<item.value.s_val>2, $<item.type>1,$<item.type>3);
                                                                }
                                                                $<item.type>$="bool";
								printf("%s\n", $<item.value.s_val>2);}
;

logical_and_expression
	: equality_expression					{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| logical_and_expression LAND equality_expression {/*if( strcmp($<item.type>1,$<item.type>3)!=0 ){
                                                                        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n"
                                                                        ,yylineno ,"LAND", $<item.type>1,$<item.type>3);
                                                                }*/
								if( !strcmp($<item.type>1,"int32")){
                                                                        printf("error:%d: invalid operation: (operator LAND not defined on %s)\n",yylineno,$<item.type>1);
                                                                }
                                                                else if( !strcmp($<item.type>3,"int32")){
                                                                        printf("error:%d: invalid operation: (operator LAND not defined on %s)\n",yylineno,$<item.type>3);
                                                                }
								$<item.type>$="bool";
								printf("LAND\n");}
;

logical_or_expression
	: logical_and_expression				{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| logical_or_expression LOR logical_and_expression {/*if( strcmp($<item.type>1,$<item.type>3)!=0 ){
                                                                        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n"
                                                                        ,yylineno ,$<item.value.s_val>2, $<item.type>1,$<item.type>3);
                                                                }*/
								if( !strcmp($<item.type>1,"int32")){
                                                                        printf("error:%d: invalid operation: (operator LOR not defined on %s)\n",yylineno,$<item.type>1);
                                                                }
                                                                else if( !strcmp($<item.type>3,"int32")){
                                                                        printf("error:%d: invalid operation: (operator LOR not defined on %s)\n",yylineno,$<item.type>3);
                                                                }
								$<item.value>$=$<item.value>3;
								$<item.type>$="bool";
								printf("LOR\n");// $<item.type>$ = "bool";
							   }
;

assignment_expression
	: logical_or_expression					{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
	| UnaryExpr assign_op assignment_expression {		if(!$<item.type>1){ $<item.type>1="ERROR"; }
								if( strcmp($<item.type>1,$<item.type>3)!=0 ){
                                                                        printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n"
                                                                        ,yylineno ,$<item.value.s_val>2, $<item.type>1,$<item.type>3);
                                                                }
                                                                $<item.value>$=$<item.value>3;
								$<item.type>$=$<item.type>3;
								printf("%s\n", $<item.value.s_val>2);}
;

Expression
	: assignment_expression 				{$<item.type>$=$<item.type>1; $<item.value>$=$<item.value>1;}
;

rel_op
	: '<'   { $<item.value.s_val>$="LTR"; }
	| LEQ 
	| '>'	{ $<item.value.s_val>$="GTR"; }
	| GEQ
;

equ_op
	: EQ	{$<item.value.s_val>$="EQL";}
	| NEQ	{$<item.value.s_val>$="NEQ";}
;

add_op
	: '+'	{ $<item.value.s_val>$="ADD"; }
	| '-'	{ $<item.value.s_val>$="SUB"; }
;

mul_op
	: '*'   { $<item.value.s_val>$="MUL"; }	  
	| '/'   { $<item.value.s_val>$="QUO"; }
	| '%'   { $<item.value.s_val>$="REM"; }
;

unary_op
	: '+'  { $<item.value.s_val>$="POS"; }
	| '-'  { $<item.value.s_val>$="NEG"; }
	| '!'  { $<item.value.s_val>$="NOT"; }
;

PrimaryExpr
	: Operand	{$<item.value>$ = $<item.value>1; $<item.type>$=$<item.type>1; }
	| ConversionExpr{$<item.value>$ = $<item.value>1; $<item.type>$=$<item.type>1;}
;

Operand
	: Literal 	{ $<item.value>$ = $<item.value>1; $<item.type>$ = $<item.type>1;}
/*
	| IDENT { 
			$<item.value>$ = $<item.value>1; $<item.type>$ = $<item.type>1;
			symtable_type* tmp_table = lookup_symbol($<item.value.s_val>1);
			if (!tmp_table){
				printf("error:%d: undefined: %s\n", yylineno+1, $<item.value.s_val>1);
				$<item.type>$ = "ERROR";
			}
			else{
				printf("IDENT (name=%s, address=%d)\n",$<item.value.s_val>1,tmp_table->address);
                        	$<item.type>$ = tmp_table->type;
			}
		}
	| IDENT '(' ')'	{printf("call: %s\n", $<item.value.s_val>1);}
*/	
	| IdSet 	     {$<item.value>$ = $<item.value>1; $<item.type>$ = $<item.type>1;}
	| '(' Expression ')' {$<item.value>$ = $<item.value>1; $<item.type>$ = $<item.type>1;}
;

IdSet 
	: IDENT {
                        $<item.value>$ = $<item.value>1; $<item.type>$ = $<item.type>1;
                        symtable_type* tmp_table = lookup_symbol($<item.value.s_val>1);
                        if (!tmp_table){
                                printf("error:%d: undefined: %s\n", yylineno+1, $<item.value.s_val>1);
                                $<item.type>$ = "ERROR";
                        }
                        else{
                                printf("IDENT (name=%s, address=%d)\n",$<item.value.s_val>1,tmp_table->address);
                                $<item.type>$ = tmp_table->type;
                        }
          }
	| IDENT '(' CallParaList ')' {
			//	printf("call: %s\n", $<item.value.s_val>1);
				$<item.value>$ = $<item.value>1;
				$<item.type>$ = "func";
				char* temp_sig_str = (char *)malloc(sizeof(char)*10);
				temp_sig_str = find_para($<item.value.s_val>1);
				printf("call: %s%s\n", $<item.value.s_val>1, temp_sig_str);
			}
;

CallParaList
	:
	| Operand
	| CallParaList ',' Operand
;

Literal
	: INT_LIT	{
				printf("INT_LIT %d\n",         $<item.value.i_val>$);
				$<item.value>$= $<item.value>1;
				$<item.type>$ = "int32";
			}
	| FLOAT_LIT	{	printf("FLOAT_LIT %f\n",       $<item.value.f_val>$);
                                 $<item.value>$= $<item.value>1;
                                 $<item.type>$ = "float32";
                         }

	| BOOL_LIT	{
				if($<item.value.b_val>$ == true) printf("TRUE 1\n");
				else printf("FALSE 0\n");
				$<item.value>$= $<item.value>1;
				$<item.type>$ = "bool";
			}
	| '"' STRING_LIT '"'{printf("STRING_LIT %s\n", $<item.value.s_val>2);
				$<item.value>$= $<item.value>2;
				$<item.type>$ = "string";
			}
;

ConversionExpr
	: Type '(' Expression ')' { 
		if (strcmp($<item.type>3, "float32") == 0 && strcmp($<item.value.s_val>1, "int32") == 0){
            		printf("f2i\n");
            		$<item.type>$ = "int32";
        	}
        	else if (strcmp($<item.type>3, "int32") == 0 && strcmp($<item.value.s_val>1, "float32") == 0){
            		printf("i2f\n");
            		$<item.type>$ = "float32";
        	}
		}
;

Statement
	: DeclarationStmt NEWLINE
	| SimpleStmt NEWLINE
	| Block
	| IfStmt
	| ForStmt
	| SwitchStmt
	| CaseStmt
	| PrintStmt NEWLINE
	| ReturnStmt NEWLINE
	| NEWLINE
;

SimpleStmt
	: ExpressionStmt
;

DeclarationStmt
	: VAR IDENT Type	{ symtable_type* tem_table = lookup_symbol($<item.value.s_val>2); 
					if(tem_table && tem_table->level == global_level){
						printf("error:%d: %s redeclared in this block. previous declaration at line %d\n"
							,yylineno, $<item.value.s_val>2, tem_table -> lineno);
						insert_symbol($<item.value.s_val>2, $<item.value.s_val>3, "-", 0);				
					}
					else{ insert_symbol($<item.value.s_val>2, $<item.value.s_val>3, "-", 0); }}	
	| VAR IDENT Type '=' Expression { symtable_type* tem_table = lookup_symbol($<item.value.s_val>2); 
                                        if(tem_table && tem_table->level == global_level){
                                                printf("error:%d: %s redeclared in this block. previous declaration at line %d\n"
							,yylineno, $<item.value.s_val>2, tem_table -> lineno);
                                        	insert_symbol($<item.value.s_val>2, $<item.value.s_val>3, "-", 0);
					}
                                        else{ insert_symbol($<item.value.s_val>2, $<item.value.s_val>3, "-", 0); }}
;

assign_op
	: '=' 	{ $<item.value.s_val>$="ASSIGN"; }
	| ADD_ASSIGN { $<item.value.s_val>$="ADD"; }
	| SUB_ASSIGN { $<item.value.s_val>$="SUB"; }
	| MUL_ASSIGN { $<item.value.s_val>$="MUL"; }
	| DIV_ASSIGN { $<item.value.s_val>$="QUO"; }
	| MOD_ASSIGN { $<item.value.s_val>$="REM"; }
;

ExpressionStmt
	: Expression
;

Block
	: BlockUp StatementList '}' {dump_symbol();}
;
BlockUp
	: '{' { create_symbol();}


StatementList 
	: Statement StatementList
	| Statement
;

IfStmt
	: IF Condition Block
	| IF Condition Block ELSE IfStmt
	| IF Condition Block ELSE Block
;

Condition
	: Expression { if (strcmp($<item.type>1, "bool")!=0){
				printf("error:%d: non-bool (type %s) used as for condition\n",yylineno+1,$<item.type>1);
			}
		     }
;

ForStmt
	: FOR ForClause Block
	| FOR Condition Block
;

ForClause
	: InitStmt ';' Condition ';' PostStmt
;

InitStmt
	: SimpleStmt
;

PostStmt
	: SimpleStmt
;

SwitchStmt
	: SWITCH Expression Block
;

CaseStmt
	: CaseUp Block
	| DEFAULT Block
;

CaseUp
	: CASE INT_LIT	{printf("case %d\n", $<item.value.i_val>2);}
;

ReturnType
	:		{funct_parameterReturn = (char*)malloc(sizeof(char)*1);
                         funct_parameterReturn[0] = 'V';
			 funct_parameter = (char*)malloc(sizeof(funct_parameterUp) + sizeof(funct_parameterIn) + sizeof(funct_parameterDown) + sizeof(funct_parameterReturn) + 1);
			 strcpy(funct_parameter, funct_parameterUp);
			 strcat(funct_parameter, funct_parameterIn);
			 strcat(funct_parameter, funct_parameterDown);
			 strcat(funct_parameter, funct_parameterReturn);
			 printf("func_signature: %s\n",funct_parameter);
			 insert_symbol(str_funct_name,"func",funct_parameter, 0);
			}
	| Type          {
                         funct_parameterReturn  = (char *)malloc(sizeof(char)*2);
                         funct_parameterReturn[1] = '\0';
                         funct_parameterReturn[0] = toupper($<item.value.s_val>1[0]);
			 funct_parameter = (char*)malloc(sizeof(funct_parameterUp) + sizeof(funct_parameterIn) + sizeof(funct_parameterDown) + sizeof(funct_parameterReturn) + 1);
                         strcpy(funct_parameter, funct_parameterUp);
                         strcat(funct_parameter, funct_parameterIn);
                         strcat(funct_parameter, funct_parameterDown);
                         strcat(funct_parameter, funct_parameterReturn);
                         printf("func_signature: %s\n",funct_parameter);
			 insert_symbol(str_funct_name,"func",funct_parameter, 0);
                        }

Type
	: INT		{$<item.value.s_val>$ = "int32";}
	| FLOAT		{$<item.value.s_val>$ = "float32";}
	| STRING	{$<item.value.s_val>$ = "string";}
	| BOOL		{$<item.value.s_val>$ = "bool";}
;

ParameterList
	: 		{ $<item.value.s_val>$ = ""; }
	| IDENT Type	 { 	char temp_str[2];
                                temp_str[1] = '\0';
                                temp_str[0] = toupper($<item.value.s_val>2[0]);
				$<item.value.s_val>$ = temp_str; 
				//$<item.value.s_val>$ = $<item.value.s_val>1;
				printf("param %s, type: %c\n", $<item.value.s_val>1,toupper($<item.value.s_val>2[0]));
				insert_symbol($<item.value.s_val>1,$<item.value.s_val>2,"-", 1);
			}
	
	| ParameterList ',' IDENT Type  {       char* extrac = (char *)malloc(sizeof($<item.value.s_val>4));
                                                strcpy(extrac, $<item.value.s_val>4);
                                         	printf("param %s, type: %c\n", $<item.value.s_val>3,toupper($<item.value.s_val>4[0]));
						insert_symbol($<item.value.s_val>3,extrac,"-", 1);
						char* temp_para_str = (char *)malloc(sizeof(char)*2);
						temp_para_str[1] = '\0';
						temp_para_str[0] = toupper($<item.value.s_val>4[0]);
                                        	
						char* combine = (char *)malloc(sizeof($<item.value.s_val>1) + sizeof(temp_para_str) + 1);
						strcpy(combine, $<item.value.s_val>1);
						strcat(combine, temp_para_str);
						$<item.value.s_val>$ = combine;
					}
                                         
;

ReturnStmt
	: RETURN Expression	{ printf("%creturn\n",$<item.type>2[0]);}
	| RETURN	{printf("return\n");}
;

PrintStmt
	: PRINT '(' Expression ')'	{printf("PRINT %s\n", $<item.type>3);}
	| PRINTLN '(' Expression ')'	{printf("PRINTLN %s\n", $<item.type>3);}
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

/* Symbol Table */
//int global_level = -1;
//int global_address = -1;

symtable_stack_type* stack_head = NULL; 

static void create_symbol() {
	// create a empty stack and set property
	global_level++;
	symtable_stack_type* tmp_stack = (symtable_stack_type *)malloc(sizeof(symtable_stack_type));
	tmp_stack -> table = NULL;
	tmp_stack -> level = global_level;
	// make it to be the head(newest) of current stack linked list
	tmp_stack -> next = stack_head;
	stack_head = tmp_stack;
	// print infomation
    	printf("> Create symbol table (scope level %d)\n", global_level);
}

static void insert_symbol(char* name, char* type, char* Func_sig, int para_bool) {
    	if(strcmp(type,"func")==0)
		printf("> Insert `%s` (addr: -1) to scope level %d\n", name, global_level-1);
	else
		printf("> Insert `%s` (addr: %d) to scope level %d\n", name, global_address, global_level);
	// Create a new table

	symtable_type* tmp_table = (symtable_type *)malloc(sizeof(symtable_type));
	
	tmp_table -> lineno = (strcmp(type, "func")==0 || (para_bool == 1))? yylineno+1 : yylineno ;
	tmp_table -> level = global_level;
	tmp_table -> address = (strcmp(type, "func")==0)? -1 : global_address;
	if (!(strcmp(type, "func")==0))
		global_address ++;
	
	tmp_table -> name = (char*) malloc (strlen(name) + 1);
        strcpy(tmp_table-> name, name);
	tmp_table -> func_sig = (char*)malloc(strlen(Func_sig) +1);
	strcpy(tmp_table->func_sig, Func_sig);
	tmp_table -> type = (char*)malloc(strlen(type) +1);
        strcpy(tmp_table->type, type);
	// Find the correct stack head
	symtable_stack_type* tmp_head = (symtable_stack_type*)malloc(0);
	if(strcmp(type,"func")==0)
		tmp_head = stack_head->next;
	else{
		tmp_head = stack_head;
	}
	// Make table to be the last one in head-stack
	if(!tmp_head->table){
		tmp_table -> index = 0;
		tmp_head -> table = tmp_table;
	}
	else{
		int last_index = 1;
		symtable_type* last_table = tmp_head -> table;
		while(last_table -> next){
			last_table = last_table -> next;
			last_index ++;
		}
		tmp_table -> index = last_index;
		last_table -> next = tmp_table;
		//tmp_tabletmp_table -> index = last_index;
	}
}

static symtable_type* lookup_symbol(char * name) {
	// from stack head
	symtable_stack_type* tmp_stack = stack_head;
	while(tmp_stack){
		// from the first table in this stack
		symtable_type* tmp_table = tmp_stack -> table;
		while(tmp_table){
			if(strcmp(tmp_table -> name,name)==0){
				return tmp_table;
			}
			tmp_table = tmp_table -> next;
		}
		tmp_stack = tmp_stack -> next;
	}
	return 0;
}

static char* find_para(char * name){
	// from stack head
        symtable_stack_type* tmp_stack = stack_head;
        while(tmp_stack){
                // from the first table in this stack
                symtable_type* tmp_table = tmp_stack -> table;
                while(tmp_table){
                        if(strcmp(tmp_table -> name,name)==0){
                                return tmp_table -> func_sig;
                        }
                        tmp_table = tmp_table -> next;
                }
                tmp_stack = tmp_stack -> next;
        }
        return 0;

}

static void dump_symbol() {
	printf("\n> Dump symbol table (scope level: %d)\n", global_level);
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
	// print all table in head stack
	symtable_type* tmp_table = stack_head -> table;
	while(tmp_table){
		printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",tmp_table->index, tmp_table->name, tmp_table->type, tmp_table->address, tmp_table->lineno, tmp_table->func_sig );
		tmp_table = tmp_table->next;
	}
	printf("\n");
	// change head by -1
	stack_head = stack_head-> next;
	global_level --;
}
