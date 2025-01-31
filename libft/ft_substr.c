/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:06:43 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/07 16:17:17 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate_substring(size_t len)
{
	char	*substring;

	substring = (char *)malloc(len * sizeof(char) + 1);
	if (!substring)
		return (NULL);
	substring[len] = '\0';
	return (substring);
}

char	*ft_substr(char const *novel, unsigned int start, size_t len)
{
	size_t	novel_len;
	char	*book;
	size_t	i;

	novel_len = ft_strlen(novel);
	if (start >= novel_len)
		return (allocate_substring(0));
	if (len > novel_len - start)
		len = novel_len - start;
	printf("%zu\n", len);
	book = allocate_substring(len);
	if (!book)
		return (NULL);
	i = 0;
	while (i < len && novel[start + i])
	{
		book[i] = novel[start + i];
		i++;
	}
	book[i] = '\0';
	return (book);
}
