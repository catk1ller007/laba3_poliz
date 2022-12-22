#pragma once
#include "Poliz_zapis.h"
#include "STEK.h"

using namespace std;

class TArithmetic
{
private:
    string STR;
    Poliz poliz;

public:
    TArithmetic(string _STR = "")
    {
        STR = _STR;
        poliz = Poliz(STR);
    }

    TArithmetic(const TArithmetic& tmp)
    {
        STR = tmp.STR;
        poliz = tmp.poliz;
    }

    TArithmetic& operator=(TArithmetic tmp)
    {
        STR = tmp.STR;
        poliz = tmp.poliz;
        return *this;
    }

    ~TArithmetic() {}

    Poliz getPoliz()
    {
        return poliz;
    }

    int calculate()
    {
        STEK <double> stack(20);
        double right;
        double left;
        for (int i = 0; i < poliz.getCount(); i++)
        {
            int l = poliz.geSpreadSheetOperand()->getNumber(poliz[i]);

            if (l == -2) continue;

            if (l != -1)
            {
                double value = poliz.geSpreadSheetOperand()->Search(poliz[i]);
                stack.add(value);
            }
            else
            {
                right = stack.get();
                left = stack.get();
                if (poliz[i] == "+")
                {
                    stack.add(left + right);
                }
                if (poliz[i] == "-")
                {
                    stack.add(left - right);
                }
                if (poliz[i] == "*")
                {
                    stack.add(left * right);
                }
                if (poliz[i] == "/")
                {
                    stack.add(left / right);
                }
                if (poliz[i] == "^")
                {
                    stack.add(pow(left, right));
                }
            }
        }
        return stack.get();
    }
};