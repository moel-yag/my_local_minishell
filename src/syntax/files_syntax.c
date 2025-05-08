#include "../../includes/minishell.h"

int files_syntax(t_lexer *lex)
{
    char *msg = "minishell: syntax error near unexpected token `newline'";

    lex = lex->next;
    while (lex && lex->type == ' ')
        lex = lex->next;

    if (!lex || lex->type == '<' || lex->type == '>'
        /*|| lex->type == '<<' || lex->type == '>>'*/)
    {
        // ft_putendl_fd(msg, 2);
        printf("%s\n" ,msg);
        // g_env->exit_status = 2;
        return 2;
    }
    return 0;
}