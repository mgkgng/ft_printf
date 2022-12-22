/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:42:43 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 18:56:25 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	plus_space(int flag)
{
	char	c;

	if (!(flag % PLUS_FLAG))
		c = '+';
	else
		c = ' ';
	return (ft_putchar(c));
}

int	instruction_d(long long int n, t_spec spec, int *ins)
{
	int	len;
	int	nbr_len;
	int	i;

	len = 0;
	nbr_len = print_nbr_len(n, spec, 10);
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += print_nbr(&n, spec);
		else if (ins[i] == 2)
			len += width_nbr(spec, &n, nbr_len);
		else if (ins[i] == 3)
			len += plus_space(spec.flag);
	}
	return (len);
}

int	print_d(int n, t_spec spec)
{
	if (spec.flag % MINUS_FLAG)
		return (instruction_d(n, spec, (int [3]) {2, 2, 1}));
	if (n >= 0 && !(spec.flag % PLUS_FLAG && spec.flag % SPACE_FLAG))
		return (instruction_d(n, spec, (int [4]) {3, 3, 1, 2}));
	return (instruction_d(n, spec, (int [3]) {2, 1, 2}));
}
