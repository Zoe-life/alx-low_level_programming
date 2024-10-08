#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to be read
 * @letters: the number of characters to read and print
 *
 * Return: the actual number of letters it could read and print, or 0 if it fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t r, w;
    char *buf;

    if (!filename)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (!buf)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buf);
        return (0);
    }

    r = read(fd, buf, letters);
    if (r == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }

    w = write(STDOUT_FILENO, buf, r);
    if (w != r)
    {
        free(buf);
        close(fd);
        return (0);
    }

    free(buf);
    close(fd);
    return (w);
}