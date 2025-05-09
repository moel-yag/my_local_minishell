#include "../includes/minishell.h"

int main(void)
{
	char *input;

	while (1)
	{
		input = readline("minishell> ");
		if (!input) // Handle EOF (Ctrl+D)
			break;
		if (*input)
			add_history(input);
		if (is_blank_line(input))
		{
			free(input);
			continue;
		}
		// Validate syntax
		if (!unclosed_quotes(input) || !pipe_syntax(input)
			|| !file_syntax(input) || !check_syntax(input))
		{
			free(input);
			continue; // Prompt again if validation fails
		}
		// Pass validated input to ft_split
		char **tokens = ft_split(input, ' ');
		if (tokens)
		{
			int i = 0;
			while (tokens[i])
			{
				free(tokens[i]);
				i++;
			}
			if (tokens)
				free(tokens);
		}
		free(input);
	}

	return 0;
}
