/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 16:54:20 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/28 15:42:26 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		modifhhu(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp >= -238 && tmp <= 255)
		ret = ft_putnbr(tmp);
	else if (tmp > 255)
		ret = ft_putnbr(-256 + tmp);
	else
		ret = ft_putnbr(237 + (tmp % 239));
	return (ret);
}

int		modifhho(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp > 255)
		ret = ft_putstring(ft_base("01234567", tmp % 256));
	else
		ret = ft_putstring(ft_base("01234567", tmp));
	return (ret);
}

int		modifhhx(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp > 255)
		ret = ft_putstring(ft_base("0123456789abcdef", tmp % 256));
	else
		ret = ft_putstring(ft_base("0123456789abcdef", tmp));
	return (ret);
}

int		modifhh_x(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp > 255)
		ret = ft_putstring(ft_base("0123456789ABCDEF", tmp % 256));
	else
		ret = ft_putstring(ft_base("0123456789ABCDEF", tmp));
	return (ret);
}

int		ft_modifier(va_list ap, char *str, int *i)
{
	int		ret;

	ret = 0;
	if (str[*i] == 'l')
		ret = modifl(ap, str, i);
	else if (str[*i] == 'h')
		ret = modifh(ap, str, i, ret);
	else if (str[*i] == 'j')
		ret = modifj(ap, str, i);
	else if (str[*i] == 'z')
		ret = modifz(ap, str, i);
	else if (ft_isdigit(str[*i]))
	{
		ret = modifspace(ap, str, i);
		*i = *i - 1;
	}
	return (ret);
}
