/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:57:50 by olobresh          #+#    #+#             */
/*   Updated: 2023/11/24 11:19:44 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static	char	*ft_get_word(const char *s, int *ix, char c)
{
	char	*w;
	int		len;
	int		st;

	st = *ix;
	while (s[*ix] && s[*ix] != c)
		(*ix)++;
	len = *ix - st;
	w = ft_calloc(len + 1, sizeof(char));
	if (!w)
		return (NULL);
	ft_strlcpy(w, s + st, len + 1);
	return (w);
}

static char	**ft_free_split(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	**ft_split_arr(const char *s, char c, char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			arr[j] = ft_get_word(s, &i, c);
			if (!arr[j])
				return (ft_free_split(arr, j));
			j++;
		}
		else
			i++;
	}
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (ft_calloc(ft_word_count(s, c) + 1, sizeof(char *)));
	if (!arr)
		return (NULL);
	return (ft_split_arr(s, c, arr));
}
/*
#include <stdio.h>

int main(void)
{
    char **result;
    int i;

    printf("Test with empty string:\n");
    result = ft_split("", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with delimiters at the beginning and end:\n");
    result = ft_split(",alpha,beta,", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with consecutive delimiters:\n");
    result = ft_split("apple,,orange", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with no delimiters:\n");
    result = ft_split("fruitbasket", ',');
    i = 0;
    while (result && result[i])
    {
        printf("'%s'\n", result[i]);
        free(result[i]);
        i++;
    }
    if (result)
        free(result);

    printf("\nTest with NULL string:\n");
    result = ft_split(NULL, ',');
    if (result)
    {
        i = 0;
        while (result[i])
        {
            printf("'%s'\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
    {
        printf("NULL\n");
    }

    return (0);
}
*/
