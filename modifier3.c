/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 15:26:16 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/28 15:42:32 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		modifj(va_list ap, char *str, int *i)
{
	int		ret;

	ret = 0;
	if (str[*i + 1] == 'u')
		ret = ft_putulnbr(va_arg(ap, unsigned long int));
	else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
		ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
	else if (str[*i + 1] == 'x')
		ret = ft_putstring(ft_base("0123456789abcdef",
							va_arg(ap, long int)));
	else if (str[*i + 1] == 'X')
		ret = ft_putstring(ft_base("0123456789ABCDEF",
							va_arg(ap, long int)));
	else
		ret = ft_putlnbr(va_arg(ap, long int));
	return (ret);
}

int		modifz(va_list ap, char *str, int *i)
{
	int		ret;

	ret = 0;
	if (str[*i + 1] == 'u')
		ret = ft_putulnbr(va_arg(ap, unsigned long int));
	else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
		ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
	else if (str[*i + 1] == 'x')
		ret = ft_putstring(ft_base("0123456789abcdef",
							va_arg(ap, long int)));
	else if (str[*i + 1] == 'X')
		ret = ft_putstring(ft_base("0123456789ABCDEF",
							va_arg(ap, long int)));
	else
		ret = ft_putlnbr(va_arg(ap, long int));
	return (ret);
}

int		modifh(va_list ap, char *str, int *i, int ret)
{
	if (str[*i + 1] == 'h')
	{
		*i = *i + 1;
		if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
			ret = modifhhd(ap);
		else if (str[*i + 1] == 'u')
			ret = modifhhu(ap);
		else if (str[*i + 1] == 'o')
			ret = modifhho(ap);
		else if (str[*i + 1] == 'x')
			ret = modifhhx(ap);
		else if (str[*i + 1] == 'X')
			ret = modifhh_x(ap);
		else if (str[*i + 1] == 'C')
		{
			ft_putchar(va_arg(ap, int));
			ret = ret + 2;
		}
		else
			ret = ft_option(ap, str, *i + 1);
	}
	else
		ret = ft_option(ap, str, *i + 1);
	return (ret);
}
