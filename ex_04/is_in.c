#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"

int	is_in_line(int**table, int line, int value)
{
  int i = 0;
  while (i < 4)
    {
  if(table[line][i] == value)
    {
    return 0;
     }
  
  i++;
    }
  return 1;
}
int	is_in_col(int**table, int column, int value)
{
  int i = 0;
  while ( i < 4)
    {
      if(table[i][column] == value)
	{
	  return 0;
	}
      i++;
    }
  return 1;
}

int	main()
{
  int line, square, column = 0;
  int value = 0;
  int j = 0;
  int i = 0;
  int k = 0;
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
  
  printf("%d - %d\n", is_in_line(table, 0, 1), is_in_col(table, 2, 3));
  printf("%d - %d\n", is_in_line(table, 3, 1), is_in_col(table, 2, 0));
}
