# RAID(Redundant Array of Inexpensive Disks or Redundant Array of Independent Disks)

## RAID 0(consists of striping, but no mirroring or parity)
	| A1 | A2 | A3 |
	| A4 | B1 | B2 |
	| B3 | B4 |    |
	----------------
	  D1   D2   D3
An example of data striping. Files A and B, of four blocks each are spread over disks D1 to D3

## RAID 1(consists of data mirroring, without parity or striping)
Hard disk drive performance characteristics
	- Seek time
	- Rotational latency
	- Command processing time
	- Settle time

## RAID 2(consists of bit-level striping with dedicated Hamming-code parity)

