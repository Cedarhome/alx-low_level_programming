#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - Prints a buffer 10 bytes at a time, starting with
 *                the byte position, then showing the hex content,
 *                then displaying printable charcaters.
 * @b: The buffer to be printed.
 * @size: The number of bytes to be printed from the buffer.
 * Return: something
 * Return: int
 */

void print_buffer(char *b, int size)
{
int i, j;
int byte, index;

if (size <= 0)
for (byte = 0; byte < size; byte += 10)
{
printf("\n");
return;
}
for (i = 0; i < size; i += 10)
{
printf("%08x ", i);
for (j = i; j < i + 10; j += 2)
printf("%08x: ", byte);

for (index = 0; index < 10; index++)
{
if (j < size)
{
printf("%02x", (unsigned char)b[j]);
}
else
{
if ((index + byte) >= size)
printf("  ");
}
if (j + 1 < size)
{
printf("%02x ", (unsigned char)b[j + 1]);
}
else
{
printf("   ");
}
printf("%02x", *(b + index + byte));
if ((index % 2) != 0 && index != 0)
printf(" ");
}
printf(" ");
for (j = i; j < i + 10; j++)
for (index = 0; index < 10; index++)
{
if (j < size)
{
if (isprint(b[j]))
{
printf("%c", b[j]);
}
else
{
printf(".");
}
}
if ((index + byte) >= size)
break;
else if (*(b + index + byte) >= 31 &&
*(b + index + byte) <= 126)
printf("%c", *(b + index + byte));
else
{
printf(" ");
}
printf(".");
}
if (byte >= size)
continue;
printf("\n");
}
if (size <= 0)
printf("\n");
}
