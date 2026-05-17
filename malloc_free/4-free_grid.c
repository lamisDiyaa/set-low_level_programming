#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid previously created
 * by alloc_grid function.
 * @grid: the 2D grid to free
 * @height: height of the grid (number of rows)
 *
 * Return: Nothing.
 */
void free_grid(int **grid, int height)
{
int i;

/* الخطوة 1: التحقق من أن المصفوفة ليست فارغة بالفعل */
if (grid == NULL || height <= 0)
return;

/* الخطوة 2: تحرير كل صف من الصفوف بشكل منفصل */
for (i = 0; i < height; i++)
{
free(grid[i]);
}

/* الخطوة 3: تحرير مصفوفة المؤشرات الرئيسية بعد تنظيف محتواها */
free(grid);
}
