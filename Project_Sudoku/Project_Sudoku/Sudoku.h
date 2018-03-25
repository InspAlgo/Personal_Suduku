#pragma once
#include"stdafx.h"
#include<iostream>
#include<fstream>

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
public:
	Sudoku();
	void Strategy_C(int i, int j);
	void Strategy_S();
	bool Check_C(int num, int i, int j);
	void Output_C();
	void charArray_init(int Out_Num);
};