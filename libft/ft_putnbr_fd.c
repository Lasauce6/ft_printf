/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 00:17:14 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/19 14:24:04 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_neg(long *nb, int *count, int fd)
{
	int	tmp;

	tmp = 0;
	if (*nb < 0)
	{
		tmp = write(fd, "-", 1);
		if (tmp == -1)
			return (0);
		*count += tmp;
		*nb *= -1;
	}
	return (1);
}

int	ft_putnbr_fd(long n, int fd)
{
	long	nb;
	int		count;
	char	c;
	int		tmp;

	count = 0;
	nb = n;
	if (!check_neg(&nb, &count, fd))
		return (-1);
	if (nb > 9)
	{
		count += ft_putnbr_fd(nb / 10, fd);
		count += ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		c = '0' + (nb % 10);
		tmp = write(fd, &c, 1);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	return (count);
}
