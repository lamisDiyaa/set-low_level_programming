#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: pointer to the newly allocated space containing concatenated strings,
 * or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
char *concat_str;
unsigned int len1 = 0, len2 = 0, i, j;

/* الخطوة 1: التعامل مع النصوص الممررة كـ NULL كأنها نصوص فارغة */
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

/* الخطوة 2: حساب طول النص الأول */
while (s1[len1] != '\0')
len1++;

/* الخطوة 3: حساب طول النص الثاني */
while (s2[len2] != '\0')
len2++;

/* الخطوة 4: حجز الذاكرة للنصين معاً + 1 للـ Null terminator */
concat_str = malloc(sizeof(char) * (len1 + len2 + 1));

/* الخطوة 5: التحقق من نجاح الـ malloc */
if (concat_str == NULL)
return (NULL);

/* الخطوة 6: نسخ النص الأول إلى المساحة الجديدة */
for (i = 0; i < len1; i++)
{
concat_str[i] = s1[i];
}

/* الخطوة 7: نسخ النص الثاني مباشرة بعد النص الأول */
for (j = 0; j < len2; j++, i++)
{
concat_str[i] = s2[j];
}

/* الخطوة 8: إغلاق النص الجديد بـ Null terminator */
concat_str[i] = '\0';

return (concat_str);
}
