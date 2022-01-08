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
#define BGIN 266
#define END 267
#define ASSIGN 268
#define OPERATOR 269
#define BOOLOPERATOR 270
#define BEGINSTMT 271
#define ENDSTMT 272
#define IF 273
#define ELSE 274
#define WHILE 275
#define FOR 276
#define CLASS 277
#define BEGINCLASS 278
#define ENDCLASS 279
#define PRIVATE 280
#define PROTECTED 281
#define PUBLIC 282
#define BEGINFNCTN 283
#define ENDFNCTN 284
#define RTRN 285
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    1,    1,    1,    1,    1,    1,    0,    2,    2,    2,
    2,    2,    2,    4,    4,    4,    4,    4,    4,    4,
   10,   10,   11,   11,   11,   11,   12,   12,    5,    7,
    7,   13,   14,   14,   15,    3,   17,   18,    6,    6,
    6,    6,   19,   19,   19,   19,   19,   19,   16,   16,
    9,    8,    8,   21,   21,   21,   21,   22,   22,   23,
   24,   25,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   26,   26,
};
static const YYINT yylen[] = {                            2,
    1,    1,    1,    1,    1,    1,    2,    2,    3,    2,
    2,    3,    2,    2,    5,    4,    4,    1,    5,    7,
    2,    3,    1,    3,    3,    3,    1,    3,    7,    1,
    3,    2,    1,    3,    2,    3,    1,    1,    8,    7,
    9,    8,    3,    4,    2,    3,    4,    3,    2,    3,
    5,    3,    1,    1,    1,    4,    4,    3,    1,    5,
    5,   14,    4,    3,    3,    2,    4,    5,    6,    6,
    7,    1,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    2,    3,    4,    5,    6,    0,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    7,
    0,   10,    0,    8,   11,   13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   72,    0,    0,
   73,   74,   75,    9,   12,    0,    0,    0,    0,    0,
    0,    0,   55,    0,   53,    0,    0,    0,   30,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   36,    0,
   49,    0,   51,    0,   21,    0,    0,    0,    0,    0,
    0,    0,   37,    0,   32,    0,    0,    0,    0,   64,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   50,    0,    0,    0,   22,   27,    0,    0,    0,    0,
    0,    0,   52,    0,    0,    0,    0,   31,    0,   63,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   16,    0,   29,    0,   57,   56,    0,    0,   38,
    0,   40,    0,   45,    0,    0,    0,    0,    0,   60,
   61,    0,    0,    0,    0,   15,   28,   46,   48,    0,
    0,   43,   39,    0,    0,    0,    0,   42,    0,   44,
   47,    0,    0,   41,    0,    0,    0,    0,    0,    0,
   62,
};
static const YYINT yydgoto[] = {                          9,
   37,   11,   20,   49,   13,   14,   58,   64,   38,   50,
   51,  107,   59,    0,    0,   39,   84,  142,  115,   40,
   55,   65,   41,   42,   43,   92,
};
static const YYINT yysindex[] = {                        15,
    0,    0,    0,    0,    0,    0, -137, -225,    0, -214,
  -65,   -5,   12,  -51,    0, -204, -188,  -36,  117,    0,
   42,    0,   -1,    0,    0,    0, -157, -159, -166, -186,
  -22, -155,  -35, -186, -186, -186, -150,    0,   37,   75,
    0,    0,    0,    0,    0,   95, -124, -121,   94, -166,
 -206,   66,    0, -109,    0, -122,  -83,  -15,    0,  105,
 -186,  -40, -111, -109, -238, -228,  -68,  -80,    0,  156,
    0,  -16,    0,  -34,    0,  157,  -46, -166, -166, -166,
 -107, -186,    0,    5,    0, -122, -137,  -37, -109,    0,
 -109,   -7,  160,  161, -186,  117,  117, -186, -186,    6,
    0, -122,    7,  -10,    0,    0,  -24, -166, -166, -166,
  162,  177,    0,  -76,  -94,  223,    5,    0, -186,    0,
 -186,   16,   17, -109,   57,   77,  -47, -109,  190,    5,
 -122,    0,   23,    0,   24,    0,    0,  227,  229,    0,
  -39,    0,  230,    0,  -94, -109, -109, -186, -186,    0,
    0, -186,   25,  -94,    5,    0,    0,    0,    0,  232,
  243,    0,    0, -109, -109,  -50, -186,    0,  -94,    0,
    0, -186, -109,    0, -185, -186,  -48,   32,  117,   97,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  246,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -108,
    0,  -41,    0,  247,    0,  248,    0,    0,    0,    0,
    0,    0,    0,  -57,    0,    0,    0,  249,    0,    0,
    0,    0,    0,  246,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  250,    0,  252,  263,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -104,  -96,  -77,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -52,    0,    0,    0,  264,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  265,   59,    0,    0,    0,
    0,    0,  266,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  267,  268,    0,    0,    0,    0,    0,
    0,    0,   75,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
   39,    0,    0,   30,  317,  320,  -44,  -17,   36,   50,
    0,    0,  255,    0,    0,  -74,  -62,  -82, -103,  -18,
  -21,  -19,    0,    0,    0,    0,
};
#define YYTABLESIZE 393
static const YYINT yytable[] = {                         54,
   90,   59,   54,   31,   62,  104,   58,   26,  172,  178,
  100,  152,   54,  145,   67,   66,   54,   54,   56,  135,
   70,  125,  126,  117,  102,   86,  154,  103,   87,   12,
  132,   95,   96,  120,  134,   15,  121,   17,   10,  130,
   21,   95,   97,   89,   91,   16,   15,  131,   18,   10,
   87,  169,   27,   24,   32,   63,   32,   45,   28,  133,
  113,   27,  163,  156,   15,  116,   87,   48,  155,   57,
   25,  168,   77,   78,   79,   80,   52,  124,   53,   76,
  127,  128,  176,   82,   76,   15,  174,   76,   48,   29,
    1,    2,    3,    4,    5,    6,  143,    7,  116,   77,
   44,  146,   77,  147,  180,   46,   70,   70,   47,   60,
   57,  116,   68,   15,   15,   15,   48,   48,   48,    1,
    2,    3,    4,    5,    6,   57,  143,  108,  109,  110,
  164,  165,  166,   71,   72,  143,  116,   76,   76,   76,
   73,   74,   57,   15,   15,   15,   48,   48,   48,  173,
  143,   93,   75,   94,  175,  111,   81,  112,  177,   82,
   83,   70,    1,    2,    3,    4,    5,    6,   33,    7,
   23,   23,   23,   23,   24,   24,   24,   24,   34,   85,
   35,   36,   25,   25,   25,   25,  138,   99,  139,  140,
  141,    1,    2,    3,    4,    5,    6,   88,    7,   98,
   19,   26,   26,   26,   26,    1,    2,    3,    4,    5,
    6,    8,   59,   59,  101,  105,  106,   58,   58,   95,
   82,   82,   52,  160,   53,  161,   54,   54,   54,   54,
  119,   30,   61,   30,    1,    2,    3,    4,    5,    6,
    1,    2,    3,    4,    5,    6,    1,    2,    3,    4,
    5,    6,  122,  123,  136,    1,    2,    3,    4,    5,
    6,    1,    2,    3,    4,    5,    6,   33,    7,  137,
  129,    1,    2,    3,    4,    5,    6,   34,    7,   35,
   36,  144,  153,  148,  149,  158,  157,  159,  162,  114,
  170,    8,  167,    1,    2,    3,    4,    5,    6,   33,
    7,  171,  179,   69,   14,   17,   16,   66,   15,   34,
   19,   35,   36,    1,    2,    3,    4,    5,    6,   33,
    7,   65,   67,   20,   68,   69,   70,   22,  150,   34,
   23,   35,   36,    1,    2,    3,    4,    5,    6,   33,
    7,  118,    0,    0,    0,    0,    0,    0,  151,   34,
    0,   35,   36,    1,    2,    3,    4,    5,    6,   33,
    7,    0,    0,    0,    0,    0,    0,    0,  181,   34,
    0,   35,   36,    1,    2,    3,    4,    5,    6,   33,
    7,    0,    0,    0,    0,    0,    0,    0,    0,   34,
    0,   35,   36,
};
static const YYINT yycheck[] = {                         41,
   41,   59,   44,   40,   40,   40,   59,   59,   59,   58,
   91,   59,   30,  117,   36,   35,   58,   59,   41,   44,
   39,   96,   97,   86,   41,   41,  130,   72,   44,    0,
   41,  270,  271,   41,   59,    0,   44,  263,    0,  102,
   11,  270,  271,   61,   62,    7,   11,   41,  263,   11,
   44,  155,   14,   59,   91,   91,   91,   59,  263,  104,
   82,   23,  145,   41,   29,   84,   44,   29,  131,   31,
   59,  154,  279,  280,  281,  282,  263,   95,  265,   50,
   98,   99,  268,  269,   41,   50,  169,   44,   50,  278,
  257,  258,  259,  260,  261,  262,  115,  264,  117,   41,
   59,  119,   44,  121,  179,  263,  125,  126,  268,  265,
   72,  130,  263,   78,   79,   80,   78,   79,   80,  257,
  258,  259,  260,  261,  262,   87,  145,   78,   79,   80,
  148,  149,  152,   59,   40,  154,  155,  108,  109,  110,
  265,  263,  104,  108,  109,  110,  108,  109,  110,  167,
  169,  263,   59,  265,  172,  263,   91,  265,  176,  269,
  283,  180,  257,  258,  259,  260,  261,  262,  263,  264,
  279,  280,  281,  282,  279,  280,  281,  282,  273,  263,
  275,  276,  279,  280,  281,  282,  263,  268,  265,  284,
  285,  257,  258,  259,  260,  261,  262,   93,  264,  268,
  266,  279,  280,  281,  282,  257,  258,  259,  260,  261,
  262,  277,  270,  271,   59,   59,  263,  270,  271,  270,
  269,  269,  263,  263,  265,  265,  268,  269,  270,  271,
  268,  268,  268,  268,  257,  258,  259,  260,  261,  262,
  257,  258,  259,  260,  261,  262,  257,  258,  259,  260,
  261,  262,   93,   93,   93,  257,  258,  259,  260,  261,
  262,  257,  258,  259,  260,  261,  262,  263,  264,   93,
  265,  257,  258,  259,  260,  261,  262,  273,  264,  275,
  276,   59,   93,  268,  268,   59,  263,   59,   59,  285,
   59,  277,  268,  257,  258,  259,  260,  261,  262,  263,
  264,   59,  271,  267,   59,   59,   59,   59,   59,  273,
   59,  275,  276,  257,  258,  259,  260,  261,  262,  263,
  264,   59,   59,   59,   59,   59,   59,   11,  272,  273,
   11,  275,  276,  257,  258,  259,  260,  261,  262,  263,
  264,   87,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  257,  258,  259,  260,  261,  262,  263,
  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  257,  258,  259,  260,  261,  262,  263,
  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,
   -1,  275,  276,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 285
#define YYUNDFTOKEN 314
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"Integer","Float","Character","Bool","String","Void","ID","CONST","NR","BGIN",
"END","ASSIGN","OPERATOR","BOOLOPERATOR","BEGINSTMT","ENDSTMT","IF","ELSE",
"WHILE","FOR","CLASS","BEGINCLASS","ENDCLASS","PRIVATE","PROTECTED","PUBLIC",
"BEGINFNCTN","ENDFNCTN","RTRN",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
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
"lista_apel_param : param_apel",
"lista_apel_param : lista_apel_param ',' param_apel",
"param_apel : DATA_TYPE ID",
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
"expr : expr OPERATOR operand",
"expr : operand",
"operand : ID",
"operand : NR",
"operand : ID '[' NR ']'",
"operand : ID '[' ID ']'",
"boolexpr : boolexpr BOOLOPERATOR expr",
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
#line 209 "limbaj.y"
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
PrintVar();
PrintFunc();
}
#line 669 "y.tab.c"

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
#line 60 "limbaj.y"
	{yyval.type_id = strdup("Integer");}
break;
case 2:
#line 61 "limbaj.y"
	{yyval.type_id = strdup("Float");}
break;
case 3:
#line 62 "limbaj.y"
	{yyval.type_id = strdup("Character");}
break;
case 4:
#line 63 "limbaj.y"
	{yyval.type_id = strdup("Bool");}
break;
case 5:
#line 64 "limbaj.y"
	{yyval.type_id = strdup("String");}
break;
case 6:
#line 65 "limbaj.y"
	{yyval.type_id = strdup("Void");}
break;
case 7:
#line 68 "limbaj.y"
	{printf("program corect sintactic\n");}
break;
case 14:
#line 80 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); pushEmptyVariable(yystack.l_mark[0].string, yystack.l_mark[-1].type_id, "false", 0); }
break;
case 15:
#line 81 "limbaj.y"
	{ PushFunction(yystack.l_mark[-3].string, yystack.l_mark[-4].type_id); }
break;
case 16:
#line 82 "limbaj.y"
	{ PushFunction(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id); }
break;
case 17:
#line 83 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "false", 0);}
break;
case 19:
#line 85 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-4].type_id); pushEmptyVariable(yystack.l_mark[-3].string, yystack.l_mark[-4].type_id, "false", yystack.l_mark[-1].intval); }
break;
case 20:
#line 86 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-6].type_id); pushEmptyVariable(yystack.l_mark[-5].string, yystack.l_mark[-6].type_id, "false", yystack.l_mark[-3].intval); }
break;
case 32:
#line 112 "limbaj.y"
	{ PushParameters(yystack.l_mark[0].string, yystack.l_mark[-1].type_id); }
break;
case 35:
#line 119 "limbaj.y"
	{ InsertIntoCallStack(yystack.l_mark[0].string, yystack.l_mark[-1].type_id); }
break;
case 37:
#line 126 "limbaj.y"
	{ EnterFunction(); }
break;
case 38:
#line 129 "limbaj.y"
	{ ExitFunction(); }
break;
case 39:
#line 134 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].string); }
break;
case 40:
#line 135 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-5].string); }
break;
case 41:
#line 136 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-7].type_id); }
break;
case 42:
#line 137 "limbaj.y"
	{ CheckForErrors(2, yystack.l_mark[-6].type_id); }
break;
case 51:
#line 156 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "true", 0);}
break;
case 63:
#line 189 "limbaj.y"
	{ ResetCallStack(); }
break;
case 64:
#line 190 "limbaj.y"
	{ ResetCallStack(); }
break;
case 66:
#line 192 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-1].type_id); pushEmptyVariable(yystack.l_mark[0].string, yystack.l_mark[-1].type_id, "false", 0);}
break;
case 67:
#line 193 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-3].type_id); pushEmptyVariable(yystack.l_mark[-2].string, yystack.l_mark[-3].type_id, "false", 0);}
break;
case 68:
#line 194 "limbaj.y"
	{ CheckArrayRange(yystack.l_mark[-3].string, yystack.l_mark[-1].intval); }
break;
case 70:
#line 196 "limbaj.y"
	{ CheckArrayRange(yystack.l_mark[-5].string, yystack.l_mark[-3].intval); }
break;
case 71:
#line 197 "limbaj.y"
	{ CheckForErrors(1, yystack.l_mark[-6].type_id); pushEmptyVariable(yystack.l_mark[-5].string, yystack.l_mark[-6].type_id, "false", yystack.l_mark[-3].intval);}
break;
#line 984 "y.tab.c"
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
