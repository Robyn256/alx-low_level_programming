
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 * Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: File descriptor to be closed.
*/
void close_file(int fd)
{
int j;

j = close(fd);

if (j == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc:Number of arguments supplied to the program.
 * @argv: Array of pointers to the arguments.
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 * Return: On success 0
 */
int main(int argc, char *argv[])
{
int k;
int q;
int p;
int x;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
k = open(argv[1], O_RDONLY);
p = read(k, buffer, 1024);
q = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if(k == -1 || p == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

x = write(q, buffer, p);
if (q == -1 || x == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

p = read(k, buffer, 1024);
q = open(argv[2], O_WRONLY | O_APPEND);

} while (p > 0);

free(buffer);
close_file(k);
close_file(q);

return (0);
}


