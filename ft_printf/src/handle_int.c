
#include "ft_printf.h"

int					put_zero(int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar('0');
		i++;
	}
	if (size < 0)
		size = 0;
	return (size);
}

static int			put_blank_befor(t_flags *flags, char *str, int *actual_size,
int *is_minus)
{
	if (flags->point > ft_strlen(str) + *is_minus)
		*actual_size = flags->point + *is_minus;
	else
		*actual_size = ft_strlen(str) + *is_minus;
	if (*actual_size == 1 && flags->point == 0 && ft_strncmp("0", str, 1) == 0)
		*actual_size = 0;
	return (put_width(flags, ft_strlen(str), is_minus, str));
}

static void			check_is_negative(long *digit, int *is_minus)
{
	if (*digit < 0)
	{
		*is_minus = 1;
		*digit = -(*digit);
	}
}

static void			handle_after_minus(t_flags *flags,
int *actual_size, int *is_minus)
{
	if (*is_minus == -5)
	{
		flags->width--;
		(*actual_size)--;
	}
}

int					handle_int(long digit, t_flags flags)
{
	int		count;
	int		actual_size;
	char	*str;
	int		is_minus;

	count = 0;
	is_minus = 0;
	check_is_negative(&digit, &is_minus);
	if ((str = ft_itoa(digit)) == NULL)
		return (-1);
	count += put_blank_befor(&flags, str, &actual_size, &is_minus);
	if (is_minus == 1)
		count += ft_putchar('-');
	if (!(flags.point == 0 && digit == 0))
		count += ft_putstrl(str, ft_strlen(str));
	handle_after_minus(&flags, &actual_size, &is_minus);
	if (flags.point > actual_size)
		actual_size = flags.point;
	flags.width -= actual_size;
	if (flags.width > 0 && flags.minus == 1)
		count += put_blank(flags.width);
	free(str);
	return (count);
}
