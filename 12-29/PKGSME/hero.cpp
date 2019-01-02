#include "hero.h"

Hero::Hero()
{
    m_Name = "������";
    m_Atk = 50;
    m_Def = 50;
    m_Hp = 500;
    weapon = nullptr;
}

void Hero::equipWeapon(Weapon *wp)
{
    this->weapon = wp;
    cout << "Ӣ�� " << m_Name << " װ���� " << this->weapon->weaponName << endl;
}

void Hero::Attack(Monster* mt)
{
    int damage = 0;
    int addHp = 0;
    bool isHold = false;
    bool isCrit = false;
    if(this->weapon == nullptr)
    {
        damage = this->m_Atk;
    }
    else
    {
        damage = this->m_Atk + this->weapon->getBaseDamage();
        addHp = this->weapon->suckBlood();
        isHold = this->weapon->freeze();
        isCrit = this->weapon->getCrit();
    }
    if(isCrit)
    {
        damage *= 2;
        cout << "��������,��� " << damage << " ���˺�";
    }
    if(isHold)
    {
        cout << "��������������ֹͣ����һ�غ�" << endl;
    }
    if(addHp>0)
    {
        cout << "������Ѫ���ָ� " << addHp << " ��Ѫ��" << endl;
    }

    mt->m_Hold = isHold;
    int trueDamage = (damage-mt->m_Def>0)?(damage-mt->m_Def):1;
    mt->m_Hp -= trueDamage;
    this->m_Hp += addHp;
    cout << "Ӣ�� " << this->m_Name << " ������ " << mt->m_Name << " ,����� " << trueDamage << " ���˺�" << endl;
}
