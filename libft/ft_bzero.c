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

static	void print_buffer(const char *buffer, size_t size) {
	for (size_t i = 0; i < size; i++) 
	{ 
		if (buffer[i] == 0) 
		{ 
			printf("\\0 ");
		}
		else
		{ 
			printf("%c ", buffer[i]); 
		} 
	}
	printf("\n");
}

int main() {
	 char buffer0[] = "ismail"; 
	 char *buffer1 = "ismail";
	// ft_bzero(buffer0, 0);
	 bzero(buffer1, 0);
	 print_buffer(buffer0, 1); 
	 print_buffer(buffer1, 1); 
	 return 0;
}