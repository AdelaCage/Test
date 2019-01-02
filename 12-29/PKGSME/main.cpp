#include <iostream>
#include <string>
#include "hero.h"
#include "weapon.h""
#include "monster.h"
#include "knife.h"
#include "dargonword.h"
#include <ctime>

using namespace std;

void play()
{
	Hero* hua = new Hero;
	Monster* zz = new Monster;

	Weapon* knife = new Knife;
	Weapon* dargonW = new DargonWord;

	cout << "��ѡ������:" << endl;
	cout << "1.���ֿ�ȭ" << endl;
	cout << "2.ذ��" << endl;
	cout << "3.��������" << endl;

	int oper;
	cin >> oper;
	switch (oper) {
	case 1:
		cout << "��ѡ���� " << "1.���ֿ�ȭ" << endl;
		break;
	case 2:
		cout << "��ѡ���� " << "2.ذ��" << endl;
		hua->equipWeapon(knife);
		break;
	case 3:
		hua->equipWeapon(dargonW);
		cout << "��ѡ���� " << "3.��������" << endl;
		break;
	}
	getchar();


	int round = 1;
	while (true) {
		getchar();
		system("cls");
		cout << "��" << round << "�غ�" << endl;
		hua->Attack(zz);
		if (zz->m_Hp <= 0)
		{
			cout << "������������Ϸʤ��" << endl;
			break;
		}
		zz->Attack(hua);
		if (hua->m_Hp <= 0)
		{
			cout << "Ӣ����������Ϸ����" << endl;
			break;
		}

		cout << "���ֽ���" << endl;
		cout << "Ӣ��ʣ��Ѫ����" << hua->m_Hp << endl;
		cout << "����ʣ��Ѫ����" << zz->m_Hp << endl;
		++round;
	}

	delete hua;
	delete zz;
	delete knife;
	delete dargonW;

}

int main()
{
	srand((unsigned int)time(NULL));
	play();
	return 0;   
}
