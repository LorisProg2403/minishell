/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:52:43 by bmabilla          #+#    #+#             */
/*   Updated: 2024/02/20 17:52:45 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	pwd(t_mini *mini)
{
	char	*pwd;
	char 	buff[1024];

	(void)mini;
	pwd = getcwd(buff, sizeof(buff));
	if (pwd != NULL)
		printf("%s\n", pwd);
	else
		perror("pwd error");
}