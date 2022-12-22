#pragma once
#include "STEK.h"
#include "TRecord.h"
#include "TTable.h"
#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

class Poliz
{
public:
	Poliz(string tmp = "") {
		size = tmp.length();
		count = 0;
		mem = new string[size];
		lex = new string[size];
		size_lex = size;
		StringToWorld(lex, tmp, "+-*/^() ", count_lex);
		MadeTableOperation();
		Opstack = STEK<TRecord>(20);
		Made_Poliz(tmp);
	}
	Poliz(const Poliz& tmp) {
		size = tmp.size;
		count = tmp.count;
		mem = new string[size];
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		lex = new string[size];
		Table_operation = tmp.Table_operation;
		Opstack = tmp.Opstack;
		Table_operand = tmp.Table_operand;
	}
	~Poliz() {
		delete[] mem;
		delete[] lex;
		delete Table_operand;
	}
	Poliz& operator=(Poliz tmp) {
		if (size != tmp.size) {
			if (size != 0) {
				delete[] mem;
			}
			
			size = tmp.size;
			mem = new string[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		lex = new string[size];
		Table_operation = tmp.Table_operation;
		Opstack = tmp.Opstack;
		Table_operand = tmp.Table_operand;
		return *this;
	}
	int getCount() {
		return count;
	}
	string operator[](int k) {
		if ((k >= 0) && (k < count)) {
			return mem[k];
		}
		else {
			return " ";
		}
	}
	string getPoliz() {
		string str = "";
		for (int i = 0; i < count; i++) {
			str = str + mem[i] + " ";
		}
		return str;
	}
	SpreadSheet* geSpreadSheetOperand() {
		return Table_operand;
	}
private:
	string* mem;
	int size;
	int count;
	string* lex;
	int size_lex;
	int count_lex;

	STEK<TRecord> Opstack;
	SpreadSheet Table_operation;
	SpreadSheet* Table_operand;

	void MadeTableOperation() {
		Table_operation = SpreadSheet(6);
		Table_operation.Add(TRecord("+", 1));
		Table_operation.Add(TRecord("-", 1));
		Table_operation.Add(TRecord("*", 2));
		Table_operation.Add(TRecord("/", 2));
		Table_operation.Add(TRecord("^", 3));
	}

	void Work_Left() {
		if (Opstack.isFull() == 0) {
			Opstack.add(TRecord("(", 0));

		}
	}

	void Work_Right() {
		while ((Opstack.isEmpty() == 0) && (Opstack.top().getname() != "("))
		{
			mem[count++] = Opstack.get().getname();
		}
	}

	void Work_Operation(string str, int pr) {
		while (Opstack.isEmpty()==0 &&(Opstack.top().getvalue()>=pr)) {
			mem[count++] = Opstack.get().getname();
		}
		Opstack.add(TRecord(str,pr));
	}

	void Work_Operand(string st) {
		mem[count++] = st;
		if ((st[0] >= '0') && (st[0] <= '9'))
		{
			Table_operand->Add(TRecord(st, atoi(st.c_str()))); // надо добавить как перевести из str в int 
		}
		else {
			Table_operand->Add(TRecord(st, 0));
		}
	}

	void Work_End() {// конец строки
		while (Opstack.isEmpty() == 0) {
			mem[count++] = Opstack.get().getname();
		}
	}

	void Made_Poliz(string& tmp)
	{
		string* lex;
		lex = new string[tmp.size() + 2];
		int k = 0;
		StringToWorld(lex, tmp, "+-*/^)( ", k);
		count = 0;
		for (int i = 0; i <= k; i++)
		{
			if (lex[i] == "(") {
				Work_Left;
			}
			else if (lex[i] == ")")
			{
				Work_Right();
			}
			else {
				int l = Table_operand->getNumber(lex[i]);
				if (l != -1)
				{
					WorkOperation(TRecord(lex[i], Table_operand->Search(lex[i])));
				}
				else
				{
					WorkOperand(lex[i]);
				}
			}
			OPstack.getData();
			cout << endl;
		}
		WorkEnd();
	}

	/*void Made_Poliz(string str) {
		count = 0;
		for (int i = 0; i <lex->length(); i++) {
			if (lex[i] == "(") {
				Work_Left();
			}
			else if(lex[i]=="0") {
				Work_Right();
			}
			else {
				int l = Table_operation.Search(lex[i]);
				if (l > 0 && l <= 3) {
					Work_Operation(lex[i], l);
				}
				else {
					Work_Operand(lex[i]);
				}
			}
		}
		Work_End();
	}*/

	void StringToWorld(string* w, string st, string zn, int& k) {
		int L;
		for (int i = 0; i < int(st.size()); i++) {
			L = zn.find(st[i]);
			if ((L <= 0) && (L >= zn.size())) {
				w[k] += st[i];
			}
			else {
				if (st[i] != ' ') {
					if (w[k] != "") {
						w[++k] = st[i];

					}
					else {
						w[k] = st[i];
					}
					w[++k] = "";
				}
			}
		}
	}

};
