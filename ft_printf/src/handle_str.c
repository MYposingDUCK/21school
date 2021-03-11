
#include "ft_printf.h"

int				put_blank(int size)
{
	int		i;

	i = 0;
	if (size < 0)
		return (0);
	while (i != size)
	{
		ft_putchar(' ');
		i++;
	}
	return (size);
}

int				handle_null_str(t_flags flags)
{
	if (flags.point < -1)
		flags.point = -1;
	return (handle_str("(null)", flags));
}

int				handle_str(char *str, t_flags flags)
{
	int		count;
	int		actual_size;

	count = 0;
	if (str == NULL)
		return (handle_null_str(flags));
	if (flags.point > -1 && flags.point < ft_strlen(str))
		actual_size = flags.point;
	else
		actual_size = ft_strlen(str);
	if (flags.width > actual_size && flags.minus == 0)
	{
		if (flags.zero == 0)
			count += put_blank(flags.width - actual_size);
		else
			count += put_zero(flags.width - actual_size);
	}
	if (flags.point < 0)
		flags.point = ft_strlen(str);
	count += ft_putstrl(str, flags.point);
	flags.width -= actual_size;
	if (flags.width > 0 && flags.minus != 0)
		count += put_blank(flags.width);
	return (count);
}
