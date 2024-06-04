/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:07 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 17:28:21 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void delete_content(void *content)
{
	free(content);
}

#include <stdio.h>
int	main()
{
    	t_list *node = malloc(sizeof(t_list));

    	node->content = malloc(10);
    	sprintf(node->content, "Node1");

    	printf("Original content: %s\n", (char *)node->content);

    	ft_lstdelone(node, delete_content);

    	printf("Content after deletion: %s\n", (char *)node->content);

    	return (0);
}
*/
