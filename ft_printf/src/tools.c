#include "ft_printf.h"

void			init_flags(t_flags *flags)
{
	flags->one_space = 0;
	flags->minus = 0;
	flags->star = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->point = -1;
	flags->return_value = 0;
	flags->arg_value = '\0';
}

int				is_format(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd')
			|| (c == 'i') || (c == 'u')
			|| (c == 'x') || (c == 'X') || (c == '%'));
}

int				is_flag(char c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*') || (c == ' '));
}

int				to_int(char c)
{
	return (c - '0');
}

char			*create_low(char *str)
{
	if (str == NULL || ft_strlen(str) == 1)
		return (str);
	while (*str != '\0')
	{
		*str = (char)ft_tolower(*str);
		str++;
	}
	return (&str[0]);
}
