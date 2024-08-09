#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file with specific permissions
 * @filename: name of the file to create
 * @text_content: null-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd, w, len = 0;
    mode_t mode = S_IRUSR | S_IWUSR; /* rw------- */

    if (!filename)
        return (-1);

    if (text_content)
        len = strlen(text_content);

    fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, mode);
    if (fd == -1)
        return (-1);

    if (text_content)
    {
        w = write(fd, text_content, len);
        if (w != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
