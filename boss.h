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
		cout << "职员编号: " << this->m_id
			<< " \t职员姓名 " << this->m_name
			<< " \t岗位信息 " << this->getdeptname()
			<< " \t岗位职责：划水,下发任务给经理" << endl;
	}

	virtual string getdeptname() {
		return string("Boss");
	}
};

