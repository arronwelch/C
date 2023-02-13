# Type Conversion

## Integer Promotion
	signed/unsigned char, short, Bit-field converts to int / unsigned int;
	1. Old Style C or function parameter include "...":
		- float converts to double;
		- char converts to int;
	```c
		char ch = 'A';
		printf("%c", ch); // char converts to int, and assigns to printf.
	```

	2. Arithmatic Conversion:
		- signed/unsigned char, short, Bit-field:
	```c
		unsigned char c1 = 255, c2 = 2;
		int n = c1 + c2;
	```
	3. Usual Arithmetic Conversion:
		if operands type is different, compiler will autorun type conversion;
		- long double > double;
		- double > float;
		- float > other(integer)
		- Integer Conversion Rank: char < short < int < long < long long
			a. all signed or unsigned, converts to high Rank type;
			b. unsigned Rank >= singed Rank, converts to unsigned Rank;
			c. signed Range >= unsigned Range, converts to signed Range;
			d. unsigned int, long -> unsigned long;
	4. Cast Operator:
		- Implicit Conversion/Coercion;
		- Explicit COnversion/Type Cast;o
	5. Compiler Type Conversion:
		- double to short: (-32769.0, 32768.0), Undefined;
		- int to unsigned short: [0, 65535];
		- int to short: [-32768, 32767];
		- short to int: Sign Extension;
