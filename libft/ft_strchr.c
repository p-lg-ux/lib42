/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:10:30 by pgros             #+#    #+#             */
/*   Updated: 2022/05/05 11:20:07 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	//char *s;
	char str[10] = "hellol";
	printf("%s\n",str);
	str[3] = 200;
	//s = NULL;
	printf("%s\n",str);
	printf("%s\n",strchr(str, 0));
	printf("%s\n",ft_strchr(str, 0));
	printf("%s\n",strchr(str, 'l'));
	printf("%s\n",ft_strchr(str, 'l'));
	printf("%s\n",strchr(str, 200));
	printf("%s\n",ft_strchr(str, 200));
	printf("%p\n",strchr(str, 'a'));
	printf("%p\n",ft_strchr(str, 'a'));
	//printf("%s\n",ft_strchr(s, 0));
	//printf("%s\n",strchr(s, 0));
	
	//printf("%s\n",strchr(s, 'e'));
	//printf("%s\n",ft_strchr(s, 'e'));
	return (0);	
}
*/