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
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,   19,   19,   19,   19,   20,
   21,   22,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   23,   23,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    2,    3,    2,
    2,    3,    2,    2,    5,    4,    4,    1,    5,    7,
    2,    3,    1,    3,    3,    3,    1,    3,    7,    1,
    3,    2,    3,    1,    1,    8,    7,    9,    8,    3,
    4,    2,    3,    4,    3,    2,    3,    5,    3,    3,
    3,    3,    3,    3,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    1,    1,    1,    4,    4,    5,
    5,   14,    4,    3,    3,    2,    4,    5,    6,    6,
    7,    1,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    7,
    0,   10,    0,    8,   11,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   82,    0,    0,
   83,   84,   85,    9,   12,    0,    0,    0,    0,    0,
    0,    0,   67,    0,    0,    0,    0,   65,    0,    0,
    0,   30,    0,    0,    0,    0,    0,    0,    0,    0,
   33,    0,   46,    0,   48,    0,   21,    0,    0,    0,
    0,    0,    0,   55,   64,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   34,
    0,   32,    0,    0,    0,    0,   74,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   47,    0,    0,    0,
   22,   27,    0,    0,    0,    0,    0,    0,   54,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   51,
   52,   53,    0,    0,    0,   31,    0,    0,    0,   73,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   16,
    0,    0,   29,   69,   68,    0,    0,   35,    0,   37,
    0,   42,    0,    0,    0,    0,    0,   70,   71,    0,
    0,    0,    0,   15,   28,   43,   45,    0,    0,   40,
   36,    0,    0,    0,    0,   39,    0,   41,   44,    0,
    0,   38,    0,    0,    0,    0,    0,    0,   72,
};
static const YYINT yydgoto[] = {                          9,
   37,   11,   20,   49,   13,   14,   61,   57,   38,   50,
   51,  123,   62,   39,  101,  170,  144,   40,   58,   41,
   42,   43,  109,
};
static const YYINT yysindex[] = {                       359,
    0,    0,    0,    0,    0,    0, -176, -248,    0, -247,
  240,  -39,  -15,  213,    0, -215, -190,  -38,  486,    0,
   49,    0,  222,    0,    0,    0, -147, -157,   54,   78,
   87, -133,  -27,   78,   78, -197, -125,    0,  411,   86,
    0,    0,    0,    0,    0,  124, -107,  -98,  116,   54,
  129,   82,    0,   78,   78,   78,  152,    0, -102,  -71,
   80,    0,  105,   78,  -14, -164,  -13,   -2,  -74,  -90,
    0,  158,    0,  182,    0,  -26,    0,  176,  -18,   54,
   54,   54,  -82,    0,    0,   53,   78,   78,   78,   78,
   78,   78,   78,   78,   78,   78,   78,   78,   78,    0,
  299,    0, -176, -102,  -24,  152,    0,  152,   96,  170,
  177,  486,  486,   78,   78,   -6,    0, -102,  103,  203,
    0,    0,  -41,   54,   54,   54,  178,  189,    0,  166,
  159,  173,  173,  364,  364,  173,  173,  114,  114,    0,
    0,    0,  -72,  231,  193,    0,  299,   78,   78,    0,
   16,   27,  419,  454,   60,  152,  209,  299, -102,    0,
  119,   11,    0,    0,    0,  246,  248,    0,  -58,    0,
  251,    0,  231,  152,  152,   78,   78,    0,    0,   78,
   32,  231,  299,    0,    0,    0,    0,  258,  266,    0,
    0,  152,  152,   67,   78,    0,  231,    0,    0,   78,
  152,    0,    9,   78,   88,   57,  486,  462,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  280,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  247,
    0,  -37,    0,    0,    0,    0,  281,    0,  283,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  291,
    0,    0,    0,    0,    0,  280,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  292,  293,  294,    0,  130,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  284,  358,  376,    0,    0,    0,  202,
  250,   95,  108,  181,  183,  118,  128,   18,   29,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  116,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  301,  138,    0,    0,    0,    0,    0,
  308,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  309,  312,    0,    0,    0,    0,    0,    0,    0,
  313,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  584,    0,    0,   17,  362,  369,  -65,  451,  523,  -44,
    0,    0,  278, -101,  -25, -140, -108,  428,  354,    0,
    0,    0,    0,
};
#define YYTABLESIZE 766
static const YYINT yytable[] = {                         66,
  116,   31,  162,   66,   66,   66,   66,   66,  119,   66,
  153,  154,   65,  120,   17,   18,   12,  163,   55,   24,
   66,   66,   66,   99,   66,   56,  107,   21,   97,   95,
   54,   96,  191,   98,   99,  124,  125,  126,  173,   97,
   95,  196,   96,   25,   98,   99,   93,   28,   94,  182,
   97,   95,   32,   96,  161,   98,  202,   93,   49,   94,
   49,   49,   49,   66,   32,   52,   78,   53,   93,   50,
   94,   50,   50,   50,  197,   49,   49,   49,  147,   49,
    1,    2,    3,    4,    5,    6,   50,   50,   50,   99,
   50,   29,  158,  129,   97,   95,   99,   96,  110,   98,
  111,   97,   95,   99,   96,  208,   98,   44,   97,   95,
   55,   96,   93,   98,   94,   46,   47,   56,  180,   93,
  104,   94,   54,  103,   99,  200,   93,   59,   94,   97,
   95,   63,   96,  183,   98,   60,  150,   70,   60,  149,
   78,   78,   78,  159,   73,  206,  103,   93,   61,   94,
   99,   61,   60,   60,   60,   97,   60,   75,   57,  184,
   98,   57,  103,   74,   76,   61,   61,   61,   56,   61,
   86,   56,   83,   86,   77,   57,   57,   57,   87,   57,
  127,   87,  128,  115,  100,   56,   56,   56,   99,   56,
  166,  102,  167,   97,   95,   99,   96,  105,   98,  114,
   97,   95,   99,   96,  188,   98,  189,   97,   95,   99,
   96,   93,   98,   94,   97,   95,  117,   96,   93,   98,
   94,   58,  118,   59,   58,   93,   59,   94,   66,   66,
   66,   66,   66,   66,  121,   30,   66,   66,   58,   58,
   59,   59,   62,  160,  122,   62,   64,   30,   52,  148,
   53,  172,   87,   88,   89,   90,   91,   92,  157,   62,
   62,  112,  151,   87,   88,   89,   90,   91,   92,  152,
  164,   26,  113,  185,   87,   88,   89,   90,   91,   92,
   45,  165,  204,   49,   49,   49,   49,   49,   49,  176,
   63,   49,   49,   63,   50,   50,   50,   50,   50,   50,
  177,  181,   50,   50,  186,  195,  187,   63,   63,  190,
    1,    2,    3,    4,    5,    6,  198,    7,   87,   88,
   89,   90,   91,   92,  199,   87,   88,   89,   90,   91,
   92,  207,   87,   88,   89,   90,   91,   92,   14,   17,
   52,   16,   53,    1,    2,    3,    4,    5,    6,   76,
   15,   19,   75,   87,   88,   89,   90,   91,   92,   20,
   60,   60,   60,   60,   60,   60,   78,   79,   60,   60,
   80,   81,   22,   61,   61,   61,   61,   61,   61,   23,
  146,   61,   61,   57,   57,   57,   57,   57,   57,   69,
    0,   57,   57,   56,   56,   56,   56,   56,   56,    0,
   99,   56,   56,    0,    0,   97,   95,    0,   96,    0,
   98,   79,   80,   81,   82,    0,    0,   87,   88,   89,
   90,   91,   92,   93,   87,   94,   89,   90,   91,   92,
    0,    0,    0,   89,   90,   91,   92,    0,    1,    2,
    3,    4,    5,    6,    0,    0,   58,   58,   59,   59,
   58,   58,   59,   59,   58,   58,   59,   59,    0,    1,
    2,    3,    4,    5,    6,    0,   72,   62,   62,    1,
    2,    3,    4,    5,    6,   62,   62,    0,    1,    2,
    3,    4,    5,    6,   67,   68,    0,    1,    2,    3,
    4,    5,    6,   33,    7,    0,    1,    2,    3,    4,
    5,    6,    0,    7,   84,   85,   86,   34,    0,   35,
   36,   19,    0,    0,  106,  108,   63,    0,  168,  169,
    8,    0,   15,   63,   63,    0,    0,    0,  145,   23,
   23,   23,   23,   15,    0,    0,    0,  130,  131,  132,
  133,  134,  135,  136,  137,  138,  139,  140,  141,  142,
    0,   15,    0,    0,    0,    1,    2,    3,    4,    5,
    6,   33,    7,    0,  155,  156,   24,   24,   24,   24,
    0,  171,   15,    0,  145,   34,    0,   35,   36,    0,
   72,   72,    0,   10,    0,  145,    0,  143,    0,    0,
   16,    0,    0,    0,   10,    0,    0,   27,  174,  175,
  171,    0,   15,   15,   15,    0,   27,    0,    0,  171,
  145,    0,   48,    0,   60,    1,    2,    3,    4,    5,
    6,    0,    7,    0,  171,    0,  192,  193,    0,    0,
  194,   89,   90,   48,    0,   72,    0,    0,    0,    8,
   25,   25,   25,   25,    0,  201,   15,   15,   15,    0,
  203,    0,    0,    0,  205,    0,    0,   60,   26,   26,
   26,   26,    0,   48,   48,   48,    0,    1,    2,    3,
    4,    5,    6,   33,    7,    1,    2,    3,    4,    5,
    6,   33,    7,   71,    0,    0,   60,   34,    0,   35,
   36,    0,    0,    0,  178,   34,    0,   35,   36,    0,
    0,    0,    0,   60,    0,    0,    0,   48,   48,   48,
    1,    2,    3,    4,    5,    6,   33,    7,    1,    2,
    3,    4,    5,    6,   33,    7,    0,    0,    0,  179,
   34,    0,   35,   36,    0,    0,    0,  209,   34,    0,
   35,   36,    1,    2,    3,    4,    5,    6,   33,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   34,    0,   35,   36,
};
static const YYINT yycheck[] = {                         37,
   91,   40,   44,   41,   42,   43,   44,   45,   74,   47,
  112,  113,   40,   40,  263,  263,    0,   59,   33,   59,
   58,   59,   60,   37,   62,   40,   41,   11,   42,   43,
   45,   45,  173,   47,   37,   80,   81,   82,  147,   42,
   43,  182,   45,   59,   47,   37,   60,  263,   62,  158,
   42,   43,   91,   45,  120,   47,  197,   60,   41,   62,
   43,   44,   45,   91,   91,  263,   50,  265,   60,   41,
   62,   43,   44,   45,  183,   58,   59,   60,  104,   62,
  257,  258,  259,  260,  261,  262,   58,   59,   60,   37,
   62,  282,  118,   41,   42,   43,   37,   45,  263,   47,
  265,   42,   43,   37,   45,  207,   47,   59,   42,   43,
   33,   45,   60,   47,   62,  263,  274,   40,   59,   60,
   41,   62,   45,   44,   37,   59,   60,   41,   62,   42,
   43,  265,   45,  159,   47,   41,   41,  263,   44,   44,
  124,  125,  126,   41,   59,   58,   44,   60,   41,   62,
   37,   44,   58,   59,   60,   42,   62,  265,   41,   41,
   47,   44,   44,   40,  263,   58,   59,   60,   41,   62,
   41,   44,   91,   44,   59,   58,   59,   60,   41,   62,
  263,   44,  265,  274,  287,   58,   59,   60,   37,   62,
  263,  263,  265,   42,   43,   37,   45,   93,   47,  274,
   42,   43,   37,   45,  263,   47,  265,   42,   43,   37,
   45,   60,   47,   62,   42,   43,   59,   45,   60,   47,
   62,   41,   41,   41,   44,   60,   44,   62,  266,  267,
  268,  269,  270,  271,   59,  274,  274,  275,   58,   59,
   58,   59,   41,   41,  263,   44,  274,  274,  263,  274,
  265,   59,  266,  267,  268,  269,  270,  271,  265,   58,
   59,  275,   93,  266,  267,  268,  269,  270,  271,   93,
   93,   59,  275,  263,  266,  267,  268,  269,  270,  271,
   59,   93,  274,  266,  267,  268,  269,  270,  271,  274,
   41,  274,  275,   44,  266,  267,  268,  269,  270,  271,
  274,   93,  274,  275,   59,  274,   59,   58,   59,   59,
  257,  258,  259,  260,  261,  262,   59,  264,  266,  267,
  268,  269,  270,  271,   59,  266,  267,  268,  269,  270,
  271,  275,  266,  267,  268,  269,  270,  271,   59,   59,
  263,   59,  265,  257,  258,  259,  260,  261,  262,   59,
   59,   59,   59,  266,  267,  268,  269,  270,  271,   59,
  266,  267,  268,  269,  270,  271,   59,   59,  274,  275,
   59,   59,   11,  266,  267,  268,  269,  270,  271,   11,
  103,  274,  275,  266,  267,  268,  269,  270,  271,   36,
   -1,  274,  275,  266,  267,  268,  269,  270,  271,   -1,
   37,  274,  275,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,  283,  284,  285,  286,   -1,   -1,  266,  267,  268,
  269,  270,  271,   60,  266,   62,  268,  269,  270,  271,
   -1,   -1,   -1,  268,  269,  270,  271,   -1,  257,  258,
  259,  260,  261,  262,   -1,   -1,  266,  267,  266,  267,
  270,  271,  270,  271,  274,  275,  274,  275,   -1,  257,
  258,  259,  260,  261,  262,   -1,   39,  266,  267,  257,
  258,  259,  260,  261,  262,  274,  275,   -1,  257,  258,
  259,  260,  261,  262,   34,   35,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,   -1,  257,  258,  259,  260,
  261,  262,   -1,  264,   54,   55,   56,  277,   -1,  279,
  280,  272,   -1,   -1,   64,   65,  267,   -1,  288,  289,
  281,   -1,    0,  274,  275,   -1,   -1,   -1,  101,  283,
  284,  285,  286,   11,   -1,   -1,   -1,   87,   88,   89,
   90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
   -1,   29,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,  263,  264,   -1,  114,  115,  283,  284,  285,  286,
   -1,  144,   50,   -1,  147,  277,   -1,  279,  280,   -1,
  153,  154,   -1,    0,   -1,  158,   -1,  289,   -1,   -1,
    7,   -1,   -1,   -1,   11,   -1,   -1,   14,  148,  149,
  173,   -1,   80,   81,   82,   -1,   23,   -1,   -1,  182,
  183,   -1,   29,   -1,   31,  257,  258,  259,  260,  261,
  262,   -1,  264,   -1,  197,   -1,  176,  177,   -1,   -1,
  180,  268,  269,   50,   -1,  208,   -1,   -1,   -1,  281,
  283,  284,  285,  286,   -1,  195,  124,  125,  126,   -1,
  200,   -1,   -1,   -1,  204,   -1,   -1,   74,  283,  284,
  285,  286,   -1,   80,   81,   82,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  257,  258,  259,  260,  261,
  262,  263,  264,  273,   -1,   -1,  103,  277,   -1,  279,
  280,   -1,   -1,   -1,  276,  277,   -1,  279,  280,   -1,
   -1,   -1,   -1,  120,   -1,   -1,   -1,  124,  125,  126,
  257,  258,  259,  260,  261,  262,  263,  264,  257,  258,
  259,  260,  261,  262,  263,  264,   -1,   -1,   -1,  276,
  277,   -1,  279,  280,   -1,   -1,   -1,  276,  277,   -1,
  279,  280,  257,  258,  259,  260,  261,  262,  263,  264,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  277,   -1,  279,  280,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 317
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
0,0,0,0,0,0,0,0,"illegal-symbol",
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
"expr : operand",
"operand : ID",
"operand : NR",
"operand : ID '[' NR ']'",
"operand : ID '[' ID ']'",
"if_stmt : IF expr BEGINSTMT list ENDSTMT",
"while_stmt : WHILE expr BEGINSTMT list ENDSTMT",
"for_stmt : FOR operand ASSIGN expr ';' expr ';' expr ASSIGN expr ':' BEGINSTMT list ENDSTMT",
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
#line 228 "limbaj.y"
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
#line 768 "y.tab.c"

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
case 73:
#line 208 "limbaj.y"
	{ ResetCallStack(); }
break;
case 74:
#line 209 "limbaj.y"
	{ ResetCallStack(); }
break;
case 76:
#line 211 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); pushEmptyVariable(yystack.l_mark[0].string, yystack.l_mark[-1].type_id, "false", 0);}
break;
case 77:
#line 212 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "false", 0);}
break;
case 78:
#line 213 "limbaj.y"
	{ CheckArrayRange(yystack.l_mark[-3].string, yystack.l_mark[-1].intval); }
break;
case 80:
#line 215 "limbaj.y"
	{ CheckArrayRange(yystack.l_mark[-5].string, yystack.l_mark[-3].intval); }
break;
case 81:
#line 216 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-6].type_id); pushEmptyVariable(yystack.l_mark[-5].string, yystack.l_mark[-6].type_id, "false", yystack.l_mark[-3].intval);}
break;
#line 1079 "y.tab.c"
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
