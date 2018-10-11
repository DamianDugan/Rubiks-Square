#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"
#define EMPTY 0
#define BLOCKED 1

int *look_for_value(int **table, int *lines, int *columns, int value)
{
  int *ret = malloc(sizeof(int) * 2);
  
  for (int i = 0; i < 4; i++)
    {
      if (lines[i] == 0)
	{
	  for (int j = 0; j < 4; j++)
	    {
	      if (columns[j] == 0)
		{
		  if (value == table[i][j])
		    {
		      ret[0] = i;
		      ret[1] = j;
		      return (ret);
		    }
		}
	    }
	}
    }
  ret = NULL;
  return ret;
}

void	verif_return(int *ret)
{
  if (ret != NULL)
    printf("line :\t%d\nColumn :\t%d\n", ret[0], ret[1]);
  else
    printf("Nothing found in the given range.\n");
}

int	main()
{
  int value = 1;
  int j = 0;
  int i = 0;
  int k = 0;
  int lines[4];
  int columns[4];
  int **table =  malloc(sizeof(int*)*4);
  
  while ( i < 4 )
    {
      table[i] =  malloc(sizeof(int)*4);
      i++;
    }
  i = 0;

  while ( i < 4)
    {
      while ( j < 4 )
	{
	  if (i == 0)
	    table[i][j] = 0;
	  if (i == 1)
	    table[i][j] = 1;
	  if (i == 2)
	    table[i][j] = 2;
	  if (i == 3)
	    table[i][j] = 3;
	  j++;
	}
      j=0;
      i++;
    }
  table[0][2] = 1;
  table[0][3] = 1;

  lines[0]= BLOCKED;
  lines[1]= BLOCKED;
  lines[2] = EMPTY;
  lines[3] = BLOCKED;
  columns[0] = EMPTY;
  columns[1] = EMPTY;
  columns[2] = BLOCKED;
  columns[3] = BLOCKED;
  verif_return(look_for_value(table, lines, columns, 1));
  verif_return(look_for_value(table, lines, columns, 2));
}
