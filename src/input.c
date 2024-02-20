/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 03:19:30 by lgaume            #+#    #+#             */
/*   Updated: 2024/02/07 03:19:34 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*make_path(char *path)
{
	path = ft_strjoin(CYAN, path);
	path = ft_strjoin(path, "\n");
	path = ft_strjoin(path, BRED);
	path = ft_strjoin(path, "❯ ");
	path = ft_strjoin(path, RESET);
	return (path);
}

int	handle_input(t_mini *mini)
{
	char	*input;
	char	*path_terminal;

	path_terminal = make_path(mini->path);
	input = readline(path_terminal);
	if (!input)
		return (0);
	if (*input)
		add_history(input);
	if (!ft_strcmp(input, "exit"))
	{
		free(input);
		return (1);
	}
	else
		init_tokens(mini, input);
	free(input);
	return (0);
}
