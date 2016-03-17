#include "ft_ls.h"

void  ft_multi_name(int ac, char **av, int i)
{
  ft_putchar((i > 1 ? '\n' : '\0'));
  ft_putstr((ac > 2 ? av[i] : ""));
  ft_putchar((ac > 2 ? ':' : '\0'));
  ft_putchar((ac > 2 ? '\n' : '\0'));
}

char  *ft_total_sym(t_file *lst)
{
  int   blocks;

  blocks = 0;
  while (lst)
  {
    blocks += lst->blocks;
    lst = lst->next;
  }
  return(ft_s_itoa(blocks));
}
