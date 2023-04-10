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
int fd, res, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[len])
len++;
}

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

if (len > 0)
{
res = write(fd, text_content, len);
if (res != len)
{
close(fd);
return (-1);
}
}

close(fd);

return (1);
}
