/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:53:37 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/04 13:17:28 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	if (!s && !f)
		return ;
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
}

// void    upp(unsigned int i, char *s)
// {
//     *s = *s - 32;
// }

// int main()
// {
//     char s[] = "ismail";
//     void (*f)(unsigned int, char*);
//     f = &upp;
//     ft_striteri(s, f);
//     printf("%s\n", s);
//     return 0;
// }
