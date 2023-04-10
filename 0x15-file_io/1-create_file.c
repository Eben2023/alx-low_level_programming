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

int file_length = 0;
int byte_written;
int file_descriptor;

if (filename == NULL)
return (-1);

file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (file_descriptor == -1)
return (-1);

if (text_content != NULL)
{

while (text_content[file_length] != '\0')
file_length++;

byte_written = write(file_descriptor, text_content, file_length);
if (byte_written == -1 || byte_written != file_length)
{
close(file_descriptor);
return (-1);
}
}

close(file_descriptor);
return (1);
}

