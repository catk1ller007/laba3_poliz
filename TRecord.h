#pragma once
#include <iostream>
#include <string>

using namespace std;

class TRecord
{
public:
	TRecord(string _name = "", int _value = 0) {
		name = _name;
		value = _value;
	}
	void setvalue(int k) {
		value = k;
	}

	int getvalue() {
		return value;
	}
	string getname() {
		return name;
	}

private:
	string name;
	int value;
};
//���� - ������������ ���������, 
//������� ��������� ���������� ����������� ���������� ����� � ��������, �� �������� LIFO
