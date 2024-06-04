/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:42:35 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 17:34:46 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = t;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
void	delete_content(void *content)
{
	free(content);
}

int main()
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

    	node1->content = malloc(10);
    	node2->content = malloc(10);
    	node3->content = malloc(10);

	node1->content = "Node1";
    	node2->content = "Node2";
    	node3->content = "Node3";

    	node1->next = node2;
    	node2->next = node3;
    	node3->next = NULL;

    	t_list *current = node1;
    	while (current)
    	{
        	printf("%s -> ", (char *)current->content);
        	current = current->next;
    	}
    	printf("NULL\n");

    	ft_lstclear(&node1, delete_content);

    	current = node1;
    	while (current)
    	{
        	printf("%s -> ", (char *)current->content);
        	current = current->next;
    	}
    	printf("NULL\n");
    return (0);
}
*/
