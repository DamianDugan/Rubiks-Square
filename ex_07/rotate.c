#include <stdio.h>
#include <stdlib.h>
#include "rubiks.h"
#define EMPTY 0
#define BLOCKED 1
void rotate_columns(int **table, int column, int offset)
{  
  int i = 0;
  int j = 0;
  if (offset < 0)
    while(i < (-offset))
      {
	algo_column_reverse(table, column);
	i++;
      }
  if (offset > 0)
    while(j < offset)
      {
	algo_column(table, column);
	j++;
      }
}

void rotate_lines(int **table, int line, int offset)
{
  int i = 0;
  if (offset < 0)
    while(i < (-offset))
      {
    algo_line_reverse(table, line);
    i++;
      }
  if (offset > 0)
    while(i < offset)
      {
	algo_line(table, line);
	i++;
      }
}

int	main()
{
  int *ret_value;
  int *ret_space;
  int j = 0;
  int i = 0;
  int k = 0;
  int lines[4];
  int columns[4];
  int **table = malloc(sizeof(int*)*4);
  
  while (i < 4)
    {
      table[i] = malloc(sizeof(int)*4);
      i++;
    }
  i = 0;
  
  table[0][0] = 0;
  table[0][1] = 2;
  table[0][2] = 0;
  table[0][3] = 0;
  table[1][0] = 3;
  table[1][1] = 0;
  table[1][2] = 3;
  table[1][3] = 1;
  table[2][0] = 2;
  table[2][1] = 2;
  table[2][2] = 1;
  table[2][3] = 3;
  table[3][0] = 1;
  table[3][1] = 1;
  table[3][2] = 3;
  table[3][3] = 2;

  lines[0]= BLOCKED;
  lines[1]= EMPTY;
  lines[2] = BLOCKED;
  lines[3] = BLOCKED;
  columns[0] = EMPTY;
  columns[1] = EMPTY;
  columns[2] = EMPTY;
  columns[3] = EMPTY;
  
  ret_value = look_for_value(table, lines, columns, 0);
  /* if(ret_value == NULL)
    {
      return (0);
    }*/
  lines[0] = EMPTY;
  lines[1] = BLOCKED;

  ret_space = look_for_space(table, lines, columns, 0);
  rotate_lines(table, ret_value[0], ret_value[1] - ret_space[1]);
  print_tab(table);
  rotate_columns(table, ret_space[1], ret_value[0] - ret_space[0]);
  print_tab(table);
}
