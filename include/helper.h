/**
 * @file helper.h
 * @author DargoDargonyx
 * @date 09/17/26
 */

#ifndef HELPER_H
#define HELPER_H

#include "ansi.h"


// Macros for repeatable output strings
#define PRINT_INFO_PREAMBLE		ANSI_BOLD ANSI_CYAN "[INFO] " ANSI_RESET
#define PRINT_ERROR_PREAMBLE	ANSI_BOLD ANSI_RED "[ERROR] " ANSI_RESET
#define PRINT_WARNING_PREAMBLE	ANSI_BOLD ANSI_YELLOW "[WARNING] " ANSI_RESET
#define PRINT_TEXPOP_PREAMBLE	ANSI_BOLD ANSI_MAGENTA "[TexPop] " ANSI_RESET


#endif // HELPER_H
