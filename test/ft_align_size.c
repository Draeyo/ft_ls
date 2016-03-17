#include "ft_ls.h"

int   ft_calc_align_size(t_file *lst)
{
  int   i;

  i = 0;
  while (lst)
  {
    if ((int)ft_strlen(lst->size) > i)
      i = ft_strlen(lst->size);
    lst = lst->next;
  }
  return (i);
}

t_file  *ft_align_size(t_file *lst)
{
  t_file *begin_list;
  int   size;

  size = ft_calc_align_size(lst);
  begin_list = lst;
  while (lst)
  {
    lst->size = ft_align_right(lst->size, size);
    lst = lst->next;
  }
  return (begin_list);
}
