#include <iostream>

using namespace std;

namespace LOL {
    int WuKong = 10;
}

void test()
{
    int WuKong = 20;

    //using ����
    //using LOL::WuKong;

    //using ���룬ֻ�򿪿ռ䣬4.5����ֲ���Χ�ڻ��� sunwukongID ,ʹ�þֲ���ID
    //������򿪶�����䣬��ôҲҪע�����������
    using namespace LOL;

    cout << WuKong << endl;//�ͽ�ԭ��,��ʹ��using����ʱ��test��������������WuKong�����ֶ�����
    cout << LOL::WuKong << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
