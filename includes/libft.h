/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:41:02 by min-kang          #+#    #+#             */
/*   Updated: 2022/12/22 18:58:00 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(char *s, char c);
int		ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
