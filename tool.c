/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemur <atemur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:07:41 by atemur            #+#    #+#             */
/*   Updated: 2023/08/01 19:51:44 by atemur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	ft_putnbr_base(size_t n, int *base)
{
	size_t		base_len;
	static int	counter;

	counter = 1;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
		counter++;
	}
	ft_putchar(base[n % base_len]);
	return (counter);
}
