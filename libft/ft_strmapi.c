/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:46:11 by pgros             #+#    #+#             */
/*   Updated: 2022/05/09 14:14:47 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*new_s;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_s = malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (new_s);
	i = 0;
	while (s[i] != '\0')
	{
		new_s[i] = f(i, (char)s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
/*
#include <stdio.h>
char	ft_toupper_test(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	i = (size_t)i;
	return (c);
}

int	main(void)
{
	char	*str = "Hello les Amis 55!";
	char	*new_str;

	new_str = ft_strmapi(str, &ft_toupper_test);
	printf("%s\n", new_str);
	free(new_str);	
	return (0);
}
*/