%{
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

%}

%union {
	char var_name[256];
	char* type_id;
     int intval;
     float floatval;
     char* strval;
}

%type <type_id> DATA_TYPE expr operand function_call constant
%type <strval> lhs declare_lhs identifier array_access descriere_functii
%token <type_id> Integer Float Character Bool String Void
%token <var_name> ID
%token <intval> NR
%token <strval> STRING
%token <floatval> FLOAT
%token LOGICAL_AND LOGICAL_OR LS_EQ GR_EQ EQ NOT_EQ
%token BGIN END ASSIGN BEGINSTMT ENDSTMT IF ELSE WHILE FOR CLASS BEGINCLASS ENDCLASS PRIVATE PROTECTED PUBLIC BEGINFNCTN ENDFNCTN RTRN CONST
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

DATA_TYPE : Integer   	 {$$ = strdup("Integer");   }
          | Float         {$$ = strdup("Float");   }
          | Character 	 {$$ = strdup("Character");  }
          | Bool          {$$ = strdup("Bool");   }
          | String        {$$ = strdup("String");   }
          | Void          {$$ = strdup("Void");   }
          ;

progr: declaratii bloc {printf("program corect sintactic\n");}
     ;

declare_lhs: identifier                 { $$ = strdup($1); AddNewVariable($1);       }
            |identifier '[' NR ']'      { $$ = strdup($1); AddArraySize($1, $3);     }
             ;

lhs:  identifier                        { $$ = strdup($1); }
     |array_access                      { $$ = strdup($1); }
     ;

identifier: ID                          { $$ = strdup($1); }
     ;

array_access: ID '[' expr ']'           { $$ = strdup($1); }
     ;

function_call : identifier '(' lista_apel ')'     { $$ = GetType(2, $1); }
              | identifier '(' ')'                { $$ = GetType(2, $1); }
              ;

/* initializare variabile, clase, functii, explicitare functii */
declaratii : declaratie ';'
	   | declaratii declaratie ';'
        | declaratii initializare_clasa
        | initializare_clasa ';'
        | declaratii descriere_functii ';'
        | descriere_functii ';'
        ;

declaratie : DATA_TYPE declare_lhs { CheckForErrors(1, $1); AddDataType($2, $1); }
           | DATA_TYPE declare_lhs { CheckForErrors(1, $1); AddDataType($2, $1); } ASSIGN expr
           | constant
           ;


/* implementare clasa */
declaratii_clasa :  declaratie ';'
	   | declaratii_clasa declaratie ';'
        | declaratii_clasa descriere_functii ';'
        | descriere_functii ';'
        ;

bloc_clasa : declaratii_clasa
           | bloc_clasa PRIVATE declaratii_clasa 
           | bloc_clasa PROTECTED declaratii_clasa 
           | bloc_clasa PUBLIC declaratii_clasa
           ;

lista_id_clasa: ID
              | lista_id_clasa ',' ID
              ;

initializare_clasa : CLASS ID BEGINCLASS { NewScope(); } bloc_clasa ENDCLASS { { ExitScope(); } } lista_id_clasa ';'
                   ;

lista_param : param
           | lista_param ','  param 
           ;
            
param : DATA_TYPE identifier            { PushParameters($1); AddParamToVarList($2, $1); }
       |DATA_TYPE identifier '[' ']'    { PushParameters($1); AddParamToVarList($2, $1); }
       ;
      
/* bloc */
bloc : BGIN { NewScope(); } list END { ExitScope(); }
     ;

enter_func: BEGINFNCTN
     ;

leave_func: ENDFNCTN
     ;


/*descriere functii */
descriere_functii : DATA_TYPE ID '(' { NewScope(); } lista_param ')' enter_func list leave_func { ExitScope(); PushFunction($2, $1); }
           | DATA_TYPE ID '(' { NewScope(); } ')' enter_func list leave_func { ExitScope(); PushFunction($2, $1); }
           | descriere_functii DATA_TYPE ID '(' { NewScope(); } lista_param ')' enter_func list leave_func { ExitScope(); PushFunction($2, $1); }
           | descriere_functii DATA_TYPE ID '(' { NewScope(); } ')' enter_func list leave_func { ExitScope(); PushFunction($2, $1); }
           ;

/* lista instructiuni */
list :  statement ';'
     | list statement ';'
     ;

///PARTE PROPRIE PROIECT
/* constante */
constant : CONST DATA_TYPE ID ASSIGN expr { CheckForErrors(1, $2); AddConstantVariable($3, $2, "true", 0); $$ = GetType(1, $3); }
         ;

/* expresii matematice */         
expr: expr '+' expr      { type_check($1, $3); $$ = strdup($1); }
	|expr '-' expr      { type_check($1, $3); $$ = strdup($1); }
	|expr '*' expr      { type_check($1, $3); $$ = strdup($1); }
	|expr '/' expr      { type_check($1, $3); $$ = strdup($1); }
	|expr '%' expr      { type_check($1, $3); $$ = strdup($1); }
	|'(' expr ')'       { $$ = strdup($2); }
	|expr '>' expr      { type_check($1, $3); $$ = strdup($1); }
	|expr '<' expr      { type_check($1, $3); $$ = strdup($1); }
	|expr EQ expr       { type_check($1, $3); $$ = strdup($1); }
	|expr NOT_EQ expr   { type_check($1, $3); $$ = strdup($1); }
	|expr LS_EQ expr    { type_check($1, $3); $$ = strdup($1); }
	|expr GR_EQ expr    { type_check($1, $3); $$ = strdup($1); }
	|expr LOGICAL_AND expr   { type_check($1, $3); $$ = strdup($1); }
	|expr LOGICAL_OR expr    { type_check($1, $3); $$ = strdup($1); }
	|'!' expr           { $$ = strdup($2); }
	|operand            { $$ = strdup($1); }
	;

/* operanzi */
operand : identifier          { $$ = GetType(1, $1);        }
         |array_access        { $$ = strdup("Integer");     }
         |NR                  { $$ = strdup("Integer");     }
         |STRING              { $$ = strdup("String"); printf("%s\n", $1);     }
         |function_call       { $$ = strdup($1);            }
        ;


begin_statement: BEGINSTMT { NewScope(); }
     ;

end_statement: ENDSTMT { ExitScope(); }
     ;

/* if */         
if_stmt : IF expr begin_statement list end_statement
        ;

/* while */
while_stmt : WHILE expr begin_statement list end_statement 
           ;

/* for */
for_stmt : FOR lhs ASSIGN expr ';' expr ';' lhs ASSIGN expr ':' begin_statement list end_statement 
         ;

/* instructiune */
statement: DATA_TYPE declare_lhs                       { CheckForErrors(1, $1); AddDataType($2, $1); }
         | lhs ASSIGN expr
         | DATA_TYPE declare_lhs { CheckForErrors(1, $1); AddDataType($2, $1); } ASSIGN expr
         | constant
         | if_stmt
         | while_stmt
         | for_stmt
         | RTRN
         | RTRN expr
         | function_call
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
     int fixed_scope = current_scope-1;
     int pos = F[fixed_scope].totalFunc;
     int *j = &F[fixed_scope].func_table[pos].ParamNumber;

     F[fixed_scope].func_table[pos].ParamType[*j] = strdup(type);

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