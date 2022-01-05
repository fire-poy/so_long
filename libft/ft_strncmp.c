/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:41:32 by mpons             #+#    #+#             */
/*   Updated: 2021/11/05 11:49:47 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char			str1[] = "holz";
	char			str2[] = "hola ";
	unsigned int	j;

	j = 4;
	printf("%d \n", strncmp(str1, str2, j));
	printf("%d \n", ft_strncmp(str1, str2, j));
	return (0);
}
*/
