/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:36:59 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/07 12:52:13 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (!lst)
		return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

int main()
{
    t_list  *lst;
    char *str0 = ft_strdup("1");
    char *str1 = ft_strdup("2");
    char *str2 = ft_strdup("3");
    char *str3 = ft_strdup("4");
    lst = ft_lstnew(str0);
    ft_lstadd_back(&lst, ft_lstnew(str1));
    ft_lstadd_back(&lst, ft_lstnew(str2));
    ft_lstadd_back(&lst, ft_lstnew(str3));
    printf("%s\n", lst->content);
    lst = ft_lstlast(NULL);
    printf("%s\n", lst->content);
    t_list  *curr = lst;
    while (curr)
    {
        curr = lst;
        free(curr->content);
        free(curr);
        curr = curr->next;
    }
    return 0;
}
