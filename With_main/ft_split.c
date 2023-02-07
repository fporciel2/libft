/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:45:26 by fporciel          #+#    #+#             */
/*   Updated: 2023/01/24 07:36:50 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

long int	ft_numc(const char *s, char c)
{
	long int	i;
	long int	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c)
			i++;
		if (s[i] == c)
			j++;
	}
	return (j);
}

long int	ft_sbstrlen(const char *s, long int start, char c)
{
	if ((s == NULL) || (start >= ft_strlen(s)))
		return (NULL);
	if ((s[start] == c) && (s[start] != 0))
		while ((s[start] == c) && (s[start] != 0))
			start++;
	else
		while ((s[start] != c) && (s[start] != 0))
			start++;
	if (start == 0)
		return (NULL);
	else
		return (start);
}

char	**ft_spltd(char **spltd, const char *s, char c, long int start)
{
	long int	sbstrlen;
	long int	sbstr;
	long int	i;
	char		*substr;
	
	i = 0;
	if ((spltd == NULL) || (s == NULL))
		return (NULL);
	while (spltd[i] != NULL)
	{
		sbstrlen = ft_sbstrlen(s, start, c);
		start = start + sbstrlen;
		substr = ft_substr(c, start, sbstrlen);
		sbstr = (char *)malloc(sizeof((ft_strtrim(substr, c))));
		if (sbstr == NULL)
			return (NULL);
		else
			sbstr = ft_strdup(ft_strtrim(ft_substr(s, start, sbstrlen), c));
		spltd[i] = sbstr;
		free(sbstr);
		i++;
	}
	return (spltd);
}

char	**ft_split(char const *s, char c)
{
	char		**spltd;
	long int	start;
	long int	sbstrlen;
	long int	sbstr;
	char		*substr;

	if ((ft_numc(s, c) == NULL) || (ft_numc(s, c) == 0))
		return (NULL);
	start = 0;
	spltd = (char **)malloc(sizeof(ft_numc(s, c) + 1));
	if (spltd == NULL)
		return (NULL);
	spltd[ft_numc(s, c) + 1] = NULL;
	if (ft_spltd == NULL)
		return (NULL);
	else
		return (ft_spltd);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(s));
	while (s[i])
	{
		((char *)str)[i] = s[i];
		i++;
	}
	((char *)str)[i] = s[i];
	return ((char *)str);
}

static int	ft_trmchk(const char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_incr(size_t  beg, const char *s1, const char *set)
{
	while ((s1[beg]) && (ft_trmchk(s1[beg], set)))
		beg++;
	return (beg);
}

size_t	ft_decr(size_t end, const char *s1, const char *set)
{
	while ((s1[end]) && (ft_trmchk(s1[end], set)))
		end--;
	return (end);
}

char	*ft_trim(char const *s1, char *trimmed, size_t i, size_t beg, size_t end)
{
	if ((s1 == 0) || (trimmed == 0))
		return (NULL);
	while (beg <= end)
		{
			trimmed[i] = s1[beg];
			beg++;
			i++;
		}
	trimmed[i] = 0;
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	beg;
	size_t	end;
	size_t	i;

	if ((s1 == NULL) || (set == NULL) || (s1 == 0))
		return (NULL);
	beg = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	beg = ft_incr(beg, s1, set);
	end = ft_decr(end, s1, set);
	if ((end - beg + 1) <= 0)
		return (ft_strdup(""));
	trimmed = (char *)malloc(sizeof(char)*(end - beg + 1));
	if (trimmed == NULL)
		return (NULL);
	if ((ft_trim(s1, trimmed, i, beg, end)) == NULL)
		return (NULL);
	else
		return (ft_strdup(ft_trim(s1, trimmed, i, beg, end)));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if ((s == NULL) || (*s == 0) || (len == 0))
		return (NULL);
	substr = (char *)malloc(sizeof(char)*(len + 1));
	if ((substr == NULL) || (start >= ft_strlen(s)))
		return (NULL);
	i = start;
	j = 0;
	while ((s[i]) && (j < len))
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = 0;
	return (substr);
}

int	main()
{
	char	char1 = ".";
	char	char2 = "";
	char	char3 = NULL;
	char	*str1 = "";
	char	*str2 = NULL;
	char	*str3 = " hello.world. how.are . you.";
  	char	*str4 = "............";
	char	*str5 = "	
}
