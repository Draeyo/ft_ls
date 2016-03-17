#include "ft_ls.h"

char  *ft_bsize(struct stat file)
{
  int   size;
  char  *ret = NULL;

  size = file.st_size;
  ret = ft_strnew(ft_nblen(size));
  ret = ft_s_itoa(size);
  return (ret);
}
