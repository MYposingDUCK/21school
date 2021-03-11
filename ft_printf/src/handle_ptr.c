
#include "ft_printf.h"

static	char	*get_ptr(unsigned long long number, int count, char *str)
{
	int num;

	str[count] = '\0';
	while (number != 0)
	{
		num = number % 16;
		if (num < 10)
			str[count - 1] = num + '0';
		else
			str[count - 1] = num + 55;
		number /= 16;
		count--;
	}
	return (str);
}

static char		*transform_ptr(unsigned long long number)
{
	unsigned long long	temp;
	int					count;
	char				*str;

	temp = number;
	count = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		number /= 16;
		count++;
	}
	if (!(str = malloc((sizeof(char) * (count + 1)))))
		return (NULL);
	str = get_ptr(temp, count, str);
	return (str);
}

static int		put_blank_befor(t_flags flags, char *str, int *actual_size,
unsigned long long ptr)
{
	int		count;

	count = 0;
	if (flags.point > -1 && flags.point > ft_strlen(str))
		*actual_size = flags.point;
	else
		*actual_size = ft_strlen(str) + 2;
	if (flags.width > *actual_size && flags.minus == 0)
	{
		if (*actual_size == 3 && ptr == 0 && flags.point >= 0)
			*actual_size -= 1;
		count += put_blank(flags.width - (*actual_size));
	}
	return (count);
}

static int		put_blank_first_c_ptr(unsigned long long ptr,
t_flags flags, char *str, int *actual_size)
{
	int count;

	count = 0;
	count = put_blank_befor(flags, str, actual_size, ptr);
	count += ft_putstr("0x");
	return (count);
}

int				handle_ptr(unsigned long long ptr, t_flags flags)
{
	char	*str;
	int		count;
	int		actual_size;

	count = 0;
	if (ptr == 0 && flags.width == 0 && flags.minus == -1)
		return (ft_putstrl("0x0", 3));
	if ((str = transform_ptr(ptr)) == NULL)
		return (-1);
	create_low(str);
	count = put_blank_first_c_ptr(ptr, flags, str, &actual_size);
	if (flags.point > 0)
		count += put_zero(flags.point - (ft_strlen(str)));
	if (flags.point < ft_strlen(str) && flags.point != 0)
		flags.point = ft_strlen(str);
	if (flags.point == 0 && ptr != 0)
		count += ft_putstrl(str, actual_size);
	count += ft_putstrl(str, flags.point);
	if (ptr == 0 && flags.point == 0)
		flags.width++;
	flags.width -= actual_size;
	if (flags.width > 0 && flags.minus != 0)
		count += put_blank(flags.width);
	free(str);
	return (count);
}
