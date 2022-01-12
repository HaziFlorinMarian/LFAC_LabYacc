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


struct Func {
     char* Name;
     char* Scope;
     char* Return;
     int   line_no;
     char* ParamType[100];
     int   ParamNumber;
};

struct NodesF {
     struct Func func_table[100];
     int Parent;
     int totalFunc;
} F[100];

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 46 "limbaj.y"
typedef union {
	char var_name[256];
	char* type_id;
     int intval;
     float floatval;
     char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 79 "y.tab.c"

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
    2,    2,    2,    3,    3,    3,    3,    3,   33,   34,
   35,   36,   37,   32,   32,   38,   32,   32,   32,   32,
   32,   32,   32,   32,   13,   13,
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
    5,    5,   14,    2,    3,    0,    5,    1,    1,    1,
    1,    1,    2,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
   25,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   21,    0,   43,    0,    7,    0,   18,   16,   19,   36,
    0,    0,    0,    0,    0,    0,   20,   17,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   94,   88,    0,    0,   11,    0,    0,   89,   90,
   91,    0,    0,    0,    0,   76,   77,    0,    0,    0,
   73,   78,    0,   75,    0,    0,   39,    0,    0,    9,
    0,    0,    0,    0,    0,    0,   10,    0,   12,    0,
    0,    0,   44,    0,   55,   29,   26,    0,    0,   37,
    0,    0,    0,   72,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   45,    0,    0,    0,    0,   79,    0,    0,    0,
    0,    0,   15,    0,    0,   56,   28,   27,    0,    0,
    0,    0,   63,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   60,   61,   62,    0,   40,    0,    0,
    0,    0,   13,    0,    0,    0,    0,    0,   14,   34,
    0,   42,    0,   46,   50,    0,    0,   80,   81,   82,
    0,    0,    0,    0,   38,   48,    0,   54,    0,   35,
   52,    0,    0,    0,    0,    0,    0,    0,   83,
};
static const YYINT yydgoto[] = {                          9,
   51,   70,   71,   72,   53,   54,   19,   73,   74,   62,
   13,   25,  135,   63,   15,   33,   64,   65,  171,   39,
  139,   76,   77,   57,   36,  123,  175,   41,   42,   81,
   82,   58,  128,  179,   59,   60,   61,  131,
};
static const YYINT yysindex[] = {                       608,
    0,    0,    0,    0,    0,    0, -245,  358,    0, -243,
    0,   19,  589,  -33,  -32, -250, -221,    4,    0,  -30,
    0, -200,    0,   85,    0,    6,    0,    0,    0,    0,
 -208,    0, -204, -192,   39,  598,    0,    0,  -51,   68,
  358,   52,   68,    2,    0,    8,   68,   68, -154,   68,
 -153,    0,    0, -162,   79,    0,  517,   75,    0,    0,
    0,  115,   81,  -51, -249,    0,    0,   68,   68,  200,
    0,    0,   79,    0, -153,    7,    0, -147,  200,    0,
  358,  105,   68,   15,   15, -116,    0,  200,    0,    0,
   68,   41,    0,   96,    0,    0,    0,  248,  102,    0,
  -51,  -51,  -51,    0,   55,   68,   68,   68,   68,   68,
   68,   68,   68,   68,   68,   68,   68,   68,   77,  358,
 -147,    0,  598,   32, -147,   69,    0,  598,  598,   68,
 -105,  200,    0,  200,   50,    0,    0,    0,  -87,  -51,
  -51,  -51,    0,  391,  228,  484,  484,  441,  441,  484,
  484,   17,   17,    0,    0,    0,   93,    0,  598,  525,
 -147,  598,    0,  563,  563,   83,   68,   68,    0,    0,
  -43,    0,  525,    0,    0,  598,  525,    0,    0,    0,
   68,  200,  200,  -75,    0,    0,  525,    0,   90,    0,
    0, -154,  -83,   68,  111,  -82,  598,  563,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -50,  -48,  -47,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  106,  -37,    0,    0,    0,  136,
    0,    0,    0,    0,  -78,    0,    0,    0,    0,    0,
    0,    0,    0, -163,    0,    0,    0,    0,    0,  145,
    0,    0,  -13,    0,    0,    0,    0,    0,  157,    0,
    0,    0,    0,    0,    0,    0,    0,  167,    0,  -46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   95,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  182,    0,  139,    0,    0,    0,    0,    0, -120,
   24,  162,    0,  400,  396,  119,  131,  209,  398,  143,
  155,   25,   45,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  185,  141,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  732,  651,    0,  527,  504,  -35,  147,  520,  416,  371,
    0,    0,    0,  432,  187,    0,  197,    0,    0,    0,
    0,  165,  129,  424,    0, -106, -134,    0,    0,    0,
    0,  359,  -45, -148,    0,    0,    0,    0,
};
#define YYTABLESIZE 899
static const YYINT yytable[] = {                         12,
  184,   49,   12,   12,   12,   12,   12,   12,   12,   12,
   22,    8,   84,   86,  159,  185,  180,   16,  162,   18,
   12,   12,   12,   74,   12,   28,   29,   74,   74,   74,
   74,   74,   30,   74,  100,  101,  102,  103,  186,  129,
   12,   31,  188,   32,   74,   74,   74,  121,   74,  199,
  120,  118,  191,  118,  176,   12,  116,  114,  116,  115,
   34,  117,   35,  117,   38,   58,   40,   58,   58,   58,
   43,   44,  161,   68,  112,  120,  113,   21,   45,   74,
   69,  133,   58,   58,   58,   59,   58,   59,   59,   59,
  169,  118,   78,  168,   80,  143,  116,  114,   83,  115,
   68,  117,   59,   59,   59,  118,   59,   69,   46,   89,
  116,  114,   91,  115,  112,  117,  113,   58,   92,  118,
   30,   30,   30,   30,  116,  114,  118,  115,  112,  117,
  113,  116,  114,   95,  115,   41,  117,   59,   41,   97,
  122,  181,  112,   37,  113,  125,   53,  118,  192,  112,
  197,  113,  116,  114,  136,  115,  193,  117,  130,   68,
  138,  163,   68,   31,   31,   31,   31,  157,  196,  167,
  112,   69,  113,   96,   69,  170,   68,   68,   68,   95,
   68,   96,   95,   65,   96,  172,   65,  190,   69,   69,
   69,  194,   69,  127,   92,   64,   10,   90,   64,   27,
   65,   65,   65,   57,   65,    1,    2,    3,    4,    5,
    6,   68,   64,   64,   64,   24,   64,   47,   47,   47,
   47,   47,   47,   69,   12,   93,   23,    8,   86,   12,
   12,   12,   12,   12,   12,   65,  118,   12,   12,    8,
   85,  116,  114,   87,  115,  124,  117,   64,  158,   66,
    0,    0,   66,   74,   74,   74,   74,   74,   74,  112,
    0,  113,   74,    0,  118,    0,   66,   66,    0,  116,
  114,    0,  115,    0,  117,    1,    2,    3,    4,    5,
    6,  106,  107,  108,  109,  110,  111,  112,    0,  113,
  127,   58,   58,   58,   58,   58,   58,  140,  141,  142,
   58,   66,    0,   46,   66,   67,  137,   32,   32,   32,
   32,   59,   59,   59,   59,   59,   59,    0,    0,    0,
   59,  106,  107,  108,  109,  110,  111,    0,    0,    0,
   46,   66,   67,    0,    0,  106,  107,  108,  109,  110,
  111,    1,    2,    3,    4,    5,    6,    0,    0,  106,
  107,  108,  109,  110,  111,    0,  106,  107,  108,  109,
  110,  111,   51,   51,   51,   51,   51,   51,    0,    0,
   12,    1,    2,    3,    4,    5,    6,  106,  107,  108,
  109,  110,  111,   24,    0,   68,   68,   68,   68,   68,
   68,    0,    0,    0,   68,    0,    0,   69,   69,   69,
   69,   69,   69,    0,    0,    0,   69,    0,    0,   65,
   65,   65,   65,   65,   65,   94,    0,    0,   65,    0,
    0,   64,   64,   64,   64,   64,   64,  118,    0,    0,
   64,   14,  116,  114,   98,  115,   71,  117,   67,   71,
   70,   67,    0,   70,   26,   33,   33,   33,   33,    0,
  112,   56,  113,   71,   71,   67,   67,   70,   70,    0,
    0,    0,    0,    0,   56,    0,  106,  107,  108,  109,
  110,  111,   56,    0,    0,   66,   66,  118,    0,   66,
   66,    0,  116,  114,   66,  115,    0,  117,   71,    0,
   67,    0,   70,    0,  106,   99,  108,  109,  110,  111,
  112,    0,  113,   11,    1,    2,    3,    4,    5,    6,
   98,   98,   98,    0,    0,    0,   11,    0,   94,    0,
  118,    0,   94,   94,    0,  116,  114,    0,  115,   20,
  117,   94,    0,    0,    0,   94,    0,    0,   56,    0,
    0,    0,   11,   56,   56,   94,  160,    0,    0,    0,
    0,  164,  165,    0,    0,   55,   94,    0,    0,    0,
    0,    0,   52,    0,    0,    0,    0,   11,   87,    0,
   20,   99,   99,   99,   56,   56,   55,   56,    0,   56,
   56,    0,  173,   52,    0,  177,    0,    0,   56,    0,
    0,   56,   56,    0,  119,    0,    0,    0,    0,  187,
    0,    0,   56,    0,   11,   11,   11,   56,    0,    0,
    0,    0,   56,   56,    1,    2,    3,    4,    5,    6,
  198,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   55,   11,   11,   11,    0,   55,   55,   52,
    0,    0,    0,    0,   52,   52,    0,    0,    0,  108,
  109,  110,  111,   71,   67,   67,   70,   70,   67,   67,
    0,   71,    0,   67,    0,   70,    0,    0,   55,   55,
    0,   55,    0,   55,   55,   52,   52,    0,   52,    0,
   52,   52,   55,   79,    0,   55,   55,   84,   85,   52,
   88,    0,   52,   52,    0,    0,   55,    0,    0,  108,
  109,   87,    0,   52,    0,    0,   55,   55,  104,  105,
    0,    0,    0,   52,   52,    0,    0,    0,    0,    0,
    0,   10,    0,  126,    0,    0,    0,    0,    0,   17,
    0,  132,  134,   22,   10,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   22,  144,  145,  146,  147,
  148,  149,  150,  151,  152,  153,  154,  155,  156,    0,
   10,    0,   75,    1,    2,    3,    4,    5,    6,   46,
  166,    1,    2,    3,    4,    5,    6,   46,    0,    0,
   93,    0,    0,   22,   47,   10,   48,   49,    0,    0,
    0,    0,   47,    0,   48,   49,   50,    8,    0,    0,
    0,    0,   75,  174,   50,    8,    0,  182,  183,    1,
    2,    3,    4,    5,    6,   46,    0,    0,    0,   22,
    0,  189,   10,   10,   10,    0,    0,    0,    0,  178,
   47,    0,   48,   49,  195,    1,    2,    3,    4,    5,
    6,   75,   50,    8,    1,    2,    3,    4,    5,    6,
   46,   23,    0,    0,    1,    2,    3,    4,    5,    6,
    7,   10,   10,   10,    0,   47,    0,   48,   49,    8,
    0,    0,    0,    0,    0,    0,    0,   50,    8,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    8,
};
static const YYINT yycheck[] = {                         37,
   44,   41,   40,   41,   42,   43,   44,   45,   59,   47,
   59,   59,   59,   49,  121,   59,  165,  263,  125,  263,
   58,   59,   60,   37,   62,   59,   59,   41,   42,   43,
   44,   45,  283,   47,  284,  285,  286,  287,  173,   85,
   91,  263,  177,   40,   58,   59,   60,   41,   62,  198,
   44,   37,  187,   37,  161,   93,   42,   43,   42,   45,
   91,   47,  263,   47,   59,   41,  275,   43,   44,   45,
  275,  264,   41,   33,   60,   44,   62,   59,   40,   93,
   40,   41,   58,   59,   60,   41,   62,   43,   44,   45,
   41,   37,   41,   44,   93,   41,   42,   43,   91,   45,
   33,   47,   58,   59,   60,   37,   62,   40,  263,  263,
   42,   43,  275,   45,   60,   47,   62,   93,   40,   37,
  284,  285,  286,  287,   42,   43,   37,   45,   60,   47,
   62,   42,   43,   59,   45,   41,   47,   93,   44,   59,
  288,   59,   60,   59,   62,   41,   41,   37,   59,   60,
  196,   62,   42,   43,   59,   45,  192,   47,  275,   41,
   59,   93,   44,  284,  285,  286,  287,   91,   58,  275,
   60,   41,   62,   59,   44,  263,   58,   59,   60,   41,
   62,   41,   44,   41,   44,   93,   44,  263,   58,   59,
   60,  275,   62,  276,   59,   41,  275,   51,   44,   13,
   58,   59,   60,   59,   62,  257,  258,  259,  260,  261,
  262,   93,   58,   59,   60,   59,   62,  257,  258,  259,
  260,  261,  262,   93,  275,   59,  275,  275,  275,  267,
  268,  269,  270,  271,  272,   93,   37,  275,  276,  291,
   59,   42,   43,   59,   45,   81,   47,   93,  120,   41,
   -1,   -1,   44,  267,  268,  269,  270,  271,  272,   60,
   -1,   62,  276,   -1,   37,   -1,   58,   59,   -1,   42,
   43,   -1,   45,   -1,   47,  257,  258,  259,  260,  261,
  262,  267,  268,  269,  270,  271,  272,   60,   -1,   62,
  276,  267,  268,  269,  270,  271,  272,  101,  102,  103,
  276,   93,   -1,  263,  264,  265,   59,  284,  285,  286,
  287,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
  276,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
  263,  264,  265,   -1,   -1,  267,  268,  269,  270,  271,
  272,  257,  258,  259,  260,  261,  262,   -1,   -1,  267,
  268,  269,  270,  271,  272,   -1,  267,  268,  269,  270,
  271,  272,  257,  258,  259,  260,  261,  262,   -1,   -1,
    0,  257,  258,  259,  260,  261,  262,  267,  268,  269,
  270,  271,  272,   13,   -1,  267,  268,  269,  270,  271,
  272,   -1,   -1,   -1,  276,   -1,   -1,  267,  268,  269,
  270,  271,  272,   -1,   -1,   -1,  276,   -1,   -1,  267,
  268,  269,  270,  271,  272,   57,   -1,   -1,  276,   -1,
   -1,  267,  268,  269,  270,  271,  272,   37,   -1,   -1,
  276,    0,   42,   43,   64,   45,   41,   47,   41,   44,
   41,   44,   -1,   44,   13,  284,  285,  286,  287,   -1,
   60,   36,   62,   58,   59,   58,   59,   58,   59,   -1,
   -1,   -1,   -1,   -1,   49,   -1,  267,  268,  269,  270,
  271,  272,   57,   -1,   -1,  267,  268,   37,   -1,  271,
  272,   -1,   42,   43,  276,   45,   -1,   47,   93,   -1,
   93,   -1,   93,   -1,  267,   64,  269,  270,  271,  272,
   60,   -1,   62,    0,  257,  258,  259,  260,  261,  262,
  140,  141,  142,   -1,   -1,   -1,   13,   -1,  160,   -1,
   37,   -1,  164,  165,   -1,   42,   43,   -1,   45,   10,
   47,  173,   -1,   -1,   -1,  177,   -1,   -1,  123,   -1,
   -1,   -1,   39,  128,  129,  187,  123,   -1,   -1,   -1,
   -1,  128,  129,   -1,   -1,   36,  198,   -1,   -1,   -1,
   -1,   -1,   36,   -1,   -1,   -1,   -1,   64,   49,   -1,
   51,  140,  141,  142,  159,  160,   57,  162,   -1,  164,
  165,   -1,  159,   57,   -1,  162,   -1,   -1,  173,   -1,
   -1,  176,  177,   -1,   75,   -1,   -1,   -1,   -1,  176,
   -1,   -1,  187,   -1,  101,  102,  103,  192,   -1,   -1,
   -1,   -1,  197,  198,  257,  258,  259,  260,  261,  262,
  197,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  123,  140,  141,  142,   -1,  128,  129,  123,
   -1,   -1,   -1,   -1,  128,  129,   -1,   -1,   -1,  269,
  270,  271,  272,  268,  267,  268,  267,  268,  271,  272,
   -1,  276,   -1,  276,   -1,  276,   -1,   -1,  159,  160,
   -1,  162,   -1,  164,  165,  159,  160,   -1,  162,   -1,
  164,  165,  173,   43,   -1,  176,  177,   47,   48,  173,
   50,   -1,  176,  177,   -1,   -1,  187,   -1,   -1,  269,
  270,  192,   -1,  187,   -1,   -1,  197,  198,   68,   69,
   -1,   -1,   -1,  197,  198,   -1,   -1,   -1,   -1,   -1,
   -1,    0,   -1,   83,   -1,   -1,   -1,   -1,   -1,    8,
   -1,   91,   92,   12,   13,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   24,  106,  107,  108,  109,
  110,  111,  112,  113,  114,  115,  116,  117,  118,   -1,
   39,   -1,   41,  257,  258,  259,  260,  261,  262,  263,
  130,  257,  258,  259,  260,  261,  262,  263,   -1,   -1,
  274,   -1,   -1,   62,  278,   64,  280,  281,   -1,   -1,
   -1,   -1,  278,   -1,  280,  281,  290,  291,   -1,   -1,
   -1,   -1,   81,  289,  290,  291,   -1,  167,  168,  257,
  258,  259,  260,  261,  262,  263,   -1,   -1,   -1,   98,
   -1,  181,  101,  102,  103,   -1,   -1,   -1,   -1,  277,
  278,   -1,  280,  281,  194,  257,  258,  259,  260,  261,
  262,  120,  290,  291,  257,  258,  259,  260,  261,  262,
  263,  273,   -1,   -1,  257,  258,  259,  260,  261,  262,
  282,  140,  141,  142,   -1,  278,   -1,  280,  281,  291,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  290,  291,  282,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  291,
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
#line 244 "limbaj.y"
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
               printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n", F[j].func_table[i].Name, F[j].func_table[i].Scope, F[j].func_table[i].Return, F[j].func_table[i].ParamNumber, F[j].func_table[i].line_no);
               printf("PARAM_TYPE\t");

     printf("P R I N T : %d\n", F[j].func_table[i].ParamNumber);
               for (int k = 0; k <  F[j].func_table[i].ParamNumber; ++k)
                    printf("%s\t", F[j].func_table[i].ParamType[k]);

               printf("\n\n");
          }
     }


     for(j=0; j <= max_scope; ++j)
          for(i=0; i < F[j].totalFunc; i++)
          {
               free(F[j].func_table[i].Name);
               free(F[j].func_table[i].Scope);
               free(F[j].func_table[i].Return);

               for (int j = 0; j <  F[j].func_table[i].ParamNumber; ++j)
               {
                    free(F[j].func_table[i].ParamType[j]);
               }
          }

	printf("\n\n");
}

int getVariableIndex(char* varName)
{
	for (int i = 0; i < S[current_scope].totalVar; i++) 
		if (strcmp(varName, S[current_scope].var_table[i].id) == 0)
			return i;

	return -1;
}

void AddConstantVariable(char* id, char* type, char* constant, int arrsize)
{
	int i = getVariableIndex(id);

	if (i != -1)
    {
		printf("The variable %s was already declared on line %d\n", id, S[current_scope].var_table[i].line_no);
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
     int i = getVariableIndex(id);

     if (i != -1)
     {
          printf("ERROR! Variabile %s has been already declared on line %d.\n", id, S[current_scope].var_table[i].line_no);
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
	int i = getVariableIndex(id);

     if (i == -1)
     {
          printf("AddDataType :: Internal error!\n");
          exit(0);
     }

     S[current_scope].var_table[i].data_type = strdup(type);
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
               printf("ERROR! You cannot declare void variable type. (line %d).\n", yylineno);
               exit(0);
     }
}

int getFunctionIndex(char* varName)
{
	for (int i = 0; i < F[current_scope].totalFunc; i++) 
		if (strcmp(varName, F[current_scope].func_table[i].Name) == 0)
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
     }
}

void CheckArrayRange(char* arr, int pos)
{
     int i = getVariableIndex(arr);

     if (i == -1)
          PrintErrorAndExit(4);

     if (pos < 0 || pos > S[current_scope].var_table[i].arrsize)
          PrintErrorAndExit(3);
}

void PushFunction(char* name, char* ret_type)
{
	int i = getFunctionIndex(name);

	if (i != -1)
		PrintErrorAndExit(5);

     int pos = F[current_scope].totalFunc;

     F[current_scope].func_table[pos].Name = strdup(name);
     F[current_scope].func_table[pos].Return = strdup(ret_type);
     F[current_scope].func_table[pos].line_no = yylineno;

	F[current_scope].totalFunc++;

}

void PushParameters(char* type)
{
     printf("\t\t\t Current_scope: %d", current_scope);
     printf("\t\tTotalFunc: %d\n", F[current_scope].totalFunc);
     int pos = F[current_scope].totalFunc;
     int *j = &F[current_scope].func_table[pos].ParamNumber;

     F[current_scope].func_table[pos].ParamType[*j] = strdup(type);

     (*j)++; 
}

void AddParamToVarList(char* id, char* type)
{
	int i = getVariableIndex(id);

     if (i != -1)
     {
          printf("Variable %s already declared!!\n", id);
          exit(0);
     }


     int pos = S[current_scope].totalVar;

     S[current_scope].var_table[pos].id = strdup(id);
     S[current_scope].var_table[pos].data_type = strdup(type);
     S[current_scope].var_table[pos].line_no = yylineno;

	S[current_scope].totalVar++;
}

void NewScope()
{
     max_scope++;
     S[max_scope].Parent = current_scope;
     current_scope += 1;
}
void ExitScope()
{
     current_scope -= 1;
}

void type_check(char* left, char* right)
{
	if(strcmp(left, right) != 0)
     {
          printf("Type mismatch between operands (%s - %s).\n", left, right);
          exit(0);
     }
}

int FindVariableWithScope(char* varName, int scope)
{
	for (int i = 0; i < S[scope].totalVar; i++) 
		if (strcmp(varName, S[scope].var_table[i].id) == 0)
			return i;

	return -1;
}

int FindFunctionWithScope(char* funcName, int scope)
{
	for (int i = 0; i < F[scope].totalFunc; i++) 
		if (strcmp(funcName, F[scope].func_table[i].Name) == 0)
			return i;

	return -1;
}

char* GetType(int type, char* id)
{
     int i = 0, flag = 0;
     int iCurScope = current_scope;

     if(type == 1)
     {
          while (flag == 0) {
               if (iCurScope == 0)
                    flag = 1;

               i = FindVariableWithScope(id, iCurScope);

               if (i == -1)
               {
                    iCurScope = S[iCurScope].Parent;
               }
               else 
                    flag = 1;

          }

          if (i == -1)
          {
               printf("Illegal use of undeclared variable! (name: %s, line: %d)\n", id, yylineno);
               exit(0);
          }

          return S[iCurScope].var_table[i].data_type;
     }
     else if (type == 2)
     {

          while (flag == 0) {
               if (iCurScope == 0)
                    flag = 1;

               i = FindFunctionWithScope(id, iCurScope);

               if (i == -1)
               {
                    printf("%d\t%d", iCurScope, F[iCurScope].Parent);
                    iCurScope = F[iCurScope].Parent;
               }
               else 
                    flag = 1;

          }

          if (i == -1)
          {
               printf("%s %d\n", id, yylineno);
               printf("Illegal use of undeclared function! (name: %s, line: %d)\n", id, yylineno);
               exit(0);
          }

          return F[iCurScope].func_table[iCurScope].Return;
     }
}

int main(int argc, char** argv)
{
     yyin=fopen(argv[1],"r");
     yyparse();
     PrintVar();
     PrintFunc();
}
#line 944 "y.tab.c"

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
#line 80 "limbaj.y"
	{yyval.type_id = strdup("Integer");   }
break;
case 2:
#line 81 "limbaj.y"
	{yyval.type_id = strdup("Float");   }
break;
case 3:
#line 82 "limbaj.y"
	{yyval.type_id = strdup("Character");  }
break;
case 4:
#line 83 "limbaj.y"
	{yyval.type_id = strdup("Bool");   }
break;
case 5:
#line 84 "limbaj.y"
	{yyval.type_id = strdup("String");   }
break;
case 6:
#line 85 "limbaj.y"
	{yyval.type_id = strdup("Void");   }
break;
case 7:
#line 88 "limbaj.y"
	{printf("program corect sintactic\n");}
break;
case 8:
#line 91 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].strval); AddNewVariable(yystack.l_mark[0].strval);       }
break;
case 9:
#line 92 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[-3].strval); AddArraySize(yystack.l_mark[-3].strval, yystack.l_mark[-1].intval);     }
break;
case 10:
#line 95 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].strval); }
break;
case 11:
#line 96 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].strval); }
break;
case 12:
#line 99 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].var_name); }
break;
case 13:
#line 102 "limbaj.y"
	{ yyval.strval = strdup(yystack.l_mark[-3].var_name); }
break;
case 14:
#line 105 "limbaj.y"
	{ yyval.type_id = GetType(2, yystack.l_mark[-3].strval); }
break;
case 15:
#line 106 "limbaj.y"
	{ yyval.type_id = GetType(2, yystack.l_mark[-2].strval); }
break;
case 22:
#line 118 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 23:
#line 119 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 36:
#line 141 "limbaj.y"
	{ NewScope(); }
break;
case 37:
#line 141 "limbaj.y"
	{ { ExitScope(); } }
break;
case 41:
#line 148 "limbaj.y"
	{ PushParameters(yystack.l_mark[-1].type_id); AddParamToVarList(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 42:
#line 149 "limbaj.y"
	{ PushParameters(yystack.l_mark[-3].type_id); AddParamToVarList(yystack.l_mark[-2].strval, yystack.l_mark[-3].type_id); }
break;
case 43:
#line 153 "limbaj.y"
	{ NewScope(); }
break;
case 44:
#line 153 "limbaj.y"
	{ NewScope(); }
break;
case 47:
#line 164 "limbaj.y"
	{ NewScope(); }
break;
case 48:
#line 164 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-7].var_name, yystack.l_mark[-8].type_id); }
break;
case 49:
#line 165 "limbaj.y"
	{ NewScope(); }
break;
case 50:
#line 165 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-6].var_name, yystack.l_mark[-7].type_id); }
break;
case 51:
#line 166 "limbaj.y"
	{ NewScope(); }
break;
case 52:
#line 166 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-8].type_id, yystack.l_mark[-9].strval); }
break;
case 53:
#line 167 "limbaj.y"
	{ NewScope(); }
break;
case 54:
#line 167 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-7].type_id, yystack.l_mark[-8].strval); }
break;
case 57:
#line 177 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); AddConstantVariable(yystack.l_mark[-2].var_name, yystack.l_mark[-3].type_id, "true", 0); yyval.type_id = GetType(1, yystack.l_mark[-2].var_name); }
break;
case 58:
#line 181 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 59:
#line 182 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 60:
#line 183 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 61:
#line 184 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 62:
#line 185 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 63:
#line 186 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[-1].type_id); }
break;
case 64:
#line 187 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 65:
#line 188 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 66:
#line 189 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 67:
#line 190 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 68:
#line 191 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 69:
#line 192 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 70:
#line 193 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 71:
#line 194 "limbaj.y"
	{ type_check(yystack.l_mark[-2].type_id, yystack.l_mark[0].type_id); yyval.type_id = strdup(yystack.l_mark[-2].type_id); }
break;
case 72:
#line 195 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[0].type_id); }
break;
case 73:
#line 196 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[0].type_id); }
break;
case 74:
#line 200 "limbaj.y"
	{ yyval.type_id = GetType(1, yystack.l_mark[0].strval);        }
break;
case 75:
#line 201 "limbaj.y"
	{ yyval.type_id = strdup("Integer");     }
break;
case 76:
#line 202 "limbaj.y"
	{ yyval.type_id = strdup("Integer");     }
break;
case 77:
#line 203 "limbaj.y"
	{ yyval.type_id = strdup("String"); printf("%s\n", yystack.l_mark[0].strval);     }
break;
case 78:
#line 204 "limbaj.y"
	{ yyval.type_id = strdup(yystack.l_mark[0].type_id);            }
break;
case 79:
#line 208 "limbaj.y"
	{ NewScope(); }
break;
case 80:
#line 211 "limbaj.y"
	{ ExitScope(); }
break;
case 84:
#line 227 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
case 86:
#line 229 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); AddDataType(yystack.l_mark[0].strval, yystack.l_mark[-1].type_id); }
break;
#line 1371 "y.tab.c"
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
