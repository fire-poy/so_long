/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:28:45 by mpons             #+#    #+#             */
/*   Updated: 2021/11/05 15:25:08 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len_max)
{
	char	*dest;
	size_t	len_s;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len_s = ft_strlen(s + start);
	if (len_s > len_max)
		len_s = len_max;
	dest = malloc ((len_s + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len_s + 1);
	return (dest);
}
