#include"stdafx.h"

using namespace std;

Input::Input(int argc, char** argv)
{
	this->argc_ = argc;
	this->argv_ = argv;
}

void Input::strategySelect()
{
	if (this->argc_ != 3)
	{
		cout << "Error: ������������" << endl;
		exit(-1);
	}

	if (this->argv_[1][0] == '-' && this->argv_[1][1] == 'c'
		&& strlen(this->argv_[1]) == 2)
	{
		this->select = 'c';
		regex reg_pattern("^\\+?[1-9][0-9]*$");  // ��֤�����������
		if (regex_match(this->argv_[2], reg_pattern))
			this->out_num = atoi(this->argv_[2]);
		else
		{
			cout << "Error: ���������Ĳ�������" << endl;
			exit(-1);
		}

	}
	else if (this->argv_[1][0] == '-' && this->argv_[1][1] == 's' 
		&& strlen(this->argv_[1]) == 2)
	{
		this->select = 's';
		this->file_name = this->argv_[2];
	}
	else
	{
		cout << "Error: ��ʹ����ȷ�Ĳ������" << endl;
		exit(-1);
	}
}

bool Input::copyNewBoard(fstream &file, char cboard[][10])
{
	string s;
	for (int i = 1; i <= 9; i++)
	{
		if (!getline(file, s))
			return false;
		for (int k = 0, j = 1; k <= 16; k += 2, j++)
			cboard[i][j] = s[k];
	}
	getline(file, s);
	return true;
}