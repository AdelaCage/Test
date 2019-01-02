#include "circle.h"
#include <iostream>

using namespace std;

void Circle::setCenter(Point p)
{
    m_C = p;
}

void Circle::setR(int r)
{
    m_R = r;
}

int &Circle::getR()
{
    return m_R;
}

void Circle::isInCircle(Point p)
{
    int dd = (getCenter().getX()-p.getX())*(getCenter().getX()-p.getX()) + (getCenter().getY()-p.getY())*(getCenter().getY()-p.getY());
    int rr = getR()*getR();
    if(dd == rr)
    {
        cout << "��Բ��" << endl;
    }
    else if (dd < rr)
    {
        cout << "��Բ��" << endl;
    }
    else
    {
        cout << "��Բ��" << endl;
    }
}

Point& Circle::getCenter()
{
    return m_C;
}
