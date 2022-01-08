%{
#include <stdio.h>
%}
%start s
%token SMB
%%
s : e  {$$=$1;  printf("regula s->e\n valoarea expresiei:%d\n",$$);}
  ;
e : e '+' e  {$$=$1+$3;printf("regula e->e+e\n"); }
  | e '*' e  {$$=$1*$3; printf("regula e->e*e\n"); }
  | SMB {$$=$1; printf("regula e->%d\n",$1); }
  ;
  
%%
int yyerror(char* s) {
 printf("error:%s\n",s);
}

int main(){
 yyparse();
}

// Exemplu modificat, nu merge bine pe exemplul 2*3+5 deoarece face operatia + inaintea * deoarece asa e scrisa ordienea la liniile 9,10