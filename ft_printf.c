/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:20:13 by rbaticle          #+#    #+#             */
/*   Updated: 2024/10/15 13:22:54 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	putptr(unsigned long p)
{
	int		len;
	char	addr[16];
	int		i;

	len = 0;
	if (!p)
		return (ft_putstr_fd("(nil)", 1));
	len += write(1, "0x", 2);
	i = 0;
	while (p)
	{
		addr[i] = BASE16_L[p % 16];
		p /= 16;
		i++;
	}
	while (i--)
		len += write(1, &addr[i], 1);
	return (len);
}

static int	puthex(unsigned long n, int uppercase)
{
	unsigned int	nb;
	int				count;
	char			c;

	count = 0;
	nb = n;
	if (nb >= 16)
	{
		count += puthex(nb / 16, uppercase);
		count += puthex(nb % 16, uppercase);
	}
	else
	{
		if (uppercase)
			c = BASE16_U[nb % 16];
		else
			c = BASE16_L[nb % 16];
		count += (write(1, &c, 1));
	}
	return (count);
}

static int	handle_percent(const char *str, va_list *valist)
{
	if (!*str)
		return (-1);
	else if (*str == 'c')
		return (ft_putchar_fd((unsigned char) va_arg(*valist, int), 1));
	else if (*str == 's')
		return (ft_putstr_fd(va_arg(*valist, char *), 1));
	else if (*str == 'p')
		return (putptr(va_arg(*valist, unsigned long)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr_fd(va_arg(*valist, int), 1));
	else if (*str == 'u')
		return (ft_putnbr_fd(va_arg(*valist, unsigned int), 1));
	else if (*str == 'x')
		return (puthex(va_arg(*valist, unsigned long), 0));
	else if (*str == 'X')
		return (puthex(va_arg(*valist, unsigned long), 1));
	return (write(1, str, 1));
}

int	ft_printf(const char *str, ...)
{
	int		count;
	size_t	i;
	va_list	valist;

	count = 0;
	if (str)
	{
		va_start(valist, str);
		i = 0;
		while (str[i])
		{
			if (str[i] != '%')
			{
				count += ft_putchar_fd(str[i], 1);
				i++;
			}
			else
			{
				count += handle_percent(&str[i + 1], &valist);
				i += 2;
			}
		}
		va_end(valist);
	}
	return (count);
}
