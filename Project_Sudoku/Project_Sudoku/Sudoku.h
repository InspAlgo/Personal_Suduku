#pragma once
#include"stdafx.h"

using namespace std;

class Sudoku
{
private:
	char board[10][10];
	int Num; //�����������վָ���
	int Output_Num; //Ҫ�����������վֵĸ���
	char* OutArray;//����Ҫ������վ�
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