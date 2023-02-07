#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

//Warning! The following main-test function is incorrect: use it only to show the real output

int main(void)
{
    // Proper usage:
    char s1[] = "   Hello, World!   ";
    char set[] = " ";
    char *trimmed = ft_strtrim(s1, set);
    printf("Proper usage: '%s' (Expected output: 'Hello, World!')\n", trimmed);
    free(trimmed);

    // Improper usage: passing NULL as the first argument
    trimmed = ft_strtrim(NULL, set);
    printf("Improper usage: passing NULL as first argument: '%p' (Expected output: NULL)\n", (void *)trimmed);

    // Proper usage for a different purpose:
    // Using the ft_strtrim to remove characters other than whitespaces from the string
    char s2[] = "Hello, World!123";
    char set2[] = "123";
    char *trimmed2 = ft_strtrim(s2, set2);
    printf("Proper usage for different purpose: '%s' (Expected output: 'Hello, World!')\n", trimmed2);
    free(trimmed2);

    // Improper usage for specific purposes:
    // Removing whitespaces and non-whitespace characters using ft_strtrim
    char s3[] = "   Hello, World!   ";
    char set3[] = " H,W! ";
    char *trimmed3 = ft_strtrim(s3, set3);
    printf("Improper usage for specific purpose: '%s' (Expected output: '')\n", trimmed3);
    free(trimmed3);

    // Proper usage for a different purpose:
    // Using ft_strtrim to remove all punctuation from a string
    char s4[] = "Hello, World! How are you doing?";
    char set4[] = ",.!?";
    char *trimmed4 = ft_strtrim(s4, set4);
    printf("Proper usage for different purpose: '%s' (Expected output: 'Hello World How are you doing')\n", trimmed4);
    free(trimmed4);

    // Proper usage for a different purpose:
    // Using ft_strtrim to remove all digits from a string
    char s5[] = "My lucky number is 42";
    char set5[] = "0123456789";
    char *trimmed5 = ft_strtrim(s5, set5);
    printf("Proper usage for different purpose: '%s' (Expected output: 'My lucky number is ')\n", trimmed5);
    free(trimmed5);

    // Proper usage for a different purpose:
    // Using ft_strtrim to remove all uppercase letters from a string
    char s6[] = "This IS a MiXed CaSe SeNTENCE";
    char set6[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *trimmed6 = ft_strtrim(s6, set6);
    printf("Proper usage for different purpose: '%s' (Expected output: 'his a ixedaseentence')\n", trimmed6);
    free(trimmed6);

    // Improper usage: passing NULL as the second argument
    char s7[] = "   Hello, World!   ";
    char *trimmed7 = ft_strtrim(s7, NULL);
    printf("Improper usage: passing NULL as second argument: '%p' (Expected output: NULL)\n", (void *)trimmed7);

    // Improper usage: passing an empty set
    char s8[] = "   Hello, World!   ";
    char set8[] = "";
    char *trimmed8 = ft_strtrim(s8, set8);
    printf("Improper usage: passing an empty set: '%s' (Expected output: '   Hello, World!   ')\n", trimmed8);
    free(trimmed8);

    // Improper usage: passing a set with only whitespaces
    char s9[] = "   Hello, World!   ";
    char set9[] = " ";
    char *trimmed9 = ft_strtrim(s9, set9);
    printf("Improper usage: passing a set with only whitespaces: '%s' (Expected output: 'Hello, World!')\n", trimmed9);
    free(trimmed9);
    
    // Improper usage: passing an empty string
    char s10[] = "";
    char set10[] = " ";
    char *trimmed10 = ft_strtrim(s10, set10);
    printf("Improper usage: passing an empty string: '%s' (Expected output: '')\n", trimmed10);
    free(trimmed10);

    return 0;
}
