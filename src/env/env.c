/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:17:55 by bmabilla          #+#    #+#             */
/*   Updated: 2024/02/16 14:17:55 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void init_envs(t_mini *mini, char **env)
{
	int i;
	int count;
	t_env	e;
	char	**split;

	set_zero(2, &i, &count);
	while (env[count])
		count++;
	(*mini).envs = malloc(sizeof(t_env) * (count + 1));
	while (env[i])
	{
		split = ft_split(env[i], '=');
		if (split[0] && split[1])
		{
			e.key = split[0];
			e.value = split[1];
			(*mini).envs[i] = e;
		}
		i++;
		free(split);
	}
}

