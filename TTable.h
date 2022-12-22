#pragma once
#include "TRecord.h"
// 1) Просматриваемые(неупорядоченные) таблицы.
//  Структура хранения - массива
//   Доп операция
//  5. Контроль полноты
// линиейные поис
// Т~О(size/2)
// 
// 2) Упорядоченные таблицы.    
//  Структура хранения - массива
//   Доп операция
//  5. Контроль полноты
// поиск бинарный
// Т~О(log2(size))
//
// 3) Хеш-таблица
//    Открытие пересмешивание
//   а) Структура хранение - массив
//  5. Контроль полноты
//   б) Использование списковой структуры
//
// 4) AVL-дерево
//


//  Операции в таблице
// 1. Положить
// 2. Удалить
// 3. По ключу выдать информацию
// 4. Контроль пустоты
// 5. контроль полноты
// 6. GetCount
// 7. []- перегружение скобочек
// 8. Поиск приват


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
			return 0; // Таблица пуста
		}
		else
		{
			return 1; // Таблица не пуста
		}
	}

	int IsFull()
	{
		if (count == size)
		{
			return 1; // Полна
		}
		else
		{
			return 0; // Не полна
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


