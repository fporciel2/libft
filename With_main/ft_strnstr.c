/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:43 by fporciel          #+#    #+#             */
/*   Updated: 2023/01/20 16:53:44 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	if ((ft_strlen((const char *)needle)
		> ft_strlen((const char *)haystack)) || (len <= 0))
		return (NULL);
	while (len - (ft_strlen((const char *)needle) + (i - 1)) > 0)
	{
		while (needle[j] != 0)
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				i++;
				j = 0;
			}
		}
		if (needle[j] == 0)
			return ((char *)haystack + (i - ft_strlen((const char *)needle)));
	}
	return (NULL);
}

int main() {
    const char haystack[20] = "Hello, World!";
    const char needle[6] = "World";
    char       *result;

    // Proper usage: find the first occurrence of "World" in "Hello, World!"
    result = ft_strnstr(haystack, needle, ft_strlen(haystack));
    if (result) {
        printf("'%s' found in '%s'\n", needle, haystack);
    } else {
        printf("'%s' not found in '%s'\n", needle, haystack);
    }
    // Output: "'World' found in 'Hello, World!'"

    // Misuse: search for a needle longer than the haystack
    result = ft_strnstr(haystack, "Hello, World, How are you?", ft_strlen(haystack));
    if (result) {
        printf("'%s' found in '%s'\n", "Hello, World, How are you?", haystack);
    } else {
        printf("'%s' not found in '%s'\n", "Hello, World, How are you?", haystack);
    }
    // Output: "'Hello, World, How are you?' not found in 'Hello, World!'"

    // Misuse: search for a needle with a maximum length of 0
    result = ft_strnstr(haystack, needle, 0);
    if (result) {
        printf("'%s' found in '%s'\n", needle, haystack);
    } else {
        printf("'%s' not found in '%s'\n", needle, haystack);
    }
    // Output: "'World' not found in 'Hello, World!'"

    // Proper usage: search for a needle in a haystack that contains multiple occurrences
    result = ft_strnstr("Hello, World, World!", "World", 20);
    if (result) {
        printf("'%s' found in '%s'\n", "World", "Hello, World, World!");
    } else {
        printf("'%s' not found in '%s'\n", "World", "Hello, World, World!");
    }
    // Output: "'World' found in 'Hello, World, World!'"

    return 0;
}
