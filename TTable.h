#pragma once
#include "TRecord.h"
// 1) ���������������(���������������) �������.
//  ��������� �������� - �������
//   ��� ��������
//  5. �������� �������
// ��������� ����
// �~�(size/2)
// 
// 2) ������������� �������.    
//  ��������� �������� - �������
//   ��� ��������
//  5. �������� �������
// ����� ��������
// �~�(log2(size))
//
// 3) ���-�������
//    �������� ��������������
//   �) ��������� �������� - ������
//  5. �������� �������
//   �) ������������� ��������� ���������
//
// 4) AVL-������
//


//  �������� � �������
// 1. ��������
// 2. �������
// 3. �� ����� ������ ����������
// 4. �������� �������
// 5. �������� �������
// 6. GetCount
// 7. []- ������������ ��������
// 8. ����� ������


class SpreadSheet
{
private:
	TRecord* mem;
	int count;
	int size;

public:

	int getNumber(string key)
	{
		int l = -1;
		int i = 0;
		while ((l == -1) && (i < count))
		{
			if (key == mem[i].getname())
			{
				l = i;
			}

			i++;
		}
		return l;
	}

	SpreadSheet(int _size = 0)
	{
		size = _size;
		count = 0;

		mem = new TRecord[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = TRecord("", 0);
		}
	}

	SpreadSheet(const SpreadSheet& tmp)
	{
		size = tmp.size;
		count = tmp.count;

		mem = new TRecord[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	~SpreadSheet()
	{
		if (size != 0)
		{
			delete[] mem;
		}
	}

	SpreadSheet& operator=(const SpreadSheet& tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[] mem;
			}
			size = tmp.size;
			mem = new TRecord[size];
		}

		count = tmp.count;

		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}

		return *this;
	}

	void Add(TRecord tmp)
	{
		int l = getNumber(tmp.getname());
		if (l == -1)
		{
			mem[count++] = tmp;
		}
		else
		{
			mem[l] = tmp;
		}
	}

	void Del(TRecord tmp)
	{
		int l = getNumber(tmp.getname());
		if (l > 0)
		{
			mem[l] = mem[--count];
		}
	}

	int Search(string key)
	{
		int l = getNumber(key);
		if (l >= 0)
		{
			return mem[l].getvalue();
		}
		else
		{
			return -1;
		}
	}

	int IsEmpty()
	{
		if (count == 0)
		{
			return 0; // ������� �����
		}
		else
		{
			return 1; // ������� �� �����
		}
	}

	int IsFull()
	{
		if (count == size)
		{
			return 1; // �����
		}
		else
		{
			return 0; // �� �����
		}
	}

	int getCount()
	{
		return count;
	}

	TRecord operator[](int k)
	{
		if (k >= 0 && k < count)
		{
			return mem[k];
		}
		else
		{
			return TRecord("", 0);
		}
	}
};


