/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:31:53 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/03 15:14:14 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	ptr = lst;
	if (!lst || !f)
		return ;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}

// void	upp(void	*content)
// {
// 	char *ptr = (char *)content;
// 	for (int i = 0; ptr[i]; i++)
// 	{
// 		ptr[i] -= 32;
// 	}
// }

// int main()
// {
// 	t_list	*node;
// 	char	*str = ft_strdup("sphynx");
// 	node = ft_lstnew(str);
// 	printf("%s\n", node->content);
// 	void	(*f)(void *);
// 	f = &upp;
// 	ft_lstiter(node, f);
// 	printf("%s\n", node->content);
// 	free(node->content);
// 	free(node);
// 	printf("%s\n", node->content);
// 	return (0);
// }