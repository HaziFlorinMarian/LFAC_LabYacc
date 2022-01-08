%{
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h> 
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylin;

//#define YYDEBUG 1
//yydebug = 1;


 int totalVar = 0;
 int func_count = 0;
 int scope = 0; // 0 -> Global - 100000+ -> Function

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

%}

%union {
	char string[256]; 
	char* type_id;
     int intval;
}

%type <type_id> DATA_TYPE
%token <type_id> Integer Float Character Bool String Void
%token <string> ID CONST
%token <intval> NR
%token LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ
%token BGIN END ASSIGN BEGINSTMT ENDSTMT IF ELSE WHILE FOR CLASS BEGINCLASS ENDCLASS PRIVATE PROTECTED PUBLIC BEGINFNCTN ENDFNCTN RTRN
%start progr

%left ','
%right '='
%left LOGICAL_OR
%left LOGICAL_AND
%left EQ NOT_EQ
%left '<' '>' LS_EQ GR_EQ
%left '+' '-'
%left '*' '/' '%'
%right '!'

%nonassoc UMINUS
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

DATA_TYPE : Integer   	 {$$ = strdup("Integer");}
          | Float         {$$ = strdup("Float");}
          | Character 	 {$$ = strdup("Character");}
          | Bool          {$$ = strdup("Bool");}
          | String        {$$ = strdup("String");}
          | Void          {$$ = strdup("Void");}
          ;

progr: declaratii bloc {printf("program corect sintactic\n");}
     ;

/* initializare variabile, clase, functii, explicitare functii */
declaratii : declaratie ';'
	   | declaratii declaratie ';'
        | declaratii initializare_clasa
        | initializare_clasa ';'
        | declaratii descriere_functii ';'
        | descriere_functii ';'
        ;

declaratie : DATA_TYPE ID { CheckForErrors(1, $1); pushEmptyVariable($2, $1, "false", 0); }
           | DATA_TYPE ID '(' lista_param ')' { PushFunction($2, $1); }
           | DATA_TYPE ID '(' ')'  { PushFunction($2, $1); }
           | DATA_TYPE ID ASSIGN expr { CheckForErrors(1, $1); pushEmptyVariable($2, $1, "false", 0);}
           | constant
           | DATA_TYPE ID '[' NR ']' { CheckForErrors(1, $1); pushEmptyVariable($2, $1, "false", $4); }
           | DATA_TYPE ID '[' NR ']' ASSIGN expr { CheckForErrors(1, $1); pushEmptyVariable($2, $1, "false", $4); }
           ;


/* implementare clasa */
declaratii_clasa :  declaratie ';'
	   | declaratii_clasa declaratie ';'
        ;

bloc_clasa : declaratii_clasa
           | bloc_clasa PRIVATE declaratii_clasa 
           | bloc_clasa PROTECTED declaratii_clasa 
           | bloc_clasa PUBLIC declaratii_clasa
           ;

lista_id_clasa: ID
              | lista_id_clasa ',' ID
              ;

initializare_clasa : CLASS ID BEGINCLASS bloc_clasa ENDCLASS lista_id_clasa ';'
                   ;

lista_param : param
           | lista_param ','  param 
           ;
            
param : DATA_TYPE ID { PushParameters($2, $1); }
      ;
      
/* bloc */
bloc : BGIN list END  
     ;

enter_func: BEGINFNCTN { EnterFunction(); }
     ;

leave_func: ENDFNCTN { ExitFunction(); }
     ;


/*descriere functii */
descriere_functii :  DATA_TYPE ID '(' lista_param ')' enter_func list_function leave_func { CheckForErrors(2, $2); }
           | DATA_TYPE ID '(' ')' enter_func list_function leave_func { CheckForErrors(2, $2); }
           | descriere_functii DATA_TYPE ID '(' lista_param ')' enter_func list_function leave_func { CheckForErrors(2, $2); }
           | descriere_functii DATA_TYPE ID '(' ')' enter_func list_function leave_func { CheckForErrors(2, $2); }
           ;

/* te lasa sa nu pui Retrun */ 
list_function : list_function statement ';'
              | list_function RTRN ID ';'
              | statement ';'
              | RTRN ID ';'
              | list_function RTRN NR ';'
              | RTRN NR ';'
              ;

/* lista instructiuni */
list :  statement ';'
     | list statement ';'
     ;

///PARTE PROPRIE PROIECT
/* constante */
constant : CONST DATA_TYPE ID ASSIGN NR { CheckForErrors(1, $2); pushEmptyVariable($3, $2, "true", 0);}
         ;

/* expresii matematice */         
expr: expr '+' expr
     |expr '-' expr		
     |expr '*' expr		
     |expr '/' expr		
     |expr '%' expr	
     |'(' expr ')'				
     |'-' expr %prec UMINUS			
     |operand
     ;

/* operanzi */
operand : ID
        | NR
        | ID '[' NR ']'
        | ID '[' ID ']'
        ;

/* expresii in if-uri, while-uri, for-uri */
boolexpr: '(' boolexpr ')' 
    |boolexpr '>' boolexpr
    |boolexpr '<' boolexpr
    |boolexpr EQ boolexpr
    |boolexpr NOT_EQ boolexpr		
    |boolexpr LS_EQ boolexpr		
    |boolexpr GR_EQ boolexpr		
    |boolexpr LOGICAL_AND boolexpr	
    |boolexpr LOGICAL_OR boolexpr	
    |'!' boolexpr
    |expr
    ;

/* if */         
if_stmt : IF boolexpr BEGINSTMT list ENDSTMT
        ;

/* while */
while_stmt : WHILE boolexpr BEGINSTMT list ENDSTMT 
           ;

/* for */
for_stmt : FOR operand ASSIGN expr ';' boolexpr ';' expr ASSIGN expr ':' BEGINSTMT list ENDSTMT 
         ;

/* instructiune */
statement: ID '(' lista_apel ')' { ResetCallStack(); }
         | ID '(' ')' { ResetCallStack(); }
         | ID ASSIGN expr
         | DATA_TYPE ID { CheckForErrors(1, $1); pushEmptyVariable($2, $1, "false", 0);}
         | DATA_TYPE ID ASSIGN expr { CheckForErrors(1, $1); pushEmptyVariable($2, $1, "false", 0);}
         | DATA_TYPE ID '[' NR ']' { CheckArrayRange($2, $4); }
         | ID '[' ID ']' ASSIGN expr
         | ID '[' NR ']' ASSIGN expr { CheckArrayRange($1, $3); }
         | DATA_TYPE ID '[' NR ']' ASSIGN expr { CheckForErrors(1, $1); pushEmptyVariable($2, $1, "false", $4);}
         | constant
         | if_stmt
         | while_stmt
         | for_stmt
         ;
        
lista_apel : expr
           | lista_apel ',' expr
           ;

%%
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