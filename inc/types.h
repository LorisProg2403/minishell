/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:45:05 by bmabilla          #+#    #+#             */
/*   Updated: 2024/02/16 14:04:18 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_tmp
{
	char	*segment;
	int		i;
	int		start;
}	t_tmp;

typedef struct s_token {
	int				type;
	char			*command;
	char 			*options;
	char			*args;
	struct s_token	*next;
	struct s_token	*prev;
} t_token;

typedef struct s_mini
{
	t_token	*token;
	t_tmp	tmp;
	t_env	*envs;
	char	*path;
}	t_mini;
#endif
