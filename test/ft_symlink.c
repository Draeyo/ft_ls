#include "ft_ls.h"

int   ft_symlink(struct stat file)
{
  int   ret;

  ret = (file.st_nlink);
  return (ft_s_itoa(ret));
}
