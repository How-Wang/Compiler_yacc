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
    static void create_symbol();
    static void insert_symbol();
    static void lookup_symbol();
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
        : FuncOpen '(' ParameterList ')' ReturnType FuncBlock
;


FuncOpen
        : FUNC IDENT
;

Expression
	: UnaryExpr
	| Expression binary_op Expression {	if	(strcmp($<type>1, "bool") == 0) $<type>$ ="bool";
						else if (strcmp($<type>1, "int" ) == 0)$<type>$ ="int";
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
	: '*'
	| '/'
	| '%'
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
	: Expression INC
	| Expression DEC
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
	: PRINT '(' Expression ')'
	| PRINTLN '(' Expression ')'
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

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", 0);
}

static void insert_symbol() {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", "XXX", 0, 0);
}

static void lookup_symbol() {
}

static void dump_symbol() {
    printf("\n> Dump symbol table (scope level: %d)\n", 0);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
    printf("%-10d%-10s%-10s%-10d%-10d%-10s\n",
            0, "name", "type", 0, 0, "func_sig");
}
