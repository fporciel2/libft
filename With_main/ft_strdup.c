#include <stdio.h>
#include <stdlib.h>

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

int main() {
    char *original = "Hello, World!";
    char *duplicate = ft_strdup(original);
    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);
    free(duplicate);
    return (0);
}
