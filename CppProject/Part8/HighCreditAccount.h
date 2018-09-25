//박다정
#ifndef __HiCredit__
#define __HiCredit__

#include "Account.h"
#include "BankingCommonDecl.h"
#include"NomalAccount.h"

class HiCreditAccount : public NomalAccount		//신용 신뢰 계좌 계설
{
private:
	int Hicredit;			//신용 신뢰 계좌 계설
public:
	HiCreditAccount(int ID, int money, const char * name, int nomal, int hicredit)
		:NomalAccount(ID, money, name, nomal), Hicredit(hicredit)
	{}
	//객체 생성과정 기본이율 등록가능
	//고객신용등급 A(0.7%), B(0.4%) C(0.2%)이율을 추가로 제공저금
	virtual void Deposit(int money)
	{
		NomalAccount::Deposit(money);		      //원금 과 이자 추가
		Account::Deposit(money*(Hicredit / 100.0));  //특별이자 추가
	}
};

#endif