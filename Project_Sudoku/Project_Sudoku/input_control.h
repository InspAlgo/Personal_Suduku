#pragma once
#include"stdafx.h"
using namespace std;
class Input
{
public:
	Input(int argc, char** argv);
	void strategySelect();
	char select;
	char* file_name;
	int out_num;

private:
	int argc_;
	char** argv_;
};