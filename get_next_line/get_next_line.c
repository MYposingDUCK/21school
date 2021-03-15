#include <stdio.h>
#include "get_next_line.h"

static char			*ft_strnew(int i)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '0';
	while (i > 0)
	{
		str[i] = '0';
		i--;
	}
	return (str);
}

int get_next_line(int fd, char **line)
{   
    char buf[10 + 1];
    int byte_was_read;
    char    *p;
    static char *remainder;
    int flag;

    flag = 1;
    if(remainder)
        *line = ft_strdup(remainder);
    else
        *line = ft_strnew(1);
    while (flag && (byte_was_read = read(fd, buf, 10)))
    {
        buf[byte_was_read] = '\0'; 
        if ((p = ft_strchr(buf,'\n')))
        {
            *p = '\0';
            flag = 0;
            p++;
            remainder = ft_strdup(p);
        }
    *line = ft_strjoin(*line, buf);
    }
    return (0);  
}

int main(void)
{
    char    *line;
    int     fd;
    //line = "Hello world";
    fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
    get_next_line(fd, &line);
    printf("%s\n", line);
    return (0);
}