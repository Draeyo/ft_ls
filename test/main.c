#include "ft_ls.h"

char	*rights(struct stat file)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * 10 + 1);
	if (S_ISDIR(file.st_mode))
		str[0] = 'd';
	else
		str[0] = '-';
	if (file.st_mode & S_IRUSR)
		str[1] = 'r';
	else
		str[1] = '-';
	if (file.st_mode & S_IWUSR)
		str[2] = 'w';
	else
		str[2] = '-';
	if (file.st_mode & S_IXUSR)
		str[3] = 'x';
	else
		str[3] = '-';
	if (file.st_mode & S_IRGRP)
		str[4] = 'r';
	else
		str[4] = '-';
	if (file.st_mode & S_IWGRP)
		str[5] = 'w';
	else
		str[5] = '-';
	if (file.st_mode & S_IXGRP)
		str[6] = 'x';
	else
		str[6] = '-';
	if (file.st_mode & S_IROTH)
		str[7] = 'r';
	else
		str[7] = '-';
	if (file.st_mode & S_IWOTH)
		str[8] = 'w';
	else
		str[8] = '-';
	if (file.st_mode & S_IXOTH)
		str[9] = 'x';
	else
		str[9] = '-';
	str[10] = '\0';
	return (str);
}

int	main(int ac, char **av)
{
	void		*dir_fd;
	struct group	*group;
	int		closeret;
	struct stat	file;
	struct dirent	*entry;
	
	if (ac != 2)
		return (0);
	if (!(dir_fd = opendir(av[1])))
	{
		ft_putendl("Not a directory");
		return (0);
	}
	while ((entry = readdir(dir_fd)))
	{
		stat(entry->d_name, &file);
		ft_putstr(rights(file));
		ft_putchar(' ');
		group = getgrgid(file.st_gid);
		ft_putstr(group->gr_name);
		ft_putchar(' ');
		ft_putnbr(file.st_size);
		ft_putchar(' ');
		ft_putstr(entry->d_name);
		ft_putchar('\n');
	}
	if ((closeret = closedir(dir_fd)) != 0)
	{
		ft_putendl("Error on close");
		return (0);
	}
	return (0);
}
