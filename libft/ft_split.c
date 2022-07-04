/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:38:29 by pgros             #+#    #+#             */
/*   Updated: 2022/05/06 20:35:56 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_wdstart(char const *s, char c, unsigned int i)
{
	if (i == 0)
	{
		if (s[i] != c)
			return (1);
	}
	else
	{
		if (s[i] != c && s[i - 1] == c)
			return (1);
	}
	return (0);
}

static	size_t	ft_nb_wd(char const *s, char c)
{
	size_t			nb;
	unsigned int	i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_is_wdstart(s, c, i))
			nb++;
		i++;
	}
	return (nb);
}

static	size_t	ft_wdlen(const char *s, char c, unsigned int i)
{
	int	j;

	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
		j++;
	return (j);
}

static	char	**ft_freeall(char **tab, int i_tab)
{
	while (i_tab >= 0)
	{
		free(tab[i_tab]);
		i_tab--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**string_tab;
	size_t			nb_wd;
	size_t			i_tab;
	unsigned int	i_str;

	if (!s)
		return (NULL);
	nb_wd = ft_nb_wd(s, c);
	string_tab = malloc((nb_wd + 1) * sizeof(char *));
	if (!string_tab)
		return (string_tab);
	i_tab = 0;
	i_str = 0;
	while (s[i_str] != '\0' && i_tab < nb_wd)
	{
		if (ft_is_wdstart(s, c, i_str))
		{
			string_tab[i_tab++] = ft_substr(s, i_str, ft_wdlen(s, c, i_str));
			if (!string_tab[i_tab - 1])
				return (ft_freeall(string_tab, i_tab - 1));
		}
		i_str++;
	}
	string_tab[i_tab] = NULL;
	return (string_tab);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = "  Salut les  jambons !@";
	char	**tab;
	int		i;

	// s = NULL;
	printf("%s\n\n", s);
	tab = ft_split(s, ' ');
	if (!tab)
		printf("null\n");
	else
	{
		i = 0;
		while (tab[i] != 0)
		{
			printf("|%s|\n", tab[i]);
			i++;
		}
	}
	return (0);
}
*/