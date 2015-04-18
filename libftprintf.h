/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 18:11:36 by basle-qu          #+#    #+#             */
/*   Updated: 2015/03/31 18:46:01 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <limits.h>

int		ft_printf(char *str, ...);
int		ft_option(va_list ap, char *str, int i);
int		ft_flag(va_list ap, char *str, int *i, char *option);
int		ft_modifier(va_list ap, char *str, int *i);
char	*cast_to_wc(wchar_t c);
char	*cast_to_ws(wchar_t *s);
int		printC(va_list ap);
int		printS(va_list ap);

#endif
