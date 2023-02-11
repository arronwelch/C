# 1. Integer:
	- char 8bit/(1bit + 7bit): Implementation Defined:
		1. signed char (-128 ~ 127)
		2. unsigned char (0 ~ 255)
	- Implementation-defined:
		char is signed or unsigned is Implementation-defined, but compiler must
	defined in document.
	- Unspecified:
		multiple choice, do not need specify the implementation-defined in doc. function call parameter expresion valuation.
	- Undefined:
		compiler not define. visit the element over the array range.

	- short (int), int, long (int), long long (int), Bit-field;
	- Sign and Magnitude, 1's Complement, 2's Complement : Implementation Defined;
	- integer is signed except char : Not Implementation Defined;
	- sizeof(char) is one Byte;
	- ILP32(int, long, pointer)
		1. char		8
		2. short	16
		3. int		32
		4. long		32
		5. long long	64
		6. pointer	32
	- LP64(long, pointer)
		1. char		8
		2. short	16
		3. int		32
		4. long		64
		5. long long	64
		6. pointer	64
	- x86/Linux/gcc, ILP32, char is signed;
	- Constant: Character, Integer, Floating Point;
	- Oct: 007,022; \07, \22
	- Hex: 0x0a, 0xAf; \x0a, \xAf;
	- u/U: unsigned, l/L: long, ll/LL: long long;
	- 0x7fffffff is int, 0xffff0000(MSB 31bit is 1) is unsigned int;
