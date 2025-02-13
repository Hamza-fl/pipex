/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:50:34 by hfalati           #+#    #+#             */
/*   Updated: 2025/02/11 12:49:42 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strnstr(const char *hs, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;

	nlen = ft_strlen(n);
	if (nlen == 0)
		return ((char *)hs);
	if (len == 0)
		return (NULL);
	i = 0;
	while (i + nlen <= len && hs[i] != '\0')
	{
		j = 0;
		while (j < nlen && hs[i + j] == n[j] && (i + j) < len)
			j++;
		if (j == nlen)
			return ((char *)(hs + i));
		i++;
	}
	return (NULL);
}
