#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project_Sudoku/input_control.h"
#include "../Project_Sudoku/sudoku.h"
#include "../Project_Sudoku/input_control.cpp"
#include "../Project_Sudoku/sudoku.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int argc = 3;
		char **argv1, **argv2;
		UnitTest1() 
		{
			argc = 3;
			argv1 = new char*[3];
			argv2 = new char*[3];
			for (int i = 0; i < 3; i++)
			{
				argv1[i] = new char[35];
				argv2[i] = new char[35];
			}
			strcpy_s(argv1[0], 35, "sudoku.exe");
			strcpy_s(argv1[1], 35, "-c");
			strcpy_s(argv1[2], 35, "1666");

			strcpy_s(argv2[0], 35, "sudoku.exe");
			strcpy_s(argv2[1], 35, "-s");
			strcpy_s(argv2[2], 35, "..\\UnitTest1\\unit_test1.txt");

		}

		/* test: strategySelect() C */
		TEST_METHOD(TestMethod1)
		{
			Input input(argc, argv1);
			input.strategySelect();
			Assert::AreEqual(input.out_num == 1666, true);
			Assert::AreEqual(input.select == 'c', true);
		}

		/* test: strategySelect() S */
		TEST_METHOD(TestMethod2)
		{
			Input input(argc, argv2);
			input.strategySelect();
			Assert::AreEqual(input.select == 's', true);
			Assert::AreEqual(strcmp("..\\UnitTest1\\unit_test1.txt", input.file_name), 0);
		}

		/* test: strategySelect() C */
		TEST_METHOD(TestMethod3)
		{
			argv1[1][1] = 'd';
			Input input(argc, argv1);
			Assert::AreEqual(input.select == '\0', true);
		}

		/* test: strategySelect() S */
		TEST_METHOD(TestMethod4)
		{
			argv2[1][0] = '/';
			Input input(argc, argv2);
			Assert::AreEqual(input.select == '\0', true);
		}

		/* test: strategySelect() S */
		TEST_METHOD(TestMethod5)
		{
			argv1[2][0] = '-';
			Input input(argc, argv1);
			Assert::AreEqual(input.select == '\0', true);
		}

		/* test: Sudoku Constructor*/
		TEST_METHOD(TestMethod6)
		{
			Input input(argc, argv1);
			input.strategySelect();
			Sudoku sudoku;
			Assert::AreEqual(sudoku.board_[1][1] == '2', true);
			Assert::AreEqual(sudoku.output_num_ == 0, true);
			Assert::AreEqual(sudoku.out_array_ == NULL, true);
		}

		/* test: readSudoku() S */
		TEST_METHOD(TestMethod7)
		{
			Input input(argc, argv2);
			input.strategySelect();
			Sudoku sudoku;
			sudoku.charArrayInit(1000000);
			fstream in_file("..\\UnitTest1\\unit_test1.txt", ios::in);
			bool read_file=sudoku.readSudoku(in_file);
			in_file.close();
			delete[] sudoku.out_array_;
			Assert::AreEqual(read_file == true, true);
			Assert::AreEqual(sudoku.board_[1][1] == '8', true);
		}

		/* test: ifSolveS() S */
		TEST_METHOD(TestMethod8)
		{
			Input input(argc, argv2);
			input.strategySelect();
			Sudoku sudoku;
			sudoku.charArrayInit(1000000);
			fstream in_file("..\\UnitTest1\\unit_test1.txt", ios::in);
			sudoku.readSudoku(in_file);
			in_file.close();
			bool solve = sudoku.ifSolveS(1, 1);
			delete[] sudoku.out_array_;
			Assert::AreEqual(solve == true, true);
		}

		/* test: straregyS() S */
		TEST_METHOD(TestMethod9)
		{
			Sudoku sudoku;
			sudoku.charArrayInit(1000000);
			sudoku.straregyS(argv2[2]);
			delete[] sudoku.out_array_;
			Assert::AreEqual(sudoku.board_[1][1] == '8', true);
		}

		/* test: straregyS() S */
		TEST_METHOD(TestMethod10)
		{
			Sudoku sudoku;
			sudoku.charArrayInit(1000000);
			sudoku.straregyS(argv2[2]);
			delete[] sudoku.out_array_;
			Assert::AreEqual(sudoku.num_row[8][1] == true, true);
			Assert::AreEqual(sudoku.num_col[8][1] == true, true);
			Assert::AreEqual(sudoku.num_box[8][1][1] == true, true);
		}

		/* test: intoOutArray() */
		TEST_METHOD(TestMethod11)
		{
			Sudoku sudoku;
			sudoku.charArrayInit(1);
			sudoku.intoOutArray();
			Assert::AreEqual(sudoku.out_array_[sudoku.out_array_pointer_ -1] == '\n', true);
			delete[] sudoku.out_array_;
		}

		/* test: strategyC() C */
		TEST_METHOD(TestMethod12)
		{
			Sudoku sudoku;
			sudoku.charArrayInit(1);
			sudoku.strategyC(1, 2);
			delete[] sudoku.out_array_;
			Assert::AreEqual(sudoku.num_ == 1, true);
		}

		/* test: outputCS() */
		TEST_METHOD(TestMethod13)
		{
			Sudoku sudoku;
			sudoku.charArrayInit(1);
			sudoku.strategyC(1, 2);
			sudoku.outputCS();
			delete[] sudoku.out_array_;
			Assert::AreEqual(sudoku.out_array_ == NULL, true);
		}
	};
}