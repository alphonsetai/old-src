/*
 * Created by CSD YACC (IBM PC) from "acfgram.y" */

/****************************************************************************
 ***            local defines
 ***************************************************************************/

#define pascal
#define FARDATA
#define NEARDATA
#define FARCODE
#define NEARCODE
#define NEARSWAP
#define YYFARDATA

#define PASCAL pascal
#define CDECL
#define VOID void
#define CONST const
#define GLOBAL

#define YYSTYPE         lextype_t
#define YYNEAR          NEARCODE
#define YYPASCAL        PASCAL
#define YYPRINT         printf
#define YYSTATIC        static
#define YYCONST         static const
#define YYLEX           yylex
#define YYPARSER        yyparse
#define yyval                   yyacfval


#include "nulldefs.h"

extern "C"      {
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
        #include <ctype.h>
        #define yyparse yyacfparse
        int yyacfparse();
}
#include "allnodes.hxx"
#include "lexutils.hxx"
#include "gramutil.hxx"
#include "filehndl.hxx"
#include "control.hxx"
#include "cmdana.hxx"

extern "C" {
        #include "lex.h"
}

/****************************************************************************
 ***            local defines contd..
 ***************************************************************************/

#define PUSH_SYMBOL_TABLE(pName, Tag, pSymTbl)                                  \
                                                        {                                                                       \
                                                        pSymTbl = pBaseSymTbl;                          \
                                                        SymKey  SKey( pName, Tag );                     \
                                                        pSymTbl->EnterScope(SKey, &pSymTbl);\
                                                        }

#define POP_SYMBOL_TABLE( pSymTbl )                                                             \
                                                        pSymTbl->ExitScope(&pSymTbl)
/****************************************************************************
 ***            local data
 ***************************************************************************/

node_proc               *       pAcfProc;
int                                     iParam;
int                                     cParams;
node_interface  *       pCurInterfaceNode;

/****************************************************************************
 ***            extern procs
 ***************************************************************************/

extern  void                            yyunlex( token_t );
extern  char    *                       GenTempName();
extern  STATUS_T                        GetBaseTypeNode(node_skl**,short,short,short);
extern  short                           CheckValidAllocate( char * );
extern  void                            SyntaxError( STATUS_T, short );
extern  int                                     PossibleMissingToken( short, short );
extern  CMD_ARG *                       pCommand;

/****************************************************************************
 ***            local data
 ***************************************************************************/
/****************************************************************************
 ***            extern data
 ***************************************************************************/

extern SymTable         *       pBaseSymTbl;
extern NFA_INFO         *       pImportCntrl;
extern PASS_2           *       pPass2;


# define KWINTERFACE 257
# define KWCLASS 258
# define KWEXESERVER 259
# define KWDLLSERVER 260
# define KWIMPORT 261
# define KWIMPORTIDLBASE 262
# define KWIMPORTODLBASE 263
# define KWCPPQUOTE 264
# define KWCPRAGMA 265
# define KWCPRAGMAPACK 266
# define KWMPRAGMAIMPORT 267
# define KWMPRAGMAECHO 268
# define KWMPRAGMAIMPORTCLNTAUX 269
# define KWMPRAGMAIMPORTSRVRAUX 270
# define TYPENAME 271
# define LIBNAME 272
# define KWVOID 273
# define KWUNSIGNED 274
# define KWSIGNED 275
# define KWFLOAT 276
# define KWDOUBLE 277
# define KWINT 278
# define KWBYTE 279
# define KWCHAR 280
# define KWSMALL 281
# define KWLONG 282
# define KWSHORT 283
# define KWHYPER 284
# define KWINT64 285
# define KWSTRUCT 286
# define KWUNION 287
# define KWENUM 288
# define KWSHORTENUM 289
# define KWLONGENUM 290
# define KWCONST 291
# define KWVOLATILE 292
# define KW_C_INLINE 293
# define KWTYPEDEF 294
# define KWEXTERN 295
# define KWSTATIC 296
# define KWAUTO 297
# define KWREGISTER 298
# define KWERRORSTATUST 299
# define KWBOOLEAN 300
# define KWISOLATIN1 301
# define KWPRIVATECHAR8 302
# define KWISOMULTILINGUAL 303
# define KWPRIVATECHAR16 304
# define KWISOUCS 305
# define KWPIPE 306
# define KWSWITCH 307
# define KWCASE 308
# define KWDEFAULT 309
# define KWUUID 310
# define KWVERSION 311
# define KWOPAQUE 312
# define KWSTRING 313
# define KWBSTRING 314
# define KWIN 315
# define KWOUT 316
# define KWIIDIS 317
# define KWFIRSTIS 318
# define KWLASTIS 319
# define KWMAXIS 320
# define KWMINIS 321
# define KWLENGTHIS 322
# define KWSIZEIS 323
# define KWID 324
# define KWHC 325
# define KWHSC 326
# define KWLCID 327
# define KWDLLNAME 328
# define KWHELPSTR 329
# define KWHELPFILE 330
# define KWENTRY 331
# define KWPROPGET 332
# define KWPROPPUT 333
# define KWPROPPUTREF 334
# define KWOPTIONAL 335
# define KWVARARG 336
# define KWAPPOBJECT 337
# define KWRESTRICTED 338
# define KWPUBLIC 339
# define KWREADONLY 340
# define KWODL 341
# define KWSOURCE 342
# define KWBINDABLE 343
# define KWREQUESTEDIT 344
# define KWDISPLAYBIND 345
# define KWDEFAULTBIND 346
# define KWLICENSED 347
# define KWPREDECLID 348
# define KWHIDDEN 349
# define KWRETVAL 350
# define KWCONTROL 351
# define KWDUAL 352
# define KWNONEXTENSIBLE 353
# define KWNONCREATABLE 354
# define KWOLEAUTOMATION 355
# define KWLIBRARY 356
# define KWMODULE 357
# define KWDISPINTERFACE 358
# define KWCOCLASS 359
# define KWMETHODS 360
# define KWPROPERTIES 361
# define KWIMPORTLIB 362
# define KWFUNCDESCATTR 363
# define KWIDLDESCATTR 364
# define KWTYPEDESCATTR 365
# define KWVARDESCATTR 366
# define KWSAFEARRAY 367
# define KWAGGREGATABLE 368
# define KWUIDEFAULT 369
# define KWNONBROWSABLE 370
# define KWDEFAULTCOLLELEM 371
# define KWDEFAULTVALUE 372
# define KWCUSTOM 373
# define KWDEFAULTVTABLE 374
# define KWIMMEDIATEBIND 375
# define KWUSESGETLASTERROR 376
# define KWREPLACEABLE 377
# define KWHANDLET 378
# define KWHANDLE 379
# define KWCONTEXTHANDLE 380
# define KWMSUNION 381
# define KWENDPOINT 382
# define KWDEFAULTPOINTER 383
# define KWLOCAL 384
# define KWSWITCHTYPE 385
# define KWSWITCHIS 386
# define KWTRANSMITAS 387
# define KWWIREMARSHAL 388
# define KWIGNORE 389
# define KWREF 390
# define KWUNIQUE 391
# define KWPTR 392
# define KWV1ARRAY 393
# define KWV1STRUCT 394
# define KWV1ENUM 395
# define KWV1STRING 396
# define KWIDEMPOTENT 397
# define KWBROADCAST 398
# define KWMAYBE 399
# define KWASYNC 400
# define KWINPUTSYNC 401
# define KWCALLBACK 402
# define KWALIGN 403
# define KWUNALIGNED 404
# define KWOPTIMIZE 405
# define STRING 406
# define WIDECHARACTERSTRING 407
# define KWTOKENNULL 408
# define NUMERICCONSTANT 409
# define NUMERICUCONSTANT 410
# define NUMERICLONGCONSTANT 411
# define NUMERICULONGCONSTANT 412
# define HEXCONSTANT 413
# define HEXUCONSTANT 414
# define HEXLONGCONSTANT 415
# define HEXULONGCONSTANT 416
# define OCTALCONSTANT 417
# define OCTALUCONSTANT 418
# define OCTALLONGCONSTANT 419
# define OCTALULONGCONSTANT 420
# define CHARACTERCONSTANT 421
# define WIDECHARACTERCONSTANT 422
# define IDENTIFIER 423
# define KWSIZEOF 424
# define TOKENTRUE 425
# define TOKENFALSE 426
# define MSCDECLSPEC 427
# define MSCDLLIMPORT 428
# define MSCDLLEXPORT 429
# define MSCEXPORT 430
# define MSCFORTRAN 431
# define MSCCDECL 432
# define MSCSTDCALL 433
# define MSCLOADDS 434
# define MSCSAVEREGS 435
# define MSCFASTCALL 436
# define MSCSEGMENT 437
# define MSCINTERRUPT 438
# define MSCSELF 439
# define MSCNEAR 440
# define MSCFAR 441
# define MSCUNALIGNED 442
# define MSCHUGE 443
# define MSCPASCAL 444
# define MSCEMIT 445
# define MSCASM 446
# define KWNOCODE 447
# define POINTSTO 448
# define INCOP 449
# define DECOP 450
# define MULASSIGN 451
# define DIVASSIGN 452
# define MODASSIGN 453
# define ADDASSIGN 454
# define SUBASSIGN 455
# define LEFTASSIGN 456
# define RIGHTASSIGN 457
# define ANDASSIGN 458
# define XORASSIGN 459
# define ORASSIGN 460
# define DOTDOT 461
# define LTEQ 462
# define GTEQ 463
# define NOTEQ 464
# define LSHIFT 465
# define RSHIFT 466
# define ANDAND 467
# define EQUALS 468
# define OROR 469
# define NOTOKEN 470
# define GARBAGETOKEN 471
# define KWOBJECT 472
# define KWSHAPE 473
# define KWBYTECOUNT 474
# define KWIMPLICITHANDLE 475
# define KWAUTOHANDLE 476
# define KWEXPLICITHANDLE 477
# define KWREPRESENTAS 478
# define KWCALLAS 479
# define KWCODE 480
# define KWINLINE 481
# define KWOUTOFLINE 482
# define KWINTERPRET 483
# define KWNOINTERPRET 484
# define KWCOMMSTATUS 485
# define KWFAULTSTATUS 486
# define KWHEAP 487
# define KWINCLUDE 488
# define KWPOINTERSIZE 489
# define KWOFFLINE 490
# define KWALLOCATE 491
# define KWENABLEALLOCATE 492
# define KWMANUAL 493
# define KWNOTIFY 494
# define KWNOTIFYFLAG 495
# define KWUSERMARSHAL 496
# define KWENCODE 497
# define KWDECODE 498
# define KWBITSET 499
# define UUIDTOKEN 500
# define VERSIONTOKEN 501
# define EOI 502
# define LASTTOKEN 503
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
extern YYSTYPE yylval;  /*CSD & DECUS LEX */
YYSTYPE yyval;          /*CSD & DECUS LEX */
# define YYERRCODE 256







short YYCONST yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 16,
	125, 40,
	-2, 9,
-1, 79,
	125, 39,
	-2, 9,
-1, 131,
	41, 83,
	-2, 9,
	};
# define YYNPROD 107
# define YYLAST 419
short YYCONST yyact[]={

  65,  66, 107, 108, 138, 154,  33,  13,  13,  32,
  23,  24,  25,  26,  27,  28,  29,  30,  31,  92,
 119, 116,  84,  22,  34, 158, 124, 125, 121,  85,
  88, 130, 123,  40, 128, 127, 129,   6, 104,  17,
  91, 150,  18,  43,  95,  13,  39,   5,  37, 153,
  41,  36,  35, 143,  81, 157, 144, 110,  89, 156,
 147, 146, 145, 142,  80, 141, 140, 135, 133, 132,
 131, 103, 102, 101, 100,  99,  98,  97,  96,  87,
  21,   3, 149, 148,  15, 106,   9,   8,  79, 126,
  54,  78,   4,  94,   2, 152,  19,  20,  49,  90,
  45,  86, 120,  16, 117, 114,  47,  50,  48,  82,
  42, 137,  10,  38,   7, 112,  77,  81, 136,  44,
  46, 122,   1,   0,   0,   0,   0, 105,   0,   0,
   0,   0,   0,   0, 113,   0, 109,   0,   0, 111,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0, 134,   0,   0,   0,   0, 139,   0,  72,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0, 151,
   0,  93, 118, 115,  83,   0,   0, 155,   0,   0,
   0,   0,   0,   0,   0,  67,  52,  53,  51,  55,
  57,  71,  58,  59,   0, 151,  69,  70,  62, 159,
  76,  61,  60,  73,  68,  74,  75,  56,  63,  64,
  12,  12,  33,   0,   0,  32,  23,  24,  25,  26,
  27,  28,  29,  30,  31,   0,   0,   0,   0,  22,
  34,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,  11,  11,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  14 };
short YYCONST yypact[]={

 -83,-1000, -84,-1000, -20,-1000,-215,  -7,  -8, -11,
-1000,-373, -46,-289,-1000,-1000, -83,-1000,-249,-394,
-421,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,  39,-379,-1000,-1000,-1000,  14,-1000,
-1000,-252,   0,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,  38,-1000,-1000,  37,  36,  35,-1000,-1000,
  34,-1000,-1000,-1000,-1000,-1000,-1000,  33,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,  32,  31, -87, -83,
-1000,-421,-1000,-1000,-1000,-1000,-1000,-426,-1000,-373,
  13,-1000,-1000,-1000,-1000,-289, -46,-250,-251,-395,
-397,-396,-248,-375,-1000,-1000,  30,  28,  27,-1000,
-252,-1000,  26,-267,  25,-1000,-1000,  24,-1000,-1000,
  22,-1000,  12,-1000,-1000,  21,  20,-1000,-1000,-1000,
  19, -46,-1000,-1000,-1000,-1000,-374,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-397,-1000,-1000,-1000,  18,  11,
-1000,-398,-1000,-1000,-1000,-1000,-1000, -46,-1000,-1000 };
short YYCONST yypgo[]={

   0, 122, 121,  32,  47, 120, 119, 118, 115, 114,
 113,  46,  43, 112, 110, 109, 108, 107,  37, 106,
 105, 104, 102,  40, 100,  99,  98,  80,  97,  96,
  95,  94,  81,  92,  91,  89,  88,  87,  86,  85,
  83,  82,  41 };
short YYCONST yyr1[]={

   0,   1,  31,  31,  32,  32,  32,  33,  18,  18,
  13,  14,  14,  12,  12,  12,  12,  12,  12,  12,
   5,   5,  17,  26,   6,   6,   6,   6,   8,  30,
  30,   7,   7,   7,  35,  35,  35,  15,  15,  34,
  34,  36,  36,   4,   4,   4,   9,  10,  10,  11,
  37,  25,  25,  23,  23,  24,  24,  24,  24,  24,
  24,  24,  24,  24,  24,  20,  20,  21,  21,  22,
   2,   2,   3,  39,  38,  16,  16,  16,  16,  16,
  16,  16,  40,  40,  41,  41,  42,  19,  19,  29,
  29,  28,  28,  27,  27,  27,  27,  27,  27,  27,
  27,  27,  27,  27,  27,  27,  27 };
short YYCONST yyr2[]={

   0,   2,   2,   1,   4,   2,   1,   3,   1,   0,
   3,   3,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   4,   4,   1,   4,   1,   1,   3,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   0,   2,   1,   2,   2,   2,   2,   3,   1,   1,
   3,   3,   1,   1,   1,   4,   4,   4,   1,   1,
   4,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   3,   1,   1,   0,   7,   1,   1,   1,   1,   1,
   1,   1,   1,   0,   3,   1,   2,   4,   1,   1,
   0,   2,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   4,   4,   2 };
short YYCONST yychk[]={

-1000,  -1, -31, -32, -33,  -4, -18,  -9, -37, -38,
 -13, 488, 294,  91, 502, -32, 123,  59, 257, -29,
 -28, -27, 444, 431, 432, 433, 434, 435, 436, 437,
 438, 439, 430, 427, 445,  59,  59,  59, -10, -11,
 406, -18, -14, -12,  -6, -24,  -5, -19, -16, -26,
 -17, 477, 475, 476, 379, 478, 496, 479, 481, 482,
 491, 490, 487, 497, 498, 289, 290, 474, 493, 485,
 486, 480, 447, 492, 494, 495, 489, 405, -34, -36,
  -4, -18, -15, 423, 271, 423, -27,  40, 409,  44,
 -25, -23, 271, 423,  93,  44,  40,  40,  40,  40,
  40,  40,  40,  40, 125,  -4, -39, 428, 429, -11,
  44, -12,  -8, -18, -20, 423, 271, -21, 423, 271,
 -22, 423,  -2,  -3, 423, 423, -35, 283, 282, 284,
 406,  40,  41,  41, -23,  41,  -7, 378, 271, 423,
  41,  41,  41,  41,  44,  41,  41,  41, -40, -41,
 -42, -18, -30, 423, 379,  -3,  41,  44, 423, -42 };
short YYCONST yydef[]={

   9,  -2,   9,   3,   0,   6,  90,   0,   0,   0,
   8,   0,   9,   0,   1,   2,  -2,   5,   0,   0,
  89,  92,  93,  94,  95,  96,  97,  98,  99, 100,
 101, 102, 103,   0,   0,  43,  44,  45,  46,  48,
  49,   0,   0,  12,  13,  14,  15,  16,  17,  18,
  19,  24,   0,  26,  27,   0,   0,   0,  58,  59,
   0,  61,  62,  63,  64,  20,  21,   0,  88,  75,
  76,  77,  78,  79,  80,  81,   0,   0,   0,  -2,
  42,  90,   7,  37,  38,  73,  91,   0, 106,   0,
  50,  52,  53,  54,  10,   0,   9,   0,   0,   0,
   0,   0,   0,   0,   4,  41,   0,   0,   0,  47,
   0,  11,   0,   0,   0,  65,  66,   0,  67,  68,
   0,  69,   0,  71,  72,   0,   0,  34,  35,  36,
   0,  -2, 104, 105,  51,  25,   0,  31,  32,  33,
  55,  56,  57,  60,   0,  87,  23,  22,   0,  82,
  85,   0,  28,  29,  30,  70,  74,   9,  86,  84 };
/* SCCSWHAT( "@(#)yypars.c	2.4 88/5/9 15:22:59	" ) */

static char *SCCSID = "@(#)yypars.c:1.3";
# define YYFLAG -1000
# define YYERROR goto yyerrlab
# define YYACCEPT return(0)
# define YYABORT return(1)

#ifdef YYDEBUG				/* RRR - 10/9/85 */
#define yyprintf(a, b, c, d, e) printf(a, b, c, d, e)
#else
#define yyprintf(a, b, c, d)
#endif

#ifndef YYPRINT
#define	YYPRINT	printf
#endif

#if ! defined YYSTATIC
#define YYSTATIC
#endif

/*	parser for yacc output	*/

#ifdef YYDEBUG
YYSTATIC int yydebug = 0; /* 1 for debugging */
#endif
extern YYSTYPE yyv[YYMAXDEPTH];	/* where the values are stored */
extern short	yys[YYMAXDEPTH];	/* the parse stack */
YYSTATIC int yychar = -1;			/* current input token number */
YYSTATIC int yynerrs = 0;			/* number of errors */
YYSTATIC short yyerrflag = 0;		/* error recovery flag */

#ifdef YYRECOVER
/*
**  yyscpy : copy f onto t and return a ptr to the null terminator at the
**  end of t.
*/
YYSTATIC	char	*yyscpy(t,f)
	register	char	*t, *f;
	{
	while(*t = *f++)
		t++;
	return(t);	/*  ptr to the null char  */
	}
#endif

#ifndef YYNEAR
#define YYNEAR
#endif
#ifndef YYPASCAL
#define YYPASCAL
#endif
#ifndef YYLOCAL
#define YYLOCAL
#endif
#if ! defined YYPARSER
#define YYPARSER yyparse
#endif
#if ! defined YYLEX
#define YYLEX yylex
#endif

static	void	yy_vc_init();
typedef	void	(*pfn)();
static	pfn	*	pcase_fn_array;
static	int		returnflag = 0;
static	YYSTYPE	*yypvt;
static	int		yym_vc_max = 0;
extern  short	GrammarAct;

extern short	yysavestate;

#define MAX_RECOVERY_ATTEMPTS	(50)
#define MAX_RETRY_COUNT			(3)
static short RetryCount = 0;
static short MaxRecoveryAttempts = 0;
static short fJustDiscarded = 0;

YYLOCAL YYNEAR YYPASCAL YYPARSER()
{
	register	short	yyn;
	short		yystate, *yyps, *yysave_yyps;
	YYSTYPE		*yypv,*yysave_yypv;
	YYSTYPE		yysave_yyval;
	short		yyj, yym;
	short		fHaveRecoveredChar	= 0;

	yy_vc_init();
#ifdef YYDEBUG
	yydebug = 1;
#endif /* YYDEBUG */

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps= &yys[-1];
	yypv= &yyv[-1];

 yystack:    /* put a state and value onto the stack */

	RetryCount = 0;

#ifdef YYDEBUG
	yyprintf( "[yydebug] state %d, char %d = %c\n", yystate, yychar,yychar, 0 );
#else /* YYDEBUG */
	yyprintf( "[yydebug] state %d, char %d\n", yystate, yychar, 0 );
#endif /* YYDEBUG */
	if( ++yyps > &yys[YYMAXDEPTH] ) {
/*		yyerror( "yacc stack overflow" ); */
		ParseError(C_STACK_OVERFLOW, (char *)NULL);
		return(1);
	}
	*yyps = yystate;
	++yypv;

#ifdef UNION
	yyunion(yypv, &yyval);
#else
	*yypv = yyval;
#endif

yynewstate:

	yysavestate	= yystate;
	yysave_yypv	= yypv;
	yysave_yyval= yyval;
	yysave_yyps	= yyps;

	yyn = yypact[yystate];

	if( yyn <= YYFLAG ) {	/*  simple state, no lookahead  */
		goto yydefault;
	}

	if( ! fHaveRecoveredChar )
		{
		if( yychar < 0 ) /*  need a lookahead */
			{
			yychar = YYLEX();
			}
		}

	fHaveRecoveredChar	= 0;

	if( ((yyn += yychar) < 0) || (yyn >= YYLAST) ) {
		goto yydefault;
	}

	if( yychk[ yyn = yyact[ yyn ] ] == yychar ) {		/* valid shift */
		yychar = -1;
#ifdef UNION
		yyunion(&yyval, &yylval);
#else
		yyval = yylval;
#endif
		yystate = yyn;
		if( yyerrflag > 0 ) {
			--yyerrflag;
		}
		goto yystack;
	}

 yydefault:
	/* default state action */

	if( (yyn = yydef[yystate]) == -2 ) {
		register	short	*yyxi;

		if( yychar < 0 ) {
			yychar = YYLEX();
		}
/*
**  search exception table, we find a -1 followed by the current state.
**  if we find one, we'll look through terminal,state pairs. if we find
**  a terminal which matches the current one, we have a match.
**  the exception table is when we have a reduce on a terminal.
*/

#if YYOPTTIME
		yyxi = yyexca + yyexcaind[yystate];
		while(( *yyxi != yychar ) && ( *yyxi >= 0 )){
			yyxi += 2;
		}
#else
		for(yyxi = (short *) yyexca;
			(*yyxi != (-1)) || (yyxi[1] != yystate);
			yyxi += 2
		) {
			; /* VOID */
			}

		while( *(yyxi += 2) >= 0 ){
			if( *yyxi == yychar ) {
				break;
				}
		}
#endif
		if( (yyn = yyxi[1]) < 0 ) {
			return(0);   /* accept */
			}
		}

	if( yyn == 0 ) /* error */
		{ 

		int yytempchar;


		if( (yychar != EOI ) &&
			 ( RetryCount < MAX_RETRY_COUNT ) &&
			 ( MaxRecoveryAttempts < MAX_RECOVERY_ATTEMPTS ) )
			{ 
			if( RetryCount == 0 )
				SyntaxError( BENIGN_SYNTAX_ERROR, yysavestate );

			if((( yytempchar = PossibleMissingToken( yysavestate, yychar ) ) != -1 ))
				{
				char Buf[ 50 ];


				fHaveRecoveredChar	= 1;
				yyunlex( yychar );
				yychar	= yytempchar;

				if( (yytempchar < 128 ) && isprint( yytempchar ) )
					{
					sprintf( Buf, " %c ", yytempchar );
					}
				else if( yytempchar == IDENTIFIER )
					{
					yylval.yy_pSymName = GenTempName();
					sprintf( Buf, " identifier %s", yylval.yy_pSymName );
					}
				else if( (yytempchar == NUMERICCONSTANT ) ||
						 (yytempchar == NUMERICLONGCONSTANT ) ||
						 (yytempchar == NUMERICULONGCONSTANT ) ||
						 (yytempchar == HEXCONSTANT ) ||
						 (yytempchar == HEXLONGCONSTANT ) ||
						 (yytempchar == HEXULONGCONSTANT ) )
					{
					sprintf( Buf, "a number" );
					yylval.yy_numeric.Val = 0;
					yylval.yy_numeric.pValStr = new char[2];
					strcpy( yylval.yy_numeric.pValStr, "0");
					}

				ParseError( ASSUMING_CHAR, Buf );
				RetryCount = 0;
				MaxRecoveryAttempts++;
				fJustDiscarded = 0;
				}
			else 
				{
				char buf[ 20 ];
				if( (yychar < 128 ) && isprint( yychar ) )
					{
					sprintf( buf, " %c ", yychar );
					}
				else
					{
					sprintf( buf, " the last token " );
					}

				ParseError( DISCARDING_CHAR, buf );
				yychar = -1;
				RetryCount++;
				MaxRecoveryAttempts++;
				fJustDiscarded = 1;
				}

			yystate	= yysavestate;
			yypv	= yysave_yypv;
			yyval	= yysave_yyval;
			yyps	= yysave_yyps;

			goto yynewstate;

			}
		else if( (yychar == EOI ) && (fJustDiscarded == 0 ) )
			{
			SyntaxError( UNEXPECTED_END_OF_FILE, yysavestate );
			return 1;
			}
		else
			{
			SyntaxError( SYNTAX_ERROR, yysavestate );
			return 1;
			}
		}

	/* reduction by production yyn */
/* yyreduce: */
		{
#ifdef YYDEBUG
		yyprintf("[yydebug] reduce %d\n",yyn, 0, 0, 0);
#else /* YYDEBUG */
		yyprintf("[yydebug] reduce %d\n",yyn, 0, 0);
#endif /* YYDEBUG */
		yypvt = yypv;
		yyps -= yyr2[yyn];
		yypv -= yyr2[yyn];
#ifdef UNION
		yyunion(&yyval, &yypv[1]);
#else
		yyval = yypv[1];
#endif
		yym = yyn;
		yyn = yyr1[yyn];		/* consult goto table to find next state */
		yyj = yypgo[yyn] + *yyps + 1;
		if( (yyj >= YYLAST) || (yychk[ yystate = yyact[yyj] ] != -yyn) ) {
			yystate = yyact[yypgo[yyn]];
			}
		returnflag = 0;
		GrammarAct = yym;
		(*(pcase_fn_array[ (yym <= yym_vc_max) ? yym : 0  ]))();
		if(returnflag != 0)
			return returnflag;
		}
		goto yystack;  /* stack new state and value */
	}

static void
case_fn_0002()


{
                if( !pCommand->IsSwitchDefined( SWITCH_MS_EXT ) )
                        {
                        ParseError( MULTIPLE_INTF_NON_OSF, NULL );
                        }
                }

static void
case_fn_0007()
{
                named_node              *       pNode;

                // the user MUST have defined the type.

                SymKey  SKey( yypvt[-0].yy_string, NAME_DEF );

                //Search for an interface_reference node in the symbol table.
                pNode = pBaseSymTbl->SymSearch( SKey );
                if ( pNode )
                        pNode = ( (node_interface_reference *)pNode )->GetRealInterface();

                //If the acf switch is specified and there is only one interface
                //in the IDL file, then tolerate mismatches in the interface name.
                if ( (!pNode) && pCommand->IsSwitchDefined( SWITCH_ACF ) )
                        {
                        node_file *pFileNode = pPass2->GetFileNode();
                        node_interface *pFirst;

                        pFirst = (node_interface *) pFileNode->GetFirstMember();

                        if(pFirst && pFirst->GetSibling())
                                pNode = 0;
                        else
                                pNode = pFirst;
                        }

                 if ( (!pNode) || ( !pNode->IsInterfaceOrObject() ) )
                        {
                        ParseError( ACF_INTERFACE_MISMATCH, yypvt[-0].yy_string );
                        returnflag = 1;
                        return;
                        }

                pCurInterfaceNode       = (node_interface *)pNode;

                if( yypvt[-2].yy_attrlist.NonNull() )
                        {
                        pCurInterfaceNode->AddAttributes( yypvt[-2].yy_attrlist );
                        if ( pCurInterfaceNode->FInSummary( ATTR_ENCODE ) ||
                             pCurInterfaceNode->FInSummary( ATTR_DECODE ) )
                            {
                            pCurInterfaceNode->SetPickleInterface();
                            }
                        }
                }

static void
case_fn_0009()
{
                yyval.yy_attrlist.MakeAttrList();
                }

static void
case_fn_0010()
{
                yyval.yy_attrlist = yypvt[-1].yy_attrlist;
                }

static void
case_fn_0011()
{
                (yyval.yy_attrlist     = yypvt[-2].yy_attrlist).SetPeer( yypvt[-0].yy_attr );
                }

static void
case_fn_0012()
{
                yyval.yy_attrlist.MakeAttrList( yypvt[-0].yy_attr );
                }

static void
case_fn_0013()
{
                yyval.yy_attr      = yypvt[-0].yy_attr;
                }

static void
case_fn_0014()
{
                yyval.yy_attr      = yypvt[-0].yy_attr;
                }

static void
case_fn_0015()
{
                yyval.yy_attr      = yypvt[-0].yy_attr;
                }

static void
case_fn_0016()
{
                yyval.yy_attr      = yypvt[-0].yy_attr;
                }

static void
case_fn_0017()
{
                yyval.yy_attr      = yypvt[-0].yy_attr;
                }

static void
case_fn_0018()
{
                ParseError(IGNORE_UNIMPLEMENTED_ATTRIBUTE, ((node_base_attr *)yypvt[-0].yy_attr)->GetNodeNameString());
                yyval.yy_attr = yypvt[-0].yy_attr;
                }

static void
case_fn_0019()
{
                yyval.yy_attr = yypvt[-0].yy_attr;
                }

static void
case_fn_0020()
{
                ParseError( IGNORE_UNIMPLEMENTED_ATTRIBUTE, "[short_enum]" );
                yyval.yy_attr = NULL;
                }

static void
case_fn_0021()
{
                ParseError( IGNORE_UNIMPLEMENTED_ATTRIBUTE, "[long_enum]" );
                yyval.yy_attr = NULL;
                }

static void
case_fn_0022()
{
		unsigned short OptFlags = OPTIMIZE_NONE;
		OPT_LEVEL_ENUM OptLevel;

		OptLevel = ParseAcfOptimizationAttr( yypvt[-1].yy_string, &OptFlags );
                yyval.yy_attr = new node_optimize( OptLevel, OptFlags );
                }

static void
case_fn_0023()
{
                yyval.yy_attr = new acf_attr( ATTR_PTRSIZE );
                }

static void
case_fn_0024()
{
                yyval.yy_attr      = new acf_attr( ATTR_EXPLICIT );
                }

static void
case_fn_0025()
{
                yyval.yy_attr = yypvt[-1].yy_attr;
                }

static void
case_fn_0026()
{
                yyval.yy_attr = new acf_attr( ATTR_AUTO );
                }

static void
case_fn_0027()
{
                yyval.yy_attr = new battr( ATTR_HANDLE );
                }

static void
case_fn_0028()
{
                node_id_fe      *               pId = new node_id_fe( yypvt[-0].yy_string );

                // if he has specified the handle attribute, the type must have
                // the handle attribute too!

                if( yypvt[-1].yy_graph && (yypvt[-1].yy_graph->NodeKind() == NODE_DEF) )
                        {
                        node_def *              pDef = (node_def *) yypvt[-1].yy_graph;
                        }
                else
                        {
                        if( yypvt[-1].yy_graph && (yypvt[-1].yy_graph->NodeKind() == NODE_FORWARD ) )
                                {
                                ParseError( IMPLICIT_HDL_ASSUMED_GENERIC,
                                                        ((node_forward *) yypvt[-1].yy_graph)->GetSymName());
                                }
                        }

                        //
                        // if the handle is a context handle type, disallow it. Do that only
                        // if the current interface node is the base interface node.
                        //


                pId->AddAttributes( yypvt[-2].yy_attrlist );

                // generate the new implicit handle attribute

                yyval.yy_attr = new node_implicit( yypvt[-1].yy_graph, pId );
                }

static void
case_fn_0029()
{
                yyval.yy_string      = yypvt[-0].yy_string;
                }

static void
case_fn_0030()
{
                yyval.yy_string      = "handle";
                }

static void
case_fn_0031()
{
                // return the base type node for handle_t
                GetBaseTypeNode( &(yyval.yy_graph),SIGN_UNDEF,SIZE_UNDEF,TYPE_HANDLE_T );
                }

static void
case_fn_0033()
{
                SymKey  SKey( yypvt[-0].yy_string, NAME_DEF );
                if( (yyval.yy_graph = pBaseSymTbl->SymSearch( SKey ) ) == (node_skl *)0 )
                        {
                        node_forward *          pFwd;

                        SymKey  SKey( yypvt[-0].yy_string, NAME_DEF );
                        pFwd    = new node_forward( SKey , pBaseSymTbl );
                        pFwd->SetSymName( yypvt[-0].yy_string );
                        yyval.yy_graph      = pFwd;
                        }
                }

static void
case_fn_0038()
{
                /** this production is necessitated for the hpp switch, which has the
                 ** interface name as a predefined type(def).
                 **/
                // yyval.yy_string   = yypvt[-0].yy_graph;
                yyval.yy_string = yypvt[-0].yy_graph->GetSymName();
                }

static void
case_fn_0046()
{
                yyval.yy_graph = yypvt[-0].yy_graph;
                }

static void
case_fn_0049()
{

                // add a file node to the acf includes list. This file node
                // must have a NODE_STATE_IMPORT for the backend to know that this
                // is to be emitted like an include. Make the file look like it
                // has been specified with an import level > 0


                unsigned short  importlvl       = pCurInterfaceNode->GetFileNode()->
                                                                                GetImportLevel();

                node_file       *       pFile = new node_file( yypvt[-0].yy_string, importlvl + 1);

                pPass2->InsertAcfIncludeFile( pFile );

                }

static void
case_fn_0050()
{
                node_def * pDef;

                if( yypvt[-1].yy_attrlist.NonNull() )
                        {
                        while( yypvt[-0].yy_tnlist->GetPeer( (node_skl **) &pDef ) == STATUS_OK )
                                {
                                pDef->AddAttributes( yypvt[-1].yy_attrlist );
                                if ( pDef->FInSummary( ATTR_ENCODE ) ||
                                     pDef->FInSummary( ATTR_DECODE ) )
                                    {
                                    pCurInterfaceNode->SetPickleInterface();
                                    }
                                }
                        }
                else
                        {
                        yypvt[-0].yy_tnlist->GetPeer( (node_skl **) &pDef );
                        if ( pDef )
                                ParseError( NO_ATTRS_ON_ACF_TYPEDEF, pDef->GetSymName() );
                        }
                }

static void
case_fn_0051()
{
                yyval.yy_tnlist = yypvt[-2].yy_tnlist;
                if ( yypvt[-0].yy_graph )
                        {
                        SymKey                  SKey( yypvt[-0].yy_graph->GetSymName(), NAME_DEF );
                        node_skl        *       pDef = (node_skl *) pBaseSymTbl->SymSearch( SKey );

                        // pDef will not be null.

                        yyval.yy_tnlist->SetPeer( pDef );
                        }
                }

static void
case_fn_0052()
{
                yyval.yy_tnlist      = new type_node_list;
                if( yypvt[-0].yy_graph )
                        yyval.yy_tnlist->SetPeer( yypvt[-0].yy_graph );
                }

static void
case_fn_0054()
{
                ParseError( UNDEFINED_TYPE, yypvt[-0].yy_string );
                yyval.yy_graph = (node_skl *)0;
                }

static void
case_fn_0055()
{
                yyval.yy_attr = yypvt[-1].yy_attr;
                }

static void
case_fn_0056()
{
                yyval.yy_attr = yypvt[-1].yy_attr;
                }

static void
case_fn_0057()
{
                yyval.yy_attr = yypvt[-1].yy_attr;
                }

static void
case_fn_0058()
{
                node_base_attr  *       pN = new acf_attr( ATTR_NONE );
                ParseError( IGNORE_UNIMPLEMENTED_ATTRIBUTE, "[inline]" );
                yyval.yy_attr = pN;
                }

static void
case_fn_0059()
{
                node_base_attr * pN = new acf_attr( ATTR_NONE );
                ParseError( IGNORE_UNIMPLEMENTED_ATTRIBUTE, "[out_of_line]" );
                yyval.yy_attr = pN;
                }

static void
case_fn_0060()
{
                node_allocate * pN      = new node_allocate( yypvt[-1].yy_short );
                ParseError( ALLOCATE_INVALID, pN->GetNodeNameString() );

#ifdef RPCDEBUG
                short s = pN->GetAllocateDetails();
#endif // RPCDEBUG
                yyval.yy_attr = pN;
                }

static void
case_fn_0061()
{
                ParseError( IGNORE_UNIMPLEMENTED_ATTRIBUTE, "offline" );
                yyval.yy_attr = new acf_attr( ATTR_NONE );
                }

static void
case_fn_0062()
{
                yyval.yy_attr = new acf_attr( ATTR_HEAP );
                }

static void
case_fn_0063()
{
                yyval.yy_attr = new acf_attr( ATTR_ENCODE );
                }

static void
case_fn_0064()
{
                yyval.yy_attr = new acf_attr( ATTR_DECODE );
                }

static void
case_fn_0065()
{
                // only non-typedefs get here, so it must be unknown...
                yyval.yy_attr = new node_represent_as( yypvt[-0].yy_string, NULL );
                }

static void
case_fn_0066()
{
                yyval.yy_attr = new node_represent_as( yypvt[-0].yy_graph->GetSymName(), yypvt[-0].yy_graph );
                }

static void
case_fn_0067()
{
                // only non-typedefs get here, so it must be unknown...
                yyval.yy_attr = new node_user_marshal( yypvt[-0].yy_string, NULL );
                }

static void
case_fn_0068()
{
                yyval.yy_attr = new node_user_marshal( yypvt[-0].yy_graph->GetSymName(), yypvt[-0].yy_graph );
                }

static void
case_fn_0069()
{
                // search for a matching proc in our interface

            SymKey              SKey( yypvt[-0].yy_string, NAME_PROC );

                named_node    *   pCur    =
                            pCurInterfaceNode->GetProcTbl()->SymSearch( SKey );

                yyval.yy_attr = new node_call_as( yypvt[-0].yy_string, pCur );
                }

static void
case_fn_0070()
{
                yyval.yy_short      |= yypvt[-0].yy_short;
                }

static void
case_fn_0072()
{
                yyval.yy_short = CheckValidAllocate( yypvt[-0].yy_string );
                }

static void
case_fn_0073()
{
                SymKey                  SKey( yypvt[-0].yy_string, NAME_PROC );

                // the proc must be defined in the idl file and it must not have the
                // local attribute

                if ( pCurInterfaceNode )
                        {
                        pAcfProc = (node_proc *)
                                   pCurInterfaceNode->GetProcTbl()->SymSearch( SKey );
                        }
                else
                        pAcfProc = NULL;

                if( pAcfProc )
                        {
                        if( pAcfProc->FInSummary( ATTR_LOCAL ) )
                                {
                                ParseError( LOCAL_PROC_IN_ACF, yypvt[-0].yy_string );
                                }
                        else
                                {

                                if(yypvt[-2].yy_attrlist)
                                    {
                                        pAcfProc->AddAttributes( yypvt[-2].yy_attrlist );
                                        if ( pAcfProc->FInSummary( ATTR_ENCODE ) ||
                                             pAcfProc->FInSummary( ATTR_DECODE ) )
                                            {
                                            pCurInterfaceNode->SetPickleInterface();
                                            }
                                        }

                                if ( yypvt[-1].yy_modifiers )
                                    pAcfProc->SetModifiers( yypvt[-1].yy_modifiers );

                                // prepare for parameter matching


                                iParam          = 0;
                                }
                        }
                else if ( pPass2->GetFileNode()->GetImportLevel() == 0 )
                        {
                        ParseError( UNDEFINED_PROC, yypvt[-0].yy_string );
                        }
                }

static void
case_fn_0074()
{
                pAcfProc = (node_proc *)NULL;
                }

static void
case_fn_0075()
{
                yyval.yy_attr = new acf_attr( ATTR_COMMSTAT );
                }

static void
case_fn_0076()
{
                yyval.yy_attr = new acf_attr( ATTR_FAULTSTAT );
                }

static void
case_fn_0077()
{
                yyval.yy_attr = new acf_attr( ATTR_CODE );
                }

static void
case_fn_0078()
{
                yyval.yy_attr = new acf_attr( ATTR_NOCODE );
                }

static void
case_fn_0079()
{
                yyval.yy_attr = new acf_attr( ATTR_ENABLE_ALLOCATE );
                }

static void
case_fn_0080()
{
                yyval.yy_attr = new acf_attr( ATTR_NOTIFY );
                }

static void
case_fn_0081()
{
                yyval.yy_attr = new acf_attr( ATTR_NOTIFY_FLAG );
                }

static void
case_fn_0082()
{
                /*************************************************************
                 *** we do not match parameters by number yet, so disable this
                if( iParam != cParams )
                        {
                        ParseError(PARAM_COUNT_MISMATCH, (char *)NULL );
                        }
                 *************************************************************/
                }

static void
case_fn_0083()
{
                /*************************************************************
                 *** we do not match parameters by number yet, so disable this
                if( cParams )
                        {
                        ParseError(PARAM_COUNT_MISMATCH, (char *)NULL );
                        }
                 *************************************************************/
                }

static void
case_fn_0084()
{
                iParam++;
                }

static void
case_fn_0085()
{
                iParam++;
                }

static void
case_fn_0086()
{
                // any ordering  of parameters is ok here...
                if( pAcfProc )
                        {
                        node_param      *       pParam;

                        if( (pParam = pAcfProc->GetParamNode( yypvt[-0].yy_string ) ) )
                                {
                                if( yypvt[-1].yy_attrlist.NonNull() )
                                        pParam->AddAttributes( yypvt[-1].yy_attrlist );
                                }
                        else if ( yypvt[-1].yy_attrlist.FInSummary( ATTR_COMMSTAT ) ||
                                          yypvt[-1].yy_attrlist.FInSummary( ATTR_FAULTSTAT ) )
                                {
                                // add parameter to end of param list
                                pAcfProc->AddStatusParam( yypvt[-0].yy_string, yypvt[-1].yy_attrlist );
                                }
                        else
                                ParseError( UNDEF_PARAM_IN_IDL, yypvt[-0].yy_string );
                        }
                }

static void
case_fn_0087()
{
                node_param      *       pParam          = NULL;

                if (pAcfProc)
                        {
                        pParam = pAcfProc->GetParamNode( yypvt[-1].yy_string );
                        }

                yyval.yy_attr      = new node_byte_count( pParam );
                }

static void
case_fn_0088()
{
                ParseError( IGNORE_UNIMPLEMENTED_ATTRIBUTE, "manual" );
                yyval.yy_attr = new acf_attr( ATTR_NONE );
                }

static void
case_fn_0090()
{
        yyval.yy_modifiers  = 0;
        }

static void
case_fn_0091()
{
        yyval.yy_modifiers  = yypvt[-1].yy_modifiers | yypvt[-0].yy_modifiers;
        }

static void
case_fn_0093()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_PASCAL);
                ParseError( BAD_CON_MSC_CDECL, "__pascal" );
                }

static void
case_fn_0094()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_FORTRAN);
                ParseError( BAD_CON_MSC_CDECL, "__fortran" );
                }

static void
case_fn_0095()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_CDECL);
                ParseError( BAD_CON_MSC_CDECL, "__cdecl" );
                }

static void
case_fn_0096()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_STDCALL);
                ParseError( BAD_CON_MSC_CDECL, "__stdcall" );
                }

static void
case_fn_0097()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_LOADDS);
                ParseError( BAD_CON_MSC_CDECL, "__loadds" );
                }

static void
case_fn_0098()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_SAVEREGS);
                ParseError( BAD_CON_MSC_CDECL, "__saveregs" );
                }

static void
case_fn_0099()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_FASTCALL);
                ParseError( BAD_CON_MSC_CDECL, "__fastcall" );
                }

static void
case_fn_0100()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_SEGMENT);
                ParseError( BAD_CON_MSC_CDECL, "__segment" );
                }

static void
case_fn_0101()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_INTERRUPT);
                ParseError( BAD_CON_MSC_CDECL, "__interrupt" );
                }

static void
case_fn_0102()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_SELF);
                ParseError( BAD_CON_MSC_CDECL, "__self" );
                }

static void
case_fn_0103()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_EXPORT);
                ParseError( BAD_CON_MSC_CDECL, "__export" );
                }

static void
case_fn_0104()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_DLLIMPORT);
                ParseError( BAD_CON_MSC_CDECL, "__declspec(dllimport)" );
                }

static void
case_fn_0105()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_DLLEXPORT);
                ParseError( BAD_CON_MSC_CDECL, "__declspec(dllexport)" );
                }

static void
case_fn_0106()
{
                yyval.yy_modifiers      = SetModifierBit(ATTR_NONE);
                ParseError( BAD_CON_MSC_CDECL, "__emit" );
                }
static void
case_fn_0000() {
	}

static void	 (*case_fn_array[])() = 
	{
	 case_fn_0000
	,case_fn_0000
	,case_fn_0002
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0007
	,case_fn_0000
	,case_fn_0009
	,case_fn_0010
	,case_fn_0011
	,case_fn_0012
	,case_fn_0013
	,case_fn_0014
	,case_fn_0015
	,case_fn_0016
	,case_fn_0017
	,case_fn_0018
	,case_fn_0019
	,case_fn_0020
	,case_fn_0021
	,case_fn_0022
	,case_fn_0023
	,case_fn_0024
	,case_fn_0025
	,case_fn_0026
	,case_fn_0027
	,case_fn_0028
	,case_fn_0029
	,case_fn_0030
	,case_fn_0031
	,case_fn_0000
	,case_fn_0033
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0038
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0000
	,case_fn_0046
	,case_fn_0000
	,case_fn_0000
	,case_fn_0049
	,case_fn_0050
	,case_fn_0051
	,case_fn_0052
	,case_fn_0000
	,case_fn_0054
	,case_fn_0055
	,case_fn_0056
	,case_fn_0057
	,case_fn_0058
	,case_fn_0059
	,case_fn_0060
	,case_fn_0061
	,case_fn_0062
	,case_fn_0063
	,case_fn_0064
	,case_fn_0065
	,case_fn_0066
	,case_fn_0067
	,case_fn_0068
	,case_fn_0069
	,case_fn_0070
	,case_fn_0000
	,case_fn_0072
	,case_fn_0073
	,case_fn_0074
	,case_fn_0075
	,case_fn_0076
	,case_fn_0077
	,case_fn_0078
	,case_fn_0079
	,case_fn_0080
	,case_fn_0081
	,case_fn_0082
	,case_fn_0083
	,case_fn_0084
	,case_fn_0085
	,case_fn_0086
	,case_fn_0087
	,case_fn_0088
	,case_fn_0000
	,case_fn_0090
	,case_fn_0091
	,case_fn_0000
	,case_fn_0093
	,case_fn_0094
	,case_fn_0095
	,case_fn_0096
	,case_fn_0097
	,case_fn_0098
	,case_fn_0099
	,case_fn_0100
	,case_fn_0101
	,case_fn_0102
	,case_fn_0103
	,case_fn_0104
	,case_fn_0105
	,case_fn_0106
	};

static void
yy_vc_init(){ pcase_fn_array = case_fn_array;
yym_vc_max = 106;
 }
