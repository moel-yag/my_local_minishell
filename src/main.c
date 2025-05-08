#include "../includes/minishell.h"

int main(void)
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
		if (!pipe_syntax(input))
		{
			free(input);
			continue;
		}
		// Pass validated input to ft_split
		char **tokens = ft_split(input, ' ');
		if (tokens)
		{
			// Process tokens (e.g., execute commands)
			int i = 0;
			while (tokens[i]) {
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
