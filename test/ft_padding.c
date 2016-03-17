#include "ft_ls.h"

static t_file  *ft_padding_size(t_file *lst)
{
  t_file  *begin_list;
  int     size;

  begin_list = lst;
  size = 0;
  while (lst)
  {
    if (ft_nblen(lst->symlinks) > size)
      size = ft_nblen(lst->symlinks);
    lst = lst->next;
  }
  lst = begin_list;
}

t_file  ft_padding(t_file *lst)
{
  lst = ft_padding_size(lst);
  return (lst);
}
