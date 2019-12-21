#include"calcul.h"


void TCalculator::SetExpr(std::string _expr)
{
	expr = _expr;
}

std::string TCalculator::GetExpr()
{
	return expr;
}

std::string TCalculator::GetPostfix()
{
	return postfix;
}

bool TCalculator::CheckBrackets()
{
	st_c.ClearSt();
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(')
			st_c.Push('(');
		if (expr[i] == ')')
		{
			if (st_c.IsEmpty()) return false;
			else st_c.Pop();
		}
	}
	if (st_c.IsEmpty()) return true;
	else return false;
}

int TCalculator::Prior(char c)
{
	if (c == '(') return 0;
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
}

void TCalculator::ToPosfix()
{
	std::string str = "(";
	str += expr;
	str += ")";
	st_c.ClearSt();
	postfix = " ";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') continue;
		if (str[i] == '(') st_c.Push('(');
		if (str[i] == 'c' || str[i] == 's')
		{
			st_c.Push(str[i]);
			i = i + 2;
		}
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') postfix += str[i];
		if (str[i] == ')')
		{
			char tmp = st_c.Pop();
			while (tmp != '(')
			{
				postfix += ' ';
				postfix += tmp;
				tmp = st_c.Pop();
			}
			if (!st_c.IsEmpty())
			{
				tmp = st_c.Pop();
				if (tmp == 'c' || tmp == 's') {
					postfix += ' ';
					postfix += tmp;
				}
				else {
					st_c.Push(tmp);
				}
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			postfix += ' ';
			char tmp = st_c.Pop();
			while (Prior(str[i]) <= Prior(tmp))
			{

				postfix += tmp;
				tmp = st_c.Pop();
			}

			st_c.Push(tmp);
			st_c.Push(str[i]);
		}

	}
}

double TCalculator::Calc()
{
	st_d.ClearSt();
	double rez;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == ' ') continue;
		if (postfix[i] >= '0'&& postfix[i] <= '9')
		{
			char*tmp;
			double d = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			st_d.Push(d);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			double op1, op2;
			op2 = st_d.Pop();
			op1 = st_d.Pop();
			if (postfix[i] == '+')
			{
				rez = op1 + op2;
			}
			if (postfix[i] == '-')
			{
				rez = op1 - op2;
			}
			if (postfix[i] == '*')
			{
				rez = op1 * op2;
			}
			if (postfix[i] == '/')
			{
				rez = op1 / op2;
			}
			if (postfix[i] == '^')
			{
				rez = pow(op1, op2);
			}
			st_d.Push(rez);
		}
		if (postfix[i] == 's') {
			double op = st_d.Pop();
			rez = sin(op);
			st_d.Push(rez);
		}
		if (postfix[i] == 'c') {
			double op = st_d.Pop();
			rez = cos(op);
			st_d.Push(rez);
		}
	}
	rez = st_d.Pop();
	return rez;
}
