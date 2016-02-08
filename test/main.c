#include "ft_ls.h"

static char		*fill_rights(char *str)
{
	int		i;

	i = 0;
	while (i++ != 10)
		str[i] = '-';
	return (str);
}

void			rights(struct stat file)
{
	char	*str;

	str = ft_strnew(10);
	str = fill_rights(str);
	ft_putchar((S_ISDIR(file.st_mode) ? 'd' : '-'));
	ft_putchar((file.st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar((file.st_mode & S_IWUSR ? 'w' : '-'));
	ft_putchar((file.st_mode & S_IXUSR ? 'x' : '-'));
	ft_putchar((file.st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar((file.st_mode & S_IWGRP ? 'w' : '-'));
	ft_putchar((file.st_mode & S_IXGRP ? 'x' : '-'));
	ft_putchar((file.st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar((file.st_mode & S_IWOTH ? 'w' : '-'));
	ft_putchar((file.st_mode & S_IXOTH ? 'x' : '-'));
	free(str);
}

void	show_mtime(const char *str)
{
	char	*month;
	char	*day;
	char	*hour;
	char	*cpy;
	int		i;

	month = ft_strnew(3);
	day = ft_strnew(2);
	hour = ft_strnew(5);
	cpy = (char*)str;
	i = 0;
	//ft_putstr(str);
	cpy += 4;
	write (1, cpy, ft_strlen(cpy) - 9);
}

int				main(int ac, char **av)
{
	void			*dir_fd;
	struct group	*group;
	struct passwd	*passwd;
	int				closeret;
	struct stat		file;
	struct dirent	*entry;
	int				i;
	int				blocks;
	
	if (ac < 2)
		return (0);
	i = 0;
	blocks = 0;
	while (av[++i])
	{
		if (!(dir_fd = opendir(av[i])))
		{
			ft_putendl("Not a directory");
			exit(EXIT_FAILURE);
		}
		ft_putchar((i > 1 ? '\n' : '\0'));
		ft_putstr((ac > 2 ? av[i] : ""));
		ft_putchar((ac > 2 ? ':' : '\0'));
		ft_putchar((ac > 2 ? '\n' : '\0'));
		while ((entry = readdir(dir_fd)))
		{
			stat(entry->d_name, &file);
			rights(file);
			ft_putstr("  ");
			ft_putnbr(file.st_nlink);
			ft_putstr(" ");
			passwd = getpwuid(file.st_uid);
			ft_putstr(passwd->pw_name);
			ft_putstr("  ");
			group = getgrgid(file.st_gid);
			ft_putstr(group->gr_name);
			ft_putstr("  ");
			ft_putnbr(file.st_size);
			ft_putstr("  ");
			show_mtime(ctime(&file.st_mtimespec.tv_sec));
			ft_putstr("  ");
			ft_putstr(entry->d_name);
			ft_putchar('\n');
			blocks += file.st_blocks;
		}
		ft_putstr("total ");
		ft_putnbr(blocks);
		ft_putchar('\n');
		if ((closeret = closedir(dir_fd)) != 0)
		{
			ft_putendl("Error on close");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
