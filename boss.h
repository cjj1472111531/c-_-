#pragma once
#include<iostream>
using namespace std;
#include"work.h"
class boss :public worker
{
public:
	boss(int id, string name, int deptid) {
		this->m_id = id;
		this->m_name = name;
		this->m_deptid = deptid;
	}

	virtual void showinfo() {
		cout << "ְԱ���: " << this->m_id
			<< " \tְԱ���� " << this->m_name
			<< " \t��λ��Ϣ " << this->getdeptname()
			<< " \t��λְ�𣺻�ˮ,�·����������" << endl;
	}

	virtual string getdeptname() {
		return string("Boss");
	}
};

