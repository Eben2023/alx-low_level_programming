#include "main.h"

/**
 * create_file - Creates a file and writes text to it
 * @filename: Name of file to create
 * @text_content: Text to be writen to the file
 *
 * Return: 1 for success, else -1
 */

int create_file(const char *filename, char *text_content)
{
int fd, bytes_written, length = 0;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content != NULL)
{

while (text_content[length] != '\0')
length++;

bytes_written = write(fd, text_content, length);
if (bytes_written == -1 || bytes_written != length)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}

