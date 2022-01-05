/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 22:53:35 by mpons             #+#    #+#             */
/*   Updated: 2021/12/27 19:26:29 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_words(const char *s, char c)
{	
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (c == '\0')
		return (1);
	while (s[i])
	{	
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (word);
		word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

void	ft_w_copy(char **tab, const char *s, char c)
{	
	int	i;
	int	j;
	int	debut;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{	
		while (s[i] && s[i] == c)
			i++;
		debut = i;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		len = i - debut;
		tab[j] = malloc((len + 1) * sizeof(char));
		if (!tab[j])
			free (tab[j]);
		ft_strlcpy(tab[j], s + debut, len + 1);
		j++;
	}
	tab[j] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		ac;

	if (!s)
		return (NULL);
	ac = ft_words(s, c);
	tab = malloc((ac + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	ft_w_copy(tab, s, c);
	tab[ac] = NULL;
	return (tab);
}
/*
	printf("words = %d\n", ac);
int	main(int ac, char **av)
{
	char	sep;
	char	**split;
	int		i;

	(void)ac;
	i = 0;
	sep = ' ';
	split = ft_split(av[1], sep);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	free(split);
	return (0);
}
*/
