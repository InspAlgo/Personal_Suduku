#include"stdafx.h"

using namespace std;

/*Class Input start*/
Input::Input(int argc, char** argv)
{
	this->argc = argc;
	this->argv = argv;
}

void Input::Strategy_Select()
{
	if (this->argc != 3)
		Error::ErrorTyepe(1);
	string instr(this->argv[1]);
	if (instr == "-c" || instr == "-C")
		this->Select = 'c';
	else if (instr == "-s" || instr == "-S")
		this->Select = 's';
	else
		Error::ErrorTyepe(2);

	if (this->Select == 'c')
	{
		regex Re("^\\+?[1-9][0-9]*$");//验证非零的正整数
		smatch m;
		string num(this->argv[2]);
		if (regex_match(num, m, Re))
		{
			stringstream ss;//#include<sstream>
			ss << num;
			ss >> this->OutNum;
		}
		else
			Error::ErrorTyepe(3);
	}
	else if (this->Select == 's')
	{
		this->FileName = this->argv[2];
	}

}
bool Input::Get_Board(fstream &file, char cboard[][10])
{
	regex Re("^(\\d\\s){8}\\d$");
	smatch m;
	string s;
	for (int i = 1; i <= 9; i++)
	{
		if (!getline(file, s))
			return false;
		if (!regex_match(s, m, Re))
		{
			file.close();
			Error::ErrorTyepe(5);
		}
		int j = 1;
		for (int k = 0; (unsigned)k < s.length(); k++)
		{
			if (!isspace(s[k]))
			{
				cboard[i][j] = s[k];
				j++;
			}
		}
	}
	getline(file, s);
	return true;
}
/*Class Input end*/

/*Class Error start*/
Error::Error()
{

}

void Error::ErrorTyepe(int Type)
{
	switch (Type)
	{
	case 1:
		cout << "Error: 参数错误！" << endl;
		break;
	case 2:
		cout << "Error: bad instruction.expect -c/-C or -s/-S" << endl;
		break;
	case 3:
		cout << "Error: bad number of instruction -c" << endl;
		break;
	case 4:
		cout << "Error: 文件名错误！" << endl;
		break;
	case 5:
		cout << "Error: 文件格式错误！" << endl;
		break;
	case 7:
		cout << "Error: bad generating of sudoku" << endl;
		break;
	}
	exit(-1);
}
/*Class Error end*/