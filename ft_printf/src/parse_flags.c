
#include "ft_printf.h"

void	parse_minus_flag(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

int		parse_point_flag(const char *str, int start,
t_flags *flags, va_list args)
{
	int i;

	i = start + 1;
	if (str[i] == '*')
	{
		flags->point = va_arg(args, int);
		i++;
	}
	else
	{
		flags->point = 0;
		while (ft_isdigit(str[i]))
		{
			flags->point = (flags->point * 10) + (to_int(str[i]));
			i++;
		}
	}
	return (i);
}

t_flags	parse_digit_flag(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

int		parse_flags(const char *fl, va_list args, t_flags *flags)
{
	int	i;

	i = 1;
	if (fl[i] == ' ')
		flags->one_space = 1;
	while (fl[i] && (is_format(fl[i]) || is_flag(fl[i]) || ft_isdigit(fl[i])))
	{
		if (fl[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (ft_isdigit(fl[i]))
			*flags = parse_digit_flag(fl[i], *flags);
		if (fl[i] == '*')
			parse_width_flag(args, flags);
		if (fl[i] == '-')
			parse_minus_flag(flags);
		if (fl[i] == '.')
			i = parse_point_flag(fl, i, flags, args);
		if (is_format(fl[i]))
		{
			flags->arg_value = fl[i];
			break ;
		}
		i++;
	}
	return (i);
}
