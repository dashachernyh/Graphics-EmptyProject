#pragma once
#include"stack.h"
#include<string>
#include<cmath>

class TCalculator
{
	std::string expr, postfix;
	TStack<char> st_c;
	TStack<double>st_d;
	int Prior(char c); //функция
public:
	TCalculator() :st_c(50) {}
	void SetExpr(std::string _expr);
	std::string GetExpr();
	std::string GetPostfix();
	bool CheckBrackets();
	void ToPosfix();
	double Calc();
};

