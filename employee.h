#pragma once
#include<iostream>
#include"work.h"
using namespace std;
class employee:public worker
{
public:
	employee(int id,string name ,int deptid) {
		this->m_id = id;
		this->m_name = name;
		this->m_deptid = deptid;
	}
	virtual void showinfo() {
		cout << "ְԱ���:" << this->m_id
			<< " \tְԱ����: " << this->m_name
			<< " \t��λ��Ϣ: " << this->getdeptname()
			<< " \t��λְ����ɾ�����������" << endl;
	}
	//��Ϊ����virtual  ���Ի������Լ�getdeptname����
	virtual string  getdeptname() {
		return string("Ա��");
	}

};


