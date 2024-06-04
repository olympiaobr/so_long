/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:00:34 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/24 10:23:52 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_l;
	t_list	*new_n;

	if (!lst || !f)
		return (NULL);
	mapped_l = NULL;
	while (lst)
	{
		new_n = ft_lstnew(f(lst->content));
		if (!new_n)
		{
			ft_lstclear(&mapped_l, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_l, new_n);
		lst = lst->next;
	}
	return (mapped_l);
}
