#include <iostream>

using namespace std;

int a = 10;

namespace A {
namespace B {
    int a = 30;
}
}

namespace A {
namespace B {
    int b = 40;
}
}

namespace  {
    int c;
}

//���������
namespace nick = A::B;
int main()
{
    int a = 20;
    cout << a << endl;
    cout << ::a << endl;//˫ð��Ϊȫ��������
    cout << A::B::a << "\t" << nick::b << endl;//namespace����Ƕ��,�ҿ�����ʱ�����µĳ�Ա,���������
    cout << c << endl;//����namespace�ĳ�ԱΪstatic
    return 0;
}
