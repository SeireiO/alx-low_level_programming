#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- read text file & print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: write actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t az;
	ssize_t e;
	ssize_t r;

	az = open(filename, O_RDONLY);
	if (az == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	r = read(az, buf, letters);
	e = write(STDOUT_FILENO, buf, r);

	free(buf);
	close(az);
	return (e);
}
