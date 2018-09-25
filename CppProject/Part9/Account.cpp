//박다정

//#include "BankingCommonDecl.h"
#include "Account.h"

	Account::Account() {}						 //생성자가 정의가 되있으면 컴파일러가 디폴트 생성자를 안 만들어줌
	Account::Account(int ID, int money, String name)		//초기화 할수있음/생성자....함수라고 생각하자//여기도 const붙일수 잇음
		: accID(ID), AMOUNT(money)						//멤버이니셜라이저...초기화
	{
		//NAME = new char[strlen(name) + 1];
		//strcpy(NAME, name);//	복사 NAME 같아짐
		NAME = name;
	}
	/*Account::Account(const Account &copy)							//깊은 복사 생성자
		:accID(copy.accID), AMOUNT(copy.AMOUNT)
	{
		NAME = new char[strlen(copy.NAME) + 1];
		strcpy(NAME, copy.NAME);
	}*///string
	/*Account& Account::operator=(const Account& copy)
	{
		accID = copy.accID;
		AMOUNT = copy.AMOUNT;

		delete[]NAME;
		NAME = new char[strlen(copy.NAME) + 1];
		strcpy(NAME, copy.NAME);
		return *this;
	}*///string
	void Account::Deposit(int money)
	{
		AMOUNT += money;
	}
	/*
	Account::~Account()							//소멸자
	{
		delete []NAME;
	}*/
