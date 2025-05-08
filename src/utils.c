#include "../includes/minishell.h"

// To detect Emty input
bool    is_blank_line(const char *s)
{
    size_t  i = 0;
    if (!s)
        return (true);
    while (s[i])
    {
        if (!isspace((unsigned char)s[i]))
            return (false);
        i++;
    }
    return (true);
}

void    print_syntax_error()
{
    perror("minishell: syntax error!\n");
    // extern int g_exit_status;
    // g_exit_status = 2;
}