//�ڴ���
#ifndef __Handler__
#define __Handler__

#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountArray.h"
class AccountHandler			 		//��Ʈ�� Ŭ����
{
private:
	BoundCheckAccountPtrArray accarr;
	Account * Accarr[100];			//������ ���� ���µ��� ������ �迭
	int cnt;							//for���� ����
	int i;								//for��������
public:
	AccountHandler();					//������//����̴ϼȶ����� 
	void ShowMenu();					//�޴�

	void AccountChoice();				//���1.���� ����
	void MakeNomalAccount();		//���1_1.���뿹�ݰ���
	void MakeHicreditAccount();	//���1_1.�ſ�ŷ� ����

	void DepositMoney();				//���2. �� ��
	void WithdrawMoney();			//���3. �� ��
	void ShowAllAccInfo(); 			//���4. �ܾ� ��ȸ

	~AccountHandler();
	
};
#endif