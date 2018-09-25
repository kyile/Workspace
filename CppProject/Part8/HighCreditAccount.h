//�ڴ���
#ifndef __HiCredit__
#define __HiCredit__

#include "Account.h"
#include "BankingCommonDecl.h"
#include"NomalAccount.h"

class HiCreditAccount : public NomalAccount		//�ſ� �ŷ� ���� �輳
{
private:
	int Hicredit;			//�ſ� �ŷ� ���� �輳
public:
	HiCreditAccount(int ID, int money, const char * name, int nomal, int hicredit)
		:NomalAccount(ID, money, name, nomal), Hicredit(hicredit)
	{}
	//��ü �������� �⺻���� ��ϰ���
	//���ſ��� A(0.7%), B(0.4%) C(0.2%)������ �߰��� ��������
	virtual void Deposit(int money)
	{
		NomalAccount::Deposit(money);		      //���� �� ���� �߰�
		Account::Deposit(money*(Hicredit / 100.0));  //Ư������ �߰�
	}
};

#endif