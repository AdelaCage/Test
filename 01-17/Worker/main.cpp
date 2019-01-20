#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

enum {Renli, Yanfa, Meigong};

class Worker
{
public:
    int m_Salary;
    string m_name;
};

void CreateWorker(vector<Worker>& v)
{
    string nameSeed = "ABCDE";
    for (int i=0; i<5; ++i)
    {
        string name = string("Ա��") + nameSeed[i];
        int salary = rand()%10000 + 10001;

        Worker w;
        w.m_name = name;
        w.m_Salary = salary;
        v.push_back(w);
    }
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
    for (vector<Worker>::iterator it=v.begin(); it!=v.end(); ++it)
    {
        int type = rand() % 3;
        m.insert(make_pair(type, *it));
    }
}

void showGroup(multimap<int, Worker>& m)
{
    cout << "����������Ա����:" << endl;
    for (multimap<int, Worker>::iterator it=m.find(Renli); it!=m.find(Yanfa); ++it)
    {
        cout << "����: " << it->second.m_name << "\t����: " << it->second.m_Salary << endl;
    }

    cout << "-------------------------" << endl;
    cout << "�з�������Ա����:" << endl;
    for (multimap<int, Worker>::iterator it=m.find(Yanfa); it!=m.find(Meigong); ++it)
    {
        cout << "����: " << it->second.m_name << "\t����: " << it->second.m_Salary << endl;
    }

    cout << "-------------------------" << endl;
    cout << "����������Ա����:" << endl;
    for (multimap<int, Worker>::iterator it=m.find(Meigong); it!=m.end(); ++it)
    {
        cout << "����: " << it->second.m_name << "\t����: " << it->second.m_Salary << endl;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<Worker> v;
    CreateWorker(v);

//    for (vector<Worker>::iterator it=v.begin(); it!=v.end(); ++it)
//    {
//        cout << it->m_name << "\t" << it->m_Salary << endl;
//    }

    multimap<int ,Worker> m;
    setGroup(v, m);

    showGroup(m);


    return 0;
}
