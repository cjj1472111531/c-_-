#pragma once
#include<iostream>
#include<string>
using namespace std;


//worker为父类 父类指针指向子类对象例如：employee，manger ，work
/*
worker 作为指针 执行其他三个类的一个对象 从而
映射出一个worker的指针，利用virtual去实现类中的多态
*/
//职工表抽象化基类
class worker
{
public:
	//显示个人信息
	virtual  void showinfo() = 0;  //等于0为纯虚函数
	//获取岗位名称
	virtual string getdeptname() = 0;

	int m_id;//职员编号
	string m_name;//职员姓名
	int m_deptid;//职员所在部门名称编号


};







