
#include "ft_printf.h"

int			ft_putchar(char ch)
{
	return (write(1, &ch, 1));
}

int			ft_putstrl(char *str, int maxlen)
{
	int	len;

	len = ft_strlen(str);
	if (maxlen == -1 || maxlen > len)
		maxlen = len;
	return (write(1, str, maxlen));
}

int			ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}
