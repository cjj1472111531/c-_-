#pragma once
#include<iostream>
using namespace std;
#include"work.h"
class manger:public worker
{
public:
	manger(int id, string name, int deptid) {
		this->m_id = id;
		this->m_name = name;
		this->m_deptid = id;
	}

	virtual void showinfo() {
		cout << "ְԱ���: " << this->m_id
			<< " \tְԱ���� " << this->m_name
			<< " \t��λ��Ϣ " << this->getdeptname()
			<< " \t��λְ������ϰ�ķԸ����·������Ա��" << endl;
	}

	virtual string getdeptname() {
		return string("����");
	}
};


