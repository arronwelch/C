# Bit Operator

## Bitwise AND : &
        00000011
        00000101
    &
----------------
        00000001
## Bitwise OR  : |
        00000011
        00000101
    |
----------------
        00000111
## Bitwise NOT : ~
        00000011
        00000101
    ^
----------------
        00000110
## Bitwise XOR : ^
    ~   11111100
----------------
        00000011

	"&,|,^,~" operators is need Usual Arithmetic Conversion(one step is Integer Promotion).
```c
	unsigned char c = 0xfc; // 0xfc is "int", c is "unsigned char".
	unsigned int i = ~c; // ~ 000000fc => ffffff03
```

# Bitwise Shift
	operand is not need same type, but all need Integer Promotion.
## left bitwise shift
        11001111111111111111111111110011
    <<                                 2
----------------------------------------
        00111111111111111111111111001100
## right bitwise shift
        11001111111111111111111111110011
    >>                                 2
----------------------------------------
        00110011111111111111111111111100

