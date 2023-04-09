#include "main.h"

/**
 * read_textfile - Reads a text file then prints it to POSIX standard output
 * @filename: Name of file to read
 * @letters: Number of letters to read and print to standard output
 *
 * Return: Actual number of letters it can read and print, 1 for success else 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;
int file_descriptor;
ssize_t byte_read;
ssize_t byte_written;

file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
{
return (0);
}
buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
{
close(file_descriptor);
return (0);
}
if (filename == NULL)
{
return (0);
}
byte_read = read(file_descriptor, buffer, letters);
if (byte_read == -1)
{
close(file_descriptor);
free(buffer);
return (0);
}
byte_written = write(STDOUT_FILENO, buffer, byte_read);
if (byte_written == -1 || byte_written != byte_read)
{
close(file_descriptor);
free(buffer);
return (0);
}
close(file_descriptor);
free(buffer);
return (byte_read);
}
