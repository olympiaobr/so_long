/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:20:04 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 17:29:22 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = new;
}
/*
#include <stdio.h>

void print_list(t_list *list)
{
    while (list)
    {
        printf("%s -> ", (char *)list->content);
        list = list->next;
    }
    printf("NULL\n");
}

void free_list(t_list *list)
{
    t_list *temp;

    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

#include <stdlib.h>
int main(void)
{
    t_list *list = NULL;

    ft_lstadd_back(&list, ft_lstnew("Node 1"));
    ft_lstadd_back(&list, ft_lstnew("Node 2"));
    ft_lstadd_back(&list, ft_lstnew("Node 3"));

    print_list(list);

    free_list(list);

    return 0;
}
*/
