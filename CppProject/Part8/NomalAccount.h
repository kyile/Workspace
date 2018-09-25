//박다정
#ifndef __Nomal__
#define __Nomal__

#include "Account.h"

class NomalAccount : public Account	 	//보통계좌 계설 =여기다가 사람들 저장
{
private:
	int Nomal;				//보통계좌 이자율
public:
	NomalAccount(int ID, int money, const char *name, int nomal)
		:Account(ID, money, name), Nomal(nomal)//부모 클래스의 멤버이니셜라이져를 먼저 작성
	{ }
	virtual void Deposit(int money)
	{
		Account::Deposit(money);				//원금과 이자 추가
		Account::Deposit(money*(Nomal / 100.0));		//특별이자 추가
	}

};
#endif