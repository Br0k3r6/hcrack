#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Parser {
	char command_exec[2048];
} parse;

int execution(struct Parser args) {
	char* cmd = args.command_exec;
	system(cmd);
	return 0;
}

#endif
