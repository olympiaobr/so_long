/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:44:52 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/23 17:04:50 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
void    print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int     main(void)
{
   	t_list  *elem1;
	t_list  *elem2;
	t_list  *elem3;

	elem1 = malloc(sizeof(t_list));
    	elem2 = malloc(sizeof(t_list));
    	elem3 = malloc(sizeof(t_list));
    	elem1->content = "Element 1";
    	elem1->next = elem2;
    	elem2->content = "Element 2";
    	elem2->next = elem3;
    	elem3->content = "Element 3";
    	elem3->next = NULL;

    	ft_lstiter(elem1, print_content);

    	free(elem1);
    	free(elem2);
    	free(elem3);

    	return (0);
}
*/
