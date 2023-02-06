/* maze_circular_queue.c
 * 1. Circular Queue:
 *
 *	front: always points to the first element: 0
 *	tail: always points to the next element of the last: 0
 *
 *	0).capacity():
 *		MAX_LEN_QUE
 * 	1).enqueue():
 *		(tail + 1) % MAX_LEN_QUE
 * 	2).dequeue():
 *		(front + 1) % MAX_LEN_QUE
 *	3).is_empty():
 *		front == tail
 *	4).is_full():
 *		(tail + 1) % MAX_LEN_QUE == front
 *	5).size():
 *		(tail + MAX_LEN_QUE - front) % MAX_LEN_QUE
 * 2. BFS(Breadth First Search) with Queue
 */

#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define MAX_LEN_QUE (MAX_ROW * MAX_COL)

struct point { int row, col; } queue[MAX_LEN_QUE];
int head = 0, tail = 0;

int is_empty(void)
{
	return head == tail;
}

int is_full()
{
	return (tail + 1) % MAX_LEN_QUE == head;
}

void enqueue(struct point p)
{
	if (is_full())
		return;

	queue[tail] = p;
	tail = (tail + 1) % MAX_LEN_QUE;
}

struct point dequeue(void)
{
	struct point p = { -1, -1 };
	if (!is_empty())
	{
		p = queue[head];
		head = (head + 1) % MAX_LEN_QUE;
	}
	return p;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

void visit(int row, int col)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	enqueue(visit_point);
}

int main(void)
{
	struct point p = { 0, 0};

	maze[p.row][p.col] = 2;
	enqueue(p);

	while (!is_empty()) {
		p = dequeue();
		if (p.row == MAX_ROW - 1 /* goal */
			&& p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL /* right */
			&& maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1);
		if (p.row+1 < MAX_ROW /* down */
			&& maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col);
		if (p.col-1 >= 0 /* left */
			&& maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1);
		if (p.row-1 >= 0 /* up */
			&& maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col);
		print_maze();
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("(%d, %d)\n", p.row, p.col);
	} else
		printf("No path!\n");

	return 0;
}
