#include "ft_ls.h"

char  *ft_time(struct stat file)
{
	char	*ret;
	char	*fulltime;
	char	*pnt;

	fulltime = ft_strnew(ft_strlen(ctime(&file.st_mtimespec.tv_sec)));
	fulltime = ft_strcpy(fulltime, ctime(&file.st_mtimespec.tv_sec));
	pnt = fulltime;
	ret = ft_strnew(15);
	fulltime += 4;
	ret = ft_strsub(fulltime, 0, ft_strlen(fulltime) - 9);
	free(pnt);
	return (ret);
}
