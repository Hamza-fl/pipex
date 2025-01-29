/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:09 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/05 09:24:59 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*l;

	l = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			l = &s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return ((char *)l);
}

// int main()
// {
// 	char buffer[] = "ssssssssssssssOssssssssssssssO";
// 	printf("%p\n", ft_strrchr(buffer, 'O'));
// 	return 0;
// }