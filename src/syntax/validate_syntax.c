#include "../../includes/minishell.h"

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

// bool validate_syntax(const char *input)
// {
//     t_lexer *lex = tokenize_input(input);
//     if (!lex)
//         return (false);

//     if (check_syntax(lex) != 0)
//     {
//         // free_lexer(lex);
//         return (false);
//     }

//     // free_lexer(lex);
//     return (true);
// }
