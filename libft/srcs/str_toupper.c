#include "libft.h"

char				*str_toupper(char *str)
{
	char				*ret;
	int					i;

	ret = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_toupper(str[i]);
		i++;
	}
	return (ret);
}
