/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:25:36 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/21 12:52:54 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_n;

	new_n = (t_list *)malloc(sizeof(t_list));
	if (!new_n)
		return (NULL);
	new_n->content = content;
	new_n->next = NULL;
	return (new_n);
}
/*
#include <stdio.h>

int main(void)
{
	t_list	*node;

	int	sample_content = 123;
	node = ft_lstnew((void *)&sample_content);

    	if (node == NULL) 
	{
        printf("Memory allocation failed\n");
        return (1);
	}
	printf("Node content: %d\n", *(int *)node->content);
	free(node);
	return (0);
}
*/
