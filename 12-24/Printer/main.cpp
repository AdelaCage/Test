#include <iostream>

using namespace std;

class Printer
{
private:
    Printer():count(0){}
    Printer(const Printer&p){}

public:
    static Printer* getPrinter()
    {
        return singPrinter;
    }
    void printText(string text)
    {
        cout << text << endl;
        ++count;
        cout << "��ʹ�ô�ӡ��" << count << "��" << endl;
    }

private:
    static Printer* singPrinter;
    int count;
};
Printer* Printer::singPrinter = new Printer;

void test()
{
    Printer* p = Printer::getPrinter();
    p->printText("ӦƸ����");
    p->printText("��ְ����");
    p->printText("��ְ����");
}

int main()
{
    test();

    return 0;
}
