//�ڴ���
#ifndef __Nomal__
#define __Nomal__

#include "Account.h"
#include "String.h"
class NomalAccount : public Account	 	//������� �輳 =����ٰ� ����� ����
{
private:
	int Nomal;				//������� ������
public:
	//NomalAccount(int ID, int money, const char *name, int nomal)
	NomalAccount(int ID, int money, String name, int nomal)
		:Account(ID, money, name), Nomal(nomal)//�θ� Ŭ������ ����̴ϼȶ������� ���� �ۼ�
	{ }
	virtual void Deposit(int money)
	{
		Account::Deposit(money);				//���ݰ� ���� �߰�
		Account::Deposit(money*(Nomal / 100.0));		//Ư������ �߰�
	}

};
#endif