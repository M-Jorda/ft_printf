/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:57:56 by jjorda            #+#    #+#             */
/*   Updated: 2024/10/27 11:03:11 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_arg(const char str, va_list args, int *count)
{
	if (str == 'c')
		ft_pt_putchar((char) va_arg(args, int), count);
	if (str == 's')
		ft_pt_putstr(va_arg(args, char *), count);
	if (str == 'p')
		ft_pt_putptr(va_arg(args, void *), count);
	if (str == 'x' || str == 'X')
		ft_puthexadecimal((unsigned long) va_arg(args, void *), str, count, 0);
	if (str == 'd' || str == 'i')
		ft_pt_putnbr((long) va_arg(args, int), count);
	if (str == 'u')
		ft_pt_putnbr((long) va_arg(args, unsigned int), count);
	if (str == '%')
		ft_pt_putchar('%', count);
}

/*
* The  strdup()  function returns a pointer to a new string which is a duplicate
* of the string s.  Memory for the new string is obtained with malloc(3), and
* can be freed with free(3).
*/
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *) malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*malloc_str;
	int		i;
	int		count;

	va_start(args, str);
	malloc_str = ft_strdup((char *) str);
	if (!malloc_str)
		return (-1);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_print_arg(str[++i], args, &count);
		else
			ft_pt_putchar(str[i], &count);
		i++;
	}
	free(malloc_str);
	va_end(args);
	return (count);
}

/* int	main(int args, char **argv)
{
	char	*str;

	str = NULL;
	(void) args;
	(void) argv;
	printf("printf: %d\n", printf(" %x ", (unsigned int) LONG_MAX));
	ft_printf("ft_printf: %d", ft_printf(" %x ", (unsigned long) LONG_MAX));
	return (1);
} */
