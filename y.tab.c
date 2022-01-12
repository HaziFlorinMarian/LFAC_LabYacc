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

 int func_count = 0;
 int current_scope = 0;
 int max_scope = 0;

struct dataType {
     char* id;
     char* data_type;
     int line_no;
     char* is_constant;
     int arrsize;
};

struct Nodes {
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
} func_table[100];

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 41 "limbaj.y"
typedef union {
	char var_name[256];
	char* type_id;
     int intval;
     char* string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 73 "y.tab.c"

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
    2,    4,    5,   10,   10,    7,    7,    7,    7,    7,
    7,   12,   12,   12,   15,   15,   16,   16,   16,   16,
   17,   17,   18,   19,   13,   20,   20,   21,   21,   23,
    8,   24,   25,   26,    6,   27,    6,   28,    6,   29,
    6,   22,   22,   14,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,   31,   31,   31,   32,   33,   34,   35,   36,
   30,   30,   30,   30,   30,   30,   30,   30,   30,   30,
   11,   11,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    1,    4,    1,
    1,    1,    4,    4,    3,    2,    3,    2,    2,    3,
    2,    2,    4,    1,    2,    3,    1,    3,    3,    3,
    1,    3,    0,    0,    9,    1,    3,    2,    4,    0,
    4,    1,    1,    0,    9,    0,    8,    0,   10,    0,
    9,    2,    3,    5,    3,    3,    3,    3,    3,    3,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    5,    5,   14,
    2,    3,    4,    1,    1,    1,    1,    1,    2,    1,
    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,   24,    0,    0,    0,    0,    0,
   21,    0,   40,    0,    7,    0,   18,   16,   19,   33,
    0,    0,    0,    0,    0,    0,   20,   17,    0,    0,
    0,    0,    0,   75,    0,    0,    0,    0,   74,    0,
   71,   72,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   11,   90,   84,    0,    0,   85,   86,   87,    0,
    0,    0,    0,    0,    0,    0,   36,    0,    0,   61,
   70,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    9,    0,    0,    0,
    0,    0,   10,    0,   12,    0,    0,   41,    0,   52,
   25,    0,   34,    0,    0,    0,    0,    0,    0,   42,
    0,    0,   60,   15,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   57,   58,   59,    0,
    0,   76,    0,    0,    0,    0,    0,   53,   26,    0,
    0,    0,    0,    0,   37,    0,    0,   13,    0,   14,
    0,    0,    0,    0,    0,    0,   31,    0,   39,    0,
   43,   47,    0,    0,    0,   77,   78,   79,    0,    0,
   35,   45,    0,   51,    0,   32,   49,    0,    0,    0,
    0,    0,    0,    0,   80,
};
static const YYINT yydgoto[] = {                          9,
   59,   60,   19,   48,   49,   11,   12,   25,   50,   51,
  126,   71,   14,   64,   72,   73,  168,   39,  150,   76,
   77,   65,   36,  121,  172,   41,   42,   98,   99,   66,
   52,  143,  177,   67,   68,   69,
};
static const YYINT yysindex[] = {                       256,
    0,    0,    0,    0,    0,    0, -243,   43,    0, -237,
   17,  620,  -32,  -18,    0, -239, -213,   19, -218,  -28,
    0, -198,    0,   85,    0,   12,    0,    0,    0,    0,
 -201,    0,   34, -191,   42,  587,    0,    0,  113,   34,
   43,   52,    4,    0,   34,   34,   34,   59,    0,  178,
    0,    0,   26,    0,   34,   34, -129,   34, -127, -134,
   59,    0,    0,    0,  507,   82,    0,    0,    0, -127,
   88,  113, -246,  178, -127,  -27,    0, -125,   34,    0,
    0,   55,   68,   34,   34,   34,   34,   34,   34,   34,
   34,   34,   34,   34,   34,   34,    0,   43,  110,   15,
   15, -116,    0,  178,    0, -114,   34,    0,  106,    0,
    0,  107,    0,  113,  113,  113,   73,   43, -125,    0,
  587,   69,    0,    0,  178,  -26,  226,  204,  535,  535,
  417,  417,  535,  535,  160,  160,    0,    0,    0,   10,
 -125,    0,  587,  587,   34,   34,  178,    0,    0,  -95,
  113,  113,  113,   77,    0,  587,  540,    0,   34,    0,
 -125,  587,  580,  580,   83,  178,    0,  -43,    0,  540,
    0,    0,  178,  587,  540,    0,    0,    0,   34,  -89,
    0,    0,  540,    0,   90,    0,    0, -129,  -97,   34,
  111,  -94,  587,  580,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -47,  124,  -57,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  105,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -37,    0,    0,    0,    0,  -13,    0,  125,
    0,    0,    0,  246,    0,    0,    0,  135,    0,    0,
  -77,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -161,    0,  139,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  146,    0,  147,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   20,    0,    0,    0,
    0,    0,    0,    0,   37,    0,  394,  398,  119,  131,
  382,  392,  141,  151,   25,   45,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  149,    0,    0,    0,
   44,  145,  183,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  158,    0,    0,    0,    0,
    0,    0,   50,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  527,  -48,  159,  427,  367,  192,    0,    0,  646,  533,
    0,  155,  202,  567,   72,    0,    0,    0,    0,  121,
  104,  400,    0, -108, -135,    0,    0,    0,    0,  588,
    0,  -82, -151,    0,    0,    0,
};
#define YYTABLESIZE 909
static const YYINT yytable[] = {                         12,
  180,    8,   12,   12,   12,   12,   12,   12,  102,   12,
  156,   12,  178,  119,  160,  181,  118,  159,  144,   16,
   12,   12,   12,   73,   12,   18,   28,   73,   73,   73,
   73,   73,  162,   73,  182,  113,  114,  115,  116,  184,
   29,   30,  195,   12,   73,   73,   73,  187,   73,   31,
  161,   96,  174,  118,   33,   12,   94,   92,   32,   93,
   38,   95,   34,   38,   35,   55,   46,   55,   55,   55,
   38,   40,   53,   47,   90,   21,   91,   91,   45,   73,
   91,   54,   55,   55,   55,   56,   55,   56,   56,   56,
   92,   96,   78,   92,   79,  123,   94,   92,   83,   93,
   46,   95,   56,   56,   56,   96,   56,   47,  124,  193,
   94,   92,   45,   93,   90,   95,   91,   55,   97,   96,
   27,   27,   27,   27,   94,   92,   96,   93,   90,   95,
   91,   94,   92,   43,   93,  105,   95,   56,  107,  189,
  110,  179,   90,   37,   91,   46,  111,   96,  188,   90,
  141,   91,   94,   92,   13,   93,  145,   95,  146,   66,
  120,  158,   66,  154,  148,  149,   26,  167,  192,  169,
   90,   67,   91,  186,   67,  190,   66,   66,   66,  142,
   66,   63,   22,   23,   63,  151,  152,  153,   67,   67,
   67,   62,   67,   88,   62,   10,   96,   54,   63,   63,
   63,   94,   63,   24,   89,   81,   95,   82,   62,   62,
   62,   66,   62,   27,   96,    8,   83,  106,  140,   94,
   92,  155,   93,   67,   95,   12,  112,   12,   12,   12,
   12,   12,   12,   63,    0,   12,   12,   90,    0,   91,
   96,    0,    0,   62,    0,   94,   92,    0,   93,    0,
   95,   73,   73,   73,   73,   73,   73,    0,    0,    0,
   73,    0,   96,   90,    0,   91,    0,   94,   92,    0,
   93,    0,   95,    1,    2,    3,    4,    5,    6,   84,
   85,   86,   87,   88,   89,   90,   50,   91,  142,   55,
   55,   55,   55,   55,   55,    0,   43,   44,   55,    1,
    2,    3,    4,    5,    6,  112,  112,  112,    0,   56,
   56,   56,   56,   56,   56,    0,    0,    0,   56,   84,
   85,   86,   87,   88,   89,   28,   28,   28,   28,    0,
   43,   44,    0,   84,   85,   86,   87,   88,   89,    0,
    0,    1,    2,    3,    4,    5,    6,   84,   85,   86,
   87,   88,   89,    0,   84,   85,   86,   87,   88,   89,
    0,   44,   44,   44,   44,   44,   44,    0,    0,    1,
    2,    3,    4,    5,    6,   84,   85,   86,   87,   88,
   89,    0,    0,   66,   66,   66,   66,   66,   66,    0,
    0,    0,   66,    0,    0,   67,   67,   67,   67,   67,
   67,    8,   62,    0,   67,   63,   63,   63,   63,   63,
   63,    0,    0,    0,   63,   62,   62,   62,   62,   62,
   62,    0,   64,   62,   62,   64,   29,   29,   29,   29,
    0,   62,   65,    0,   68,   65,   20,   68,   69,   64,
   64,   69,   84,   85,   86,   87,   88,   89,    0,   65,
   65,   68,   68,   96,    0,   69,   69,    0,   94,   92,
    0,   93,   61,   95,   30,   30,   30,   30,   84,    0,
   86,   87,   88,   89,   64,    0,   90,    0,   91,    0,
    0,    0,    0,  103,   65,   20,   68,   62,    0,    0,
   69,   61,   86,   87,   88,   89,   20,    0,    0,    0,
    0,  117,   48,   48,   48,   48,   48,   48,    0,   62,
   62,    0,    1,    2,    3,    4,    5,    6,    0,    0,
  157,    0,   62,   62,    0,    0,   10,    0,   62,   62,
   62,    0,    0,    0,   17,    7,   62,   22,   10,    0,
   62,   62,  163,  164,    8,    0,    0,   61,    0,   62,
   22,    0,    0,    0,   62,  170,    0,    0,    0,   62,
   62,  175,    0,    0,    0,   70,   15,   75,   63,   61,
   61,   96,    0,  183,    0,    0,   94,   92,   15,   93,
    0,   95,   61,   61,    0,    0,    0,    0,   61,   61,
   61,    0,  194,    0,    0,    0,   61,   63,   70,    0,
   61,   61,    0,    0,    0,   15,    0,    0,    0,   61,
    0,    0,    0,    0,  103,    0,    0,    0,    0,   61,
   61,    0,    0,    0,   75,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   15,    0,
   70,   70,   70,    0,   75,    0,   64,   64,    0,    0,
   64,   64,  109,   63,    0,   64,   65,   65,   68,   68,
   65,   65,    0,   69,    0,   65,    0,   68,    0,    0,
    0,   69,    0,    0,    0,   63,   63,   70,   70,   70,
   15,   15,   15,   86,   87,   74,    0,    0,   63,   63,
   80,   81,   82,    0,   63,   63,   63,    0,    0,    0,
  100,  101,   63,  104,    0,    0,   63,   63,    0,    0,
    0,    0,    0,    0,    0,   63,    0,   15,   15,   15,
    0,    0,    0,    0,  122,   63,   63,    0,  125,  127,
  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,
  138,  139,    0,    0,  109,    0,    0,    0,    0,    0,
  109,  109,  147,    0,    0,    0,    0,  109,    0,    0,
    0,    0,  109,    1,    2,    3,    4,    5,    6,   43,
  109,    0,    0,    0,    0,    0,    0,    0,  108,    0,
    0,  109,   55,    0,   56,   57,    0,    0,    0,    0,
  165,  166,    0,    0,   58,    8,    1,    2,    3,    4,
    5,    6,   43,    0,  173,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   55,    0,   56,   57,    0,
    0,    0,    0,    0,  185,    0,  171,   58,    8,    0,
    0,    0,    0,    0,    0,  191,    1,    2,    3,    4,
    5,    6,   43,    1,    2,    3,    4,    5,    6,   43,
    0,    0,    0,    0,  176,   55,    0,   56,   57,    0,
    0,    0,   55,    0,   56,   57,    0,   58,    8,    0,
    0,    0,    0,    0,   58,    8,    1,    2,    3,    4,
    5,    6,    0,    0,    0,    0,    0,    0,    0,    0,
   23,    0,    0,    0,    0,    0,    0,    0,    0,    7,
    0,    0,    0,    0,    0,    0,    0,    0,    8,
};
static const YYINT yycheck[] = {                         37,
   44,   59,   40,   41,   42,   43,   44,   45,   57,   47,
  119,   59,  164,   41,   41,   59,   44,   44,  101,  263,
   58,   59,   60,   37,   62,  263,   59,   41,   42,   43,
   44,   45,  141,   47,  170,  282,  283,  284,  285,  175,
   59,  281,  194,   91,   58,   59,   60,  183,   62,  263,
   41,   37,  161,   44,  273,   93,   42,   43,   40,   45,
   41,   47,   91,   44,  263,   41,   33,   43,   44,   45,
   59,  273,  264,   40,   60,   59,   62,   41,   45,   93,
   44,   40,   58,   59,   60,   41,   62,   43,   44,   45,
   41,   37,   41,   44,   91,   41,   42,   43,   40,   45,
   33,   47,   58,   59,   60,   37,   62,   40,   41,  192,
   42,   43,   45,   45,   60,   47,   62,   93,   93,   37,
  282,  283,  284,  285,   42,   43,   37,   45,   60,   47,
   62,   42,   43,  263,   45,  263,   47,   93,  273,  188,
   59,   59,   60,   59,   62,   41,   59,   37,   59,   60,
   41,   62,   42,   43,    0,   45,  273,   47,  273,   41,
  286,   93,   44,   91,   59,   59,   12,  263,   58,   93,
   60,   41,   62,  263,   44,  273,   58,   59,   60,  274,
   62,   41,   59,   59,   44,  114,  115,  116,   58,   59,
   60,   41,   62,   59,   44,  273,   37,   59,   58,   59,
   60,   42,   62,   12,   59,   59,   47,   59,   58,   59,
   60,   93,   62,   12,   37,  273,   59,   59,   98,   42,
   43,  118,   45,   93,   47,  273,   72,  265,  266,  267,
  268,  269,  270,   93,   -1,  273,  274,   60,   -1,   62,
   37,   -1,   -1,   93,   -1,   42,   43,   -1,   45,   -1,
   47,  265,  266,  267,  268,  269,  270,   -1,   -1,   -1,
  274,   -1,   37,   60,   -1,   62,   -1,   42,   43,   -1,
   45,   -1,   47,  257,  258,  259,  260,  261,  262,  265,
  266,  267,  268,  269,  270,   60,   41,   62,  274,  265,
  266,  267,  268,  269,  270,   -1,  263,  264,  274,  257,
  258,  259,  260,  261,  262,  151,  152,  153,   -1,  265,
  266,  267,  268,  269,  270,   -1,   -1,   -1,  274,  265,
  266,  267,  268,  269,  270,  282,  283,  284,  285,   -1,
  263,  264,   -1,  265,  266,  267,  268,  269,  270,   -1,
   -1,  257,  258,  259,  260,  261,  262,  265,  266,  267,
  268,  269,  270,   -1,  265,  266,  267,  268,  269,  270,
   -1,  257,  258,  259,  260,  261,  262,   -1,   -1,  257,
  258,  259,  260,  261,  262,  265,  266,  267,  268,  269,
  270,   -1,   -1,  265,  266,  267,  268,  269,  270,   -1,
   -1,   -1,  274,   -1,   -1,  265,  266,  267,  268,  269,
  270,  289,   36,   -1,  274,  265,  266,  267,  268,  269,
  270,   -1,   -1,   -1,  274,  265,  266,  267,  268,  269,
  270,   -1,   41,   57,  274,   44,  282,  283,  284,  285,
   -1,   65,   41,   -1,   41,   44,   10,   44,   41,   58,
   59,   44,  265,  266,  267,  268,  269,  270,   -1,   58,
   59,   58,   59,   37,   -1,   58,   59,   -1,   42,   43,
   -1,   45,   36,   47,  282,  283,  284,  285,  265,   -1,
  267,  268,  269,  270,   93,   -1,   60,   -1,   62,   -1,
   -1,   -1,   -1,   57,   93,   59,   93,  121,   -1,   -1,
   93,   65,  267,  268,  269,  270,   70,   -1,   -1,   -1,
   -1,   75,  257,  258,  259,  260,  261,  262,   -1,  143,
  144,   -1,  257,  258,  259,  260,  261,  262,   -1,   -1,
  121,   -1,  156,  157,   -1,   -1,    0,   -1,  162,  163,
  164,   -1,   -1,   -1,    8,  280,  170,   11,   12,   -1,
  174,  175,  143,  144,  289,   -1,   -1,  121,   -1,  183,
   24,   -1,   -1,   -1,  188,  156,   -1,   -1,   -1,  193,
  194,  162,   -1,   -1,   -1,   39,    0,   41,   36,  143,
  144,   37,   -1,  174,   -1,   -1,   42,   43,   12,   45,
   -1,   47,  156,  157,   -1,   -1,   -1,   -1,  162,  163,
  164,   -1,  193,   -1,   -1,   -1,  170,   65,   72,   -1,
  174,  175,   -1,   -1,   -1,   39,   -1,   -1,   -1,  183,
   -1,   -1,   -1,   -1,  188,   -1,   -1,   -1,   -1,  193,
  194,   -1,   -1,   -1,   98,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   72,   -1,
  114,  115,  116,   -1,  118,   -1,  265,  266,   -1,   -1,
  269,  270,   65,  121,   -1,  274,  265,  266,  265,  266,
  269,  270,   -1,  266,   -1,  274,   -1,  274,   -1,   -1,
   -1,  274,   -1,   -1,   -1,  143,  144,  151,  152,  153,
  114,  115,  116,  267,  268,   40,   -1,   -1,  156,  157,
   45,   46,   47,   -1,  162,  163,  164,   -1,   -1,   -1,
   55,   56,  170,   58,   -1,   -1,  174,  175,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  183,   -1,  151,  152,  153,
   -1,   -1,   -1,   -1,   79,  193,  194,   -1,   83,   84,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   -1,   -1,  157,   -1,   -1,   -1,   -1,   -1,
  163,  164,  107,   -1,   -1,   -1,   -1,  170,   -1,   -1,
   -1,   -1,  175,  257,  258,  259,  260,  261,  262,  263,
  183,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,
   -1,  194,  276,   -1,  278,  279,   -1,   -1,   -1,   -1,
  145,  146,   -1,   -1,  288,  289,  257,  258,  259,  260,
  261,  262,  263,   -1,  159,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  276,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,  179,   -1,  287,  288,  289,   -1,
   -1,   -1,   -1,   -1,   -1,  190,  257,  258,  259,  260,
  261,  262,  263,  257,  258,  259,  260,  261,  262,  263,
   -1,   -1,   -1,   -1,  275,  276,   -1,  278,  279,   -1,
   -1,   -1,  276,   -1,  278,  279,   -1,  288,  289,   -1,
   -1,   -1,   -1,   -1,  288,  289,  257,  258,  259,  260,
  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  280,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  289,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 330
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"$$1 :",
"$$2 :",
"initializare_clasa : CLASS ID BEGINCLASS $$1 bloc_clasa ENDCLASS $$2 lista_id_clasa ';'",
"lista_param : param",
"lista_param : lista_param ',' param",
"param : DATA_TYPE identifier",
"param : DATA_TYPE identifier '[' ']'",
"$$3 :",
"bloc : BGIN $$3 list END",
"enter_func : BEGINFNCTN",
"leave_func : ENDFNCTN",
"$$4 :",
"descriere_functii : DATA_TYPE ID '(' $$4 lista_param ')' enter_func list leave_func",
"$$5 :",
"descriere_functii : DATA_TYPE ID '(' $$5 ')' enter_func list leave_func",
"$$6 :",
"descriere_functii : descriere_functii DATA_TYPE ID '(' $$6 lista_param ')' enter_func list leave_func",
"$$7 :",
"descriere_functii : descriere_functii DATA_TYPE ID '(' $$7 ')' enter_func list leave_func",
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
"begin_statement : BEGINSTMT",
"end_statement : ENDSTMT",
"if_stmt : IF expr begin_statement list end_statement",
"while_stmt : WHILE expr begin_statement list end_statement",
"for_stmt : FOR lhs ASSIGN expr ';' expr ';' lhs ASSIGN expr ':' begin_statement list end_statement",
"statement : DATA_TYPE declare_lhs",
"statement : lhs ASSIGN expr",
"statement : DATA_TYPE declare_lhs ASSIGN expr",
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
#line 234 "limbaj.y"
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

	for(int i=0; i < func_count; i++) {
		printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n", func_table[i].Name, func_table[i].Scope, func_table[i].Return, func_table[i].ParamNumber, func_table[i].line_no);
	     printf("PARAM_TYPE\t");

          for (int j = 0; j <  func_table[i].ParamNumber; ++j)
               printf("%s\t", func_table[i].ParamType[j]);

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
          printf("Internal error!\n");
          exit(0);
     }

     S[current_scope].var_table[i].data_type = strdup(type);
}

void PrintErrorAndExit(int x)
{
     switch(x)
     {
          case 1:
               printf("Cannot have  VOID data type for variables.\n");
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
     {
		PrintErrorAndExit(5);
	}

     func_table[func_count].Name = strdup(name);
     func_table[func_count].Return = strdup(ret_type);
     func_table[func_count].line_no = yylineno;

	func_count++;
}

void PushParameters(char* type)
{
     int *j = &func_table[func_count].ParamNumber;

     func_table[func_count].ParamType[*j] = strdup(type);

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

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
PrintVar();
PrintFunc();
}
#line 823 "y.tab.c"

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
#line 72 "limbaj.y"
	{yyval.type_id = strdup("Integer");   }
break;
case 2:
#line 73 "limbaj.y"
	{yyval.type_id = strdup("Float");   }
break;
case 3:
#line 74 "limbaj.y"
	{yyval.type_id = strdup("Character");  }
break;
case 4:
#line 75 "limbaj.y"
	{yyval.type_id = strdup("Bool");   }
break;
case 5:
#line 76 "limbaj.y"
	{yyval.type_id = strdup("String");   }
break;
case 6:
#line 77 "limbaj.y"
	{yyval.type_id = strdup("Void");   }
break;
case 7:
#line 80 "limbaj.y"
	{printf("program corect sintactic\n");}
break;
case 8:
#line 83 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].string); AddNewVariable(yystack.l_mark[0].string);       }
break;
case 9:
#line 84 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[-3].string); AddArraySize(yystack.l_mark[-3].string, yystack.l_mark[-1].intval);     }
break;
case 10:
#line 87 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].string); }
break;
case 11:
#line 88 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].string); }
break;
case 12:
#line 91 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[0].var_name); }
break;
case 13:
#line 94 "limbaj.y"
	{ yyval.string = strdup(yystack.l_mark[-3].var_name); }
break;
case 22:
#line 110 "limbaj.y"
	{ AddDataType(yystack.l_mark[0].string, yystack.l_mark[-1].type_id); }
break;
case 23:
#line 111 "limbaj.y"
	{ AddDataType(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id); }
break;
case 33:
#line 131 "limbaj.y"
	{ NewScope(); }
break;
case 34:
#line 131 "limbaj.y"
	{ { ExitScope(); } }
break;
case 38:
#line 138 "limbaj.y"
	{ PushParameters(yystack.l_mark[-1].type_id); AddParamToVarList(yystack.l_mark[0].string, yystack.l_mark[-1].type_id); }
break;
case 39:
#line 139 "limbaj.y"
	{ PushParameters(yystack.l_mark[-3].type_id); AddParamToVarList(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id); }
break;
case 40:
#line 143 "limbaj.y"
	{ NewScope(); }
break;
case 41:
#line 143 "limbaj.y"
	{ NewScope(); }
break;
case 44:
#line 154 "limbaj.y"
	{ NewScope(); }
break;
case 45:
#line 154 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-7].var_name, yystack.l_mark[-8].type_id); }
break;
case 46:
#line 155 "limbaj.y"
	{ NewScope(); }
break;
case 47:
#line 155 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-6].var_name, yystack.l_mark[-7].type_id); }
break;
case 48:
#line 156 "limbaj.y"
	{ NewScope(); }
break;
case 49:
#line 156 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-8].type_id, yystack.l_mark[-9].string); }
break;
case 50:
#line 157 "limbaj.y"
	{ NewScope(); }
break;
case 51:
#line 157 "limbaj.y"
	{ ExitScope(); PushFunction(yystack.l_mark[-7].type_id, yystack.l_mark[-8].string); }
break;
case 54:
#line 167 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); AddConstantVariable(yystack.l_mark[-2].var_name, yystack.l_mark[-3].type_id, "true", 0); }
break;
case 76:
#line 198 "limbaj.y"
	{ NewScope(); }
break;
case 77:
#line 201 "limbaj.y"
	{ ExitScope(); }
break;
case 81:
#line 217 "limbaj.y"
	{ AddDataType(yystack.l_mark[0].string, yystack.l_mark[-1].type_id); }
break;
case 83:
#line 219 "limbaj.y"
	{ AddDataType(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id); }
break;
#line 1158 "y.tab.c"
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
