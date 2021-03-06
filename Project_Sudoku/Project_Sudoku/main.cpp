// Project_Sudoku.cpp: 定义控制台应用程序的入口点。
//
#include"stdafx.h"

using namespace std;

int main(int argc, char* argv[])
{
	Input input(argc, argv);
	Sudoku sudoku;
	clock_t start_time = 0, end_time = 0, output_time = 0;

	start_time = clock();
	input.strategySelect();

	switch (input.select)
	{
	case 'c':
		sudoku.charArrayInit(input.out_num);
		sudoku.strategyC(1, 2);
		end_time = clock();
		sudoku.outputCS();
		output_time = clock();
		break;
	case 's':
		sudoku.charArrayInit(1000000);
		sudoku.straregyS(input.file_name);
		end_time = clock();
		sudoku.outputCS();
		output_time = clock();
		break;
	}
	cout << "生成终局用时：" << end_time - start_time << " ms" << endl;
	cout << "输出到文本用时：" << output_time - end_time << " ms" << endl;
	return 0;
}