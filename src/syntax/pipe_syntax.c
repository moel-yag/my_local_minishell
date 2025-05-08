#include "../../includes/minishell.h"

bool pipe_syntax(const char *input)
{
    int i = 0;
    bool prev_pipe = false;

    while (input[i])
    {
        if (input[i] == '|')
        {
            if (prev_pipe || i == 0 || input[i + 1] == '\0')
            {
                printf("Error: Invalid pipe syntax\n");
                return (false);
            }
            prev_pipe = true;
        }
        else if (input[i] != ' ' && input[i] != '\t')
        {
            prev_pipe = false;
        }
        i++;
    }
    return (true);
}

// int pipe_syntax(t_lexer *lex)
// {
//     t_lexer *tmp = lex->prev;

//     while (tmp && tmp->type == ' ')
//         tmp = tmp->prev;

//     lex = lex->next;
//     while (lex && lex->type == ' ')
//         lex = lex->next;

//     if (!lex || lex->type == '|' || !tmp || tmp->type == '|' ||
//         tmp->type == '<' || tmp->type == '>' /*|| tmp->type == '<<' || tmp->type == '>>'*/)
//     {
//         // ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
//         printf("minishell: syntax error near unexpected token `|'");

//         // g_env->exit_status = 2;
//         return 2;
//     }
//     return 0;
// }