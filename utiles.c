#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_ssl.h"
#include "libft.h"
#include "get_next_line.h"

char	*read_fd(int fd)
{
	char	*line;
	char	*ret;

	line = NULL;
	ret = NULL;
	while (get_next_line(fd, &line) > 0) // Remove empty line
	{
		if (ret == NULL)
			ret = ft_strdup(line);
		else
			ft_strproperjoin(&ret, &line);
	}
	if (line != NULL)
		ft_strproperjoin(&ret, &line);
	return (ret);
}

char	*read_file(char	*filename)
{
	int		fd;
	char	*ret;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	ret = read_fd(fd);
	close(fd);
	return (ret);
}
