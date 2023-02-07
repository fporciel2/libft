#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;

	if ((s1 == NULL) || (s2 == NULL) || (*s2 == 0)
		|| ((*s1 == 0) && (*s2 == 0)))
		return (NULL);
	strjoin = (char *)malloc(sizeof(char)*(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strjoin == NULL)
		return (NULL);
	strjoin = ft_strcpy(strjoin, s1);
	strjoin = ft_strcat(strjoin, s2);
	return (strjoin);
}

void test_proper_usage() {
    char* result = ft_strjoin("Hello, ", "world!");
    printf("Expected output: Hello, world!\n");
    printf("Output: %s\n", result);
    free(result);
}

void test_invalid_input() {
    char* result = ft_strjoin(NULL, "world!");
    printf("Expected output: (null)\n");
    printf("Output: %s\n", result);
}

void test_unintended_usage() {
    char* result = ft_strjoin("Hello, ", "world!");
    result[3] = '\0';
    printf("Expected output: Hel\n");
    printf("Output: %s\n", result);
    free(result);
}

void test_specific_invalid_usage() {
    char* result = ft_strjoin("Hello, ", NULL);
    printf("Expected output: (null)\n");
    printf("Output: %s\n", result);
}

int main() {
    test_proper_usage();
    test_invalid_input();
    test_unintended_usage();
    test_specific_invalid_usage();
    return 0;
}
