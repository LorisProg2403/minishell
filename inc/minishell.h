/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:55:46 by lgaume            #+#    #+#             */
/*   Updated: 2024/02/16 13:59:22 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/include/libft.h"
# include "types.h"
# include "constants.h"
# include <readline/readline.h>
# include <readline/history.h>
#include <fcntl.h>


//COMMANDS DIR
void	echo(t_mini *mini, t_token *token);

// ENV DIRECTORY
// env.c
void 	init_envs(t_mini *mini, char **env);

// TOKENS DIRECTORY
// tokens_input.c
void	init_tokens(t_mini *mini, char *input);
void	add_token(t_mini *mini, char *command, char *del);
// tokens.c
void	init_tokens_mini(t_mini *mini, char *command, char *del);

// SRCS DIRECTORY
// utils.c
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
char	*ft_strcat(char *dest, char *src);

// lst_utils.c
void	add_back_token(t_token **lst, t_token *n);
t_token	*lst_last_token(t_token *lst);
void	lst_tkn_delone(t_token *lst);
void	lst_tkn_clear(t_token **lst);

// input.c
int		handle_input(t_mini *mini);

#endif
