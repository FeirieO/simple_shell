#include "main.h"

/**
 * gets_sign - function for the crtl + c call in prompt
 * @signal: Signal handler
 */

void gets_sign(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
