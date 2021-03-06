/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 18:11:36 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/28 15:44:15 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(char *str, ...);
int		ft_option(va_list ap, char *str, int i);
int		ft_flag(va_list ap, char *str, int *i, char *option);
int		ft_modifier(va_list ap, char *str, int *i);
char	*cast_to_wc(wchar_t c);
char	*cast_to_ws(wchar_t *s);
int		print_c(va_list ap);
int		print_s(va_list ap);
int		print_d(va_list ap);
int		modifhhd(va_list ap);
int		modifhh_x(va_list ap);
int		modifhhx(va_list ap);
int		modifhho(va_list ap);
int		modifhhu(va_list ap);
int		modifh(va_list ap, char *str, int *i, int ret);
int		modifspace(va_list ap, char *str, int *i);
int		modifll(va_list ap, char *str, int *i);
int		modifl(va_list ap, char *str, int *i);
int		modifj(va_list ap, char *str, int *i);
int		modifz(va_list ap, char *str, int *i);

#endif
