
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_flags
{
	int		minus;
	int		star;
	int		zero;
	int		width;
	int		point;
	int		one_space;
	int		return_value;
	int		count;
	char	arg_value;
}				t_flags;

int				ft_putchar(char c);
int				parse_flags(const char *format, va_list args, t_flags *flags);
int				is_format(char c);
int				is_flag(char c);
void			init_flags(t_flags *flags);
int				parse_point_flag(const char *str, int start,
t_flags *flags, va_list args);
int				parse(const char *format, va_list args);
int				ft_isdigit(int c);
int				ft_printf(const char *format, ...);
int				handle_char(char c, t_flags flags);
int				handle_width(int width, int minus, int zero);
int				handle_flag(t_flags flags, va_list args);
void			parse_minus_flag(t_flags *flags);
t_flags			parse_digit_flag(char c, t_flags flags);
void			parse_width_flag(va_list args, t_flags *flags);
int				ft_putstr(char *str);
int				ft_putstrl(char *str, int maxlen);
int				handle_str(char *str, t_flags flags);
int				handle_int(long digit, t_flags flags);
int				put_blank(int size);
int				handle_percent(t_flags flags);
int				handle_ptr(unsigned long long ptr, t_flags flags);
int				put_width(t_flags *flags, int actual_size,
int *is_minus, char *str);
int				handle_hex(unsigned int digit, t_flags flags, int low_or_high);
int				handle_unsigned(unsigned int digit, t_flags flags);
int				put_zero(int size);
int				to_int(char c);
char			*create_low(char *str);

#endif
