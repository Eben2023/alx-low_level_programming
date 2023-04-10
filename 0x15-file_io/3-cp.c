#include "main.h"

/**
 * print_usage - Prints usage message to stderr
 */
void print_usage(void)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
}

/**
 * print_error - Prints error message to stderr
 *
 * @error_code: The error code to use in the message
 * @filename: The name of the file to use in the message
 */
void print_error(int error_code, char *filename)
{
switch (error_code)
{
case 98:
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
break;
case 99:
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
break;
case 100:
dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", filename);
break;
default:
break;
}
}

/**
 * copy_file - Copies the content of a file to another file
 *
 * @from_file: The name of the file to copy from
 * @to_file: The name of the file to copy to
 *
 * Return: 0 on success, otherwise exit codes 97-100
 */
int copy_file(char *from_file, char *to_file)
{
int fd_from, fd_to, rd, wr, ret = 0;
char buffer[BUFFER_SIZE];
fd_from = open(from_file, O_RDONLY);
if (fd_from == -1)
{
print_error(98, from_file);
return (98);
}
fd_to = open(to_file, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
print_error(99, to_file);
close(fd_from);
return (99);
}
while ((rd = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
wr = write(fd_to, buffer, rd);
if (wr == -1)
{
print_error(99, to_file);
ret = 99;
break;
}
}
if (rd == -1)
{
print_error(98, from_file);
ret = 98;
}
if (close(fd_from) == -1 || close(fd_to) == -1)
{
print_error(100, "");
return (100);
}
return (ret);
}

/**
 * main - Entry point
 *
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success, otherwise exit codes 97-100
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
print_usage();
return (97);
}

return (copy_file(argv[1], argv[2]));
}

