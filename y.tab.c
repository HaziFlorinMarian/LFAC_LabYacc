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
#line 42 "limbaj.y"
typedef union {
	char var_name[256];
	char* type_id;
     int intval;
     char* string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 74 "y.tab.c"

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
#define NR 264
#define LOGICAL_AND 265
#define LOGICAL_OR 266
#define LS_EQ 267
#define GR_EQ 268
#define EQ 269
#define NOT_EQ 270
#define BGIN 271
#define END 272
#define ASSIGN 273
#define BEGINSTMT 274
#define ENDSTMT 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define FOR 279
#define CLASS 280
#define BEGINCLASS 281
#define ENDCLASS 282
#define PRIVATE 283
#define PROTECTED 284
#define PUBLIC 285
#define BEGINFNCTN 286
#define ENDFNCTN 287
#define RTRN 288
#define CONST 289
#define UMINUS 290
#define LOWER_THAN_ELSE 291
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    1,    1,    1,    1,    1,    1,    0,    3,    3,    2,
    2,    4,    5,    9,    9,    6,    6,    6,    6,    6,
    6,   11,   11,   11,   11,   11,   16,   16,   17,   17,
   17,   17,   18,   18,   12,   14,   14,   19,   19,    7,
   21,   22,   13,   13,   13,   13,   20,   20,   15,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,   24,   24,   24,
   25,   26,   27,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   10,   10,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    1,    4,    1,
    1,    1,    4,    4,    3,    2,    3,    2,    2,    3,
    2,    5,    4,    2,    4,    1,    2,    3,    1,    3,
    3,    3,    1,    3,    7,    1,    3,    2,    4,    3,
    1,    1,    8,    7,    9,    8,    2,    3,    5,    3,
    3,    3,    3,    3,    3,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    1,    1,    1,    1,    1,
    5,    5,   14,    2,    3,    4,    1,    1,    1,    1,
    1,    2,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,   26,    0,    0,    0,    0,    0,
    0,    7,    0,   18,    0,   16,   19,   21,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   11,   83,   77,    0,    0,   78,   79,   80,
   17,   20,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   36,   70,    0,    0,    0,    0,   69,    0,   66,
   67,    0,    0,    0,    0,    0,   10,    0,    0,    0,
    0,   40,    0,   47,    0,    0,   27,    0,    0,    0,
    0,    0,    0,   41,    0,   12,    0,    0,    0,   56,
   65,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    9,    0,    0,    0,    0,
    0,    0,   15,    0,    0,   48,    0,    0,    0,   28,
   33,    0,    0,    0,    0,    0,    0,   37,    0,   55,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   52,   53,   54,   13,    0,    0,    0,    0,    0,   14,
    0,    0,   23,    0,    0,   35,   42,   44,   39,    0,
   71,   72,    0,    0,    0,    0,   22,   34,   43,    0,
   46,    0,    0,   45,    0,    0,    0,    0,    0,    0,
   73,
};
static const YYINT yydgoto[] = {                          9,
   40,   41,   19,   67,   68,   11,   22,   69,   70,  125,
   55,   13,   14,   61,   45,   56,   57,  132,   62,   46,
   95,  168,   47,   71,   48,   49,   50,
};
static const YYINT yysindex[] = {                       727,
    0,    0,    0,    0,    0,    0, -261,  -49,    0, -249,
  364,  -41,  -40,  107,    0, -246, -225,   19, -218,  -25,
  720,    0,    8,    0,  260,    0,    0,    0, -193,  300,
 -201,   97,  123, -188,   -1,  123,  123, -185,  123, -185,
 -179,   45,    0,    0,    0,  600,   36,    0,    0,    0,
    0,    0,   61, -160,   46,  300, -161,  123, -168, -136,
   -4,    0,    0,  123,  123,  123,   45,    0,  228,    0,
    0,   42,  123,   15,   26, -144,    0,  228, -129,  123,
   71,    0,   80,    0,  182,  106,    0,   94, -112,  300,
  300,  300,  228,    0,  720,    0,   67,  -49, -168,    0,
    0,   72,  123,  123,  123,  123,  123,  123,  123,  123,
  123,  123,  123,  123,  123,    0,   83,  720,  720,  123,
  123,  228,    0,  228,    9,    0, -168,   10,  245,    0,
    0,  -43,  300,  300,  300,  640,   68,    0,  720,    0,
  347,  283,  148,  148,  420,  420,  148,  148,  133,  133,
    0,    0,    0,    0,  647,  680,  105,  228,  123,    0,
  720, -168,    0,   43, -101,    0,    0,    0,    0,  640,
    0,    0,  123,  228,  640,  720,    0,    0,    0,  112,
    0,  640, -185,    0, -104,  123,  136,  -97,  720,  687,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -26,  125,  -46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -37,    0,    0,    0,  128,    0,
    0,  -91,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -6,    0,    0,  129,    0,
    0,    0,    0,    0,    0,    0,  -13,    0,  140,    0,
    0,    0,    0,    0,    0,    0,    0,  142,  143,    0,
    0,    0,    0,    0,    0,  -26,    0,    0,    0,    0,
    0,    0,  147,    0,    0,    0,   58,    0,  158,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  160,    0,   92,    0,    0,    0,    0,    0,    0,
    0,    0,  149,  201,  242,    0,    0,    0,    0,    0,
  417,  -32,  145,  156,  303,  394,  181,  204,   38,   48,
    0,    0,    0,    0,    0,    0,    0,  161,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   96,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
  752,  -23,    0,  553,  491,    0,    0,  710,  583,    0,
  445,  210,  213,  -65,  564,  -48,    0,    0,  137,  395,
  -88, -134,  353,    0,    0,    0,    0,
};
#define YYTABLESIZE 1016
static const YYINT yytable[] = {                         12,
  165,   16,   12,   12,   12,   12,   12,   12,   64,   12,
  139,   64,    8,   18,   76,  166,   79,   26,   27,  128,
   12,   12,   12,   68,   12,   64,   64,   68,   68,   68,
   68,   68,   12,   68,   30,  179,   99,   31,  161,   98,
  181,  133,  134,  135,   68,   68,   68,  184,   68,  160,
  162,  115,  159,   98,   33,   12,  113,  111,   32,  112,
   64,  114,  115,  164,   12,   34,   51,  113,  111,   53,
  112,   58,  114,  176,  109,   72,  110,   35,   50,   68,
   50,   50,   50,  177,   81,  109,   98,  110,   51,   73,
   51,   51,   51,   80,   84,   50,   50,   50,   38,   50,
   85,   38,   86,   65,   87,   51,   51,   51,  115,   51,
   66,  123,  140,  113,  111,   64,  112,   94,  114,  115,
   89,   90,   91,   92,  113,  111,   96,  112,  120,  114,
   50,  109,   84,  110,  116,   84,   85,   59,  126,   85,
   51,  115,  109,  121,  110,  129,  113,  111,  115,  112,
  131,  114,  130,  113,  111,   65,  112,  137,  114,  185,
  169,  178,   66,  173,  109,   28,  110,   64,  186,  115,
  183,  109,  115,  110,  113,  154,  189,  113,  111,  114,
  112,   10,  114,   24,  115,   61,   81,   23,   61,  113,
  111,    0,  112,  188,  114,  109,   62,  110,   25,   62,
   82,   74,   61,   61,   61,   49,   61,    1,    2,    3,
    4,    5,    6,   62,   62,   62,   22,   62,   75,   76,
   24,   58,  127,   25,   58,    0,    8,   12,   12,   12,
   12,   12,   12,   64,  138,   12,   12,   61,   58,   58,
   58,   64,   58,    0,   57,    0,   12,   57,   62,    0,
    0,   68,   68,   68,   68,   68,   68,    0,    0,    0,
   68,   57,   57,   57,  115,   57,    0,    0,    0,  113,
  111,    0,  112,   58,  114,   29,   29,   29,   29,  103,
  104,  105,  106,  107,  108,  163,    0,  109,  118,  110,
  103,  104,  105,  106,  107,  108,   57,    0,    0,  119,
    0,    0,   50,   50,   50,   50,   50,   50,    0,    0,
    0,   50,   51,   51,   51,   51,   51,   51,   52,  115,
    0,   51,    0,    0,  113,  111,    0,  112,    0,  114,
    0,    0,    0,   35,   63,    0,  103,  104,  105,  106,
  107,  108,  109,   59,  110,    0,   59,  103,  104,  105,
  106,  107,  108,    1,    2,    3,    4,    5,    6,    0,
   59,   59,    0,    1,    2,    3,    4,    5,    6,  103,
  104,  105,  106,  107,  108,    0,  103,  104,  105,  106,
  107,  108,    0,  115,    0,   35,   63,    0,  113,  111,
    0,  112,    0,  114,    0,   59,    0,    0,   83,    0,
  103,  104,  105,  106,  107,  108,  109,    0,  110,   61,
   61,   61,   61,   61,   61,    0,    0,    0,   61,    0,
   62,   62,   62,   62,   62,   62,    0,    0,    0,   62,
   30,   30,   30,   30,   60,    0,    0,   60,    1,    2,
    3,    4,    5,    6,   12,   58,   58,   58,   58,   58,
   58,   60,   60,    0,   58,   23,  115,   63,    0,    0,
   63,  113,  111,    0,  112,    0,  114,    0,   57,   57,
   57,   57,   57,   57,   63,   63,    0,   57,    0,  109,
    0,  110,   31,   31,   31,   31,   60,    0,   83,  136,
    0,    0,  103,  104,  105,  106,  107,  108,    0,    0,
   88,    1,    2,    3,    4,    5,    6,   83,   83,   63,
    0,   43,  155,  156,    0,    0,    1,    2,    3,    4,
    5,    6,   83,   32,   32,   32,   32,   83,   43,    0,
   43,    0,    0,  170,   83,    0,   43,    0,    0,    0,
    0,    0,   83,    0,    0,    0,    0,  103,    0,  105,
  106,  107,  108,    0,    0,  175,    1,    2,    3,    4,
    5,    6,   20,   15,    0,    0,    0,   59,   59,    0,
  182,   59,   59,   42,   15,    0,   59,   88,   88,   88,
    0,    0,    0,  190,    0,   43,    0,    0,    8,    0,
   77,    0,   77,   15,    0,    0,    0,    0,   42,    0,
    0,    0,    0,   44,    0,    0,   20,    0,   43,   43,
    0,    0,   97,  105,  106,  107,  108,    0,    0,   15,
    1,    2,    3,    4,    5,    6,   43,    0,   44,   43,
    0,    0,    0,    0,   21,    0,    0,    0,    0,    0,
    0,    0,    0,    7,    0,   43,   43,   42,    0,    0,
    0,   43,    8,   15,   15,   15,    0,    0,   60,   60,
   43,    0,   60,   60,    0,   43,   43,   60,    0,    0,
   42,   42,   43,   43,    0,    0,    0,   44,    0,   43,
   43,   63,   63,    0,    0,    0,  105,  106,   42,    0,
   63,   42,    0,    0,    0,    0,   15,   15,   15,    0,
   44,   44,    0,    0,    0,    0,    0,   42,   42,    0,
    0,    0,    0,   42,    0,    0,    0,    0,   44,    0,
    0,   44,   42,    0,    0,    0,    0,   42,   42,    0,
    0,    0,    0,    0,   42,   77,    0,   44,   44,    0,
    0,   42,   42,   44,    0,   74,   75,    0,   78,    0,
    0,   10,   44,    0,    0,    0,    0,   44,   44,   17,
    0,    0,   10,    0,   44,   29,    0,   93,    0,    0,
    0,   44,   44,  100,  101,  102,   29,    0,    0,    0,
    0,   54,  117,   60,    0,    0,    0,    0,    0,  122,
  124,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   54,    0,    0,
    0,    0,  141,  142,  143,  144,  145,  146,  147,  148,
  149,  150,  151,  152,  153,    0,    0,    0,    0,  157,
  158,    0,    0,    0,    0,    0,   60,    0,    0,    0,
    0,   54,   54,   54,    0,    0,    0,    0,    0,   60,
    0,    0,    0,    0,    0,    0,    1,    2,    3,    4,
    5,    6,   35,    0,    0,    0,    0,    0,  174,    0,
    0,   82,    0,    0,    0,   36,    0,   37,   38,    0,
   60,    0,  180,    0,   54,   54,   54,   39,    8,    0,
    0,    0,    0,    0,    0,  187,    1,    2,    3,    4,
    5,    6,   35,    1,    2,    3,    4,    5,    6,   35,
    0,    0,    0,    0,    0,   36,    0,   37,   38,    0,
    0,  171,   36,    0,   37,   38,  167,   39,    8,    0,
    0,    0,    0,    0,   39,    8,    1,    2,    3,    4,
    5,    6,   35,    1,    2,    3,    4,    5,    6,   35,
    0,    0,    0,    0,  172,   36,    0,   37,   38,    0,
    0,  191,   36,    0,   37,   38,    0,   39,    8,    0,
    0,    0,    0,    0,   39,    8,    1,    2,    3,    4,
    5,    6,   35,    1,    2,    3,    4,    5,    6,    0,
    0,    0,    0,    0,    0,   36,    0,   37,   38,    0,
    0,    0,    0,    0,    0,    0,    7,   39,    8,    0,
    0,    0,    0,    0,    0,    8,
};
static const YYINT yycheck[] = {                         37,
   44,  263,   40,   41,   42,   43,   44,   45,   41,   47,
   99,   44,   59,  263,   38,   59,   40,   59,   59,   85,
   58,   59,   60,   37,   62,   58,   59,   41,   42,   43,
   44,   45,   59,   47,  281,  170,   41,  263,  127,   44,
  175,   90,   91,   92,   58,   59,   60,  182,   62,   41,
   41,   37,   44,   44,  273,   93,   42,   43,   40,   45,
   93,   47,   37,  129,   91,   91,   59,   42,   43,  263,
   45,  273,   47,  162,   60,  264,   62,  263,   41,   93,
   43,   44,   45,   41,   40,   60,   44,   62,   41,   91,
   43,   44,   45,  273,   59,   58,   59,   60,   41,   62,
   40,   44,  263,   33,   59,   58,   59,   60,   37,   62,
   40,   41,   41,   42,   43,   45,   45,  286,   47,   37,
  282,  283,  284,  285,   42,   43,  263,   45,  273,   47,
   93,   60,   41,   62,   93,   44,   41,   41,   59,   44,
   93,   37,   60,  273,   62,   40,   42,   43,   37,   45,
  263,   47,   59,   42,   43,   33,   45,   91,   47,  183,
   93,  263,   40,   59,   60,   59,   62,   45,  273,   37,
   59,   60,   37,   62,   42,   93,  274,   42,   43,   47,
   45,  273,   47,   59,   37,   41,   59,   59,   44,   42,
   43,   -1,   45,   58,   47,   60,   41,   62,   59,   44,
   59,   59,   58,   59,   60,   59,   62,  257,  258,  259,
  260,  261,  262,   58,   59,   60,   59,   62,   59,   59,
   11,   41,   41,   11,   44,   -1,  273,  265,  266,  267,
  268,  269,  270,  266,   98,  273,  274,   93,   58,   59,
   60,  274,   62,   -1,   41,   -1,  273,   44,   93,   -1,
   -1,  265,  266,  267,  268,  269,  270,   -1,   -1,   -1,
  274,   58,   59,   60,   37,   62,   -1,   -1,   -1,   42,
   43,   -1,   45,   93,   47,  282,  283,  284,  285,  265,
  266,  267,  268,  269,  270,   41,   -1,   60,  274,   62,
  265,  266,  267,  268,  269,  270,   93,   -1,   -1,  274,
   -1,   -1,  265,  266,  267,  268,  269,  270,   -1,   -1,
   -1,  274,  265,  266,  267,  268,  269,  270,   59,   37,
   -1,  274,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,  263,  264,   -1,  265,  266,  267,  268,
  269,  270,   60,   41,   62,   -1,   44,  265,  266,  267,
  268,  269,  270,  257,  258,  259,  260,  261,  262,   -1,
   58,   59,   -1,  257,  258,  259,  260,  261,  262,  265,
  266,  267,  268,  269,  270,   -1,  265,  266,  267,  268,
  269,  270,   -1,   37,   -1,  263,  264,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   93,   -1,   -1,   46,   -1,
  265,  266,  267,  268,  269,  270,   60,   -1,   62,  265,
  266,  267,  268,  269,  270,   -1,   -1,   -1,  274,   -1,
  265,  266,  267,  268,  269,  270,   -1,   -1,   -1,  274,
  282,  283,  284,  285,   41,   -1,   -1,   44,  257,  258,
  259,  260,  261,  262,    0,  265,  266,  267,  268,  269,
  270,   58,   59,   -1,  274,   11,   37,   41,   -1,   -1,
   44,   42,   43,   -1,   45,   -1,   47,   -1,  265,  266,
  267,  268,  269,  270,   58,   59,   -1,  274,   -1,   60,
   -1,   62,  282,  283,  284,  285,   93,   -1,  136,   95,
   -1,   -1,  265,  266,  267,  268,  269,  270,   -1,   -1,
   56,  257,  258,  259,  260,  261,  262,  155,  156,   93,
   -1,   21,  118,  119,   -1,   -1,  257,  258,  259,  260,
  261,  262,  170,  282,  283,  284,  285,  175,   38,   -1,
   40,   -1,   -1,  139,  182,   -1,   46,   -1,   -1,   -1,
   -1,   -1,  190,   -1,   -1,   -1,   -1,  265,   -1,  267,
  268,  269,  270,   -1,   -1,  161,  257,  258,  259,  260,
  261,  262,   10,    0,   -1,   -1,   -1,  265,  266,   -1,
  176,  269,  270,   21,   11,   -1,  274,  133,  134,  135,
   -1,   -1,   -1,  189,   -1,   95,   -1,   -1,  289,   -1,
   38,   -1,   40,   30,   -1,   -1,   -1,   -1,   46,   -1,
   -1,   -1,   -1,   21,   -1,   -1,   54,   -1,  118,  119,
   -1,   -1,   60,  267,  268,  269,  270,   -1,   -1,   56,
  257,  258,  259,  260,  261,  262,  136,   -1,   46,  139,
   -1,   -1,   -1,   -1,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  280,   -1,  155,  156,   95,   -1,   -1,
   -1,  161,  289,   90,   91,   92,   -1,   -1,  265,  266,
  170,   -1,  269,  270,   -1,  175,  176,  274,   -1,   -1,
  118,  119,  182,  183,   -1,   -1,   -1,   95,   -1,  189,
  190,  265,  266,   -1,   -1,   -1,  267,  268,  136,   -1,
  274,  139,   -1,   -1,   -1,   -1,  133,  134,  135,   -1,
  118,  119,   -1,   -1,   -1,   -1,   -1,  155,  156,   -1,
   -1,   -1,   -1,  161,   -1,   -1,   -1,   -1,  136,   -1,
   -1,  139,  170,   -1,   -1,   -1,   -1,  175,  176,   -1,
   -1,   -1,   -1,   -1,  182,  183,   -1,  155,  156,   -1,
   -1,  189,  190,  161,   -1,   36,   37,   -1,   39,   -1,
   -1,    0,  170,   -1,   -1,   -1,   -1,  175,  176,    8,
   -1,   -1,   11,   -1,  182,   14,   -1,   58,   -1,   -1,
   -1,  189,  190,   64,   65,   66,   25,   -1,   -1,   -1,
   -1,   30,   73,   32,   -1,   -1,   -1,   -1,   -1,   80,
   81,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   56,   -1,   -1,
   -1,   -1,  103,  104,  105,  106,  107,  108,  109,  110,
  111,  112,  113,  114,  115,   -1,   -1,   -1,   -1,  120,
  121,   -1,   -1,   -1,   -1,   -1,   85,   -1,   -1,   -1,
   -1,   90,   91,   92,   -1,   -1,   -1,   -1,   -1,   98,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,  263,   -1,   -1,   -1,   -1,   -1,  159,   -1,
   -1,  272,   -1,   -1,   -1,  276,   -1,  278,  279,   -1,
  129,   -1,  173,   -1,  133,  134,  135,  288,  289,   -1,
   -1,   -1,   -1,   -1,   -1,  186,  257,  258,  259,  260,
  261,  262,  263,  257,  258,  259,  260,  261,  262,  263,
   -1,   -1,   -1,   -1,   -1,  276,   -1,  278,  279,   -1,
   -1,  275,  276,   -1,  278,  279,  287,  288,  289,   -1,
   -1,   -1,   -1,   -1,  288,  289,  257,  258,  259,  260,
  261,  262,  263,  257,  258,  259,  260,  261,  262,  263,
   -1,   -1,   -1,   -1,  275,  276,   -1,  278,  279,   -1,
   -1,  275,  276,   -1,  278,  279,   -1,  288,  289,   -1,
   -1,   -1,   -1,   -1,  288,  289,  257,  258,  259,  260,
  261,  262,  263,  257,  258,  259,  260,  261,  262,   -1,
   -1,   -1,   -1,   -1,   -1,  276,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  280,  288,  289,   -1,
   -1,   -1,   -1,   -1,   -1,  289,
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
"Void","ID","NR","LOGICAL_AND","LOGICAL_OR","LS_EQ","GR_EQ","EQ","NOT_EQ",
"BGIN","END","ASSIGN","BEGINSTMT","ENDSTMT","IF","ELSE","WHILE","FOR","CLASS",
"BEGINCLASS","ENDCLASS","PRIVATE","PROTECTED","PUBLIC","BEGINFNCTN","ENDFNCTN",
"RTRN","CONST","UMINUS","LOWER_THAN_ELSE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"declare_lhs : identifier",
"declare_lhs : identifier '[' NR ']'",
"lhs : identifier",
"lhs : array_access",
"identifier : ID",
"array_access : ID '[' expr ']'",
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
"declaratie : DATA_TYPE declare_lhs",
"declaratie : DATA_TYPE declare_lhs ASSIGN expr",
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
#line 231 "limbaj.y"
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

void AddConstantVariable(char* id, char* type, char* constant, int arrsize)
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

void AddNewVariable(char* id)
{
     var_table[totalVar].id = strdup(id);
     var_table[totalVar].line_no = yylineno;

	totalVar++;
}

void AddArraySize(char* id, int size)
{
     var_table[totalVar].id = strdup(id);
     var_table[totalVar].line_no = yylineno;
     var_table[totalVar].arrsize = size;

	totalVar++;
}

void AddDataType(char* id, char* type)
{
	int i = getVariableIndex(id);

     if (i == -1)
     {
          printf("Internal error!\n");
          exit(0);
     }

     var_table[i].data_type = strdup(type);
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
     scope += 100000 + getFunctionIndex(yylval.var_name);
}
void ExitFunction()
{
     scope = 0;
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
PrintVar();
//PrintFunc();
}
#line 840 "y.tab.c"

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
#line 73 "limbaj.y"
	{yyval.type_id = strdup("Integer");     }
break;
case 2:
#line 74 "limbaj.y"
	{yyval.type_id = strdup("Float");       }
break;
case 3:
#line 75 "limbaj.y"
	{yyval.type_id = strdup("Character");   }
break;
case 4:
#line 76 "limbaj.y"
	{yyval.type_id = strdup("Bool");        }
break;
case 5:
#line 77 "limbaj.y"
	{yyval.type_id = strdup("String");      }
break;
case 6:
#line 78 "limbaj.y"
	{yyval.type_id = strdup("Void");        }
break;
case 7:
#line 81 "limbaj.y"
	{printf("program corect sintactic\n");}
break;
case 8:
#line 84 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].string); AddNewVariable(yystack.l_mark[0].string);       }
break;
case 9:
#line 85 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[-3].string); AddArraySize(yystack.l_mark[-3].string, yystack.l_mark[-1].intval);     }
break;
case 10:
#line 88 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].string); }
break;
case 11:
#line 89 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].string); }
break;
case 12:
#line 92 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].var_name); }
break;
case 13:
#line 95 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[-3].var_name); }
break;
case 22:
#line 111 "limbaj.y"
	{ PushFunction(yystack.l_mark[-3].var_name, yystack.l_mark[-4].type_id); }
break;
case 23:
#line 112 "limbaj.y"
	{ PushFunction(yystack.l_mark[-2].var_name, yystack.l_mark[-3].type_id); }
break;
case 24:
#line 113 "limbaj.y"
	{ AddDataType(yystack.l_mark[0].string, yystack.l_mark[-1].type_id); }
break;
case 25:
#line 114 "limbaj.y"
	{ AddDataType(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id); }
break;
case 41:
#line 149 "limbaj.y"
	{ EnterFunction(); }
break;
case 42:
#line 152 "limbaj.y"
	{ ExitFunction(); }
break;
case 43:
#line 157 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].var_name); }
break;
case 44:
#line 158 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-5].var_name); }
break;
case 45:
#line 159 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-7].type_id); }
break;
case 46:
#line 160 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].type_id); }
break;
case 49:
#line 170 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); AddConstantVariable(yystack.l_mark[-2].var_name, yystack.l_mark[-3].type_id, "true", 0); }
break;
#line 1135 "y.tab.c"
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
