#pragma once
#include"stdafx.h"

using namespace std;

class Sudoku
{
private:
	char board_[10][10];
	int num_;          // �����������վָ���
	int output_num_;   // Ҫ�����������վֵĸ���
	char* out_array_;  // ����Ҫ������վ�
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