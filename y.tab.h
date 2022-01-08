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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	char var_name[256];
	char* type_id;
     int intval;
     char* string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
