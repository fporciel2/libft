/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:24:12 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/09 17:48:20 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strmchck(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;

	if (*s == 0)
		return (0);
	i = 0;
	while ((s[i]) && (f(i, s[i])))
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	slen;
	char			*strmapi;
	unsigned int	j;

	if ((s == NULL) || (*f == NULL))
		return (NULL);
	slen = ft_strmchck(s, f);
	strmapi = (char *)malloc(sizeof(char) * (slen + 1));
	if (strmapi == NULL)
		return (NULL);
	j = 0;
	while (s[j])
	{
		strmapi[j] = (*f)(j, s[j]);
		j++;
	}
	strmapi[j] = 0;
	return (strmapi);
}
