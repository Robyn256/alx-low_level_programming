#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: The string to add to the end of the file.
 * Return: If the function fails or filename is NULL - -1.
 * User lacks write permissions if file does not exist - -1.
 * Otherwise - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int h = 0;
int y = 0;
int gor = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (gor = 0; text_content[gor];)
gor;
}

h = open(filename, O_WRONLY | O_APPEND);
y = write(h, text_content, gor);

if (h == -1 || y == -1)
return (-1);

close(h);

return (1);
}


