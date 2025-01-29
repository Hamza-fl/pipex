/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:06 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/05 11:54:11 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*c;
	t_list	*n;

	if (!lst || !del)
		return ;
	c = *lst;
	while (c)
	{
		n = c->next;
		ft_lstdelone(c, del);
		c = n;
	}
	*lst = NULL;
}

// void	dlt(void	*content)
// {
// 	free(content);
// }

// int main()
// {
// 	void	(*del)(void *);
// 	del = &dlt;
// 	t_list	*node;
// 	char *str0 = ft_strdup("ismail");
// 	char *str1 = ft_strdup("mouad");
// 	char *str2 = ft_strdup("abdo");
// 	char *str3 = ft_strdup("hamza");	
// 	node = ft_lstnew(str0);
// 	ft_lstadd_back(&node, ft_lstnew(str1));
// 	ft_lstadd_back(&node, ft_lstnew(str2));
// 	ft_lstadd_back(&node, ft_lstnew(str3));
// 	t_list	*curr = node;
// 	while (curr)
// 	{
// 		printf("%s\n", curr->content);
// 		curr = curr->next;
// 	}
// 	ft_lstclear(&node, del);
// 	curr = node;
// 	while (curr)
// 	{
// 		printf("%s\n", curr->content);
// 		curr = curr->next;
// 	}
// 	return (0);
// }