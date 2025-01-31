/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:01:33 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/07 16:45:44 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t numberOfBytes)
{
	size_t			i;
	unsigned char	*nptr;

	nptr = (unsigned char *)ptr;
	i = 0;
	while (i < numberOfBytes)
	{
		nptr[i] = 0;
		i++;
	}
}

