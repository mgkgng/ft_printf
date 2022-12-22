/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:29:38 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 18:56:38 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	instruction_u(unsigned int n, t_spec spec, int *ins)
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
			len += print_unsigned(n, spec);
		else
			len += width_unsigned(spec, nbr_len);
	}
	return (len);
}

int	print_u(unsigned int n, t_spec spec)
{
	if (!(spec.flag % MINUS_FLAG))
		return (instruction_u(n, spec, (int [3]) {2, 1, 2}));
	return (instruction_u(n, spec, (int [3]) {2, 2, 1}));

}
