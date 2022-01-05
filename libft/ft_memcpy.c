/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:31:58 by mpons             #+#    #+#             */
/*   Updated: 2021/11/05 17:14:11 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!dst && !src)
		return (NULL);
	s = (char *) src;
	d = (char *) dst;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
/*
int	main(void)
{
	char d[] = "chau";
	char s[] = "holasp";
	printf("avant \n dest %s source %s \n", d , s);
	ft_memcpy(d, s, 6);
	printf("apres \n dest %s source %s", d , s);
	return(0);
}
*/
