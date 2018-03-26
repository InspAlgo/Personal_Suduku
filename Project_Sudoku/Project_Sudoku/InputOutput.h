#pragma once
#include"stdafx.h"
using namespace std;
class Input
{
private:
	int argc;
	char** argv;
public:
	Input(int argc, char** argv);
	void Strategy_Select();
	bool Get_Board(fstream &file, char board[][10]);
	char Select;
	char* FileName;
	int OutNum;
};

class Error
{
public:
	Error();
	static void ErrorTyepe(int Type);
};