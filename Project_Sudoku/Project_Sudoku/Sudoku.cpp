#include"stdafx.h"

#define NUMBER 9  // 1~9的9个数
using namespace std;

Sudoku::Sudoku()
{
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
		{
			this->board_[i][j] = '0';
			this->num_row[i][j] = true;
			this->num_col[i][j] = true;
			for (int k = 0; k <= 9; k++)
				this->num_box[i][j][k] = true;
		}
	this->num_row[2][1] = false;
	this->num_col[2][1] = false;
	this->num_box[2][1][1] = false;
	this->board_[1][1] = 2 + '0';  // 第一个数是[(学号后两位相加)%9+1]
	this->num_ = 0;
	this->output_num_ = 0;
	this->out_array_pointer_ = 0;
	this->out_array_ = NULL;       // 没有new对象
}

void Sudoku::charArrayInit(int Output_Num)
{
	this->output_num_ = Output_Num;
	this->out_array_ = new char[163 * Output_Num + 5];
	memset(out_array_, '\0', sizeof(out_array_));
}

void Sudoku::outputCS()
{
	this->out_array_[this->out_array_pointer_] = '\0';  // 最后一个终局不用空行
	this->out_array_[this->out_array_pointer_ - 1] = '\0';
	this->out_array_[this->out_array_pointer_ - 2] = '\0';

	fstream file;
	file.open("sudoku.txt", ios::out);
	file << this->out_array_;
	delete[] this->out_array_;
	file.close();
}

void Sudoku::intoOutArray()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			this->out_array_[this->out_array_pointer_++] = this->board_[i][j];
			this->out_array_[this->out_array_pointer_++] = ' ';
		}
		this->out_array_[this->out_array_pointer_++] = this->board_[i][9];
		this->out_array_[this->out_array_pointer_++] = '\n';
	}
	this->out_array_[this->out_array_pointer_++] = '\n';
}

void Sudoku::strategyC(int i, int j)
{
	if (this->num_ >= this->output_num_)
		return;
	if (i == 9 && j == 10)  // 当完成了一个新终局时
	{
		this->num_++;
		this->intoOutArray();
			
		return;
	}

	if (i != 9 && j == 10)
	{
		i++;
		j = 1;
	}

	int row = ((i - 1) / 3) * 3 + 1;
	int col = ((j - 1) / 3) * 3 + 1;
	for (int num = 1; num <= NUMBER; num++)  // 填入数字num
	{
		if (this->num_ >= this->output_num_)
			return;

		if (this->num_row[num][i] == true
			&& this->num_col[num][j] == true
			&& this->num_box[num][row][col] == true)
		{
			this->board_[i][j] = num + '0';
			this->num_row[num][i] = false;
			this->num_col[num][j] = false;
			this->num_box[num][row][col] = false;

			strategyC(i, j + 1);

			this->num_row[num][i] = true;
			this->num_col[num][j] = true;
			this->num_box[num][row][col] = true;
		}

	}
	this->board_[i][j] = '0';  // 回溯时当前位又要重置为0
}

void Sudoku::straregyS(Input input)
{
	fstream read_file(input.file_name, ios::in);
	if (!read_file.is_open())
	{
		cout << "Error: 打开文件错误！" << endl;
		exit(-1);
	}
	string s;
	int num = 0;
	while (true)
	{
		memset(board_, '0', sizeof(board_));
		memset(num_row, true, sizeof(num_row));
		memset(num_col, true, sizeof(num_col));
		memset(num_box, true, sizeof(num_box));
		for (int i = 1; i <= 9; i++)
		{
			if (!getline(read_file, s))
			{
				read_file.close();
				return;
			}

			for (int k = 0, j = 1; k <= 16; k += 2, j++)
			{
				num = s[k] - '0';
				this->board_[i][j] = s[k];
				this->num_row[num][i] = false;
				this->num_col[num][j] = false;
				this->num_box[num][i][j] = false;
			}
		}
		getline(read_file, s);

		if (ifSolveS(1, 1))
		{
			intoOutArray();
		}	
		else
			cout << "无解！" << endl;
	}

	read_file.close();
}

bool Sudoku::ifSolveS(int i, int j)
{
	if (i == 9 && j == 10)
		return true;

	if (i != 9 && j == 10)
	{
		i++;
		j = 1;
	}

	if (this->board_[i][j] != '0')
		return ifSolveS(i, j + 1);

	int row = ((i - 1) / 3) * 3 + 1;
	int col = ((j - 1) / 3) * 3 + 1;
	for (int num = 1; num <= NUMBER; num++)
	{
		if (this->num_row[num][i] == true
			&& this->num_col[num][j] == true
			&& this->num_box[num][row][col] == true)
		{
			this->board_[i][j] = num + '0';
			this->num_row[num][i] = false;
			this->num_col[num][j] = false;
			this->num_box[num][row][col] = false;

			bool out_come = ifSolveS(i, j + 1);

			if (out_come)
				return true;
			this->num_row[num][i] = true;
			this->num_col[num][j] = true;
			this->num_box[num][row][col] = true;
		}
	}

	this->board_[i][j] = '0';
	return false;
}