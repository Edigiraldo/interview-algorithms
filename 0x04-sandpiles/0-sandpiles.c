#include "sandpiles.h"

/**
* print_nogd - docs
* @grid: docs
* Return: docs
*
*/
void print_nogd(int grid[3][3])
{
	int i, j;

	puts("=");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
* sandpiles_sum - docs
* @grid1: docs
* @grid2: docs
* Return: docs
*/
void sandpiles_sum(int grid1[3][3],
		   int grid2[3][3])
{
	int i, j;
	int d_u;
	int aux[3][3];

	if (grid1 == NULL || grid2 == NULL)
		return;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
	do {
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				aux[i][j] = grid1[i][j];
		}
		d_u = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (aux[i][j] > 3)
				{
					if (!d_u)
						print_nogd(grid1);
					d_u = 1;
					grid1[i][j] -= 4;
					if (i > 0)
						grid1[i - 1][j] += 1;
					if (i < 2)
						grid1[i + 1][j] += 1;
					if (j > 0)
						grid1[i][j - 1] += 1;
					if (j < 2)
						grid1[i][j + 1] += 1;
				}
			}
		}
	} while (d_u);
}
