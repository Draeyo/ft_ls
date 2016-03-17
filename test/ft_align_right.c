#include "ft_ls.h"

char  *ft_strnew_digit(int nb, int fill)
{
  char  *str;
  int   i;

  i = 0;
  str = (char*)malloc(sizeof(*str) * (nb + 1));
  while (nb--)
  {
    str[i] = (char)fill;
    i++;
  }
  str[i] = '\0';
  return (str);
}

char  *ft_align_right(char *str, int lenmax)
{
  char  *ret;
  int   i;
  int   j;

  i = lenmax - 1;
  j = ft_strlen(str) - 1;
  ret = ft_strnew_digit(lenmax, ' ');
  while (str[j])
  {
    ret[i] = str[j];
    j--;
    i--;
  }
  return (ret);
}
