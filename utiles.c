#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "ft_ssl.h"
#include "libft.h"

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
	buff = ft_strnew(4096);
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
		printf("%s %s: Is a directory\n", NAME, filename);
		return (NULL);
	}
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		printf("%s %s: no such file or directory\n", NAME, filename);
		return (NULL);
	}
	ret = read_fd(fd);
	close(fd);
	return (ret);
}
