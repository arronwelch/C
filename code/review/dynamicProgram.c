/*
dynamic programming (0-1 knapsack problem)

condition:
item number 1 2 3 4
item volume 2 3 4 5
item value  3 4 5 6
------------------------------------------
line:the last N item(0 1 2 ... N)
column: the max volume
------------------------------------------
    0 1 2 3 4 5 6 7 8
  0 0 0 0 0 0 0 0 0 0
  1 0 0 3 3 3 3 3 3 3
  2 0 0 3 4
  3 0
  4 0

1.if can't load current item, the last n item's dp equal to the (n-1) item's dp;
2.id can load current item:
    (1) select load current item:when total volume - current the n-th item volume,(n-1) item's dp + current value;
    (2) not select load current item: current the n-th item's dp equal to the (n-1) item's dp.
*/
     8-http:/💰faYjJmZGJhZDc💰-₳Y3kEF8tFM₣＄2cVqUn8＄/