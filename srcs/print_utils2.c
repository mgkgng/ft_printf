/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:33:55 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 18:46:08 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int upper)
{
	char			set[17];

	if (!upper)
		ft_strlcpy(set, "0123456789abcdef", 17);
	else
		ft_strlcpy(set, "0123456789ABCDEF", 17);
	if (n > 15)
		ft_puthex(n / 16, upper);
	ft_putchar(set[n % 16]);
	return (ft_nbrlen(n, 16));
}

int	ft_ptrlen(unsigned long long n)
{
	int	len;

	len = 3;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_putptr(unsigned long long n, int on)
{
	char	set[17];
	
	ft_strlcpy(set, "0123456789abcdef", 17);
	if (on)
		ft_putstr("0x");
	if (n > 15)
		ft_putptr(n / 16, 0);
	ft_putchar(set[n % 16]);
	return (ft_ptrlen(n));
}
