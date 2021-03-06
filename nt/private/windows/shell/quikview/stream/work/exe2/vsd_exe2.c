#include "vsp_exe2.h"
#include "vsdtop.h"


FILTER_DESC VwExeOverlayId[1] =
{
    { FI_EXECUTABLE, SO_WORDPROCESSOR, "Executable", },
};


VIEW_EXE_INIT ExeInit =
{
    {
        {INIT_HEADERINFO, 1, LINE_SIGNATURE},       //LINE_OLDEXEHDR
        {INIT_SIGNATURE, 1, LINE_LASTPAGE},         //LINE_SIGNATURE
        {INIT_LASTPAGE, 1, LINE_PAGES},             //LINE_LASTPAGE
        {INIT_TOTPAGES, 1, LINE_RELOCATEITEMS},     //LINE_PAGES
        {INIT_RELOCITEMS, 1, LINE_HDRPARAGRAPHS},   //LINE_RELOCATEITEMS
        {INIT_PARAINHEAD, 1, LINE_MINALLOC},        //LINE_HDRPARAGRAPHS
        {INIT_MINPARA, 1, LINE_MAXALLOC},           //LINE_MINALLOC
        {INIT_MAXPARA, 1, LINE_INITIALSS},          //LINE_MAXALLOC
        {INIT_INITSS, 1, LINE_INITIALSP},           //LINE_INITIALSS
        {INIT_INITSP, 1, LINE_CHECKSUM},            //LINE_INITIALSP
        {INIT_COMPCHKSUM, 1, LINE_INITIALIP},       //LINE_CHECKSUM
        {INIT_INITIP, 1, LINE_INITIALCS},           //LINE_INITIALIP
        {INIT_INITCODE, 1, LINE_RELOCATEOFFSET},    //LINE_INITIALCS
        {INIT_RELOCTABLE, 1, LINE_OVERLAYNO},       //LINE_RELOCATEOFFSET
        {INIT_OVERNUM, 1, LINE_RESERVED},           //LINE_OVERLAYNO
        {INIT_RESERVED, 4, LINE_NEWEXEPTR},         //LINE_RESERVED
        {INIT_OFFSET2HDR, 1, LINE_MEMORYNEEDED},    //LINE_NEWEXEPTR
        {INIT_MEMNEEDED, 1, (WORD)LINE_SECTBREAK}   //LINE_MEMORYNEEDED
    },
    {
        {INIT_GENINFO, 1, LINE_DESCRIPTION},        //LINE_NEWEXEHDR
        {INIT_MODNAME, 1, LINE_OPERATINGSYS},       //LINE_MODULENAME
        {INIT_DESCRIP, 1, LINE_MODULENAME},         //LINE_DESCRIPTION
        {INIT_OS, 1, LINE_WINDOWSVERSION},          //LINE_OPERATINGSYS
        {INIT_SIGNATURE, 1, LINE_LINKERVERSION},    //LINE_NEWSIGNATURE
        {INIT_LINKVER, 1, LINE_NEWCHECKSUM},        //LINE_LINKERVERSION
        {INIT_CHECKSUM, 1, LINE_AUTODATASEG},       //LINE_NEWCHECKSUM
        {INIT_ADS, 1, LINE_INITIALHEAP},            //LINE_AUTODATASEG
        {INIT_INITHS, 1, LINE_INITIALSTACK},        //LINE_INITIALHEAP
        {INIT_INITSS, 1, LINE_INITIALCSIP},         //LINE_INITIALSTACK
        {INIT_INITCSIP, 1, LINE_INITIALSSSP},       //LINE_INITIALCSIP
        {INIT_INITCSSP, 1, LINE_SEGMENTTABLE},      //LINE_INITIALSSSP
        {INIT_ADDNFO, 8, LINE_BEGINFASTLOAD},       //LINE_ADDITIONAL
        {INIT_FLOADSTART, 1, LINE_LENGTHFASTLOAD},  //LINE_BEGINFASTLOAD
        {INIT_FLOADLEN, 1, LINE_NEWSECTBREAK},      //LINE_LENGTHFASTLOAD
        {INIT_WINVER, 1, LINE_NEWSIGNATURE},        //LINE_WINDOWSVERSION
        {INIT_ENTRYTABLE, 1, LINE_NONRESTABLE},     //LINE_ENTRYTABLE
        {INIT_SEGTABLE, 1, LINE_RESOURCETABLE},     //LINE_SEGMENTTABLE
        {INIT_RESOURCETABLE, 1, LINE_RESIDENTTABLE},//LINE_RESOURCETABLE
        {INIT_RESTABLENAME, 1, LINE_MODULETABLE},   //LINE_RESIDENTTABLE
        {INIT_MODULEREF, 1, LINE_IMPORTTABLE},      //LINE_MODULETABLE
        {INIT_IMPORTEDTABLE, 1, LINE_ENTRYTABLE},   //LINE_IMPORTTABLE
        {INIT_NONRESTABLE, 1, LINE_MOVEABLE},       //LINE_NONRESTABLE
        {INIT_MOVEENPT, 1, LINE_ALIGNMENT},         //LINE_MOVEABLE
        {INIT_ALIGN, 1, LINE_FLAGS},                //LINE_ALIGNMENT
        {INIT_FLAGS, 16, LINE_ADDITIONAL},          //LINE_FLAGS
        {INIT_BLANK, 1, LINE_SECTBREAK}             //LINE_NEWSECTBREAK
    },
    {
        {INIT_IMAGEHEADER, 1, LINE_PE_SIGNATURE},
        {INIT_SIGNATURE, 1, LINE_MACHINE},
        {INIT_MACHINE, 1, LINE_NUM_SECTIONS},
        {INIT_NUMSECTION, 1, LINE_TIMEDATESTAMP},
        {INIT_TIMEDATE, 1, LINE_SYMBOLTABLE},
        {INIT_PSYMBOL, 1, LINE_NUM_SYMBOLS},
        {INIT_NUMSYMBOL, 1, LINE_SIZE_OP_HEADER},
        {INIT_SIZOPHEAD, 1, LINE_CHARACTERISTICS},
        {INIT_CHARACTER, 16, LINE_MAGIC},
        {INIT_MAGIC, 1, LINE_LINK},
        {INIT_LINKVER, 1, LINE_SIZEOFCODE},
        {INIT_SIZECODE, 1, LINE_SIZEOFINITDATA},
        {INIT_SIZINITDATA, 1, LINE_SIZEOF_UN_INITDATA},
        {INIT_SIZUNITDATA, 1, LINE_ADDRESS},
        {INIT_ADDRENTRY, 1, LINE_CODEBASE},
        {INIT_BASECODE, 1, LINE_DATABASE},
        {INIT_BASEDATA, 1, LINE_IMAGEBASE},
        {INIT_IMAGEBASE, 1, LINE_SECALIGN},
        {INIT_SECTALIGN, 1, LINE_FILEALIGN},
        {INIT_FILEALIGN, 1, LINE_OPSYSVER},
        {INIT_OSVER, 1, LINE_IMAGEVER},
        {INIT_IMAGEVER, 1, LINE_SUBVER},
        {INIT_SUBSYSVER, 1, LINE_IMAGESIZE},
        {INIT_SIZEIMAGE, 1, LINE_HEADERSIZE},
        {INIT_SIZEHEAD, 1, LINE_PECHECKSUM},
        {INIT_CHECKSUM, 1, LINE_SUBSYSTEM},
        {INIT_SUBSYS, 1, LINE_STACKRES},
        {INIT_SIZESTKR, 1, LINE_STACKCOM},
        {INIT_SIZESTKC, 1, LINE_HEAPRES},
        {INIT_SIZEHEAPR, 1, LINE_HEAPCOM},
        {INIT_SIZEHEAPC, 1, LINE_RVA},
        {INIT_SIZEDDIR, 1, LINE_DATADIR},
        {INIT_DATADIR, 1, LINE_PE_SECTBREAK},
        {INIT_BLANK, 1, LINE_SECTBREAK}
    },

    {
    {INIT_SECTTABLE, 1, LINE_PE_SEC_NAME},
        {INIT_SECTNAME, 1, LINE_VIRT_SIZE},
        {INIT_VIRTSIZE, 1, LINE_VIRT_ADDRESS},
        {INIT_VIRTADDR, 1, LINE_SIZEOF_RAW_DATA},
        {INIT_SIZERAWDATA, 1, LINE_PTR_RAW_DATA},
        {INIT_PRAWDATA, 1, LINE_PTR_RELOC},
        {INIT_PRELOC, 1, LINE_PTR_LINE_NUM},
        {INIT_PNLINES, 1, LINE_NUM_RELOC},
        {INIT_NUMRELOC, 1, LINE_NUM_LINE_NUM},
        {INIT_NUMLINES, 1, LINE_SEC_CHARACTERISTICS},
        {INIT_CHARACTER, 32, LINE_SEC_TABLEBREAK},
        {INIT_BLANK, 1, LINE_SECTBREAK}
    },

    {
    {INIT_EXPTABLE, 1, LINE_EXPORT_NAME},
        {INIT_NAME, 1, LINE_EXPORT_CHARACTERISTIC},
        {INIT_CHARACTER, 1, LINE_EXPORT_TIME_STAMP},
        {INIT_TIMEDATE, 1, LINE_EXPORT_VERSION},
        {INIT_VERSION, 1, LINE_EXPORT_BASE},
        {INIT_BASE, 1, LINE_EXPORT_NUM_FUNCTIONS},
        {INIT_NUMFUNCT, 1, LINE_EXPORT_NUM_NAMES},
        {INIT_NUMNAMES, 1, LINE_EXPORT_NAMES_ORDS},
        {INIT_BLANK, 1,  LINE_PE_EXPORT_BREAK},
        {INIT_BLANK, 1, LINE_SECTBREAK}
    },

    {
    {INIT_IMPTABLE, 1, LINE_IMPORTS_FROM},
        {INIT_BLANK, 1, LINE_IMPORTS_STUFF},
        {INIT_BLANK, 1,  LINE_IMPORTS_FUNCTION_NAME},
        {INIT_BLANK, 1,  LINE_PE_IMPORT_BREAK},
        {INIT_BLANK, 1, LINE_SECTBREAK}
    },
};

