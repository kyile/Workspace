//박다정
#include "BankingCommonDecl.h"
#include "AccountHandler.h"


int main(void)
{
	int num;
	AccountHandler person;						//회원등록 객체 생성
	//Account create;								//계좌 생성 객체

	while (1)
	{
		person.ShowMenu();			//메뉴함수
		cin >> num;
		if (num < 0)
		{
			cout<<"함수의 범위가 아닙니다. "<<endl;
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
			{ exit(1);}					//종료//메모리를 해제하며 종료
			}
		}
	}
	return 0;
}

