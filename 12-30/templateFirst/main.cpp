#include <iostream>

using namespace std;

template<class T>
void mySwap(T& m, T& n)
{
    T tmp = m;
    m = n;
    n = tmp;
}

template<class T>
void mySwap2()
{
}

void test()
{
    int a = 1;
    int b = 3;
    //�Զ������Ƶ�
    mySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    double c =2.3;
    double d = 5.0;
    //��ʽָ������
    mySwap<double>(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    mySwap2<double>();
}

int main()
{
    test();
    return 0;
}
