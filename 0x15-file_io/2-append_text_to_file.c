#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: Name of file
 * @text_content: String added at the end of the file
 *
 * Return: 1 on success and -1 on failure
 **/

int append_text_to_file(const char *filename, char *text_content)
{
int file_length = 0;
int file_descriptor;
int write_check;

if (text_content != NULL)
{
while (text_content[file_length])
file_length++;
}

file_descriptor = open(filename, O_WRONLY | O_APPEND);
if (file_descriptor == -1)
return (-1);

if (filename == NULL)
return (-1);

if (file_length >= 1)
{
write_check = write(file_descriptor, text_content, file_length);
if (write_check != file_length)
{
close(file_descriptor);
return (-1);
}
}

else
{
close(file_descriptor);

return (1);
}
}
