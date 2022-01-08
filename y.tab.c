/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "limbaj.y"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylin;

/*#define YYDEBUG 1*/
/*yydebug = 1;*/


 int totalVar = 0;
 int func_count = 0;
 int scope = 0; /* 0 -> Global - 100000+ -> Function*/

struct dataType {
     char* id;
     char* data_type;
     int scope;
     int line_no;
     char* is_constant;
     int arrsize;
} var_table[100];

struct Func {
     char* Name;
     char* Scope;
     char* Return;
     int   line_no;
     char* ParamType[100];
     char* ParamName[100];
     int   ParamNumber;
} func_table[100];

struct CallStack {
     char* ParamType[100];
     char* ParamName[100];
     int   ParamNumber;
} call_stack;

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 46 "limbaj.y"
typedef union {
	char string[256]; 
	char* type_id;
     int intval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 77 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define Integer 257
#define Float 258
#define Character 259
#define Bool 260
#define String 261
#define Void 262
#define ID 263
#define CONST 264
#define NR 265
#define LOGICAL_AND 266
#define LOGICAL_OR 267
#define LS_EQ 268
#define GR_EQ 269
#define EQ 270
#define NOT_EQ 271
#define BGIN 272
#define END 273
#define ASSIGN 274
#define BEGINSTMT 275
#define ENDSTMT 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define FOR 280
#define CLASS 281
#define BEGINCLASS 282
#define ENDCLASS 283
#define PRIVATE 284
#define PROTECTED 285
#define PUBLIC 286
#define BEGINFNCTN 287
#define ENDFNCTN 288
#define RTRN 289
#define UMINUS 290
#define LOWER_THAN_ELSE 291
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    1,    1,    1,    1,    1,    1,    0,    4,    4,    5,
    6,    7,    9,    9,    2,    2,    2,    2,    2,    2,
   11,   11,   11,   11,   11,   16,   16,   17,   17,   17,
   17,   18,   18,   12,   14,   14,   19,   19,    3,   21,
   22,   13,   13,   13,   13,   20,   20,   15,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,   24,   24,   24,   25,
   26,   27,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   10,   10,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    1,    1,    1,
    4,    1,    4,    3,    2,    3,    2,    2,    3,    2,
    5,    4,    2,    4,    1,    2,    3,    1,    3,    3,
    3,    1,    3,    7,    1,    3,    2,    4,    3,    1,
    1,    8,    7,    9,    8,    2,    3,    5,    3,    3,
    3,    3,    3,    3,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    1,    1,    1,    1,    1,    5,
    5,   14,    2,    3,    4,    1,    1,    1,    1,    1,
    2,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,   25,    0,    0,    0,    0,    8,
    9,    0,    7,    0,   17,    0,   15,   18,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   82,   76,    0,    0,   77,   78,   79,
   16,   19,    0,    0,    0,    0,    0,    0,   69,    0,
    0,    0,    0,   68,    0,    0,   65,   66,    0,    0,
    0,   35,    0,    0,    0,    0,    0,    0,    0,    0,
   39,    0,   46,    0,    0,    0,   26,    0,    0,    0,
    0,    0,   55,   64,    0,   11,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   40,
    0,   10,    0,    0,    0,    0,    0,    0,    0,    0,
   14,    0,    0,   47,    0,    0,    0,   27,   32,    0,
    0,    0,    0,   54,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   51,   52,   53,    0,    0,   36,
    0,    0,    0,    0,    0,    0,   13,    0,    0,   22,
    0,    0,   34,   41,   43,   38,    0,   70,   71,    0,
    0,    0,    0,   21,   33,   42,    0,   45,    0,    0,
   44,    0,    0,    0,    0,    0,    0,   72,
};
static const YYINT yydgoto[] = {                          9,
   41,   11,   23,   42,   63,   64,   65,   66,   67,  123,
   56,   13,   14,   71,   45,   57,   58,  130,   72,   46,
  111,  165,   47,   68,   48,   49,   50,
};
static const YYINT yysindex[] = {                       478,
    0,    0,    0,    0,    0,    0,  337, -261,    0, -248,
  350,  -41,  -24,  109,    0, -221, -239,  -27, -219,    0,
    0,  653,    0,   11,    0,  209,    0,    0,    0, -196,
 -202,  328,    8,   98,    8,  -17,    8,    8, -187,    8,
 -187, -184,   54,    0,    0,  516,   19,    0,    0,    0,
    0,    0,   55,    8, -160,   42,  328, -246,    0,    8,
    8,    8,   54,    0,   12,  181,    0,    0, -169, -136,
  -32,    0,  181,   15,   26, -145,  181, -141,    8,   71,
    0,   81,    0,  184,  181,  -26,    0,   87, -116,  328,
  328,  328,    0,    0,   72,    0,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    0,
  653,    0,   73,  337, -169,  653,  653,    8,    8,  181,
    0,  181,  -25,    0, -169,   43,  199,    0,    0,  -33,
  328,  328,  328,    0,  284,  227,  489,  489,  393,  393,
  489,  489,  111,  111,    0,    0,    0,  549,   78,    0,
  653,  594,  618,   83,  181,    8,    0,  653, -169,    0,
   58,  -86,    0,    0,    0,    0,  549,    0,    0,    8,
  181,  549,  653,    0,    0,    0,  107,    0,  549, -187,
    0,  -85,    8,  114,  -87,  653,  642,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -39,  132,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -37,    0,    0,    0,  136,
    0,    0,  -77,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -162,    0,    0,    0,
    0,    0,  -13,    0,    0,  106,    0,    0,  143,    0,
    0,    0,  144,    0,    0,    0,  148,  154,    0,    0,
    0,    0,    0,    0,  177,  -39,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  119,    0,  183,    0,    0,    0,    0,  185,
    0,  129,    0,    0,    0,    0,    0,    0,    0,    0,
 -148,  -74,  179,    0,  304,   -8,  121,  134,  207,  219,
  146,  157,   38,   48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  186,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  141,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  758,    0,    0,  145,  465,  517,    0,  648,  547,    0,
  472,  235,  236,  -83,  510,  130,    0,    0,  135,  433,
  -98, -113,  361,    0,    0,    0,    0,
};
#define YYTABLESIZE 942
static const YYINT yytable[] = {                         10,
  126,   17,   10,   10,   10,   10,   10,   10,  115,   10,
  162,  114,   34,  127,   18,  157,  151,   27,  156,   10,
   10,   10,   10,   67,   10,  163,  158,   67,   67,   67,
   67,   67,   63,   67,   28,   63,   89,   90,   91,   92,
   61,   31,   32,  161,   67,   67,   67,   62,   67,   63,
   63,  109,   60,  176,   35,   10,  107,  105,  178,  106,
  173,  108,  109,   33,   33,  181,   53,  107,  105,   51,
  106,   54,  108,   33,  103,   36,  104,   83,   49,   67,
   49,   49,   49,  159,   63,  103,  114,  104,   50,   79,
   50,   50,   50,   80,   84,   49,   49,   49,  174,   49,
   87,  114,   86,   61,   96,   50,   50,   50,  109,   50,
   62,  121,  134,  107,  105,   60,  106,  110,  108,  109,
   28,   28,   28,   28,  107,  105,  112,  106,  118,  108,
   49,  103,  119,  104,   29,   29,   29,   29,   69,  124,
   50,  170,  103,  109,  104,  128,  129,  109,  107,  105,
  109,  106,  107,  108,   19,  107,  105,  108,  106,   37,
  108,   60,   37,  149,   60,  180,  103,   29,  104,   83,
  166,  185,   83,  103,   61,  104,  175,   61,   60,   60,
   60,   84,   60,   76,   84,   78,   57,  186,  183,   57,
   23,   61,   61,   61,   80,   61,    8,   56,   12,   19,
   56,   22,   24,   57,   57,   57,   81,   57,   30,   30,
   30,   30,   73,   60,   56,   56,   56,  109,   56,  131,
  132,  133,  107,  105,  125,  106,   61,  108,   10,   10,
   10,   10,   10,   10,   10,   48,   10,   10,   57,  160,
  103,   21,  104,   74,   75,   25,   26,   58,  150,   56,
   58,    0,   67,   67,   67,   67,   67,   67,   63,   59,
    0,   67,   59,  109,   58,   58,   63,   52,  107,  105,
   36,  106,   59,  108,    0,    0,   59,   59,    0,    0,
   97,   98,   99,  100,  101,  102,  103,    0,  104,  116,
    0,   97,   98,   99,  100,  101,  102,    0,    0,   58,
  117,    0,    0,   49,   49,   49,   49,   49,   49,    0,
    0,   59,   49,   50,   50,   50,   50,   50,   50,    0,
  109,    0,   50,    0,  182,  107,  105,    0,  106,    0,
  108,    0,    0,   36,    0,   59,    0,   97,   98,   99,
  100,  101,  102,  103,   62,  104,    0,   62,   97,   98,
   99,  100,  101,  102,    1,    2,    3,    4,    5,    6,
    0,   62,   62,    0,    0,    1,    2,    3,    4,    5,
    6,    0,   97,   98,   99,  100,  101,  102,    0,   97,
   98,   99,  100,  101,  102,    0,   60,   60,   60,   60,
   60,   60,    0,    0,    0,   60,   62,    0,    0,   61,
   61,   61,   61,   61,   61,    0,   82,    0,   61,    0,
    0,   57,   57,   57,   57,   57,   57,    0,    0,    0,
   57,    0,   56,   56,   56,   56,   56,   56,    0,  109,
    0,   56,    0,    0,  107,  105,    0,  106,    0,  108,
    1,    2,    3,    4,    5,    6,   97,   98,   99,  100,
  101,  102,  103,    0,  104,    1,    2,    3,    4,    5,
    6,   31,   31,   31,   31,    1,    2,    3,    4,    5,
    6,   12,   58,   58,   20,    0,   58,   58,    0,    0,
    0,   58,   24,    0,   59,   59,   43,    0,   59,   59,
    0,    0,   97,   59,   99,  100,  101,  102,    0,    0,
    0,    0,    0,   20,    0,   20,    0,    0,   82,   15,
   43,    0,   82,   82,    0,    0,    0,    0,    0,   20,
   15,    0,    0,    0,    0,  109,   21,   82,   88,    0,
  107,  105,   82,  106,  113,  108,    0,    0,   21,   82,
    0,   15,    0,  148,    0,    0,    0,   82,  152,  153,
    0,   99,  100,  101,  102,   21,    0,   21,    0,    0,
    0,    0,   21,    0,    0,    0,   15,    0,   44,   62,
   62,   21,    0,    0,    0,   43,    0,    0,   62,    0,
   43,   43,    0,  167,    1,    2,    3,    4,    5,    6,
  172,    7,   44,    1,    2,    3,    4,    5,    6,   15,
   15,   15,   88,   88,   88,  179,    1,    2,    3,    4,
    5,    6,   43,    7,    0,   43,   43,   43,  187,    0,
    0,   22,   43,    0,    0,    0,    0,   21,    0,    0,
    8,   43,   21,   21,    0,    0,   43,   43,    0,    0,
   15,   15,   15,   43,   20,    0,    0,    0,    0,    0,
   43,   43,    0,    0,    0,    0,    0,   44,    0,    0,
   99,  100,   44,   44,   21,    0,    0,   21,   21,   21,
    0,    0,    0,    0,   21,    0,    0,    0,    0,    0,
    0,    0,   73,   21,   74,   75,    0,   77,   21,   21,
    0,    0,    0,    0,   44,   21,   21,   44,   44,   44,
    0,   85,   21,   21,   44,    0,    0,   93,   94,   95,
    0,    0,    0,   44,    0,    0,    0,    0,   44,   44,
    0,    0,    0,    0,    0,   44,  120,  122,    0,    0,
    0,    0,   44,   44,    1,    2,    3,    4,    5,    6,
    0,    7,    0,    0,  135,  136,  137,  138,  139,  140,
  141,  142,  143,  144,  145,  146,  147,   10,    8,    0,
    0,    0,    0,    0,   16,  154,  155,    0,   10,    0,
    0,   30,    1,    2,    3,    4,    5,    6,   36,    7,
    0,    0,    0,   30,    0,    0,    0,    0,   81,   55,
    0,   70,   37,    0,   38,   39,    0,    0,    0,    0,
    0,    0,    0,  171,   40,    1,    2,    3,    4,    5,
    6,   36,    7,    0,   55,    0,    0,  177,    0,    0,
    0,    0,    0,    0,    0,   37,    0,   38,   39,    0,
  184,    0,    0,    0,    0,    0,  164,   40,    0,    0,
    0,   70,    0,    0,    0,    0,    0,   55,   55,   55,
    1,    2,    3,    4,    5,    6,   36,    7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  168,
   37,   70,   38,   39,    1,    2,    3,    4,    5,    6,
   36,    7,   40,    0,   70,    0,    0,    0,   55,   55,
   55,    0,    0,  169,   37,    0,   38,   39,    1,    2,
    3,    4,    5,    6,   36,    7,   40,    0,    0,    1,
    2,    3,    4,    5,    6,   36,    7,  188,   37,    0,
   38,   39,    0,    0,    0,    0,    0,    0,    0,   37,
   40,   38,   39,    0,    0,    0,    0,    0,    0,    0,
    0,   40,
};
static const YYINT yycheck[] = {                         37,
   84,  263,   40,   41,   42,   43,   44,   45,   41,   47,
   44,   44,   40,   40,  263,   41,  115,   59,   44,   59,
   58,   59,   60,   37,   62,   59,  125,   41,   42,   43,
   44,   45,   41,   47,   59,   44,  283,  284,  285,  286,
   33,  263,  282,  127,   58,   59,   60,   40,   62,   58,
   59,   37,   45,  167,  274,   93,   42,   43,  172,   45,
  159,   47,   37,   91,   91,  179,  263,   42,   43,   59,
   45,  274,   47,   91,   60,  263,   62,   59,   41,   93,
   43,   44,   45,   41,   93,   60,   44,   62,   41,  274,
   43,   44,   45,   40,   40,   58,   59,   60,   41,   62,
   59,   44,  263,   33,   93,   58,   59,   60,   37,   62,
   40,   41,   41,   42,   43,   45,   45,  287,   47,   37,
  283,  284,  285,  286,   42,   43,  263,   45,  274,   47,
   93,   60,  274,   62,  283,  284,  285,  286,   41,   59,
   93,   59,   60,   37,   62,   59,  263,   37,   42,   43,
   37,   45,   42,   47,   10,   42,   43,   47,   45,   41,
   47,   41,   44,   91,   44,   59,   60,   59,   62,   41,
   93,   58,   44,   60,   41,   62,  263,   44,   58,   59,
   60,   41,   62,   39,   44,   41,   41,  275,  274,   44,
   59,   58,   59,   60,   59,   62,  274,   41,   93,   55,
   44,   59,   59,   58,   59,   60,   59,   62,  283,  284,
  285,  286,   59,   93,   58,   59,   60,   37,   62,   90,
   91,   92,   42,   43,   41,   45,   93,   47,  266,  267,
  268,  269,  270,  271,  274,   59,  274,  275,   93,   41,
   60,   59,   62,   59,   59,   11,   11,   41,  114,   93,
   44,   -1,  266,  267,  268,  269,  270,  271,  267,   41,
   -1,  275,   44,   37,   58,   59,  275,   59,   42,   43,
  263,   45,  265,   47,   -1,   -1,   58,   59,   -1,   -1,
  266,  267,  268,  269,  270,  271,   60,   -1,   62,  275,
   -1,  266,  267,  268,  269,  270,  271,   -1,   -1,   93,
  275,   -1,   -1,  266,  267,  268,  269,  270,  271,   -1,
   -1,   93,  275,  266,  267,  268,  269,  270,  271,   -1,
   37,   -1,  275,   -1,  180,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,  263,   -1,  265,   -1,  266,  267,  268,
  269,  270,  271,   60,   41,   62,   -1,   44,  266,  267,
  268,  269,  270,  271,  257,  258,  259,  260,  261,  262,
   -1,   58,   59,   -1,   -1,  257,  258,  259,  260,  261,
  262,   -1,  266,  267,  268,  269,  270,  271,   -1,  266,
  267,  268,  269,  270,  271,   -1,  266,  267,  268,  269,
  270,  271,   -1,   -1,   -1,  275,   93,   -1,   -1,  266,
  267,  268,  269,  270,  271,   -1,   46,   -1,  275,   -1,
   -1,  266,  267,  268,  269,  270,  271,   -1,   -1,   -1,
  275,   -1,  266,  267,  268,  269,  270,  271,   -1,   37,
   -1,  275,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
  257,  258,  259,  260,  261,  262,  266,  267,  268,  269,
  270,  271,   60,   -1,   62,  257,  258,  259,  260,  261,
  262,  283,  284,  285,  286,  257,  258,  259,  260,  261,
  262,    0,  266,  267,   10,   -1,  270,  271,   -1,   -1,
   -1,  275,   11,   -1,  266,  267,   22,   -1,  270,  271,
   -1,   -1,  266,  275,  268,  269,  270,  271,   -1,   -1,
   -1,   -1,   -1,   39,   -1,   41,   -1,   -1,  148,    0,
   46,   -1,  152,  153,   -1,   -1,   -1,   -1,   -1,   55,
   11,   -1,   -1,   -1,   -1,   37,   10,  167,   57,   -1,
   42,   43,  172,   45,   70,   47,   -1,   -1,   22,  179,
   -1,   32,   -1,  111,   -1,   -1,   -1,  187,  116,  117,
   -1,  268,  269,  270,  271,   39,   -1,   41,   -1,   -1,
   -1,   -1,   46,   -1,   -1,   -1,   57,   -1,   22,  266,
  267,   55,   -1,   -1,   -1,  111,   -1,   -1,  275,   -1,
  116,  117,   -1,  151,  257,  258,  259,  260,  261,  262,
  158,  264,   46,  257,  258,  259,  260,  261,  262,   90,
   91,   92,  131,  132,  133,  173,  257,  258,  259,  260,
  261,  262,  148,  264,   -1,  151,  152,  153,  186,   -1,
   -1,  272,  158,   -1,   -1,   -1,   -1,  111,   -1,   -1,
  281,  167,  116,  117,   -1,   -1,  172,  173,   -1,   -1,
  131,  132,  133,  179,  180,   -1,   -1,   -1,   -1,   -1,
  186,  187,   -1,   -1,   -1,   -1,   -1,  111,   -1,   -1,
  268,  269,  116,  117,  148,   -1,   -1,  151,  152,  153,
   -1,   -1,   -1,   -1,  158,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   35,  167,   37,   38,   -1,   40,  172,  173,
   -1,   -1,   -1,   -1,  148,  179,  180,  151,  152,  153,
   -1,   54,  186,  187,  158,   -1,   -1,   60,   61,   62,
   -1,   -1,   -1,  167,   -1,   -1,   -1,   -1,  172,  173,
   -1,   -1,   -1,   -1,   -1,  179,   79,   80,   -1,   -1,
   -1,   -1,  186,  187,  257,  258,  259,  260,  261,  262,
   -1,  264,   -1,   -1,   97,   98,   99,  100,  101,  102,
  103,  104,  105,  106,  107,  108,  109,    0,  281,   -1,
   -1,   -1,   -1,   -1,    7,  118,  119,   -1,   11,   -1,
   -1,   14,  257,  258,  259,  260,  261,  262,  263,  264,
   -1,   -1,   -1,   26,   -1,   -1,   -1,   -1,  273,   32,
   -1,   34,  277,   -1,  279,  280,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  156,  289,  257,  258,  259,  260,  261,
  262,  263,  264,   -1,   57,   -1,   -1,  170,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  277,   -1,  279,  280,   -1,
  183,   -1,   -1,   -1,   -1,   -1,  288,  289,   -1,   -1,
   -1,   84,   -1,   -1,   -1,   -1,   -1,   90,   91,   92,
  257,  258,  259,  260,  261,  262,  263,  264,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,
  277,  114,  279,  280,  257,  258,  259,  260,  261,  262,
  263,  264,  289,   -1,  127,   -1,   -1,   -1,  131,  132,
  133,   -1,   -1,  276,  277,   -1,  279,  280,  257,  258,
  259,  260,  261,  262,  263,  264,  289,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,  276,  277,   -1,
  279,  280,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,
  289,  279,  280,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  289,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 321
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Integer","Float","Character","Bool","String",
"Void","ID","CONST","NR","LOGICAL_AND","LOGICAL_OR","LS_EQ","GR_EQ","EQ",
"NOT_EQ","BGIN","END","ASSIGN","BEGINSTMT","ENDSTMT","IF","ELSE","WHILE","FOR",
"CLASS","BEGINCLASS","ENDCLASS","PRIVATE","PROTECTED","PUBLIC","BEGINFNCTN",
"ENDFNCTN","RTRN","UMINUS","LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : progr",
"DATA_TYPE : Integer",
"DATA_TYPE : Float",
"DATA_TYPE : Character",
"DATA_TYPE : Bool",
"DATA_TYPE : String",
"DATA_TYPE : Void",
"progr : declaratii bloc",
"lhs : identifier",
"lhs : array_access",
"identifier : ID",
"array_access : ID '[' array_index ']'",
"array_index : expr",
"function_call : identifier '(' lista_apel ')'",
"function_call : identifier '(' ')'",
"declaratii : declaratie ';'",
"declaratii : declaratii declaratie ';'",
"declaratii : declaratii initializare_clasa",
"declaratii : initializare_clasa ';'",
"declaratii : declaratii descriere_functii ';'",
"declaratii : descriere_functii ';'",
"declaratie : DATA_TYPE ID '(' lista_param ')'",
"declaratie : DATA_TYPE ID '(' ')'",
"declaratie : DATA_TYPE lhs",
"declaratie : DATA_TYPE lhs ASSIGN expr",
"declaratie : constant",
"declaratii_clasa : declaratie ';'",
"declaratii_clasa : declaratii_clasa declaratie ';'",
"bloc_clasa : declaratii_clasa",
"bloc_clasa : bloc_clasa PRIVATE declaratii_clasa",
"bloc_clasa : bloc_clasa PROTECTED declaratii_clasa",
"bloc_clasa : bloc_clasa PUBLIC declaratii_clasa",
"lista_id_clasa : ID",
"lista_id_clasa : lista_id_clasa ',' ID",
"initializare_clasa : CLASS ID BEGINCLASS bloc_clasa ENDCLASS lista_id_clasa ';'",
"lista_param : param",
"lista_param : lista_param ',' param",
"param : DATA_TYPE identifier",
"param : DATA_TYPE identifier '[' ']'",
"bloc : BGIN list END",
"enter_func : BEGINFNCTN",
"leave_func : ENDFNCTN",
"descriere_functii : DATA_TYPE ID '(' lista_param ')' enter_func list leave_func",
"descriere_functii : DATA_TYPE ID '(' ')' enter_func list leave_func",
"descriere_functii : descriere_functii DATA_TYPE ID '(' lista_param ')' enter_func list leave_func",
"descriere_functii : descriere_functii DATA_TYPE ID '(' ')' enter_func list leave_func",
"list : statement ';'",
"list : list statement ';'",
"constant : CONST DATA_TYPE ID ASSIGN expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : '(' expr ')'",
"expr : '-' expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr EQ expr",
"expr : expr NOT_EQ expr",
"expr : expr LS_EQ expr",
"expr : expr GR_EQ expr",
"expr : expr LOGICAL_AND expr",
"expr : expr LOGICAL_OR expr",
"expr : '!' expr",
"expr : function_call",
"expr : operand",
"operand : identifier",
"operand : array_access",
"operand : NR",
"if_stmt : IF expr BEGINSTMT list ENDSTMT",
"while_stmt : WHILE expr BEGINSTMT list ENDSTMT",
"for_stmt : FOR lhs ASSIGN expr ';' expr ';' lhs ASSIGN expr ':' BEGINSTMT list ENDSTMT",
"statement : DATA_TYPE lhs",
"statement : lhs ASSIGN expr",
"statement : DATA_TYPE lhs ASSIGN expr",
"statement : constant",
"statement : if_stmt",
"statement : while_stmt",
"statement : for_stmt",
"statement : RTRN",
"statement : RTRN expr",
"statement : function_call",
"lista_apel : expr",
"lista_apel : lista_apel ',' expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 232 "limbaj.y"
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

void PrintVar()
{
    printf("\n\n");
	printf("\nSYMBOL\tIS_CONSTANT\tDATATYPE\tSCOPE\tLINE NUMBER\tARRAY SIZE\n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i < totalVar; i++) {
		printf("%s\t%s\t%s\t%d\t%d\t%d\n", var_table[i].id, var_table[i].is_constant, var_table[i].data_type, var_table[i].scope, var_table[i].line_no, var_table[i].arrsize);
	}
	for(i=0;i < totalVar;i++) {
		free(var_table[i].id);
		free(var_table[i].data_type);
		free(var_table[i].is_constant);
	}
	printf("\n\n");
}

void PrintFunc()
{
    printf("\n\n");
	printf("\nNAME\t\tSCOPE\t\tRETURN_TYPE\tPARAM_NUMBER\tLINE_NUMBER\n");
	printf("_______________________________________\n\n");

	for(int i=0; i < func_count; i++) {
		printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n", func_table[i].Name, func_table[i].Scope, func_table[i].Return, func_table[i].ParamNumber, func_table[i].line_no);
	     printf("PARAM_TYPE\tPARAM_NAME\n");

          for (int j = 0; j <  func_table[i].ParamNumber; ++j)
               printf("%s\t%s\n", func_table[i].ParamType[j], func_table[i].ParamName[j]);

          printf("\n\n");
	}

	for(int i=0; i < func_count; i++)
     {
		free(func_table[i].Name);
		free(func_table[i].Scope);
		free(func_table[i].Return);

          for (int j = 0; j <  func_table[i].ParamNumber; ++j)
          {
		     free(func_table[i].ParamType[j]);
		     free(func_table[i].ParamName[j]);
          }
	}

	printf("\n\n");
}

int getVariableIndex(char* varName)
{
	for (int i = 0; i < totalVar; i++) 
		if (strcmp(varName, var_table[i].id) == 0)
			return i;

	return -1;
}

void pushEmptyVariable(char* id, char* type, char* constant, int arrsize)
{
	int i = getVariableIndex(id);

	if (i != -1)
    {
		printf("The variable %s was already declared on line %d\n", id, var_table[i].line_no);
		exit(0);
	}

     var_table[totalVar].id = strdup(id);
     var_table[totalVar].data_type = strdup(type);
     var_table[totalVar].line_no = yylineno;
     var_table[totalVar].is_constant = strdup(constant);
     var_table[totalVar].scope = scope;
     var_table[totalVar].arrsize = arrsize;

	totalVar++;
}

void PrintErrorAndExit(int x)
{
     switch(x)
     {
          case 1:
               printf("Cannot have  VOID data type for variables.\n");
               exit(0);
               break;
          case 2:
               printf("The header of the function was not declared (line %d).\n", yylineno);
               exit(0);
               break;
          case 3:
               printf("Array identified negative or above declared size. (line %d)\n", yylineno);
               exit(0);
          case 4:
               printf("ERROR! You cannot use a non-declared variable (line %d)\n", yylineno);
               exit(0);
          case 5:
               printf("ERROR! You cannot declare more than once same variable (line %d).\n", yylineno);
               exit(0);
     }
}

int getFunctionIndex(char* varName)
{
	for (int i = 0; i < func_count; i++) 
		if (strcmp(varName, func_table[i].Name) == 0)
			return i;

	return -1;
}

void CheckForErrors(int x, char* var)
{
     switch(x)
     {
          case 1:
          if (strcmp(var, "Void") == 0)
               PrintErrorAndExit(1);
               break;
          case 2:
          {
               int i = getFunctionIndex(var);

               if (i == -1)
                    PrintErrorAndExit(2);
               break;
          }
     }
}

void CheckArrayRange(char* arr, int pos)
{
     int i = getVariableIndex(arr);

     if (i == -1)
          PrintErrorAndExit(4);

     if (pos < 0 || pos > var_table[i].arrsize)
          PrintErrorAndExit(3);
}

void PushFunction(char* name, char* ret_type)
{
	int i = getFunctionIndex(name);

	if (i != -1)
     {
		PrintErrorAndExit(5);
	}

     func_table[func_count].Name = strdup(name);
     func_table[func_count].Return = strdup(ret_type);
     func_table[func_count].line_no = yylineno;

	func_count++;
}

void PushParameters(char* id, char* type)
{
     int *j = &func_table[func_count].ParamNumber;

     func_table[func_count].ParamType[*j] = strdup(type);
     func_table[func_count].ParamName[*j] = strdup(id);

     (*j)++;
}

void InsertIntoCallStack(char* id, char* type)
{
     int *j = &call_stack.ParamNumber;

     call_stack.ParamType[*j] = strdup(type);
     call_stack.ParamName[*j] = strdup(id);

     (*j)++;
}

void ResetCallStack()
{
     int *j = &call_stack.ParamNumber;

     for (int i = 0; i < *j; ++i)
     {
          free(call_stack.ParamType[*j]);
          free(call_stack.ParamName[*j]);
     }

     (*j) = 0;
}


void EnterFunction()
{
     scope += 100000 + getFunctionIndex(yylval.string);
}
void ExitFunction()
{
     scope = 0;
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
//PrintVar();
//PrintFunc();
}
#line 795 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 75 "limbaj.y"
	{yyval.type_id = strdup("Integer");}
break;
case 2:
#line 76 "limbaj.y"
	{yyval.type_id = strdup("Float");}
break;
case 3:
#line 77 "limbaj.y"
	{yyval.type_id = strdup("Character");}
break;
case 4:
#line 78 "limbaj.y"
	{yyval.type_id = strdup("Bool");}
break;
case 5:
#line 79 "limbaj.y"
	{yyval.type_id = strdup("String");}
break;
case 6:
#line 80 "limbaj.y"
	{yyval.type_id = strdup("Void");}
break;
case 7:
#line 83 "limbaj.y"
	{printf("program corect sintactic\n");}
break;
case 21:
#line 112 "limbaj.y"
	{ PushFunction(yystack.l_mark[-3].string, yystack.l_mark[-4].type_id); }
break;
case 22:
#line 113 "limbaj.y"
	{ PushFunction(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id); }
break;
case 40:
#line 150 "limbaj.y"
	{ EnterFunction(); }
break;
case 41:
#line 153 "limbaj.y"
	{ ExitFunction(); }
break;
case 42:
#line 158 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].string); }
break;
case 43:
#line 159 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-5].string); }
break;
case 44:
#line 160 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-7].type_id); }
break;
case 45:
#line 161 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].type_id); }
break;
case 48:
#line 171 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "true", 0);}
break;
#line 1058 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
