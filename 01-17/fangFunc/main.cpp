#include <iostream>

using namespace std;

class MyPrint
{
public:
    void operator()(int num)
    {
        cout << "��ӡ" << num << endl;
        ++m_Num;
    }
    int m_Num = 0;
};

void DoPrint(MyPrint print, int num)
{
    print(num);
}

void test01()
{
    MyPrint myprint1;
    myprint1(1);
    myprint1(2);
    myprint1(3);
    cout << "myprint1ʹ����" << myprint1.m_Num << "��" << endl;
    MyPrint()(111);
    MyPrint()(222);
    cout << "��������ʹ����" << MyPrint().m_Num << "��" << endl;

    DoPrint(MyPrint(),12345);
}

int main()
{
    test01();
    return 0;
}
