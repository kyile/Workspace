//�ڴ���
#ifndef __Acc__
#define __Acc__

#include "BankingCommonDecl.h"
//#include "AccountHandler.h"

class Account					//Entity Ŭ����
{
private:							//Ŭ������(Ŭ���� ���� ���ǵ� �Լ�) ������  �������,��� ���� ����

	int  accID;					//���̵�
	char * NAME;				//�̸�
	int   AMOUNT;		    	//�ݾ�

public:									//��𼭵� ���� ���, ��� �Լ� ����

	Account();						 //�����ڰ� ���ǰ� �������� �����Ϸ��� ����Ʈ �����ڸ� �� �������
	Account(int ID, int money, const char * name);	
	Account(const Account &copy);
	Account& operator=(const Account& ref); //Bound
	void Deposit(int money);

	friend class AccountHandler;//Account ģ���� �������
	~Account();							//�Ҹ���
};
#endif 

