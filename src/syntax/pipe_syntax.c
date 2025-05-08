#include "../../includes/minishell.h"

int pipe_syntax(t_lexer *lex)
{
    t_lexer *tmp = lex->prev;

    while (tmp && tmp->type == ' ')
        tmp = tmp->prev;

    lex = lex->next;
    while (lex && lex->type == ' ')
        lex = lex->next;

    if (!lex || lex->type == '|' || !tmp || tmp->type == '|' ||
        tmp->type == '<' || tmp->type == '>' /*|| tmp->type == '<<' || tmp->type == '>>'*/)
    {
        // ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
        printf("minishell: syntax error near unexpected token `|'");

        // g_env->exit_status = 2;
        return 2;
    }
    return 0;
}