/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemur <atemur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:06:13 by atemur            #+#    #+#             */
/*   Updated: 2023/08/01 19:48:43 by atemur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	neg_or_pos(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			return (ft_putnbr_base(2147483648, "0123456789" + 1));
		n = -n;
		return (ft_putnbr_base(n, "0123456789", +1));
	}
	return (ft_putnbr_base(n, "0123456789"));
}

int	type_control(va_list list, char *str)
{
	int	len;

	len = 0;
	if (str[1] == 'c')
		len += ft_putchar(va_arg(list, int));
	else if (str[1] == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (str[1] == 'p')
	{
		ft_putstr("Ox");
		len += ft_putnbr_base(va_arg(list, unsigned long), "0123456789abcdef")
			+ 2;
	}
	else if (str[1] == 'i' || str[1] == 'd')
		len += neg_or_pos(va_arg(list, int));
	else if (str[1] == 'u')
		len += ft_putnbr_base(va_arg(list, unsigned int), "0123456789");
	else if (str[1] == 'x')
		len += ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	else if (str[1] == 'X')
		len += ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (str[1] == '%')
		return (ft_putchar('%'));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	lst;

	i = 0;
	len = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += type_control(lst, (char *)&str[i]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	main(void)
{
	ft_printf("%s %c %s", "31", 'a', "abdullah");
}
