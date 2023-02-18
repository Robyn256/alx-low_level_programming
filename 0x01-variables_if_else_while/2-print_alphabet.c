 #include <stdio.h>

/**
 * main - prints the alphabet in lowercase
 * Return: Always 0 Success
 */

int main(void)
{
char alp[26] = "abcdefghijklmnopqrstuvwyz";
int i;
for i = 0; i < 26; i++
{
putchar(alp[i]);
}
putchar('\n');
return (0);
}

