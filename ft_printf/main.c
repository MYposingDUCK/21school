#include <stdio.h>

int	ft_printf(const char *format, ...);

int main(int argc,char **argv)
	{
		int a = -4;
		int count = 10;
	
		ft_printf("original printf = %0*ad",count);
		printf("original printf = %0*ad",a);
		return (0);

	}
