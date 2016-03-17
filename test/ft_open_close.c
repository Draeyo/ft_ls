#include "ft_ls.h"

void   *ft_opendir(char *av)
{
  void   *dir_fd;

  dir_fd = opendir(av);
  if (!dir_fd)
  {
    ft_putendl("Error on Open");
    exit(EXIT_FAILURE);
  }
  return (dir_fd);
}

void   ft_closedir(void *dir_fd)
{
  int   closeret;

  if ((closeret = closedir(dir_fd)) < 0)
  {
    ft_putendl("Error on Close");
    exit(EXIT_FAILURE);
  }
}
