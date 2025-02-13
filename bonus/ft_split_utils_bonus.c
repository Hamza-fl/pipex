/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:54:12 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/11 12:49:25 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*extract_regular_word(const char *s, int *i, char c)
{
	int		word_start;
	char	*word;
	int		j;

	j = 0;
	word_start = *i;
	while (s[*i] && s[*i] != c && !is_quote(s[*i]))
		(*i)++;
	word = (char *)malloc(sizeof(char) * (*i - word_start + 1));
	if (!word)
		return (NULL);
	while (word_start < *i)
		word[j++] = s[word_start++];
	word[j] = '\0';
	return (word);
}

int	is_delimiter(char const *s, char c, int *i)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	return (s[*i] == '\0');
}

char	*process_word(char const *s, char c, int *i, int is_quote_word)
{
	char	quote_type;
	char	*word;

	if (is_quote_word)
	{
		quote_type = s[*i];
		word = extract_quoted_word(s, i, quote_type);
	}
	else
	{
		word = extract_regular_word(s, i, c);
	}
	return (word);
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"' || c == 96);
}

char	**free_array(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free (str);
	return (0);
}
