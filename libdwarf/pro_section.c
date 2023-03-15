/*
  Copyright (C) 2000,2004,2006 Silicon Graphics, Inc.  All Rights Reserved.
  Portions Copyright (C) 2007-2019 David Anderson. All Rights Reserved.
  Portions Copyright 2002-2010 Sun Microsystems, Inc. All rights reserved.
  Portions Copyright 2012 SN Systems Ltd. All rights reserved.

  This program is free software; you can redistribute it
  and/or modify it under the terms of version 2.1 of the
  GNU Lesser General Public License as published by the Free
  Software Foundation.

  This program is distributed in the hope that it would be
  useful, but WITHOUT ANY WARRANTY; without even the implied
  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  Further, this software is distributed without any warranty
  that it is free of the rightful claim of any third person
  regarding infringement or the like.  Any license provided
  herein, whether implied or otherwise, applies only to this
  software file.  Patent licenses, if any, provided herein
  do not apply to combinations of this program with other
  software, or any other product whatsoever.

  You should have received a copy of the GNU Lesser General
  Public License along with this program; if not, write the
  Free Software Foundation, Inc., 51 Franklin Street - Fifth
  Floor, Boston MA 02110-1301, USA.

*/

#include "config.h"
#include "libdwarfdefs.h"
#include <stdio.h>
#ifdef HAVE_STRING_H
#include <string.h> 
#endif /* HAVE_STRING_H */
#ifdef   HAVE_ELFACCESS_H
#include <elfaccess.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_MALLOC_H
/* Useful include for some Windows compilers. */
#include <malloc.h>
#endif /* HAVE_MALLOC_H */
#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif /* HAVE_STDDEF_H */
#include "pro_incl.h"
#include "dwarf.h"
#include "libdwarf.h"
#include "pro_opaque.h"
#include "pro_error.h"
#include "pro_util.h"
#include "pro_encode_nm.h"
#include "pro_alloc.h"
#include "pro_section.h"
#include "pro_line.h"
#include "pro_frame.h"
#include "pro_die.h"
#include "pro_macinfo.h"
#include "pro_types.h"
#include "pro_dnames.h"


#ifndef SHN_UNDEF
#define SHN_UNDEF 0
#endif /* SHN_UNDEF */

#ifndef SHF_MIPS_NOSTRIP
/* if this is not defined, we probably don't need it: just use 0 */
#define SHF_MIPS_NOSTRIP 0
#endif
#ifndef R_MIPS_NONE
#define R_MIPS_NONE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
#ifdef WORDS_BIGENDIAN
#define ASNOUT(t,s,l)                       \
    do {                                    \
        unsigned sbyte = 0;                 \
        const char *p = 0;                  \
        if (l > sizeof(s)) {                \
            _dwarf_p_error(dbg, error, DW_DLE_DEBUG_FRAME_LENGTH_BAD);\
            return DW_DLV_ERROR;            \
        }                                   \
        sbyte = sizeof(s) - l;              \
        p = (const char *)(&s);             \
        dbg->de_copy_word(t,(const void *)(p+sbyte),l);\
    } while (0)
#else /* LITTLEENDIAN */
#define ASNOUT(t,s,l)                       \
    do {                                    \
        const char *p = 0;                  \
        if (l > sizeof(s)) {                \
            _dwarf_p_error(dbg, error, DW_DLE_DEBUG_FRAME_LENGTH_BAD);\
            return DW_DLV_ERROR;            \
        }                                   \
        p = (const char *)(&s);             \
        dbg->de_copy_word(t,(const void *)p,l); \
    } while (0)
#endif /* ENDIANNESS */


#define SIZEOFT32 4

<<<<<<< HEAD
=======
=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
struct Dwarf_Sort_Abbrev_s {
    Dwarf_Unsigned dsa_attr;
    Dwarf_Unsigned dsa_form;
    Dwarf_Signed dsa_implicitvalue;
    Dwarf_P_Attribute dsa_attrp;
};

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
/* Must match up with pro_section.h defines of DEBUG_INFO etc
and sectnames (below).  REL_SEC_PREFIX is either ".rel" or ".rela"
see pro_incl.h
*/
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
const char *_dwarf_rel_section_names[] = {
    REL_SEC_PREFIX ".debug_info",
    REL_SEC_PREFIX ".debug_line",
    REL_SEC_PREFIX ".debug_abbrev",     /* Nothing here refers to anything. */
<<<<<<< HEAD
=======
=======
const char* _dwarf_rel_section_names[] = {
    REL_SEC_PREFIX ".debug_info",
    REL_SEC_PREFIX ".debug_line",

    /* Nothing here refers to anything. */
    REL_SEC_PREFIX ".debug_abbrev",

>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    REL_SEC_PREFIX ".debug_frame",
    REL_SEC_PREFIX ".debug_aranges",
    REL_SEC_PREFIX ".debug_pubnames",
    REL_SEC_PREFIX ".debug_funcnames",  /* sgi extension */
    REL_SEC_PREFIX ".debug_typenames",  /* sgi extension */
    REL_SEC_PREFIX ".debug_varnames",   /* sgi extension */
    REL_SEC_PREFIX ".debug_weaknames",  /* sgi extension */
    REL_SEC_PREFIX ".debug_macinfo",
    REL_SEC_PREFIX ".debug_loc",
    REL_SEC_PREFIX ".debug_ranges",
    REL_SEC_PREFIX ".debug_types",      /* new in DWARF4 */
    REL_SEC_PREFIX ".debug_pubtypes",   /* new in DWARF3 */
    REL_SEC_PREFIX ".debug_names",      /* DWARF5 aka dnames */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    REL_SEC_PREFIX ".debug_str",        /* Nothing here refers to anything.*/
    REL_SEC_PREFIX ".debug_rnglists",   /* DWARF5. */
    REL_SEC_PREFIX ".debug_line_str",   /* DWARF5. Nothing referselsewhere */
    REL_SEC_PREFIX ".debug_macro",      /* DWARF5. */
    REL_SEC_PREFIX ".debug_loclists",   /* DWARF5. */
    REL_SEC_PREFIX ".debug_rnglists",   /* DWARF5. */
<<<<<<< HEAD
=======
=======

    /* Nothing here refers to anything.*/
    REL_SEC_PREFIX ".debug_str",

    REL_SEC_PREFIX ".debug_rnglists",   /* DWARF5. */

    /* DWARF5. Nothing referselsewhere */
    REL_SEC_PREFIX ".debug_line_str",

    REL_SEC_PREFIX ".debug_macro",      /* DWARF5. */
    REL_SEC_PREFIX ".debug_loclists",   /* DWARF5. */
    REL_SEC_PREFIX ".debug_rnglists",   /* DWARF5. */
    REL_SEC_PREFIX ".debug_sup",   /* DWARF5. No relocs on this */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
};

/*  names of sections. Ensure that it matches the defines
    in pro_section.h, in the same order
    Must match also _dwarf_rel_section_names above
*/
<<<<<<< HEAD
const char *_dwarf_sectnames[] = {
=======
<<<<<<< HEAD
const char *_dwarf_sectnames[] = {
=======
const char* _dwarf_sectnames[] = {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    ".debug_info",
    ".debug_line",
    ".debug_abbrev",
    ".debug_frame",
    ".debug_aranges",
    ".debug_pubnames",
    ".debug_funcnames",         /* sgi extension */
    ".debug_typenames",         /* sgi extension */
    ".debug_varnames",          /* sgi extension */
    ".debug_weaknames",         /* sgi extension */
    ".debug_macinfo",
    ".debug_loc",
    ".debug_ranges",
    ".debug_types",             /* new in DWARF4 */
    ".debug_pubtypes",          /* new in DWARF3 */
    ".debug_names",             /* new in DWARF5. aka dnames */
    ".debug_str",
    ".debug_line_str",          /* new in DWARF5 */
    ".debug_macro",             /* new in DWARF5 */
    ".debug_loclists",          /* new in DWARF5 */
    ".debug_rnglists",          /* new in DWARF5 */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
};




<<<<<<< HEAD
=======
=======
    ".debug_sup",               /* new in DWARF5 */
};

>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
static const Dwarf_Ubyte std_opcode_len[] = { 0, /* DW_LNS_copy */
    1,                          /* DW_LNS_advance_pc */
    1,                          /* DW_LNS_advance_line */
    1,                          /* DW_LNS_set_file */
    1,                          /* DW_LNS_set_column */
    0,                          /* DW_LNS_negate_stmt */
    0,                          /* DW_LNS_set_basic_block */
    0,                          /* DW_LNS_const_add_pc */
    1,                          /* DW_LNS_fixed_advance_pc */
    /*  The following for DWARF3 and DWARF4, though GNU
        uses these in DWARF2 as well. */
    0,                          /* DW_LNS_set_prologue_end */
    0,                          /* DW_LNS_set_epilogue_begin */
    1,                          /* DW_LNS_set_isa */
};

<<<<<<< HEAD
/*  struct to hold relocation entries. Its mantained as a linked
=======
<<<<<<< HEAD
/*  struct to hold relocation entries. Its mantained as a linked
=======
/*  struct to hold relocation entries. Its maintained as a linked
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    list of relocation structs, and will then be written at as a
    whole into the relocation section. Whether its 32 bit or
    64 bit will be obtained from Dwarf_Debug pointer.
*/

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
typedef struct Dwarf_P_Rel_s *Dwarf_P_Rel;
struct Dwarf_P_Rel_s {
    Dwarf_P_Rel dr_next;
    void *dr_rel_datap;
};
typedef struct Dwarf_P_Rel_Head_s *Dwarf_P_Rel_Head;
struct Dwarf_P_Rel_Head_s {
    struct Dwarf_P_Rel_s *drh_head;
    struct Dwarf_P_Rel_s *drh_tail;
};

static int
_dwarf_pro_generate_debug_line_str(Dwarf_P_Debug dbg,
    Dwarf_Signed *nbufs, Dwarf_Error * error);
static int _dwarf_pro_generate_debug_names(Dwarf_P_Debug dbg,
    Dwarf_Signed *nbufs, Dwarf_Error * error);
static int _dwarf_pro_generate_debug_str(Dwarf_P_Debug dbg,
    Dwarf_Signed *nbufs, Dwarf_Error * error);
static int _dwarf_pro_generate_debugline(Dwarf_P_Debug dbg,
    Dwarf_Signed *nbufs, Dwarf_Error * error);
static int _dwarf_pro_generate_debugframe(Dwarf_P_Debug dbg,
    Dwarf_Signed *nbufs, Dwarf_Error * error);
static int _dwarf_pro_generate_debuginfo(Dwarf_P_Debug dbg,
    Dwarf_Signed *nbufs, Dwarf_Error * error);

#if 0
static void
dump_bytes(char * msg,Dwarf_Small * start, long len)
{
    Dwarf_Small *end = start + len;
    Dwarf_Small *cur = start;

    printf("%s len %ld ",msg,len);
<<<<<<< HEAD
=======
=======
typedef struct Dwarf_P_Rel_s* Dwarf_P_Rel;
struct Dwarf_P_Rel_s {
    Dwarf_P_Rel dr_next;
    void* dr_rel_datap;
};
typedef struct Dwarf_P_Rel_Head_s* Dwarf_P_Rel_Head;
struct Dwarf_P_Rel_Head_s {
    struct Dwarf_P_Rel_s* drh_head;
    struct Dwarf_P_Rel_s* drh_tail;
};

static int _dwarf_pro_generate_debug_line_str(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs, Dwarf_Error* error);
static int _dwarf_pro_generate_dnames(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs, Dwarf_Error* error);
static int _dwarf_pro_generate_debug_str(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs, Dwarf_Error* error);
static int _dwarf_pro_generate_debugline(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs, Dwarf_Error* error);
static int _dwarf_pro_generate_debugframe(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs, Dwarf_Error* error);
static int _dwarf_pro_generate_debuginfo(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs, Dwarf_Error* error);
static int _dwarf_pro_generate_debugsup(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs, Dwarf_Error* error);

#if 0
static void
dump_bytes(char* msg, Dwarf_Small* start, long len)
{
    Dwarf_Small* end = start + len;
    Dwarf_Small* cur = start;

    printf("%s len %ld ", msg, len);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    for (; cur < end; cur++) {
        printf("%02x ", *cur);
    }
    printf("\n");
}
#endif

#if 0
static void
print_single_abbrev(Dwarf_P_Abbrev c, unsigned idx)
{
    unsigned j = 0;

<<<<<<< HEAD
    printf(" %2u idx %2u tag 0x%x attrct %2u\n",idx,
=======
<<<<<<< HEAD
    printf(" %2u idx %2u tag 0x%x attrct %2u\n",idx,
=======
    printf(" %2u idx %2u tag 0x%x attrct %2u\n", idx,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        (unsigned)c->abb_idx,
        (unsigned)c->abb_tag,
        (unsigned)c->abb_n_attr);

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    for ( ; j < (unsigned)c->abb_n_attr; ++j) {
        printf("  %2u attr 0x%2x  form 0x%2x impl val %" DW_PR_DSd "\n",
            j,
            (unsigned)c->abb_attrs[j],
            (unsigned)c->abb_forms[j]);
            (unsigned)c->abb_implicits[j]);
    }
}
static void
print_curabbrev(const char *where,
<<<<<<< HEAD
=======
=======
    for (; j < (unsigned)c->abb_n_attr; ++j) {
        printf("  %2u attr 0x%2x  form 0x%2x impl val %"
            DW_PR_DSd "\n",
            j,
            (unsigned)c->abb_attrs[j],
            (unsigned)c->abb_forms[j]);
        (unsigned)c->abb_implicits[j]);
    }
}
static void
print_curabbrev(const char* where,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_P_Abbrev curabbrev)
{
    Dwarf_P_Abbrev ca = 0;
    unsigned i = 0;
<<<<<<< HEAD
    for(ca = curabbrev; ca ; ca = ca->abb_next,++i) {
        printf("ABBREV %u from %s\n",i,where);
        print_single_abbrev(ca,i);
=======
<<<<<<< HEAD
    for(ca = curabbrev; ca ; ca = ca->abb_next,++i) {
        printf("ABBREV %u from %s\n",i,where);
        print_single_abbrev(ca,i);
=======
    for (ca = curabbrev; ca; ca = ca->abb_next, ++i) {
        printf("ABBREV %u from %s\n", i, where);
        print_single_abbrev(ca, i);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    }
}
#endif

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
/* These macros used as return value for _dwarf_pro_get_opc. */
#define         OPC_INCS_ZERO           -1
#define         OPC_OUT_OF_RANGE        -2
#define         LINE_OUT_OF_RANGE       -3
/*  Given address advance and line advance, it gives
    either special opcode, or a number < 0

    FIXME: Check all three negative values.
    Are any negatives really hard errors?
*/
static int
_dwarf_pro_get_opc(
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits,
=======
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits,
=======
    struct Dwarf_P_Line_Inits_s* inits,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Unsigned addr_adv,
    int line_adv)
{
    int line_base = inits->pi_line_base;
<<<<<<< HEAD
    int line_range =inits->pi_line_range;
=======
<<<<<<< HEAD
    int line_range =inits->pi_line_range;
=======
    int line_range = inits->pi_line_range;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Unsigned factored_adv = 0;

    factored_adv = addr_adv / inits->pi_minimum_instruction_length;
    if (line_adv == 0 && factored_adv == 0) {
        return OPC_INCS_ZERO;
    }
    if (line_adv >= line_base && line_adv < line_base + line_range) {
        int opc = 0;

        opc = (line_adv - line_base) +
            (factored_adv * line_range) +
            inits->pi_opcode_base;
        if (opc > 255) {
            return OPC_OUT_OF_RANGE;
        }
        return opc;
    }
    return LINE_OUT_OF_RANGE;
}

<<<<<<< HEAD


/*  OFFSET_PLUS_EXTENSION_SIZE is the size of the 'length' field in total.
=======
<<<<<<< HEAD


/*  OFFSET_PLUS_EXTENSION_SIZE is the size of the 'length' field in total.
=======
/*  OFFSET_PLUS_EXTENSION_SIZE is the size of the
    'length' field in total.
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Which may be 4,8, or 12 bytes!
    4 is standard DWARF2.
    8 is non-standard MIPS-IRIX 64-bit.
    12 is standard DWARF3 for 64 bit offsets.
    Used in various routines: local variable names
    must match the names here.
*/
#define OFFSET_PLUS_EXTENSION_SIZE (offset_size + extension_size)

/*  Return TRUE if we need the section, FALSE otherwise

    If any of the 'line-data-related' calls were made
    including file or directory entries,
    produce .debug_line .

*/
static int
dwarf_need_debug_line_section(Dwarf_P_Debug dbg)
{
    if (dbg->de_output_version > 4) {
        return FALSE;
    }
    if (dbg->de_lines == NULL && dbg->de_file_entries == NULL
        && dbg->de_inc_dirs == NULL) {
        return FALSE;
    }
    return TRUE;
}

/*  DWARF5 only. */
static int
dwarf_need_debug_names_section(Dwarf_P_Debug dbg)
{
<<<<<<< HEAD
    if (dbg->de_output_version <  5) {
=======
<<<<<<< HEAD
    if (dbg->de_output_version <  5) {
=======
    if (dbg->de_output_version < 5) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        return FALSE;
    }
    if (!dbg->de_dnames) {
        return FALSE;
    }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    if (!dbg->de_dnames->dn_create_section) {
        return FALSE;
    }
    return TRUE;
<<<<<<< HEAD
=======
=======
    return dbg->de_force_dnames;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
}

/*  Convert debug information to  a format such that
    it can be written on disk.
    Called exactly once per execution.
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    This is the traditional interface. Bad interface design.
*/
Dwarf_Signed
dwarf_transform_to_disk_form(Dwarf_P_Debug dbg, Dwarf_Error * error)
<<<<<<< HEAD
=======
=======
*/

Dwarf_Signed
dwarf_transform_to_disk_form(Dwarf_P_Debug dbg, Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    Dwarf_Signed count = 0;
    int res = 0;

<<<<<<< HEAD
    res = dwarf_transform_to_disk_form_a(dbg, &count,error);
=======
<<<<<<< HEAD
    res = dwarf_transform_to_disk_form_a(dbg, &count,error);
=======
    res = dwarf_transform_to_disk_form_a(dbg, &count, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    if (res == DW_DLV_ERROR) {
        return DW_DLV_NOCOUNT;
    }
    return count;
}
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
/*  Convert debug information to  a format such that
    it can be written on disk.
    Called exactly once per execution.
    This is the interface design used with the consumer
    interface, so easier for callers to work with.
*/
int
dwarf_transform_to_disk_form_a(Dwarf_P_Debug dbg, Dwarf_Signed *count,
    Dwarf_Error * error)
{
    /*  Section data in written out in a number of buffers. Each
        _generate_*() function returns a cumulative count of buffers for
<<<<<<< HEAD
=======
=======

int
dwarf_transform_to_disk_form_a(Dwarf_P_Debug dbg, Dwarf_Signed* count,
    Dwarf_Error* error)
{
    /*  Section data in written out in a number of buffers. Each
        _generate_*() function returns a cumulative
        count of buffers for
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        all the sections.
        dwarf_get_section_bytes() returns pointers to these
        buffers one at a time. */
    Dwarf_Signed nbufs = 0;
    int sect = 0;
    int err = 0;
    Dwarf_Unsigned du = 0;

    if (dbg->de_version_magic_number != PRO_VERSION_MAGIC) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_IA, DW_DLV_ERROR);
    }

    /* Create dwarf section headers */
    for (sect = 0; sect < NUM_DEBUG_SECTIONS; sect++) {
        long flags = 0;

        switch (sect) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
        case DEBUG_SUP:
            if (!dbg->de_debug_sup.ds_version) {
                continue;
            }
            break;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

        case DEBUG_INFO:
            if (dbg->de_dies == NULL) {
                continue;
            }
            break;

        case DEBUG_LINE:
            if (dwarf_need_debug_line_section(dbg) == FALSE) {
                continue;
            }
            break;

        case DEBUG_ABBREV:
            if (dbg->de_dies == NULL) {
                continue;
            }
            break;

        case DEBUG_FRAME:
            if (dbg->de_frame_cies == NULL) {
                continue;
            }
            flags = SHF_MIPS_NOSTRIP;
            break;

        case DEBUG_ARANGES:
            if (dbg->de_arange == NULL) {
                continue;
            }
            break;

        case DEBUG_PUBNAMES:
            if (dbg->de_simple_name_headers[dwarf_snk_pubname].
                sn_head == NULL) {
                continue;
            }
            break;
        case DEBUG_PUBTYPES:
            if (dbg->de_simple_name_headers[dwarf_snk_pubtype].
                sn_head == NULL) {
                continue;
            }
            break;

        case DEBUG_STR:
            if (dbg->de_debug_str->ds_data == NULL) {
                continue;
            }
            break;

        case DEBUG_FUNCNAMES:
            if (dbg->de_simple_name_headers[dwarf_snk_funcname].
                sn_head == NULL) {
                continue;
            }
            break;

        case DEBUG_TYPENAMES:
            if (dbg->de_simple_name_headers[dwarf_snk_typename].
                sn_head == NULL) {
                continue;
            }
            break;

        case DEBUG_VARNAMES:
            if (dbg->de_simple_name_headers[dwarf_snk_varname].
                sn_head == NULL) {
                continue;
            }
            break;

        case DEBUG_WEAKNAMES:
            if (dbg->de_simple_name_headers[dwarf_snk_weakname].
                sn_head == NULL) {
                continue;
            }
            break;

        case DEBUG_MACINFO:
            if (dbg->de_first_macinfo == NULL) {
                continue;
            }
            break;
        case DEBUG_NAMES: /* DWARF5 */
            if (dwarf_need_debug_names_section(dbg) == FALSE) {
                continue;
            }
            break;
        case DEBUG_LOC:
            /* Not handled yet. */
            continue;
        case DEBUG_RANGES:
            /* Not handled yet. */
            continue;
        case DEBUG_TYPES:
            /* Not handled yet. */
            continue;
        case DEBUG_MACRO:
            /* Not handled yet. */
            continue;
        case DEBUG_LOCLISTS:
            /* Not handled yet. */
            continue;
        case DEBUG_RNGLISTS:
            /* Not handled yet. */
            continue;
        case DEBUG_LINE_STR:
            if (dwarf_need_debug_line_section(dbg) == FALSE) {
                continue;
            }
            /* Not handled yet. */
            continue;
        default:
            /* logic error: missing a case */
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ELF_SECT_ERR, DW_DLV_ERROR);
        }
        {
            int new_base_elf_sect = 0;

            if (dbg->de_callback_func) {
                new_base_elf_sect =
                    dbg->de_callback_func(_dwarf_sectnames[sect],
                        /* rec size */ 1,
                        SECTION_TYPE,
                        flags, SHN_UNDEF, 0, &du,
                        dbg->de_user_data, &err);
            }
            if (new_base_elf_sect == -1) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_ELF_SECT_ERR,
                    DW_DLV_ERROR);
            }
            dbg->de_elf_sects[sect] = new_base_elf_sect;
            dbg->de_sect_name_idx[sect] = du;
        }
    }

    nbufs = 0;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    /*  Changing the order in which the sections are generated may cause
        problems because of relocations. */

    if (dwarf_need_debug_line_section(dbg) == TRUE) {
        int res = _dwarf_pro_generate_debugline(dbg,&nbufs, error);
<<<<<<< HEAD
=======
=======
    /*  Changing the order in which the sections
        are generated may cause
        problems because of relocations. */

    if (dbg->de_debug_sup.ds_version) {
        int res = _dwarf_pro_generate_debugsup(dbg,
            &nbufs, error);
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }

    if (dwarf_need_debug_line_section(dbg) == TRUE) {
        int res = _dwarf_pro_generate_debugline(dbg, &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }

    if (dbg->de_frame_cies) {
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debugframe(dbg,&nbufs,error);
=======
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debugframe(dbg,&nbufs,error);
=======
        int res = _dwarf_pro_generate_debugframe(dbg, &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }
    if (dbg->de_first_macinfo) {
        /* For DWARF 2,3,4 only */
        /* Need new code for DWARF5 macro info. FIXME*/
<<<<<<< HEAD
        int res  = _dwarf_pro_transform_macro_info_to_disk(dbg,
            &nbufs,error);
=======
<<<<<<< HEAD
        int res  = _dwarf_pro_transform_macro_info_to_disk(dbg,
            &nbufs,error);
=======
        int res = _dwarf_pro_transform_macro_info_to_disk(dbg,
            &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }

    if (dbg->de_dies) {
<<<<<<< HEAD
        int res= _dwarf_pro_generate_debuginfo(dbg, &nbufs, error);
=======
<<<<<<< HEAD
        int res= _dwarf_pro_generate_debuginfo(dbg, &nbufs, error);
=======
        int res = _dwarf_pro_generate_debuginfo(dbg, &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }

    if (dbg->de_debug_str->ds_data) {
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_str(dbg,&nbufs, error);
=======
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_str(dbg,&nbufs, error);
=======
        int res = _dwarf_pro_generate_debug_str(dbg, &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }
    if (dbg->de_debug_line_str->ds_data) {
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_line_str(dbg,&nbufs, error);
=======
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_line_str(dbg,&nbufs, error);
=======
        int res = _dwarf_pro_generate_debug_line_str(dbg, &nbufs,
            error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)


    if (dbg->de_arange) {
        int res = _dwarf_transform_arange_to_disk(dbg,&nbufs, error);
<<<<<<< HEAD
=======
=======
    if (dbg->de_arange) {
        int res = _dwarf_transform_arange_to_disk(dbg, &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }
    if (dbg->de_output_version < 5) {
        if (dbg->de_simple_name_headers[dwarf_snk_pubname].sn_head) {
            int res = _dwarf_transform_simplename_to_disk(dbg,
                dwarf_snk_pubname,
                DEBUG_PUBNAMES,
                &nbufs,
                error);
            if (res == DW_DLV_ERROR) {
                return res;
            }
        }
        if (dbg->de_simple_name_headers[dwarf_snk_pubtype].sn_head) {
            int res = _dwarf_transform_simplename_to_disk(dbg,
                dwarf_snk_pubtype,
                DEBUG_PUBTYPES,
                &nbufs,
                error);
            if (res == DW_DLV_ERROR) {
                return res;
            }
        }

        if (dbg->de_simple_name_headers[dwarf_snk_funcname].sn_head) {
            int res = _dwarf_transform_simplename_to_disk(dbg,
                dwarf_snk_funcname,
                DEBUG_FUNCNAMES,
                &nbufs,
                error);
            if (res == DW_DLV_ERROR) {
                return res;
            }
        }

        if (dbg->de_simple_name_headers[dwarf_snk_typename].sn_head) {
            int res = _dwarf_transform_simplename_to_disk(dbg,
                dwarf_snk_typename,
                DEBUG_TYPENAMES,
                &nbufs,
                error);
            if (res == DW_DLV_ERROR) {
                return res;
            }
        }

        if (dbg->de_simple_name_headers[dwarf_snk_varname].sn_head) {
            int res = _dwarf_transform_simplename_to_disk(dbg,
                dwarf_snk_varname,
                DEBUG_VARNAMES,
                &nbufs,
                error);
            if (res == DW_DLV_ERROR) {
                return res;
            }
        }

        if (dbg->de_simple_name_headers[dwarf_snk_weakname].sn_head) {
            int res = _dwarf_transform_simplename_to_disk(dbg,
                dwarf_snk_weakname, DEBUG_WEAKNAMES,
                &nbufs,
                error);
            if (res == DW_DLV_ERROR) {
                return res;
            }
        }
    }
    if (dwarf_need_debug_names_section(dbg) == TRUE) {
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_names(dbg,&nbufs, error);
=======
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_names(dbg,&nbufs, error);
=======
        int res = _dwarf_pro_generate_dnames(dbg, &nbufs,
            error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }
#if 0  /* FIXME: TODO new sections */
    if (dwarf_need_debug_macro_section(dbg) == TRUE) {
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_macro(dbg,&nbufs, error);
=======
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_macro(dbg,&nbufs, error);
=======
        int res = _dwarf_pro_generate_debug_macro(dbg, &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }
    if (dwarf_need_debug_loclists_section(dbg) == TRUE) {
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_loclists(dbg,&nbufs, error);
=======
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_loclists(dbg,&nbufs, error);
=======
        int res = _dwarf_pro_generate_debug_loclists(dbg,
            &nbufs, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }
    if (dwarf_need_debug_rnglists_section(dbg) == TRUE) {
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_rnglists(dbg,&nbufs, error);
=======
<<<<<<< HEAD
        int res = _dwarf_pro_generate_debug_rnglists(dbg,&nbufs, error);
=======
        int res = _dwarf_pro_generate_debug_rnglists(dbg, &nbufs,
            error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res == DW_DLV_ERROR) {
            return res;
        }
    }
#endif

    {
        Dwarf_Signed new_chunks = 0;
        int res = 0;

        res = dbg->de_transform_relocs_to_disk(dbg, &new_chunks);
        if (res != DW_DLV_OK) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_RELOCS_ERROR,
                DW_DLV_ERROR);
        }
        nbufs += new_chunks;
    }
    *count = nbufs;
    return DW_DLV_OK;
}

static int
write_fixed_size(Dwarf_Unsigned val,
    Dwarf_P_Debug dbg,
    int elfsectno,
    Dwarf_Unsigned size,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned * size_out,
    Dwarf_Error* error)
{
    unsigned char *data = 0;
    GET_CHUNK_ERR(dbg, elfsectno, data, size, error);
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &val,
<<<<<<< HEAD
=======
=======
    unsigned* size_out,
    Dwarf_Error* error)
{
    unsigned char* data = 0;
    GET_CHUNK_ERR(dbg, elfsectno, data, size, error);
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&val,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof(val), size);
    *size_out = size;
    return DW_DLV_OK;
}

static int
write_ubyte(unsigned val,
    Dwarf_P_Debug dbg,
    int elfsectno,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned *len_out,
    Dwarf_Error* error)
{
    Dwarf_Ubyte db = val;
    unsigned char *data = 0;
    unsigned len = sizeof(Dwarf_Ubyte);
    GET_CHUNK_ERR(dbg, elfsectno, data,
        len, error);
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
<<<<<<< HEAD
=======
=======
    unsigned* len_out,
    Dwarf_Error* error)
{
    Dwarf_Ubyte db = val;
    unsigned char* data = 0;
    unsigned len = sizeof(Dwarf_Ubyte);
    GET_CHUNK_ERR(dbg, elfsectno, data,
        len, error);
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof(db), len);
    *len_out = 1;
    return DW_DLV_OK;;
}
static int
pretend_write_uval(Dwarf_Unsigned val,
    Dwarf_P_Debug dbg,
<<<<<<< HEAD
    unsigned *uval_len_out,
=======
<<<<<<< HEAD
    unsigned *uval_len_out,
=======
    unsigned* uval_len_out,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Error* error)
{
    char buff1[ENCODE_SPACE_NEEDED];
    int nbytes = 0;
    int res = 0;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    res = _dwarf_pro_encode_leb128_nm(val,
        &nbytes, buff1,
        sizeof(buff1));
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg,DW_DLE_LEB_OUT_ERROR , DW_DLV_ERROR);
<<<<<<< HEAD
=======
=======
    res = dwarf_encode_leb128(val,
        &nbytes, buff1,
        sizeof(buff1));
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    }
    *uval_len_out = nbytes;
    return DW_DLV_OK;
}

static int
write_sval(Dwarf_Signed val,
    Dwarf_P_Debug dbg,
    int elfsectno,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned *sval_len_out,
    Dwarf_Error* error)
{
    char buff1[ENCODE_SPACE_NEEDED];
    unsigned char *data = 0;
    int nbytes = 0;
    int res =  _dwarf_pro_encode_signed_leb128_nm(val,
<<<<<<< HEAD
=======
=======
    unsigned* sval_len_out,
    Dwarf_Error* error)
{
    char buff1[ENCODE_SPACE_NEEDED];
    unsigned char* data = 0;
    int nbytes = 0;
    int res = dwarf_encode_signed_leb128(val,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        &nbytes, buff1,
        sizeof(buff1));
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
    }
    GET_CHUNK(dbg, elfsectno, data, nbytes, error);
<<<<<<< HEAD
    memcpy((void *) data, (const void *) buff1, nbytes);
=======
<<<<<<< HEAD
    memcpy((void *) data, (const void *) buff1, nbytes);
=======
    memcpy((void*)data, (const void*)buff1, nbytes);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    *sval_len_out = nbytes;
    return DW_DLV_OK;
}

/*  This one does not allocate a chunk, uses
    an already existing chunk.
    data points into that existing chunk. */
static int
append_uval(Dwarf_Unsigned val,
    Dwarf_P_Debug dbg,
<<<<<<< HEAD
    unsigned char *data,
    unsigned * uval_len_out,
=======
<<<<<<< HEAD
    unsigned char *data,
    unsigned * uval_len_out,
=======
    unsigned char* data,
    unsigned* uval_len_out,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Error* error)
{
    char buff1[ENCODE_SPACE_NEEDED];
    int nbytes = 0;
<<<<<<< HEAD
    int res =  _dwarf_pro_encode_leb128_nm(val,
=======
<<<<<<< HEAD
    int res =  _dwarf_pro_encode_leb128_nm(val,
=======
    int res = dwarf_encode_leb128(val,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        &nbytes, buff1,
        sizeof(buff1));
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
    }
<<<<<<< HEAD
    memcpy((void *) data, (const void *) buff1, nbytes);
=======
<<<<<<< HEAD
    memcpy((void *) data, (const void *) buff1, nbytes);
=======
    memcpy((void*)data, (const void*)buff1, nbytes);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    *uval_len_out = nbytes;
    return DW_DLV_OK;
}

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
static int
write_uval(Dwarf_Unsigned val,
    Dwarf_P_Debug dbg,
    int elfsectno,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned * uval_len_out,
    Dwarf_Error* error)
{
    char buff1[ENCODE_SPACE_NEEDED];
    unsigned char *data = 0;
    int nbytes = 0;
    int res =  _dwarf_pro_encode_leb128_nm(val,
<<<<<<< HEAD
=======
=======
    unsigned* uval_len_out,
    Dwarf_Error* error)
{
    char buff1[ENCODE_SPACE_NEEDED];
    unsigned char* data = 0;
    int nbytes = 0;
    int res = dwarf_encode_leb128(val,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        &nbytes, buff1,
        sizeof(buff1));
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
    }
    GET_CHUNK_ERR(dbg, elfsectno, data, nbytes, error);
<<<<<<< HEAD
    memcpy((void *) data, (const void *) buff1, nbytes);
=======
<<<<<<< HEAD
    memcpy((void *) data, (const void *) buff1, nbytes);
=======
    memcpy((void*)data, (const void*)buff1, nbytes);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    *uval_len_out = nbytes;
    return DW_DLV_OK;
}

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
static unsigned
write_opcode_uval(int opcode,
    Dwarf_P_Debug dbg,
    int elfsectno,
    Dwarf_Unsigned val,
<<<<<<< HEAD
    unsigned *len_out,
=======
<<<<<<< HEAD
    unsigned *len_out,
=======
    unsigned* len_out,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Error* error)
{
    unsigned ublen = 0;
    int res = 0;
    unsigned uvlen = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    res  = write_ubyte(opcode,dbg,elfsectno,&ublen,error);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
    }
    res = write_uval(val,dbg,elfsectno,&uvlen,error);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
    }
    *len_out = ublen +uvlen;
<<<<<<< HEAD
=======
=======
    res = write_ubyte(opcode, dbg, elfsectno, &ublen, error);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
    }
    res = write_uval(val, dbg, elfsectno, &uvlen, error);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LEB_OUT_ERROR, DW_DLV_ERROR);
    }
    *len_out = ublen + uvlen;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    return DW_DLV_OK;
}

static int
determine_form_size(Dwarf_P_Debug dbg,
    unsigned format_count,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    struct Dwarf_P_Line_format_s *format,
    unsigned *size_out,
    Dwarf_Bool write_out,
    unsigned char *data,
    Dwarf_Error *error)
<<<<<<< HEAD
=======
=======
    struct Dwarf_P_Line_format_s* format,
    unsigned* size_out,
    Dwarf_Bool write_out,
    unsigned char* data,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    unsigned calculated_size = 0;
    unsigned n = 0;
    int res = 0;

    /*  entry format itself */
    calculated_size += sizeof_ubyte(dbg);

    /*  Space for the format details. */
<<<<<<< HEAD
    for(n = 0; n < format_count; ++n) {
        struct Dwarf_P_Line_format_s *lf = format+n;
=======
<<<<<<< HEAD
    for(n = 0; n < format_count; ++n) {
        struct Dwarf_P_Line_format_s *lf = format+n;
=======
    for (n = 0; n < format_count; ++n) {
        struct Dwarf_P_Line_format_s* lf = format + n;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        unsigned val_len = 0;
        unsigned val_len2 = 0;

        if (write_out) {
            res = append_uval(lf->def_content_type, dbg,
                data,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                &val_len,error);
        } else {
            res = pretend_write_uval(lf->def_content_type, dbg,
                &val_len,error);
        }
        data += val_len;
        if(res != DW_DLV_OK) {
<<<<<<< HEAD
=======
=======
                &val_len, error);
        }
        else {
            res = pretend_write_uval(lf->def_content_type, dbg,
                &val_len, error);
        }
        data += val_len;
        if (res != DW_DLV_OK) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            return res;
        }
        if (write_out) {
            res = append_uval(lf->def_form_code, dbg,
                data,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                &val_len2,error);
        } else {
            res = pretend_write_uval(lf->def_form_code, dbg,
                &val_len2,error);
        }
        if(res != DW_DLV_OK) {
<<<<<<< HEAD
=======
=======
                &val_len2, error);
        }
        else {
            res = pretend_write_uval(lf->def_form_code, dbg,
                &val_len2, error);
        }
        if (res != DW_DLV_OK) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            return res;
        }
        data += val_len2;
        calculated_size += val_len + val_len2;
    }
    *size_out = calculated_size;
    return DW_DLV_OK;
}

static int
determine_file_content_size(Dwarf_P_Debug dbg,
    Dwarf_P_F_Entry entry_list,
    Dwarf_Unsigned format_count,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    struct Dwarf_P_Line_format_s *format,
    unsigned *size_out,
    Dwarf_Bool write_out,
    unsigned char *data,
    Dwarf_Error *error)
{
    unsigned calculated_size = 0;
    unsigned count_len   = 0;
    Dwarf_P_F_Entry  cur = 0;
    Dwarf_P_F_Entry  nxt = 0;
    unsigned n           = 0;
    int res              = 0;
    Dwarf_Unsigned offset_size = 0;

    offset_size = dbg->de_dwarf_offset_size;
    res = pretend_write_uval(format_count,dbg,
        &count_len,error);
    if(res != DW_DLV_OK) {
<<<<<<< HEAD
=======
=======
    struct Dwarf_P_Line_format_s* format,
    unsigned* size_out,
    Dwarf_Bool write_out,
    unsigned char* data,
    Dwarf_Error* error)
{
    unsigned calculated_size = 0;
    unsigned count_len = 0;
    Dwarf_P_F_Entry  cur = 0;
    Dwarf_P_F_Entry  nxt = 0;
    unsigned n = 0;
    int res = 0;
    Dwarf_Unsigned offset_size = 0;

    offset_size = dbg->de_dwarf_offset_size;
    res = pretend_write_uval(format_count, dbg,
        &count_len, error);
    if (res != DW_DLV_OK) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        return res;
    }
    calculated_size += count_len;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    cur =  entry_list;
    for(n = 0; cur; n++,cur = nxt) {
        unsigned f = 0;
        nxt = cur->dfe_next;

        for( ; f < format_count; f++) {
            struct Dwarf_P_Line_format_s *lf = format+f;
<<<<<<< HEAD
=======
=======
    cur = entry_list;
    for (n = 0; cur; n++, cur = nxt) {
        unsigned f = 0;
        nxt = cur->dfe_next;

        for (; f < format_count; f++) {
            struct Dwarf_P_Line_format_s* lf = format + f;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            unsigned ctype = lf->def_content_type;
            unsigned cform = lf->def_form_code;

            switch (ctype) {
            case DW_LNCT_path: {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                switch(cform) {
                case DW_FORM_string: {
                    unsigned slen = strlen(cur->dfe_name) +1;
                    calculated_size += slen;
                    if (write_out) {
                        strcpy((char *)data, cur->dfe_name);
                        data += slen;
                    }
                    }
                    break;
                case DW_FORM_strp: {
                    unsigned slen = strlen(cur->dfe_name) +1;
<<<<<<< HEAD
=======
=======
                switch (cform) {
                case DW_FORM_string: {
                    unsigned slen = strlen(cur->dfe_name) + 1;
                    calculated_size += slen;
                    if (write_out) {
                        strcpy((char*)data, cur->dfe_name);
                        data += slen;
                    }
                }
                                   break;
                case DW_FORM_strp: {
                    unsigned slen = strlen(cur->dfe_name) + 1;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    if (write_out) {
                        Dwarf_Unsigned stroffset = 0;
                        res = _dwarf_insert_or_find_in_debug_str(
                            dbg,
                            cur->dfe_name,
                            _dwarf_hash_debug_str,
                            slen,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            &stroffset,error);
                        if (res != DW_DLV_OK) {
                            return res;
                        }
                        WRITE_UNALIGNED(dbg, (void *) data,
                            (const void *) &stroffset,
<<<<<<< HEAD
=======
=======
                            &stroffset, error);
                        if (res != DW_DLV_OK) {
                            return res;
                        }
                        WRITE_UNALIGNED(dbg, (void*)data,
                            (const void*)&stroffset,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            sizeof(stroffset), offset_size);
                        data += offset_size;
                    }
                    calculated_size += offset_size;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    break;
                case DW_FORM_line_strp: {
                    unsigned slen = strlen(cur->dfe_name) +1;
<<<<<<< HEAD
=======
=======
                }
                                 break;
                case DW_FORM_line_strp: {
                    unsigned slen = strlen(cur->dfe_name) + 1;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    if (write_out) {
                        Dwarf_Unsigned stroffset = 0;
                        res = _dwarf_insert_or_find_in_debug_str(
                            dbg,
                            cur->dfe_name,
                            _dwarf_hash_debug_line_str,
                            slen,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            &stroffset,error);
                        if (res != DW_DLV_OK) {
                            return res;
                        }
                        WRITE_UNALIGNED(dbg, (void *) data,
                            (const void *) &stroffset,
<<<<<<< HEAD
=======
=======
                            &stroffset, error);
                        if (res != DW_DLV_OK) {
                            return res;
                        }
                        WRITE_UNALIGNED(dbg, (void*)data,
                            (const void*)&stroffset,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            sizeof(stroffset), offset_size);
                        data += offset_size;
                    }
                    calculated_size += offset_size;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    break;
                case DW_FORM_strp_sup:
                /* Following in dwo only. */
<<<<<<< HEAD
=======
=======
                }
                                      break;
                case DW_FORM_strp_sup:
                    /* Following in dwo only. */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                case DW_FORM_strx:
                case DW_FORM_strx1:
                case DW_FORM_strx2:
                case DW_FORM_strx3:
                case DW_FORM_strx4:
                default:
                    DWARF_P_DBG_ERROR(dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED, DW_DLV_ERROR);
                    break;
                }
                }
                break;
            case DW_LNCT_directory_index: {
                switch(cform) {
<<<<<<< HEAD
=======
=======
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED,
                        DW_DLV_ERROR);
                    break;
                }
            }
                             break;
            case DW_LNCT_directory_index: {
                switch (cform) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                case DW_FORM_data1:
                    calculated_size += 1;
                    if (write_out) {
                        unsigned char ub = cur->dfe_index;
                        *data = ub;
                        data += 1;
                    }
                    break;
                case DW_FORM_data2:
                    calculated_size += DWARF_HALF_SIZE;
                    if (write_out) {
                        Dwarf_Half uh = cur->dfe_index;
<<<<<<< HEAD
                        memcpy(data,&uh,DWARF_HALF_SIZE);
=======
<<<<<<< HEAD
                        memcpy(data,&uh,DWARF_HALF_SIZE);
=======
                        memcpy(data, &uh, DWARF_HALF_SIZE);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        data += DWARF_HALF_SIZE;
                    }
                    break;
                case DW_FORM_udata: {
                    unsigned val_len = 0;
                    if (write_out) {
                        res = append_uval(cur->dfe_index,
                            dbg,
                            data,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            &val_len,error);
                        data += val_len;
                    } else {
                        res = pretend_write_uval(cur->dfe_index,
                            dbg, &val_len,error);
<<<<<<< HEAD
=======
=======
                            &val_len, error);
                        data += val_len;
                    }
                    else {
                        res = pretend_write_uval(cur->dfe_index,
                            dbg, &val_len, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    calculated_size += val_len;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    break;
                default:
                    DWARF_P_DBG_ERROR(dbg,
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED, DW_DLV_ERROR);
                }
                }
                break;
            case DW_LNCT_timestamp: {
                switch(cform) {
<<<<<<< HEAD
=======
=======
                }
                                  break;
                default:
                    DWARF_P_DBG_ERROR(dbg,
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED,
                        DW_DLV_ERROR);
                }
            }
                                        break;
            case DW_LNCT_timestamp: {
                switch (cform) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                case DW_FORM_udata: {
                    unsigned val_len = 0;
                    if (write_out) {
                        res = append_uval(cur->dfe_timestamp,
                            dbg,
                            data,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            &val_len,error);
                        data += val_len;
                    } else {
                        res = pretend_write_uval(cur->dfe_timestamp,
                            dbg, &val_len,error);
<<<<<<< HEAD
=======
=======
                            &val_len, error);
                        data += val_len;
                    }
                    else {
                        res = pretend_write_uval(cur->dfe_timestamp,
                            dbg, &val_len, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    calculated_size += val_len;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    break;
                case DW_FORM_data4: {
                    calculated_size += DWARF_32BIT_SIZE;
                    if (write_out) {
                        ASNOUT(data,cur->dfe_timestamp,
                            DWARF_32BIT_SIZE);
                        data += DWARF_32BIT_SIZE;
                    }
                    }
                    break;
<<<<<<< HEAD
=======
=======
                }
                                  break;
                case DW_FORM_data4: {
                    calculated_size += DWARF_32BIT_SIZE;
                    if (write_out) {
                        ASNOUT(data, cur->dfe_timestamp,
                            DWARF_32BIT_SIZE);
                        data += DWARF_32BIT_SIZE;
                    }
                }
                                  break;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                case DW_FORM_data8:
                    /*  As of 2017 there is no 8 byte timestamp
                        defined, though it does have to happen.
                        before 2038. */
                    calculated_size += DWARF_64BIT_SIZE;
                    if (write_out) {
                        Dwarf_Unsigned u8 = cur->dfe_index;
<<<<<<< HEAD
                        WRITE_UNALIGNED(dbg, (void *) data,
                            (const void *) &u8,
=======
<<<<<<< HEAD
                        WRITE_UNALIGNED(dbg, (void *) data,
                            (const void *) &u8,
=======
                        WRITE_UNALIGNED(dbg, (void*)data,
                            (const void*)&u8,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            sizeof(u8), DWARF_64BIT_SIZE);
                        data += DWARF_64BIT_SIZE;
                    }
                    break;
                case DW_FORM_block:
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                default:
                    DWARF_P_DBG_ERROR(dbg,
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED, DW_DLV_ERROR);
                }
                }
                break;
            case DW_LNCT_size: {
                switch(cform) {
<<<<<<< HEAD
=======
=======
                case DW_FORM_exprloc:
                default:
                    DWARF_P_DBG_ERROR(dbg,
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED,
                        DW_DLV_ERROR);
                }
            }
                                  break;
            case DW_LNCT_size: {
                switch (cform) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                case DW_FORM_data1:
                    calculated_size += 1;
                    if (write_out) {
                        unsigned char ub = cur->dfe_index;
                        *data = ub;
                        data += 1;
                    }
                    break;
                case DW_FORM_data2:
                    calculated_size += DWARF_HALF_SIZE;
                    if (write_out) {
                        Dwarf_Half uh = cur->dfe_index;
<<<<<<< HEAD
                        memcpy(data,&uh,DWARF_HALF_SIZE);
=======
<<<<<<< HEAD
                        memcpy(data,&uh,DWARF_HALF_SIZE);
=======
                        memcpy(data, &uh, DWARF_HALF_SIZE);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

                    }
                    break;
                case DW_FORM_data4:
                    calculated_size += DWARF_32BIT_SIZE;
                    if (write_out) {
<<<<<<< HEAD
                        ASNOUT(data,cur->dfe_index,
=======
<<<<<<< HEAD
                        ASNOUT(data,cur->dfe_index,
=======
                        ASNOUT(data, cur->dfe_index,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            DWARF_32BIT_SIZE);
                        data += DWARF_32BIT_SIZE;
                    }
                    break;
                case DW_FORM_data8:
                    calculated_size += DWARF_64BIT_SIZE;
                    if (write_out) {
                        Dwarf_Unsigned u8 = cur->dfe_index;
<<<<<<< HEAD
                        WRITE_UNALIGNED(dbg, (void *) data,
                            (const void *) &u8,
=======
<<<<<<< HEAD
                        WRITE_UNALIGNED(dbg, (void *) data,
                            (const void *) &u8,
=======
                        WRITE_UNALIGNED(dbg, (void*)data,
                            (const void*)&u8,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            sizeof(u8), DWARF_64BIT_SIZE);
                        data += DWARF_64BIT_SIZE;
                    }
                    break;
                case DW_FORM_udata: {
                    unsigned val_len = 0;
                    if (write_out) {
                        res = append_uval(cur->dfe_size,
                            dbg,
                            data,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                            &val_len,error);
                        data += val_len;
                    } else {
                        res = pretend_write_uval(cur->dfe_size,
                            dbg, &val_len,error);
<<<<<<< HEAD
=======
=======
                            &val_len, error);
                        data += val_len;
                    }
                    else {
                        res = pretend_write_uval(cur->dfe_size,
                            dbg, &val_len, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    calculated_size += val_len;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    }
                    break;
                default:
                    DWARF_P_DBG_ERROR(dbg,
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED, DW_DLV_ERROR);
                }
                }
                break;
            case DW_LNCT_MD5: {
                switch(cform) {
                case DW_FORM_data16:
                    if (write_out) {
                        memcpy(data,cur->dfe_md5,sizeof(cur->dfe_md5));
<<<<<<< HEAD
=======
=======
                }
                                  break;
                default:
                    DWARF_P_DBG_ERROR(dbg,
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED,
                        DW_DLV_ERROR);
                }
            }
                             break;
            case DW_LNCT_MD5: {
                switch (cform) {
                case DW_FORM_data16:
                    if (write_out) {
                        memcpy(data, cur->dfe_md5,
                            sizeof(cur->dfe_md5));
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        data += 16;
                    }
                    calculated_size += 16;
                    break;
                default:
                    DWARF_P_DBG_ERROR(dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED, DW_DLV_ERROR);
                }
                }
                break;
            default:
                DWARF_P_DBG_ERROR(dbg, DW_DLE_LNCT_CODE_UNKNOWN, DW_DLV_ERROR);
<<<<<<< HEAD
=======
=======
                        DW_DLE_LNCT_FORM_CODE_NOT_HANDLED,
                        DW_DLV_ERROR);
                }
            }
                            break;
            default:
                DWARF_P_DBG_ERROR(dbg, DW_DLE_LNCT_CODE_UNKNOWN,
                    DW_DLV_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            }
        }
    }
    *size_out = calculated_size;
    return DW_DLV_OK;
}

static int
calculate_size_of_line_header5(Dwarf_P_Debug dbg,
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits,
    unsigned *prolog_size_out,
    Dwarf_Error *error)
=======
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits,
    unsigned *prolog_size_out,
    Dwarf_Error *error)
=======
    struct Dwarf_P_Line_Inits_s* inits,
    unsigned* prolog_size_out,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    unsigned prolog_size = 0;
    int offset_size = dbg->de_dwarf_offset_size;
    int extension_size = dbg->de_64bit_extension ? 4 : 0;
    int res = 0;

    prolog_size += OFFSET_PLUS_EXTENSION_SIZE +
        sizeof_uhalf(dbg) + /* version # */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof_ubyte(dbg) +     /* address_size */
        sizeof_ubyte(dbg) +     /* segment_selector_size */
        offset_size       +     /* header length */
        sizeof_ubyte(dbg) +     /* min_instr length */
        sizeof_ubyte(dbg) +     /* maximum_operations_per_instruction */
        sizeof_ubyte(dbg) +     /* default is_stmt */
        sizeof_ubyte(dbg) +     /* linebase */
        sizeof_ubyte(dbg) +     /* linerange */
        sizeof_ubyte(dbg);      /* opcode base */
        /* For maximum_operations_per_instruction. */
        prolog_size += sizeof_ubyte(dbg);

    /* standard_opcode_lengths table len */
    prolog_size += inits->pi_opcode_base-1;
<<<<<<< HEAD
=======
=======
        sizeof_ubyte(dbg) + /* address_size */
        sizeof_ubyte(dbg) + /* segment_selector_size */
        offset_size + /* header length */
        sizeof_ubyte(dbg) + /* min_instr length */
        sizeof_ubyte(dbg) + /* maximum_operations_per_instruction */
        sizeof_ubyte(dbg) + /* default is_stmt */
        sizeof_ubyte(dbg) + /* linebase */
        sizeof_ubyte(dbg) + /* linerange */
        sizeof_ubyte(dbg);  /* opcode base */
    /* For maximum_operations_per_instruction. */
    prolog_size += sizeof_ubyte(dbg);

    /* standard_opcode_lengths table len */
    prolog_size += inits->pi_opcode_base - 1;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    {
        unsigned fsize = 0;
        res = determine_form_size(dbg,
            inits->pi_directory_entry_format_count,
            inits->pi_incformats,
<<<<<<< HEAD
            &fsize,FALSE,0,error);
=======
<<<<<<< HEAD
            &fsize,FALSE,0,error);
=======
            &fsize, FALSE, 0, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res != DW_DLV_OK) {
            return res;
        }
        prolog_size += fsize;
    }
    {
        unsigned dir_count_len = 0;
        res = determine_file_content_size(dbg,
            dbg->de_inc_dirs,
            dbg->de_line_inits.pi_directory_entry_format_count,
            dbg->de_line_inits.pi_incformats,
            &dir_count_len,
<<<<<<< HEAD
            FALSE,0,
=======
<<<<<<< HEAD
            FALSE,0,
=======
            FALSE, 0,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            error);
        if (res != DW_DLV_OK) {
            return res;
        }
        prolog_size += dir_count_len;
    }
    {
        unsigned fsize = 0;
        res = determine_form_size(dbg,
            inits->pi_file_entry_format_count,
            inits->pi_fileformats,
            &fsize,
<<<<<<< HEAD
            FALSE,0,
=======
<<<<<<< HEAD
            FALSE,0,
=======
            FALSE, 0,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            error);
        if (res != DW_DLV_OK) {
            return res;
        }
        prolog_size += fsize;
    }
    {
        unsigned file_count_len = 0;
        res = determine_file_content_size(dbg,
            dbg->de_file_entries,
            dbg->de_line_inits.pi_file_entry_format_count,
            dbg->de_line_inits.pi_fileformats,
            &file_count_len,
<<<<<<< HEAD
            FALSE,0,
=======
<<<<<<< HEAD
            FALSE,0,
=======
            FALSE, 0,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            error);
        if (res != DW_DLV_OK) {
            return res;
        }
        prolog_size += file_count_len;
    }
    *prolog_size_out = prolog_size;
    return DW_DLV_OK;
}

/* For DWARF 2,3,4 */
static int
calculate_size_of_line_header4(Dwarf_P_Debug dbg,
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits,
    unsigned *prolog_size_out,
    UNUSEDARG Dwarf_Error *error)
=======
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits,
    unsigned *prolog_size_out,
    UNUSEDARG Dwarf_Error *error)
=======
    struct Dwarf_P_Line_Inits_s* inits,
    unsigned* prolog_size_out,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    Dwarf_P_F_Entry curdir = 0;
    Dwarf_P_F_Entry curentry = 0;
    unsigned prolog_size = 0;
    int offset_size = dbg->de_dwarf_offset_size;
    int extension_size = dbg->de_64bit_extension ? 4 : 0;

<<<<<<< HEAD
    prolog_size += OFFSET_PLUS_EXTENSION_SIZE +
        sizeof_uhalf(dbg) +  /* version # */
        offset_size       +  /* header length */
=======
<<<<<<< HEAD
    prolog_size += OFFSET_PLUS_EXTENSION_SIZE +
        sizeof_uhalf(dbg) +  /* version # */
        offset_size       +  /* header length */
=======
    (void)error;
    prolog_size += OFFSET_PLUS_EXTENSION_SIZE +
        sizeof_uhalf(dbg) +  /* version # */
        offset_size +  /* header length */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof_ubyte(dbg) +  /* min_instr length */
        sizeof_ubyte(dbg) +  /* default is_stmt */
        sizeof_ubyte(dbg) +  /* linebase */
        sizeof_ubyte(dbg) +  /* linerange */
        sizeof_ubyte(dbg);   /* opcode base */
    if (inits->pi_linetable_version == DW_LINE_VERSION4) {
        /* For maximum_operations_per_instruction. */
        prolog_size += sizeof_ubyte(dbg);
    }
    /* standard_opcode_lengths table len */
<<<<<<< HEAD
    prolog_size += inits->pi_opcode_base-1;
=======
<<<<<<< HEAD
    prolog_size += inits->pi_opcode_base-1;
=======
    prolog_size += inits->pi_opcode_base - 1;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    /* include directories */
    curdir = dbg->de_inc_dirs;
    while (curdir) {
        prolog_size += strlen(curdir->dfe_name) + 1;
        curdir = curdir->dfe_next;
    }
    prolog_size++; /* last null following last directory
        entry. */

<<<<<<< HEAD
    /* file entries */
=======
<<<<<<< HEAD
    /* file entries */
=======
        /* file entries */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    curentry = dbg->de_file_entries;
    while (curentry) {
        prolog_size +=
            strlen(curentry->dfe_name) + 1 + curentry->dfe_nbytes;
        curentry = curentry->dfe_next;
    }
    prolog_size++; /* last null byte */
    *prolog_size_out = prolog_size;
    return DW_DLV_OK;
}

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
/* Generate debug_line section
   Dwarf2, dwarf3 headers are the same (DW3 acknowledges 64bit).
   DWARF4 adds the maximum_operations_per_instruction field.
   DWARF5 adds address size and address selector size
   and replaces the entire directories/files list with
   very different stuff.
*/
static int
_dwarf_pro_generate_debugline(Dwarf_P_Debug dbg,
<<<<<<< HEAD
    Dwarf_Signed * nbufs,
    Dwarf_Error * error)
=======
<<<<<<< HEAD
    Dwarf_Signed * nbufs,
    Dwarf_Error * error)
=======
    Dwarf_Signed* nbufs,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    Dwarf_P_F_Entry curdir = 0;
    Dwarf_P_F_Entry curentry = 0;
    Dwarf_P_Line curline = 0;
    Dwarf_P_Line prevline = 0;
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits = 0;
=======
<<<<<<< HEAD
    struct Dwarf_P_Line_Inits_s *inits = 0;
=======
    struct Dwarf_P_Line_Inits_s* inits = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    /* all data named cur* are used to loop thru linked lists */

    int sum_bytes = 0;
    unsigned prolog_size = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned char *data = 0;    /* holds disk form data */
    int elfsectno = 0;
    unsigned char *start_line_sec = 0;  /* pointer to the buffer at
        section start */
    /* temps for memcpy */
<<<<<<< HEAD
=======
=======
    unsigned char* data = 0;    /* holds disk form data */
    int elfsectno = 0;
    unsigned char* start_line_sec = 0;  /* pointer to the buffer at
        section start */
        /* temps for memcpy */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Unsigned du = 0;
    Dwarf_Ubyte db = 0;
    Dwarf_Half dh = 0;
    int res = 0;
    Dwarf_Half version = dbg->de_output_version;
    int offset_size = dbg->de_dwarf_offset_size;
    Dwarf_Ubyte extension_size = dbg->de_64bit_extension ? 4 : 0;
    Dwarf_Ubyte address_size = dbg->de_pointer_size;

    sum_bytes = 0;

    elfsectno = dbg->de_elf_sects[DEBUG_LINE];

    inits = &dbg->de_line_inits;
    if (version < 5) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        res  = calculate_size_of_line_header4(dbg,inits,&prolog_size,
            error);
    } else if (version == 5) {
        res  = calculate_size_of_line_header5(dbg,inits,&prolog_size,
            error);
    } else {
        _dwarf_p_error(dbg, error,DW_DLE_VERSION_STAMP_ERROR );
<<<<<<< HEAD
=======
=======
        res = calculate_size_of_line_header4(dbg, inits, &prolog_size,
            error);
    }
    else if (version == 5) {
        res = calculate_size_of_line_header5(dbg, inits, &prolog_size,
            error);
    }
    else {
        _dwarf_p_error(dbg, error, DW_DLE_VERSION_STAMP_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        return DW_DLV_ERROR;
    }
    if (res != DW_DLV_OK) {
        return res;
    }
    /* Allocate a chunk, put address in 'data' */
    GET_CHUNK_ERR(dbg, elfsectno, data, prolog_size, error);

    start_line_sec = data;

    /* Copy the prologue data into 'data' */
    /* total_length */
    du = 0;
    if (extension_size) {
        DISTINGUISHED_VALUE_ARRAY(v4);

<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &v4[0],
        SIZEOFT32, extension_size);
=======
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &v4[0],
        SIZEOFT32, extension_size);
=======
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&v4[0],
            SIZEOFT32, extension_size);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        data += extension_size;
    }

    /*  We will adjust this later, we do not know the full length
        of the line_section content for this cu  yet. */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &du,
        sizeof(du), offset_size);
    data += offset_size;

    dh =  inits->pi_linetable_version;
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &dh,
        sizeof(dh), DWARF_HALF_SIZE);
    data +=  DWARF_HALF_SIZE;
    if (version == 5 ) {
        /* address size, seg sel size now */
        db = inits->pi_address_size;
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
            sizeof(db), sizeof(db));
        data += sizeof(db);
        db = inits->pi_segment_size; /* segment selector size */
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
<<<<<<< HEAD
=======
=======
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&du,
        sizeof(du), offset_size);
    data += offset_size;

    dh = inits->pi_linetable_version;
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&dh,
        sizeof(dh), DWARF_HALF_SIZE);
    data += DWARF_HALF_SIZE;
    if (version == 5) {
        /* address size, seg sel size now */
        db = inits->pi_address_size;
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
            sizeof(db), sizeof(db));
        data += sizeof(db);
        db = inits->pi_segment_size; /* segment selector size */
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            sizeof(db), sizeof(db));
        data += sizeof(db);
    }

    {
        /*  header length (called prolog length in DWARF2)
            This we do know, we calculated the prolog length
            already and it is prolog_size so just
            */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        Dwarf_Unsigned sofar = data  - start_line_sec;

        du = prolog_size - sofar - offset_size;
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &du,
            sizeof(du), offset_size);
        data += offset_size;
    }
    db =  inits->pi_minimum_instruction_length;
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
<<<<<<< HEAD
=======
=======
        Dwarf_Unsigned sofar = data - start_line_sec;

        du = prolog_size - sofar - offset_size;
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&du,
            sizeof(du), offset_size);
        data += offset_size;
    }
    db = inits->pi_minimum_instruction_length;
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);

    if (inits->pi_linetable_version == 4 ||
        inits->pi_linetable_version == 5) {
<<<<<<< HEAD
        db =  inits->pi_maximum_operations_per_instruction;
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
=======
<<<<<<< HEAD
        db =  inits->pi_maximum_operations_per_instruction;
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
=======
        db = inits->pi_maximum_operations_per_instruction;
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            sizeof(db), sizeof(Dwarf_Ubyte));
        data += sizeof(Dwarf_Ubyte);
    }

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    db =  inits->pi_default_is_stmt;
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    db =  inits->pi_line_base;
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    db =  inits->pi_line_range;
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    db =  inits->pi_opcode_base;
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    WRITE_UNALIGNED(dbg, (void *) data, (const void *) std_opcode_len,
        inits->pi_opcode_base-1,
        inits->pi_opcode_base-1);
    data += inits->pi_opcode_base-1;
<<<<<<< HEAD
=======
=======
    db = inits->pi_default_is_stmt;
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    db = inits->pi_line_base;
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    db = inits->pi_line_range;
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    db = inits->pi_opcode_base;
    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
        sizeof(db), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);
    /* stream of single bytes. No endian issues. */
    memcpy((void*)data, (const void*)std_opcode_len,
        inits->pi_opcode_base - 1);
    data += inits->pi_opcode_base - 1;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    if (version < 5) {
        /* copy over include directories */
        curdir = dbg->de_inc_dirs;
        while (curdir) {
<<<<<<< HEAD
            strcpy((char *) data, curdir->dfe_name);
=======
<<<<<<< HEAD
            strcpy((char *) data, curdir->dfe_name);
=======
            strcpy((char*)data, curdir->dfe_name);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            data += strlen(curdir->dfe_name) + 1;
            curdir = curdir->dfe_next;
        }
        *data = '\0';               /* last null */
        data++;

        /* copy file entries */
        curentry = dbg->de_file_entries;
        while (curentry) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            strcpy((char *) data, curentry->dfe_name);
            data += strlen(curentry->dfe_name) + 1;
            /* copies of leb numbers, no endian issues */
            memcpy((void *) data,
                (const void *) curentry->dfe_args, curentry->dfe_nbytes);
<<<<<<< HEAD
=======
=======
            strcpy((char*)data, curentry->dfe_name);
            data += strlen(curentry->dfe_name) + 1;
            /* copies of leb numbers, no endian issues */
            memcpy((void*)data,
                (const void*)curentry->dfe_args,
                curentry->dfe_nbytes);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            data += curentry->dfe_nbytes;
            curentry = curentry->dfe_next;
        }
        *data = '\0';
        data++;
<<<<<<< HEAD
    } else if (version == 5) {
=======
<<<<<<< HEAD
    } else if (version == 5) {
=======
    }
    else if (version == 5) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        {
            unsigned fsize = 0;
            res = determine_form_size(dbg,
                inits->pi_directory_entry_format_count,
                inits->pi_incformats,
                &fsize,
<<<<<<< HEAD
                TRUE,data,
=======
<<<<<<< HEAD
                TRUE,data,
=======
                TRUE, data,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                error);
            if (res != DW_DLV_OK) {
                return res;
            }
            data += fsize;
        }
        {
            unsigned dir_count_len = 0;
            res = determine_file_content_size(dbg,
                dbg->de_inc_dirs,
                inits->pi_directory_entry_format_count,
                inits->pi_incformats,
                &dir_count_len,
<<<<<<< HEAD
                TRUE,data,
=======
<<<<<<< HEAD
                TRUE,data,
=======
                TRUE, data,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                error);
            if (res != DW_DLV_OK) {
                return res;
            }
            data += dir_count_len;
        }
        {
            unsigned fsize = 0;
            res = determine_form_size(dbg,
                inits->pi_file_entry_format_count,
                inits->pi_fileformats,
                &fsize,
<<<<<<< HEAD
                TRUE,data,
=======
<<<<<<< HEAD
                TRUE,data,
=======
                TRUE, data,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                error);
            if (res != DW_DLV_OK) {
                return res;
            }
            data += fsize;
        }
        {
            unsigned file_count_len = 0;
            res = determine_file_content_size(dbg,
                dbg->de_file_entries,
                dbg->de_line_inits.pi_file_entry_format_count,
                dbg->de_line_inits.pi_fileformats,
                &file_count_len,
<<<<<<< HEAD
                TRUE,data,
=======
<<<<<<< HEAD
                TRUE,data,
=======
                TRUE, data,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                error);
            if (res != DW_DLV_OK) {
                return res;
            }
            data += file_count_len;
        }
    }

    {
        Dwarf_Unsigned sofar = data - start_line_sec;
        if (sofar != prolog_size) {
            /* We miscalculated something. */
            _dwarf_p_error(dbg, error,
                DW_DLE_LINE_HEADER_LENGTH_BOTCH);
            return DW_DLV_ERROR;
        }
        sum_bytes += prolog_size;
    }

    curline = dbg->de_lines;
    prevline = (Dwarf_P_Line)
        _dwarf_p_get_alloc(dbg, sizeof(struct Dwarf_P_Line_s));
    if (prevline == NULL) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_LINE_ALLOC, DW_DLV_ERROR);
    }
<<<<<<< HEAD
    _dwarf_pro_reg_init(dbg,prevline);
=======
<<<<<<< HEAD
    _dwarf_pro_reg_init(dbg,prevline);
=======
    _dwarf_pro_reg_init(dbg, prevline);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    /* generate opcodes for line numbers */
    while (curline) {
        int opc = 0;
        int no_lns_copy = 0; /* if lns copy opcode does not need to be
            generated, if special opcode or end
            sequence */
        Dwarf_Unsigned addr_adv = 0;
<<<<<<< HEAD
        int line_adv = 0;           /* supposed to be a reasonably small
=======
<<<<<<< HEAD
        int line_adv = 0;           /* supposed to be a reasonably small
=======
        int line_adv = 0; /* supposed to be a reasonably small
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            number, so the size should not be a
            problem. ? */

        no_lns_copy = 0;
        if (curline->dpl_opc != 0) {
<<<<<<< HEAD
            int inst_bytes = 0;     /* no of bytes in extended opcode */
=======
<<<<<<< HEAD
            int inst_bytes = 0;     /* no of bytes in extended opcode */
=======
            int inst_bytes = 0; /* no of bytes in extended opcode */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            unsigned writelen = 0;

            switch (curline->dpl_opc) {
            case DW_LNE_end_sequence:
                /* Advance pc to end of text section. */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                addr_adv = curline->dpl_address - prevline->dpl_address;
                if (addr_adv > 0) {
                    res = write_opcode_uval(DW_LNS_advance_pc,dbg,
                        elfsectno,
                        addr_adv/inits->pi_minimum_instruction_length,
<<<<<<< HEAD
=======
=======
                addr_adv = curline->dpl_address -
                    prevline->dpl_address;
                if (addr_adv > 0) {
                    res = write_opcode_uval(DW_LNS_advance_pc, dbg,
                        elfsectno,
                        addr_adv / inits->pi_minimum_instruction_length,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        &writelen,
                        error);
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    sum_bytes += writelen;
                    prevline->dpl_address = curline->dpl_address;
                }

                /* first null byte */
                db = 0;
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_ubyte(db, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* write length of extended opcode */
                inst_bytes = sizeof(Dwarf_Ubyte);
<<<<<<< HEAD
                res = write_uval(inst_bytes,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_uval(inst_bytes,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_uval(inst_bytes, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* write extended opcode */
<<<<<<< HEAD
                res = write_ubyte(DW_LNE_end_sequence,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_ubyte(DW_LNE_end_sequence,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_ubyte(DW_LNE_end_sequence, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* reset value to original values */
<<<<<<< HEAD
                _dwarf_pro_reg_init(dbg,prevline);
=======
<<<<<<< HEAD
                _dwarf_pro_reg_init(dbg,prevline);
=======
                _dwarf_pro_reg_init(dbg, prevline);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                no_lns_copy = 1;
                /*  this is set only for end_sequence, so that a
                    dw_lns_copy is not generated */
                break;

            case DW_LNE_set_address:

                /* first null byte */
                db = 0;
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_ubyte(db, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* write length of extended opcode */
                inst_bytes = sizeof(Dwarf_Ubyte) + address_size;
<<<<<<< HEAD
                res = write_uval(inst_bytes,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_uval(inst_bytes,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_uval(inst_bytes, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* write extended opcode */
<<<<<<< HEAD
                res = write_ubyte(DW_LNE_set_address,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_ubyte(DW_LNE_set_address,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_ubyte(DW_LNE_set_address, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* reloc for address */
                res = dbg->de_relocate_by_name_symbol(dbg,
                    DEBUG_LINE,
                    sum_bytes,  /* r_offset  */
                    curline->dpl_r_symidx,
                    dwarf_drt_data_reloc,
                    offset_size);
                if (res != DW_DLV_OK) {
<<<<<<< HEAD
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC, DW_DLV_ERROR);
=======
<<<<<<< HEAD
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC, DW_DLV_ERROR);
=======
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC,
                        DW_DLV_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                }

                /* write offset (address) */
                du = curline->dpl_address;
<<<<<<< HEAD
                res = write_fixed_size(du,dbg,elfsectno,
                    address_size,&writelen,error);
=======
<<<<<<< HEAD
                res = write_fixed_size(du,dbg,elfsectno,
                    address_size,&writelen,error);
=======
                res = write_fixed_size(du, dbg, elfsectno,
                    address_size, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;
                prevline->dpl_address = curline->dpl_address;
                no_lns_copy = 1;
                break;
            case DW_LNE_define_file:
                /*  Not supported, all add-file entries
                    are added via dbg  -> de_file_entries,
                    which adds to the line table header.  */
                no_lns_copy = 1;
                break;
            case DW_LNE_set_discriminator: {/* DWARF4 */
                unsigned val_len = 0;
                /* first null byte */
                db = 0;
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,&writelen,error);
=======
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,&writelen,error);
=======
                res = write_ubyte(db, dbg, elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* Write len of opcode + value here. */
                res = pretend_write_uval(curline->dpl_discriminator,
<<<<<<< HEAD
                    dbg, &val_len,error);
=======
<<<<<<< HEAD
                    dbg, &val_len,error);
=======
                    dbg, &val_len, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                val_len++;

<<<<<<< HEAD
                res = write_uval(val_len +1,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_uval(val_len +1,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_uval(val_len + 1, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* Write opcode */
                res = write_ubyte(DW_LNE_set_discriminator,
<<<<<<< HEAD
                    dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                    dbg,elfsectno,
                    &writelen,error);
=======
                    dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* Write the value itself. */
                res = write_uval(curline->dpl_discriminator,
<<<<<<< HEAD
                    dbg,elfsectno,&writelen,error);
=======
<<<<<<< HEAD
                    dbg,elfsectno,&writelen,error);
=======
                    dbg, elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;
                no_lns_copy = 1;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                }
                break;
            }
        } else {
            unsigned writelen = 0;
            if (inits->pi_opcode_base >12) {
<<<<<<< HEAD
=======
=======
            }
                                         break;
            }
        }
        else {
            unsigned writelen = 0;
            if (inits->pi_opcode_base > 12) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                /*  We have the newer standard opcodes
                    DW_LNS_set_prologue_end, DW_LNS_set_epilogue_end,
                    DW_LNS_set_isa, we do not write them if not
                    in the table. DWARF3 and DWARF4 */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                /*  Should we check if a change? These reset automatically
                    in the line processing/reading engine,
                    so I think no check of prevline is wanted. */
                if (curline->dpl_epilogue_begin) {
                    res = write_ubyte(DW_LNS_set_epilogue_begin,dbg,
                        elfsectno,&writelen, error);
<<<<<<< HEAD
=======
=======
                    /*  Should we check if a change?
                        These reset automatically
                        in the line processing/reading engine,
                        so I think no check of prevline is wanted. */
                if (curline->dpl_epilogue_begin) {
                    res = write_ubyte(DW_LNS_set_epilogue_begin, dbg,
                        elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    sum_bytes += writelen;
                }
                if (curline->dpl_prologue_end) {
<<<<<<< HEAD
                    res = write_ubyte(DW_LNS_set_prologue_end,dbg,
                        elfsectno, &writelen,error);
=======
<<<<<<< HEAD
                    res = write_ubyte(DW_LNS_set_prologue_end,dbg,
                        elfsectno, &writelen,error);
=======
                    res = write_ubyte(DW_LNS_set_prologue_end, dbg,
                        elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    sum_bytes += writelen;
                }
                if (curline->dpl_isa != prevline->dpl_isa) {
<<<<<<< HEAD
                    res = write_opcode_uval(DW_LNS_set_isa,dbg,
                        elfsectno, curline->dpl_isa,
                        &writelen ,error);
=======
<<<<<<< HEAD
                    res = write_opcode_uval(DW_LNS_set_isa,dbg,
                        elfsectno, curline->dpl_isa,
                        &writelen ,error);
=======
                    res = write_opcode_uval(DW_LNS_set_isa, dbg,
                        elfsectno, curline->dpl_isa,
                        &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    sum_bytes += writelen;
                }
            }
            if (curline->dpl_file != prevline->dpl_file) {
                db = DW_LNS_set_file;
<<<<<<< HEAD
                res = write_opcode_uval(db,dbg,
                    elfsectno,
                        curline->dpl_file,&writelen ,error);
=======
<<<<<<< HEAD
                res = write_opcode_uval(db,dbg,
                    elfsectno,
                        curline->dpl_file,&writelen ,error);
=======
                res = write_opcode_uval(db, dbg,
                    elfsectno,
                    curline->dpl_file, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                prevline->dpl_file = curline->dpl_file;
            }
            if (curline->dpl_column != prevline->dpl_column) {
                db = DW_LNS_set_column;
<<<<<<< HEAD
                res = write_opcode_uval(db,dbg,
                    elfsectno, curline->dpl_column , &writelen,error);
=======
<<<<<<< HEAD
                res = write_opcode_uval(db,dbg,
                    elfsectno, curline->dpl_column , &writelen,error);
=======
                res = write_opcode_uval(db, dbg,
                    elfsectno, curline->dpl_column, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;
                prevline->dpl_column = curline->dpl_column;
            }
            if (curline->dpl_is_stmt != prevline->dpl_is_stmt) {
<<<<<<< HEAD
                res = write_ubyte(DW_LNS_negate_stmt,dbg,elfsectno,
                    &writelen,error);
=======
<<<<<<< HEAD
                res = write_ubyte(DW_LNS_negate_stmt,dbg,elfsectno,
                    &writelen,error);
=======
                res = write_ubyte(DW_LNS_negate_stmt, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;
                prevline->dpl_is_stmt = curline->dpl_is_stmt;
            }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            if (curline->dpl_basic_block == true &&
                prevline->dpl_basic_block == false) {
                res = write_ubyte(DW_LNS_set_basic_block,dbg,
                    elfsectno,&writelen,error);
<<<<<<< HEAD
=======
=======
            if (curline->dpl_basic_block == TRUE &&
                prevline->dpl_basic_block == FALSE) {
                res = write_ubyte(DW_LNS_set_basic_block, dbg,
                    elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;
                prevline->dpl_basic_block = curline->dpl_basic_block;
            }
            if (curline->dpl_discriminator) {
                /*  This is dwarf4, but because it is an extended op
                    not a standard op,
                    we allow it without testing version.
                    GNU seems to set this from time to time. */
                unsigned val_len = 0;
                /* first null byte */
                db = 0;
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,&writelen,error);
=======
<<<<<<< HEAD
                res = write_ubyte(db,dbg,elfsectno,&writelen,error);
=======
                res = write_ubyte(db, dbg, elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* Write len of opcode + value here. */
                res = pretend_write_uval(curline->dpl_discriminator,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    dbg, &val_len,error);
                if (res != DW_DLV_OK) {
                    return res;
                }
                val_len ++;
                res = write_uval(val_len +1,dbg,elfsectno,
                    &writelen,error);
<<<<<<< HEAD
=======
=======
                    dbg, &val_len, error);
                if (res != DW_DLV_OK) {
                    return res;
                }
                val_len++;
                res = write_uval(val_len + 1, dbg, elfsectno,
                    &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* Write opcode */
                res = write_ubyte(DW_LNE_set_discriminator,
<<<<<<< HEAD
                    dbg,elfsectno,&writelen,error);
=======
<<<<<<< HEAD
                    dbg,elfsectno,&writelen,error);
=======
                    dbg, elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;

                /* Write the value itself. */
                res = write_uval(curline->dpl_discriminator,
<<<<<<< HEAD
                    dbg,elfsectno,&writelen,error);
=======
<<<<<<< HEAD
                    dbg,elfsectno,&writelen,error);
=======
                    dbg, elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;
            }

            addr_adv = curline->dpl_address - prevline->dpl_address;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            line_adv = (int) (curline->dpl_line - prevline->dpl_line);
            if ((addr_adv % MIN_INST_LENGTH) != 0) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_WRONG_ADDRESS, DW_DLV_ERROR);
            }
            opc = _dwarf_pro_get_opc(inits,addr_adv, line_adv);
            if (opc > 0) {
                /* Use special opcode. */
                no_lns_copy = 1;
                res = write_ubyte(opc,dbg,elfsectno,&writelen,error);
<<<<<<< HEAD
=======
=======
            line_adv = (int)(curline->dpl_line - prevline->dpl_line);
            if ((addr_adv % MIN_INST_LENGTH) != 0) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_WRONG_ADDRESS,
                    DW_DLV_ERROR);
            }
            opc = _dwarf_pro_get_opc(inits, addr_adv, line_adv);
            if (opc > 0) {
                /* Use special opcode. */
                no_lns_copy = 1;
                res = write_ubyte(opc, dbg, elfsectno, &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
                sum_bytes += writelen;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                prevline->dpl_basic_block = false;
                prevline->dpl_address = curline->dpl_address;
                prevline->dpl_line = curline->dpl_line;
            } else {
                /*  opc says use standard opcodes. */
                if (addr_adv > 0) {
                    db = DW_LNS_advance_pc;
                    res = write_opcode_uval(db,dbg,
                        elfsectno,
                        addr_adv/inits->pi_minimum_instruction_length,
<<<<<<< HEAD
=======
=======
                prevline->dpl_basic_block = FALSE;
                prevline->dpl_address = curline->dpl_address;
                prevline->dpl_line = curline->dpl_line;
            }
            else {
                /*  opc says use standard opcodes. */
                if (addr_adv > 0) {
                    db = DW_LNS_advance_pc;
                    res = write_opcode_uval(db, dbg,
                        elfsectno,
                        addr_adv / inits->pi_minimum_instruction_length,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        &writelen,
                        error);
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    sum_bytes += writelen;
<<<<<<< HEAD
                    prevline->dpl_basic_block = false;
=======
<<<<<<< HEAD
                    prevline->dpl_basic_block = false;
=======
                    prevline->dpl_basic_block = FALSE;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    prevline->dpl_address = curline->dpl_address;
                }
                if (line_adv != 0) {
                    db = DW_LNS_advance_line;
<<<<<<< HEAD
                    res = write_ubyte(db,dbg,
=======
<<<<<<< HEAD
                    res = write_ubyte(db,dbg,
=======
                    res = write_ubyte(db, dbg,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        elfsectno,
                        &writelen,
                        error);
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    sum_bytes += writelen;
<<<<<<< HEAD
                    res = write_sval(line_adv,dbg,
=======
<<<<<<< HEAD
                    res = write_sval(line_adv,dbg,
=======
                    res = write_sval(line_adv, dbg,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        elfsectno,
                        &writelen,
                        error);
                    if (res != DW_DLV_OK) {
                        return res;
                    }
                    sum_bytes += writelen;
<<<<<<< HEAD
                    prevline->dpl_basic_block = false;
=======
<<<<<<< HEAD
                    prevline->dpl_basic_block = false;
=======
                    prevline->dpl_basic_block = FALSE;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    prevline->dpl_line = curline->dpl_line;
                }
            }
        }   /* ends else for opc <= 0 */
        if (no_lns_copy == 0) { /* if not a special or dw_lne_end_seq
            generate a matrix line */
            unsigned writelen = 0;
<<<<<<< HEAD
            res = write_ubyte(DW_LNS_copy,dbg,elfsectno,&writelen,error);
=======
<<<<<<< HEAD
            res = write_ubyte(DW_LNS_copy,dbg,elfsectno,&writelen,error);
=======
            res = write_ubyte(DW_LNS_copy, dbg, elfsectno,
                &writelen, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            if (res != DW_DLV_OK) {
                return res;
            }
            sum_bytes += writelen;
<<<<<<< HEAD
            prevline->dpl_basic_block = false;
=======
<<<<<<< HEAD
            prevline->dpl_basic_block = false;
=======
            prevline->dpl_basic_block = FALSE;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }
        curline = curline->dpl_next;
    }

    /* write total length field */
    du = sum_bytes - OFFSET_PLUS_EXTENSION_SIZE;
    {
        start_line_sec += extension_size;
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) start_line_sec,
            (const void *) &du, sizeof(du), offset_size);
=======
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) start_line_sec,
            (const void *) &du, sizeof(du), offset_size);
=======
        WRITE_UNALIGNED(dbg, (void*)start_line_sec,
            (const void*)&du, sizeof(du), offset_size);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    }

    *nbufs = dbg->de_n_debug_sect;
    return DW_DLV_OK;
}

/*
    Generate debug_frame section  */
static int
_dwarf_pro_generate_debugframe(Dwarf_P_Debug dbg,
<<<<<<< HEAD
    Dwarf_Signed *nbufs,
    Dwarf_Error * error)
=======
<<<<<<< HEAD
    Dwarf_Signed *nbufs,
    Dwarf_Error * error)
=======
    Dwarf_Signed* nbufs,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    int elfsectno = 0;
    int i = 0;
    int firsttime = 1;
    Dwarf_P_Cie curcie = 0;
    Dwarf_P_Fde curfde = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned char *data = 0;
    Dwarf_Unsigned du = 0;
    Dwarf_Ubyte db = 0;
    long *cie_offs = 0;   /* Holds byte offsets for links to fde's */
<<<<<<< HEAD
=======
=======
    unsigned char* data = 0;
    Dwarf_Unsigned du = 0;
    Dwarf_Ubyte db = 0;
    long* cie_offs = 0;   /* Holds byte offsets for links to fde's */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned long cie_length = 0;
    int cie_no = 0;
    Dwarf_Ubyte offset_size = dbg->de_dwarf_offset_size;
    Dwarf_Ubyte extension_size = dbg->de_64bit_extension ? 4 : 0;
    Dwarf_Ubyte address_size = dbg->de_pointer_size;
<<<<<<< HEAD
    Dwarf_Unsigned cur_off = 0; /* current offset of written data, held
=======
<<<<<<< HEAD
    Dwarf_Unsigned cur_off = 0; /* current offset of written data, held
=======
    Dwarf_Unsigned cur_off = 0;/* current offset of written data, held
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        for relocation info */

    elfsectno = dbg->de_elf_sects[DEBUG_FRAME];

    curcie = dbg->de_frame_cies;
    cie_length = 0;
<<<<<<< HEAD
    cie_offs = (long *)
=======
<<<<<<< HEAD
    cie_offs = (long *)
=======
    cie_offs = (long*)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        _dwarf_p_get_alloc(dbg, sizeof(long) * dbg->de_n_cie);
    if (cie_offs == NULL) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_OFFS_ALLOC, DW_DLV_ERROR);
    }
    /*  Generate cie number as we go along.  This writes
        all CIEs first before any FDEs, which is rather
        different from the order a compiler might like (which
        might be each CIE followed by its FDEs then the next CIE, and
        so on). */
    cie_no = 1;
    while (curcie) {
<<<<<<< HEAD
        char *code_al = 0;
        int codeal_bytes = 0;
        char *data_al = 0;
=======
<<<<<<< HEAD
        char *code_al = 0;
        int codeal_bytes = 0;
        char *data_al = 0;
=======
        char* code_al = 0;
        int codeal_bytes = 0;
        char* data_al = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        int data_align_bytes = 0;
        int pad = 0;     /* Pad for padding to align cies and fdes */
        int res = 0;
        char buff1[ENCODE_SPACE_NEEDED];
        char buff2[ENCODE_SPACE_NEEDED];
        char buff3[ENCODE_SPACE_NEEDED];
<<<<<<< HEAD
        char *augmentation = 0;
        char *augmented_al = 0;
=======
<<<<<<< HEAD
        char *augmentation = 0;
        char *augmented_al = 0;
=======
        char* augmentation = 0;
        char* augmented_al = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        long augmented_fields_length = 0;
        int irix_auglen_v0 = 0;
        Dwarf_Half version = curcie->cie_version;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        res = _dwarf_pro_encode_leb128_nm(curcie->cie_code_align,
            &codeal_bytes,
            buff1, sizeof(buff1));
        if (res != DW_DLV_OK) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_OFFS_ALLOC, DW_DLV_ERROR);
<<<<<<< HEAD
=======
=======
        res = dwarf_encode_leb128(curcie->cie_code_align,
            &codeal_bytes,
            buff1, sizeof(buff1));
        if (res != DW_DLV_OK) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_OFFS_ALLOC,
                DW_DLV_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }
        /*  Before April 1999, the following was using an unsigned
            encode. That worked ok even though the decoder used the
            correct signed leb read, but doing the encode correctly
<<<<<<< HEAD
            (according to the dwarf spec) saves space in the output file
=======
<<<<<<< HEAD
            (according to the dwarf spec) saves space in the output file
=======
            (according to the dwarf spec)
            saves space in the output file
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            and is completely compatible.

            Note the actual stored amount on MIPS was 10 bytes (!) to
            store the value -4. (hex)fc ffffffff ffffffff 01 The
            libdwarf consumer consumed all 10 bytes too!

            old version res =
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            _dwarf_pro_encode_leb128_nm(curcie->cie_data_align,

            below is corrected signed version. */
        res = _dwarf_pro_encode_signed_leb128_nm(curcie->cie_data_align,
            &data_align_bytes,
            buff2, sizeof(buff2));
        if (res != DW_DLV_OK) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_OFFS_ALLOC, DW_DLV_ERROR);
<<<<<<< HEAD
=======
=======
            dwarf_encode_leb128(curcie->cie_data_align,

            below is corrected signed version. */
        res = dwarf_encode_signed_leb128(
            curcie->cie_data_align,
            &data_align_bytes,
            buff2, sizeof(buff2));
        if (res != DW_DLV_OK) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_OFFS_ALLOC,
                DW_DLV_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }
        code_al = buff1;
        data_al = buff2;

        /* get the correct offset */
        if (firsttime) {
            cie_offs[cie_no - 1] = 0;
            firsttime = 0;
<<<<<<< HEAD
        } else {
            cie_offs[cie_no - 1] = cie_offs[cie_no - 2] +
                (long) cie_length + OFFSET_PLUS_EXTENSION_SIZE;
=======
<<<<<<< HEAD
        } else {
            cie_offs[cie_no - 1] = cie_offs[cie_no - 2] +
                (long) cie_length + OFFSET_PLUS_EXTENSION_SIZE;
=======
        }
        else {
            cie_offs[cie_no - 1] = cie_offs[cie_no - 2] +
                (long)cie_length + OFFSET_PLUS_EXTENSION_SIZE;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }
        cie_no++;
        augmentation = curcie->cie_aug;
        cie_length = offset_size +  /* cie_id */
            sizeof(Dwarf_Ubyte) +   /* cie version */
            strlen(curcie->cie_aug) + 1 +   /* augmentation */
            codeal_bytes +       /* code alignment factor */
            data_align_bytes +       /* data alignment factor */
            sizeof(Dwarf_Ubyte) +   /* return reg address */
            curcie->cie_inst_bytes;
        if (dbg->de_irix_exc_augmentation &&
            (strcmp(augmentation, DW_CIE_AUGMENTER_STRING_V0) == 0)) {

            /* IRIX specific. */
            augmented_fields_length = 0;
<<<<<<< HEAD
            res = _dwarf_pro_encode_leb128_nm(augmented_fields_length,
=======
<<<<<<< HEAD
            res = _dwarf_pro_encode_leb128_nm(augmented_fields_length,
=======
            res = dwarf_encode_leb128(augmented_fields_length,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                &irix_auglen_v0, buff3,
                sizeof(buff3));
            augmented_al = buff3;
            if (res != DW_DLV_OK) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_OFFS_ALLOC,
                    DW_DLV_ERROR);
            }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            cie_length += irix_auglen_v0 ;       /* augmentation length */
        }
        if (version >= 4) {
            /* address size, segment selector size */
            cie_length += 1 +1;
        }

        pad = (int) PADDING(cie_length, address_size);
<<<<<<< HEAD
=======
=======
            cie_length += irix_auglen_v0; /* augmentation length */
        }
        if (version >= 4) {
            /* address size, segment selector size */
            cie_length += 1 + 1;
        }

        pad = (int)PADDING(cie_length, address_size);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        cie_length += pad;

        /* Now we have the cie length with padding,
            allocate a buffer for that plus the header
            length. */
        GET_CHUNK_ERR(dbg, elfsectno, data, cie_length +
            OFFSET_PLUS_EXTENSION_SIZE,
            error);
        if (extension_size) {
            DISTINGUISHED_VALUE_ARRAY(v4);

<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &v4[0],
=======
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &v4[0],
=======
            WRITE_UNALIGNED(dbg, (void*)data,
                (const void*)&v4[0],
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                SIZEOFT32, extension_size);
            data += extension_size;

        }
        du = cie_length;
        /* total length of cie */
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data,
            (const void *) &du, sizeof(du), offset_size);
=======
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data,
            (const void *) &du, sizeof(du), offset_size);
=======
        WRITE_UNALIGNED(dbg, (void*)data,
            (const void*)&du, sizeof(du), offset_size);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        data += offset_size;

        /* cie-id is a special value. */
        du = DW_CIE_ID;
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &du,
=======
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &du,
=======
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&du,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            sizeof(du), offset_size);
        data += offset_size;

        db = curcie->cie_version;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
            sizeof(db), sizeof(Dwarf_Ubyte));
        data += sizeof(Dwarf_Ubyte);

        strcpy((char *) data, curcie->cie_aug);
<<<<<<< HEAD
=======
=======
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
            sizeof(db), sizeof(Dwarf_Ubyte));
        data += sizeof(Dwarf_Ubyte);

        strcpy((char*)data, curcie->cie_aug);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        data += strlen(curcie->cie_aug) + 1;

        if (curcie->cie_version >= 4) {
            /* emit address-size, segment selector size */
            db = dbg->de_pointer_size;
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
=======
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
=======
            WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                sizeof(db), sizeof(Dwarf_Ubyte));
            data += sizeof(Dwarf_Ubyte);

            db = dbg->de_segment_selector_size;
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
=======
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
=======
            WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                sizeof(db), sizeof(Dwarf_Ubyte));
            data += sizeof(Dwarf_Ubyte);
        }

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

        memcpy((void *) data, (const void *) code_al, codeal_bytes);
        data += codeal_bytes;

        memcpy((void *) data, (const void *) data_al, data_align_bytes);
        data += data_align_bytes;

        db = curcie->cie_ret_reg;
        WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
<<<<<<< HEAD
=======
=======
        memcpy((void*)data, (const void*)code_al, codeal_bytes);
        data += codeal_bytes;

        memcpy((void*)data, (const void*)data_al,
            data_align_bytes);
        data += data_align_bytes;

        db = curcie->cie_ret_reg;
        WRITE_UNALIGNED(dbg, (void*)data, (const void*)&db,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            sizeof(db), sizeof(Dwarf_Ubyte));
        data += sizeof(Dwarf_Ubyte);

        if (dbg->de_irix_exc_augmentation &&
            strcmp(augmentation, DW_CIE_AUGMENTER_STRING_V0) == 0) {

            /* IRIX only */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            memcpy((void *) data, (const void *) augmented_al,
                irix_auglen_v0);
            data += irix_auglen_v0;
        }
        memcpy((void *) data, (const void *) curcie->cie_inst,
<<<<<<< HEAD
=======
=======
            memcpy((void*)data, (const void*)augmented_al,
                irix_auglen_v0);
            data += irix_auglen_v0;
        }
        memcpy((void*)data, (const void*)curcie->cie_inst,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            curcie->cie_inst_bytes);
        data += curcie->cie_inst_bytes;

        for (i = 0; i < pad; i++) {
            *data = DW_CFA_nop;
            data++;
        }
        curcie = curcie->cie_next;
    }
    /* calculate current offset */
    cur_off = cie_offs[cie_no - 2] + cie_length +
        OFFSET_PLUS_EXTENSION_SIZE;

    /* write out fde's */
    curfde = dbg->de_frame_fdes;
    while (curfde) {
        Dwarf_P_Frame_Pgm curinst = 0;
        long fde_length = 0;
        int pad2 = 0;
        Dwarf_P_Cie cie_ptr = 0;
        Dwarf_Unsigned cie_index = 0;
<<<<<<< HEAD
        /* index is a global in string.h, so don't name anything index. */
=======
<<<<<<< HEAD
        /* index is a global in string.h, so don't name anything index. */
=======
        /*  index is a global in string.h, so don't
            name anything index. */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        Dwarf_Unsigned indx = 0;
        int oet_length = 0;
        int afl_length = 0;
        int res = 0;
        int v0_augmentation = 0;
        char afl_buff[ENCODE_SPACE_NEEDED];

        /* Find the CIE associated with this fde. */
        cie_ptr = dbg->de_frame_cies;
        cie_index = curfde->fde_cie;
        indx = 1; /* The cie_index of the first cie is 1, not 0. */
        while (cie_ptr && indx < cie_index) {
            cie_ptr = cie_ptr->cie_next;
            indx++;
        }
        if (cie_ptr == NULL) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_NULL, DW_DLV_ERROR);
        }

        fde_length = curfde->fde_n_bytes +
            OFFSET_PLUS_EXTENSION_SIZE +
            /* cie pointer */
            address_size + /* initial loc */
            address_size;  /* address range */
        if (dbg->de_irix_exc_augmentation &&
<<<<<<< HEAD
            strcmp(cie_ptr->cie_aug, DW_CIE_AUGMENTER_STRING_V0) == 0) {
=======
<<<<<<< HEAD
            strcmp(cie_ptr->cie_aug, DW_CIE_AUGMENTER_STRING_V0) == 0) {
=======
            strcmp(cie_ptr->cie_aug,
                DW_CIE_AUGMENTER_STRING_V0) == 0) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

            v0_augmentation = 1;
            oet_length = DWARF_32BIT_SIZE;
            /* encode the length of augmented fields. */
<<<<<<< HEAD
            res = _dwarf_pro_encode_leb128_nm(oet_length,
=======
<<<<<<< HEAD
            res = _dwarf_pro_encode_leb128_nm(oet_length,
=======
            res = dwarf_encode_leb128(oet_length,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                &afl_length, afl_buff,
                sizeof(afl_buff));
            if (res != DW_DLV_OK) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_CIE_OFFS_ALLOC,
                    DW_DLV_ERROR);
            }

            fde_length +=
                afl_length +    /* augmented field length */
                oet_length;     /* exception_table offset */
        }

        if (curfde->fde_die) {
            /*  IRIX/MIPS extension:
                Using fde offset, generate DW_AT_MIPS_fde
                attribute for the
                die corresponding to this fde.  */
            res = _dwarf_pro_add_AT_fde(dbg, curfde->fde_die, cur_off,
                error);
            if (res != DW_DLV_OK) {
                return res;
            }
        }

        /* store relocation for cie pointer */

        res = dbg->de_relocate_by_name_symbol(dbg,
            DEBUG_FRAME, cur_off +
            OFFSET_PLUS_EXTENSION_SIZE /* r_offset */,
            dbg->de_sect_name_idx[DEBUG_FRAME],
            dwarf_drt_data_reloc, offset_size);
        if (res != DW_DLV_OK) {
<<<<<<< HEAD
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC, res );
=======
<<<<<<< HEAD
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC, res );
=======
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC, res);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }

        /* store relocation information for initial location */
        res = dbg->de_relocate_by_name_symbol(dbg,
            DEBUG_FRAME,
            cur_off + OFFSET_PLUS_EXTENSION_SIZE +
<<<<<<< HEAD
                address_size /* r_offset */,
=======
<<<<<<< HEAD
                address_size /* r_offset */,
=======
            address_size /* r_offset */,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            curfde->fde_r_symidx,
            dwarf_drt_data_reloc, address_size);
        if (res != DW_DLV_OK) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC, res);
        }
        /*  Store the relocation information for the
<<<<<<< HEAD
            offset_into_exception_info field, if the offset is valid (0
=======
<<<<<<< HEAD
            offset_into_exception_info field, if the offset is valid (0
=======
            offset_into_exception_info field, if the
            offset is valid (0
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            is a valid offset). */
        if (v0_augmentation &&
            curfde->fde_offset_into_exception_tables >= 0) {

            res = dbg->de_relocate_by_name_symbol(dbg,
                DEBUG_FRAME,
                /* r_offset, where in cie this field starts */
                cur_off + OFFSET_PLUS_EXTENSION_SIZE +
<<<<<<< HEAD
                    offset_size + 2 * address_size +
                    afl_length,
=======
<<<<<<< HEAD
                    offset_size + 2 * address_size +
                    afl_length,
=======
                offset_size + 2 * address_size +
                afl_length,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                curfde->fde_exception_table_symbol,
                dwarf_drt_segment_rel,
                DWARF_32BIT_SIZE);
            if (res != DW_DLV_OK) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_CHUNK_ALLOC, res);
            }
        }

        /* adjust for padding */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        pad2 = (int) PADDING(fde_length, address_size);
        fde_length += pad2;


<<<<<<< HEAD
=======
=======
        pad2 = (int)PADDING(fde_length, address_size);
        fde_length += pad2;

>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        /* write out fde */
        GET_CHUNK(dbg, elfsectno, data, fde_length +
            OFFSET_PLUS_EXTENSION_SIZE,
            error);
        du = fde_length;
        {
            if (extension_size) {
                DISTINGUISHED_VALUE_ARRAY(v4);

<<<<<<< HEAD
                WRITE_UNALIGNED(dbg, (void *) data,
                    (const void *) &v4[0],
=======
<<<<<<< HEAD
                WRITE_UNALIGNED(dbg, (void *) data,
                    (const void *) &v4[0],
=======
                WRITE_UNALIGNED(dbg, (void*)data,
                    (const void*)&v4[0],
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    SIZEOFT32, extension_size);
                data += extension_size;
            }
            /* length */
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &du,
=======
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &du,
=======
            WRITE_UNALIGNED(dbg, (void*)data,
                (const void*)&du,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                sizeof(du), offset_size);
            data += offset_size;

            /* offset to cie */
            du = cie_offs[curfde->fde_cie - 1];
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &du,
=======
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &du,
=======
            WRITE_UNALIGNED(dbg, (void*)data,
                (const void*)&du,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                sizeof(du), offset_size);
            data += offset_size;

            du = curfde->fde_initloc;
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &du,
=======
<<<<<<< HEAD
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &du,
=======
            WRITE_UNALIGNED(dbg, (void*)data,
                (const void*)&du,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                sizeof(du), address_size);
            data += address_size;

            if (dbg->de_relocate_pair_by_symbol &&
                curfde->fde_end_symbol != 0 &&
                curfde->fde_addr_range == 0) {
                /*  symbolic reloc, need reloc for length What if we
<<<<<<< HEAD
                    really know the length? If so, should use the other
                    part of 'if'. */
                Dwarf_Unsigned val;
=======
<<<<<<< HEAD
                    really know the length? If so, should use the other
                    part of 'if'. */
                Dwarf_Unsigned val;
=======
                    really know the length? If so, should use
                    the other part of 'if'. */
                Dwarf_Unsigned val = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

                res = dbg->de_relocate_pair_by_symbol(dbg,
                    DEBUG_FRAME,
                    cur_off + 2 * offset_size + address_size,
                    /* r_offset */ curfde->fde_r_symidx,
                    curfde->fde_end_symbol,
                    dwarf_drt_first_of_length_pair,
                    address_size);
                if (res != DW_DLV_OK) {
                    {
                        _dwarf_p_error(dbg, error, DW_DLE_ALLOC_FAIL);
                        return DW_DLV_ERROR;
                    }
                }

                /*  arrange pre-calc so assem text can do .word end -
                    begin + val (gets val from stream) */
                val = curfde->fde_end_symbol_offset -
                    curfde->fde_initloc;
                WRITE_UNALIGNED(dbg, data,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    (const void *) &val,
                    sizeof(val), address_size);
                data += address_size;
            } else {
                du = curfde->fde_addr_range;
                WRITE_UNALIGNED(dbg, (void *) data,
                    (const void *) &du,
<<<<<<< HEAD
=======
=======
                    (const void*)&val,
                    sizeof(val), address_size);
                data += address_size;
            }
            else {
                du = curfde->fde_addr_range;
                WRITE_UNALIGNED(dbg, (void*)data,
                    (const void*)&du,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    sizeof(du), address_size);
                data += address_size;
            }
        }

        if (v0_augmentation) {
            /* IRIX only. */
            /* write the encoded augmented field length. */
            Dwarf_Signed dsw = 0;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            memcpy((void *) data, (const void *) afl_buff, afl_length);
            data += afl_length;
            /* write the offset_into_exception_tables field. */
            dsw = (Dwarf_Signed)curfde->fde_offset_into_exception_tables;
            WRITE_UNALIGNED(dbg, (void *) data,
                (const void *) &dsw,
<<<<<<< HEAD
=======
=======
            memcpy((void*)data, (const void*)afl_buff,
                afl_length);
            data += afl_length;
            /* write the offset_into_exception_tables field. */
            dsw = (Dwarf_Signed)
                curfde->fde_offset_into_exception_tables;
            WRITE_UNALIGNED(dbg, (void*)data,
                (const void*)&dsw,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                sizeof(dsw), DWARF_32BIT_SIZE);
            data += DWARF_32BIT_SIZE;
        }

        curinst = curfde->fde_inst;
        if (curfde->fde_block) {
            unsigned long size = curfde->fde_inst_block_size;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            memcpy((void *) data, (const void *) curfde->fde_block, size);
            data += size;
        } else {
            while (curinst) {
                db = curinst->dfp_opcode;
                WRITE_UNALIGNED(dbg, (void *) data, (const void *) &db,
                    sizeof(db), sizeof(Dwarf_Ubyte));
                data += sizeof(Dwarf_Ubyte);
                memcpy((void *) data,
                    (const void *) curinst->dfp_args,
<<<<<<< HEAD
=======
=======
            memcpy((void*)data, (const void*)curfde->fde_block,
                size);
            data += size;
        }
        else {
            while (curinst) {
                db = curinst->dfp_opcode;
                WRITE_UNALIGNED(dbg, (void*)data,
                    (const void*)&db,
                    sizeof(db), sizeof(Dwarf_Ubyte));
                data += sizeof(Dwarf_Ubyte);
                memcpy((void*)data,
                    (const void*)curinst->dfp_args,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    curinst->dfp_nbytes);
                data += curinst->dfp_nbytes;
                curinst = curinst->dfp_next;
            }
        }
        /* padding */
        for (i = 0; i < pad2; i++) {
            *data = DW_CFA_nop;
            data++;
        }
        cur_off += fde_length + offset_size;
        curfde = curfde->fde_next;
    }

<<<<<<< HEAD

    *nbufs =  dbg->de_n_debug_sect;
=======
<<<<<<< HEAD

    *nbufs =  dbg->de_n_debug_sect;
=======
    *nbufs = dbg->de_n_debug_sect;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    return DW_DLV_OK;
}

/*
  These functions remember all the markers we see along
  with the right offset in the .debug_info section so that
  we can dump them all back to the user with the section info.
*/

static int
marker_init(Dwarf_P_Debug dbg,
    unsigned count)
{
    dbg->de_marker_n_alloc = count;
    dbg->de_markers = NULL;
    if (count > 0) {
        dbg->de_markers = _dwarf_p_get_alloc(dbg,
            sizeof(struct Dwarf_P_Marker_s) * dbg->de_marker_n_alloc);
        if (dbg->de_markers == NULL) {
            dbg->de_marker_n_alloc = 0;
            return DW_DLV_ERROR;
        }
    }
    return DW_DLV_OK;
}

static int
marker_add(Dwarf_P_Debug dbg,
    Dwarf_Unsigned offset,
    Dwarf_Unsigned marker)
{
    if (dbg->de_marker_n_alloc >= (dbg->de_marker_n_used + 1)) {
        unsigned n = dbg->de_marker_n_used++;
        dbg->de_markers[n].ma_offset = offset;
        dbg->de_markers[n].ma_marker = marker;
        return DW_DLV_OK;
    }
    return DW_DLV_ERROR;
}

Dwarf_Signed
dwarf_get_die_markers(Dwarf_P_Debug dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_P_Marker * marker_list, /* pointer to a pointer */
    Dwarf_Unsigned * marker_count,
    Dwarf_Error * error)
{
    int res = 0;

    res = dwarf_get_die_markers_a(dbg,marker_list,marker_count,
<<<<<<< HEAD
=======
=======
    Dwarf_P_Marker* marker_list, /* pointer to a pointer */
    Dwarf_Unsigned* marker_count,
    Dwarf_Error* error)
{
    int res = 0;

    res = dwarf_get_die_markers_a(dbg, marker_list, marker_count,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        error);
    if (res == DW_DLV_ERROR) {
        return DW_DLV_BADADDR;
    }
    return 0;
}

int
dwarf_get_die_markers_a(Dwarf_P_Debug dbg,
<<<<<<< HEAD
    Dwarf_P_Marker * marker_list, /* pointer to a pointer */
    Dwarf_Unsigned * marker_count,
    Dwarf_Error * error)
=======
<<<<<<< HEAD
    Dwarf_P_Marker * marker_list, /* pointer to a pointer */
    Dwarf_Unsigned * marker_count,
    Dwarf_Error * error)
=======
    Dwarf_P_Marker* marker_list, /* pointer to a pointer */
    Dwarf_Unsigned* marker_count,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    if (marker_list == NULL || marker_count == NULL) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_IA, DW_DLV_ERROR);
    }
    if (dbg->de_marker_n_used != dbg->de_marker_n_alloc) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_MAF, DW_DLV_ERROR);
    }

    *marker_list = dbg->de_markers;
    *marker_count = dbg->de_marker_n_used;
    return DW_DLV_OK;
}

/*  These functions provide the offsets of DW_FORM_string
    attributes in the section section_index. These information
    will enable a producer app that is generating assembly
    text output to easily emit those attributes in ascii form
    without having to decode the byte stream.  */
static int
<<<<<<< HEAD
string_attr_init (Dwarf_P_Debug dbg,
=======
<<<<<<< HEAD
string_attr_init (Dwarf_P_Debug dbg,
=======
string_attr_init(Dwarf_P_Debug dbg,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Signed section_index,
    unsigned count)
{
    Dwarf_P_Per_Sect_String_Attrs sect_sa =
        &dbg->de_sect_string_attr[section_index];

    sect_sa->sect_sa_n_alloc = count;
    sect_sa->sect_sa_list = NULL;
    if (count > 0) {
        sect_sa->sect_sa_section_number = section_index;
        sect_sa->sect_sa_list = _dwarf_p_get_alloc(dbg,
<<<<<<< HEAD
            sizeof(struct Dwarf_P_String_Attr_s) * sect_sa->sect_sa_n_alloc);
=======
<<<<<<< HEAD
            sizeof(struct Dwarf_P_String_Attr_s) * sect_sa->sect_sa_n_alloc);
=======
            sizeof(struct Dwarf_P_String_Attr_s) *
            sect_sa->sect_sa_n_alloc);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (sect_sa->sect_sa_list == NULL) {
            sect_sa->sect_sa_n_alloc = 0;
            return DW_DLV_ERROR;
        }
    }
    return DW_DLV_OK;
}

static int
<<<<<<< HEAD
string_attr_add (Dwarf_P_Debug dbg,
=======
<<<<<<< HEAD
string_attr_add (Dwarf_P_Debug dbg,
=======
string_attr_add(Dwarf_P_Debug dbg,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Signed section_index,
    Dwarf_Unsigned offset,
    Dwarf_P_Attribute attr)
{
<<<<<<< HEAD
    Dwarf_P_Per_Sect_String_Attrs sect_sa = &dbg->de_sect_string_attr[section_index];
=======
<<<<<<< HEAD
    Dwarf_P_Per_Sect_String_Attrs sect_sa = &dbg->de_sect_string_attr[section_index];
=======
    Dwarf_P_Per_Sect_String_Attrs sect_sa =
        &dbg->de_sect_string_attr[section_index];
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    if (sect_sa->sect_sa_n_alloc >= (sect_sa->sect_sa_n_used + 1)) {
        unsigned n = sect_sa->sect_sa_n_used++;
        sect_sa->sect_sa_list[n].sa_offset = offset;
        sect_sa->sect_sa_list[n].sa_nbytes = attr->ar_nbytes;
        return DW_DLV_OK;
    }

    return DW_DLV_ERROR;
}

int
dwarf_get_string_attributes_count(Dwarf_P_Debug dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Unsigned *
    count_of_sa_sections,
    int *drd_buffer_version,
    UNUSEDARG Dwarf_Error *error)
<<<<<<< HEAD
=======
=======
    Dwarf_Unsigned*
    count_of_sa_sections,
    int* drd_buffer_version,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    int i = 0;
    unsigned int count = 0;

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    (void)error;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    for (i = 0; i < NUM_DEBUG_SECTIONS; ++i) {
        if (dbg->de_sect_string_attr[i].sect_sa_n_used > 0) {
            ++count;
        }
    }
<<<<<<< HEAD
    *count_of_sa_sections = (Dwarf_Unsigned) count;
=======
<<<<<<< HEAD
    *count_of_sa_sections = (Dwarf_Unsigned) count;
=======
    *count_of_sa_sections = (Dwarf_Unsigned)count;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    *drd_buffer_version = DWARF_DRD_BUFFER_VERSION;

    return DW_DLV_OK;
}

int
dwarf_get_string_attributes_info(Dwarf_P_Debug dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Signed *elf_section_index,
    Dwarf_Unsigned *sect_sa_buffer_count,
    Dwarf_P_String_Attr *sect_sa_buffer,
    UNUSEDARG Dwarf_Error *error)
<<<<<<< HEAD
=======
=======
    Dwarf_Signed* elf_section_index,
    Dwarf_Unsigned* sect_sa_buffer_count,
    Dwarf_P_String_Attr* sect_sa_buffer,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    int i = 0;
    int next = dbg->de_sect_sa_next_to_return;

<<<<<<< HEAD
    for (i = next; i < NUM_DEBUG_SECTIONS; ++i) {
        Dwarf_P_Per_Sect_String_Attrs sect_sa = &dbg->de_sect_string_attr[i];
=======
<<<<<<< HEAD
    for (i = next; i < NUM_DEBUG_SECTIONS; ++i) {
        Dwarf_P_Per_Sect_String_Attrs sect_sa = &dbg->de_sect_string_attr[i];
=======
    (void)error;
    for (i = next; i < NUM_DEBUG_SECTIONS; ++i) {
        Dwarf_P_Per_Sect_String_Attrs sect_sa =
            &dbg->de_sect_string_attr[i];
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (sect_sa->sect_sa_n_used > 0) {
            dbg->de_sect_sa_next_to_return = i + 1;
            *elf_section_index = sect_sa->sect_sa_section_number;
            *sect_sa_buffer_count = sect_sa->sect_sa_n_used;
            *sect_sa_buffer = sect_sa->sect_sa_list;
            return DW_DLV_OK;
        }
    }
    return DW_DLV_NO_ENTRY;
}

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
static int
has_sibling_die_already(Dwarf_P_Die d)
{
    Dwarf_P_Attribute a = 0;
<<<<<<< HEAD
    for(a = d->di_attrs; a ; a = a->ar_next) {
        if(a->ar_attribute == DW_AT_sibling) {
=======
<<<<<<< HEAD
    for(a = d->di_attrs; a ; a = a->ar_next) {
        if(a->ar_attribute == DW_AT_sibling) {
=======
    for (a = d->di_attrs; a; a = a->ar_next) {
        if (a->ar_attribute == DW_AT_sibling) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            return TRUE;
        }
    }
    return FALSE;
}

/*  For DW_FORM_strp we need to set the symindex so we need
    to check that such applies.  */
static int
<<<<<<< HEAD
if_relocatable_string_form(Dwarf_P_Debug dbg, Dwarf_P_Attribute curattr,
    int *debug_str_reloc,
    Dwarf_Error *error)
=======
<<<<<<< HEAD
if_relocatable_string_form(Dwarf_P_Debug dbg, Dwarf_P_Attribute curattr,
    int *debug_str_reloc,
    Dwarf_Error *error)
=======
if_relocatable_string_form(Dwarf_P_Debug dbg,
    Dwarf_P_Attribute curattr,
    int* debug_str_reloc,
    Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    if (curattr->ar_rel_type == R_MIPS_NONE) {
        *debug_str_reloc = 0;
        return DW_DLV_OK;
    }
    if (curattr->ar_attribute_form != DW_FORM_strp) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        _dwarf_p_error(dbg, error,DW_DLE_DEBUGSTR_UNEXPECTED_REL);
        return DW_DLV_ERROR;
    }
    if (curattr->ar_rel_type != dbg->de_offset_reloc) {
        _dwarf_p_error(dbg, error,DW_DLE_DEBUGSTR_UNEXPECTED_REL);
<<<<<<< HEAD
=======
=======
        _dwarf_p_error(dbg, error, DW_DLE_DEBUGSTR_UNEXPECTED_REL);
        return DW_DLV_ERROR;
    }
    if (curattr->ar_rel_type != dbg->de_offset_reloc) {
        _dwarf_p_error(dbg, error, DW_DLE_DEBUGSTR_UNEXPECTED_REL);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        return DW_DLV_ERROR;
    }
    *debug_str_reloc = 1;
    return DW_DLV_OK;
}

/*  Tries to see if given attribute and form combination
    of the attr exists in the given abbreviation.
    abbrevs and attrs are sorted in attrnum order. */
static int
_dwarf_pro_match_attr(Dwarf_P_Attribute attr,
    Dwarf_P_Abbrev abbrev, int no_attr)
{
    int i = 0;
    Dwarf_P_Attribute curatp = attr;

<<<<<<< HEAD
    for (i = 0; i < no_attr && curatp; i++,curatp = curatp->ar_next ) {
=======
<<<<<<< HEAD
    for (i = 0; i < no_attr && curatp; i++,curatp = curatp->ar_next ) {
=======
    for (i = 0; i < no_attr && curatp;
        i++, curatp = curatp->ar_next) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (curatp->ar_attribute != abbrev->abb_attrs[i] ||
            curatp->ar_attribute_form != abbrev->abb_forms[i]) {
            return 0;
        }
        /*  If either is implicit_const need special
            check for matching val. */
        if (curatp->ar_attribute_form == DW_FORM_implicit_const) {
            if (abbrev->abb_forms[i] == DW_FORM_implicit_const) {
                if (curatp->ar_implicit_const !=
                    abbrev->abb_implicits[i]) {
                    return 0;
                }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            } else {
                return 0;
            }
        } else {
<<<<<<< HEAD
=======
=======
            }
            else {
                return 0;
            }
        }
        else {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            if (abbrev->abb_forms[i] == DW_FORM_implicit_const) {
                return 0;
            }
        }
    }
    return 1;
}

static int
<<<<<<< HEAD
verify_ab_no_dups(struct Dwarf_Sort_Abbrev_s *sortab,
=======
<<<<<<< HEAD
verify_ab_no_dups(struct Dwarf_Sort_Abbrev_s *sortab,
=======
verify_ab_no_dups(struct Dwarf_Sort_Abbrev_s* sortab,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    int attrcount)
{
    int k = 0;
    unsigned preva = 0;
<<<<<<< HEAD
    struct Dwarf_Sort_Abbrev_s *ab = sortab;
=======
<<<<<<< HEAD
    struct Dwarf_Sort_Abbrev_s *ab = sortab;
=======
    struct Dwarf_Sort_Abbrev_s* ab = sortab;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    if (attrcount < 2) {
        return DW_DLV_OK;
    }
<<<<<<< HEAD
    for(k = 0; k < attrcount; ++k,++ab) {
=======
<<<<<<< HEAD
    for(k = 0; k < attrcount; ++k,++ab) {
=======
    for (k = 0; k < attrcount; ++k, ++ab) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (k) {
            if (preva >= ab->dsa_attr) {
                return DW_DLV_ERROR;
            }
        }
        preva = ab->dsa_attr;
    }
    return DW_DLV_OK;
}

static int
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
abcompare(const void *l_in, const void *r_in)
{
    struct Dwarf_Sort_Abbrev_s *l =
        (struct Dwarf_Sort_Abbrev_s *)l_in;
    struct Dwarf_Sort_Abbrev_s *r =
        (struct Dwarf_Sort_Abbrev_s *)r_in;
<<<<<<< HEAD
=======
=======
abcompare(const void* l_in, const void* r_in)
{
    struct Dwarf_Sort_Abbrev_s* l =
        (struct Dwarf_Sort_Abbrev_s*)l_in;
    struct Dwarf_Sort_Abbrev_s* r =
        (struct Dwarf_Sort_Abbrev_s*)r_in;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    if (l->dsa_attr < r->dsa_attr) {
        return -1;
    }
    if (l->dsa_attr > r->dsa_attr) {
        return +1;
    }
    /* ASSERT: This never happens in correct dwarf. */
    return 0;
}

/*  Handles abbreviations. It takes a die, searches through
    current list of abbreviations for a matching one. If it
    finds one, it returns a pointer to the abbrev through
    the ab_out pointer, and if it does not,
    it returns a new abbrev through the ab_out pointer.

    The die->die_attrs are sorted by attribute and the curabbrev
    attrs are too.

    It is up to the user of this function to
    link it up to the abbreviation head. If it is a new abbrev
    abb_idx has 0. */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
static int
_dwarf_pro_getabbrev(Dwarf_P_Debug dbg,
    Dwarf_P_Die die, Dwarf_P_Abbrev head,
    Dwarf_P_Abbrev*ab_out,Dwarf_Error *error)
{
    Dwarf_P_Abbrev curabbrev = 0;
    Dwarf_P_Attribute curattr = 0;
    int match = 0;
    Dwarf_Unsigned *forms = 0;
    Dwarf_Unsigned *attrs = 0;
    Dwarf_Signed *implicits = 0;
    int attrcount = die->di_n_attr;

    curabbrev = head;
    /*  Loop thru the currently known abbreviations needed
        to see if we can share an existing abbrev.  */
    while (curabbrev) {
        if ((die->di_tag == curabbrev->abb_tag) &&
            ((die->di_child != NULL &&
            curabbrev->abb_children == DW_CHILDREN_yes) ||
            (die->di_child == NULL &&
            curabbrev->abb_children == DW_CHILDREN_no)) &&
            (attrcount == curabbrev->abb_n_attr)) {

            /*  There is a chance of a match, basic
                characterists match. Now Check the attrs and
                forms. */
            curattr = die->di_attrs;
            match = _dwarf_pro_match_attr(curattr,
                curabbrev,
                (int) curabbrev->abb_n_attr);
            if (match == 1) {
                /*  This tag/children/abbrev-list matches
                    the incoming die needs exactly. Reuse
                    this abbreviation. */
                *ab_out = curabbrev;
                return DW_DLV_OK;
<<<<<<< HEAD
=======
=======
static Dwarf_P_Abbrev
_dwarf_pro_getabbrev(Dwarf_P_Die die, Dwarf_P_Abbrev head)
{
    Dwarf_P_Abbrev curabbrev;
    Dwarf_P_Attribute curattr;
    int res1;
    int nattrs;
    int match;
    Dwarf_Unsigned* forms = 0;
    Dwarf_Unsigned* attrs = 0;

    curabbrev = head;
    while (curabbrev) {
        if ((die->di_tag == curabbrev->abb_tag) &&
            ((die->di_child != NULL &&
                curabbrev->abb_children == DW_CHILDREN_yes) ||
                (die->di_child == NULL &&
                    curabbrev->abb_children == DW_CHILDREN_no)) &&
            (die->di_n_attr == curabbrev->abb_n_attr)) {

            /* There is a chance of a match. */
            curattr = die->di_attrs;
            match = 1;          /* Assume match found. */
            while (match && curattr) {
                res1 = _dwarf_pro_match_attr(curattr,
                    curabbrev,
                    (int)curabbrev->
                    abb_n_attr);
                if (res1 == 0) {
                    match = 0;
                }
                curattr = curattr->ar_next;
            }
            if (match == 1) {
                return curabbrev;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            }
        }
        curabbrev = curabbrev->abb_next;
    }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    /* no match, create new abbreviation */
    if (attrcount) {
        forms = (Dwarf_Unsigned *)
            _dwarf_p_get_alloc(die->di_dbg,
                sizeof(Dwarf_Unsigned) * attrcount);
        if (forms == NULL) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
        }
        attrs = (Dwarf_Unsigned *)
            _dwarf_p_get_alloc(die->di_dbg,
                sizeof(Dwarf_Unsigned) * attrcount);
        if (attrs == NULL) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
        }
        implicits = (Dwarf_Signed *)
            _dwarf_p_get_alloc(die->di_dbg,
                sizeof(Dwarf_Signed) * attrcount);
        if (implicits == NULL) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
        }
    }
    curattr = die->di_attrs;
    if (forms && attrs && attrcount) {
        struct Dwarf_Sort_Abbrev_s *sortab = 0;
        struct Dwarf_Sort_Abbrev_s *ap = 0;
        int k = 0;
        int res = 0;

        sortab = (struct Dwarf_Sort_Abbrev_s *)
            malloc(sizeof(struct Dwarf_Sort_Abbrev_s)*attrcount);
        if(!sortab) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
        }
        /*  ASSERT curattr->ar_next chain length == attrcount  */
        ap = sortab;
        for(; curattr; ++ap, curattr = curattr->ar_next) {
            ap->dsa_attr = curattr->ar_attribute;
            ap->dsa_form = curattr->ar_attribute_form;
            ap->dsa_implicitvalue = curattr->ar_implicit_const;
            ap->dsa_attrp = 0;
        }

        qsort(sortab,attrcount,sizeof(struct Dwarf_Sort_Abbrev_s),
            abcompare);
        ap = sortab;
        k = 0;
        res = verify_ab_no_dups(sortab,attrcount);
        if (res != DW_DLV_OK) {
            DWARF_P_DBG_ERROR(dbg,DW_DLE_DUP_ATTR_ON_DIE,DW_DLV_ERROR);
        }
        for( ; k < attrcount; ++k,++ap) {
            attrs[k] = ap->dsa_attr;
            forms[k] = ap->dsa_form;
            implicits[k] = ap->dsa_implicitvalue;
        }
        free(sortab);
<<<<<<< HEAD
=======
=======

    /* no match, create new abbreviation */
    if (die->di_n_attr != 0) {
        forms = (Dwarf_Unsigned*)
            _dwarf_p_get_alloc(die->di_dbg,
                sizeof(Dwarf_Unsigned) * die->di_n_attr);
        if (forms == NULL) {
            return NULL;
        }
        attrs = (Dwarf_Unsigned*)
            _dwarf_p_get_alloc(die->di_dbg,
                sizeof(Dwarf_Unsigned) * die->di_n_attr);
        if (attrs == NULL)
            return NULL;
    }
    nattrs = 0;
    curattr = die->di_attrs;
    while (curattr) {
        attrs[nattrs] = curattr->ar_attribute;
        forms[nattrs] = curattr->ar_attribute_form;
        nattrs++;
        curattr = curattr->ar_next;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    }

    curabbrev = (Dwarf_P_Abbrev)
        _dwarf_p_get_alloc(die->di_dbg, sizeof(struct Dwarf_P_Abbrev_s));
    if (curabbrev == NULL) {
<<<<<<< HEAD
        DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
=======
<<<<<<< HEAD
        DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
=======
        return NULL;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    }

    if (die->di_child == NULL) {
        curabbrev->abb_children = DW_CHILDREN_no;
<<<<<<< HEAD
    } else {
=======
<<<<<<< HEAD
    } else {
=======
    }
    else {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        curabbrev->abb_children = DW_CHILDREN_yes;
    }
    curabbrev->abb_tag = die->di_tag;
    curabbrev->abb_attrs = attrs;
    curabbrev->abb_forms = forms;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    curabbrev->abb_implicits = implicits;
    curabbrev->abb_n_attr = attrcount;
    curabbrev->abb_idx = 0;
    curabbrev->abb_next = NULL;
    *ab_out = curabbrev;
    return DW_DLV_OK;
}

/* Generate debug_info and debug_abbrev sections */


/*  DWARF 2,3,4  */
static int
generate_debuginfo_header_2(Dwarf_P_Debug dbg,
    unsigned *abbrev_offset_io,
    unsigned char **data_io,
    int     *cu_header_size_out,
    Dwarf_Small **abbr_off_ptr_out,
    Dwarf_Half version,
    int extension_size,
    Dwarf_Ubyte address_size,
    Dwarf_Error * error)
{
    unsigned abbrev_offset = 0;
    unsigned char * data = 0;
<<<<<<< HEAD
=======
=======
    curabbrev->abb_n_attr = die->di_n_attr;
    curabbrev->abb_idx = 0;
    curabbrev->abb_next = NULL;

    return curabbrev;
}

/* Generate debug_info and debug_abbrev sections */
/*  DWARF 2,3,4  */
static int
generate_debuginfo_header_2(Dwarf_P_Debug dbg,
    unsigned* abbrev_offset_io,
    unsigned char** data_io,
    int* cu_header_size_out,
    Dwarf_Small** abbr_off_ptr_out,
    Dwarf_Half version,
    int extension_size,
    Dwarf_Ubyte address_size,
    Dwarf_Error* error)
{
    unsigned abbrev_offset = 0;
    unsigned char* data = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    int offset_size = dbg->de_dwarf_offset_size;
    int elfsectno_of_debug_info = dbg->de_elf_sects[DEBUG_INFO];
    int cu_header_size = 0;
    Dwarf_Unsigned du = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Small *abbr_off_ptr = 0;

    /* write cu header. abbrev_offset used to
        generate relocation record below */
    abbrev_offset =  OFFSET_PLUS_EXTENSION_SIZE +
        DWARF_HALF_SIZE  ;
<<<<<<< HEAD
=======
=======
    Dwarf_Small* abbr_off_ptr = 0;

    /* write cu header. abbrev_offset used to
        generate relocation record below */
    abbrev_offset = OFFSET_PLUS_EXTENSION_SIZE +
        DWARF_HALF_SIZE;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    cu_header_size = abbrev_offset +
        offset_size + sizeof(Dwarf_Ubyte);

    GET_CHUNK_ERR(dbg, elfsectno_of_debug_info, data, cu_header_size,
        error);
    if (extension_size) {
        /* This for a dwarf-standard 64bit offset. */
        DISTINGUISHED_VALUE_ARRAY(v4);

<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data,
            (const void *) &v4[0], SIZEOFT32, extension_size);
=======
<<<<<<< HEAD
        WRITE_UNALIGNED(dbg, (void *) data,
            (const void *) &v4[0], SIZEOFT32, extension_size);
=======
        WRITE_UNALIGNED(dbg, (void*)data,
            (const void*)&v4[0], SIZEOFT32, extension_size);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        data += extension_size;
    }
    abbr_off_ptr = data;
    du = 0; /* length of debug_info, not counting
        this field itself (unknown at this point). */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    WRITE_UNALIGNED(dbg, (void *) data,
        (const void *) &du, sizeof(du), offset_size);
    data += offset_size;

    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &version,
<<<<<<< HEAD
=======
=======
    WRITE_UNALIGNED(dbg, (void*)data,
        (const void*)&du, sizeof(du), offset_size);
    data += offset_size;

    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&version,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof(version), DWARF_HALF_SIZE);
    data += DWARF_HALF_SIZE;

    du = 0;/* offset into abbrev table, not yet known. */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    WRITE_UNALIGNED(dbg, (void *) data,
        (const void *) &du, sizeof(du), offset_size);
    data += offset_size;

    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &address_size,
<<<<<<< HEAD
=======
=======
    WRITE_UNALIGNED(dbg, (void*)data,
        (const void*)&du, sizeof(du), offset_size);
    data += offset_size;

    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&address_size,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof(address_size), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);

    /*  We have filled the chunk we got with GET_CHUNK.
        At this point we
        no longer dare use "data"  as a
        pointer any longer except to refer to that first
        small chunk for the cu header to update
        the section length. */
    *abbrev_offset_io = abbrev_offset;
    *data_io = data;
    *cu_header_size_out = cu_header_size;
    *abbr_off_ptr_out = abbr_off_ptr;
    return DW_DLV_OK;
}

/*  DWARF 5 */
static int
generate_debuginfo_header_5(Dwarf_P_Debug dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned       *abbrev_offset_io,
    unsigned char **data_io,
    int            *cu_header_size_out,
    Dwarf_Small   **abbr_off_ptr_out,
<<<<<<< HEAD
=======
=======
    unsigned* abbrev_offset_io,
    unsigned char** data_io,
    int* cu_header_size_out,
    Dwarf_Small** abbr_off_ptr_out,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Half      version,
    Dwarf_Ubyte     unit_type,
    int             extension_size,
    Dwarf_Ubyte     address_size,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Error    *error)
{
    int offset_size = dbg->de_dwarf_offset_size;
    unsigned abbrev_offset = 0;
    unsigned char * data = 0;
    int elfsectno_of_debug_info = dbg->de_elf_sects[DEBUG_INFO];
    int cu_header_size = 0;
    Dwarf_Unsigned du = 0;
    Dwarf_Small *abbr_off_ptr = 0;


    /*  write cu header. abbrev_offset used to
        generate relocation record below */
    abbrev_offset =  OFFSET_PLUS_EXTENSION_SIZE +
<<<<<<< HEAD
=======
=======
    Dwarf_Error* error)
{
    int offset_size = dbg->de_dwarf_offset_size;
    unsigned abbrev_offset = 0;
    unsigned char* data = 0;
    int elfsectno_of_debug_info = dbg->de_elf_sects[DEBUG_INFO];
    int cu_header_size = 0;
    Dwarf_Unsigned du = 0;
    Dwarf_Small* abbr_off_ptr = 0;

    /*  write cu header. abbrev_offset used to
        generate relocation record below */
    abbrev_offset = OFFSET_PLUS_EXTENSION_SIZE +
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        DWARF_HALF_SIZE + /* version stamp */
        sizeof(unit_type) +
        sizeof(Dwarf_Ubyte);
    cu_header_size = abbrev_offset + offset_size;

    GET_CHUNK_ERR(dbg, elfsectno_of_debug_info, data, cu_header_size,
        error);
    if (extension_size) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        /* Impossible in DW5, really, is for IRIX64. But we allow it. */
        DISTINGUISHED_VALUE_ARRAY(v4);

        WRITE_UNALIGNED(dbg, (void *) data,
            (const void *) &v4[0], SIZEOFT32, extension_size);
<<<<<<< HEAD
=======
=======
        /* Impossible in DW5, really, is for IRIX64.
        But we allow it. */
        DISTINGUISHED_VALUE_ARRAY(v4);

        WRITE_UNALIGNED(dbg, (void*)data,
            (const void*)&v4[0], SIZEOFT32, extension_size);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        data += extension_size;
    }
    abbr_off_ptr = data;
    du = 0; /* length of debug_info, not counting
        this field itself (unknown at this point). */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    WRITE_UNALIGNED(dbg, (void *) data,
        (const void *) &du, sizeof(du), offset_size);
    data += offset_size;

    WRITE_UNALIGNED(dbg, (void *) data,
        (const void *) &version,
        sizeof(version), DWARF_HALF_SIZE);
    data += DWARF_HALF_SIZE;

    WRITE_UNALIGNED(dbg, (void *) data,
        (const void *) &unit_type,
        sizeof(unit_type), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);

    WRITE_UNALIGNED(dbg, (void *) data, (const void *) &address_size,
<<<<<<< HEAD
=======
=======
    WRITE_UNALIGNED(dbg, (void*)data,
        (const void*)&du, sizeof(du), offset_size);
    data += offset_size;

    WRITE_UNALIGNED(dbg, (void*)data,
        (const void*)&version,
        sizeof(version), DWARF_HALF_SIZE);
    data += DWARF_HALF_SIZE;

    WRITE_UNALIGNED(dbg, (void*)data,
        (const void*)&unit_type,
        sizeof(unit_type), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);

    WRITE_UNALIGNED(dbg, (void*)data, (const void*)&address_size,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        sizeof(address_size), sizeof(Dwarf_Ubyte));
    data += sizeof(Dwarf_Ubyte);

    du = 0;/* offset into abbrev table, not yet known. */
<<<<<<< HEAD
    WRITE_UNALIGNED(dbg, (void *) data,
        (const void *) &du, sizeof(du), offset_size);
=======
<<<<<<< HEAD
    WRITE_UNALIGNED(dbg, (void *) data,
        (const void *) &du, sizeof(du), offset_size);
=======
    WRITE_UNALIGNED(dbg, (void*)data,
        (const void*)&du, sizeof(du), offset_size);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    data += offset_size;

    /*  We have filled the chunk we got with GET_CHUNK.
        At this point we
        no longer dare use "data" as a pointer any
        longer except to refer to that first small chunk for the cu
        header to update the section length. */

    *abbrev_offset_io = abbrev_offset;
    *data_io = data;
    *cu_header_size_out = cu_header_size;
    *abbr_off_ptr_out = abbr_off_ptr;
    return DW_DLV_OK;
}

/* Write out debug_abbrev section */
static int
write_out_debug_abbrev(Dwarf_P_Debug dbg,
    Dwarf_P_Abbrev abbrev_head,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Error * error)
{
    Dwarf_P_Abbrev curabbrev = abbrev_head;
    unsigned char *data = 0;
<<<<<<< HEAD
=======
=======
    Dwarf_Error* error)
{
    Dwarf_P_Abbrev curabbrev = abbrev_head;
    unsigned char* data = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    int res = 0;
    int abbrevsectno = dbg->de_elf_sects[DEBUG_ABBREV];

    while (curabbrev) {
        int idx = 0;
        unsigned lebcount = 0;
        Dwarf_Ubyte db = 0;

<<<<<<< HEAD
        res  = write_uval(curabbrev->abb_idx,dbg,abbrevsectno,
            &lebcount,error);
=======
<<<<<<< HEAD
        res  = write_uval(curabbrev->abb_idx,dbg,abbrevsectno,
            &lebcount,error);
=======
        res = write_uval(curabbrev->abb_idx, dbg, abbrevsectno,
            &lebcount, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res != DW_DLV_OK) {
            return res;
        }

<<<<<<< HEAD
        res  = write_uval(curabbrev->abb_tag,dbg,abbrevsectno,
            &lebcount,error);
=======
<<<<<<< HEAD
        res  = write_uval(curabbrev->abb_tag,dbg,abbrevsectno,
            &lebcount,error);
=======
        res = write_uval(curabbrev->abb_tag, dbg, abbrevsectno,
            &lebcount, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res != DW_DLV_OK) {
            return res;
        }

        db = curabbrev->abb_children;
<<<<<<< HEAD
        res = write_ubyte(db,dbg,abbrevsectno,&lebcount,error);
=======
<<<<<<< HEAD
        res = write_ubyte(db,dbg,abbrevsectno,&lebcount,error);
=======
        res = write_ubyte(db, dbg, abbrevsectno, &lebcount, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res != DW_DLV_OK) {
            return res;
        }

        /* add attributes and forms */
        for (idx = 0; idx < curabbrev->abb_n_attr; idx++) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            res =write_uval(curabbrev->abb_attrs[idx],
                dbg,abbrevsectno,
                &lebcount,error);
            if (res != DW_DLV_OK) {
                return res;
            }
            res =write_uval(curabbrev->abb_forms[idx],
                dbg,abbrevsectno,
                &lebcount,error);
            if (res != DW_DLV_OK) {
                return res;
            }
            if (curabbrev->abb_forms[idx] == DW_FORM_implicit_const){
                res =write_sval(curabbrev->abb_implicits[idx],
                    dbg,abbrevsectno,
                    &lebcount,error);
<<<<<<< HEAD
=======
=======
            res = write_uval(curabbrev->abb_attrs[idx],
                dbg, abbrevsectno,
                &lebcount, error);
            if (res != DW_DLV_OK) {
                return res;
            }
            res = write_uval(curabbrev->abb_forms[idx],
                dbg, abbrevsectno,
                &lebcount, error);
            if (res != DW_DLV_OK) {
                return res;
            }
            if (curabbrev->abb_forms[idx] == DW_FORM_implicit_const) {
                res = write_sval(curabbrev->abb_implicits[idx],
                    dbg, abbrevsectno,
                    &lebcount, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                if (res != DW_DLV_OK) {
                    return res;
                }
            }
        }
        /* Two zeros, for last entry, see dwarf2 sec 7.5.3 */
        GET_CHUNK_ERR(dbg, abbrevsectno, data, 2, error);
        *data = 0;
        data++;
        *data = 0;

        curabbrev = curabbrev->abb_next;
    }
    /* one zero, for end of cu, see dwarf2 sec 7.5.3 */
    GET_CHUNK_ERR(dbg, abbrevsectno, data, 1, error);
    *data = 0;
    return DW_DLV_OK;
}

static int
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
sort_die_attrs(Dwarf_P_Debug dbg,Dwarf_P_Die die,
    Dwarf_Error *error)
{
    struct Dwarf_Sort_Abbrev_s *sortab = 0;
    struct Dwarf_Sort_Abbrev_s *ap = 0;
    Dwarf_P_Attribute at = 0;
    Dwarf_P_Attribute sorted_attrlist = 0;
    Dwarf_P_Attribute sorted_tail = 0;
    int attrcount = die->di_n_attr;
    int res = 0;
    unsigned ct = 0;

    int k = 0;

    if (attrcount < 2) {
        return DW_DLV_OK;
    }

    sortab = (struct Dwarf_Sort_Abbrev_s *)
        malloc(sizeof(struct Dwarf_Sort_Abbrev_s)*attrcount);
    if(!sortab) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
    }
    /*  ASSERT at->ar_next chain length == attrcount  */
    ap = sortab;
    at = die->di_attrs;
    for(; at; ++ap, at = at->ar_next) {
        ap->dsa_attr = at->ar_attribute;
        ap->dsa_form = at->ar_attribute_form;
        ap->dsa_attrp = at;
        ++ct;
    }
    qsort(sortab,attrcount,sizeof(struct Dwarf_Sort_Abbrev_s),
        abcompare);
    res = verify_ab_no_dups(sortab,attrcount);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_DUP_ATTR_ON_DIE, DW_DLV_ERROR);
    }
    ap = sortab;
    k = 0;
    for( ; k < attrcount; ++k,++ap) {
        Dwarf_P_Attribute localptr = ap->dsa_attrp;
        if (!sorted_attrlist) {
            sorted_attrlist = localptr;
            sorted_tail = sorted_attrlist;
            localptr->ar_next = 0;
            continue;
        }
        sorted_tail->ar_next  = localptr;
        sorted_tail = localptr;
        localptr->ar_next = 0;
    }
    /*  Now replace the list with the same pointers
        but in order sorted by attribute. */
    die->di_attrs = sorted_attrlist;
    free(sortab);
    return DW_DLV_OK;
}



static int
_dwarf_pro_generate_debuginfo(Dwarf_P_Debug dbg,
    Dwarf_Signed *nbufs,
    Dwarf_Error * error)
{
    int elfsectno_of_debug_info = 0;
    unsigned char *data = 0;
<<<<<<< HEAD
=======
=======
_dwarf_pro_generate_debugsup(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs,
    Dwarf_Error* error)
{
    int elfsectno = 0;
    unsigned char* data = 0;
    Dwarf_Half version = 0;
    unsigned int uleblen = 0;
    int leblen = 0;
    unsigned i = 0;
    unsigned name_len = 0;
    Dwarf_Unsigned alloc_size = 0;
    int res = 0;

    elfsectno = dbg->de_elf_sects[DEBUG_SUP];
    res = pretend_write_uval(dbg->de_debug_sup.ds_checksum_len,
        dbg, &uleblen, error);
    if (res != DW_DLV_OK) {
        return res;
    }
    version = dbg->de_debug_sup.ds_version;
    name_len = strlen(dbg->de_debug_sup.ds_filename) + 1;
    alloc_size = DWARF_HALF_SIZE +
        1 + name_len +
        uleblen + dbg->de_debug_sup.ds_checksum_len;
    GET_CHUNK_ERR(dbg, elfsectno, data, alloc_size, error);

    WRITE_UNALIGNED(dbg, (void*)data,
        (const void*)&version, DWARF_HALF_SIZE, DWARF_HALF_SIZE);
    data += DWARF_HALF_SIZE;

    *data = dbg->de_debug_sup.ds_is_supplementary;
    ++data;

    for (i = 0; i < name_len; ++i, ++data) {
        *data = *(unsigned char*)(dbg->de_debug_sup.ds_filename + i);
    }

    res = dwarf_encode_leb128(
        dbg->de_debug_sup.ds_checksum_len,
        &leblen,
        (char*)data, (int)uleblen);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_DEBUG_SUP_ERROR, DW_DLV_ERROR);
    }
    data += uleblen;

    memcpy(data, dbg->de_debug_sup.ds_checksum,
        dbg->de_debug_sup.ds_checksum_len);
    *nbufs = dbg->de_n_debug_sect;
    return DW_DLV_OK;
}

static int
_dwarf_pro_generate_debuginfo(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs,
    Dwarf_Error* error)
{
    int elfsectno_of_debug_info = 0;
    unsigned char* data = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    int cu_header_size = 0;
    Dwarf_P_Abbrev curabbrev = 0;
    Dwarf_P_Abbrev abbrev_head = 0;
    Dwarf_P_Abbrev abbrev_tail = 0;
    Dwarf_P_Die curdie = 0;
    Dwarf_P_Die first_child = 0;
    Dwarf_Unsigned dw = 0;
    Dwarf_Unsigned du = 0;
    Dwarf_Half dh = 0;
    Dwarf_Unsigned die_off = 0; /* Offset of die in debug_info. */
    int n_abbrevs = 0;
    unsigned  abbrev_offset = 0;
    int res = 0;
    unsigned marker_count = 0;
    unsigned string_attr_count = 0;
    unsigned string_attr_offset = 0;
<<<<<<< HEAD
    Dwarf_Small *abbr_off_ptr = 0;
=======
<<<<<<< HEAD
    Dwarf_Small *abbr_off_ptr = 0;
=======
    Dwarf_Small* abbr_off_ptr = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    int offset_size = dbg->de_dwarf_offset_size;
    /*  extension_size is oddly names. The standard calls
        for a 64bit offset to have a 4 byte 0xffff
        while original IRIX64 did not.
        So if dbg->de_64bit_extension set this is a standard
        DWARF 64bit offset and if de_64bit_extension not set
        this is non-standard IRIX64 64 bit offset. */
    Dwarf_Half version = dbg->de_output_version;
    int extension_size = dbg->de_64bit_extension ? 4 : 0;

    /* For now just assume DW_UT_compile FIXME */
    Dwarf_Ubyte unit_type = DW_UT_compile;
    Dwarf_Ubyte address_size = 0;

    elfsectno_of_debug_info = dbg->de_elf_sects[DEBUG_INFO];
    address_size = dbg->de_pointer_size;
<<<<<<< HEAD
    if (version  < 5) {
=======
<<<<<<< HEAD
    if (version  < 5) {
=======
    if (version < 5) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        res = generate_debuginfo_header_2(dbg,
            &abbrev_offset,
            &data,
            &cu_header_size,
            &abbr_off_ptr,
<<<<<<< HEAD
            version,  extension_size, address_size,
=======
<<<<<<< HEAD
            version,  extension_size, address_size,
=======
            version, extension_size, address_size,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            error);
        if (res != DW_DLV_OK) {
            return res;
        }
<<<<<<< HEAD
    } else if (version == 5) {
=======
<<<<<<< HEAD
    } else if (version == 5) {
=======
    }
    else if (version == 5) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        res = generate_debuginfo_header_5(dbg,
            &abbrev_offset,
            &data,
            &cu_header_size,
            &abbr_off_ptr,
            version, unit_type, extension_size, address_size,
            error);
        if (res != DW_DLV_OK) {
            return res;
        }
<<<<<<< HEAD
    } else {
=======
<<<<<<< HEAD
    } else {
=======
    }
    else {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        DWARF_P_DBG_ERROR(dbg, DW_DLE_VERSION_STAMP_ERROR,
            DW_DLV_ERROR);
    }

    curdie = dbg->de_dies;

    /*  Create AT_macro_info if appropriate */
<<<<<<< HEAD
    if( version < 5) {
=======
<<<<<<< HEAD
    if( version < 5) {
=======
    if (version < 5) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (dbg->de_first_macinfo != NULL) {
            res = _dwarf_pro_add_AT_macro_info(dbg, curdie, 0, error);
            if (res != DW_DLV_OK) {
                return res;
            }
        }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    } else {
        /* FIXME need to add code to emit DWARF5 macro data. */
#if 0
            res = _dwarf_pro_add_AT_macro5_info(dbg, curdie, 0, error);
<<<<<<< HEAD
=======
=======
    }
    else {
        /* FIXME need to add code to emit DWARF5 macro data. */
#if 0
        res = _dwarf_pro_add_AT_macro5_info(dbg, curdie,
            0, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
#endif
    }

    /* Create AT_stmt_list attribute if necessary */
    if (dwarf_need_debug_line_section(dbg) == TRUE) {
<<<<<<< HEAD
        res =_dwarf_pro_add_AT_stmt_list(dbg, curdie, error);
=======
<<<<<<< HEAD
        res =_dwarf_pro_add_AT_stmt_list(dbg, curdie, error);
=======
        res = _dwarf_pro_add_AT_stmt_list(dbg, curdie, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        if (res != DW_DLV_OK) {
            return res;
        }
    }
    die_off = cu_header_size;

    /*  Relocation for abbrev offset in cu header store relocation
        record in linked list */
    res = dbg->de_relocate_by_name_symbol(dbg,
        DEBUG_INFO,
        abbrev_offset /* r_offset */,
        dbg->de_sect_name_idx[DEBUG_ABBREV],
        dwarf_drt_data_reloc, offset_size);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC, DW_DLV_ERROR);
    }

    /*  Pass 0: only top level dies, add at_sibling attribute to those
        dies with children, but if and only if
        there is no sibling attribute already. */
    first_child = curdie->di_child;
    while (first_child && first_child->di_right) {
        if (first_child->di_child) {
            if (!has_sibling_die_already(first_child)) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                dwarf_add_AT_reference(dbg,
                    first_child,
                    DW_AT_sibling,
                    first_child->di_right, error);
<<<<<<< HEAD
=======
=======
                Dwarf_P_Attribute attr_out = 0;
                res = dwarf_add_AT_reference_c(dbg,
                    first_child,
                    DW_AT_sibling,
                    first_child->di_right,
                    &attr_out, error);
                if (res != DW_DLV_OK) {
                    /* DW_DLV_NO_ENTRY is impossible. */
                    return res;
                }
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            }
        }
        first_child = first_child->di_right;
    }

<<<<<<< HEAD
    /* Pass 1: create abbrev info, get die offsets, calc relocations */
=======
<<<<<<< HEAD
    /* Pass 1: create abbrev info, get die offsets, calc relocations */
=======
    /*  Pass 1: create abbrev info, get die offsets,
        calc relocations */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    abbrev_head = abbrev_tail = NULL;
    marker_count = 0;
    string_attr_count = 0;
    while (curdie != NULL) {
        int nbytes = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        Dwarf_P_Attribute curattr = 0;
        char *space = 0;
        int cres = 0;
        char buff1[ENCODE_SPACE_NEEDED];

        curdie->di_offset = die_off;

        if (curdie->di_marker != 0) {
            marker_count++;
        }
        cres  =sort_die_attrs(dbg,curdie,error);
        if (cres != DW_DLV_OK) {
            /* DW_DLV_NO_ENTRY is impossible. */
            return cres;
        }
        /*  Find or create a final abbrev record for the
            debug_abbrev section we will write (below). */
        cres  = _dwarf_pro_getabbrev(dbg,curdie, abbrev_head,&curabbrev,
            error);
        if (cres != DW_DLV_OK) {
            return cres;
<<<<<<< HEAD
=======
=======
        Dwarf_P_Attribute curattr;
        Dwarf_P_Attribute new_first_attr;
        Dwarf_P_Attribute new_last_attr;
        char* space = 0;
        int cres = 0;
        char buff1[ENCODE_SPACE_NEEDED];
        int i = 0;

        curdie->di_offset = die_off;

        if (curdie->di_marker != 0)
            marker_count++;

        curabbrev = _dwarf_pro_getabbrev(curdie, abbrev_head);
        if (curabbrev == NULL) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, -1);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }
        if (abbrev_head == NULL) {
            n_abbrevs = 1;
            curabbrev->abb_idx = n_abbrevs;
            abbrev_tail = abbrev_head = curabbrev;
<<<<<<< HEAD
        } else {
            /* Check if it is a new abbreviation, if yes, add to tail */
=======
<<<<<<< HEAD
        } else {
            /* Check if it is a new abbreviation, if yes, add to tail */
=======
        }
        else {
            /* check if its a new abbreviation, if yes, add to tail */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            if (curabbrev->abb_idx == 0) {
                n_abbrevs++;
                curabbrev->abb_idx = n_abbrevs;
                abbrev_tail->abb_next = curabbrev;
                abbrev_tail = curabbrev;
            }
        }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        /*  We know the abbrev number to use now.
            So create the bytes of the leb with the
            value and save those bytes in di_abbrev,
            we will emit in Pass 2 (below). */
<<<<<<< HEAD
=======
=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        cres = _dwarf_pro_encode_leb128_nm(curabbrev->abb_idx,
            &nbytes,
            buff1, sizeof(buff1));
        if (cres != DW_DLV_OK) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
        }
        space = _dwarf_p_get_alloc(dbg, nbytes);
        if (space == NULL) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, DW_DLV_ERROR);
<<<<<<< HEAD
=======
=======
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, -1);
        }
        space = _dwarf_p_get_alloc(dbg, nbytes);
        if (space == NULL) {
            DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, -1);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }
        memcpy(space, buff1, nbytes);
        curdie->di_abbrev = space;
        curdie->di_abbrev_nbytes = nbytes;
        die_off += nbytes;

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        /*  The abbrev and DIE attr lists match, so the die
            abbrevs are in the correct order,
            curdie->di_attrs.  */

        /*  Now we attach the attributes list to the die. */
<<<<<<< HEAD
=======
=======
        /* Resorting the attributes!! */
        new_first_attr = new_last_attr = NULL;
        curattr = curdie->di_attrs;
        for (i = 0; i < (int)curabbrev->abb_n_attr; i++) {
            Dwarf_P_Attribute ca;
            Dwarf_P_Attribute cl;

            /* The following should always find an attribute! */
            for (ca = cl = curattr;
                ca && curabbrev->abb_attrs[i] != ca->ar_attribute;
                cl = ca, ca = ca->ar_next)
            {
            }

            if (!ca) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC, -1);
            }

            /* Remove the attribute from the old list. */
            if (ca == curattr) {
                curattr = ca->ar_next;
            }
            else {
                cl->ar_next = ca->ar_next;
            }

            ca->ar_next = NULL;

            /* Add the attribute to the new list. */
            if (new_first_attr == NULL) {
                new_first_attr = new_last_attr = ca;
            }
            else {
                new_last_attr->ar_next = ca;
                new_last_attr = ca;
            }
        }

        curdie->di_attrs = new_first_attr;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        curattr = curdie->di_attrs;

        while (curattr) {
            if (curattr->ar_rel_type != R_MIPS_NONE) {
<<<<<<< HEAD
                int rres=0;
=======
<<<<<<< HEAD
                int rres=0;
=======
                int rres = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                switch (curattr->ar_attribute) {
                case DW_AT_stmt_list:
                    curattr->ar_rel_symidx =
                        dbg->de_sect_name_idx[DEBUG_LINE];
                    break;
                case DW_AT_MIPS_fde:
                    curattr->ar_rel_symidx =
                        dbg->de_sect_name_idx[DEBUG_FRAME];
                    break;
                case DW_AT_macro_info:
                    curattr->ar_rel_symidx =
                        dbg->de_sect_name_idx[DEBUG_MACINFO];
                    break;
<<<<<<< HEAD
                /* See also: pro_forms.c for same strings attribute list. */
=======
<<<<<<< HEAD
                /* See also: pro_forms.c for same strings attribute list. */
=======
                    /*  See also: pro_forms.c for same strings
                        attribute list. */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                case DW_AT_comp_dir:
                case DW_AT_const_value:
                case DW_AT_linkage_name: /* DWARF5 */
                case DW_AT_MIPS_abstract_name:
                case DW_AT_MIPS_linkage_name:
                case DW_AT_name:
                case DW_AT_producer: {
                    int is_debug_str = 0;
<<<<<<< HEAD
                    int nres = if_relocatable_string_form(dbg,curattr,
                        &is_debug_str,error);
=======
<<<<<<< HEAD
                    int nres = if_relocatable_string_form(dbg,curattr,
                        &is_debug_str,error);
=======
                    int nres = if_relocatable_string_form(dbg, curattr,
                        &is_debug_str, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    if (nres != DW_DLV_OK) {
                        return res;
                    }
                    if (is_debug_str) {
                        curattr->ar_rel_symidx =
                            dbg->de_sect_name_idx[DEBUG_STR];
                    }
<<<<<<< HEAD
                    }
                    break;
=======
<<<<<<< HEAD
                    }
                    break;
=======
                }
                                   break;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                default:
                    break;
                }
                rres = dbg->de_relocate_by_name_symbol(dbg,
                    DEBUG_INFO,
                    die_off + curattr->ar_rel_offset,/* r_offset */
                    curattr->ar_rel_symidx,
                    dwarf_drt_data_reloc,
                    curattr->ar_reloc_len);

                if (rres != DW_DLV_OK) {
<<<<<<< HEAD
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC, DW_DLV_ERROR);
=======
<<<<<<< HEAD
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC, DW_DLV_ERROR);
=======
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC,
                        DW_DLV_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                }
            }
            if (curattr->ar_attribute_form == DW_FORM_string) {
                string_attr_count++;
            }
            die_off += curattr->ar_nbytes;
            curattr = curattr->ar_next;
        }
        /* Depth first access to all the DIEs. */
        if (curdie->di_child) {
            curdie = curdie->di_child;
<<<<<<< HEAD
        } else {
=======
<<<<<<< HEAD
        } else {
=======
        }
        else {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            while (curdie != NULL && curdie->di_right == NULL) {
                curdie = curdie->di_parent;
                /* See -nonrootsibling- below */
                if (curdie != NULL) {
                    die_off++;
                }
            }
            if (curdie != NULL) {
                curdie = curdie->di_right;
            }
        }
<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    } /* end while (curdie != NULL), the per-die loop */

    res = marker_init(dbg, marker_count);
    if (res == DW_DLV_ERROR) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC, DW_DLV_ERROR);
    }
    res = string_attr_init(dbg, DEBUG_INFO, string_attr_count);
    if (res != DW_DLV_OK) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC, DW_DLV_ERROR);
    }

    /*  Pass 2: Write out the die information Here 'data' is a
<<<<<<< HEAD
        temporary, one block for each GET_CHUNK.  'data' is overused. */
=======
<<<<<<< HEAD
        temporary, one block for each GET_CHUNK.  'data' is overused. */
=======
        temporary, one block for each GET_CHUNK.
        'data' is overused. */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    curdie = dbg->de_dies;
    while (curdie != NULL) {
        Dwarf_P_Attribute curattr;

        if (curdie->di_marker != 0) {
<<<<<<< HEAD
            res = marker_add(dbg, curdie->di_offset, curdie->di_marker);
            if (res == DW_DLV_ERROR) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC, DW_DLV_ERROR);
=======
<<<<<<< HEAD
            res = marker_add(dbg, curdie->di_offset, curdie->di_marker);
            if (res == DW_DLV_ERROR) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC, DW_DLV_ERROR);
=======
            res = marker_add(dbg, curdie->di_offset,
                curdie->di_marker);
            if (res == DW_DLV_ERROR) {
                DWARF_P_DBG_ERROR(dbg, DW_DLE_REL_ALLOC,
                    DW_DLV_ERROR);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            }
        }

        /* Index to abbreviation table */
        GET_CHUNK_ERR(dbg, elfsectno_of_debug_info,
            data, curdie->di_abbrev_nbytes, error);
<<<<<<< HEAD
        memcpy((void *) data,
            (const void *) curdie->di_abbrev,
=======
<<<<<<< HEAD
        memcpy((void *) data,
            (const void *) curdie->di_abbrev,
=======
        memcpy((void*)data,
            (const void*)curdie->di_abbrev,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            curdie->di_abbrev_nbytes);

        /* Attribute values - need to fill in all form attributes */
        curattr = curdie->di_attrs;
        string_attr_offset = curdie->di_offset +
            curdie->di_abbrev_nbytes;
        while (curattr) {
            GET_CHUNK_ERR(dbg, elfsectno_of_debug_info, data,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                (unsigned long) curattr->ar_nbytes, error);
            switch (curattr->ar_attribute_form) {
            case DW_FORM_ref1:
                {
                    Dwarf_Ubyte db = 0;
                    if (curattr->ar_ref_die->di_offset >
                        (unsigned) 0xff) {
                        DWARF_P_DBG_ERROR(dbg, DW_DLE_OFFSET_UFLW, DW_DLV_ERROR);
                    }
                    db = curattr->ar_ref_die->di_offset;
                    WRITE_UNALIGNED(dbg, (void *) data,
                        (const void *) &db,
                        sizeof(db), sizeof(Dwarf_Ubyte));
                    break;
                }
            case DW_FORM_ref2:
                {
                    if (curattr->ar_ref_die->di_offset >
                        (unsigned) 0xffff) {
                        DWARF_P_DBG_ERROR(dbg, DW_DLE_OFFSET_UFLW, DW_DLV_ERROR);
                    }
                    dh = curattr->ar_ref_die->di_offset;
                    WRITE_UNALIGNED(dbg, (void *) data,
                        (const void *) &dh,
                        sizeof(dh), DWARF_HALF_SIZE);
                    break;
                }
            case DW_FORM_ref_addr:
                {
                    /*  curattr->ar_ref_die == NULL!

                        DW_FORM_ref_addr doesn't take a CU-offset.
                        This is different than other refs.
                        This value will be set by the user of the
                        producer library using a relocation.
                        No need to set a value here.  */
                    break;

                }
            case DW_FORM_ref4:
                {
                    if (curattr->ar_ref_die->di_offset >
                        (unsigned) 0xffffffff) {
                        DWARF_P_DBG_ERROR(dbg, DW_DLE_OFFSET_UFLW,
                            DW_DLV_ERROR);
                    }
                    dw = (Dwarf_Unsigned) curattr->ar_ref_die->di_offset;
                    WRITE_UNALIGNED(dbg, (void *) data,
                        (const void *) &dw,
                        sizeof(dw), DWARF_32BIT_SIZE);
                    break;
                }
            case DW_FORM_ref8:
                du = curattr->ar_ref_die->di_offset;
                WRITE_UNALIGNED(dbg, (void *) data,
                    (const void *) &du,
                    sizeof(du), DWARF_64BIT_SIZE);
                break;
            case DW_FORM_ref_udata:
                {   /* unsigned leb128 offset */

                    int nbytesx;
                    char buff1[ENCODE_SPACE_NEEDED];

                    res =
                        _dwarf_pro_encode_leb128_nm(curattr->
                            ar_ref_die->
                            di_offset, &nbytesx,
                            buff1,
                            sizeof(buff1));
                    if (res != DW_DLV_OK) {
                        DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC,
                            DW_DLV_ERROR);
                    }
                    memcpy(data, buff1, nbytesx);
                    break;
                }
            default:
                if(curattr->ar_nbytes) {
                    memcpy((void *) data,
                        (const void *) curattr->ar_data,
<<<<<<< HEAD
=======
=======
                (unsigned long)curattr->ar_nbytes, error);
            switch (curattr->ar_attribute_form) {
            case DW_FORM_ref1:
            {
                Dwarf_Ubyte db = 0;
                if (curattr->ar_ref_die->di_offset >
                    (unsigned)0xff) {
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_OFFSET_UFLW,
                        DW_DLV_ERROR);
                }
                db = curattr->ar_ref_die->di_offset;
                WRITE_UNALIGNED(dbg, (void*)data,
                    (const void*)&db,
                    sizeof(db), sizeof(Dwarf_Ubyte));
                break;
            }
            case DW_FORM_ref2:
            {
                if (curattr->ar_ref_die->di_offset >
                    (unsigned)0xffff) {
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_OFFSET_UFLW,
                        DW_DLV_ERROR);
                }
                dh = curattr->ar_ref_die->di_offset;
                WRITE_UNALIGNED(dbg, (void*)data,
                    (const void*)&dh,
                    sizeof(dh), DWARF_HALF_SIZE);
                break;
            }
            case DW_FORM_ref_addr:
            {
                /*  curattr->ar_ref_die == NULL!

                    DW_FORM_ref_addr doesn't take a CU-offset.
                    This is different than other refs.
                    This value will be set by the user of the
                    producer library using a relocation.
                    No need to set a value here.  */
                break;

            }
            case DW_FORM_ref4:
            {
                if (curattr->ar_ref_die->di_offset >
                    (unsigned)0xffffffff) {
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_OFFSET_UFLW,
                        DW_DLV_ERROR);
                }
                dw = (Dwarf_Unsigned)
                    curattr->ar_ref_die->di_offset;
                WRITE_UNALIGNED(dbg, (void*)data,
                    (const void*)&dw,
                    sizeof(dw), DWARF_32BIT_SIZE);
                break;
            }
            case DW_FORM_ref8:
                du = curattr->ar_ref_die->di_offset;
                WRITE_UNALIGNED(dbg, (void*)data,
                    (const void*)&du,
                    sizeof(du), DWARF_64BIT_SIZE);
                break;
            case DW_FORM_ref_udata:
            {   /* unsigned leb128 offset */

                int nbytesx;
                char buff1[ENCODE_SPACE_NEEDED];

                res =
                    dwarf_encode_leb128(curattr->
                        ar_ref_die->
                        di_offset, &nbytesx,
                        buff1,
                        sizeof(buff1));
                if (res != DW_DLV_OK) {
                    DWARF_P_DBG_ERROR(dbg, DW_DLE_ABBREV_ALLOC,
                        DW_DLV_ERROR);
                }
                memcpy(data, buff1, nbytesx);
                break;
            }
            default:
                if (curattr->ar_nbytes) {
                    memcpy((void*)data,
                        (const void*)curattr->ar_data,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                        curattr->ar_nbytes);
                }
                break;
            }
            if (curattr->ar_attribute_form == DW_FORM_string) {
<<<<<<< HEAD
                string_attr_add(dbg, DEBUG_INFO, string_attr_offset, curattr);
=======
<<<<<<< HEAD
                string_attr_add(dbg, DEBUG_INFO, string_attr_offset, curattr);
=======
                string_attr_add(dbg, DEBUG_INFO,
                    string_attr_offset, curattr);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            }
            string_attr_offset += curattr->ar_nbytes;
            curattr = curattr->ar_next;
        }

        /* depth first search */
        if (curdie->di_child) {
            curdie = curdie->di_child;
<<<<<<< HEAD
        } else {
=======
<<<<<<< HEAD
        } else {
=======
        }
        else {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            while (curdie != NULL && curdie->di_right == NULL) {
                /*  -nonrootsibling-
                    A null die should only be written for terminating
                    siblings, not the root.  Adding a terminating die
                    for the root will cause, after object files are
                    linked, warnings to be generated with newer
                    versions of readelf. */
                if (!curdie->di_parent) {
                    /*  The parent is not a DIE so ending a sibling
                        chain makes no sense (wastes a byte). */
                    break;
                }
<<<<<<< HEAD
                GET_CHUNK_ERR(dbg, elfsectno_of_debug_info, data, 1, error);
=======
<<<<<<< HEAD
                GET_CHUNK_ERR(dbg, elfsectno_of_debug_info, data, 1, error);
=======
                GET_CHUNK_ERR(dbg, elfsectno_of_debug_info,
                    data, 1, error);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                *data = '\0';
                curdie = curdie->di_parent;
            }
            if (curdie != NULL)
                curdie = curdie->di_right;
        }
    } /* end while (curdir != NULL) */

    /*  Write out debug_info size, now that we know it
        This is back-patching the CU header we created
        above. */
    du = die_off - OFFSET_PLUS_EXTENSION_SIZE;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    WRITE_UNALIGNED(dbg, (void *) abbr_off_ptr,
        (const void *) &du, sizeof(du), offset_size);


    data = 0;                   /* Emphasise not usable now */
<<<<<<< HEAD
=======
=======
    WRITE_UNALIGNED(dbg, (void*)abbr_off_ptr,
        (const void*)&du, sizeof(du), offset_size);

    data = 0;                   /* Emphasize not usable now */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    res = write_out_debug_abbrev(dbg,
        abbrev_head, error);
    if (res != DW_DLV_OK) {
        return res;
    }

<<<<<<< HEAD
    *nbufs =  dbg->de_n_debug_sect;
=======
<<<<<<< HEAD
    *nbufs =  dbg->de_n_debug_sect;
=======
    *nbufs = dbg->de_n_debug_sect;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    return DW_DLV_OK;
}

static int
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
_dwarf_pro_generate_debug_names(Dwarf_P_Debug dbg,
    UNUSEDARG Dwarf_Signed *nbufs,
    Dwarf_Error * error UNUSEDARG)
{
#if 0
    int elfsectno_of_debug_names =  dbg->de_elf_sects[DEBUG_NAMES];
    FIXME: Needs implementation
    unsigned char *data = 0;

    GET_CHUNK(dbg, elfsectno_of_debug_names, data,
        dbg->de_debug_names->ds_nbytes,
        error);
    memcpy(data,dbg->de_debug_names->ds_data,dbg->de_debug_names->ds_nbytes);
#endif
<<<<<<< HEAD
=======
=======
_dwarf_pro_generate_dnames(Dwarf_P_Debug dbg,
    Dwarf_Signed* nbufs,
    Dwarf_Error* error)
{
    int elfsectno_of_debug_names = dbg->de_elf_sects[DEBUG_NAMES];
    if (dbg->de_force_dnames) {
        dwarf_force_dnames(dbg, elfsectno_of_debug_names, error);
    }
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    *nbufs = dbg->de_n_debug_sect;
    return DW_DLV_OK;
}

static int
_dwarf_pro_generate_debug_str(Dwarf_P_Debug dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Signed *nbufs,
    Dwarf_Error * error)
{
    int elfsectno_of_debug_str = 0;
    unsigned char *data = 0;

    elfsectno_of_debug_str = dbg->de_elf_sects[DEBUG_STR];
    GET_CHUNK(dbg, elfsectno_of_debug_str, data, dbg->de_debug_str->ds_nbytes,
        error);
    memcpy(data,dbg->de_debug_str->ds_data,dbg->de_debug_str->ds_nbytes);
<<<<<<< HEAD
=======
=======
    Dwarf_Signed* nbufs,
    Dwarf_Error* error)
{
    int elfsectno_of_debug_str = 0;
    unsigned char* data = 0;

    elfsectno_of_debug_str = dbg->de_elf_sects[DEBUG_STR];
    GET_CHUNK(dbg, elfsectno_of_debug_str, data,
        dbg->de_debug_str->ds_nbytes, error);
    memcpy(data, dbg->de_debug_str->ds_data,
        dbg->de_debug_str->ds_nbytes);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    *nbufs = dbg->de_n_debug_sect;
    return DW_DLV_OK;
}
static int
_dwarf_pro_generate_debug_line_str(Dwarf_P_Debug dbg,
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    Dwarf_Signed *nbufs,
    Dwarf_Error * error)
{
    int elfsectno_of_debug_line_str = 0;
    unsigned char *data = 0;
<<<<<<< HEAD
=======
=======
    Dwarf_Signed* nbufs,
    Dwarf_Error* error)
{
    int elfsectno_of_debug_line_str = 0;
    unsigned char* data = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    elfsectno_of_debug_line_str = dbg->de_elf_sects[DEBUG_LINE_STR];
    GET_CHUNK(dbg, elfsectno_of_debug_line_str, data,
        dbg->de_debug_line_str->ds_nbytes,
        error);
<<<<<<< HEAD
    memcpy(data,dbg->de_debug_line_str->ds_data,
=======
<<<<<<< HEAD
    memcpy(data,dbg->de_debug_line_str->ds_data,
=======
    memcpy(data, dbg->de_debug_line_str->ds_data,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        dbg->de_debug_line_str->ds_nbytes);
    *nbufs = dbg->de_n_debug_sect;
    return DW_DLV_OK;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

/*  Get a buffer of section data.
    section_idx is the elf-section number that this data applies to.
    length shows length of returned data
    This is the original format. Hard to check for error. */

/*ARGSUSED*/                   /* pretend all args used */
Dwarf_Ptr
dwarf_get_section_bytes(Dwarf_P_Debug dbg,
    UNUSEDARG Dwarf_Signed dwarf_section,
    Dwarf_Signed * section_idx,
    Dwarf_Unsigned * length, Dwarf_Error * error)
<<<<<<< HEAD
=======
=======
Dwarf_Ptr
dwarf_get_section_bytes(Dwarf_P_Debug dbg,
    UNUSEDARG Dwarf_Signed dwarf_section,
    Dwarf_Signed* section_idx,
    Dwarf_Unsigned* length, Dwarf_Error* error)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    Dwarf_Ptr s_bytes = 0;
    int res = 0;

    res = dwarf_get_section_bytes_a(dbg,
        dwarf_section,
        section_idx,
        length,
        &s_bytes,
        error);
    if (res == DW_DLV_ERROR) {
        return (Dwarf_Ptr)DW_DLV_BADADDR;
    }
    if (res == DW_DLV_NO_ENTRY) {
        return NULL;
    }
    return s_bytes;
}

/*  Get a buffer of section data.
    section_idx is the elf-section number that this data applies to.
    length shows length of returned data
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    This is the September 2016 format. Preferred. */
int
dwarf_get_section_bytes_a(Dwarf_P_Debug dbg,
    UNUSEDARG Dwarf_Signed dwarf_section,
    Dwarf_Signed   * section_idx,
    Dwarf_Unsigned * length,
    Dwarf_Ptr      * section_bytes,
    Dwarf_Error * error)
{
    Dwarf_Ptr buf = 0;

<<<<<<< HEAD
=======
=======
*/
int
dwarf_get_section_bytes_a(Dwarf_P_Debug dbg,
    Dwarf_Signed dwarf_section,
    Dwarf_Signed* section_idx,
    Dwarf_Unsigned* length,
    Dwarf_Ptr* section_bytes,
    Dwarf_Error* error)
{
    Dwarf_Ptr buf = 0;

    (void)dwarf_section;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    if (dbg->de_version_magic_number != PRO_VERSION_MAGIC) {
        DWARF_P_DBG_ERROR(dbg, DW_DLE_IA, DW_DLV_ERROR);
    }
    *section_bytes = 0;
    *length = 0;
    if (dbg->de_debug_sects == 0) {
        /* no more data !! */
        return DW_DLV_NO_ENTRY;
    }
    if (dbg->de_debug_sects->ds_elf_sect_no == MAGIC_SECT_NO) {
        /* no data ever entered !! */
        return DW_DLV_NO_ENTRY;
    }
    *section_idx = dbg->de_debug_sects->ds_elf_sect_no;
    *length = dbg->de_debug_sects->ds_nbytes;

<<<<<<< HEAD
    buf = (Dwarf_Ptr *) dbg->de_debug_sects->ds_data;
=======
<<<<<<< HEAD
    buf = (Dwarf_Ptr *) dbg->de_debug_sects->ds_data;
=======
    buf = (Dwarf_Ptr*)dbg->de_debug_sects->ds_data;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    /*  Here is the iterator so the next call gets
        the next section. */
    dbg->de_debug_sects = dbg->de_debug_sects->ds_next;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    /*  We may want to call the section stuff more than once: see
        dwarf_reset_section_bytes() do not do: dbg->de_n_debug_sect--; */

<<<<<<< HEAD
=======
=======
    /*  We may want to call the section stuff more than once: see
        dwarf_reset_section_bytes() do not do:
        dbg->de_n_debug_sect--; */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    *section_bytes = buf;
    return DW_DLV_OK;
}

/* No errors possible.  */
void
dwarf_reset_section_bytes(Dwarf_P_Debug dbg)
{
    dbg->de_debug_sects = dbg->de_first_debug_sect;
<<<<<<< HEAD
    /*  No need to reset; commented out decrement. dbg->de_n_debug_sect
        = ???; */
=======
<<<<<<< HEAD
    /*  No need to reset; commented out decrement. dbg->de_n_debug_sect
        = ???; */
=======
    /*  No need to reset; commented out decrement.
        dbg->de_n_debug_sect = ???; */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    dbg->de_reloc_next_to_return = 0;
    dbg->de_sect_sa_next_to_return = 0;
}

/*  Storage handler. Gets either a new chunk of memory, or
    a pointer in existing memory, from the linked list attached
    to dbg at de_debug_sects, depending on size of nbytes

    Assume dbg not null, checked in top level routine

    Returns a pointer to the allocated buffer space for the
    lib to fill in,  predincrements next-to-use count so the
    space requested is already counted 'used'
    when this returns (ie, reserved).

*/
<<<<<<< HEAD
Dwarf_Small *
=======
<<<<<<< HEAD
Dwarf_Small *
=======
Dwarf_Small*
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
_dwarf_pro_buffer(Dwarf_P_Debug dbg,
    int elfsectno, unsigned long nbytes)
{
    Dwarf_P_Section_Data cursect = 0;

    cursect = dbg->de_current_active_section;
<<<<<<< HEAD
    /*  By using MAGIC_SECT_NO we allow the following MAGIC_SECT_NO must
=======
<<<<<<< HEAD
    /*  By using MAGIC_SECT_NO we allow the following MAGIC_SECT_NO must
=======
    /*  By using MAGIC_SECT_NO we allow the
        following MAGIC_SECT_NO must
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        not match any legit section number. test to have just two
        clauses (no NULL pointer test) See dwarf_producer_init(). */
    if ((cursect->ds_elf_sect_no != elfsectno) ||
        ((cursect->ds_nbytes + nbytes) > cursect->ds_orig_alloc)
        ) {

        /*  Either the elf section has changed or there is not enough
            space in the current section.

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            Create a new Dwarf_P_Section_Data_s for the chunk. and have
            space 'on the end' for the buffer itself so we just do one
            malloc (not two).  */
        unsigned long space = nbytes;

        if (nbytes < CHUNK_SIZE)
            space = CHUNK_SIZE;

<<<<<<< HEAD
=======
=======
            Create a new Dwarf_P_Section_Data_s for the chunk.
            and have
            space 'on the end' for the buffer itself so we
            just do one malloc (not two).  */
        unsigned long space = nbytes;

        if (nbytes < CHUNK_SIZE) {
            space = CHUNK_SIZE;
        }
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        cursect = (Dwarf_P_Section_Data)
            _dwarf_p_get_alloc(dbg,
                sizeof(struct Dwarf_P_Section_Data_s)
                + space);
        if (cursect == NULL) {
            return (NULL);
        }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

        /* _dwarf_p_get_alloc zeroes the space... */

        cursect->ds_data = (char *) cursect +
            sizeof(struct Dwarf_P_Section_Data_s);
        cursect->ds_orig_alloc = space;
        cursect->ds_elf_sect_no = elfsectno;
        cursect->ds_nbytes = nbytes;    /* reserve this number of bytes
            of space for caller to fill in */
        /*  Now link on the end of the list, and mark this one as the
            current one */
<<<<<<< HEAD
=======
=======
        /* _dwarf_p_get_alloc zeroes the space... */

        cursect->ds_data = (char*)cursect +
            sizeof(struct Dwarf_P_Section_Data_s);
        cursect->ds_orig_alloc = space;
        cursect->ds_elf_sect_no = elfsectno;
        cursect->ds_nbytes = nbytes;/* reserve this number of bytes
            of space for caller to fill in */
            /*  Now link on the end of the list, and mark this one as the
                current one */
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

        if (dbg->de_debug_sects->ds_elf_sect_no == MAGIC_SECT_NO) {
            /*  The only entry is the special one for 'no entry' so
                delete that phony one while adding this initial real
                one. */
            dbg->de_debug_sects = cursect;
            dbg->de_current_active_section = cursect;
            dbg->de_first_debug_sect = cursect;
<<<<<<< HEAD
        } else {
=======
<<<<<<< HEAD
        } else {
=======
        }
        else {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            dbg->de_current_active_section->ds_next = cursect;
            dbg->de_current_active_section = cursect;
        }
        dbg->de_n_debug_sect++;

<<<<<<< HEAD
        return ((Dwarf_Small *) cursect->ds_data);
=======
<<<<<<< HEAD
        return ((Dwarf_Small *) cursect->ds_data);
=======
        return ((Dwarf_Small*)cursect->ds_data);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    }

    /* There is enough space in the current buffer */
    {
<<<<<<< HEAD
        Dwarf_Small *space_for_caller = (Dwarf_Small *)
=======
<<<<<<< HEAD
        Dwarf_Small *space_for_caller = (Dwarf_Small *)
=======
        Dwarf_Small* space_for_caller = (Dwarf_Small*)
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            (cursect->ds_data + cursect->ds_nbytes);

        cursect->ds_nbytes += nbytes;
        return space_for_caller;
    }
}
