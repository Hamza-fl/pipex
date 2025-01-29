/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:56:55 by ilarhrib          #+#    #+#             */
/*   Updated: 2024/11/03 14:34:56 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void    dlt(void    *content)
// {
//     free(content);
// }

// int main()
// {
//     void (*del)(void*);
//     del = &dlt;
//     t_list  *list;
//     char *str = ft_strdup("sphynx");
//     list = ft_lstnew(str);
//     printf("%s\n", list->content);
//     ft_lstdelone(list, del);
//     printf("%s\n", list->content);
//     return 0;
// }