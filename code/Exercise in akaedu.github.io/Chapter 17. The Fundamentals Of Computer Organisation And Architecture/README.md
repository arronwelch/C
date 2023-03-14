# Von Neumann
	- CPU(Central Processing Unit) : Fetch
	- Memory

## 1. Memory and Address

## 2. CPU
	- Register : x86 eax(General-purpose Register),esp,eip(Special-purpose Register)
	- PC(Program Counter) Special Register
	- Instruction Decoder
	- ALU(Arithmetic and Logic Unit)
	- Bus

 Word, Half Word, Address Space(0x0000_0000 ~ 0xFFFF_FFFF : 4GB),MMU,Little Endian,x86,Byte Order,Big Endian.

```
	mov 0x804a01c, %eax
	add $0x1, %eax
	mov %eax, 0x804a018
```

## 3. Device
	ARM: Memory-mapped I/O
	x86: Port I/O
	PCI,AGP,USB,1394,SATA
	x86: Device : hard disk(IDE,SATA,SCSI bus)
	Load,Process,Shell,/bin/bash
	Operating System, Bootloader,Kernel,/boot/vmlinuz-2.6.28-13-generic,Shell,Office
	Interrupt,ISR(Interrupt Service Routine),Device Driver.

## 4. MMU(Memory Management Unit)
	Virtual Memory Management, PA(Physical Address), VA(Virtual Address),
	Page(0x0000~0x0FFF=1KB),VA:0xb7001000~0xb7001fff => PA:0x2000~2fff,
	CPU => 0xb7001008 => 0x2008, Page Frame,Page Table,
	User Mode, Privileged Mode,Interrupt or exception, Return from Interrupt or exception.
	x86 Linux : 0x00000000~0xffffffff; total
	3GB,        0x00000000~0xbfffffff; User Space
	1GB,        0xc0000000~0xffffffff; Kernel Space

## 5. Memory Hierarchy
	Hard Disk, Memory, CPU Register, Cache.

	Type Capacity  |         |  Access Time
	 100GB~1TB      Hard Disk       3 ~  15 ms
	 100MB~1GB      Memory        100 ~ 150 ns
	 100KB~1MB      L2 Cache       40 ~  60 ns
	  10KB~100KB    L1 Cache        5 ~  10 ns
	  10KB~100B     Register        1ns

	Flip-flop, RAM(Random Access Memory), Cache-SRAM(Static RAM), Memory-DRAM(Dynamic RAM)
	Cache Line : 32 ~ 256 Bytes; Amortize; Volatile Memory; Non-volatile Memory;
	Locality;
