/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:53:11 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/06 17:23:09 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	i = 0;
	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == ch)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	int a = 1337;
// 	unsigned char *ptr;
// 	ptr = ft_memchr(&a, 5, sizeof(int));
// 	printf("%d\n", *ptr);
// 	return 0;
// }
