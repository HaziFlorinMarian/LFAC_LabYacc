#define Integer 257
#define Float 258
#define Character 259
#define Bool 260
#define String 261
#define Void 262
#define ID 263
#define NR 264
#define STRING 265
#define FLOAT 266
#define LOGICAL_AND 267
#define LOGICAL_OR 268
#define LS_EQ 269
#define GR_EQ 270
#define EQ 271
#define NOT_EQ 272
#define BGIN 273
#define END 274
#define ASSIGN 275
#define BEGINSTMT 276
#define ENDSTMT 277
#define IF 278
#define ELSE 279
#define WHILE 280
#define FOR 281
#define CLASS 282
#define BEGINCLASS 283
#define ENDCLASS 284
#define PRIVATE 285
#define PROTECTED 286
#define PUBLIC 287
#define BEGINFNCTN 288
#define ENDFNCTN 289
#define RTRN 290
#define CONST 291
#define UMINUS 292
#define LOWER_THAN_ELSE 293
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
     float floatval;
     char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
