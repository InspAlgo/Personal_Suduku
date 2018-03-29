#pragma once
#include"stdafx.h"
using namespace std;
class Input
{
private:
	int argc_;
	char** argv_;
public:
	Input(int argc, char** argv);
	void strategySelect();
	bool copyNewBoard(fstream &file, char board[][10]);
	char select;
	char* file_name;
	int out_num;
};