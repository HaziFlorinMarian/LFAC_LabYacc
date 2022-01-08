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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char string[256]; 
	char* type_id;
     int intval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
