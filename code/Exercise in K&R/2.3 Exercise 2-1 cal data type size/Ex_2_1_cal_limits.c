/***
 *
 * Exercise 2.1
 *
 * Program to print maximum, minimum limits of char, int, long using
 * calculation
 *
 ***/

/* The logic used is
* ~0 will give bits in 1s.
* (unsigned <type>) will cast it unsigned.
* >> 1 right shifts 1 bit to remove the sign bit.
* (<type>) casting it the required type again
*/

#include<stdio.h>
#include<limits.h>
#include<float.h>

int strlen(const char s[]);

int main(void)
{
	/* ranges of various floating-point types through calculation */
	printf("Ranges of various floating-point types through calculation:\n");
	
	printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
	printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

	printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
	printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

	printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
	printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

	printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
	printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

	/* Unsigned Maximum Values */

	printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
	printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
	printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
	printf("Maximum Unsigned Long %lu\n\n",(unsigned long)~0);
	
	/* ranges of various floating-point types from standard headers */
	printf("Ranges of various floating-point types from standard headers:\n");
	
	printf("Minimum Signed Char %d\n", SCHAR_MIN);
    	printf("Maximum Signed Char %d\n", SCHAR_MAX);
    
    	printf("Minimum Signed Short %d\n", SHRT_MIN);
    	printf("Maximum Signed Short %d\n", SHRT_MAX);
    
    	printf("Minimum Signed Int %d\n", INT_MIN);
    	printf("Maximum Signed Int %d\n", INT_MAX);
    
    	printf("Minimum Signed Long %ld\n", LONG_MIN);
    	printf("Maximum signed Long %ld\n", LONG_MAX);
    
    	/* Unsigned Maximum Values */
    
    	printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
    	printf("Maximum Unsigned Short %d\n", USHRT_MAX);
    	printf("Maximum Unsigned Int %u\n", UINT_MAX);
    	printf("Maximum Unsigned Long %lu\n", ULONG_MAX);

		putchar('\041');
		putchar('\x21');

		printf("%ld\n", 2147483648L);
		printf("%lu\n", 2147483648L);

		printf("%f\n", 123.4);
		printf("%f\n", \
		123.4e-2);

		printf("hello,"   
		"world");

		printf("hello,"
		"world" 
		"length ="
		"%d",strlen("hello,"
		"world"));//The standard library function strlen(s) returns the length of its character string \
                                             argument s, excluding the terminal '\0'

		enum boolean { NO = -2, YES = -2, TEST};//Values need not be distinct in the same enumeration!
		printf("\n%d %d %d",NO,YES,TEST);

		//TEST = 3;

		enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };//Names in different enumerations(months and boolean) must be distinct!
		/* FEB = 2, MAR = 3, etc. */

		//typedef enum monthsss { TMW } monthsss_type;

		enum monthsss { TMW } ;//[Definition the enumeration monthsss with initial variable TMW]
		enum monthsss aaadfgg = 6;//[Declared monthsss's enum types's variable aaadfgg]:\
		Although variables of enum types may be declared,\
		compilers need not check that what you store in such a variable is a valid value for the enumeration.
		printf("\naaadfgg:%d",aaadfgg);

		printf("\n%f\n", 4.0/5.0/3.0);

		printf("\n%d\n", (-4 >= 5) == (8 < 7));
		printf("%d\n", -4 >= 5 != 8 < 7);
		printf("%d\n", (-4 >= 5) != (8 < 7));

		short int si;
		si = 0x12345678L;
		printf("\nshort int si= %x",si);//may draw a warning, but they are not illegal.
		unsigned short int usi;
		usi = 1.23e2L;
		printf("\nunsigned short int usi= %d",usi);//may draw a warning, but they are not illegal.

		enum cardsuit 
		{
			Clubs,
			Diamonds,
			Hearts,
			Spades
		};

		struct card 
		{
			enum cardsuit suit;
			short int value;
		} hand[13];

		enum cardsuit trump = Spades;
		trump = -1;
		hand[0].suit = -1;
    	
	return 0;
}

/* strlen: return length of s */
int strlen(const char s[])
{
	int i;
	while (s[i] != '\0')
	++i;
	return i;
}