/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 04:01:32 by basle-qu          #+#    #+#             */
/*   Updated: 2015/03/27 19:49:43 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printD(va_list ap)
{
	int		ret;
	long int nbr;
	unsigned long int tmp;

	ret = 0;
	nbr = va_arg(ap, long int);
	if (nbr >= 0)
		ret += ft_putlnbr(nbr);
	else
	{
		tmp = (unsigned long int)nbr;
		ret += ft_putlnbr(tmp);
	}
	return (ret);
}

int		printC(va_list ap)
{
	int		ret;
	char	*str;
	wchar_t	c;

	ret = 0;
	c = va_arg(ap, wchar_t);
	str = cast_to_wc(c);
	if (c == 0)
		ret = 1;
	else
		ret = ft_putstring(str);
	return (ret);
}

int		printS(va_list ap)
{
	int		ret;
	char	*str;
	wchar_t	*s;

	ret = 0;
	s = va_arg(ap, wchar_t*);
	str = cast_to_ws(s);
	ret = ft_putstring(str);
	return (ret);
}

int		printo(va_list ap)
{
	int		ret;
	unsigned long int nb;
	char	*tmp;

	tmp = NULL;
	nb = va_arg(ap, unsigned long int);
	tmp = ft_base("01234567", nb);
	ret = ft_putstring(tmp);
	return (ret);
}

int		printx(va_list ap)
{
	int		ret;
	unsigned long int nb;
	char	*tmp;

	tmp = NULL;
	nb = va_arg(ap, unsigned long int);
	tmp = ft_base("0123456789abcdef", nb);
	ret = ft_putstring(tmp);
	return (ret);
}

int		printX(va_list ap)
{
	int		ret;
	unsigned long int nb;
	char	*tmp;

	tmp = NULL;
	nb = va_arg(ap, unsigned long int);
	tmp = ft_base("0123456789ABCDEF", nb);
	ret = ft_putstring(tmp);
	return (ret);
}

int		ft_option(va_list ap, char *str, int i)
{
	int		ret;

	ret = 0;
	if (str[i] == 's')
		ret += ft_putstring(va_arg(ap, char *));
	else if (str[i] == 'S')
		ret = printS(ap);
	else if (str[i] == 'd' || str[i] == 'i')
		ret += ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'u')
		ret += ft_putlnbr(va_arg(ap, long int));
	else if (str[i] == 'U')
		ret += ft_putulnbr(va_arg(ap, long int));
	else if (str[i] == 'D')
		ret += printD(ap);
	else if (str[i] == 'p')
		ret += ft_putaddr(va_arg(ap, void *));
	else if (str[i] == '%')
		ret += ft_putstring("%");
	else if (str[i] == 'o' || str[i] == 'O')
		ret += printo(ap);
	else if (str[i] == 'x')
		ret += printx(ap);
	else if (str[i] == 'X')
		ret += printX(ap);
	else if (str[i] == 'c')
	{
		ft_putchar(va_arg(ap, int));
		ret++;
	}
	else if (str[i] == 'C')
		ret = printC(ap);
	else if (str[i] == '\0' || str[i] == ' ')
		i++;
	else
	{
		ft_putchar(str[i]);
		ret++;
	}
	return (ret);
}
