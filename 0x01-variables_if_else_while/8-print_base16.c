#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - main block
 * description: prints all the numbers of base 16 in lowercase
 * followed by a new line
 * Return: 0
 */

int main(void)
{
char c = 'z';
while (c >= 'a')
{
putchar(c);
c--;
}
putchar('\n');
return (0);
}

