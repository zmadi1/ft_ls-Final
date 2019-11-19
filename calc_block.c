#include "my_flags.h"

blkcnt_t blockcount(char **directory)
{
    blkcnt_t size;
    int i;
    struct stat fileStat;
    
    size = 0;
    i = 0;
    while(directory[i])
    {
        if (directory[i][0] != '.')
        {
            stat(directory[i], &fileStat);
            size += fileStat.st_blocks;
        }
        i++;
    }
    return size;
}

void display_blockcount(blkcnt_t count)
{
    ft_putstr("total ");
	ft_putnbr(count);
	ft_putendl(" ");
}

