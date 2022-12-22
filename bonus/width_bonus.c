/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:33:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 17:37:15 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_unsigned(t_spec spec, int nbr_len)
{
	int		len;

	len = 0;
	if (spec.flag % MINUS_FLAG && !(spec.flag % ZERO_FLAG)
		&& spec.precis == -1)
		len += print_width(spec.width, nbr_len, '0');
	else
		len += print_width(spec.width, nbr_len, ' ');
	return (len);
}

int	width_nbr(t_spec spec, long long int *n, int nbr_len)
{
	int		len;

	len = 0;
	if (*n >= 0 && !(spec.flag % PLUS_FLAG && spec.flag % SPACE_FLAG))
		spec.width--;
	if (spec.flag % MINUS_FLAG && !(spec.flag % ZERO_FLAG)
		&& spec.precis == -1)
	{
		if (*n >= 0 && !(spec.flag % PLUS_FLAG && spec.flag % SPACE_FLAG))
			len += plus_space(spec.flag);
		if (*n < 0)
		{
			len += ft_putchar('-');
			*n *= -1;
		}
		len += print_width(spec.width, nbr_len, '0');
	}
	else
	{
		len += print_width(spec.width, nbr_len, ' ');
		if (*n >= 0 && !(spec.flag % PLUS_FLAG && spec.flag % SPACE_FLAG))
			len += plus_space(spec.flag);
	}
	return (len);
}

int	width_hex(t_spec spec, unsigned int n, int upper)
{
	int		len;
	int		nbr_len;

	len = 0;
	nbr_len = print_nbr_len(n, spec, 16);
	if (!(spec.flag % SHARP_FLAG) && n && spec.precis)
		spec.width -= 2;
	if (spec.flag % MINUS_FLAG && !(spec.flag % ZERO_FLAG)
		&& spec.precis == -1)
	{
		if (!(spec.flag % SHARP_FLAG) && n && spec.precis)
			len += hashtag(upper);
		len += print_width(spec.width, nbr_len, '0');
	}
	else
	{
		len += print_width(spec.width, nbr_len, ' ');
		if (spec.flag % MINUS_FLAG && !(spec.flag % SHARP_FLAG) && n && spec.precis)
			len += hashtag(upper);
	}
	return (len);
}

int	print_width(int width, int len, char c)
{
	int	i;

	if (len >= width)
		return (0);
	i = -1;
	while (++i < width - len)
		ft_putchar(c);
	return (i);
}
