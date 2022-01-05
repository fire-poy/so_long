/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:05:02 by mpons             #+#    #+#             */
/*   Updated: 2021/11/05 17:15:10 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	char	*d;
	char	*s;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (s < d)
		while (++i <= len)
			d[len - i] = s[len - i];
	else
		while (len-- > 0)
			*(d++) = *(s++);
	return (dst);
}
/*
int	main(void)
{
	char s[] = "holasp";
	char d[] = "chau";
	printf("avant \n dest %s source %s \n", d , s);
	ft_memmove(d, s, 6);
	printf("apres \n dest %s source %s", d , s);
	return(0);
}
*/
