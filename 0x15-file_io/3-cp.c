#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define EXIT_WRONG_ARGS 97
#define EXIT_READ_ERR 98
#define EXIT_WRITE_ERR 99
#define EXIT_CLOSE_ERR 100

/**
 * main - copies the content of a file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exit code on failure
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, r, w;
    char buffer[BUFFER_SIZE];
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;  /* rw-rw-r-- */
    struct stat st;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(EXIT_WRONG_ARGS);
    }

    /* Open source file for reading */
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(EXIT_READ_ERR);
    }

    /* Check if destination file exists (truncate if it does) */
    if (stat(argv[2], &st) == 0)
    {
        if (open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, mode) == -1)
        {
            close(fd_from);
            dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
            exit(EXIT_WRITE_ERR);
        }
    }
    else
    {
        /* Create destination file with specific permissions */
        fd_to = open(argv[2], O_WRONLY | O_CREAT, mode);
        if (fd_to == -1)
        {
            close(fd_from);
            dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
            exit(EXIT_WRITE_ERR);
        }
    }

    /* Read from source and write to destination in chunks */
    while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        w = write(fd_to, buffer, r);
        if (w != r)
        {
            close(fd_from);
            close(fd_to);
            dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
            exit(EXIT_WRITE_ERR);
        }
    }

    /* Check for read errors */
    if (r == -1)
    {
        close(fd_from);
        close(fd_to);
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(EXIT_READ_ERR);
    }

    /* Close file descriptors */
    if (close(fd_from) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(EXIT_CLOSE_ERR);
    }
    if (close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(EXIT_CLOSE_ERR);
    }

    return (0);
}