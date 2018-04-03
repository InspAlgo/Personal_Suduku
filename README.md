Personal_Suduku
===
软件工程基础课的个人项目作业。一款数独游戏的控制台程序，emmmmm，我知道数独英语是**sudoku**，上面那个**suduku**。。。请忽略谢谢！  

**项目博客：**  
[软件工程基础课-个人项目-数独](https://blog.csdn.net/qq_38597315/article/details/79633400)  
[软件工程基础课-个人项目纪实](https://blog.csdn.net/qq_38597315/article/details/79650763)

**文档目录：**
[TOC]
***
# 一、程序功能：
1. 生成不重复的数独终局至文件。
2. 读取文件内的数独问题，求解并将结果输出到文件。
## 1.1 生成终局
1. 在命令行中使用`-c`参数加数字N(1<=N<=1,000,000)控制生成数独终局的数量，例如下述命令将生成20个数独终局至文件中：  
  `sudoku.exe -c 20`
2. 将生成的数独终局用一个文本文件（假设名字叫sudoku.exe）的形式保存起来，每次生成的txt文件需要覆盖上次生成的txt文件，文件内的格式如下，数与数之间由空格分开，终局与终局空一行，行末无空格：  
	```
	2 6 8 4 7 3 9 5 1
	3 4 1 9 6 5 2 7 8
	7 9 5 8 1 2 3 6 4
	5 7 4 6 2 1 8 3 9
	1 3 9 5 4 8 6 2 7
	8 2 6 3 9 7 4 1 5
	9 1 7 2 8 6 5 4 3
	6 8 3 1 5 4 7 9 2
	4 5 2 7 3 9 1 8 6

	4 5 1 7 8 2 3 6 9
	7 8 6 4 9 3 5 2 1
	3 9 2 1 5 6 4 8 7
	5 2 7 6 4 9 8 1 3
	9 6 8 5 3 1 2 7 4
	1 3 4 2 7 8 6 9 5
	8 1 5 3 6 7 9 4 2
	6 7 3 9 2 4 1 5 8
	2 4 9 8 1 5 7 3 6

	9 5 8 3 6 7 1 2 4
	2 3 7 4 5 1 9 6 8
	1 4 6 9 2 8 3 5 7
	6 1 2 8 7 4 5 9 3
	5 7 3 6 1 9 4 8 2
	4 8 9 2 3 5 6 7 1
	7 2 4 5 9 3 8 1 6
	8 9 1 7 4 6 2 3 5
	3 6 5 1 8 2 7 4 9
	……
	```
3. 在生成数独矩阵时，左上角的第一个数为：(学号后两位）%9+1。例如学生A学号后2位是80，则该数字为(8+0)%9+1=9，那么生成的数独棋盘如下（x表示满足数独规则的任意数字）：
	```
	9 x x x x x x x x
	x x x x x x x x x
	x x x x x x x x x
	x x x x x x x x x
	x x x x x x x x x
	x x x x x x x x x
	x x x x x x x x x
	x x x x x x x x x
	x x x x x x x x x
	```
## 1.2 求解数独
1. 在命令行中使用`-s`参数加文件名的形式来求解数独，并将结果输出至文件，如：
  `sudoku.exe -s absolute_path_of_puzzlefile`  
程序将从路径中读取数独题目，并将数独题目的一个可行解输出至与sudoku.exe同目录的sudoku.txt中，输出格式与生成终局相同。
2. 数独题目格式如下，其中0代表空格，题目与题目之间空一行，行末无空格，最后一个数独题目后无空行：   
	```   
	9 0 8 0 6 0 1 2 4    
	2 3 7 4 5 1 9 6 8  
	1 4 6 0 2 0 3 5 7  
	0 1 2 0 7 0 5 9 3  
	0 7 3 0 1 0 4 8 2  
	4 8 0 0 0 5 6 0 1
	7 0 4 5 9 0 8 1 6
	8 9 0 7 4 6 2 0 0
	3 0 5 0 8 0 7 0 9

	9 0 0 8 0 0 4 0 0
	……
	```
3. 数独题目个数N(1<=N<=1,000,000)，保证文件中数独格式正确。
***
# 二、单元测试
## 2.1 总述
本程序的单元测试是使用VS自带的`本机单元测试项目`。

## 2.2 说明
由于类的私有成员及方法不易进行单元测试，所以在使用本单元测试文件时请将`Project_Sudoku`文件夹中`sudoku.h`里`Sudoku类`的`private`注释掉。
***