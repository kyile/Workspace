//�ڴ���
#include "BankingCommonDecl.h"
#include "AccountHandler.h"


int main(void)
{
	int num;
	AccountHandler person;						//ȸ����� ��ü ����
	//Account create;								//���� ���� ��ü

	while (1)
	{
		person.ShowMenu();			//�޴��Լ�
		cin >> num;
		if (num < 0)
		{
			printf("�Լ��� ������ �ƴմϴ�. ");
		}
		else if (num > 0)
		{
			switch (num)
			{
			case MAKE:
			{	person.AccountChoice(); break;   }
			case DEPOSIT:
			{	person.DepositMoney(); break;    }
			case WIHDRAW:
			{	person.WithdrawMoney(); break; }
			case INQUIRE:
			{	person.ShowAllAccInfo(); break;   }
			case EXIT:
			{	person.~AccountHandler(); exit(1); break; }					//����//�޸𸮸� �����ϸ� ����
			}
		}
	}
	return 0;
}

