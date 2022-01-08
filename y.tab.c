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
    1,    1,    1,    1,    1,    1,    0,    2,    2,    2,
    2,    2,    2,    4,    4,    4,    4,    4,    4,    4,
   10,   10,   11,   11,   11,   11,   12,   12,    5,    7,
    7,   13,    3,   15,   16,    6,    6,    6,    6,   17,
   17,   17,   17,   17,   17,   14,   14,    9,    8,    8,
    8,    8,    8,    8,    8,   19,   19,   19,   19,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   21,   22,   23,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   24,   24,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    2,    3,    2,
    2,    3,    2,    2,    5,    4,    4,    1,    5,    7,
    2,    3,    1,    3,    3,    3,    1,    3,    7,    1,
    3,    2,    3,    1,    1,    8,    7,    9,    8,    3,
    4,    2,    3,    4,    3,    2,    3,    5,    3,    3,
    3,    3,    3,    2,    1,    1,    1,    4,    4,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    1,
    5,    5,   14,    4,    3,    3,    2,    4,    5,    6,
    6,    7,    1,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    7,
    0,   10,    0,    8,   11,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   83,    0,    0,
   84,   85,   86,    9,   12,    0,    0,    0,    0,    0,
    0,    0,   57,    0,    0,   55,    0,    0,    0,   30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   33,    0,   46,    0,   48,    0,   21,    0,    0,
    0,    0,    0,    0,   54,    0,    0,    0,    0,    0,
   34,    0,   32,    0,    0,    0,    0,   75,    0,    0,
    0,    0,   69,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   47,    0,    0,
    0,   22,   27,    0,    0,    0,    0,    0,    0,    0,
    0,   51,   52,   53,    0,    0,    0,   31,    0,    0,
    0,   74,    0,    0,   60,    0,    0,   65,   66,    0,
    0,    0,   62,   61,    0,    0,    0,    0,    0,    0,
   16,    0,    0,   29,   59,   58,    0,    0,   35,    0,
   37,    0,   42,    0,    0,    0,    0,    0,   71,   72,
    0,    0,    0,    0,   15,   28,   43,   45,    0,    0,
   40,   36,    0,    0,    0,    0,   39,    0,   41,   44,
    0,    0,   38,    0,    0,    0,    0,    0,    0,   73,
};
static const YYINT yydgoto[] = {                          9,
   37,   11,   20,   49,   13,   14,   59,   67,   38,   50,
   51,  124,   60,   39,   92,  171,  136,   40,   56,   68,
   41,   42,   43,  100,
};
static const YYINT yysindex[] = {                       118,
    0,    0,    0,    0,    0,    0,  106, -234,    0, -228,
  -74,    1,   11,  -56,    0, -192, -203,  -27,  341,    0,
   34,    0,  -48,    0,    0,    0, -164, -165,  177,   24,
  -40, -146,   -9,   33,   33, -150, -143,    0,  260,   90,
    0,    0,    0,    0,    0,   94, -102,  -97,  110,  177,
  -41,   87,    0,   24,  125,    0, -105,  -72,    5,    0,
   96,   24,   44, -124,   33,   33,  125,   56,   66,  -78,
  -79,    0,  141,    0,   53,    0,   -8,    0,  149,  -47,
  177,  177,  177, -118,    0,   24,   24,   24,   24,   24,
    0,  127,    0,  106, -105,  -59,  125,    0,  125,   17,
  130,  142,    0,   35,   33,   33,   33,   33,   33,   33,
  341,   33,   33,  341,   24,   24,  -10,    0, -105,   40,
   59,    0,    0,   -5,  177,  177,  177,  155,  163,   75,
   75,    0,    0,    0,  -71, -156,  218,    0,  127,   24,
   24,    0,   14,   18,    0,   86,   82,    0,    0,  -44,
  -44,  285,    0,    0,  309,  134,  125,  200,  127, -105,
    0,   46,   31,    0,    0,    0,  236,  238,    0,  -66,
    0,  240,    0, -156,  125,  125,   24,   24,    0,    0,
   33,   26, -156,  127,    0,    0,    0,    0,  249,  269,
    0,    0,  125,  125,   76,   24,    0, -156,    0,    0,
   24,  125,    0,  -28,   24,  368,   54,  341,  317,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  280,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  117,
    0,  -37,    0,    0,  281,    0,  290,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0,    0,    0,
  299,    0,    0,    0,    0,    0,  280,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  300,  301,  302,    0,   47,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  135,  168,  174,    0,    0,  -17,
   -7,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -39,   16,    0,    0,    9,
   15,    0,    0,    0,    0,    0,  110,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  310,   99,    0,    0,    0,    0,
    0,  313,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  314,  315,    0,    0,    0,    0,    0,    0,
    0,  322,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  433,    0,    0,  114,  381,  382,  -35,  308,   48,   78,
    0,    0,  318,  -81,  -23,  -18,  -92,  291,  372,   45,
    0,    0,    0,    0,
};
#define YYTABLESIZE 621
static const YYINT yytable[] = {                         56,
   57,   67,   26,   56,   56,   56,   56,   56,   90,   56,
   45,  117,   31,   88,   86,  112,   87,  113,   89,   67,
   56,   56,   56,   49,   56,   49,   49,   49,   17,  152,
   63,  121,  155,   50,   18,   50,   50,   50,  163,  120,
   49,   49,   49,   70,   49,   95,  174,   15,   94,   63,
   50,   50,   50,  164,   50,   64,   68,  142,   15,   24,
  141,   70,   70,   32,   70,   65,  183,   63,   54,   25,
   28,  139,   66,   64,   68,  145,   15,   54,   29,   69,
  160,   64,   32,   94,   98,  162,  185,   87,   54,   94,
   87,  198,   44,  119,  112,  159,  113,   15,   46,  161,
    1,    2,    3,    4,    5,    6,   33,    7,   47,  103,
  104,   90,   52,   12,   53,  112,   88,  113,   61,   71,
   34,   89,   35,   36,   21,  112,  209,  113,   15,   15,
   15,  169,  170,   75,  201,  112,  184,  113,  101,   88,
  102,  112,   88,  113,  128,  112,  129,  113,   74,  146,
  147,  148,  149,  150,  151,  192,  153,  154,  125,  126,
  127,   90,   76,   79,  197,   77,   88,   86,   78,   87,
   90,   89,   15,   15,   15,   88,   86,   84,   87,  203,
   89,   91,    1,    2,    3,    4,    5,    6,   96,    7,
   93,  167,  181,  168,  116,  115,  189,   19,  190,  118,
    1,    2,    3,    4,    5,    6,    8,  122,    1,    2,
    3,    4,    5,    6,  140,  123,    1,    2,    3,    4,
    5,    6,  143,  107,  108,  195,   67,   67,   56,   56,
   56,   56,   56,   56,  144,   67,   56,   56,   79,   79,
   79,   80,   81,   82,   83,  205,   30,  165,   49,   49,
   49,   49,   49,   49,  158,  166,   49,   49,   50,   50,
   50,   50,   50,   50,   62,   30,   50,   50,   70,   70,
   70,   70,   70,   70,   63,   63,  173,   70,   63,   63,
   64,   64,   68,   63,   64,   64,   52,  177,   53,   64,
   68,  178,  182,  186,  187,   52,  188,   53,  191,  196,
  105,  106,  107,  108,  109,  110,   52,  199,   53,    1,
    2,    3,    4,    5,    6,    1,    2,    3,    4,    5,
    6,  105,  106,  107,  108,  109,  110,  200,  208,   73,
  111,  105,  106,  107,  108,  109,  110,   55,   14,   17,
  114,  105,  106,  107,  108,  109,  110,  105,   16,  107,
  108,  109,  110,  107,  108,  109,  110,   77,   15,   19,
   76,   85,    1,    2,    3,    4,    5,    6,   20,   97,
   99,   79,   80,   81,    1,    2,    3,    4,    5,    6,
   82,    7,  137,    1,    2,    3,    4,    5,    6,   33,
    7,   22,   23,  130,  131,  132,  133,  134,    8,   23,
   23,   23,   23,   34,   90,   35,   36,   70,    0,   88,
   86,  138,   87,    0,   89,  135,    0,   24,   24,   24,
   24,    0,  156,  157,    0,  207,  172,    0,    0,  137,
    0,    0,   10,    1,    2,    3,    4,    5,    6,   16,
    7,    0,   73,   10,    0,   73,   27,  175,  176,  137,
   25,   25,   25,   25,    0,   27,   26,   26,   26,   26,
    0,   48,    0,   58,  172,    0,    0,    0,    0,    0,
    0,    0,    0,  172,  137,    0,    0,    0,    0,    0,
    0,    0,   48,    0,  193,  194,    0,    0,  172,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   73,
    0,    0,    0,  202,    0,    0,    0,   58,  204,    0,
    0,    0,  206,   48,   48,   48,    1,    2,    3,    4,
    5,    6,   33,    7,    0,    0,   58,    0,    0,    0,
    0,    0,   72,    0,    0,    0,   34,    0,   35,   36,
    0,    1,    2,    3,    4,    5,    6,   33,    7,    0,
    0,    0,    0,   58,    0,    0,    0,   48,   48,   48,
  179,   34,    0,   35,   36,    1,    2,    3,    4,    5,
    6,   33,    7,    1,    2,    3,    4,    5,    6,   33,
    7,    0,    0,    0,  180,   34,    0,   35,   36,    0,
    0,    0,  210,   34,    0,   35,   36,    1,    2,    3,
    4,    5,    6,   33,    7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,    0,   35,
   36,
};
static const YYINT yycheck[] = {                         37,
   41,   41,   59,   41,   42,   43,   44,   45,   37,   47,
   59,   91,   40,   42,   43,   60,   45,   62,   47,   59,
   58,   59,   60,   41,   62,   43,   44,   45,  263,  111,
   40,   40,  114,   41,  263,   43,   44,   45,   44,   75,
   58,   59,   60,   41,   62,   41,  139,    0,   44,   41,
   58,   59,   60,   59,   62,   41,   41,   41,   11,   59,
   44,   59,   60,   91,   62,   33,  159,   59,   45,   59,
  263,   95,   40,   59,   59,   41,   29,   45,  282,   35,
   41,   91,   91,   44,   41,  121,   41,   41,   45,   44,
   44,  184,   59,   41,   60,  119,   62,   50,  263,   41,
  257,  258,  259,  260,  261,  262,  263,  264,  274,   65,
   66,   37,  263,    0,  265,   60,   42,   62,  265,  263,
  277,   47,  279,  280,   11,   60,  208,   62,   81,   82,
   83,  288,  289,   40,   59,   60,  160,   62,  263,   41,
  265,   60,   44,   62,  263,   60,  265,   62,   59,  105,
  106,  107,  108,  109,  110,  174,  112,  113,   81,   82,
   83,   37,  265,   50,  183,  263,   42,   43,   59,   45,
   37,   47,  125,  126,  127,   42,   43,   91,   45,  198,
   47,  287,  257,  258,  259,  260,  261,  262,   93,  264,
  263,  263,   59,  265,  274,  274,  263,  272,  265,   59,
  257,  258,  259,  260,  261,  262,  281,   59,  257,  258,
  259,  260,  261,  262,  274,  263,  257,  258,  259,  260,
  261,  262,   93,  268,  269,  181,  266,  267,  266,  267,
  268,  269,  270,  271,   93,  275,  274,  275,  125,  126,
  127,  283,  284,  285,  286,  274,  274,   93,  266,  267,
  268,  269,  270,  271,  265,   93,  274,  275,  266,  267,
  268,  269,  270,  271,  274,  274,  274,  275,  266,  267,
  268,  269,  270,  271,  266,  267,   59,  275,  270,  271,
  266,  267,  267,  275,  270,  271,  263,  274,  265,  275,
  275,  274,   93,  263,   59,  263,   59,  265,   59,  274,
  266,  267,  268,  269,  270,  271,  263,   59,  265,  257,
  258,  259,  260,  261,  262,  257,  258,  259,  260,  261,
  262,  266,  267,  268,  269,  270,  271,   59,  275,   39,
  275,  266,  267,  268,  269,  270,  271,   30,   59,   59,
  275,  266,  267,  268,  269,  270,  271,  266,   59,  268,
  269,  270,  271,  268,  269,  270,  271,   59,   59,   59,
   59,   54,  257,  258,  259,  260,  261,  262,   59,   62,
   63,   59,   59,   59,  257,  258,  259,  260,  261,  262,
   59,  264,   92,  257,  258,  259,  260,  261,  262,  263,
  264,   11,   11,   86,   87,   88,   89,   90,  281,  283,
  284,  285,  286,  277,   37,  279,  280,   36,   -1,   42,
   43,   94,   45,   -1,   47,  289,   -1,  283,  284,  285,
  286,   -1,  115,  116,   -1,   58,  136,   -1,   -1,  139,
   -1,   -1,    0,  257,  258,  259,  260,  261,  262,    7,
  264,   -1,  152,   11,   -1,  155,   14,  140,  141,  159,
  283,  284,  285,  286,   -1,   23,  283,  284,  285,  286,
   -1,   29,   -1,   31,  174,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  183,  184,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   50,   -1,  177,  178,   -1,   -1,  198,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  209,
   -1,   -1,   -1,  196,   -1,   -1,   -1,   75,  201,   -1,
   -1,   -1,  205,   81,   82,   83,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,   94,   -1,   -1,   -1,
   -1,   -1,  273,   -1,   -1,   -1,  277,   -1,  279,  280,
   -1,  257,  258,  259,  260,  261,  262,  263,  264,   -1,
   -1,   -1,   -1,  121,   -1,   -1,   -1,  125,  126,  127,
  276,  277,   -1,  279,  280,  257,  258,  259,  260,  261,
  262,  263,  264,  257,  258,  259,  260,  261,  262,  263,
  264,   -1,   -1,   -1,  276,  277,   -1,  279,  280,   -1,
   -1,   -1,  276,  277,   -1,  279,  280,  257,  258,  259,
  260,  261,  262,  263,  264,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,   -1,  279,
  280,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 318
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
0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"declaratii : declaratie ';'",
"declaratii : declaratii declaratie ';'",
"declaratii : declaratii initializare_clasa",
"declaratii : initializare_clasa ';'",
"declaratii : declaratii descriere_functii ';'",
"declaratii : descriere_functii ';'",
"declaratie : DATA_TYPE ID",
"declaratie : DATA_TYPE ID '(' lista_param ')'",
"declaratie : DATA_TYPE ID '(' ')'",
"declaratie : DATA_TYPE ID ASSIGN expr",
"declaratie : constant",
"declaratie : DATA_TYPE ID '[' NR ']'",
"declaratie : DATA_TYPE ID '[' NR ']' ASSIGN expr",
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
"param : DATA_TYPE ID",
"bloc : BGIN list END",
"enter_func : BEGINFNCTN",
"leave_func : ENDFNCTN",
"descriere_functii : DATA_TYPE ID '(' lista_param ')' enter_func list_function leave_func",
"descriere_functii : DATA_TYPE ID '(' ')' enter_func list_function leave_func",
"descriere_functii : descriere_functii DATA_TYPE ID '(' lista_param ')' enter_func list_function leave_func",
"descriere_functii : descriere_functii DATA_TYPE ID '(' ')' enter_func list_function leave_func",
"list_function : list_function statement ';'",
"list_function : list_function RTRN ID ';'",
"list_function : statement ';'",
"list_function : RTRN ID ';'",
"list_function : list_function RTRN NR ';'",
"list_function : RTRN NR ';'",
"list : statement ';'",
"list : list statement ';'",
"constant : CONST DATA_TYPE ID ASSIGN NR",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : '-' expr",
"expr : operand",
"operand : ID",
"operand : NR",
"operand : ID '[' NR ']'",
"operand : ID '[' ID ']'",
"boolexpr : '(' boolexpr ')'",
"boolexpr : boolexpr '>' boolexpr",
"boolexpr : boolexpr '<' boolexpr",
"boolexpr : boolexpr EQ boolexpr",
"boolexpr : boolexpr NOT_EQ boolexpr",
"boolexpr : boolexpr LS_EQ boolexpr",
"boolexpr : boolexpr GR_EQ boolexpr",
"boolexpr : boolexpr LOGICAL_AND boolexpr",
"boolexpr : boolexpr LOGICAL_OR boolexpr",
"boolexpr : '!' boolexpr",
"boolexpr : expr",
"if_stmt : IF boolexpr BEGINSTMT list ENDSTMT",
"while_stmt : WHILE boolexpr BEGINSTMT list ENDSTMT",
"for_stmt : FOR operand ASSIGN expr ';' boolexpr ';' expr ASSIGN expr ':' BEGINSTMT list ENDSTMT",
"statement : ID '(' lista_apel ')'",
"statement : ID '(' ')'",
"statement : ID ASSIGN expr",
"statement : DATA_TYPE ID",
"statement : DATA_TYPE ID ASSIGN expr",
"statement : DATA_TYPE ID '[' NR ']'",
"statement : ID '[' ID ']' ASSIGN expr",
"statement : ID '[' NR ']' ASSIGN expr",
"statement : DATA_TYPE ID '[' NR ']' ASSIGN expr",
"statement : constant",
"statement : if_stmt",
"statement : while_stmt",
"statement : for_stmt",
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
#line 741 "y.tab.c"

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
case 14:
#line 95 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); pushEmptyVariable(yystack.l_mark[0].string, yystack.l_mark[-1].type_id, "false", 0); }
break;
case 15:
#line 96 "limbaj.y"
	{ PushFunction(yystack.l_mark[-3].string, yystack.l_mark[-4].type_id); }
break;
case 16:
#line 97 "limbaj.y"
	{ PushFunction(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id); }
break;
case 17:
#line 98 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "false", 0);}
break;
case 19:
#line 100 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-4].type_id); pushEmptyVariable(yystack.l_mark[-3].string, yystack.l_mark[-4].type_id, "false", yystack.l_mark[-1].intval); }
break;
case 20:
#line 101 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-6].type_id); pushEmptyVariable(yystack.l_mark[-5].string, yystack.l_mark[-6].type_id, "false", yystack.l_mark[-3].intval); }
break;
case 32:
#line 127 "limbaj.y"
	{ PushParameters(yystack.l_mark[0].string, yystack.l_mark[-1].type_id); }
break;
case 34:
#line 134 "limbaj.y"
	{ EnterFunction(); }
break;
case 35:
#line 137 "limbaj.y"
	{ ExitFunction(); }
break;
case 36:
#line 142 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].string); }
break;
case 37:
#line 143 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-5].string); }
break;
case 38:
#line 144 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-7].type_id); }
break;
case 39:
#line 145 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].type_id); }
break;
case 48:
#line 164 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "true", 0);}
break;
case 74:
#line 211 "limbaj.y"
	{ ResetCallStack(); }
break;
case 75:
#line 212 "limbaj.y"
	{ ResetCallStack(); }
break;
case 77:
#line 214 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); pushEmptyVariable(yystack.l_mark[0].string, yystack.l_mark[-1].type_id, "false", 0);}
break;
case 78:
#line 215 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "false", 0);}
break;
case 79:
#line 216 "limbaj.y"
	{ CheckArrayRange(yystack.l_mark[-3].string, yystack.l_mark[-1].intval); }
break;
case 81:
#line 218 "limbaj.y"
	{ CheckArrayRange(yystack.l_mark[-5].string, yystack.l_mark[-3].intval); }
break;
case 82:
#line 219 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-6].type_id); pushEmptyVariable(yystack.l_mark[-5].string, yystack.l_mark[-6].type_id, "false", yystack.l_mark[-3].intval);}
break;
#line 1052 "y.tab.c"
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
