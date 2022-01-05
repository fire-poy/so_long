/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:26:27 by mpons             #+#    #+#             */
/*   Updated: 2021/11/05 16:46:16 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len-- > 0)
		*str++ = (unsigned char)c;
	return (b);
}
/*
	writes len bytes
	   	of value c
		unsigned char string b

return first argument

	writes 3 bytes
	   	of value 5 (converted to unsigned char)
	   to the	string b
return string b
*/
