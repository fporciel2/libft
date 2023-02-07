#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

int main() {
    // Test 1: Proper usage
    char *s = "Hello World";
    char *substring = ft_substr(s, 0, 5);
    printf("Test 1: The substring is: %s\n", substring);
    free(substring);

    // Test 2: Proper usage
    s = "Hello World";
    substring = ft_substr(s, 6, 5);
    printf("Test 2: The substring is: %s\n", substring);
    free(substring);

    // Test 3: Improper usage - start index is greater than length of the string
    s = "Hello World";
    substring = ft_substr(s, 15, 5);
    if(substring == NULL)
        printf("Test 3: start index is greater than length of the string\n");
    else
        printf("Test 3: The substring is: %s\n", substring);
    free(substring);

    // Test 4: Improper usage - input string is NULL
    substring = ft_substr(NULL, 0, 5);
    if(substring == NULL)
        printf("Test 4: input string is NULL\n");
    else
        printf("Test 4: The substring is: %s\n", substring);
    free(substring);

    // Test 5: Proper usage but for a purpose other than that for which it is needed
    s = "Hello World";
    substring = ft_substr(s, 0, 15);
    printf("Test 5: The substring is: %s\n", substring);
    free(substring);

    // Test 6: Improper usage for specific purposes - len = 0
    s = "Hello World";
    substring = ft_substr(s, 0, 0);
    printf("Test 6: The substring is: %s\n", substring);
    free(substring);

    // Test 7: Improper usage for specific purposes - input string is empty
    s = "";
    substring = ft_substr(s, 0, 2);
    printf("Test 7: The substring is: %s\n", substring);
    free(substring);

    return 0;
}
