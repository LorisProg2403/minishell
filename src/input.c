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

int	handle_input(void)
{
	char	*input;

	input = readline("MINISHELL : ");
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
		ft_printf("You entered: %s\n\n", input);
	free(input);
	return (0);
}
