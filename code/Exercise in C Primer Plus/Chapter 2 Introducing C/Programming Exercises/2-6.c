/* Programming Exercises 2.6 */

// Write a program that creates an integer variable called toes.Have the program set toes
// to 10. Also have the program calculate what twice toes is and what toes squared is. The
// program should print all three values, identifying them.

#include <stdio.h>

int main()
{
	int toes = 10;
	int toes_twice; 
	int toes_squared; 

	toes_twice = toes * 2;
	toes_squared = toes * toes;

	printf("toes = %d, toes_twice = %d, toes_squared = %d\n",toes, toes_twice, toes_squared);

	return 0;
}
