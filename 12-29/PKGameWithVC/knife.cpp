#include "knife.h"


Knife::Knife()
{
    baseDamage = 0;
    weaponName = "ذ��";
}

int Knife::getBaseDamage()
{
    return baseDamage;
}

int Knife::suckBlood()
{
    return 0;
}

bool Knife::freeze()
{
    return false;
}

bool Knife::getCrit()
{
    return false;
}
