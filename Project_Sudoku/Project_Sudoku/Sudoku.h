#pragma once
#include"stdafx.h"

using namespace std;

class Sudoku
{
private:
	char board_[10][10];
	int num_;          // 已生成数独终局个数
	int output_num_;   // 要求生成数独终局的个数
	char* out_array_;  // 储存要输出的终局
	int out_array_pointer_;
	void intoOutArray();
	bool num_row[10][10];
	bool num_col[10][10];
	bool num_box[10][10][10];
public:
	Sudoku();
	void strategyC(int i, int j);
	void straregyS(Input input);
	bool ifSolveS(int i, int j);
	void outputCS();
	void charArrayInit(int Out_Num);
};