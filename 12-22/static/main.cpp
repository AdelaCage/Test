#include <iostream>

using namespace std;

int& doWork2()
{
    static int a = 10;
    return a;
}
void test05()
{

    int &ret = doWork2();

    //��������ķ���ֵ�����ã���ô����������ÿ�����Ϊ��ֵ

    doWork2() = 1000; //�൱��д�� a = 1000;

    cout << ret <<endl;

}


void test01()
{
    //int &ref = 10;//�����˲��Ϸ����ڴ棬������
    const int &ref = 10; //����const�� ������������ʽΪ�� int tmp = 10; const int &ref = tmp;

    //ref = 10;

    int * p = (int*)&ref;
    *p = 1000;

    cout << "ref = " << ref << endl;

}

const int constA = 10;
int main()
{
    int* p = (int*)&constA;
    *p = 200;
    printf("constA = %d, *p = %d", constA, *p);
}


int main1()
{
    test01();
    return 0;
}
