/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:44:43 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/06 12:27:33 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t numberOfBytes)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	i = 0;
	dest = (unsigned char *)d;
	src = (const unsigned char *)s;
	while (i < numberOfBytes)
	{
		dest[i] = src[i];
		i++;
	}
	return (d);
}

// int  main()
// {
//     char *buffer = (void *)0;
//     char *dest = NULL;
//     memcpy(NULL, "LLLL", 5);
//     printf("%s\n", dest);
//     return 0;
// }