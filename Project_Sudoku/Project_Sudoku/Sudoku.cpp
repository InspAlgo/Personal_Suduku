#include"stdafx.h"

#define NUMBER 9 //1~9��9����
using namespace std;

//9*9�Ĵ�Ź���ĳ�ʼ��
Sudoku::Sudoku()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			this->board[i][j] = '0';
	this->board[1][1] = 2 + '0';//��һ������[(ѧ�ź���λ���)%9+1]
	this->Num = 0;
	this->Output_Num = 0;
	this->select = '\0';
}

void Sudoku::charArray_init(int Output_Num, char Sel)
{
	this->Output_Num = Output_Num;
	this->select = Sel;
	this->OutArray = new char[163 * Output_Num + 5];
	this->OutArray_Pointer = 0;
	memset(OutArray, '\0', sizeof(OutArray));
}

void Sudoku::Output_CS()
{
	this->OutArray[this->OutArray_Pointer] = '\0';//���һ���վֲ��ÿ���
	this->OutArray[this->OutArray_Pointer - 1] = '\0';
	this->OutArray[this->OutArray_Pointer - 2] = '\0';
	fstream file;
	file.open("sudoku.txt", ios::out);
	file << this->OutArray;
	delete[] this->OutArray;
	file.close();
}

inline char* Sudoku::into_OutArray()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			this->OutArray[this->OutArray_Pointer++] = this->board[i][j];
			if (j != 9)
				this->OutArray[this->OutArray_Pointer++] = ' ';
		}
		this->OutArray[this->OutArray_Pointer++] = '\n';
	}
	this->OutArray[this->OutArray_Pointer++] = '\n';
	return NULL;
}

//�������-c�Ĳ���
void Sudoku::Strategy_C(int i, int j)
{
	if (this->Num >= this->Output_Num)//���ɵ������վ���Ŀ�ﵽҪ���򷵻�
		return;
	if (i == 9 && j == 10)//�������һ���վ�ʱ
	{
		this->Num++;
		this->into_OutArray();
			
		return;
	}

	if (i != 9 && j == 10)//���м���������
	{
		i++;
		j = 1;
	}

	for (int num = 1; num <= NUMBER; num++) //��������num
	{
		if (this->Num >= this->Output_Num)
			return;
		if (Check_C(num, i, j))
		{
			this->board[i][j] = num + '0';
			Strategy_C(i, j + 1);
		}
	}

	this->board[i][j] = '0';//����ʱ��ǰλ��Ҫ����Ϊ0
}

//�������-s�Ĳ���
void Sudoku::Straregy_S(Input input)
{
	
	fstream inFile(input.FileName, ios::in);
	if (!inFile.is_open())
		Error::ErrorTyepe(4);
	char cboard[10][10] = { '\0' };
	memset(cboard, '\0', sizeof(cboard));
	while (input.Get_Board(inFile,cboard))
	{
		memcpy(board, cboard, 100);
		if (ifSolve_S(1, 1))
			into_OutArray();
		else
		{
			cout << "�޽�" << endl;
		}
	}
	inFile.close();
}

bool Sudoku::ifSolve_S(int i, int j)
{
	if (i == 9 && j == 10)
		return true;

	if (i != 9 && j == 10)
	{
		i++;
		j = 1;
	}

	if (this->board[i][j] != '0')
		return ifSolve_S(i, j + 1);
	for (int num = 1; num <= NUMBER; num++)
	{
		if (Check_S(num, i, j))
		{
			this->board[i][j] = num + '0';
			bool OutCome = ifSolve_S(i, j + 1);
			if (OutCome)
				return true;
		}
	}

	this->board[i][j] = '0';
	return false;
}

//�Ƿ������������
bool Sudoku::Check_C(int num, int i, int j)
{
	//check row
	for (int a = 1; a < j; a++)
		if (this->board[i][a] == '0' + num)
			return false;
	//check col
	for (int a = 1; a < i; a++)
		if (this->board[a][j] == '0' + num)
			return false;
	//check 3*3 block
	int row = ((i - 1) / 3) * 3 + 1;
	int col = ((j - 1) / 3) * 3 + 1;

	for (int a = row; a <= i; a++)
	{
		for (int b = col; b <= col + 2; b++)
		{
			if (a == i && b == j)
				continue;
			if (this->board[a][b] == '0' + num)
				return false;
		}
	}
	return true;//�����򷵻�true
}

bool Sudoku::Check_S(int num, int i, int j)
{
	//check row
	for (int a = 1; a <= 9; a++)
		if (this->board[i][a] == '0' + num)
			return false;
	//check col
	for (int a = 1; a <= 9; a++)
		if (this->board[a][j] == '0' + num)
			return false;
	//check 3*3 block
	int row = ((i - 1) / 3) * 3 + 1;
	int col = ((j - 1) / 3) * 3 + 1;
	for (int a = row; a <= row + 2; a++)
	{
		for (int b = col; b <= col + 2; b++)
		{
			if (this->board[a][b] == num + '0')
				return false;
		}
	}
	return true;
}