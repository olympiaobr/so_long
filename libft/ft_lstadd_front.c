/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:29:09 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 13:50:19 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list	*head;
	t_list	*node;
	int	i;

    	head = NULL;
    	i = 0;
    	while (i < 3)
    	{
		node = (t_list *)malloc(sizeof(t_list));
	        if (node == NULL)
        	{
            		return (1);
        	}
        	node->content = (void *)(size_t)i;
        	ft_lstadd_front(&head, node);
        	i++;
    	}	
    	node = head;
    	while (node != NULL)
   	{
        	printf("Node content: %zu\n", (size_t)node->content);
        	node = node->next;
    	}	
    	return (0);
}
*/
