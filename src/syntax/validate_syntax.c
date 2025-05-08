#include "../../includes/minishell.h"

t_lexer *create_token(const char *value)
{
    t_lexer *new_token = malloc(sizeof(t_lexer));
    if (!new_token)
        return (NULL);
    new_token->value = strdup(value); // Duplicate the token value
    if (!new_token->value)
    {
        free(new_token);
        return (NULL);
    }
    new_token->next = NULL;
    return (new_token);
}

t_lexer *tokenize_input(const char *input)
{
    t_lexer *head = NULL;
    t_lexer *current = NULL;
    char *token;
    char *input_copy = strdup(input);

    if (!input_copy)
        return (NULL);

    token = strtok(input_copy, " \t"); // Split input by spaces or tabs
    while (token)
    {
        t_lexer *new_token = create_token(token);
        if (!new_token)
        {
            free(input_copy);
            free_lexer(&head); // Free already created tokens
            return (NULL);
        }
        if (!head)
            head = new_token;
        else
            current->next = new_token;
        current = new_token;
        token = strtok(NULL, " \t");
    }
    free(input_copy);
    return (head);
}

bool unclosed_quotes(const char *input)
{
  int i, single_q, double_q;

  i = 0;
  single_q = 0;
  double_q = 0;
  while (input[i])
  {
    if (input[i] == '\'' && !double_q)
      single_q ^= 1;
    else if (input[i] == '"' && !single_q)
      double_q ^= 1;
    i++;
  }
  if (single_q || double_q)
  {
    printf("Error: Unclosed quotes\n");
    return (false);
  }
  return (true);
}

bool validate_syntax(const char *input)
{
    t_lexer *lex = tokenize_input(input);
    if (!lex)
        return (false);

    if (check_syntax(lex) != 0)
    {
        free_lexer(&lex);
        return (false);
    }

    free_lexer(&lex);
    return (true);
}
