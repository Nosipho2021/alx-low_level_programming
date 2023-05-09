#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

void print_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }
    char* filename = argv[1];


    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("Failed to open file");
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Failed to read ELF header");
    }


    if (header.e_ident[EI_MAG0] != ELFMAG0
        || header.e_ident[EI_MAG1] != ELFMAG1
        || header.e_ident[EI_MAG2] != ELFMAG2
        || header.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("File is not an ELF file");
    }


    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2MSB ? "big endian" : "little endian");
    printf("Version:                           %d\n", header.e_ident[EI_VERSION]);
    printf("OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" : "Other");
    printf("ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("Type:                              %s\n", header.e_type == ET_EXEC ? "EXEC (Executable file)" : (header.e_type == ET_DYN ? "DYN (Shared object file)" : "Other"));
    printf("Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

    close(fd);

    return 0;
}

