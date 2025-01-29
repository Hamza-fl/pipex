/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:02:53 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/05 09:38:52 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*nn;

	nl = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		nn = ft_lstnew(f(lst->content));
		if (!nn)
		{
			ft_lstclear(&nl, del);
			return (NULL);
		}
		ft_lstadd_back(&nl, nn);
		lst = lst->next;
	}
	return (nl);
}

// void    dlt(void * content)
// {
//     free(content);
// }

// void *hh(void *content) 
// {
//     char *ptr = (char *)content;
//     char *new_ptr = strdup(ptr);
//     if (!new_ptr)
// 		return NULL;
//     for (int i = 0; new_ptr[i]; i++)
//         new_ptr[i] = ft_toupper(new_ptr[i]);
//     return new_ptr;
// }

// int main()
// {
//     t_list  *lst;
//     t_list  *ptr;
//     void    (*del)(void*);
//     del = &dlt;
//     void    *(*f)(void*);
//     f = hh;
//     lst = ft_lstnew(ft_strdup("ismail"));
//     ft_lstadd_back(&lst, ft_lstnew(ft_strdup("tabi")));
//     ptr = lst;
//     while (ptr)
//     {
//         printf("%s\n", ptr->content);
//         ptr = ptr->next;
//     }
//     t_list *nlst = ft_lstmap(lst, f, del);
//     ptr = nlst;
//     while (ptr)
//     {
//         printf("%s\n", ptr->content);
//         ptr = ptr->next;
//     }
// 	ft_lstclear(&lst, del);
// 	ft_lstclear(&nlst, del);
//     return 0;
// }
