#include "ft_ls.h"

t_file   *ft_fill_list(struct dirent *entry, struct stat file, t_file *lst, void *dir_fd)
{
  int   i;
  t_file  *begin_list;
  t_file  *first = NULL;
  t_file  *line = NULL;

  i = 0;
  while ((entry = readdir(dir_fd)))
  {
    if (i == 0)
    {
      first = ft_register(file, entry);
      lst = first;
      begin_list = lst;
    }
    else if (i > 0)
    {
      line = ft_register(file, entry);
      lst->next = line;
      lst = lst->next;
    }
    i++;
  }
  return (begin_list);
}
