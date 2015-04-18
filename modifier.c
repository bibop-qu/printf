/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 16:54:20 by basle-qu          #+#    #+#             */
/*   Updated: 2015/03/31 19:14:56 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		modifhhd(va_list ap)
{
	int	ret;
	int tmp;

	tmp = va_arg(ap, int);
	if (tmp < -128)
		ret = ft_putnbr(127 + (tmp % 129));
	else if (tmp >= -128 && tmp <= 127)
		ret = ft_putnbr(tmp);
	else
		ret = ft_putnbr(-128 + (tmp % 128));
	return (ret);
}

int		modifspace(va_list ap, char *str, int *i)
{
	int		j;
	int		ret;
	char	*nbr;
	int		tmp;
	int		nb;

	j = *i;
	ret = 0;
	tmp = va_arg(ap, int);
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	nbr = ft_strsub(str, j, *i - j);
	nb = ft_atoi(nbr) - ft_strlen(ft_itoa(tmp));
	j = -1;
	if (str[*i] == 'p')
		j = 1;
	while (++j < nb)
		ret += ft_putstring(" ");
	if (str[*i] == 'd')
		ret += ft_putnbr(tmp);
	else if (str[*i] == 'p')
	{
		if (tmp == 0)
			ret += ft_putaddr(NULL);
		else
			ret += ft_putaddr(&tmp);
	}
	else
	{
		ret = ret + 2;
		*i = *i + 1;
	}
	return (ret);
}

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

int		modifhhX(va_list ap)
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
	{
		if (str[*i + 1] == 'd' || str[*i + 1] == 'i' || str[*i + 1] == 'D')
			ret = ft_putlnbr(va_arg(ap, long int));
		else if (str[*i + 1] == 'u' || str[*i + 1] == 'U')
			ret = ft_putulnbr(va_arg(ap, unsigned long int));
		else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
			ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
		else if (str[*i + 1] == 'x')
			ret = ft_putstring(ft_base("0123456789abcdef", va_arg(ap, long int)));
		else if (str[*i + 1] == 'X')
			ret = ft_putstring(ft_base("0123456789ABCDEF", va_arg(ap, long int)));
		else if (str[*i + 1] == 'c')
			ret = printC(ap);
		else if (str[*i + 1] == 's')
			ret = printS(ap);
		else if (str[*i + 1] == 'l')
		{
			*i = *i + 1;
			if (str[*i + 1] == 'u')
				ret = ft_putulnbr(va_arg(ap, unsigned long int));
			else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
				ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
			else if (str[*i + 1] == 'x')
				ret = ft_putstring(ft_base("0123456789abcdef", va_arg(ap, long int)));
			else if (str[*i + 1] == 'X')
				ret = ft_putstring(ft_base("0123456789ABCDEF", va_arg(ap, long int)));
			else
				ret = ft_putlnbr(va_arg(ap, long long int));
		}
		else if (str[*i + 1] == 'p')
			ret = ft_option(ap, str, *i + 1);
	}
	else if (str[*i] == 'h')
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
				ret = modifhhx(ap);
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
	}
	else if (str[*i] == 'j')
	{
		if (str[*i + 1] == 'u')
			ret = ft_putulnbr(va_arg(ap, unsigned long int));
		else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
			ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
		else if (str[*i + 1] == 'x')
			ret = ft_putstring(ft_base("0123456789abcdef", va_arg(ap, long int)));
		else if (str[*i + 1] == 'X')
			ret = ft_putstring(ft_base("0123456789ABCDEF", va_arg(ap, long int)));
		else
			ret = ft_putlnbr(va_arg(ap, long int));
	}
	else if (str[*i] == 'z')
		if (str[*i + 1] == 'u')
			ret = ft_putulnbr(va_arg(ap, unsigned long int));
		else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
			ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
		else if (str[*i + 1] == 'x')
			ret = ft_putstring(ft_base("0123456789abcdef", va_arg(ap, long int)));
		else if (str[*i + 1] == 'X')
			ret = ft_putstring(ft_base("0123456789ABCDEF", va_arg(ap, long int)));
		else
			ret = ft_putlnbr(va_arg(ap, long int));
	else if (ft_isdigit(str[*i]))
	{
		ret = modifspace(ap, str, i);
		*i = *i - 1;
	}
	return (ret);
}
