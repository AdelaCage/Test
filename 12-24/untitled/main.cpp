#include <iostream>

/*
 * ����ģʽ
 */

using namespace std;

class Chairman
{
public:
    static Chairman* getInstance()
    {
        return singMan;
    }
private:
    Chairman()
    {
        cout << "������ϯ" << endl;
    }
    Chairman(const Chairman&c){}
    static Chairman* singMan;
};
Chairman* Chairman::singMan = new Chairman;

void test()
{
    Chairman* cm = Chairman::getInstance();
    //Chairman* cm2 = new Chairman(*cm);
}

int main()
{
    test();
    cout << "Hello World!" << endl;
    return 0;
}
