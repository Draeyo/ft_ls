#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define DEBUG	ft_putendl("DEBUG");

typedef struct  s_file
{
  char          *rights;
  char          *symlinks;
  char          *owner;
  char          *group;
  char          *size;
  char          *time;
  char          *name;
  int           blocks;
  struct s_file *next;
}               t_file;

/*
** Main
*/

char            *ft_rights(struct stat file);
char            *ft_owner(struct stat file);
char            *ft_owner_grp(struct stat file);
char            *ft_bsize(struct stat file);
char            *ft_time(struct stat file);
char            *ft_total_sym(t_file *lst);
char            *ft_align_right(char *str, int lenmax);

int             ft_symlink(struct stat file);

void            *ft_opendir(char *av);
void            ft_closedir(void *dir_fd);
void            ft_display_la(t_file *lst);

t_file          *ft_register(struct stat file, struct dirent *entry);
t_file          *ft_fill_list(struct dirent *entr, struct stat file, t_file *lst, void *dir_fd);
t_file          *ft_padding(t_file *lst);

/*
** Utilitaires
*/

void            ft_multi_name(int ac, char **av, int i);

/*
** Utilitaires lib2
*/

char            *ft_s_itoa(int nb);
int             ft_s_atoi(char *str);
int             ft_nblen(int nb);

#endif
