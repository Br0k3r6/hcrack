#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.hpp"

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "[!] There was an error when parsing args for parser.out!" << std::endl;
		exit(EXIT_FAILURE);
	}
	Parser parser;
	strcpy(parser.command_exec, argv[1]);
	strcat(parser.command_exec, " ");

	strcat(parser.command_exec, argv[2]);
	strcat(parser.command_exec, " ");

	strcat(parser.command_exec, argv[3]);

	if (execution(parser) == 0) exit(EXIT_SUCCESS);
	else exit(EXIT_FAILURE);
	return 0;
}
