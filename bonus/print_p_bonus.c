/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:41:48 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 18:56:31 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_ptrlen(unsigned long long n, int precis)
{
	int	len;

	len = 3;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	if (len < precis)
		return (precis);
	return (len);
}

int	ft_printptr(unsigned long long n, t_spec spec, int on)
{
	char	set[17];

	ft_strlcpy(set, "0123456789abcdef", 17);
	if (on)
		ft_putstr("0x");
	if (n > 15)
		ft_printptr(n / 16, spec, 0);
	ft_putchar(set[n % 16]);
	return (ft_ptrlen(n, spec.precis));
}

int	instruction_p(unsigned long long n, t_spec spec, int *ins)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_printptr(n, spec, 1);
		if (ins[i] == 2)
			len += print_width(spec.width, ft_ptrlen(n, spec.precis), ' ');
	}
	return (len);
}

int	print_p(unsigned long long n, t_spec spec)
{
	if (!(spec.flag % MINUS_FLAG))
		return (instruction_p(n, spec, (int [3]) {2, 1, 2}));
	return (instruction_p(n, spec, (int [3]) {2, 2, 1}));
}
