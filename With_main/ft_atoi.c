#include <stdio.h>

int	ft_isdigit(int a)
{
	return ((a >= 48) && (a <= 57)); 
}

int	ft_power(int base, int exp)
{
	int	power;

	power = base;
	if ((base == 0) && (exp != 0))
		return (0);
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (base);
	if (exp == 2)
		return (base * base);
	while (exp > 1)
		{
			power = power * base;
			exp--;
		}
	return (power);
}

int	ft_chkatoi(char *nptr)
{
	int	i;
	
	i = 0;
	while (!ft_isdigit((char)nptr[i]) && (nptr[i] != 0))
	{
		if (!(((char)nptr[i] == 43) || ((char)nptr[i] == 45))
			&& !(((char)nptr[i] == 32)
			|| (((char)nptr[i] >= 9) && ((char)nptr[i] <= 13))))
			return (0);
		if (((char)nptr[i] == 45) && (ft_isdigit((char)nptr[i + 1])))
			return (-1);
		if ((((char)nptr[i] == 43) || ((char)nptr[i] == 45))
			&& (!ft_isdigit((char)nptr[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	num;
	int	exp;

	i = 0;
	num = 0;
	j = 0;
	while (!ft_isdigit((char)nptr[i]) && (nptr[i] != 0))
		i++;
	j = i;
	while (ft_isdigit((char)nptr[i]))
		i++;
	exp = ((i - j) - 1);
	while (j < i)
	{
		num = num + (((char)nptr[j] - 48) * ft_power(10, exp));
		exp--;
		j++; 
	}
	return (num * ft_chkatoi((char *)nptr));
}

int	main() 
{
	char	str[] = "123";
	char	str1[] = "  123";
	int 	num = ft_atoi(str);
	int	num1 = ft_atoi(str1);
	char	str2[] = "123abc";
	int	num2 = ft_atoi(str2);
	char	str3[] = "+123";
	int	num3 = ft_atoi(str3);
	char 	str4[] = "-123";
	int	num4 = ft_atoi(str4);
	char	str5[] = "";
	int	num5 = ft_atoi(str5);
	char	str6[] = "    \t\n -abc123";
	int	num6 = ft_atoi(str6);

	printf("The integer value is: %d\n", num);
	printf("The integer value is: %d\n", num1);
	printf("The integer value is: %d\n", num2);
	printf("The integer value is: %d\n", num3);
	printf("The integer value is: %d\n", num4);
	printf("The integer value is: %d\n", num5);
	printf("The integer value is: %d\n", num6);
	return (0);
}
