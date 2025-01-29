/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:28:51 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/05 15:18:20 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	ptr = lst;
	i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

// int main()
// {
//     t_list  *lst;
//     char    *str = "ismail";
//     char    *str1 = "abdo";
//     char    *str2 = "hamza";
//     char    *str3 = "mouad";
//     lst = ft_lstnew(str);
//     ft_lstadd_back(&lst, ft_lstnew(str1));
//     ft_lstadd_back(&lst, ft_lstnew(str2));
//     ft_lstadd_back(&lst, ft_lstnew(str3));
//     printf("%d\n", ft_lstsize(lst));
//     return 0;
// }
