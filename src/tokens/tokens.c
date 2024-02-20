/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:35:45 by bmabilla          #+#    #+#             */
/*   Updated: 2024/02/19 16:35:48 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	prepare_token_3(t_token *tkn)
{
	if (ft_strlen(tkn->options) > 0
		&& tkn->options[ft_strlen(tkn->options) - 1] == ' ')
		tkn->options[ft_strlen(tkn->options) - 1] = '\0';
	if (ft_strlen(tkn->args) > 0 && tkn->args[ft_strlen(tkn->args) - 1] == ' ')
		tkn->args[ft_strlen(tkn->args) - 1] = '\0';
}

void	prepare_token_2(t_mini *mini, t_token *tkn, char *cmd, int *section)
{
	int	i;
	int	start;

	i = mini->tmp.i;
	start = mini->tmp.start;
	if ((*section) == 0)
	{
		ft_strncpy(tkn->command, cmd + start, i - start);
		tkn->command[i - start] = '\0';
		(*section)++;
	}
	else if ((*section) == 1 && cmd[start] == '-')
	{
		ft_strncat(tkn->options, cmd + start, i - start);
		ft_strcat(tkn->options, " ");
	}
	else
	{
		if ((*section) == 1)
			(*section)++;
		ft_strncat(tkn->args, cmd + start, i - start);
		ft_strcat(tkn->args, " ");
	}
	mini->tmp.start = i + 1;
}

void	prepare_token(t_mini *mini, t_token *tkn, char *cmd)
{
	int	length;
	int	i;
	int	start;
	int	in_quotes;
	int	section;

	length = ft_strlen(cmd);
	set_zero(4, &i, &start, &in_quotes, &section);
	while (i <= length)
	{
		if (cmd[i] == '"' && (i == 0 || cmd[i - 1] != '\\'))
			in_quotes = !in_quotes;
		if ((cmd[i] == ' ' && !in_quotes) || i == length)
		{
			mini->tmp.i = i;
			mini->tmp.start = start;
			prepare_token_2(mini, tkn, cmd, &section);
			start = mini->tmp.start;
		}
		i++;
	}
	prepare_token_3(tkn);
}

int	get_type(char *del)
{
	if (del == NULL)
		return (DEL_NULL);
	else if (!ft_strcmp(del, ">>"))
		return (DEL_2ARW_R);
	else if (!ft_strcmp(del, "<<"))
		return (DEL_2ARW_L);
	else if (!ft_strcmp(del, ">"))
		return (DEL_2ARW_L);
	else if (!ft_strcmp(del, "<"))
		return (DEL_2ARW_L);
	else if (!ft_strcmp(del, "&&"))
		return (DEL_2ARW_L);
	else if (!ft_strcmp(del, "&"))
		return (DEL_2ARW_L);
	else if (!ft_strcmp(del, "||"))
		return (DEL_2ARW_L);
	else if (!ft_strcmp(del, "|"))
		return (DEL_2ARW_L);
	else
		return (DEL_UNDEFINED);
}

void	add_token(t_mini *mini, char *command, char *del)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->command = ft_calloc(256, sizeof(char));
	token->options = ft_calloc(256, sizeof(char));
	token->args = ft_calloc(1024, sizeof(char));
	token->next = NULL;
	token->prev = NULL;
	token->type = get_type(del);
	prepare_token(mini, token, command);
	if (!mini->token)
	{
		mini->token = malloc(sizeof(t_token));
		mini->token = token;
	}
	else
		add_back_token(&mini->token, token);
}
