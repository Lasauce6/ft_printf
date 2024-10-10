/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:00:16 by rbaticle          #+#    #+#             */
/*   Updated: 2024/09/27 20:18:05 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (*(const char *)(s2) - *(const char *)(s1));
	i = 0;
	while (*(const char *)(s1 + i) == *(const char *)(s2 + i) && i < n)
		i++;
	if (i != n)
		return (*(const char *)(s2 + i) - *(const char *)(s1 + i));
	return (0);
}
