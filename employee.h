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
		cout << "职员编号:" << this->m_id
			<< " \t职员姓名: " << this->m_name
			<< " \t岗位信息: " << this->getdeptname()
			<< " \t岗位职责：完成经理交代的事宜" << endl;
	}
	//因为是有virtual  所以会运行自己getdeptname函数
	virtual string  getdeptname() {
		return string("员工");
	}

};


