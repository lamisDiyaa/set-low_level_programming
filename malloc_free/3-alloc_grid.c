#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the grid (columns)
 * @height: height of the grid (rows)
 *
 * Return: pointer to the 2D array of integers, or NULL on failure.
 */
int **alloc_grid(int width, int height)
{
int **grid;
int i, j;

/* الخطوة 1: التحقق من الأبعاد */
if (width <= 0 || height <= 0)
return (NULL);

/* الخطوة 2: حجز مصفوفة المؤشرات التي تشير إلى الصفوف */
grid = malloc(sizeof(int *) * height);

/* التحقق من نجاح الحجز الرئيسي */
if (grid == NULL)
return (NULL);

/* الخطوة 3: حجز الذاكرة لكل صف (الأعمدة) */
for (i = 0; i < height; i++)
{
grid[i] = malloc(sizeof(int) * width);

/* إذا فشل حجز صف معين، يجب تنظيف الذاكرة المحجوزة سابقاً وتجنب الـ Leak */
if (grid[i] == NULL)
{
for (j = 0; j < i; j++)
{
free(grid[j]);
}
free(grid);
return (NULL);
}
}

/* الخطوة 4: تهيئة جميع عناصر المصفوفة بالقيمة 0 */
for (i = 0; i < height; i++)
{
for (j = 0; j < width; j++)
{
grid[i][j] = 0;
}
}

return (grid);
}
