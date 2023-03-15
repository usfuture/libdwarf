<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
/* Copyright (c) 2013-2019, David Anderson
All rights reserved.

Redistribution and use in source and binary forms, with
or without modification, are permitted provided that the
following conditions are met:

    Redistributions of source code must retain the above
    copyright notice, this list of conditions and the following
    disclaimer.

    Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials
    provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


/*  The interfaces follow tsearch (See the Single
    Unix Specification) but the implementation is
    written without reference to the source of any
    version of tsearch or any hashing code.

    An additional interface is added (compared to
    a real tsearch) to let the caller identify a
    'hash' function with each hash table (called
    a tree below, but that is a misnomer).

    So read 'tree' below as hash table.

    See http://www.prevanders.net/tsearch.html
    for information and an example of use.

    Based on Knuth, chapter 6.4

    This uses a hash based on the key.
    Collision resolution is by chaining.

    twalk() and tdestroy() walk in a random order.
    The 'preorder' etc labels mean nothing in a hash, so everything
    is called a leaf.

*/


#include "config.h"
#ifdef HAVE_UNUSED_ATTRIBUTE
#define  UNUSEDARG __attribute__ ((unused))
#else
#define  UNUSEDARG
#endif
#ifdef HAVE_STDLIB_H
#include "stdlib.h" /* for malloc, free() etc */
#endif /* HAVE_STDLIB_H */
#ifdef HAVE_MALLOC_H
/* Useful include for some Windows compilers. */
#include <malloc.h>
#endif /* HAVE_MALLOC_H */
#include <stdio.h>  /* for printf() */
#ifdef HAVE_STDINT_H
#include <stdint.h> /* for uintptr_t */
#endif /* HAVE_STDINT_H */
/*  This must match the types and print options
    found in libdwarf.h.  */
#define Dwarf_Unsigned unsigned long long
#if defined(_WIN32) && defined(HAVE_NONSTANDARD_PRINTF_64_FORMAT)
#define DW_PR_DUx "I64x"
#define DW_PR_DUu "I64u"
#else
#define DW_PR_DUx "llx"
#define DW_PR_DUu "llu"
#endif /* DW_PR defines */
<<<<<<< HEAD
=======
=======
#include <config.h>

#include <stddef.h> /* NULL */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* calloc() free() malloc() */

#ifdef HAVE_STDINT_H
#include <stdint.h> /* uintptr_t */
#endif /* HAVE_STDINT_H */

#include "libdwarf.h"
#include "libdwarf_private.h"
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
#include "dwarf_tsearch.h"

/*  A table of primes used to size  and resize the hash table.
    From public sources of prime numbers, arbitrarily chosen
    to approximately double in size at each step.
*/
static unsigned long primes[] =
{
#if 0 /* for testing only */
5,11, 17,23, 31, 47, 53,
<<<<<<< HEAD
#endif
79,
=======
<<<<<<< HEAD
#endif
79,
=======
79,
#endif /*0*/
521,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
1009,
5591,
10007,
21839,
41413,
99907,
199967,
400009,
800029,
1600141,
3000089,
6000121,
12000257,
24000143,
48000203,
100000127,
200001611,
400000669,
800000573,
0 /* Here we are giving up */
};

static unsigned long allowed_fill_percent = 90;

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
struct hs_base {
    unsigned long tablesize_;
    unsigned long tablesize_entry_index_;
    unsigned long allowed_fill_;
    /* Record_count means number of active records,
        counting all records on chains.
        When the record_count is > 90% of a full
        tablesize_ we redo the table before adding
        a new entry.  */
    unsigned long record_count_;
    /*  hashtab_ is an array of hs_entry,
        indexes 0 through tablesize_ -1. */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    struct ts_entry * hashtab_;
    DW_TSHASHTYPE (*hashfunc_)(const void *key);
};

struct ts_entry {
    const void * keyptr;
<<<<<<< HEAD
=======
=======
    struct ts_entry* hashtab_;
    DW_TSHASHTYPE(*hashfunc_)(const void* key);
};

struct ts_entry {
    const void* keyptr;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    /*  So that a keyptr of 0 (if added) is
        not confused with an empty hash slot,
        we must mark used slots as used in the hash tab */
    unsigned char entryused;
<<<<<<< HEAD
    struct ts_entry *next;
=======
<<<<<<< HEAD
    struct ts_entry *next;
=======
    struct ts_entry* next;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
};

enum search_intent_t
{
    want_insert,
    only_find,
    want_delete
};

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
static struct ts_entry *
tsearch_inner( const void *key, struct hs_base* head,
    int (*compar)(const void *, const void *),
    const enum search_intent_t intent, int*inserted,
    struct ts_entry **parent_ptr);
static void
dwarf_tdestroy_inner(struct hs_base*h,
    void (*free_node)(void *nodep),
    int depth);

<<<<<<< HEAD
=======
=======
static struct ts_entry*
_tsearch_inner(const void* key, struct hs_base* head,
    int (*compar)(const void*, const void*),
    const enum search_intent_t intent, int* inserted,
    struct ts_entry** parent_ptr);
static void
_dwarf_tdestroy_inner(struct hs_base* h,
    void (*free_node)(void* nodep));
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

/*  A trivial integer-based percentage calculation.
    Percents >100 are reasonable for a hash-with-chains
    situation (even if they might not be the best choice
    for performance). */
static unsigned long
calculate_allowed_fill(unsigned long fill_percent, unsigned long ct)
{
    unsigned long v = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    if(ct < 100000) {
        unsigned long v2 = (ct *fill_percent)/100;
        return v2;
    }
    v = (ct /100)*fill_percent;
    return v;
}

/* Initialize the hash and pass in the hash function.
   If the entry count needed is unknown, pass in  0 as a count estimate,
   but if the number of hash entries needed can be estimated,
   pass in the estimate (which need not be prime, we actually use
   the nearest higher prime from the above table).
   If the estimated count is
   Return the tree base, or return NULL if insufficient memory. */
void *
dwarf_initialize_search_hash( void **treeptr,
    DW_TSHASHTYPE(*hashfunc)(const void *key),
<<<<<<< HEAD
=======
=======
    if (ct < 100000) {
        unsigned long v2 = (ct * fill_percent) / 100;
        return v2;
    }
    v = (ct / 100) * fill_percent;
    return v;
}

/*  Initialize the hash and pass in the hash function.
    If the entry count needed is unknown, pass in
    0 as a count estimate,
    but if the number of hash entries needed can be estimated,
    pass in the estimate (which need not be prime,
    we actually use
    the nearest higher prime from the above table).
    If the estimated count is
    Return the tree base, or return NULL if insufficient
    memory. */
void*
dwarf_initialize_search_hash(void** treeptr,
    DW_TSHASHTYPE(*hashfunc)(const void* key),
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned long size_estimate)
{
    unsigned long prime_to_use = primes[0];
    unsigned entry_index = 0;
    unsigned k = 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    struct hs_base *base = 0;

    base = *(struct hs_base **)treeptr;
    if(base) {
        /* initalized already. */
        return base ;
    }
    base = calloc(sizeof(struct hs_base),1);
    if(!base) {
        /* Out of memory. */
        return NULL ;
    }
    prime_to_use = primes[0];
    while(size_estimate && (size_estimate > prime_to_use)) {
        k = k +1;
        prime_to_use = primes[k];
        if(prime_to_use == 0) {
<<<<<<< HEAD
=======
=======
    struct hs_base* base = 0;

    base = *(struct hs_base**)treeptr;
    if (base) {
        /* initialized already. */
        return base;
    }
    base = calloc(sizeof(struct hs_base), 1);
    if (!base) {
        /* Out of memory. */
        return NULL;
    }
    prime_to_use = primes[0];
    while (size_estimate && (size_estimate > prime_to_use)) {
        k = k + 1;
        prime_to_use = primes[k];
        if (prime_to_use == 0) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            /* Oops. Too large. */
            free(base);
            return NULL;
        }
        entry_index = k;
    }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    base->tablesize_ = prime_to_use;
    base->allowed_fill_ = calculate_allowed_fill(allowed_fill_percent,
        prime_to_use);
    if( base->allowed_fill_< (base->tablesize_/2)) {
<<<<<<< HEAD
=======
=======
#ifdef TESTINGHASHTAB
    printf("debugging: initial alloc size estimate %lu\n", size_estimate);
    printf("debugging: initial alloc prime to use %lu\n", prime_to_use);
#endif
    base->tablesize_ = prime_to_use;
    base->allowed_fill_ = calculate_allowed_fill(allowed_fill_percent,
        prime_to_use);
    if (base->allowed_fill_ < (base->tablesize_ / 2)) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        free(base);
        /* Oops. We are in trouble. Coding mistake here.  */
        return NULL;
    }
    base->record_count_ = 0;
    base->tablesize_entry_index_ = entry_index;
    /*  hashtab_ is an array of hs_entry,
        indexes 0 through tablesize_ -1. */
    base->hashfunc_ = hashfunc;
<<<<<<< HEAD
    base->hashtab_ = calloc(sizeof(struct ts_entry),base->tablesize_);
    if(!base->hashtab_) {
=======
<<<<<<< HEAD
    base->hashtab_ = calloc(sizeof(struct ts_entry),base->tablesize_);
    if(!base->hashtab_) {
=======
    base->hashtab_ = calloc(sizeof(struct ts_entry), base->tablesize_);
    if (!base->hashtab_) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        free(base);
        return NULL;
    }
    *treeptr = base;
    return base;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

/*  We don't really care whether hashpos or chainpos
    are 32 or 64 bits. 32 suffices. */
static void print_entry(struct ts_entry *t,const char *descr,
    char *(* keyprint)(const void *),
    unsigned long hashpos,
    unsigned long chainpos)
{
    char *v = 0;
    if(!t->entryused) {
        return;
    }
    v = keyprint(t->keyptr);
    printf(
        "[%4lu.%02lu] 0x%08" DW_PR_DUx
        " <keyptr 0x%08" DW_PR_DUx
        "> <key %s> %s\n",
        hashpos,chainpos,
<<<<<<< HEAD
=======
=======
#ifdef BUILD_TDUMP
/*  We don't really care whether hashpos or chainpos
    are 32 or 64 bits. 32 suffices. */
static void print_entry(struct ts_entry* t, const char* descr,
    char* (*keyprint)(const void*),
    unsigned long hashpos,
    unsigned long chainpos)
{
    char* v = 0;
    if (!t->entryused) {
        return;
    }
    v = keyprint(t->keyptr);
    printf("[%4lu.%02lu] 0x%08" DW_PR_DUx
        " <keyptr 0x%08" DW_PR_DUx
        "> <key %s> %s\n",
        hashpos, chainpos,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        (Dwarf_Unsigned)(uintptr_t)t,
        (Dwarf_Unsigned)(uintptr_t)t->keyptr,
        v,
        descr);
}

/* For debugging */
static void
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
dumptree_inner(const struct hs_base *h,
    char *(* keyprint)(const void *),
    const char *descr, int printdetails)
{
    unsigned long ix = 0;
    unsigned long tsize = h->tablesize_;
    struct ts_entry *p = &h->hashtab_[0];
<<<<<<< HEAD
=======
=======
dumptree_inner(const struct hs_base* h,
    char* (*keyprint)(const void*),
    const char* descr, int printdetails)
{
    unsigned long ix = 0;
    unsigned long tsize = h->tablesize_;
    struct ts_entry* p = &h->hashtab_[0];
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    unsigned long hashused = 0;
    unsigned long maxchainlength = 0;
    unsigned long chainsgt1 = 0;
    printf("dumptree head ptr : 0x%08" DW_PR_DUx
        " size %"    DW_PR_DUu
        " entries %" DW_PR_DUu
        " allowed %" DW_PR_DUu " %s\n",
        (Dwarf_Unsigned)(uintptr_t)h,
        (Dwarf_Unsigned)h->tablesize_,
        (Dwarf_Unsigned)h->record_count_,
        (Dwarf_Unsigned)h->allowed_fill_,
        descr);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    for(  ; ix < tsize; ix++,p++) {
        unsigned long chainlength = 0;
        struct ts_entry*n = 0;
        int chainpos = 0;
        if(p->entryused) {
            ++hashused;
            chainlength = 1;
            if(printdetails) {
                print_entry(p,"head",keyprint,ix,chainpos);
            }
        }
        chainpos++;
        for(n = p->next; n ; n = n->next) {
            chainlength++;
            if(printdetails) {
                print_entry(n,"chain",keyprint,ix,chainpos);
            }
        }
        if(chainlength > maxchainlength) {
<<<<<<< HEAD
=======
=======
    for (; ix < tsize; ix++, p++) {
        unsigned long chainlength = 0;
        struct ts_entry* n = 0;
        int chainpos = 0;
        if (p->entryused) {
            ++hashused;
            chainlength = 1;
            if (printdetails) {
                print_entry(p, "head", keyprint, ix, chainpos);
            }
        }
        chainpos++;
        for (n = p->next; n; n = n->next) {
            chainlength++;
            if (printdetails) {
                print_entry(n, "chain", keyprint, ix, chainpos);
            }
        }
        if (chainlength > maxchainlength) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            maxchainlength = chainlength;
        }
        if (chainlength > 1) {
            chainsgt1++;
        }
    }
<<<<<<< HEAD
    printf("Hashtable: %lu of %lu hash entries used.\n",hashused,tsize);
    printf("Hashtable: %lu chains length longer than 1. \n",chainsgt1);
    printf("Hashtable: %lu is maximum chain length.\n",maxchainlength);
=======
<<<<<<< HEAD
    printf("Hashtable: %lu of %lu hash entries used.\n",hashused,tsize);
    printf("Hashtable: %lu chains length longer than 1. \n",chainsgt1);
    printf("Hashtable: %lu is maximum chain length.\n",maxchainlength);
=======
    printf("Hashtable: %lu of %lu hash entries used.\n",
        hashused, tsize);
    printf("Hashtable: %lu chains length longer than 1. \n",
        chainsgt1);
    printf("Hashtable: %lu is maximum chain length.\n",
        maxchainlength);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
}

/*  Dumping the tree.
    */
void
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
dwarf_tdump(const void*headp_in,
    char *(* keyprint)(const void *),
    const char *msg)
{
    const struct hs_base *head = (const struct hs_base *)headp_in;
    if(!head) {
        printf("dumptree null tree ptr : %s\n",msg);
        return;
    }
    dumptree_inner(head,keyprint,msg,1);
}

static struct ts_entry *
allocate_ts_entry(const void *key)
{
    struct ts_entry *e = (struct ts_entry *)
        malloc(sizeof(struct ts_entry));
    if(!e) {
<<<<<<< HEAD
=======
=======
dwarf_tdump(const void* headp_in,
    char* (*keyprint)(const void*),
    const char* msg)
{
    const struct hs_base* head = (const struct hs_base*)headp_in;
    if (!head) {
        printf("dumptree null tree ptr : %s\n", msg);
        return;
    }
    dumptree_inner(head, keyprint, msg, 1);
}
#endif /* BUILD_TDUMP */

static struct ts_entry*
allocate_ts_entry(const void* key)
{
    struct ts_entry* e = 0;

    e = (struct ts_entry*)malloc(sizeof(struct ts_entry));
    if (!e) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        return NULL;
    }
    e->keyptr = key;
    e->entryused = 1;
    e->next = 0;
    return e;
}

static void
<<<<<<< HEAD
resize_table(struct hs_base *head,
    int (*compar)(const void *, const void *))
=======
<<<<<<< HEAD
resize_table(struct hs_base *head,
    int (*compar)(const void *, const void *))
=======
resize_table(struct hs_base* head,
    int (*compar)(const void*, const void*))
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
{
    struct hs_base newhead;
    unsigned new_entry_index = 0;
    unsigned long prime_to_use = 0;

    /* Copy the values we have. */
    newhead = *head;
    /* But drop the hashtab_ from new. calloc below. */
    newhead.hashtab_ = 0;
    newhead.record_count_ = 0;
<<<<<<< HEAD
    new_entry_index = head->tablesize_entry_index_ +1;
    prime_to_use = primes[new_entry_index];
    if(prime_to_use == 0) {
=======
<<<<<<< HEAD
    new_entry_index = head->tablesize_entry_index_ +1;
    prime_to_use = primes[new_entry_index];
    if(prime_to_use == 0) {
=======
    new_entry_index = head->tablesize_entry_index_ + 1;
    prime_to_use = primes[new_entry_index];
    if (!prime_to_use) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        /*  Oops, too large. Leave table size as is, though
            it will get slow as it overfills. */
        return;
    }
    newhead.tablesize_ = prime_to_use;
<<<<<<< HEAD
    newhead.allowed_fill_ = calculate_allowed_fill(allowed_fill_percent,
        prime_to_use);
    if( newhead.allowed_fill_< (newhead.tablesize_/2)) {
=======
<<<<<<< HEAD
    newhead.allowed_fill_ = calculate_allowed_fill(allowed_fill_percent,
        prime_to_use);
    if( newhead.allowed_fill_< (newhead.tablesize_/2)) {
=======
    newhead.allowed_fill_ = calculate_allowed_fill(
        allowed_fill_percent, prime_to_use);
    if (newhead.allowed_fill_ < (newhead.tablesize_ / 2)) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        /* Oops. We are in trouble.  */
        return;
    }
    newhead.tablesize_entry_index_ = new_entry_index;
<<<<<<< HEAD
    newhead.hashtab_ = calloc(sizeof(struct ts_entry),newhead.tablesize_);
    if(!newhead.hashtab_) {
=======
<<<<<<< HEAD
    newhead.hashtab_ = calloc(sizeof(struct ts_entry),newhead.tablesize_);
    if(!newhead.hashtab_) {
=======
    newhead.hashtab_ = calloc(sizeof(struct ts_entry),
        newhead.tablesize_);
    if (!newhead.hashtab_) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        /*  Oops, too large. Leave table size as is, though
            things will get slow as it overfills. */
        free(newhead.hashtab_);
        return;
    }
    {
        /*  Insert all the records from the old table into
            the new table. */
        int fillnewfail = 0;
        unsigned long ix = 0;
        unsigned long tsize = head->tablesize_;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        struct ts_entry *p = &head->hashtab_[0];
        for(  ; ix < tsize; ix++,p++) {
            int inserted = 0;
            struct ts_entry*n = 0;
            if(fillnewfail) {
                break;
            }
            if(p->keyptr) {
                tsearch_inner(p->keyptr,
                    &newhead,compar,
                    want_insert,
                    &inserted,
                    0);
                if(!inserted) {
<<<<<<< HEAD
=======
=======
        struct ts_entry* p = &head->hashtab_[0];
#ifdef TESTINGHASHTAB
        printf("debugging: Resize %lu to %lu\n", tsize, prime_to_use);
#endif
        for (; ix < tsize; ix++, p++) {
            int inserted = 0;
            struct ts_entry* n = 0;
            if (fillnewfail) {
                break;
            }
            if (p->keyptr) {
                _tsearch_inner(p->keyptr,
                    &newhead, compar,
                    want_insert,
                    &inserted,
                    0);
                if (!inserted) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    fillnewfail = 1;
                    break;
                }
            }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            for(n = p->next; n ; n = n->next) {
                inserted = 0;
                tsearch_inner(n->keyptr,
                    &newhead,compar,
                    want_insert,
                    &inserted,
                    0);
                if(!inserted) {
<<<<<<< HEAD
=======
=======
            for (n = p->next; n; n = n->next) {
                inserted = 0;
                _tsearch_inner(n->keyptr,
                    &newhead, compar,
                    want_insert,
                    &inserted,
                    0);
                if (!inserted) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
                    fillnewfail = 1;
                    break;
                }
            }
        }
<<<<<<< HEAD
        if(fillnewfail) {
=======
<<<<<<< HEAD
        if(fillnewfail) {
=======
        if (fillnewfail) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            free(newhead.hashtab_);
            return;
        }
    }
    /* Now get rid of the chain entries of the old table. */
<<<<<<< HEAD
    dwarf_tdestroy_inner(head,0,0);
=======
<<<<<<< HEAD
    dwarf_tdestroy_inner(head,0,0);
=======
    _dwarf_tdestroy_inner(head, 0);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    /* Now get rid of the old table itself. */
    free(head->hashtab_);
    head->hashtab_ = 0;
    *head = newhead;
    return;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
/*   Inner search of the hash and synonym chains.
  */
static struct ts_entry *
tsearch_inner( const void *key, struct hs_base* head,
    int (*compar)(const void *, const void *),
    const enum search_intent_t intent, int*inserted,
<<<<<<< HEAD
=======
=======
/*  Inner search of the hash and synonym chains.  */
static struct ts_entry*
_tsearch_inner(const void* key, struct hs_base* head,
    int (*compar)(const void*, const void*),
    const enum search_intent_t intent, int* inserted,
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    /* owner_ptr used for delete.  Only set
        if the to-be-deleted item is on a chain,
        not in the hashtab. Points to the item
        pointing to the to-be-deleted-item.*/
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    struct ts_entry **owner_ptr)
{
    struct ts_entry *s =0;
    struct ts_entry *c =0;
    struct ts_entry *q =0;
    int kc = 0;
    DW_TSHASHTYPE keyhash =  0;
    DW_TSHASHTYPE hindx = 0;
    struct ts_entry *chain_parent = 0;

    if(! head->hashfunc_) {
        /* Not fully initialized. */
        return NULL;
    }
    keyhash =  head->hashfunc_(key);
    if (intent == want_insert) {
        if( head->record_count_ > head->allowed_fill_) {
            resize_table(head,compar);
        }
    }
    hindx = keyhash%head->tablesize_;
    s = &head->hashtab_[hindx];
    if(!s->entryused) {
        /* Not found. */
        if(intent != want_insert) {
<<<<<<< HEAD
=======
=======
    struct ts_entry** owner_ptr)
{
    struct ts_entry* s = 0;
    struct ts_entry* c = 0;
    struct ts_entry* q = 0;
    int kc = 0;
    DW_TSHASHTYPE keyhash = 0;
    DW_TSHASHTYPE hindx = 0;
    struct ts_entry* chain_parent = 0;

    if (!head->hashfunc_) {
        /* Not fully initialized. */
        return NULL;
    }
    keyhash = head->hashfunc_(key);
    if (intent == want_insert) {
        if (head->record_count_ > head->allowed_fill_) {
            resize_table(head, compar);
        }
    }
    hindx = keyhash % head->tablesize_;
    s = &head->hashtab_[hindx];
    if (!s->entryused) {
        /* Not found. */
        if (intent != want_insert) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            return NULL;
        }
        /*  Insert in the base hash table in an
            empty slot. */
        *inserted = 1;
        head->record_count_++;
<<<<<<< HEAD
        s->keyptr = (const void *)key;
=======
<<<<<<< HEAD
        s->keyptr = (const void *)key;
=======
        s->keyptr = (const void*)key;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        s->entryused = 1;
        s->next = 0;
        return s;
    }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    kc = compar(key,s->keyptr);
    if(kc == 0 ) {
        /* found! */
        if(want_delete) {
            *owner_ptr = 0;
        }
        return (void *)&(s->keyptr);
    }
    chain_parent = s;
    for(c = s->next; c; c = c->next)  {
        kc = compar(key,c->keyptr);
        if(kc == 0 ) {
            /* found! */
            if(want_delete) {
                *owner_ptr = chain_parent;
            }
            return (void *)&(c->keyptr);
        }
        chain_parent = c;
    }
    if(intent != want_insert) {
<<<<<<< HEAD
=======
=======
    kc = compar(key, s->keyptr);
    if (kc == 0) {
        /* found! */
        if (intent == want_delete) {
            *owner_ptr = 0;
        }
        return (void*)&(s->keyptr);
    }
    chain_parent = s;
    for (c = s->next; c; c = c->next) {
        kc = compar(key, c->keyptr);
        if (kc == 0) {
            /* found! */
            if (intent == want_delete) {
                *owner_ptr = chain_parent;
            }
            return (void*)&(c->keyptr);
        }
        chain_parent = c;
    }
    if (intent != want_insert) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        return NULL;
    }
    /* Insert following head record of the chain. */
    q = allocate_ts_entry(key);
    if (!q) {
        return q;
    }
    q->next = s->next;
    s->next = q;
    head->record_count_++;
    *inserted = 1;
    return q;
}
/* Search and, if missing, insert. */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
void *
dwarf_tsearch(const void *key, void **headin,
    int (*compar)(const void *, const void *))
{
    struct hs_base **rootp = (struct hs_base **)headin;
    struct hs_base *head = *rootp;
    struct ts_entry *r = 0;
    int inserted = 0;
    /* nullme won't be set. */
    struct ts_entry *nullme = 0;
<<<<<<< HEAD
=======
=======
void*
dwarf_tsearch(const void* key, void** headin,
    int (*compar)(const void*, const void*))
{
    struct hs_base** rootp = (struct hs_base**)headin;
    struct hs_base* head = *rootp;
    struct ts_entry* r = 0;
    int inserted = 0;
    /* nullme won't be set. */
    struct ts_entry* nullme = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    if (!head) {
        /* something is wrong here, not initialized. */
        return NULL;
    }
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    r = tsearch_inner(key,head,compar,want_insert,&inserted,&nullme);
    if (!r) {
        return NULL;
    }
    return (void *)&(r->keyptr);
}


/* Search. */
void *
dwarf_tfind(const void *key, void *const *rootp,
    int (*compar)(const void *, const void *))
{
    /*  Nothing will change, but we discard const
        so we can use tsearch_inner(). */
    struct hs_base **proot = (struct hs_base **)rootp;
    struct hs_base *head = *proot;
    struct ts_entry *r = 0;
    /* inserted flag won't be set. */
    int inserted = 0;
    /* nullme won't be set. */
    struct ts_entry * nullme = 0;
<<<<<<< HEAD
=======
=======
    r = _tsearch_inner(key, head, compar, want_insert, &inserted, &nullme);
    if (!r) {
        return NULL;
    }
    return (void*)&(r->keyptr);
}

/* Search. */
void*
dwarf_tfind(const void* key, void* const* rootp,
    int (*compar)(const void*, const void*))
{
    /*  Nothing will change, but we discard const
        so we can use tsearch_inner(). */
    struct hs_base** proot = (struct hs_base**)rootp;
    struct hs_base* head = *proot;
    struct ts_entry* r = 0;
    /* inserted flag won't be set. */
    int inserted = 0;
    /* nullme won't be set. */
    struct ts_entry* nullme = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    /* Get to actual tree. */

    if (!head) {
        return NULL;
    }

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    r = tsearch_inner(key,head,compar,only_find,&inserted,&nullme);
    if(!r) {
        return NULL;
    }
    return (void *)(&(r->keyptr));
<<<<<<< HEAD
=======
=======
    r = _tsearch_inner(key, head, compar, only_find, &inserted, &nullme);
    if (!r) {
        return NULL;
    }
    return (void*)(&(r->keyptr));
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
}

/*  Unlike the simple binary tree case,
    a fully-empty hash situation does not null the *rootp
*/
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
void *
dwarf_tdelete(const void *key, void **rootp,
    int (*compar)(const void *, const void *))
{
    struct hs_base **proot = (struct hs_base **)rootp;
    struct hs_base *head = *proot;
    struct ts_entry *found = 0;
    /* inserted flag won't be set. */
    int inserted = 0;
    struct ts_entry * parentp = 0;
<<<<<<< HEAD
=======
=======
void*
dwarf_tdelete(const void* key, void** rootp,
    int (*compar)(const void*, const void*))
{
    struct hs_base** proot = (struct hs_base**)rootp;
    struct hs_base* head = *proot;
    struct ts_entry* found = 0;
    /* inserted flag won't be set. */
    int inserted = 0;
    struct ts_entry* parentp = 0;
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)

    if (!head) {
        return NULL;
    }

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    found = tsearch_inner(key,head,compar,want_delete,&inserted,
        &parentp);
    if(found) {
        if(parentp) {
<<<<<<< HEAD
=======
=======
    found = _tsearch_inner(key, head, compar, want_delete, &inserted,
        &parentp);
    if (found) {
        if (parentp) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            /* Delete a chain entry. */
            head->record_count_--;
            parentp->next = found->next;
            /*  We free our storage. It would be up
                to caller to do a tfind to find
                a record and delete content if necessary. */
            free(found);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            return (void *)&(parentp->keyptr);
        }
        /* So found is the head of a chain. */
        if(found->next) {
            /*  Delete a chain entry, pull up to hash tab, freeing
                up the chain entry. */
            struct ts_entry *pullup = found->next;
            *found = *pullup;
            free(pullup);
            head->record_count_--;
            return (void *)&(found->keyptr);
        } else {
<<<<<<< HEAD
=======
=======
            return (void*)&(parentp->keyptr);
        }
        /* So found is the head of a chain. */
        if (found->next) {
            /*  Delete a chain entry, pull up to hash tab, freeing
                up the chain entry. */
            struct ts_entry* pullup = found->next;
            *found = *pullup;
            free(pullup);
            head->record_count_--;
            return (void*)&(found->keyptr);
        }
        else {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            /*  Delete a main hash table entry.
                Problem: what the heck to return as a keyptr pointer?
                Well, we return NULL. As in the standard
                tsearch, returning NULL does not mean
                failure! Here it just means 'empty chain somewhere'.
            */
            head->record_count_--;
            found->next = 0;
            found->keyptr = 0;
            found->entryused = 0;
            return NULL;
        }
    }
    return NULL;
}

static void
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
dwarf_twalk_inner(const struct hs_base *h,
    struct ts_entry *p,
    void (*action)(const void *nodep, const DW_VISIT which,
        UNUSEDARG const int depth),
    UNUSEDARG unsigned level)
{
    unsigned long ix = 0;
    unsigned long tsize = h->tablesize_;
    for(  ; ix < tsize; ix++,p++) {
        struct ts_entry*n = 0;
        if(p->keyptr) {
            action((void *)(&(p->keyptr)),dwarf_leaf,level);
        }
        for(n = p->next; n ; n = n->next) {
            action((void *)(&(n->keyptr)),dwarf_leaf,level);
<<<<<<< HEAD
=======
=======
_dwarf_twalk_inner(const struct hs_base* h,
    struct ts_entry* p,
    void (*action)(const void* nodep, const DW_VISIT which,
        const int depth)
)
{
    unsigned long ix = 0;
    int depth = 0;
    unsigned long tsize = h->tablesize_;
    for (; ix < tsize; ix++, p++) {
        struct ts_entry* n = 0;
        if (p->keyptr) {
            action((void*)(&(p->keyptr)), dwarf_leaf, depth);
        }
        for (n = p->next; n; n = n->next) {
            action((void*)(&(n->keyptr)), dwarf_leaf, depth);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        }
    }
}

void
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
dwarf_twalk(const void *rootp,
    void (*action)(const void *nodep, const DW_VISIT which,
        UNUSEDARG const int depth))
{
    const struct hs_base *head = (const struct hs_base *)rootp;
    struct ts_entry *root = 0;
    if(!head) {
<<<<<<< HEAD
=======
=======
dwarf_twalk(const void* rootp,
    void (*action)(const void* nodep, const DW_VISIT which,
        const int depth))
{
    const struct hs_base* head = (const struct hs_base*)rootp;
    struct ts_entry* root = 0;
    if (!head) {
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
        return;
    }
    root = head->hashtab_;
    /* Get to actual tree. */
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    dwarf_twalk_inner(head,root,action,0);
}

static void
dwarf_tdestroy_inner(struct hs_base*h,
    void (*free_node)(void *nodep),
    UNUSEDARG int depth)
{
    unsigned long ix = 0;
    unsigned long tsize = h->tablesize_;
    struct ts_entry *p = &h->hashtab_[0];
    for(  ; ix < tsize; ix++,p++) {
        struct ts_entry*n = 0;
        struct ts_entry*prev = 0;
        if(p->keyptr && p->entryused) {
            if(free_node) {
                free_node((void *)(p->keyptr));
<<<<<<< HEAD
=======
=======
    _dwarf_twalk_inner(head, root, action);
}

static void
_dwarf_tdestroy_inner(struct hs_base* h,
    void (*free_node)(void* nodep))
{
    unsigned long ix = 0;
    unsigned long tsize = h->tablesize_;
    struct ts_entry* p = &h->hashtab_[0];
#ifdef TESTINGHASHTAB
    printf("debugging: destroyhashtable blocks      %lu\n", tsize);
    printf("debugging: destroyhashtable recordcount %lu\n",
        h->record_count_);
#endif
    for (; ix < tsize; ix++, p++) {
        struct ts_entry* n = 0;
        struct ts_entry* prev = 0;
        if (p->keyptr && p->entryused) {
            if (free_node) {
                free_node((void*)(p->keyptr));
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            }
            --h->record_count_;
        }
        /* Now walk and free up the chain entries. */
<<<<<<< HEAD
        for(n = p->next; n ; ) {
            if(free_node) {
                free_node((void *)(n->keyptr));
=======
<<<<<<< HEAD
        for(n = p->next; n ; ) {
            if(free_node) {
                free_node((void *)(n->keyptr));
=======
        for (n = p->next; n; ) {
            if (free_node) {
                free_node((void*)(n->keyptr));
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
            }
            --h->record_count_;
            prev = n;
            n = n->next;
            free(prev);
        }
    }
}

/*  Walk the tree, freeing all space in the tree
    and calling the user's callback function on each node.
<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    It is up to the caller to zero out anything pointing to
    head (ie, that has the value rootp holds) after this
    returns.
*/
void
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
dwarf_tdestroy(void *rootp, void (*free_node)(void *nodep))
{
    struct hs_base *head = (struct hs_base *)rootp;
    struct ts_entry *root = 0;
    if(!head) {
        return;
    }
    root = head->hashtab_;
    dwarf_tdestroy_inner(head,free_node,0);
<<<<<<< HEAD
=======
=======
dwarf_tdestroy(void* rootp, void (*free_node)(void* nodep))
{
    struct hs_base* head = (struct hs_base*)rootp;
    struct ts_entry* root = 0;
    if (!head) {
        return;
    }
    root = head->hashtab_;
    _dwarf_tdestroy_inner(head, free_node);
>>>>>>> 7cd586f (refactored to work with dwarf export)
>>>>>>> 9c45ac7 (refactored to work with dwarf export)
    free(root);
    free(head);
}
