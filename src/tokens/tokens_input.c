/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:26:44 by bmabilla          #+#    #+#             */
/*   Updated: 2024/02/19 16:26:44 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**get_dels(void)
{
	char	**dels;

	dels = malloc(sizeof(char *) * 8);
	dels[0] = "&&";
	dels[1] = "||";
	dels[2] = "|";
	dels[3] = ">>";
	dels[4] = ">";
	dels[5] = "<<";
	dels[6] = "<";
	dels[7] = NULL;
	return (dels);
}

int	is_delimiter(char *p, char **found_delim)
{
	char	**dels;
	int		i;
	size_t	len;

	dels = get_dels();
	i = 0;
	while (dels[i])
	{
		len = ft_strlen(dels[i]);
		if (ft_strncmp(p, dels[i], len) == 0)
		{
			*found_delim = dels[i];
			return (1);
		}
		i++;
	}
	return (0);
}

void	split_cmds_2(char **input, char	**start, char *segment, char **delim)
{
	size_t	len;

	len = (*input) - (*start);
	segment = (char *)malloc(len + 1);
	ft_strncpy(segment, *start, len);
	segment[len] = '\0';
	printf("Segment: |%s|, Delimiter: '%s'\n", segment, *delim);
	free(segment);
	*input += ft_strlen(*delim);
	*start = *input;
}

void	split_commands(t_mini *mini, char *input, char	*segment)
{
	(void)mini;
	char	*start;
	int		in_sgl_quote;
	int		in_dbl_quote;
	char	*found_delim;

	start = input;
	set_zero(2, &in_sgl_quote, &in_dbl_quote);
	while (*input)
	{
		if (*input == '\"' && !in_sgl_quote)
			in_dbl_quote = !in_dbl_quote;
		else if (*input == '\'' && !in_dbl_quote)
			in_sgl_quote = !in_sgl_quote;
		if (!in_sgl_quote && !in_dbl_quote && is_delimiter(input, &found_delim))
			split_cmds_2(&input, &start, segment, &found_delim);
		else
			++input;
	}
	if (start)
	{
		segment = ft_strdup(start);
		printf("Segment: |%s|, Delimiter: None\n", segment);
		free(segment);
	}
}

void	init_tokens(t_mini *mini, char *input)
{
	split_commands(mini, input, "");
}