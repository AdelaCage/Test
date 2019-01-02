#include <iostream>
#include <string.h>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal����" << endl;
    }
    virtual void speak() = 0;

//    virtual ~Animal()
//    {
//        cout << "Animal����" << endl;
//    }
    virtual ~Animal() = 0;//����Ǵ�������������Ҫ������ʵ�֣��������Ҳ�ǳ����࣬����ʵ����
};
Animal::~Animal()
{
    cout << "Animal����" << endl;
}

class Cat:public Animal
{
public:
    Cat(const char* name)
    {
        cout << "Cat����" << endl;
        m_Name = new char[strlen(name)+1];
        strcpy(m_Name, name);
    }

    ~Cat()
    {
        cout << "Cat����" << endl;
        if(nullptr != m_Name)
            delete [] m_Name;
        m_Name = nullptr;
    }

    virtual void speak()
    {
        cout << "è��������" << endl;
    }

private:
    char* m_Name;
};

void test()
{
    Animal* cat = new Cat("pussy");
    cat->speak();

    delete cat;
}

int main()
{
    test();
    return 0;
}
