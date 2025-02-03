/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:00:21 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/02 14:05:07 by hfalati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_process_quote(const char *str, int *i, int *in_quotes, char *quote_type)
{
	int	count;

	count = 0;
	if (is_quote(str[*i]))
	{
		if (!(*in_quotes))
		{
			*quote_type = str[*i];
			*in_quotes = 1;
			count = 1;
		}
		else if (str[*i] == *quote_type)
		{
			*in_quotes = 0;
			*quote_type = 0;
		}
		(*i)++;
	}
	return (count);
}

static int	ft_count_words(char const *str, char c)
{
	int		i;
	int		count;
	int		in_quotes;
	char	quote_type;

	i = 0;
	count = 0;
	in_quotes = 0;
	quote_type = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			count += ft_process_quote(str, &i, &in_quotes, &quote_type);
		else if (!in_quotes && str[i] == c)
			i++;
		else if (!in_quotes)
		{
			count++;
			while (str[i] && str[i] != c && !is_quote(str[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*extract_quoted_word(const char *s, int *i, char quote_type)
{
	int		word_start;
	char	*word;
	int		j;

	word_start = ++(*i);
	j = 0;
	while (s[*i] && s[*i] != quote_type)
		(*i)++;
	word = (char *)malloc(sizeof(char) * (*i - word_start + 1));
	if (!word)
		return (NULL);
	while (word_start < *i)
		word[j++] = s[word_start++];
	word[j] = '\0';
	if (s[*i] == quote_type)
		(*i)++;
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **str, int num_words)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (word < num_words)
	{
		if (is_delimiter(s, c, &i))
			break ;
		str[word] = process_word(s, c, &i, is_quote(s[i]));
		if (!str[word])
			return (free_array(str, word));
		word++;
	}
	str[word] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!str)
		return (0);
	str = ft_split_words(s, c, str, num_words);
	return (str);
}
