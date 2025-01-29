/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:55:19 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/06 12:18:45 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	num_converter(char *str, long n, size_t len)
{
	while (len > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
		if (n == 0 && len == 1 && str[0] == '-')
			break ;
	}
}

char	*ft_itoa(int nb)
{
	char	*str;
	size_t	len;
	long	n;

	n = nb;
	len = count_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	num_converter(str, n, len);
	return (str);
}

/*
int main()
{
	printf("%s", ft_itoa(-2147483648));
	return 0;
}
*/