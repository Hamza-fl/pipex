/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:34:12 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/06 14:21:46 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

// #include <fcntl.h>
// int main()
// {
//     int fd = open("text.txt", O_CREAT | O_RDWR, 0777);
//     ft_putstr_fd("psps", fd);
//     return 0;
// }
