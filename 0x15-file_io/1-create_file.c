#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A name of the file to create.
 * @text_content: A string to write to the file.
 * Return: If the function fails - -1.
 * Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
int sl, z, gin = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (gin = 0; text_content[gin];)
gin++;
}

sl = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
z = write(sl, text_content, gin);

if (sl == -1 || z == -1)
return (-1);

close(sl);

return (1);
}

