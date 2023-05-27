#include "shell.h"

/**
 * hundle_ctrl - Function that hundles Ctrl-C signal
 * @signal: Argument to the singal function
 * Return : Void
*/

void hundle_ctrl(int signal)
{
	(void)signal;
	write(1, "\n$ ", 4);
}
