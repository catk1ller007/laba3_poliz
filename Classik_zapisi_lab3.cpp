#include "TRecord.h"
#include "TTable.h"
#include <string>
#include "Poliz_zapis.h"
#include "Arifmetica.h"

using namespace std;

int main()
{
    /*setlocale(LC_ALL, "Rus");

    int N = 5;

    TRecord recA("a", 3);
    TRecord recB("b", 2);

    SpreadSheet A(N);
    SpreadSheet B;

    A.Add(recA);
    A.Add(recB);

    B = A;

    for (int i = 0; i < A.getCount(); i++)
    {
        cout << A[i].getname() << " " << A[i].getvalue() << endl;
    }

    B.Add(TRecord("c", 5));

    for (int i = 0; i < B.getCount(); i++)
    {
        cout << B[i].getname() << " " << B[i].getvalue() << endl;
    }

    SpreadSheet C(A);

    for (int i = 0; i < C.getCount(); i++)
    {
        cout << C[i].getname() << " " << C[i].getvalue() << endl;
    }*/





    //Тестер стека
    /*int sizeA = 5, sizeB = 7;

    STEK<int> A(sizeA);
    STEK<int> B(sizeB);

    cout << "Стек пуст: " << endl;
    cout << "A = " << A.isEmpty() << endl;
    cout << "B = " << B.isEmpty() << endl << endl;

    for (int i = 0; !(A.isFull()); i++)
    {
        cout << i << " ";
        A.add(i);
    }
    cout << endl;

    cout << "Стек пуст: " << endl;
    cout << "A = " << A.isEmpty() << endl;
    cout << "B = " << B.isEmpty() << endl << endl;

    B = A;
    cout << "Стек В: " << endl;
    for (int i = 0; !(B.isEmpty()); i++)
    {
        cout << B.get() << " ";
    }
    cout << endl;

    cout << "Стек пуст: " << endl;
    cout << "A = " << A.isEmpty() << endl;
    cout << "B = " << B.isEmpty() << endl << endl;

    cout << "Стек полон: " << endl;
    cout << "A = " << A.isFull() << endl;
    cout << "B = " << B.isFull() << endl << endl;

    cout << "Top A: " << endl;
    cout << "A = " << A.top() << endl << endl;

    cout << "get(pop) A: " << endl;
    cout << "A = " << A.get() << endl << endl;

    cout << "Стек В: " << endl;
    while (A.isEmpty() != 1)
    {
        cout << A.get() << " ";
    }*/

    TArithmetic asd("a^(x*y/k-b^2)/(x^2+y^2)*b-25*a^2/b^2");
    cout << asd.getPoliz().getPoliz() << '\n';
    cout << asd.calculate() << endl;

    return 0;
}