/* maze_recursive_bfs.c */

#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define MAX_LEN_STK 512

struct point { int row, col; } stack[MAX_LEN_STK];
int top = 0;

void push(int row, int col)
{
	struct point p;
	p.row = row;
	p.col = col;
	stack[top++] = p;
}

struct point pop(void)
{
	return stack[--top];
}

int is_empty(void)
{
	return top == 0;
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

void print_path(void)
{
	while (!is_empty())
	{
		struct point p = pop();
		printf("(%d, %d)\n", p.row, p.col);
	}
}

int path_search(int row, int col)
{
	maze[row][col] = 2;
	print_maze();

	if (row == MAX_ROW - 1 /* goal */
		&& col == MAX_COL - 1)
	{
		push(row, col);
		return 1;
	}
	if (col+1 < MAX_COL /* right */
		&& maze[row][col+1] == 0
		&& path_search(row, col+1))
	{
		push(row, col);
		return 1;
	}
	if (row+1 < MAX_ROW /* down */
		&& maze[row+1][col] == 0
		&& path_search(row+1, col))
	{
		push(row, col);
		return 1;
	}
	if (col-1 >= 0 /* left */
		&& maze[row][col-1] == 0
		&& path_search(row, col-1))
	{
		push(row, col);
		return 1;
	}
	if (row-1 >= 0 /* up */
		&& maze[row-1][col] == 0
		&& path_search(row-1, col))
	{
		push(row, col);
		return 1;
	}

	return 0;
}

int main(void)
{
	struct point p = { 0, 0 };

	if (path_search(p.row, p.col))
		print_path();
	else
		printf("No path!\n");

	return 0;
}
