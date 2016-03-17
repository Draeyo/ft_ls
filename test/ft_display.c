#include "ft_ls.h"

void  ft_display_la(t_file *lst)
{
  while (lst)
  {
    ft_putstr(lst->rights);
    ft_putstr("  ");
    ft_putstr(ft_itoa(lst->symlinks));
    ft_putstr("  ");
    ft_putstr(lst->owner);
    ft_putstr("  ");
    ft_putstr(lst->group);
    ft_putstr("  ");
    ft_putstr(lst->size);
    ft_putstr("  ");
    ft_putstr(lst->time);
    ft_putstr(" ");
    ft_putendl(lst->name);
    lst = lst->next;
  }
}
