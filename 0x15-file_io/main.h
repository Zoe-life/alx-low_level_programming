#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* File descriptor functions */
/* 0-read_textfile.c */
ssize_t read_textfile(const char *filename, size_t letters);

/* 1-create_file.c */
int create_file(const char *filename, char *text_content);

/* 2-append_text_to_file.c */
int append_text_to_file(const char *filename, char *text_content);

/* ELF header function */
void print_elf_header(ElfHeader *eh);

/* Helper functions for ELF header */
const char *elf_osabi_to_string(unsigned char osabi);
const char *elf_type_to_string(unsigned short type);

#endif /* MAIN_H */