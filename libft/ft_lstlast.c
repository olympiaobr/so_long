/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:08:00 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 13:55:05 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list	*head;
    	t_list	*node1;
   	t_list	*node2;
    	t_list	*last;

    	head = (t_list *)malloc(sizeof(t_list));
    	node1 = (t_list *)malloc(sizeof(t_list));
    	node2 = (t_list *)malloc(sizeof(t_list));
    	if (!head || !node1 || !node2)
    	{
        	free(head);
        	free(node1);
        	free(node2);
        	return (1);
    	}
    	head->content = "First Node";
    	head->next = node1;

    	node1->content = "Second Node";
    	node1->next = node2;

    	node2->content = "Third Node";
    	node2->next = NULL;

    	last = ft_lstlast(head);
    	if (last)
        	printf("Last node content: %s\n", (char *)last->content);
    	free(head);
    	free(node1);
    	free(node2);
   	return (0);
}
*/
