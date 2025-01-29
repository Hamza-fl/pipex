/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:45:19 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/07 12:42:54 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}

// int main()
// {
//     t_list *head;
//     t_list *nn;
// 	t_list *curr;
//     char *str0 = "ismail";
//     char *str1 = "abdo";
//     char *str2 = "hamza";
//     char *str3 = "mouad";
//     node = ft_lstnew(str0);
//     head->next = ft_lstnew(str1);
//     //node->next->next = ft_lstnew(str2);
//     ft_lstadd_back(&head, ft_lstnew(str2));
//     ft_lstadd_back(&head, ft_lstnew(str3));
// 	curr = head;
//     while(curr)
//     {
//         printf("%s\n", curr->content);
//         curr = curr->next;
//     }
//     curr = head;
//     while (curr)
//     {
//         nn = curr->next;
//         free(curr);
//         curr = nn;
//     }
//     return 0;
// }
