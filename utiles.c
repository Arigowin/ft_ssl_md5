#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "ft_ssl.h"
#include "libft.h"

uint32_t			swap_int32(const uint32_t value)
{
	uint32_t result;

	result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return (result);
}


int			ft_isfile(char *name)
{
	DIR *directory;

	directory = opendir(name);
	if (directory != NULL)
	{
		closedir(directory);
		return (0);
	}
	return (1);
}

char	*read_fd(int fd)
{
	int		err;
	char	*buff;
	char	*ret;

	ret = NULL;
	if ((buff = ft_strnew(4096)) == NULL)
		return (NULL);
	while ((err = read(fd, buff, 4096)) > 0)
	{
		if (ret == NULL)
			ret = ft_strdup(buff);
		else
			ft_strproperjoin(&ret, &buff);
	}
	return (ret);
}

char	*read_file(char	*filename)
{
	int		fd;
	char	*ret;

	if (!ft_isfile(filename))
	{
		printf("ft_ssl: %s: Is a directory\n", filename);
		return (NULL);
	}
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		printf("ft_ssl: %s: no such file or directory\n", filename);
		return (NULL);
	}
	ret = read_fd(fd);
	close(fd);
	return (ret);
}
