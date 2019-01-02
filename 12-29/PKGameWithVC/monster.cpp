#include "monster.h"

Monster::Monster()
{
    this->m_Hp = 300;
    this->m_Atk = 70;
    this->m_Def = 40;
    this->m_Hold = false;
    this->m_Name = "�ȿ˴�ħ��";
}

void Monster::Attack(Hero* hr)
{
    if(this->m_Hold)
    {
        cout << "���� " << this->m_Name << " ���������غ��޷�����" << endl;
        return;
    }

    int trueDamage = (this->m_Atk-hr->m_Def>0)?(this->m_Atk-hr->m_Def):1;
    hr->m_Hp -= trueDamage;
    cout << "���� " << this->m_Name << " ������ " << hr->m_Name << " ,����� " << trueDamage << " ���˺�" << endl;
}
