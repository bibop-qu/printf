/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 14:22:26 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/20 17:43:32 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		moinsflag(va_list ap, char *str, int *i)
{
	int		j;
	int		nb;
	char	*nbr;
	int		tmp;
	int		ret;

	ret = 0;
	tmp = va_arg(ap, int);
	j = *i;
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	nbr = ft_strsub(str, j, *i - j);
	nb = ft_atoi(nbr) - ft_strlen(ft_itoa(tmp));
	j = -1;
	if (str[*i] == 'd')
		ret = ft_putnbr(tmp);
	else if (str[*i] == 'p')
	{
		if (tmp == 0)
			ret += ft_putaddr(NULL);
		else
			ret += ft_putaddr(&tmp);
		j = 1;
	}
	else
	{
		ret = ret + 2;
		*i = *i + 1;
	}
	while (++j < nb)
		ret += ft_putstring(" ");
	return (ret);
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
