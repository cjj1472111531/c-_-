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
		cout << "职员编号: " << this->m_id
			<< " \t职员姓名 " << this->m_name
			<< " \t岗位信息 " << this->getdeptname()
			<< " \t岗位职责：完成老板的吩咐，下发任务给员工" << endl;
	}

	virtual string getdeptname() {
		return string("经理");
	}
};


