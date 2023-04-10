/**
 * get_string_length - Returns the length of a null-terminated string.
 * @str: The string to get the length of.
 *
 * Return: The length of the string.
 */
int get_string_length(const char *str)
{
int len = 0;

while (str && str[len])
{
len++;
}

return (len);
}

/**
 * append_text_to_file - Appends text to a file.
 * @filename: The name of the file to append to.
 * @text_content: The text to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, const char *text_content)
{
int text_len, file_descriptor, write_check;

if (!filename)
{
return (-1);
}

text_len = get_string_length(text_content);
if (text_len == 0)
{
return (1);
}

file_descriptor = open(filename, O_WRONLY | O_APPEND);
if (file_descriptor == -1)
{
return (-1);
}

write_check = write(file_descriptor, text_content, text_len);
close(file_descriptor);

return (write_check == text_len ? 1 : -1);
}

