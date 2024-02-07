/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaume <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:56:34 by lgaume            #+#    #+#             */
/*   Updated: 2024/01/24 11:56:36 by lgaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int main(void)
{
	while (1)
	{
		int i = handle_input();
		if (i)
		{
			ft_printf(BRED"\nYou exit the minishell...\n"RESET);
			return (0);
		}
	}
}
