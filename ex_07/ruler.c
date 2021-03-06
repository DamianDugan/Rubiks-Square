#include <stdlib.h>
#include <stdio.h>
#include "rubiks.h"

void	print_tab(int **table)
{
  int i = 0;
  printf("-----------------\n");
  while (i < 4)
    {
      printf("| %d | %d | %d | %d |", table[i][0], table[i][1], table[i][2], table[i][3]);
      printf("\n-----------------\n");
      i++;
    }
  printf("\n");
}

void	algo_line(int **table, int line)
{
  int i = 1;
  int tmp;

  tmp=table[line][0];
  while (i < 4)
    {
      table[line][i] = table[line][i+1];
      i++;
    }
  table[line][3] = tmp;
}

void	algo_column(int **table, int column)
{
  int i = 0;
  int tmp;

  tmp = table[0][column];
  while (i < 3)
    {
      table[i][column] = table[i+1][column];
      i++;
    }
  table[3][column] = tmp;
}

void	algo_line_reverse(int **table, int line)
{
  int i = 3;
  int tmp;

  tmp = table[line][3];
    while (i > 0)
      {
	table[line][i] = table[line][i-1];
	i--;
      }
  table[line][0] = tmp;
}

void	algo_column_reverse(int **table, int column)
{
  int i = 3;
  int tmp;

  tmp = table[3][column];
    while(i > 0)
      {
	table[i][column] = table[i-1][column];
	i--;
      }
    table[0][column] = tmp;
}
int	*look_for_value(int**table, int *lines, int *columns, int value)
{
  int *ret = malloc(sizeof(int) * 2);

  for(int i = 0; i < 4; i++)
    {
      if(lines[i] == 0)
	{
	  for(int j = 0; j < 4; j++)
	    {
	      if(columns[j] == 0)
		{
		  if (table[i][j] == value)
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
  return (ret);
}

int	*look_for_space(int **table, int*lines, int *columns, int value)
{
  int *ret = malloc(sizeof(int) * 2);

  for(int i = 0; i < 4; i++)
    {
      if(lines[i] == 0)
	{
	  for(int j = 0; j < 4; j++)
	    {
	      if(columns[j] == 0)
		{
		  if(value != table[i][j])
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
  return (ret);
}
