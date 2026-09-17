/**
 * @file cli.c
 * @author DargoDargonyx
 * @date 09/17/26
 */

#include "cli.h"
#include "command.h"
#include "helper.h"

#include <stdio.h>
#include <string.h>


int cli_run(void) {
	char input[256];
	printf(PRINT_INFO_PREAMBLE "Kitty Task => Type 'help' for commands.\n");

	int result;
	while (1) {
		printf(PRINT_TEXPOP_PREAMBLE);
		if (fgets(input, sizeof(input), stdin) == NULL) {
			result = 1;
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		
		if (strcmp(input, "exit") == 0 
				|| strcmp(input, "quit") == 0
				|| strcmp(input, "q") == 0) {
			
			result = 0;
			break;
		}

		if (strcmp(input, "") == 0) continue;

		// Help command
		if (strcmp(input, "help") == 0)	
			cmd_print_help();
		// Commands related to tex profiles, delegates behaviour 
		// to another function
		else if (strcmp(input, "profiles") == 0)	
			cli_parse_tex_prof_cmd();
		else printf("Unknown command: %s\n", input);
	}

	return result;
}

void cli_parse_tex_prof_cmd(void) {
	return;
}
