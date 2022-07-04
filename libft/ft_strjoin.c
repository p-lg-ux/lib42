/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:04:55 by pgros             #+#    #+#             */
/*   Updated: 2022/05/06 11:23:07 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new)
		return (new);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, len_s1 + len_s2 + 1);
	return (new);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "";
	char	*s2 = "";
	char 	*new;

	//s2 = NULL;
	//s1 = NULL;
	new = ft_strjoin(s1, s2);
	if(!new)
		printf("null\n");
	else
		printf("|%s|%s|\n|%s|\n", s1, s2, new);
	free(new);
	return (0);
}
*/