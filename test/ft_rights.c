#include "ft_ls.h"

static char		*ft_fill_rights(char *str)
{
	int		i;

	i = 0;
	while (i++ != 9)
		str[i] = '-';
	return (str);
}

char			*ft_rights(struct stat file)
{
	char	*rights;

	rights = ft_strnew(10);
	rights = ft_fill_rights(rights);
	rights[0] = (S_ISDIR(file.st_mode) ? 'd' : '-');
	rights[1] = (file.st_mode & S_IRUSR ? 'r' : '-');
	rights[2] = (file.st_mode & S_IWUSR ? 'w' : '-');
	rights[3] = (file.st_mode & S_IXUSR ? 'x' : '-');
	rights[4] = (file.st_mode & S_IRGRP ? 'r' : '-');
	rights[5] = (file.st_mode & S_IWGRP ? 'w' : '-');
	rights[6] = (file.st_mode & S_IXGRP ? 'x' : '-');
	rights[7] = (file.st_mode & S_IROTH ? 'r' : '-');
	rights[8] = (file.st_mode & S_IWOTH ? 'w' : '-');
	rights[9] = (file.st_mode & S_IXOTH ? 'x' : '-');
	return (rights);
}
