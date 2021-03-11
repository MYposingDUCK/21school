
#include "ft_printf.h"

char			*transferm_to_hex_zero(void)
{
	char	*result;

	if ((result = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static void		copy_hex_str(char *result, char *hex_num, int temp, int i)
{
	temp = i - 1;
	i = 0;
	while (temp >= 0)
		result[i++] = hex_num[temp--];
	result[i] = '\0';
}

char			*transform_to_hex(unsigned int n, int low_or_high)
{
	char	hex_num[100];
	int		i;
	char	*result;
	int		temp;

	i = 0;
	if (n == 0)
		return (transferm_to_hex_zero());
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hex_num[i] = temp + '0';
		else
			hex_num[i] = temp + low_or_high;
		i++;
		n = n / 16;
	}
	if ((result = (char*)malloc(sizeof(char) * 100)) == NULL)
		return (NULL);
	copy_hex_str(result, hex_num, temp, i);
	return (result);
}

int				handle_hex(unsigned int digit, t_flags flags, int low_or_high)
{
	int		count;
	int		actual_size;
	char	*str;
	int		is_minus;

	count = 0;
	is_minus = 0;
	if ((str = transform_to_hex(digit, low_or_high)) == NULL)
		return (-1);
	if (flags.point > ft_strlen(str))
		actual_size = flags.point;
	else
		actual_size = ft_strlen(str);
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
