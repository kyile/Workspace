//박다정
#ifndef __Acc__
#define __Acc__

#include "BankingCommonDecl.h"
//#include "AccountHandler.h"

class Account					//Entity 클래스
{
private:							//클래스내(클래스 내에 정의된 함수) 에서만  접근허용,멤버 변수 선언

	int  accID;					//아이디
	char * NAME;				//이름
	int   AMOUNT;		    	//금액

public:									//어디서든 접근 허용, 멤버 함수 선언

	Account();						 //생성자가 정의가 되있으면 컴파일러가 디폴트 생성자를 안 만들어줌
	Account(int ID, int money, const char * name);	
	Account(const Account &copy);
	Account& operator=(const Account& ref); //Bound
	void Deposit(int money);

	friend class AccountHandler;//Account 친구를 만들어줌
	~Account();							//소멸자
};
#endif 

