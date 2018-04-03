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
	int num_;				   // �����������վָ���
	int output_num_;		   // Ҫ�����������վֵĸ���
	char* out_array_;		   // ����Ҫ������վ�
	int out_array_pointer_;
	bool num_row[10][10];      // [num][i]������num�ڵ�i���Ƿ����
	bool num_col[10][10];	   // [num][j]
	bool num_box[10][10][10];  // [num][row][col]������num��[row][col]���Ƿ����
};