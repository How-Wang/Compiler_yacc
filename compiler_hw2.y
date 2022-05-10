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
    static void insert_symbol();
    static symtable_type* Lookup_symbol();
    static void dump_symbol();
    /* Global variables */
    bool HAS_ERROR = false;




%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    union{
	int i_val;
    	float f_val;
    	char *s_val;
    	bool b_val;	
	}value;
    char * type;
    /* ... */
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING
%token INC DEC GEQ LOR LAND EQ LEQ NEQ
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token IF ELSE FOR SWITCH CASE FUNC
%token PRINT PACKAGE RETURN PRINTLN
%token Type 

%token DEFAULT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT
%token <b_val> BOOL_LIT
%token <f_val> FLOAT_LIT
%token <s_val> IDENT


/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    	: GlobalStatementList
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
        : PACKAGE IDENT		{printf("hello world\n");}
;

FunctionDeclStmt
        : FuncOpen '(' ParameterList ')' ReturnType FuncBlock {printf("hello 99\n");}
;


FuncOpen
        : FUNC IDENT
;

Expression
	: UnaryExpr
	| Expression binary_op Expression {if		(strcmp($<type>1, "bool") == 0) $<type>$ ="bool";
					   else if 	(strcmp($<type>1, "int" ) == 0) $<type>$ ="int";
					   else 					$<type>$ ="float";}
;

UnaryExpr
	: PrimaryExpr
	| unary_op UnaryExpr
;

binary_op
	: LOR
	| LAND
	| cmp_op
	| add_op
	| mul_op
;

cmp_op
	: EQ
	| NEQ
	| '<'
	| LEQ
	| '>'
	| GEQ
;

add_op
	: '+'	{ $<value.s_val>$="+";  printf("ADD\n"); }
	| '-'	{ $<value.s_val>$="-";  printf("SUB\n"); }
;

mul_op
	: '*'   { $<value.s_val>$="*";  printf("MUL\n"); }	  
	| '/'   { $<value.s_val>$="/";  printf("QUO\n"); }
	| '%'   { $<value.s_val>$="%";  printf("REM\n"); }
;

unary_op
	: '+'
	| '-'
	| '!'
;

PrimaryExpr
	: Operand
	| IndexExpr
	| ConversionExpr
;

IndexExpr
	: PrimaryExpr '[' Expression ']'
;

Operand
	: Literal
	| IDENT
	| '(' Expression ')'
;

Literal
	: INT_LIT
	| FLOAT_LIT
	| BOOL_LIT
	| '"' STRING_LIT '"'
;

ConversionExpr
	: Type '(' Expression ')'
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
	: AssignmentStmt
	| ExpressionStmt
	| IncDecStmt
;

DeclarationStmt
	: VAR IDENT Type
	| VAR IDENT Type '=' Expression
;

AssignmentStmt
	: Expression assign_op Expression
;

assign_op
	: '='
	| ADD_ASSIGN
	| SUB_ASSIGN
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
;

ExpressionStmt
	: Expression
;

IncDecStmt
	: Expression INC	{ printf("INC\n");}
	| Expression DEC	{ printf("DEC\n");}
;

Block
	: '{' StatementList '}'
;

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
	: Expression
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
	: CASE INT_LIT ':' Block
	| DEFAULT ':' Block
;

ReturnType
	: Type
;

ParameterList
	: 
	| IDENT Type
	| ParameterList ',' IDENT Type
;

FuncBlock
	: '{' StatementList '}'
;
ReturnStmt
	: RETURN Expression
	| RETURN
;

PrintStmt
	: PRINT '(' Expression ')'	{printf("PRINT %s\n", $<type>3);}
	| PRINTLN '(' Expression ')'	{printf("PRINTLN %s\n", $<type>3);}
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
int global_level = -1;
int global_address = -1;

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

static void insert_symbol(char* name, char* type, char* Func_sig) {
    	printf("> Insert `%s` (addr: %d) to scope level %d\n", name, global_address, global_level);
	// Create a new table
	symtable_type* tmp_table = (symtable_type *)malloc(sizeof(symtable_type));
	tmp_table -> lineno = yylineno;
	tmp_table -> level = global_level;
	tmp_table -> address = global_address;
	global_address ++;

	tmp_table -> name = (char*) malloc (strlen(name) + 1);
        strcpy(tmp_table-> name, name);
	tmp_table -> func_sig = (char*)malloc(strlen(Func_sig) +1);
	strcpy(tmp_table->func_sig, Func_sig);

	// Make table to be the last one in head-stack
	if(stack_head->table){
		tmp_table -> index = 0;
		stack_head -> table = tmp_table;
	}
	else{
		int last_index = 1;
		symtable_type* last_table = stack_head -> table;
		while(last_table -> next){
			last_table = last_table -> next;
			last_index ++;
		}
		last_table -> index = last_index;
		last_table -> next = tmp_table;
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

static void dump_symbol() {
	printf("\n> Dump symbol table (scope level: %d)\n", global_level);
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
	// print all table in head stack
	symtable_type* tmp_table = stack_head -> table;
	while(tmp_table){
		printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",tmp_table->index, tmp_table->name, tmp_table->type, tmp_table->address, tmp_table->lineno, tmp_table->func_sig );
		tmp_table = tmp_table->next;
	}
	// change head by -1
	stack_head = stack_head-> next;
	global_level --;
}
