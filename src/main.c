#include "../includes/minishell.h"

void  multi_to_single_space(char **av, char *res, int ac)
{
  int (i), (j), (k);

  i = 1;
  k = 0;
  while (i < ac)
  {
    j = 0;
    while (av[i][j])
    {
      while (av[i][j] && av[i][j] == ' ')
        j++;
      while (av[i][j] && av[i][j] != ' ')
        res[k++] = av[i][j++];
      while (av[i][j] && av[i][j] == ' ')
        j++;
      if (av[i][j] != '\0')
        res[k++] = ' ';
    }
    if (i < ac - 1)
      res[k++] = ' ';
    i++;
  }
  res[k] = '\0';
}

int main(int ac, char **av)
{
  char *input;

  while (1)
  {
    input = readline("minishell> ");
    if (!input) // Handle EOF (Ctrl+D)
      break;

    // Add input to history if it's not empty
    if (*input)
        add_history(input);

    // Check for blank input
    if (is_blank_line(input))
    {
      free(input);
      continue;
    }

    // Validate syntax
    if (!unclosed_quotes(input))
    {
      free(input);
      continue; // Prompt again if validation fails
    }

    // Pass validated input to ft_split
    char **tokens = ft_split(input, ' '); // Example: split by spaces
    if (tokens)
    {
        // Process tokens (e.g., execute commands)
        for (int i = 0; tokens[i]; i++)
            free(tokens[i]);
        free(tokens);
    }

    free(input); // Free input after processing
  }
  
  // if (ac < 2)
  // {
  //   printf("\n");
  //   return 0;
  // }
  // char *res = malloc(1000);
  // if (res == NULL)
  // {
  //   perror("malloc");
  //   return 1;
  // }
  // multi_to_single_space(av, res, ac);
  // // printf("%s\n", res);
  // t_command *cmd = parse_input(res);
  // if (cmd == NULL)
  // {
  //   free(res);
  //   return 1;
  // }
  // shell_loop(cmd);
  // free(cmd);

  return 0;
}
