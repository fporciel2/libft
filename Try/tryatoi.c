#include <stdio.h>
#include <stdlib.h>

int	main() 
{
	char	str[] = "123";
	char	str1[] = "  123";
	int 	num = atoi(str);
	int	num1 = atoi(str1);
	char	str2[] = "123abc";
	int	num2 = atoi(str2);
	char	str3[] = "+123";
	int	num3 = atoi(str3);
	char 	str4[] = "-123";
	int	num4 = atoi(str4);
	char	str5[] = "";
	int	num5 = atoi(str5);
	char	str6[] = "    \t\n -abc123";
	int	num6 = atoi(str6);

	printf("The integer value is: %d\n", num);
	printf("The integer value is: %d\n", num1);
	printf("The integer value is: %d\n", num2);
	printf("The integer value is: %d\n", num3);
	printf("The integer value is: %d\n", num4);
	printf("The integer value is: %d\n", num5);
	printf("The integer value is: %d\n", num6);
	return (0);
}
