/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:34:43 by bmabilla          #+#    #+#             */
/*   Updated: 2024/02/21 16:34:47 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_token	*lst_last_token(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_back_token(t_token **lst, t_token *n)
{
	t_token	*last;

	if (lst)
	{
		if (*lst)
		{
			last = lst_last_token(*lst);
			last->next = n;
		}
		else
			*lst = n;
	}
}

void	lst_tkn_delone(t_token *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	lst_tkn_clear(t_token **lst)
{
	t_token	*prev;
	t_token	*tmp;

	if (lst && *lst)
	{
		prev = (t_token *)*lst;
		while (prev)
		{
			tmp = prev->next;
			lst_tkn_delone(prev);
			prev = tmp;
		}
		*lst = NULL;
	}
}
