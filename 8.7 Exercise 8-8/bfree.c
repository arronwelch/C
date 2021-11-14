
/*
 * Exercise 8-8: (page 189 K&R)
 * Write a routine bfree(p,n) that will free an arbitrary block of p of n characters
 * into the free list maintained by malloc and free. By using bfree, a user can
 * add a static or external array to the free list at any time.
 **/

// #include "syscalls.h"
#include <stdio.h>
#include <stdlib.h>

typedef long Align; /* for alignment to long boundary */

union header
{
	struct
	{
		union header *ptr; /* next block if on free list */
		unsigned size;	   /* size of this block */
	} s;
	Align x; /* force alignment of blocks */
};

typedef union header Header;

#define MAXBYTES (unsigned) 10240

static unsigned maxalloc; /* max number of units allocated */
static Header base; /* empty list to get started */
static Header *freep = NULL; /* start of free list */
static Header *morecore(unsigned);

int main()
{
	printf("Hello,Ubuntu!\n");
	return 0;
}


/* bfree: free an arbitrary block p of n chars */
unsigned bfree(char *p, unsigned n)
{
    Header *hp;

    if (n < sizeof(Header))
        return 0; /* too small to be useful */
    hp = (Header *) p;
    hp->s.size = n / sizeof (Header);
    free((void *)(hp + 1));
    return hp->s.size;
}

/* malloc: general-purpose storage allocator */
void *mmalloc(unsigned nbytes)
{
    Header *p, *prevp;
    //static Header *morecore(unsigned);
    unsigned nunits;

    if (nbytes > MAXBYTES)
    {
        fprintf(stderr,"alloc: can't allocate more than %u bytes\n", MAXBYTES);
        return NULL;
    }
    nunits = (nbytes + sizeof(Header) -1 ) / sizeof(Header) + 1;
    /* ... */ /* as on page 187 K&R */
    if ((prevp = freep) == NULL) /* no free list yet */
	{
		base.s.ptr = freep = prevp = &base; //freeptr prevptr ?
		base.s.size = 0;
	}

	for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr)
	{
		if (p->s.size >= nunits) /* big enough */
		{
			if (p->s.size == nunits) /* exactly */
				prevp->s.ptr = p->s.ptr;
			else
			{ /* allocate tail end */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p + 1);
		}
		if (p == freep) /* wrapped around free list */
			if ((p = morecore(nunits)) == NULL)
				return NULL; /* none left */
	}
}

#define NALLOC 1024 /* minimum #units to request */

/* morecore: ask system for more memory */
static Header *morecore(unsigned nu)
{
    char *cp, *sbrk(int);
    Header *up;

    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if (cp==(char *) -1) /* no space at all */
        return NULL;
    up = (Header *)cp;
    up->s.size = nu;
    maxalloc = (up->s.size > maxalloc) ? up->s.size : maxalloc;
    free((void *)(up + 1));
    return freep;
}

/* free: put block ap in free list */
void free(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap - 1; /* point to block header */
    if (bp->s.size == 0 || bp->s.size > maxalloc)
    {
        fprintf(stderr, "free: can't free %u units\n", bp->s.size);
        return;
    }
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        /* ... */   /* as on page 188 K&R */
		if ( p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break; /* freed block at start or end of arena */
	
	if (bp + bp->s.size == p->s.ptr) /* join to upper nbr */
	{
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	}
	else
		bp->s.ptr = p->s.ptr;
	if (p + p->s.size == bp) /* join to lower nbr */
	{
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	}
	else
		p->s.ptr = bp;
	freep = p;        
}

