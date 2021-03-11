
#include "ft_printf.h"

int			handle_width(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}

int			handle_flag(t_flags flags, va_list args)
{
	if (flags.arg_value == 'c')
		return (handle_char(va_arg(args, int), flags));
	if (flags.arg_value == 's')
		return (handle_str(va_arg(args, char*), flags));
	if (flags.arg_value == 'd' || flags.arg_value == 'i')
		return (handle_int(va_arg(args, int), flags));
	if (flags.arg_value == 'u')
		return (handle_unsigned(va_arg(args, unsigned int), flags));
	if (flags.arg_value == '%')
		return (handle_percent(flags));
	if (flags.arg_value == 'p')
		return (handle_ptr(va_arg(args, unsigned long long), flags));
	if (flags.arg_value == 'x')
		return (handle_hex(va_arg(args, int), flags, 87));
	if (flags.arg_value == 'X')
		return (handle_hex(va_arg(args, int), flags, 55));
	return (0);
}

static void	init_variables(int *i, int *count,
int *size, const char *format)
{
	*i = 0;
	*count = 0;
	*size = ft_strlen(format);
}

int			parse(const char *format, va_list args)
{
	int		i;
	int		size;
	t_flags	flags;

	init_variables(&i, &flags.count, &size, format);
	while (i <= size && format[i])
	{
		init_flags(&flags);
		if (format[i] == '%' && format[i + 1])
		{
			i += parse_flags(&format[i], args, &flags);
			if (is_format(format[i]))
			{
				if ((flags.return_value = handle_flag(flags, args)) == -1)
					return (-1);
				flags.count += flags.return_value;
			}
			else if (format[i])
				flags.count += ft_putchar(format[i]);
		}
		else if (format[i] != '%')
			flags.count += ft_putchar(format[i]);
		i++;
	}
	return (flags.count);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	count = parse(format, args);
	va_end(args);
	return (count);
}
