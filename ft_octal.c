/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 15:37:52 by basle-qu          #+#    #+#             */
/*   Updated: 2015/02/18 05:00:08 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

unsigned long int	ft_octal(unsigned long int n)
{
    unsigned long int rem;
	int	i;
	unsigned long int octal;

	i = 1;
	octal = 0;
    while (n != 0)
    {
        rem = n % 8;
        n /= 8;
        octal += rem * i;
        i *= 10;
    }
    return (octal);
}
