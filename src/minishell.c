/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:56:34 by lgaume            #+#    #+#             */
/*   Updated: 2024/02/19 16:28:48 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_minishell(t_mini *mini, int ac, char **av, char **env)
{
	char	path[PATH_MAX];
	(void)ac;
	(void)av;
	init_envs(mini, env);
	if (getcwd(path, sizeof(path)) == NULL)
	{
		ft_printf("getcwd error\n");
		exit(ERROR);
	}
	mini->path = ft_strdup(path);
	mini->token = NULL;
}

int main(int ac, char **av, char **env)
{
	t_mini	mini;

	init_minishell(&mini, ac, av, env);
	while (1)
	{
		int i = handle_input(&mini);
		printf("funciton 1: %s\n", mini.token->command);
		if (i)
		{
			ft_printf(BRED"\nYou exit the minishell...\n"RESET);
			return (0);
		}
	}
}
