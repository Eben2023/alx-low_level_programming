#include "main.h"

/**
 * printout - Prints usage message to stderr
 */

void printout(void)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
}

/**
 * error_msg - Prints error message to stderr
 *
 * @error_num: Code to use in sending the error message
 * @file_doc: Name of file to use when sending message
 */

void error_msg(int error_num, char *file_doc)
{
switch (error_num)
{
case 98:
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_doc);
break;
case 99:
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_doc);
break;
case 100:
dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", file_doc);
break;
default:
break;
}
}

/**
 * copy_file - Copies content of one file to another
 *
 * @from_file: Name of file to copy from
 * @to_file: Name of file to copy to
 *
 * Return: 0 on success else exit codes 97-100
 */

int copy_file(char *from_file, char *to_file)
{
int fd_to, fd_from, wr, rd, ret = 0;
char buffer[BUFFER_SIZE];
fd_from = open(from_file, O_RDONLY);
if (fd_from == -1)
{
error_msg(98, from_file);
return (98);
}
fd_to = open(to_file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
error_msg(99, to_file);
close(fd_from);
return (99);
}
while ((rd = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
wr = write(fd_to, buffer, rd);
if (wr == -1)
{
error_msg(99, to_file);
ret = 99;
break;
}
}
if (rd == -1)
{
error_msg(98, from_file);
ret = 98;
}
if (close(fd_from) == -1 || close(fd_to) == -1)
{
error_msg(100, "");
return (100);
}
return (ret);
}

/**
 * main - Main function
 *
 * @argc: Number of arguments passed
 * @argv: Pointers to the arguments
 *
 * Return: 0 for success else exit codes 97-100
 */

int main(int argc, char *argv[])
{
if (argc != 3)
{
printout();
return (97);
}
return (copy_file(argv[1], argv[2]));
}

