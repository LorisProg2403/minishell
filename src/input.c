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

void	handle_command(t_mini *mini, t_token *token)
{
	if (!ft_strcmp("echo", token->command))
		echo(mini, token);
	else if (!ft_strcmp("pwd", token->command))
		pwd(mini);
	//if ()
	// todo: faire ici les test (mini->token->type) pour savoir quelles commandes appeler
	// y a deja les fichiers des commandes, faut juste les remplir

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
	{
		lst_tkn_clear(&(mini->token));
		init_tokens(mini, input);
		handle_command(mini, mini->token);
	}

	free(input);
	return (0);
}
