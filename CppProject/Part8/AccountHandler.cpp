//박다정

#include "Account.h"
#include "AccountHandler.h"
//#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "NomalAccount.h"

AccountHandler::AccountHandler() :cnt(0), i(0)					//생성자//멤버이니셜라이져 
{}
void AccountHandler::ShowMenu()				//메뉴
{
	cout << endl << "------------Menu-----------";
	cout << endl << "1. 계좌 개설";
	cout << endl << "2. 입   금";
	cout << endl << "3. 출   금";
	cout << endl << "4. 전체고객 잔액조회";
	cout << endl << "5. 프로그램 종료";
	cout << endl << "선택: ";

}
void AccountHandler::AccountChoice()								//계좌선택//하다가감
{
	int num = 0;

	cout << "[계좌 종류 선택]" << endl;
	cout << "1. 보통예금계좌" << " 2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> num;

	if (num > 3)
	{
		cout << "선택범위를 벗어났습니다. " << endl;
	}
	switch (num)
	{
	case 1:			//보통예금계좌
	{ AccountHandler::MakeNomalAccount(); break; }
	case 2:			//신용신뢰계좌
	{ AccountHandler::MakeHicreditAccount(); break; }
	}

}
void AccountHandler::MakeNomalAccount()
{
	int id;
	char name[Pnumber];
	int money;
	char intereat;

	//계좌 종류 선택 함수 만들기
	cout << " ----------- [보통예금계좌 개설창] ---------------";

	cout << endl << "계좌계설 ";
	cout << endl << "계좌ID: "; cin >> id;
	cout << endl << "이름: "; cin >> name;
	cout << endl << "입금액: "; cin >> money;
	cout << endl << "이자율: "; cin >> intereat;

	//보통계좌 클래스에 동적 할당
	Accarr[cnt] = new NomalAccount(id, money, name, intereat);			//입력받은 정보를 계좌 정보 저장
	cnt++;

}
void AccountHandler::MakeHicreditAccount()
{
	int id;
	char name[Pnumber];
	int money;
	char intereat;
	int level;

	//계좌 종류 선택 함수 만들기
	cout << " ----------- [신뢰예금계좌 개설창] ---------------";

	cout << endl << "계좌계설 ";
	cout << endl << "계좌ID: "; cin >> id;
	cout << endl << "이름: "; cin >> name;
	cout << endl << "입금액: "; cin >> money;
	cout << endl << "이자율: "; cin >> intereat;
	cout << endl << "신용등급(1toA, 2toB, 3toC): ";
	cin >> level;

	//신뢰 신용 계좌 클래스에 동적 할당
	switch (level)
	{
	case 1:
		Accarr[cnt++] = new HiCreditAccount(id, money, name, intereat, A);			//입력받은 정보를 계좌 정보 저장
		break;
	case 2:
		Accarr[cnt++] = new HiCreditAccount(id, money, name, intereat, B);
		break;
	case 3:
		Accarr[cnt++] = new HiCreditAccount(id, money, name, intereat, C);
		break;
	}

}
void AccountHandler::DepositMoney()				//기능2. 입 금
{
	int money = 0;
	int id = 0;
	long intereat;
	int sw = 0;

	cout << "---------2.입금하기-----------" << endl;
	cout << "계좌ID: "; cin >> id;

	for (i = 0; i < cnt; i++)
	{
		if (Accarr[i]->accID == id)					//id가 같다면
		{
			cout << endl << "입금액: "; cin >> money;
			Accarr[i]->AMOUNT += money;
			cout << endl << "이자율: "; cin >> intereat;
			cout << "입금 완료";
			sw = 1;
		}
	}
	if (sw = 0)
		cout << "유효하지 않은 ID 입니다." << endl;

}
void AccountHandler::WithdrawMoney()			//기능3. 출 금
{
	int money = 0;
	int id = 0;
	int sw = 0;
	int i;
	cout << "---------3.출금하기------------" << endl;

	cout << "계좌ID: "; cin >> id;

	for (i = 0; i < cnt; i++)
	{
		if (Accarr[i]->accID == id)							//accID를 가리키는 배열?
		{
			cout << "출금액: "; cin >> money;
			Accarr[i]->AMOUNT -= money;					//출금 연산
			cout << endl << "출금 완료";
			sw = 1;									//if(sw=0)이 실행되지 않도록  값을 1로 바꾸어줌
		}
	}
	if (sw = 0)
	{
		cout << "유효하지 않은 ID 입니다. " << endl;
	}


}
void AccountHandler::ShowAllAccInfo() 	//4.잔액 조회
{
	int i;
	cout << endl << "---------4. 잔액 조회------------" << endl;

	for (i = 0; i < cnt; i++)
	{
		cout << "계좌ID: " << Accarr[i]->accID << endl;
		cout << "이름: " << Accarr[i]->NAME << endl;
		cout << "잔액: " << Accarr[i]->AMOUNT << endl;
	}
}
AccountHandler::~AccountHandler()
{
	for (i = 0; i < cnt; i++)
		delete []Accarr;
}