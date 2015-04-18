/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 14:22:26 by basle-qu          #+#    #+#             */
/*   Updated: 2015/03/31 19:26:08 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		moinsflag(va_list ap, char *str, int *i)
{

}

int		ft_flag(va_list ap, char *str, int *i, char *option)
{
	int		ret;
	int		nbr;

	ret = 0;
	if (str[*i] == ' ')
	{
		if (str[*i + 1] == '%')
			ret = ft_putstring("%");
		else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		{
			nbr = va_arg(ap, int);
			if (nbr >= 0)
			{
				ret += ft_putstring(" ");
				ret += ft_putstring(ft_itoa(nbr));
			}
			else
				ret += ft_putstring(ft_itoa(nbr));
		}
		else if (!ft_strchr(option, str[*i + 1]))
		{
			ret++;
			ft_putchar(str[*i + 1]);
		}
	}
	else if (str[*i] == '+')
	{
		nbr = va_arg(ap, int);
		if (nbr > 0)
		{
			ret += ft_putstring("+");
			ret += ft_option(ap, str, *i);
		}
		else
			ret += ft_option(ap, str, *i);
	}
	else if (str[*i] == '-')
		ret += moinsflag(ap, str, i);
	return (ret);
}
