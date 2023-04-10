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
if (!filename)
{
return (-1);
}

int fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
{
return (-1);
}

int nletters = 0;
if (text_content)
{
while (text_content[nletters])
{
nletters++;
}
if (write(fd, text_content, nletters) == -1)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}

