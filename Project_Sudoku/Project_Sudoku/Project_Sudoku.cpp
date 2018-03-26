// Project_Sudoku.cpp: 定义控制台应用程序的入口点。
//
#include"stdafx.h"

using namespace std;

int main(int argc, char* argv[])
{
	Input input(argc, argv);
	Sudoku sudoku;
	clock_t start = 0, end = 0, OutTime = 0;

	input.Strategy_Select();
	switch (input.Select)
	{
	case 'c':
		sudoku.charArray_init(input.OutNum, 'c');
		sudoku.Strategy_C(1, 2);
		end = clock();
		sudoku.Output_CS();
		OutTime = clock();
		break;
	case 's':
		sudoku.charArray_init(1000000, 's');
		sudoku.Straregy_S(input);
		end = clock();
		sudoku.Output_CS();
		OutTime = clock();
		break;
	}
	cout << "生成终局用时：" << end - start << " ms" << endl;
	cout << "输出到文本用时：" << OutTime - end << " ms" << endl;
	return 0;
}