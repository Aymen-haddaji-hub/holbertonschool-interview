#include "menger.h"

/**
 * menger - function that draws 2D menger square.
 * @level: is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int i, j, n, row, col, symbol;

	n = pow(3, level);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			symbol = '#';
			row = i;
			col = j;
			while (row || col)
			{
				if (row % 3 == 1 && col % 3 == 1)
					symbol = ' ';
				row /= 3;
				col /= 3;
			}
			putchar(symbol);
		}
		putchar('\n');
	}
}
