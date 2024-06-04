/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:09 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 13:42:39 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list	*head;
	t_list	*node;
	int	c;

	head = NULL;
	c = 0;
	while (c < 5)
	{
		node = (t_list *)malloc(sizeof(t_list));
		if (node == NULL)
            		return (1);
        	node->content = NULL;
        	node->next = head;
        	head = node;
       	 	c++;
    	}
    	printf("Size of the list: %d\n", ft_lstsize(head));
   	while (head)
    	{
        	node = head;
        	head = head->next;
        	free(node);
   	}
    	return (0);
}
*/
