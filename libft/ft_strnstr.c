/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:58:29 by mpons             #+#    #+#             */
/*   Updated: 2021/11/05 19:08:56 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	match;
	size_t	longeur;

	i = 0;
	match = 0;
	longeur = ft_strlen(needle);
	if (longeur == 0 || !needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + match] && (i + match) < len
			&& haystack[i + match] == needle[match])
			match++;
		if (match == longeur)
			return ((char *)(haystack + i));
		match = 0;
		i++;
	}
	return (NULL);
}
/*
int    main(void)
{
    char            str1[] = "A";
    char            str2[] = "A";
    unsigned int    j;

    j = 443;
	printf("strlen = %zu\n", ft_strlen(str1));
    printf("%s\n", ft_strnstr(str1, str2, j));
    printf("%s \n", strnstr(str1, str2, j));
    return (0);
}
*/
