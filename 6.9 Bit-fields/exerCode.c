
/* 6.9 Bit-fields */

//norm way:

#define KEYWORD 01
#define EXTRENAL 02
#define STATIC 04

enum { KEYWORD = 01, EXTRENAL = 02, STATIC = 04 };

flags |= EXTRENAL | STATIC;//turn on the EXTRENAL and STATIC bits in flags
flags &= ~(EXTRENAL | STATIC);//turns them off
if ((flags & (EXTRENAL | STATIC)) == 0)//is ture if both bits are off


//bit-fields way:

struct 
{
    unsigned int is_keyword : 1;//must be integer | (operation bit-field named) | bit_width;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
} flags;

flags.is_extern = flags.is_static = 1;//to turn the bits on;
flags.is_extern = flags.is_static = 0;//to turn them off
if (flags.is_extern == 0 && flags.is_static == 0) // to test them

//almost everything about fields is implementation-dependent.

