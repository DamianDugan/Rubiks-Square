#include <stdlib.h>
#include <stdio.h>
#include "rubiks.h"

void	print_tab(int **table)
{
  int i = 0;
  printf("-------------\n");
  while ( i < 4 )
    {
      printf("| %d | %d | %d | %d |", table[i][0], table[i][1], table[i][2], table[i][3]);
      printf("-----------------\n");
      i++;

    }
  printf("\n");
}

/*int	main()
{
  int
  

  }*/
