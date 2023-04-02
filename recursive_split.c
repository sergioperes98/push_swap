/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:07:15 by svilaca-          #+#    #+#             */
/*   Updated: 2023/04/02 18:23:28 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	*malloc(size_t size)
// {
// 	(void)size;
// 	return (NULL);
// }

char	**ft_split(char const *s, char c)
{
	char		**arr;
	static int	wd;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == c)
		s++;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (++wd && *s == '\0')
	{
		arr = malloc(wd * sizeof(char *));
		if (arr)
			arr[--wd] = NULL;
		return (arr);
	}
	arr = ft_split(s + i, c);
	if (!arr)
		return (NULL);
	arr[--wd] = malloc((i + 1) * sizeof(char));
	arr[wd][i] = '\0';
	while (i-- > 0)
		arr[wd][i] = *(s + i);
	return (arr);
}

// int	main(void)
// {
// 	char	**arr;
// 	char	*str = "  Ola42 Sou Eu ";

// 	arr = ft_split(str, ' ');
// 	while (arr && *arr)
// 		printf("%s\n", *arr++);
// 	return (0);
// }