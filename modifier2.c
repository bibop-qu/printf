/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:15:39 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/28 15:25:41 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		modifll(va_list ap, char *str, int *i)
{
	int		ret;

	ret = 0;
	*i = *i + 1;
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
		ret = ft_putlnbr(va_arg(ap, long long int));
	return (ret);
}

int		modifl(va_list ap, char *str, int *i)
{
	int		ret;

	ret = 0;
	if (str[*i + 1] == 'd' || str[*i + 1] == 'i' || str[*i + 1] == 'D')
		ret = ft_putlnbr(va_arg(ap, long int));
	else if (str[*i + 1] == 'u' || str[*i + 1] == 'U')
		ret = ft_putulnbr(va_arg(ap, long int));
	else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
		ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
	else if (str[*i + 1] == 'x')
		ret = ft_putstring(ft_base("0123456789abcdef",
							va_arg(ap, long int)));
	else if (str[*i + 1] == 'X')
		ret = ft_putstring(ft_base("0123456789ABCDEF",
							va_arg(ap, long int)));
	else if (str[*i + 1] == 'c')
		ret = print_c(ap);
	else if (str[*i + 1] == 's')
		ret = print_d(ap);
	else if (str[*i + 1] == 'p')
		ret = ft_option(ap, str, *i + 1);
	else if (str[*i + 1] == 'l')
		ret = modifll(ap, str, i);
	return (ret);
}

int		spacep(int tmp)
{
	int	ret;

	ret = 0;
	if (tmp == 0)
		ret += ft_putaddr(NULL);
	else
		ret += ft_putaddr(&tmp);
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
		ret = spacep(tmp);
	return (ret);
}

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
