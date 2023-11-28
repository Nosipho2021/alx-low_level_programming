#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error_exit - Print an error message to stderr and exit with code 98
 * @msg: The error message to print
 */
void print_error_exit(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}
/**
 * print_elf_header - Print information from the ELF header
 * @header: Pointer to the ELF header structure
 */


void print_elf_header(const Elf64_Ehdr *header)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
	printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)" : "Other");
	printf("  Entry point address:               %#lx\n", (unsigned long)header->e_entry);
}
/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings representing the command-line arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	print_error_exit("Usage: elf_header elf_filename");
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd ==  -1)
	{
	print_error_exit("Error opening file");
	}

	Elf64_Ehdr elf_header;
	ssize_t read_size = read(fd, &elf_header, sizeof(elf_header));

	if (read_size == -1)
	{
	print_error_exit("Error reading file");
	}

	if (read_size != sizeof(elf_header) || elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
	elf_header.e_ident[EI_MAG1] != ELFMAG1 || elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
	print_error_exit("Not an ELF file");
	}

	print_elf_header(&elf_header);
	close(fd);

	return (0);
}

