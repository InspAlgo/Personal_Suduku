#pragma once
#include"stdafx.h"
#include<iostream>
#include<fstream>

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
public:
	Sudoku();
	void Strategy_C(int i, int j);
	void Strategy_S();
	bool Check_C(int num, int i, int j);
	void Output_C();
	void charArray_init(int Out_Num);
};