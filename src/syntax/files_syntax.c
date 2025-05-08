#include "../../includes/minishell.h"

int files_syntax(t_lexer *lex)
{
    char *msg = "minishell: syntax error near unexpected token `newline'";

    lex = lex->next;
    while (lex && lex->type == 'W')
        lex = lex->next;

    if (!lex || lex->type == 'I' || lex->type == 'O' || lex->type == 'H' || lex->type == 'A')
    {
        // ft_putendl_fd(msg, 2);
        printf("%s\n" ,msg);
        // g_env->exit_status = 2;
        return 2;
    }
    return 0;
}