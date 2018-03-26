#pragma once
#include"stdafx.h"

using namespace std;

class Sudoku
{
private:
	char board[10][10];
	int Num; //已生成数独终局个数
	int Output_Num; //要求生成数独终局的个数
	char* OutArray;//储存要输出的终局
	long int OutArray_Pointer;
	inline char* into_OutArray();
	char select;
public:
	Sudoku();
	void Strategy_C(int i, int j);
	void Straregy_S(Input input);
	bool ifSolve_S(int i, int j);
	bool Check_C(int num, int i, int j);
	bool Check_S(int num, int i, int j);
	void Output_CS();
	void charArray_init(int Out_Num, char Sel);
};