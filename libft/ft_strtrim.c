/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:56:45 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/05 09:01:05 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) - 1;
	ptr = NULL;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[len]))
		len--;
	ptr = ft_substr(s1, i, len - i + 1);
	return (ptr);
}

// int main()
// {
//     char buffer[] = "xaxaxaxaxaxaxISMAILxaxaxaxaxax";
//     printf("%s\n", ft_strtrim(buffer, "xa"));
//     return 0;
// }