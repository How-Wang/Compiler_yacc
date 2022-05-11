/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    NEWLINE = 259,
    INT = 260,
    FLOAT = 261,
    BOOL = 262,
    STRING = 263,
    INC = 264,
    DEC = 265,
    GEQ = 266,
    LOR = 267,
    LAND = 268,
    EQ = 269,
    LEQ = 270,
    NEQ = 271,
    ADD_ASSIGN = 272,
    SUB_ASSIGN = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    IF = 277,
    ELSE = 278,
    FOR = 279,
    SWITCH = 280,
    CASE = 281,
    FUNC = 282,
    PRINT = 283,
    PACKAGE = 284,
    RETURN = 285,
    PRINTLN = 286,
    DEFAULT = 287,
    INT_LIT = 288,
    STRING_LIT = 289,
    BOOL_LIT = 290,
    FLOAT_LIT = 291,
    IDENT = 292
  };
#endif
/* Tokens.  */
#define VAR 258
#define NEWLINE 259
#define INT 260
#define FLOAT 261
#define BOOL 262
#define STRING 263
#define INC 264
#define DEC 265
#define GEQ 266
#define LOR 267
#define LAND 268
#define EQ 269
#define LEQ 270
#define NEQ 271
#define ADD_ASSIGN 272
#define SUB_ASSIGN 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define IF 277
#define ELSE 278
#define FOR 279
#define SWITCH 280
#define CASE 281
#define FUNC 282
#define PRINT 283
#define PACKAGE 284
#define RETURN 285
#define PRINTLN 286
#define DEFAULT 287
#define INT_LIT 288
#define STRING_LIT 289
#define BOOL_LIT 290
#define FLOAT_LIT 291
#define IDENT 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "compiler_hw2.y" /* yacc.c:1909  */

    struct{
	union{
 		int i_val;
		float f_val;
		char *s_val;
		bool b_val;
        }value;
    	char * type;
    }item;   

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
