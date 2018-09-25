//박다정
#ifndef __Handler__
#define __Handler__

#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountArray.h"
class AccountHandler			 		//컨트롤 클래스
{
private:
	BoundCheckAccountPtrArray accarr;
	Account * Accarr[100];			//정보를 받은 계좌들을 저장할 배열
	int cnt;							//for돌릴 변수
	int i;								//for돌릴변수
public:
	AccountHandler();					//생성자//멤버이니셜라이져 
	void ShowMenu();					//메뉴

	void AccountChoice();				//기능1.계좌 선택
	void MakeNomalAccount();		//기능1_1.보통예금계좌
	void MakeHicreditAccount();	//기능1_1.신용신뢰 계좌

	void DepositMoney();				//기능2. 입 금
	void WithdrawMoney();			//기능3. 출 금
	void ShowAllAccInfo(); 			//기능4. 잔액 조회

	~AccountHandler();
	
};
#endif