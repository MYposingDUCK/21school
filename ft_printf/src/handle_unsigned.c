
#include "ft_printf.h"

int				handle_unsigned(unsigned int digit, t_flags flags)
{
	int		count;
	int		actual_size;
	char	*str;
	int		is_minus;

	count = 0;
	is_minus = 0;
	if ((str = ft_itoa(digit)) == NULL)
		return (-1);
	if (flags.point > ft_strlen(str) + is_minus)
		actual_size = flags.point + is_minus;
	else
		actual_size = ft_strlen(str) + is_minus;
	if (actual_size == 1 && flags.point == 0 && digit == 0)
		actual_size = 0;
	count += put_width(&flags, ft_strlen(str), &is_minus, str);
	if (!(flags.point == 0 && digit == 0))
		count += ft_putstrl(str, ft_strlen(str));
	flags.width -= actual_size;
	if (flags.width > 0 && flags.minus == 1)
		count += put_blank(flags.width);
	free(str);
	return (count);
}
