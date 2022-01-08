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
   11,   11,   11,   11,   11,   15,   15,   16,   16,   16,
   16,   17,   17,   12,   10,   10,   18,   18,    3,   20,
   21,   13,   13,   13,   13,   22,   22,   22,   22,   22,
   22,   19,   19,   14,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,   24,   24,   24,   25,   26,   27,   23,   23,
   23,   23,   23,   23,   23,   23,   28,   28,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    1,    1,    1,
    4,    1,    4,    3,    2,    3,    2,    2,    3,    2,
    5,    4,    2,    4,    1,    2,    3,    1,    3,    3,
    3,    1,    3,    7,    1,    3,    2,    4,    3,    1,
    1,    8,    7,    9,    8,    3,    4,    2,    3,    4,
    3,    2,    3,    5,    3,    3,    3,    3,    3,    3,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    1,    1,    1,    1,    1,    5,    5,   14,    2,    3,
    4,    1,    1,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,   25,    0,    0,    0,    0,    8,
    9,    0,    7,    0,   17,    0,   15,   18,   20,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   86,   82,    0,    0,   83,   84,   85,   16,
   19,    0,    0,    0,    0,    0,    0,   75,    0,    0,
    0,    0,   74,    0,    0,   71,   72,    0,    0,    0,
   35,    0,    0,    0,    0,    0,    0,    0,   39,    0,
   52,    0,    0,    0,   26,    0,    0,    0,    0,    0,
   61,   70,    0,   11,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   40,    0,   10,
    0,    0,    0,    0,    0,    0,    0,    0,   14,    0,
   53,    0,    0,    0,   27,   32,    0,    0,    0,    0,
   60,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   57,   58,   59,    0,    0,    0,    0,   36,    0,
    0,    0,    0,    0,   13,    0,    0,   22,    0,    0,
   34,    0,    0,   41,    0,   43,    0,   48,   38,    0,
   76,   77,    0,    0,    0,   21,   33,   49,   51,    0,
    0,   46,   42,    0,   45,    0,   47,   50,    0,   44,
    0,    0,    0,    0,    0,    0,   78,
};
static const YYINT yydgoto[] = {                          9,
   40,   11,   23,   41,   62,   63,   64,   65,   66,   70,
   55,   13,   14,   44,   56,   57,  127,   71,   45,  109,
  166,  146,   46,   67,   47,   48,   49,    0,
};
static const YYINT yysindex[] = {                       463,
    0,    0,    0,    0,    0,    0,  -49, -262,    0, -254,
  519,  -40,  -39,  130,    0, -230, -238,  -27, -219,    0,
    0,  615,    0,   19,    0,  212,    0,    0,    0, -204,
 -184,  299,   -2,   75,   -2,   14,   -2,   -2, -145, -145,
 -152,   93,    0,    0,  544,   64,    0,    0,    0,    0,
    0,  100,   -2, -108,  101,  299, -148,    0,   -2,   -2,
   -2,   93,    0,   71,  128,    0,    0, -110,  -85,    7,
    0,  128,   15,   26,  -95,  -89,   -2,   98,    0,  127,
    0,  106,  128,  -24,    0,  132,  -67,  299,  299,  299,
    0,    0,   72,    0,   -2,   -2,   -2,   -2,   -2,   -2,
   -2,   -2,   -2,   -2,   -2,   -2,   -2,    0,  420,    0,
  108,  -49, -110,  615,  615,   -2,   -2,  128,    0,   41,
    0, -110,   43,  143,    0,    0,  -32,  299,  299,  299,
    0,  284,  227,  471,  471,  421,  421,  471,  471,  116,
  116,    0,    0,    0, -191,  509,  133,  105,    0,  420,
  575,  583,   83,  128,    0,  420, -110,    0,   58,  -60,
    0,  146,  147,    0, -136,    0,  160,    0,    0,  509,
    0,    0,   -2,  509,  420,    0,    0,    0,    0,  168,
  180,    0,    0,  107,    0,  509,    0,    0, -145,    0,
   -1,   -2,  114,  -33,  615,  607,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -57,  192,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -37,    0,    0,    0,    0,
    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   86,    0,    0,    0,    0,
    0,  -13,    0,    0,  186,    0,    0,  229,    0,    0,
    0,  232,    0,    0,    0,  239,    0,    0,    0,    0,
    0,    0,  240,  -57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   60,    0,  241,    0,    0,    0,    0,  244,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  135,  159,  176,
    0,  219,   53,  -23,  142,  182,  209,  156,  166,   38,
   48,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   64,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  515,    0,    0,  226,  467,  480,    0,  658,  556,  -71,
   65,  300,  311,   92,  -48,    0,    0,  198, -100,  -96,
 -120,   12,  394,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 895
static const YYINT yytable[] = {                         10,
   17,   10,   10,   10,   10,   10,  120,   10,   18,   10,
  123,  160,   34,  151,  152,  124,  150,   66,   27,   28,
   10,   10,   10,   73,   10,  156,  161,   73,   73,   73,
   60,   73,   31,   73,   66,   66,   66,   61,   66,  128,
  129,  130,   59,   32,   73,   73,   73,  113,   73,  183,
  112,  107,  159,  185,   35,   10,  105,  103,   52,  104,
  175,  106,  107,   33,   12,  190,   33,  105,  103,   66,
  104,  162,  106,  163,  101,   24,  102,   50,   55,   73,
   55,  155,   55,  157,  112,  101,  112,  102,   56,   53,
   56,   15,   56,   69,  196,   55,   55,   55,  176,   55,
   37,  112,   15,   37,   33,   56,   56,   56,  107,   56,
   69,   69,  131,  105,  103,   68,  104,   36,  106,  107,
   86,   77,   81,   15,  105,  103,  180,  104,  181,  106,
   55,  101,   78,  102,   87,   88,   89,   90,  119,   82,
   56,  173,  101,  107,  102,   69,  122,   15,  105,  103,
  107,  104,  107,  106,   84,  105,  103,  105,  104,   85,
  106,  170,  106,   94,  107,  189,  101,  174,  102,  105,
  103,  194,  104,  101,  106,  102,  108,  110,  116,   15,
   15,   15,   67,  158,  117,  121,  186,  101,   29,  102,
  125,  168,   86,   86,   86,  126,   63,  169,  148,   67,
   67,   67,  177,   67,  178,  179,   62,    1,    2,    3,
    4,    5,    6,   63,   63,   63,   10,   63,  182,   15,
   15,   15,   64,   62,   62,   62,  187,   62,   10,   10,
   10,   10,   10,   10,   67,   19,   10,   10,  188,   64,
   64,  195,   66,   66,   66,   66,   66,   66,   63,   65,
   23,   66,   73,   73,   73,   73,   73,   73,   62,   68,
   36,   73,   58,  107,   75,   76,   65,   65,  105,  103,
   51,  104,  192,  106,   64,    8,   68,   68,   12,   19,
   95,   96,   97,   98,   99,  100,  101,   22,  102,  114,
   24,   95,   96,   97,   98,   99,  100,   79,   54,   21,
  115,   65,   80,   55,   55,   55,   55,   55,   55,  149,
   25,   68,   55,   56,   56,   56,   56,   56,   56,   69,
  107,   26,   56,    0,    0,  105,  103,   69,  104,    0,
  106,    1,    2,    3,    4,    5,    6,   95,   96,   97,
   98,   99,  100,  101,    0,  102,    0,    0,   95,   96,
   97,   98,   99,  100,    1,    2,    3,    4,    5,    6,
    0,    0,    1,    2,    3,    4,    5,    6,   28,   28,
   28,   28,   95,   96,   97,   98,   99,  100,    0,   95,
   96,   97,   98,   99,  100,    0,    1,    2,    3,    4,
    5,    6,    0,   95,   96,   97,   98,   99,  100,    1,
    2,    3,    4,    5,    6,    0,    0,   67,   67,   67,
   67,   67,   67,    0,  191,    0,   67,   29,   29,   29,
   29,   63,   63,   63,   63,   63,   63,    0,    0,    0,
   63,   62,   62,   62,   62,   62,   62,    0,   80,    0,
   62,   30,   30,   30,   30,    0,    0,   64,   64,    0,
    0,   64,   64,    0,    0,    0,   64,  107,   31,   31,
   31,   31,  105,  103,    0,  104,    0,  106,    1,    2,
    3,    4,    5,    6,   65,   65,   20,    0,   65,   65,
  101,    0,  102,   65,   68,   68,    0,    0,   42,   21,
    0,    0,   95,   68,   97,   98,   99,  100,    0,    0,
    0,   21,  147,    0,    0,   20,   20,  107,    0,    0,
    0,   42,  105,  103,   10,  104,    0,  106,   21,   21,
   20,   16,    0,    0,   21,   10,    0,    0,   30,    0,
    0,    0,    0,   21,    0,  111,    0,    0,    0,  167,
   30,    0,    0,  147,   80,   80,   54,    0,   69,  147,
    0,   97,   98,   99,  100,    1,    2,    3,    4,    5,
    6,    0,    7,  167,    0,    0,    0,  167,  147,    0,
   54,    0,    0,    0,    0,   42,    0,   43,    0,  167,
   42,   42,    0,    0,    0,    0,    0,    0,   21,   80,
    0,    0,   69,   21,   21,    0,   69,    0,    0,    0,
   43,    0,   54,   54,   54,    0,    0,    0,    0,    0,
    0,    0,   42,    0,    0,    0,   42,   42,   42,    0,
    0,    0,   42,    0,    0,   21,   69,    0,    0,   21,
   21,   21,    0,    0,    0,   21,   42,    0,   69,    0,
   42,   42,   54,   54,   54,    0,    0,    0,    0,   21,
    0,    0,   42,   21,   21,   20,    0,    0,    0,    0,
    0,   42,   42,    0,   43,   21,    0,    0,   21,   43,
   43,    0,    0,    0,   21,   21,    1,    2,    3,    4,
    5,    6,   36,    7,    0,    0,    0,    0,   97,   98,
    0,    0,   72,    0,   73,   74,   37,    0,   38,   39,
    0,   43,    0,    0,    0,   43,   43,   43,  145,    0,
   83,   43,    0,    0,    0,    0,   91,   92,   93,    1,
    2,    3,    4,    5,    6,   43,    7,    0,    0,   43,
   43,    0,    0,    0,  118,    0,    0,    0,    0,    0,
    0,   43,    0,    8,    0,    0,    0,    0,    0,    0,
   43,   43,  132,  133,  134,  135,  136,  137,  138,  139,
  140,  141,  142,  143,  144,    1,    2,    3,    4,    5,
    6,   36,    7,  153,  154,    1,    2,    3,    4,    5,
    6,    0,    7,    0,    0,   37,    0,   38,   39,    0,
   22,    0,    0,    0,    0,    0,  164,  165,    0,    8,
    1,    2,    3,    4,    5,    6,   36,    7,    0,    0,
    0,    0,    0,    0,    0,    0,   79,    0,    0,    0,
   37,    0,   38,   39,    0,    0,    0,    0,    0,    0,
  184,    1,    2,    3,    4,    5,    6,   36,    7,    1,
    2,    3,    4,    5,    6,   36,    7,    0,    0,  193,
  171,   37,    0,   38,   39,    0,    0,    0,  172,   37,
    0,   38,   39,    1,    2,    3,    4,    5,    6,   36,
    7,    1,    2,    3,    4,    5,    6,   36,    7,    0,
    0,    0,  197,   37,    0,   38,   39,    0,    0,    0,
    0,   37,    0,   38,   39,
};
static const YYINT yycheck[] = {                         37,
  263,   59,   40,   41,   42,   43,   78,   45,  263,   47,
   82,   44,   40,  114,  115,   40,  113,   41,   59,   59,
   58,   59,   60,   37,   62,  122,   59,   41,   42,   43,
   33,   45,  263,   47,   58,   59,   60,   40,   62,   88,
   89,   90,   45,  282,   58,   59,   60,   41,   62,  170,
   44,   37,  124,  174,  274,   93,   42,   43,  263,   45,
  157,   47,   37,   91,    0,  186,   91,   42,   43,   93,
   45,  263,   47,  265,   60,   11,   62,   59,   41,   93,
   43,   41,   45,   41,   44,   60,   44,   62,   41,  274,
   43,    0,   45,   41,  195,   58,   59,   60,   41,   62,
   41,   44,   11,   44,   91,   58,   59,   60,   37,   62,
   58,   59,   41,   42,   43,   41,   45,  263,   47,   37,
   56,  274,   59,   32,   42,   43,  263,   45,  265,   47,
   93,   60,   40,   62,  283,  284,  285,  286,   41,   40,
   93,   59,   60,   37,   62,   93,   41,   56,   42,   43,
   37,   45,   37,   47,  263,   42,   43,   42,   45,   59,
   47,  150,   47,   93,   37,   59,   60,  156,   62,   42,
   43,   58,   45,   60,   47,   62,  287,  263,  274,   88,
   89,   90,   41,   41,  274,   59,  175,   60,   59,   62,
   59,   59,  128,  129,  130,  263,   41,   93,   91,   58,
   59,   60,  263,   62,   59,   59,   41,  257,  258,  259,
  260,  261,  262,   58,   59,   60,  274,   62,   59,  128,
  129,  130,   41,   58,   59,   60,   59,   62,  266,  267,
  268,  269,  270,  271,   93,   10,  274,  275,   59,   58,
   59,  275,  266,  267,  268,  269,  270,  271,   93,   41,
   59,  275,  266,  267,  268,  269,  270,  271,   93,   41,
  263,  275,  265,   37,   39,   40,   58,   59,   42,   43,
   59,   45,  274,   47,   93,  274,   58,   59,   93,   54,
  266,  267,  268,  269,  270,  271,   60,   59,   62,  275,
   59,  266,  267,  268,  269,  270,  271,   59,   59,   59,
  275,   93,   59,  266,  267,  268,  269,  270,  271,  112,
   11,   93,  275,  266,  267,  268,  269,  270,  271,  267,
   37,   11,  275,   -1,   -1,   42,   43,  275,   45,   -1,
   47,  257,  258,  259,  260,  261,  262,  266,  267,  268,
  269,  270,  271,   60,   -1,   62,   -1,   -1,  266,  267,
  268,  269,  270,  271,  257,  258,  259,  260,  261,  262,
   -1,   -1,  257,  258,  259,  260,  261,  262,  283,  284,
  285,  286,  266,  267,  268,  269,  270,  271,   -1,  266,
  267,  268,  269,  270,  271,   -1,  257,  258,  259,  260,
  261,  262,   -1,  266,  267,  268,  269,  270,  271,  257,
  258,  259,  260,  261,  262,   -1,   -1,  266,  267,  268,
  269,  270,  271,   -1,  189,   -1,  275,  283,  284,  285,
  286,  266,  267,  268,  269,  270,  271,   -1,   -1,   -1,
  275,  266,  267,  268,  269,  270,  271,   -1,   45,   -1,
  275,  283,  284,  285,  286,   -1,   -1,  266,  267,   -1,
   -1,  270,  271,   -1,   -1,   -1,  275,   37,  283,  284,
  285,  286,   42,   43,   -1,   45,   -1,   47,  257,  258,
  259,  260,  261,  262,  266,  267,   10,   -1,  270,  271,
   60,   -1,   62,  275,  266,  267,   -1,   -1,   22,   10,
   -1,   -1,  266,  275,  268,  269,  270,  271,   -1,   -1,
   -1,   22,  109,   -1,   -1,   39,   40,   37,   -1,   -1,
   -1,   45,   42,   43,    0,   45,   -1,   47,   39,   40,
   54,    7,   -1,   -1,   45,   11,   -1,   -1,   14,   -1,
   -1,   -1,   -1,   54,   -1,   69,   -1,   -1,   -1,  146,
   26,   -1,   -1,  150,  151,  152,   32,   -1,   34,  156,
   -1,  268,  269,  270,  271,  257,  258,  259,  260,  261,
  262,   -1,  264,  170,   -1,   -1,   -1,  174,  175,   -1,
   56,   -1,   -1,   -1,   -1,  109,   -1,   22,   -1,  186,
  114,  115,   -1,   -1,   -1,   -1,   -1,   -1,  109,  196,
   -1,   -1,   78,  114,  115,   -1,   82,   -1,   -1,   -1,
   45,   -1,   88,   89,   90,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  146,   -1,   -1,   -1,  150,  151,  152,   -1,
   -1,   -1,  156,   -1,   -1,  146,  112,   -1,   -1,  150,
  151,  152,   -1,   -1,   -1,  156,  170,   -1,  124,   -1,
  174,  175,  128,  129,  130,   -1,   -1,   -1,   -1,  170,
   -1,   -1,  186,  174,  175,  189,   -1,   -1,   -1,   -1,
   -1,  195,  196,   -1,  109,  186,   -1,   -1,  189,  114,
  115,   -1,   -1,   -1,  195,  196,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,   -1,   -1,  268,  269,
   -1,   -1,   35,   -1,   37,   38,  277,   -1,  279,  280,
   -1,  146,   -1,   -1,   -1,  150,  151,  152,  289,   -1,
   53,  156,   -1,   -1,   -1,   -1,   59,   60,   61,  257,
  258,  259,  260,  261,  262,  170,  264,   -1,   -1,  174,
  175,   -1,   -1,   -1,   77,   -1,   -1,   -1,   -1,   -1,
   -1,  186,   -1,  281,   -1,   -1,   -1,   -1,   -1,   -1,
  195,  196,   95,   96,   97,   98,   99,  100,  101,  102,
  103,  104,  105,  106,  107,  257,  258,  259,  260,  261,
  262,  263,  264,  116,  117,  257,  258,  259,  260,  261,
  262,   -1,  264,   -1,   -1,  277,   -1,  279,  280,   -1,
  272,   -1,   -1,   -1,   -1,   -1,  288,  289,   -1,  281,
  257,  258,  259,  260,  261,  262,  263,  264,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  273,   -1,   -1,   -1,
  277,   -1,  279,  280,   -1,   -1,   -1,   -1,   -1,   -1,
  173,  257,  258,  259,  260,  261,  262,  263,  264,  257,
  258,  259,  260,  261,  262,  263,  264,   -1,   -1,  192,
  276,  277,   -1,  279,  280,   -1,   -1,   -1,  276,  277,
   -1,  279,  280,  257,  258,  259,  260,  261,  262,  263,
  264,  257,  258,  259,  260,  261,  262,  263,  264,   -1,
   -1,   -1,  276,  277,   -1,  279,  280,   -1,   -1,   -1,
   -1,  277,   -1,  279,  280,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 322
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
0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"function_call : identifier '(' lista_param ')'",
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
#line 239 "limbaj.y"
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
#line 792 "y.tab.c"

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
case 54:
#line 180 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "true", 0);}
break;
#line 1055 "y.tab.c"
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
