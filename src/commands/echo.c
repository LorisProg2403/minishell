/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:49 by bmabilla          #+#    #+#             */
/*   Updated: 2024/02/20 17:48:49 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_echo(t_token *token)
{
	printf("%s", token->args);
	if (ft_strcmp("-n", token->options))
		printf("\n");
}

void	overwrite_echo(t_mini *mini, t_token *token, t_token *next)
{
	int		fd;
	char	*msg;
	char	*path;

	path = ft_strjoin(mini->path, "/");
	path = ft_strjoin(path, next->command);
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(path);
	if (fd == -1)
		return (perror("Error opening file"));
	if (ft_strcmp("-n", token->options))
		msg = ft_strjoin(token->args, "\n");
	else
		msg = ft_strjoin(token->args, "");
	if (write(fd, msg, ft_strlen(msg)) == -1)
		perror("Error writing to file");
	free(msg);
	close(fd);
}

void	append_echo(t_mini *mini, t_token *token, t_token *next)
{
	int		fd;
	char	*msg;
	char	*path;

	path = ft_strjoin(mini->path, "/");
	path = ft_strjoin(path, next->command);
	fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(path);
	if (fd == -1)
		return (perror("Error opening file"));
	if (ft_strcmp("-n", token->options))
		msg = ft_strjoin(token->args, "\n");
	else
		msg = ft_strjoin(token->args, "");
	if (write(fd, msg, ft_strlen(msg)) == -1)
		perror("Error writing to file");
	free(msg);
	close(fd);
}

void	echo(t_mini *mini, t_token *token)
{
	t_token	*next;

	next = token->next;
	if (token->type == DEL_NULL)
		print_echo(token);
	else if (token->type == DEL_ARW_R)
		overwrite_echo(mini, token, next);
	else if (token->type == DEL_2ARW_R)
		append_echo(mini, token, next);
	while (next && next->type != DEL_NULL)
	{
		if (next->type == DEL_ARW_R)
			overwrite_echo(mini, token, next->next);
		else if (next->type == DEL_2ARW_R)
			append_echo(mini, token, next->next);
		next = next->next;
	}
}
