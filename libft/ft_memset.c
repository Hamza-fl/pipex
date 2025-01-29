/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:12:55 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/06 17:38:38 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	v;

	v = (unsigned char) c;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = v;
		i++;
	}
	return (s);
}

// int main()
// {
// 	int a = 0;
// 	ft_memset((unsigned char *)&a, 57, 1);
// 	ft_memset((unsigned char *)&a + 1, 5, 1);
// 	printf("%d\n", a);
// 	return 0;
// }