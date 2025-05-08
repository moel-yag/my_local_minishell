#include "../../includes/minishell.h"

int pipe_syntax(t_lexer *lex)
{
    t_lexer *tmp = lex->prev;

    while (tmp && tmp->type == 'W')
        tmp = tmp->prev;

    lex = lex->next;
    while (lex && lex->type == 'W')
        lex = lex->next;

    if (!lex || lex->type == 'P' || !tmp || tmp->type == 'P' ||
        tmp->type == 'I' || tmp->type == 'O' || tmp->type == 'H' || tmp->type == 'A')
    {
        // ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
        printf("minishell: syntax error near unexpected token `|'");

        // g_env->exit_status = 2;
        return 2;
    }
    return 0;
}