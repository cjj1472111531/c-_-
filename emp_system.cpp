
#include<iostream>
#include<string>
#include"workmanager.h"
using namespace std;
int main() {
	workmanager wm;
	int choice;
	while (true)
	{
		wm.show();
		cout << "������clown��ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: wm.exitt(); break;//�˳�ϵͳ
		/* 
		��Ϊ�û��������� ���в�ͬ����
		����ͬ���ֵ�Ա������һ�������У����Խ�����Ա��ά����һ������
		������ڳ�����ά����������������飬���Խ����鴴���ڶ���
		�ö���ָ�����ά�� worker **
		  worker**=new worker*[];
		  ��һ��*�ŷ���new �еĿռ����� ���� �ڼ���Ա��
		  �ڶ���*�ŷ��������е�����
		*/
		case 1:  wm.add_emp(); break;//���
		case 2: wm.show_emp();break; //��ʾְԱ��� ���������Լ����ű��
		case 3:wm.del_emp();break;//ɾ��
		case 4:wm.mod_emp();break;//�޸� 
		case 5:wm.search();break;//����
		case 6:wm.sort1();break;//����
		case 7://���
			wm.clearfile();break;
		default:
			system("cls");
			break;
		}


	}
		return 0;
}




