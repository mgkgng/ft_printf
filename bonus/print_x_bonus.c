/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:44:50 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 18:57:13 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_pow(int nb, int pow)
{
	if (!pow)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

int	ft_printhex(unsigned int n, int precis, int upper)
{
	int				i;
	char			set[17];
	int				len;	

	if (!n && !precis)
		return (0);
	if (!upper)
		ft_strlcpy(set, "0123456789abcdef", 17);
	else
		ft_strlcpy(set, "0123456789ABCDEF", 17);
	len = ft_nbrlen(n, 16);
	i = len;
	while (len < precis)
	{
		ft_putchar('0');
		len++;
	}
	while (i)
	{
		ft_putchar(set[n / ft_pow(16, i - 1)]);
		n %= ft_pow(16, i - 1);
		i--;
	}
	return (len);
}

int	hashtag(int upper)
{
	if (!upper)
		ft_putstr("0x");
	else
		ft_putstr("0X");
	return (2);
}

int	instruction_x(unsigned int n, t_spec spec, int upper, int *ins)
{
	int	len;
	int	nbr_len;
	int	i;

	len = 0;
	nbr_len = print_nbr_len(n, spec, 16);
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_printhex(n, spec.precis, upper);
		else if (ins[i] == 2)
			len += width_hex(spec, n, upper);
		else if (ins[i] == 3)
			len += hashtag(upper);
	}
	return (len);
}

int	print_x(unsigned int n, t_spec spec, int upper)
{
	if ((spec.flag % MINUS_FLAG))
		return (instruction_x(n, spec, upper, (int [3]) {2, 2, 1}));
	if (!(spec.flag % SHARP_FLAG) && n && spec.precis)
		return (instruction_x(n, spec, upper, (int [4]) {3, 3, 1, 2}));
	return (instruction_x(n, spec, upper, (int [3]) {2, 1, 2}));

}
