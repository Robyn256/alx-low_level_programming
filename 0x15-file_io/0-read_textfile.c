#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file read
 * @letters: number of letters read
 * Return: z- actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t sd;
	ssize_t z;
	ssize_t x;

	sd = open(filename, O_RDONLY);
	if (sd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	x = read(fd, buf, letters);
	z = write(STDOUT_FILENO, buf, x);

	free(buf);
	close(sd);
	return (z);
}

