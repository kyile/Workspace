//�ڴ���

#include "Account.h"
#include "AccountHandler.h"
//#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "NomalAccount.h"

AccountHandler::AccountHandler() :cnt(0), i(0)					//������//����̴ϼȶ����� 
{}
void AccountHandler::ShowMenu()				//�޴�
{
	cout << endl << "------------Menu-----------";
	cout << endl << "1. ���� ����";
	cout << endl << "2. ��   ��";
	cout << endl << "3. ��   ��";
	cout << endl << "4. ��ü�� �ܾ���ȸ";
	cout << endl << "5. ���α׷� ����";
	cout << endl << "����: ";

}
void AccountHandler::AccountChoice()								//���¼���//�ϴٰ���
{
	int num = 0;

	cout << "[���� ���� ����]" << endl;
	cout << "1. ���뿹�ݰ���" << " 2. �ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> num;

	if (num > 3)
	{
		cout << "���ù����� ������ϴ�. " << endl;
	}
	switch (num)
	{
	case 1:			//���뿹�ݰ���
	{ AccountHandler::MakeNomalAccount(); break; }
	case 2:			//�ſ�ŷڰ���
	{ AccountHandler::MakeHicreditAccount(); break; }
	}

}
void AccountHandler::MakeNomalAccount()
{
	int id;
	char name[Pnumber];
	int money;
	char intereat;

	//���� ���� ���� �Լ� �����
	cout << " ----------- [���뿹�ݰ��� ����â] ---------------";

	cout << endl << "���°輳 ";
	cout << endl << "����ID: "; cin >> id;
	cout << endl << "�̸�: "; cin >> name;
	cout << endl << "�Աݾ�: "; cin >> money;
	cout << endl << "������: "; cin >> intereat;

	//������� Ŭ������ ���� �Ҵ�
	Accarr[cnt] = new NomalAccount(id, money, name, intereat);			//�Է¹��� ������ ���� ���� ����
	cnt++;

}
void AccountHandler::MakeHicreditAccount()
{
	int id;
	char name[Pnumber];
	int money;
	char intereat;
	int level;

	//���� ���� ���� �Լ� �����
	cout << " ----------- [�ŷڿ��ݰ��� ����â] ---------------";

	cout << endl << "���°輳 ";
	cout << endl << "����ID: "; cin >> id;
	cout << endl << "�̸�: "; cin >> name;
	cout << endl << "�Աݾ�: "; cin >> money;
	cout << endl << "������: "; cin >> intereat;
	cout << endl << "�ſ���(1toA, 2toB, 3toC): ";
	cin >> level;

	//�ŷ� �ſ� ���� Ŭ������ ���� �Ҵ�
	switch (level)
	{
	case 1:
		Accarr[cnt++] = new HiCreditAccount(id, money, name, intereat, A);			//�Է¹��� ������ ���� ���� ����
		break;
	case 2:
		Accarr[cnt++] = new HiCreditAccount(id, money, name, intereat, B);
		break;
	case 3:
		Accarr[cnt++] = new HiCreditAccount(id, money, name, intereat, C);
		break;
	}

}
void AccountHandler::DepositMoney()				//���2. �� ��
{
	int money = 0;
	int id = 0;
	long intereat;
	int sw = 0;

	cout << "---------2.�Ա��ϱ�-----------" << endl;
	cout << "����ID: "; cin >> id;

	for (i = 0; i < cnt; i++)
	{
		if (Accarr[i]->accID == id)					//id�� ���ٸ�
		{
			cout << endl << "�Աݾ�: "; cin >> money;
			Accarr[i]->AMOUNT += money;
			cout << endl << "������: "; cin >> intereat;
			cout << "�Ա� �Ϸ�";
			sw = 1;
		}
	}
	if (sw = 0)
		cout << "��ȿ���� ���� ID �Դϴ�." << endl;

}
void AccountHandler::WithdrawMoney()			//���3. �� ��
{
	int money = 0;
	int id = 0;
	int sw = 0;
	int i;
	cout << "---------3.����ϱ�------------" << endl;

	cout << "����ID: "; cin >> id;

	for (i = 0; i < cnt; i++)
	{
		if (Accarr[i]->accID == id)							//accID�� ����Ű�� �迭?
		{
			cout << "��ݾ�: "; cin >> money;
			Accarr[i]->AMOUNT -= money;					//��� ����
			cout << endl << "��� �Ϸ�";
			sw = 1;									//if(sw=0)�� ������� �ʵ���  ���� 1�� �ٲپ���
		}
	}
	if (sw = 0)
	{
		cout << "��ȿ���� ���� ID �Դϴ�. " << endl;
	}


}
void AccountHandler::ShowAllAccInfo() 	//4.�ܾ� ��ȸ
{
	int i;
	cout << endl << "---------4. �ܾ� ��ȸ------------" << endl;

	for (i = 0; i < cnt; i++)
	{
		cout << "����ID: " << Accarr[i]->accID << endl;
		cout << "�̸�: " << Accarr[i]->NAME << endl;
		cout << "�ܾ�: " << Accarr[i]->AMOUNT << endl;
	}
}
AccountHandler::~AccountHandler()
{
	for (i = 0; i < cnt; i++)
		delete []Accarr;
}