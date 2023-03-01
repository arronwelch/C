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
	Hamming-code parity

## RAID 3(consists of byte-level striping with dedicated parity)
	All disk spindle rotation is synchronized and data is striped such that each sequential byte is on a different drive.

## RAID 4(consists of block-level striping with dedicated parity)
	RAID-DP

## RAID 5(consists of block-level striping with distributed parity)

## RAID 6(consists of block-level striping with double distributed parity)

## Nested(hybrid) RAID
