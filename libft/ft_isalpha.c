/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:31:26 by mpons             #+#    #+#             */
/*   Updated: 2021/11/03 12:57:01 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (c);
	else
		return (0);
}
/*
int	main(void)
{
	int i;

	i = isalpha(97);	
	printf("%d", i);
	return (0);
}


Test any character for which
 
  isupper(3) ||  islower(3)  = true;
 
 the value of the argument must be representable as an
 unsigned char
 or EOF
 

if (char test = true)
	return (non-zero);
else

return (0) 
*/
