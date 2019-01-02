#include<iostream>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream& cout, Person& p);

public:
    Person()
    {
        m_Num = 0;
    }

    //ǰ��++����
    Person& operator++()
    {
        this->m_Num++;
        return *this;
    }

    //����++ ����
    Person operator++(int)
    {
        //�ȱ���Ŀǰ����
        Person tmp = *this;
        m_Num++;
        return tmp;
    }
    int m_Num;
};

ostream& operator<<(ostream& cout, Person& p)
{
    cout << p.m_Num;
    return cout;
}

void test01()
{
    Person p;

    cout << ++(++p) << endl;
    cout << p << endl;
}

int main() {

    test01();

    system("pause");
    return EXIT_SUCCESS;
}
