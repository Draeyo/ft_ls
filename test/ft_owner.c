#include "ft_ls.h"

char    *ft_owner(struct stat file)
{
  struct passwd *passwd;
  char          *ret = NULL;

  passwd = getpwuid(file.st_uid);
  ret = ft_strnew(ft_strlen(passwd->pw_name));
  ret = ft_strcpy(ret, passwd->pw_name);
  return (ret);
}

char   *ft_owner_grp(struct stat file)
{
  struct group  *group;
  char          *ret = NULL;

  group = getgrgid(file.st_gid);
  ret = ft_strnew(ft_strlen(group->gr_name));
  ret = ft_strcpy(ret, group->gr_name);
  return (ret);
}
