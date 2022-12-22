/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:45:57 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 18:56:42 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printstr(char *s, int precis)
{
	int	i;

	if (precis == -1)
		precis = ft_strlen(s);
	i = 0;
	while (s[i] && i < precis)
		ft_putchar(s[i++]);
	return (i);
}

int	instruction_s(char *s, t_spec spec, int *ins)
{
	int	len;
	int	str_len;
	int	i;

	len = 0;
	str_len = ft_strlen(s);
	if (spec.precis != -1 && str_len > spec.precis)
		str_len = spec.precis;
	i = -1;
	while (ins[++i])
	{
		if (ins[i] == 1)
			len += ft_printstr(s, spec.precis);
		if (ins[i] == 2)
			len += print_width(spec.width, str_len, ' ');
	}
	return (len);
}

int	print_s(char *s, t_spec spec)
{
	char	null_str[7];

	ft_strlcpy(null_str, "(null)", 7);
	if (!s)
		s = null_str;
	if (!(spec.flag % MINUS_FLAG))
		return (instruction_s(s, spec, (int [3]) {2, 1, 2}));
	return (instruction_s(s, spec, (int [3]) {2, 2, 1}));
}
