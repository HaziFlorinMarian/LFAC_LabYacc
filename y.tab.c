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

 int current_scope = 0;
 int max_scope = 0;

struct dataType {
     char* id;
     char* data_type;
     int line_no;
     char* is_constant;
     int arrsize;
};

struct NodesV {
     struct dataType var_table[100];
     int Parent;
     int totalVar;
} S[100];


typedef struct Func {
     char* Name;
     char* Return;
     int   line_no;
     char* ParamType[100];
     int   ParamNumber;
} Func;

struct Func CalledFunction;

struct NodesF {
     struct Func func_table[100];
     int Parent;
     int totalFunc;
} F[100];

typedef struct VarPos {
     int pos;
     int scope;
} VarPos;

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 52 "limbaj.y"
typedef union {
	char var_name[256];
	char* type_id;
     int intval;
     float floatval;
     char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 85 "y.tab.c"

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
#define STRING 265
#define FLOAT 266
#define LOGICAL_AND 267
#define LOGICAL_OR 268
#define LS_EQ 269
#define GR_EQ 270
#define EQ 271
#define NOT_EQ 272
#define BGIN 273
#define END 274
#define ASSIGN 275
#define BEGINSTMT 276
#define ENDSTMT 277
#define IF 278
#define ELSE 279
#define WHILE 280
#define FOR 281
#define CLASS 282
#define BEGINCLASS 283
#define ENDCLASS 284
#define PRIVATE 285
#define PROTECTED 286
#define PUBLIC 287
#define BEGINFNCTN 288
#define ENDFNCTN 289
#define RTRN 290
#define CONST 291
#define UMINUS 292
#define LOWER_THAN_ELSE 293
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    1,    1,    1,    1,    1,    1,    0,    7,    7,    6,
    6,    8,    9,    4,    4,   11,   11,   11,   11,   11,
   11,   14,   16,   14,   14,   17,   17,   17,   17,   18,
   18,   18,   18,   19,   19,   20,   21,   15,   22,   22,
   23,   23,   25,   12,   26,   27,   28,   10,   29,   10,
   30,   10,   31,   10,   24,   24,    5,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    3,    3,    3,    3,    3,   33,
   34,   35,   36,   37,   32,   32,   38,   32,   32,   32,
   32,   32,   32,   32,   32,   13,   13,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    1,    4,    1,
    1,    1,    4,    4,    3,    2,    3,    2,    2,    3,
    2,    2,    0,    5,    1,    2,    3,    3,    2,    1,
    3,    3,    3,    1,    3,    0,    0,    9,    1,    3,
    2,    4,    0,    4,    1,    1,    0,    9,    0,    8,
    0,   10,    0,    9,    2,    3,    5,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    5,    5,   14,    2,    3,    0,    5,    1,    1,
    1,    1,    1,    2,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
   25,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   21,    0,   43,    0,    7,    0,   18,   16,   19,   36,
    0,    0,    0,    0,    0,    0,   20,   17,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   95,   89,    0,    0,   11,    0,    0,   90,   91,
   92,    0,    0,    0,    0,   76,   77,   78,    0,    0,
    0,   73,   79,    0,   75,    0,    0,   39,    0,    0,
    9,    0,    0,    0,    0,    0,    0,   10,    0,   12,
    0,    0,    0,   44,    0,   55,   29,   26,    0,    0,
   37,    0,    0,    0,   72,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   45,    0,    0,    0,    0,   80,    0,    0,
    0,    0,    0,   15,    0,    0,   56,   28,   27,    0,
    0,    0,    0,   63,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   60,   61,   62,    0,   40,    0,
    0,    0,    0,   13,    0,    0,    0,    0,    0,   14,
   34,    0,   42,    0,   46,   50,    0,    0,   81,   82,
   83,    0,    0,    0,    0,   38,   48,    0,   54,    0,
   35,   52,    0,    0,    0,    0,    0,    0,    0,   84,
};
static const YYINT yydgoto[] = {                          9,
   51,   71,   72,   73,   53,   54,   19,   74,   75,   62,
   13,   25,  136,   63,   15,   33,   64,   65,  172,   39,
  140,   77,   78,   57,   36,  124,  176,   41,   42,   82,
   83,   58,  129,  180,   59,   60,   61,  132,
};
static const YYINT yysindex[] = {                       362,
    0,    0,    0,    0,    0,    0, -244,  369,    0, -243,
    0,   19,  644,  -33,  -32, -245, -221,    4,    0,  -36,
    0, -204,    0,   85,    0,    6,    0,    0,    0,    0,
 -212,    0, -208, -193,   39,  609,    0,    0,  380,   68,
  369,   31,   68,    2,    0,    8,   68,   68, -170,   68,
 -154,    0,    0, -165,   73,    0,  518,   60,    0,    0,
    0,  115,   75,  380, -163,    0,    0,    0,   68,   68,
  200,    0,    0,   73,    0, -154,   -8,    0, -152,  200,
    0,  369,  110,   68,   15,   15, -118,    0,  200,    0,
    0,   68,   41,    0,   96,    0,    0,    0,  249,  102,
    0,  380,  380,  380,    0,   55,   68,   68,   68,   68,
   68,   68,   68,   68,   68,   68,   68,   68,   68,   77,
  369, -152,    0,  609,   -4, -152,   69,    0,  609,  609,
   68, -105,  200,    0,  200,    7,    0,    0,    0,  -87,
  380,  380,  380,    0,  391,  228,  476,  476,  441,  441,
  476,  476,  169,  169,    0,    0,    0,   87,    0,  609,
  567, -152,  609,    0,  602,  602,   83,   68,   68,    0,
    0,  -43,    0,  567,    0,    0,  609,  567,    0,    0,
    0,   68,  200,  200,  -81,    0,    0,  567,    0,   90,
    0,    0, -170,  -92,   68,  111,  -91,  609,  602,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -50,  -48,  -47,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  106,  -37,    0,    0,    0,  127,
    0,    0,    0,    0,  -83,    0,    0,    0,    0,    0,
    0,    0,    0, -120,    0,    0,    0,    0,    0,    0,
  129,    0,    0,  -13,    0,    0,    0,    0,    0,  135,
    0,    0,    0,    0,    0,    0,    0,    0,  136,    0,
  -46,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   20,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  138,    0,   32,    0,    0,    0,    0,    0,
  -77,  178,  230,    0,  400,  396,  119,  131,  209,  398,
  143,  155,   25,   45,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  139,   50,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  733,  651,    0,  437,  448,  -34,  149,  519,  526,  466,
    0,    0,    0,  588,  191,    0,   37,    0,    0,    0,
    0,  144,  120,  419,    0, -108, -135,    0,    0,    0,
    0,  359,  -51, -149,    0,    0,    0,    0,
};
#define YYTABLESIZE 935
static const YYINT yytable[] = {                         12,
  185,   49,   12,   12,   12,   12,   12,   12,   12,   12,
   22,    8,   85,  160,   87,  186,  181,  163,   16,   18,
   12,   12,   12,   74,   12,   28,   29,   74,   74,   74,
   74,   74,  122,   74,  130,  121,  162,   30,  187,  121,
   12,   31,  189,   32,   74,   74,   74,  170,   74,  200,
  169,  119,  192,  177,   34,   12,  117,  115,   35,  116,
   41,  118,   40,   41,   38,   58,   43,   58,   58,   58,
   44,   79,   96,   69,  113,   96,  114,   21,   45,   74,
   70,  134,   58,   58,   58,   59,   58,   59,   59,   59,
   97,  119,   46,   97,   81,  144,  117,  115,   84,  116,
   69,  118,   59,   59,   59,  119,   59,   70,   90,   92,
  117,  115,   93,  116,  113,  118,  114,   58,   96,  119,
  101,  102,  103,  104,  117,  115,  119,  116,  113,  118,
  114,  117,  115,   98,  116,  123,  118,   59,  141,  142,
  143,  182,  113,   37,  114,  198,   53,  119,  193,  113,
  126,  114,  117,  115,  137,  116,  131,  118,  194,   68,
  139,  164,   68,   30,   30,   30,   30,  158,  197,  168,
  113,   69,  114,   97,   69,  171,   68,   68,   68,  173,
   68,  191,  195,   65,  128,   93,   65,   57,   69,   69,
   69,   10,   69,   24,   94,   64,   86,   88,   64,   91,
   65,   65,   65,   27,   65,  119,   31,   31,   31,   31,
  117,   68,   64,   64,   64,  118,   64,   47,   47,   47,
   47,   47,   47,   69,   12,  125,   23,    8,   87,   12,
   12,   12,   12,   12,   12,   65,  119,   12,   12,    0,
  159,  117,  115,    0,  116,    0,  118,   64,    0,   66,
    0,    0,   66,   74,   74,   74,   74,   74,   74,  113,
    0,  114,   74,    0,  119,    0,   66,   66,    0,  117,
  115,    0,  116,    0,  118,    1,    2,    3,    4,    5,
    6,  107,  108,  109,  110,  111,  112,  113,    0,  114,
  128,   58,   58,   58,   58,   58,   58,    0,    0,    0,
   58,   66,    0,   46,   66,   67,   68,  138,    0,    0,
    0,   59,   59,   59,   59,   59,   59,    0,    0,    0,
   59,  107,  108,  109,  110,  111,  112,    0,    0,    0,
   46,   66,   67,   68,    0,  107,  108,  109,  110,  111,
  112,    1,    2,    3,    4,    5,    6,    0,    0,  107,
  108,  109,  110,  111,  112,    0,  107,  108,  109,  110,
  111,  112,   51,   51,   51,   51,   51,   51,    0,    0,
    0,    1,    2,    3,    4,    5,    6,  107,  108,  109,
  110,  111,  112,    0,    0,   68,   68,   68,   68,   68,
   68,    0,    0,    0,   68,    0,    0,   69,   69,   69,
   69,   69,   69,    0,    0,    0,   69,    0,    0,   65,
   65,   65,   65,   65,   65,   95,    0,    0,   65,    0,
    0,   64,   64,   64,   64,   64,   64,  119,    0,    0,
   64,    0,  117,  115,    0,  116,   71,  118,   67,   71,
   70,   67,    0,   70,    0,    0,    0,   11,    0,    0,
  113,    0,  114,   71,   71,   67,   67,   70,   70,    0,
   11,   32,   32,   32,   32,   12,  107,  108,  109,  110,
  111,  112,   52,    0,    0,   66,   66,  119,   24,   66,
   66,    0,  117,  115,   66,  116,   11,  118,   71,    0,
   67,    0,   70,   52,  107,    0,  109,  110,  111,  112,
  113,    0,  114,    0,    0,    1,    2,    3,    4,    5,
    6,   11,  119,   33,   33,   33,   33,  117,  115,   95,
  116,    0,  118,   95,   95,    0,    0,    0,   20,   99,
    0,    0,   95,    0,    0,    0,   95,    0,    0,    0,
    0,    0,  161,    0,    0,    0,   95,  165,  166,   11,
   11,   11,    0,    0,   55,    0,    0,   95,    0,    0,
   52,   56,    0,    0,    0,   52,   52,   88,    0,   20,
    0,    0,    0,    0,   56,   55,    0,    0,  174,    0,
    0,  178,   56,    0,    0,    0,    0,   14,   11,   11,
   11,    0,    0,    0,  120,  188,   52,   52,    0,   52,
   26,   52,   52,    0,    0,    0,   99,   99,   99,    0,
   52,    0,    0,   52,   52,    0,  199,    0,    1,    2,
    3,    4,    5,    6,   52,    1,    2,    3,    4,    5,
    6,    0,    0,    0,   52,   52,    1,    2,    3,    4,
    5,    6,   55,    7,    0,    0,    0,   55,   55,   56,
    0,  100,    8,    0,   56,   56,    0,    0,    0,  109,
  110,  111,  112,   71,   67,   67,   70,   70,   67,   67,
    8,   71,    0,   67,    0,   70,    0,    0,   55,   55,
    0,   55,    0,   55,   55,   56,   56,    0,   56,    0,
   56,   56,   55,   80,    0,   55,   55,   85,   86,   56,
   89,    0,   56,   56,    0,    0,   55,    0,    0,  109,
  110,   88,    0,   56,    0,    0,   55,   55,   56,  105,
  106,    0,    0,   56,   56,    0,    0,    0,  100,  100,
  100,    0,   10,    0,  127,    0,    0,    0,    0,    0,
   17,    0,  133,  135,   22,   10,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   22,  145,  146,  147,
  148,  149,  150,  151,  152,  153,  154,  155,  156,  157,
    0,   10,    0,   76,    1,    2,    3,    4,    5,    6,
   46,  167,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   94,    0,    0,   22,   47,   10,   48,   49,    0,
    0,    0,    0,    0,    0,    0,    0,   50,    8,    0,
    0,    0,    0,    0,   76,    0,    0,    0,  183,  184,
    0,    0,    0,    1,    2,    3,    4,    5,    6,   46,
    0,   22,  190,    0,   10,   10,   10,    0,    0,    0,
    0,    0,    0,    0,   47,  196,   48,   49,    0,    0,
    0,    0,    0,   76,    0,  175,   50,    8,    1,    2,
    3,    4,    5,    6,   46,    1,    2,    3,    4,    5,
    6,   46,    0,   10,   10,   10,    0,    0,  179,   47,
    0,   48,   49,    0,    0,    0,   47,    0,   48,   49,
    0,   50,    8,    0,    0,    0,    0,    0,   50,    8,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   23,    0,    0,    0,
    0,    0,    0,    0,    0,    7,    0,    0,    0,    0,
    0,    0,    0,    0,    8,
};
static const YYINT yycheck[] = {                         37,
   44,   41,   40,   41,   42,   43,   44,   45,   59,   47,
   59,   59,   59,  122,   49,   59,  166,  126,  263,  263,
   58,   59,   60,   37,   62,   59,   59,   41,   42,   43,
   44,   45,   41,   47,   86,   44,   41,  283,  174,   44,
   91,  263,  178,   40,   58,   59,   60,   41,   62,  199,
   44,   37,  188,  162,   91,   93,   42,   43,  263,   45,
   41,   47,  275,   44,   59,   41,  275,   43,   44,   45,
  264,   41,   41,   33,   60,   44,   62,   59,   40,   93,
   40,   41,   58,   59,   60,   41,   62,   43,   44,   45,
   41,   37,  263,   44,   93,   41,   42,   43,   91,   45,
   33,   47,   58,   59,   60,   37,   62,   40,  263,  275,
   42,   43,   40,   45,   60,   47,   62,   93,   59,   37,
  284,  285,  286,  287,   42,   43,   37,   45,   60,   47,
   62,   42,   43,   59,   45,  288,   47,   93,  102,  103,
  104,   59,   60,   59,   62,  197,   41,   37,   59,   60,
   41,   62,   42,   43,   59,   45,  275,   47,  193,   41,
   59,   93,   44,  284,  285,  286,  287,   91,   58,  275,
   60,   41,   62,   59,   44,  263,   58,   59,   60,   93,
   62,  263,  275,   41,  276,   59,   44,   59,   58,   59,
   60,  275,   62,   59,   59,   41,   59,   59,   44,   51,
   58,   59,   60,   13,   62,   37,  284,  285,  286,  287,
   42,   93,   58,   59,   60,   47,   62,  257,  258,  259,
  260,  261,  262,   93,  275,   82,  275,  275,  275,  267,
  268,  269,  270,  271,  272,   93,   37,  275,  276,   -1,
  121,   42,   43,   -1,   45,   -1,   47,   93,   -1,   41,
   -1,   -1,   44,  267,  268,  269,  270,  271,  272,   60,
   -1,   62,  276,   -1,   37,   -1,   58,   59,   -1,   42,
   43,   -1,   45,   -1,   47,  257,  258,  259,  260,  261,
  262,  267,  268,  269,  270,  271,  272,   60,   -1,   62,
  276,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
  276,   93,   -1,  263,  264,  265,  266,   59,   -1,   -1,
   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
  276,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
  263,  264,  265,  266,   -1,  267,  268,  269,  270,  271,
  272,  257,  258,  259,  260,  261,  262,   -1,   -1,  267,
  268,  269,  270,  271,  272,   -1,  267,  268,  269,  270,
  271,  272,  257,  258,  259,  260,  261,  262,   -1,   -1,
   -1,  257,  258,  259,  260,  261,  262,  267,  268,  269,
  270,  271,  272,   -1,   -1,  267,  268,  269,  270,  271,
  272,   -1,   -1,   -1,  276,   -1,   -1,  267,  268,  269,
  270,  271,  272,   -1,   -1,   -1,  276,   -1,   -1,  267,
  268,  269,  270,  271,  272,   57,   -1,   -1,  276,   -1,
   -1,  267,  268,  269,  270,  271,  272,   37,   -1,   -1,
  276,   -1,   42,   43,   -1,   45,   41,   47,   41,   44,
   41,   44,   -1,   44,   -1,   -1,   -1,    0,   -1,   -1,
   60,   -1,   62,   58,   59,   58,   59,   58,   59,   -1,
   13,  284,  285,  286,  287,    0,  267,  268,  269,  270,
  271,  272,   36,   -1,   -1,  267,  268,   37,   13,  271,
  272,   -1,   42,   43,  276,   45,   39,   47,   93,   -1,
   93,   -1,   93,   57,  267,   -1,  269,  270,  271,  272,
   60,   -1,   62,   -1,   -1,  257,  258,  259,  260,  261,
  262,   64,   37,  284,  285,  286,  287,   42,   43,  161,
   45,   -1,   47,  165,  166,   -1,   -1,   -1,   10,   64,
   -1,   -1,  174,   -1,   -1,   -1,  178,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   -1,  188,  129,  130,  102,
  103,  104,   -1,   -1,   36,   -1,   -1,  199,   -1,   -1,
  124,   36,   -1,   -1,   -1,  129,  130,   49,   -1,   51,
   -1,   -1,   -1,   -1,   49,   57,   -1,   -1,  160,   -1,
   -1,  163,   57,   -1,   -1,   -1,   -1,    0,  141,  142,
  143,   -1,   -1,   -1,   76,  177,  160,  161,   -1,  163,
   13,  165,  166,   -1,   -1,   -1,  141,  142,  143,   -1,
  174,   -1,   -1,  177,  178,   -1,  198,   -1,  257,  258,
  259,  260,  261,  262,  188,  257,  258,  259,  260,  261,
  262,   -1,   -1,   -1,  198,  199,  257,  258,  259,  260,
  261,  262,  124,  282,   -1,   -1,   -1,  129,  130,  124,
   -1,   64,  291,   -1,  129,  130,   -1,   -1,   -1,  269,
  270,  271,  272,  268,  267,  268,  267,  268,  271,  272,
  291,  276,   -1,  276,   -1,  276,   -1,   -1,  160,  161,
   -1,  163,   -1,  165,  166,  160,  161,   -1,  163,   -1,
  165,  166,  174,   43,   -1,  177,  178,   47,   48,  174,
   50,   -1,  177,  178,   -1,   -1,  188,   -1,   -1,  269,
  270,  193,   -1,  188,   -1,   -1,  198,  199,  193,   69,
   70,   -1,   -1,  198,  199,   -1,   -1,   -1,  141,  142,
  143,   -1,    0,   -1,   84,   -1,   -1,   -1,   -1,   -1,
    8,   -1,   92,   93,   12,   13,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   24,  107,  108,  109,
  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,
   -1,   39,   -1,   41,  257,  258,  259,  260,  261,  262,
  263,  131,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,   -1,   -1,   62,  278,   64,  280,  281,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  290,  291,   -1,
   -1,   -1,   -1,   -1,   82,   -1,   -1,   -1,  168,  169,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
   -1,   99,  182,   -1,  102,  103,  104,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  278,  195,  280,  281,   -1,   -1,
   -1,   -1,   -1,  121,   -1,  289,  290,  291,  257,  258,
  259,  260,  261,  262,  263,  257,  258,  259,  260,  261,
  262,  263,   -1,  141,  142,  143,   -1,   -1,  277,  278,
   -1,  280,  281,   -1,   -1,   -1,  278,   -1,  280,  281,
   -1,  290,  291,   -1,   -1,   -1,   -1,   -1,  290,  291,
  257,  258,  259,  260,  261,  262,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  273,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  282,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  291,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
#define YYUNDFTOKEN 334
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
"Void","ID","NR","STRING","FLOAT","LOGICAL_AND","LOGICAL_OR","LS_EQ","GR_EQ",
"EQ","NOT_EQ","BGIN","END","ASSIGN","BEGINSTMT","ENDSTMT","IF","ELSE","WHILE",
"FOR","CLASS","BEGINCLASS","ENDCLASS","PRIVATE","PROTECTED","PUBLIC",
"BEGINFNCTN","ENDFNCTN","RTRN","CONST","UMINUS","LOWER_THAN_ELSE",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
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
"declaratie : DATA_TYPE declare_lhs",
"$$1 :",
"declaratie : DATA_TYPE declare_lhs $$1 ASSIGN expr",
"declaratie : constant",
"declaratii_clasa : declaratie ';'",
"declaratii_clasa : declaratii_clasa declaratie ';'",
"declaratii_clasa : declaratii_clasa descriere_functii ';'",
"declaratii_clasa : descriere_functii ';'",
"bloc_clasa : declaratii_clasa",
"bloc_clasa : bloc_clasa PRIVATE declaratii_clasa",
"bloc_clasa : bloc_clasa PROTECTED declaratii_clasa",
"bloc_clasa : bloc_clasa PUBLIC declaratii_clasa",
"lista_id_clasa : ID",
"lista_id_clasa : lista_id_clasa ',' ID",
"$$2 :",
"$$3 :",
"initializare_clasa : CLASS ID BEGINCLASS $$2 bloc_clasa ENDCLASS $$3 lista_id_clasa ';'",
"lista_param : param",
"lista_param : lista_param ',' param",
"param : DATA_TYPE identifier",
"param : DATA_TYPE identifier '[' ']'",
"$$4 :",
"bloc : BGIN $$4 list END",
"enter_func : BEGINFNCTN",
"leave_func : ENDFNCTN",
"$$5 :",
"descriere_functii : DATA_TYPE ID '(' $$5 lista_param ')' enter_func list leave_func",
"$$6 :",
"descriere_functii : DATA_TYPE ID '(' $$6 ')' enter_func list leave_func",
"$$7 :",
"descriere_functii : descriere_functii DATA_TYPE ID '(' $$7 lista_param ')' enter_func list leave_func",
"$$8 :",
"descriere_functii : descriere_functii DATA_TYPE ID '(' $$8 ')' enter_func list leave_func",
"list : statement ';'",
"list : list statement ';'",
"constant : CONST DATA_TYPE ID ASSIGN expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : '(' expr ')'",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr EQ expr",
"expr : expr NOT_EQ expr",
"expr : expr LS_EQ expr",
"expr : expr GR_EQ expr",
"expr : expr LOGICAL_AND expr",
"expr : expr LOGICAL_OR expr",
"expr : '!' expr",
"expr : operand",
"operand : identifier",
"operand : array_access",
"operand : NR",
"operand : STRING",
"operand : FLOAT",
"operand : function_call",
"begin_statement : BEGINSTMT",
"end_statement : ENDSTMT",
"if_stmt : IF expr begin_statement list end_statement",
"while_stmt : WHILE expr begin_statement list end_statement",
"for_stmt : FOR lhs ASSIGN expr ';' expr ';' lhs ASSIGN expr ':' begin_statement list end_statement",
"statement : DATA_TYPE declare_lhs",
"statement : lhs ASSIGN expr",
"$$9 :",
"statement : DATA_TYPE declare_lhs $$9 ASSIGN expr",
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
#line 251 "limbaj.y"
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

void PrintVar()
{
     printf("\n\n");
	printf("\nSYMBOL\tSCOPE\tIS_CONSTANT\tDATATYPE\tLINE NUMBER\tARRAY SIZE\n");
	printf("_______________________________________\n\n");

	int i = 0, j = 0;

     for(j=0; j <= max_scope; ++j)
          for(i=0; i < S[j].totalVar; i++)
               printf("%s\t%d\t%s\t%s\t%d\t%d\n", S[j].var_table[i].id, j, S[j].var_table[i].is_constant, S[j].var_table[i].data_type, S[j].var_table[i].line_no, S[j].var_table[i].arrsize);

     for(j=0; j <= max_scope; ++j)
          for(i=0; i < S[j].totalVar;i++) {
               free(S[j].var_table[i].id);
               free(S[j].var_table[i].data_type);
               free(S[j].var_table[i].is_constant);
          }

	printf("\n\n");
}

void PrintFunc()
{
    printf("\n\n");
	printf("\nNAME\t\tSCOPE\t\tRETURN_TYPE\tPARAM_NUMBER\tLINE_NUMBER\n");
	printf("_______________________________________\n\n");
     
     int i = 0, j = 0;

     for(j=0; j <= max_scope; ++j)
     {    
          for(i=0; i < F[j].totalFunc; i++) {
               printf("%s\t\t%d\t\t%s\t\t%d\t\t%d\n", F[j].func_table[i].Name, j, F[j].func_table[i].Return, F[j].func_table[i].ParamNumber, F[j].func_table[i].line_no);
               printf("PARAM_TYPE\t");

               for (int k = 0; k <  F[j].func_table[i].ParamNumber; ++k)
                    printf("%s\t", F[j].func_table[i].ParamType[k]);

               printf("\n\n");
          }
     }


     for(j=0; j <= max_scope; ++j)
          for(i=0; i < F[j].totalFunc; i++)
          {
               free(F[j].func_table[i].Name);
               free(F[j].func_table[i].Return);

               for (int j = 0; j <  F[j].func_table[i].ParamNumber; ++j)
               {
                    free(F[j].func_table[i].ParamType[j]);
               }
          }

	printf("\n\n");
}

VarPos SearchVar(char* varName)
{
     int i = 0, flag = 0, iCurScope = current_scope;
     struct VarPos result;
     result.pos = -1;
     result.scope = -1;

     while (flag == 0)
     {
          if (iCurScope == 0)
               flag = 1;

          for (i = 0; i < S[iCurScope].totalVar; i++)
          {    
               if (strcmp(varName, S[iCurScope].var_table[i].id) == 0)
               {
                    result.pos = i;
                    result.scope = iCurScope;

                    return result;
               }
          }

          if (i == S[iCurScope].totalVar)
               iCurScope = S[iCurScope].Parent;
          else 
               flag = 1;
     }

     return result;
}

int SearchLocalVar(char* varName)
{
	for (int i = 0; i < S[current_scope].totalVar; i++) 
		if (strcmp(varName, S[current_scope].var_table[i].id) == 0)
			return i;

	return -1;
}

int SearchLocalFunc(char* varName)
{
     int fixed_scope = F[current_scope].Parent;

	for (int i = 0; i < F[fixed_scope].totalFunc; i++) 
		if (strcmp(varName, F[fixed_scope].func_table[i].Name) == 0)
			return i;

	return -1;
}

void AddConstantVariable(char* id, char* type, char* constant, int arrsize)
{
	struct VarPos i = SearchVar(id);

	if (i.pos != -1)
    {
		printf("The variable %s was already declared on line %d\n", id, S[current_scope].var_table[i.pos].line_no);
		exit(0);
	}

     int pos = S[current_scope].totalVar;

     S[current_scope].var_table[pos].id = strdup(id);
     S[current_scope].var_table[pos].data_type = strdup(type);
     S[current_scope].var_table[pos].line_no = yylineno;
     S[current_scope].var_table[pos].is_constant = strdup(constant);
     S[current_scope].var_table[pos].arrsize = arrsize;

	S[current_scope].totalVar++;
}

void AddNewVariable(char* id)
{
     int i = SearchLocalVar(id);

     if (i != -1)
     {
          printf("ERROR! Variabile %s has been already declared! (line_no: %d).\n", id, yylineno);
          exit(0);
     }

     int pos = S[current_scope].totalVar;

     S[current_scope].var_table[pos].id = strdup(id);
     S[current_scope].var_table[pos].line_no = yylineno;

	S[current_scope].totalVar++;
}

void AddArraySize(char* id, int size)
{
     int pos = S[current_scope].totalVar;

     S[current_scope].var_table[pos].id = strdup(id);
     S[current_scope].var_table[pos].line_no = yylineno;
     S[current_scope].var_table[pos].arrsize = size;

	S[current_scope].totalVar++;
}

void AddDataType(char* id, char* type)
{
	struct VarPos i = SearchVar(id);

     if (i.pos == -1)
     {
          printf("AddDataType :: Internal error!\n");
          exit(0);
     }

     S[current_scope].var_table[i.pos].data_type = strdup(type);
}

void PrintErrorAndExit(int x)
{
     switch(x)
     {
          case 1:
               yyerror("Cannot have  VOID data type for variables.");
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
          case 6:
               yyerror("ERROR! Trying to call an undefined function.");
               exit(0);
     }
}

VarPos SearchFunc(char* funcName)
{
     int i = 0, flag = 0, iCurScope = current_scope;
     struct VarPos result;
     result.pos = -1;
     result.scope = -1;

     while (flag == 0)
     {
          if (iCurScope == 0)
               flag = 1;

          for (; i < F[iCurScope].totalFunc; i++) 
               if (strcmp(funcName, F[iCurScope].func_table[i].Name) == 0)
               {
                    result.pos = i;
                    result.scope = iCurScope;

                    return result;
               }

          if (i == F[iCurScope].totalFunc)
               iCurScope = F[iCurScope].Parent;
          else 
               flag = 1;

          }

     return result;
}

void CheckIfVoidVariables(char* var)
{
	if (strcmp(var, "Void") == 0)
		PrintErrorAndExit(1);
}

void CheckArrayRange(char* arr, int pos)
{
     struct VarPos i = SearchVar(arr);

     if (i.pos == -1)
          PrintErrorAndExit(4);

     if (pos < 0 || pos > S[current_scope].var_table[i.pos].arrsize)
          PrintErrorAndExit(3);
}

void PushFunction(char* name, char* ret_type)
{
	int i = SearchLocalFunc(name);

	if (i != -1)
		PrintErrorAndExit(5);

     int* pos = &F[current_scope].totalFunc;

     F[current_scope].func_table[*pos].Name = strdup(name);
     F[current_scope].func_table[*pos].Return = strdup(ret_type);
     F[current_scope].func_table[*pos].line_no = yylineno;

	(*pos)++;
}

void PushParameters(char* type)
{
     int fixed_scope = F[current_scope].Parent;

     int pos = F[fixed_scope].totalFunc;
     int *j = &F[fixed_scope].func_table[pos].ParamNumber;

     F[fixed_scope].func_table[pos].ParamType[*j] = strdup(type);

     (*j)++; 
}

void AddParamToVarList(char* id, char* type)
{
	int i = SearchLocalVar(id);

     if (i != -1)
     {
          printf("Variable %s already declared!\n (line_no: %d)", id, yylineno);
          exit(0);
     }

     int pos = S[current_scope].totalVar;

     S[current_scope].var_table[pos].id = strdup(id);
     S[current_scope].var_table[pos].data_type = strdup(type);
     S[current_scope].var_table[pos].line_no = yylineno;

	S[current_scope].totalVar++;
}

void CheckIfIsDefined(char* id)
{
     struct VarPos i = SearchVar(id);

     if (i.pos == -1)
     {
          PrintErrorAndExit(4);
     }
}

void NewScope()
{
     max_scope++;
     S[max_scope].Parent = current_scope;
     F[max_scope].Parent = current_scope;
     current_scope = max_scope;
}
void ExitScope()
{
     current_scope = S[current_scope].Parent;
}

void type_check(char* left, char* right)
{
	if(strcmp(left, right) != 0)
     {
          printf("Type mismatch between operands (%s - %s, line_no: %d).\n", left, right, yylineno);
          exit(0);
     }
}

char* GetType(int type, char* id)
{
     if(type == 1)
     {
          struct VarPos i = SearchVar(id);

          if (i.pos == -1)
          {
               printf("Illegal use of undeclared variable! (name: %s, line: %d)\n", id, yylineno);
               exit(0);
          }

          return S[i.scope].var_table[i.pos].data_type;
     }
     else if (type == 2)
     {
          struct VarPos i = SearchFunc(id);

          if (i.pos == -1)
          {
               printf("Illegal use of undeclared function! (name: %s, line: %d)\n", id, yylineno);
               exit(0);
          }

          return F[i.scope].func_table[i.pos].Return;
     }
}

void AddCallStackFunction(char* name)
{
	struct VarPos i = SearchFunc(name);

	if (i.pos == -1)
		PrintErrorAndExit(6);

     CalledFunction.Name = strdup(name);
     CalledFunction.line_no = yylineno;
}

void AddCallParameters(char* type)
{
     int *pos = &CalledFunction.ParamNumber;
     CalledFunction.ParamType[*pos] = strdup(type);
     (*pos)++;
}

void CompareFunctions()
{
     printf("Name: %s\tParamNumber: %d\n", CalledFunction.Name, CalledFunction.ParamNumber);
     for (int i = 0; i < CalledFunction.ParamNumber; ++i)
          printf("%s\t", CalledFunction.ParamType[i]);
     printf("\n\n");
}


int main(int argc, char** argv)
{
     yyin=fopen(argv[1],"r");
     yyparse();
     PrintVar();
     PrintFunc();
}
#line 1003 "y.tab.c"

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
#line 86 "limbaj.y"
	{yyval.type_id = strdup("Integer");   }
break;
case 2:
#line 87 "limbaj.y"
	{yyval.type_id = strdup("Float");   }
break;
case 3:
#line 88 "limbaj.y"
	{yyval.type_id = strdup("Character");  }
break;
case 4:
#line 89 "limbaj.y"
	{yyval.type_id = strdup("Bool");   }
break;
case 5:
#line 90 "limbaj.y"
	{yyval.type_id = strdup("String");   }
break;
case 6:
#line 91 "limbaj.y"
	{yyval.type_id = strdup("Void");   }
break;
case 7:
#line 94 "limbaj.y"
	{printf("program corect sintactic\n");}
break;
case 8:
#line 97 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].strval); AddNewVariable(yystack.l_mark[0].strval);       }
break;
case 9:
#line 98 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[-3].strval); AddArraySize(yystack.l_mark[-3].strval, yystack.l_mark[-1].intval);     }
break;
case 10:
#line 101 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].strval); }
break;
case 11:
#line 102 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].strval); }
break;
case 12:
#line 105 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].var_name); }
break;
case 13:
#line 108 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[-3].var_name); }
break;
case 14:
#line 111 "limbaj.y"
	{ yyval.type_id = GetType(2, yystack.l_mark[-3].strval); AddCallStackFunction(yystack.l_mark[-3].strval); CompareFunctions(); }
break;
case 15:
#line 112 "limbaj.y"
	{ yyval.type_id = GetType(2, yystack.l_mark[-2].strval); AddCallStackFunction(yystack.l_mark[-2].strval); CompareFunctions(); }
break;
case 22:
#line 124 "limbaj.y"
	{ CheckIfVoidVariables(yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 23:
#line 125 "limbaj.y"
	{ CheckIfVoidVariables(yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 36:
#line 147 "limbaj.y"
	{ NewScope(); }
break;
case 37:
#line 147 "limbaj.y"
	{ { ExitScope(); } }
break;
case 41:
#line 154 "limbaj.y"
	{ PushParameters(yystack.l_mark[-1].type_id); AddParamToVarList(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 42:
#line 155 "limbaj.y"
	{ PushParameters(yystack.l_mark[-3].type_id); AddParamToVarList(yystack.l_mark[-2].strval, yystack.l_mark[-3].type_id); }
break;
case 43:
#line 159 "limbaj.y"
	{ NewScope(); }
break;
case 44:
#line 159 "limbaj.y"
	{ ExitScope(); }
break;
case 47:
#line 170 "limbaj.y"
	{ NewScope(); }
break;
case 48:
#line 170 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-7].var_name, yystack.l_mark[-8].type_id); }
break;
case 49:
#line 171 "limbaj.y"
	{ NewScope(); }
break;
case 50:
#line 171 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-6].var_name, yystack.l_mark[-7].type_id); }
break;
case 51:
#line 172 "limbaj.y"
	{ NewScope(); }
break;
case 52:
#line 172 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-8].type_id, yystack.l_mark[-9].strval); }
break;
case 53:
#line 173 "limbaj.y"
	{ NewScope(); }
break;
case 54:
#line 173 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-7].type_id, yystack.l_mark[-8].strval); }
break;
case 57:
#line 183 "limbaj.y"
	{ CheckIfVoidVariables(yystack.l_mark[-3].type_id); AddConstantVariable(yystack.l_mark[-2].var_name, yystack.l_mark[-3].type_id, "true", 0); yyval.type_id = GetType(1, yystack.l_mark[-2].var_name); }
break;
case 58:
#line 187 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 59:
#line 188 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 60:
#line 189 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 61:
#line 190 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 62:
#line 191 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 63:
#line 192 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[-1].type_id); }
break;
case 64:
#line 193 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 65:
#line 194 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 66:
#line 195 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 67:
#line 196 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 68:
#line 197 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 69:
#line 198 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 70:
#line 199 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 71:
#line 200 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 72:
#line 201 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[0].type_id); }
break;
case 73:
#line 202 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[0].type_id); }
break;
case 74:
#line 206 "limbaj.y"
	{ yyval.type_id = GetType(1, yystack.l_mark[0].strval);        }
break;
case 75:
#line 207 "limbaj.y"
	{ yyval.type_id = strdup("Integer");     }
break;
case 76:
#line 208 "limbaj.y"
	{ yyval.type_id = strdup("Integer");     }
break;
case 77:
#line 209 "limbaj.y"
	{ yyval.type_id = strdup("String");      }
break;
case 78:
#line 210 "limbaj.y"
	{ yyval.type_id = strdup("Float");       }
break;
case 79:
#line 211 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[0].type_id);            }
break;
case 80:
#line 215 "limbaj.y"
	{ NewScope(); }
break;
case 81:
#line 218 "limbaj.y"
	{ ExitScope(); }
break;
case 85:
#line 234 "limbaj.y"
	{ CheckIfVoidVariables(yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 86:
#line 235 "limbaj.y"
	{ CheckIfIsDefined(yystack.l_mark[-2].strval); type_check(GetType(1, yystack.l_mark[-2].strval), yystack.l_mark[0].type_id); }
break;
case 87:
#line 236 "limbaj.y"
	{ CheckIfVoidVariables(yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 96:
#line 246 "limbaj.y"
	{ AddCallParameters(yystack.l_mark[0].type_id); }
break;
case 97:
#line 247 "limbaj.y"
	{ AddCallParameters(yystack.l_mark[0].type_id); }
break;
#line 1446 "y.tab.c"
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
