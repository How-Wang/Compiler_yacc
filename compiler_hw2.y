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
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING
%token INC DEC GEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN
%token IF ELSE FOR SWITCH CASE
%token PRINT IDENT PACKAGE RETURN 

%token DEFAULT 

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <s_val> STRING_LIT

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
    :
;

FunctionDeclStmt
    :
;

Expression
	: UnaryExpr
	| Expression binary_op Expression
;

UnaryExpr
	: PrimaryExpr
	| unary_op UnaryExpr
;

binary
	: "||"
	| "&&"
	| cmp_op
	| add_op
	| mul_op
;

cmp_op
	: "=="
	| "!="
	| "<"
	| "<="
	| ">"
	| ">="
;

add_op
	: "+"
	| "-"
;

mul_op
	: "*"
	| "/"
	| "%"
;

unary_op
	: "+"
	| "-"
	| "!"
;

PrimaryExpr
	: Operand
	| IndexExpr
	| ConversionExpr
;

Operand
	: Literal
	| identifier
	| "(" Expression ")"
;

Literal
	: int_lit
	| float_lit
	| bool_lit
	| string_lit
;

ConversionExpr
	: Type "(" Expression ")"
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
	: "var" identifier Type
	| "var" identifier Type "=" Expression
;

AssignmentStmt
	: Expression assign_op Expression
;

assign_op
	: "="
	| "+="
	| "-="
	| "*="
	| "/="
	| "%="
;

ExpressionStmt
	: Expression
;

IncDecStmt
	: Expression INC
	| Expression DEC
;

Block
	: "{" StatementList "}"
;

StatementList 
	: Statement StatementList
	| Statement
;

IfStmt
	: "if" Condition Block
	| "if" Condition Block "else" IfStmt
	| "if" Condition Block "else" Block
;

Condition
	: Expression
;

ForStmt
	: "for" ForClause Block
	| "for" Condition Block
;

ForClause
	: InitStmt ";" Condition ";" PostStmt
;

InitStmt
	: SimpleStmt
;

PostStmt
	: SimpleStmt
;

SwitchStmt
	: "switch" Expression Block
;

CaseStmt
	: "case" INT_LIT ":" Block
	| DEFAULT ":" Block
;

GlobalStatement
	: PackageStmt NEWLINE 
	| FunctionDeclStmt
	| NEWLINE
;

PackageStmt
	: PACKAGE IDENT
;

FunctionDeclStmt
	: FuncOpen "(" ParameterList ")" ReturnType FuncBlock
;

ParameterList
	: %empty
	| IDENT Type
	| ParameterList "," IDENT Type
;

FuncBlock
	: "{" StatementList "}"
;

ReturnStmt
	: RETURN Expression
	| RETURN
;

PrintStmt
	: "print" "(" Expression ")"
	| "println" "(" Expression ")"
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
