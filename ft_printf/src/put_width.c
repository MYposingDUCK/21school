
#include "ft_printf.h"

void				parse_width_flag(va_list args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
		flags->zero = 0;
	}
}

static int			put_befor_1(t_flags *flags, int *field_len,
int actual_size, int *is_minus)
{
	int		count;

	count = 0;
	if (actual_size < flags->point)
		*field_len = flags->point;
	if (flags->zero == 1 && flags->point < 0)
	{
		if (*is_minus == 1)
			count += ft_putchar('-');
		count += put_zero(flags->width - *field_len - *is_minus);
	}
	else
		count += put_blank(flags->width - *field_len - *is_minus);
	if (*is_minus == 1 && !(flags->zero == 1 && flags->point < 0))
		count += ft_putchar('-');
	count += put_zero(flags->point - actual_size);
	*is_minus = -5;
	return (count);
}

static int			put_befor_2(t_flags *flags, int *field_len,
int *is_minus, char *str)
{
	int		count;

	count = 0;
	if (flags->zero == 1)
	{
		if (*is_minus == 1)
			count += ft_putchar('-');
		if (ft_strncmp(str, "0", 1) == 0 && flags->width == 1)
			count += put_blank(flags->width - *field_len - *is_minus);
		else
			count += put_zero(flags->width - *field_len - *is_minus);
		*is_minus = -5;
	}
	else
		count += put_blank(flags->width - *field_len - *is_minus);
	if (*is_minus == 1)
	{
		count += ft_putchar('-');
		*is_minus = -5;
	}
	return (count);
}

int					put_width(t_flags *flags, int actual_size,
int *is_minus, char *str)
{
	int		field_len;
	int		count;

	count = 0;
	field_len = actual_size;
	if (flags->one_space != 0)
		count += put_blank(1);
	if (actual_size == 1 && flags->point == 0 && ft_strncmp("0", str, 1) == 0)
		field_len = 0;
	if (flags->width != 0 && flags->point != -1 &&
		flags->minus == 0 && flags->width > actual_size)
		count += put_befor_1(flags, &field_len, actual_size, is_minus);
	else if (flags->width != 0 && flags->width > field_len && flags->minus == 0)
		count += put_befor_2(flags, &field_len, is_minus, str);
	else if (flags->point != 0)
	{
		if (*is_minus == 1)
		{
			count += ft_putchar('-');
			*is_minus = -5;
		}
		count += put_zero(flags->point - actual_size);
	}
	return (count);
}
