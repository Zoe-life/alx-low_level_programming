#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

#define ELF_MAGIC 0x454C467F  /* Magic number for ELF files */
#define EI_NIDENT (sizeof(ELF_MAGIC))
#define EXIT_FAILURE 98

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    Elf64_Ehdr *ehdr64;
    Elf32_Ehdr *ehdr32;
} ElfHeader;

void print_elf_header(ElfHeader *eh) {
    printf("ELF Header:\n");

    /* Print magic number */
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", eh->e_ident[i]);
    }
    printf("\n");

    /* Check class (32-bit or 64-bit) */
    if (eh->ehdr64) {
        printf("  Class:                             ELF64\n");
        printf("  Data:                              ");
        switch (eh->ehdr64->e_ident[EI_DATA]) {
            case ELFDATA2LSB:
                printf("2's complement, little endian\n");
                break;
            case ELFDATA2MSB:
                printf("2's complement, big endian\n");
                break;
            default:
                printf("unknown\n");
        }
        printf("  Version:                           %d (current)\n",
               eh->ehdr64->e_version);
        printf("  OS/ABI:                            %s\n",
               elf_osabi_to_string(eh->ehdr64->e_osabi));
        printf("  ABI Version:                       %d\n",
               eh->ehdr64->e_abiversion);
        printf("  Type:                              %s\n",
               elf_type_to_string(eh->ehdr64->e_type));
        printf("  Entry point address:               0x%" PRIx64 "\n",
               eh->ehdr64->e_entry);
    } else {
        printf("  Class:                             ELF32\n");
        printf("  Data:                              ");
        switch (eh->ehdr32->e_ident[EI_DATA]) {
            case ELFDATA2LSB:
                printf("2's complement, little endian\n");
                break;
            case ELFDATA2MSB:
                printf("2's complement, big endian\n");
                break;
            default:
                printf("unknown\n");
        }
        printf("  Version:                           %d (current)\n",
               eh->ehdr32->e_version);
        printf("  OS/ABI:                            %s\n",
               elf_osabi_to_string(eh->ehdr32->e_osabi));
        printf("  ABI Version:                       %d\n",
               eh->ehdr32->e_abiversion);
        printf("  Type:                              %s\n",
               elf_type_to_string(eh->ehdr32->e_type));
        printf("  Entry point address:               0x%" PRIx32 "\n",
               eh->ehdr32->e_entry);
    }
}

const char *elf_osabi_to_string(unsigned char osabi) {
    switch (osabi) {
        case ELFOSABI_NONE:
            return "UNIX - System V";
        case ELFOSABI_HPUX:
            return "UNIX - HP/UX";
        case ELFOSABI_NETBSD:
            return "UNIX - NetBSD";
        case ELFOSABI_LINUX:
            return "UNIX - Linux";
        case ELFOSABI_SOLARIS:
            return "UNIX - Solaris";
        case ELFOSABI_AIX:
            return "UNIX - AIX";
        default:
            return "<unknown>";
    }
}

const char *elf_type_to_string(unsigned short type) {
    switch (type) {
        case ET