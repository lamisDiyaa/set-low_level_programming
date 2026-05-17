#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL
 * or if insufficient memory was available.
 */
char *_strdup(char *str)
{
char *dup;
unsigned int i, len;

/* الخطوة 1: التحقق إذا كان النص الممرر فارغاً */
if (str == NULL)
return (NULL);

/* الخطوة 2: حساب طول النص */
len = 0;
while (str[len] != '\0')
{
len++;
}

/* الخطوة 3: حجز الذاكرة للنص الجديد (+1 للـ Null terminator) */
dup = malloc(sizeof(char) * (len + 1));

/* الخطوة 4: التحقق من نجاح عملية حجز الذاكرة */
if (dup == NULL)
return (NULL);

/* الخطوة 5: نسخ محتوى النص الأصلي إلى النص الجديد */
for (i = 0; i <= len; i++)
{
dup[i] = str[i];
}

return (dup);
}
