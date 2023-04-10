# 4. Addressing Mode
```
ADDRESS_OR_OFFSET(%BASE_OR_OFFSET,%INDEX,MULTIPLIER)
        |                 |          |        |
    constants          register   register  constants

FINAL_ADDRESS=ADDRESS_OR_OFFSET+BASE_OR_OFFSET+MULTIPLIER*INDEX
```

## Direct Addressing Mode
   movl ADDRESS, %eax # mov the 32-bit value pointer by ADDRESS to Register eax
## Indexed Addressing Mode
   movl data_items(,%edi,4), %eax
## Indirect Addressing Mode
   movl (%eax), %ebx
## Base Pointer Addressing Mode
   movl 4(%eax), %ebx
## Immediate Mode
   movl $12, %eax
## Register Addressing Mode
   movl $12, %eax

## ELF(Executable and Linkable Format)
	- Relocatable, or Object File
	- Executable
	- Shared Object, Shared Library
