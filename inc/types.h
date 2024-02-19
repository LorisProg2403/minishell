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

typedef struct s_mini
{
	t_env	*envs;
	char	*path;
}	t_mini;


//typedef struct t_token t_token;
//typedef struct s_token {
//	int type;
//	char *command;
//	char *options;
//	char *agrs;
//	t_token next;
//} t_token;
#endif
