/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:08:25 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/06 17:39:17 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nof, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nof == 0 || size == 0)
		return (malloc(0));
	if (nof > ((size_t)-1) / size)
		return (NULL);
	total_size = nof * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
