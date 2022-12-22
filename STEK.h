#pragma once
#include <string>
using namespace std;

template<typename T>
class STEK
{
public:
	STEK(int _size = 0) {
		size = _size;
		count = 0;
		mem = new T[size];
		for (int i = 0; i < size; i++) {
			mem[i] = T(0);
		}
	}
	STEK(const STEK& tmp) {
		size = tmp.size;
		count = tmp.count;
		mem = new T[size];
		for (int i = 0; i < size; i++) {
			mem[i] = tmp.mem[i];
		}
	}
	~STEK() {
		if (size != 0) {
			delete[]mem;
		}
	}
	STEK<T>& operator=(const STEK<T>& tmp)
	{
		if (size!=tmp.size) {
			if (size != 0) {
				delete[]mem;
			}
			size = tmp.size;
			mem = new T[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		return *this;
	}
	int getsize() const noexcept{
		return size;
	}
	void add(T tmp) {
		if (count < size) {
			{
				mem[count++] = tmp;
			}
		}
	}

	T get() {
		if (count > 0) {
			return mem[--count];
		}
	}

	T top() {
		if (count > 0) {
			return mem[count - 1];
		}
	}

	int isEmpty() {
		if (count == 0) {
			return 1;//���� ����
		}
		else {
			return 0;//���� �� ����
		}
	}

	int isFull() {
		if (count == size) {
			return 1; //���� �����
		}
		else {
			return 0; //���� �� �����
		}
	}

private:
	T* mem;
	int size;
	int count;
};


// �������-������������ ���������, � �������
// ������ ��������� ����������, ������ ���� ������������ ��������� ����� ���
// ��������
// ������ �������=�����
// ������� ������������� ������� �������� � �������
// ���� ������� �����(����� ����������� � ������������), ���� � ��������������� �� ����������� 
//