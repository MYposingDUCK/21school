
#include "ft_printf.h"

int		handle_char(char c, t_flags flags)
{
	int count;

	if (flags.minus == 1)
		ft_putchar(c);
	count = handle_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}

int		handle_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus)
		count = ft_putchar('%');
	count += handle_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putchar('%');
	return (count);
}
