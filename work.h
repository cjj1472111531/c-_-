#pragma once
#include<iostream>
#include<string>
using namespace std;


//workerΪ���� ����ָ��ָ������������磺employee��manger ��work
/*
worker ��Ϊָ�� ִ�������������һ������ �Ӷ�
ӳ���һ��worker��ָ�룬����virtualȥʵ�����еĶ�̬
*/
//ְ������󻯻���
class worker
{
public:
	//��ʾ������Ϣ
	virtual  void showinfo() = 0;  //����0Ϊ���麯��
	//��ȡ��λ����
	virtual string getdeptname() = 0;

	int m_id;//ְԱ���
	string m_name;//ְԱ����
	int m_deptid;//ְԱ���ڲ������Ʊ��


};







