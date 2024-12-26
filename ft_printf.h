/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:41:50 by rbaticle          #+#    #+#             */
/*   Updated: 2024/11/22 11:40:26 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE16_L "0123456789abcdef"
# define BASE16_U "0123456789ABCDEF"
# include <stdarg.h>
# include "libft/libft.h"

# ifdef __unix__
#  define NULL_PTR "(nil)"
# endif
# ifdef __APPLE__
#  define NULL_PTR "0x0"
# endif

int	ft_printf(const char *str, ...);

#endif
