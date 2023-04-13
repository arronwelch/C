# 5. ELF file

## ELF(Executable and Linkable Format)
	- Relocatable, or Object File
	- Executable
	- Shared Object, Shared Library

```bash
find . -type f -name 'max.s'
vim max.s
as max.s -o max.o
ld max.o -o max
./max
echo $?
readelf -a max.o | less
hexdump -C max.o | less
objdump -d max.o | less
readelf -a max | less
```
