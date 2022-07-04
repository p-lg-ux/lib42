/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgros <pgros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:05:24 by pgros             #+#    #+#             */
/*   Updated: 2022/05/05 11:18:29 by pgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char) c;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s;
	char str[10] = "hellol";
	printf("%s\n",str);
	str[3] = 200;
	s = NULL;
	printf("%s\n",str);
	printf("%s\n",strrchr(str, 0));
	printf("%s\n",ft_strrchr(str, 0));
	printf("%s\n",strrchr(str, 'l'));
	printf("%s\n",ft_strrchr(str, 'l'));
	printf("%s\n",strrchr(str, 'h'));
	printf("%s\n",ft_strrchr(str, 'h'));
	printf("%p\n",strrchr(str, 'a'));
	printf("%p\n",ft_strrchr(str, 'a'));
	printf("%s\n",strrchr(s, 0));
	printf("%s\n",ft_strrchr(s, 0));
	
	//printf("%s\n",strchr(s, 'e'));
	//printf("%s\n",ft_strchr(s, 'e'));
	return (0);	
}
*/