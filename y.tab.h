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
