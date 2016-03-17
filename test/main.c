#include "ft_ls.h"

int				main(int ac, char **av)
{
	void					*dir_fd;
	struct stat		file;
	struct dirent	*entry = NULL;
	int						i;
	t_file				*lst = NULL;
	int						blocks;

	if (ac < 2)
		return (0);
	i = 0;
	blocks = 0;
	while (av[++i])
	{
		dir_fd = ft_opendir(av[i]);
		ft_multi_name(ac, av, i);
		lst = ft_fill_list(entry, file, lst, dir_fd);
		ft_putstr("total ");
		ft_putendl(ft_total_sym(lst));
		ft_display_la(lst);
		ft_closedir(dir_fd);
	}
	return (0);
}
