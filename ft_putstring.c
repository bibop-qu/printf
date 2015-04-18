
#include "libft.h"

int		ft_putstring(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		i += ft_putstring("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

