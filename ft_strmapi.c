/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:05:08 by fporciel          #+#    #+#             */
/*   Updated: 2023/02/07 08:27:36 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_slen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			slen;
	char			*strmapi;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	slen = ft_slen(s);
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
