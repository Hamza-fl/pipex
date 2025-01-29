/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:57 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/05 15:12:44 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
//     t_list  *node;
//     char *str0 = "mouad";
//     char *str1 = "hamza";
//     char *str2 = "abdo";
//     char *str3 = "ismail";
//     node = ft_lstnew(str0);
//     ft_lstadd_back(&node, ft_lstnew(str1));
//     ft_lstadd_back(&node, ft_lstnew(str2));
//     ft_lstadd_front(&node, ft_lstnew(str3));
//     while (node)
//     {
//         printf("%s\n", node->content);
//         node = node->next;
//     }
//     t_list *curr = node;
//     t_list *nn = NULL;
//     while (curr)
//     {
//         nn = curr->next;
//         free(curr);
//         curr = nn;
//     }
//     return (0);
// }