#pragma once
#include"stdafx.h"

using namespace std;

class Sudoku
{
public:
	Sudoku();
	void charArrayInit(int Out_Num);
	void strategyC(int i, int j);
	void straregyS(char *file_name);
	bool ifSolveS(int i, int j);
	void outputCS();
	bool readSudoku(fstream &read_file);

private:
	void intoOutArray();
	char board_[10][10];
	int num_;				   // 已生成数独终局个数
	int output_num_;		   // 要求生成数独终局的个数
	char* out_array_;		   // 储存要输出的终局
	int out_array_pointer_;
	bool num_row[10][10];      // [num][i]：数字num在第i行是否可填
	bool num_col[10][10];	   // [num][j]
	bool num_box[10][10][10];  // [num][row][col]：数字num在[row][col]格是否可填
};