#ifndef RUBIKS_H_
#define RUBIKS_H_

void	print_tab(int **table);
void	algo_line(int **table, int line);
void	algo_column(int **table, int column);
void	algo_square(int **table, int square);

void	algo_line_reverse(int **table, int line);
void	algo_column_reverse(int **table, int column);
void	algo_square_reverse(int **table, int square);
#endif
