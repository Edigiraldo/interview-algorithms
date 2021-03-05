#include "menger.h"

/**
* menger - Draws a 2D Menger Sponge.
* @level: Level of the Menger Sponge to draw.
*/

void menger(int level)
{
	int n = pow(3, level), i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (solid_cell(i, j))
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

/**
* solid_cell - Tells if a cell should be solid or not in a Menger sponge.
* @row: Row of the cell.
* @col: Column of the cell.
* Return: 1 if cell should be solid or 0 if not.
*/

int solid_cell(int row, int col)
{
	while (1)
	{
		if (row == 0 || col == 0)
			return (1);
		else if (row % 3 == 1 && col % 3 == 1)
			return (0);
		row /= 3;
		col /= 3;
	}
}
