#include "ft_ls.h"

t_file  *ft_register(struct stat file, struct dirent *entry)
{
  t_file  *element;

  element = (t_file*)malloc(sizeof(t_file));
  stat(entry->d_name, &file);
  //rights
  element->rights = ft_rights(file);
  //symlinks
  element->symlinks = ft_symlink(file);
  //owner name
  element->owner = ft_owner(file);
  //owner group
  element->group = ft_owner_grp(file);
  //size
  element->size = ft_bsize(file);
  //time
  element->time = ft_time(file);
  //name
  element->name = entry->d_name;
  //blocks
  element->blocks = file.st_blocks;
  element->next = NULL;
  return (element);
}
