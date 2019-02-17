#include <stdio.h>
#include <stdlib.h>
#define PRINT_SQUARE_DEBUG_ 1
#include "rubiks.h"

void	algo_line_reverse(int **table, int line)
{
  int i = 3;
  int tmp;

  tmp = table[line][3];
  while(i > 0 )
    {
      table[line][i] = table[line][i-1];
      i--;
    }
  table[line][0] = tmp;

 printf("Rotate Right line %d.\n", line);
 print_tab(table);
}

void	algo_column_reverse(int **table, int column)
{
  int i = 3;
  int tmp;

  tmp = table[3][column];
  while (i > 0)
    {
      table[i][column] = table[i-1][column];
      i--;
    }
  
  table[0][column] = tmp;
 printf("Rotate Down column %d.\n", column);
 print_tab(table);
}
void	algo_square_reverse(int **table, int square)
{
  int tmp;

  if (square == 0 )
    {
  tmp= table[0][0];
  table[0][0] = table[0][1];
  table[0][1] = table[1][1];
  table[1][1] = table[1][0];
  table[1][0] = tmp;   
    }

  if (square ==  1 )
    {
  tmp= table[0][2];
  table[0][2] = table[0][3];
  table[0][3] = table[1][3];
  table[1][3] = table[1][2];
  table[1][2] = tmp;
    }
  if (square ==  2 )
    {
  tmp= table[2][0];
  table[2][0] = table[2][1];
  table[2][1] = table[3][1];
  table[3][1] = table[3][0];
  table[3][0] = tmp;
    }
   if (square ==  3 )
    {
  tmp= table[2][2];
  table[2][2] = table[2][3];
  table[2][3] = table[3][3];
  table[3][3] = table[3][2];
  table[3][2] = tmp;
    }
   
 printf("Rotate Counter Clockwise square %d.\n", square);
 print_tab(table);
}

int	main()
{
  int line, square, column = 0;
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
  
  printf("-------------------\n");
  while ( k < 4 )
    {
      printf("| %d | %d | %d | %d |", table[k][0], table[k][1], table [k][2], table[k][3]);
      printf("\n-------------------\n");
      k++;
      }
  print_tab(table);
  algo_line_reverse(table, 0);
  print_tab(table);  
  algo_column_reverse(table, 0);
  print_tab(table);
  algo_square_reverse(table, 0);
  print_tab(table);
  }
