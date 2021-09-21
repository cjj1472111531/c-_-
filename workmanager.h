#pragma once//防止头文件重复包含
#include<iostream>
#include"work.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
//文件交互 写文件
#include<fstream>

#define FILENAME "clown.txt" //准备要写入到文本名字

using namespace std;

class workmanager
{

public:
	//记录文件中的人数个数
	int m_empnum;
	// 员工数组的指针
	worker ** m_emparr;
	bool m_fileempty;//用一个布尔值判断为不为0

	//构建函数
	workmanager() {
	/*
	第一次使用，文件没创建
	第二次使用 文件存在 但数据被清空
	第三次使用 文件存在 数据存在
	*/
		//文件方面：文件不存在
		ifstream ifs;
		ifs.open(FILENAME, ios::in); 
		if (!ifs.is_open())    //第一种情况
		{
			cout << "文件不存在" << endl;//如果不存在 做一些补救的操作  初始化
			this->m_empnum = 0;
			this->m_emparr = NULL;
			this->m_fileempty = true;//为空了
			ifs.close();
			return;
		}
		//第二种情况:文件存在且没有记录
		char ch;  //ifs右移读一个字符 如果这个字符是EOF 则说明文件无内容
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "文件为空" << endl;
			this->m_empnum = 0;
			this->m_fileempty = true;
			this->m_emparr = NULL;
			ifs.close();
			return ;//返回到程序出口
		}
		//文件存在，而且存在数据
		cout << "文件存在而且之前存在数据" << endl;
		int num = this->getnum();
		cout << "职员职工有:" << num <<"个" << endl;
		this->m_empnum = num;

		//开辟空间
		this->m_emparr = new worker * [this->m_empnum];
		this->init_emp();//数据化初始化
		/*测试代码
		for (int i = 0; i < this->m_empnum; i++)
		{
			cout << "职工编号：" << this->m_emparr[i]->m_id << "  姓名："
				<< this->m_emparr[i]->m_name << "  部门编号："
				<< this->m_emparr[i]->m_deptid << endl;

		}
		*/
		cout << "-----------开始构建职工表----------" << endl;
	}

	//析构函数 //开辟了 用完就删除
	~workmanager() {
		cout << "------------开始删除职工表---------" << endl;
		if (this->m_emparr != NULL)
		{
			for (int i = 0;i < this->m_empnum;i++)
			{
				if (this->m_emparr[i] != NULL)
				{
					delete this->m_emparr[i];
				}
			}
			this->m_empnum = 0;
			delete[] this->m_emparr;
			this->m_emparr = NULL;
		}
	}
	void save();//保存数据进入clown.txt文本文件中

	void add_emp();

	int getnum();
	void init_emp();

	void exitt() {
		cout << "欢迎下次使用" << endl;
		system("pause");
		exit(0);
	}

	//show 是展示菜单
	void show() {
			cout << "*************************************************" << endl;
			cout << "*************欢迎使用职员管理系统****************" << endl;
			cout << "************* 0.退出管理系统 ********************" << endl;
			cout << "************* 1.增加职工信息 ********************" << endl;
			cout << "************* 2.显示职工信息 ********************" << endl;
			cout << "************* 3.删除离职员工信息*****************" << endl;
			cout << "************* 4.修改职工信息*********************" << endl;
			cout << "************* 5.查找职工信息*********************" << endl;
			cout << "************* 6.按照编号排序*********************" << endl;
			cout << "************* 7.清空所有文档*********************" << endl;
			cout << "*************************************************" << endl;
			cout << endl;
	}

	void show_emp();

	void del_emp();
	//先删除之前判断存不存在
	int isexist(int id);

	void mod_emp();//修改的话可能会用到是否存在的功能

	void search();

	void sort1();

	void clearfile();
};

void workmanager::add_emp()
{
	cout << "请输入增加员工的数量：" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) {
		//新的员工人数
		int newsize = this->m_empnum + addnum;
		worker** newspace = new worker * [newsize];
		 //worker ** newspace = new worker*[newsize]; //新的内存空间 worker指针新空间人数大小

		//将原有的内存放入新的内存中去
		if (this->m_emparr != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparr[i];

			}
		}
		//输入新的数据
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int deptid;

	/*		cout << "请输入第" << i + 1 << " 个新职员的编号：" << endl;
			cin >> id;*/
			//防止同名编号
			int k = 0;
			int check = 0;//check用于检测是否有同id
		
				cout << "请输入第" << i + 1 << " 个新职员的编号：" << endl;
				cin >> id;
				for (int i = 0; i < this->m_empnum; i++)
				{
					if (this->m_emparr[i]->m_id == id)
					{
						cout << "此编号已经进入，不可再次加入" << endl;
						return;//直接退回接口
					}
				}


			cout << "请输入第" << i + 1 << " 个新职员的姓名：" << endl;
			cin >> name;

			cout << "请选择该职员的岗位" << endl;
			cout << "1：员工   2：经理   3：BOSS" << endl;
			cin >> deptid;

			worker* worker = NULL;
			switch (deptid)
			{
			case 1://普通员工
				worker = new employee(id, name, 1);
				break;
			case 2:// 经理
				worker = new manger(id, name, 2);
				break;
			case 3://老板
				worker = new boss(id, name, 3);
				break;
			default:
				cout << "您老人家 输入错的部门号" << endl;
				break;
			}
			//如果之前有内存 之后 往他后面加
			newspace[this->m_empnum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_emparr;
		//更改新的指针
		this->m_emparr = newspace;
		//更新新的人数
		this->m_empnum = newsize;

		//说明人数不为空
		this->m_fileempty = false;

		cout << "成功添加：" << addnum <<"名公司人员" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//再添加的过程就进行信息的保存
	this->save();

	//按任意键清屏
	system("pause");
	system("cls");
}

void workmanager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out|ios_base::binary);//写入方式打开  open(文件名，打开方式) out 写 in读
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparr[i]->m_id << "  " 
			<< this->m_emparr[i]->m_name << "  "
			<< this->m_emparr[i]->m_deptid << endl;
	}
	ofs.close();//使用完记得关闭
}

int workmanager::getnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //in 是读的意思
	int id,num=0;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did) {
		//记录人数
		num++;
	}
	ifs.close();
	return num;


}

void workmanager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//in 是读的意思
	int new_num = this->getnum();//知道已知的人数
	int id, did;
	string name;
	int index=0;//当前指向的位置
	while (ifs>>id&&ifs>>name&&ifs>>did)// >>表示右移操作
	{
		worker* emp = NULL;//具体的职工
		//根据不同的部门 id创建不同的对象；
		if (did==1)
		{
			emp = new employee(id, name, did);
		}
		else if (did == 2)
		{
			emp = new manger(id, name, did);
		}
		else
		{
			emp = new boss(id, name, did);
		}
		this->m_emparr[index] = emp;//将读取的数据放入m_emparr 维护的数组中 这个二重指针中去
		index++;//从头初始化的人数加加
	}
	ifs.close();
}

void workmanager::show_emp() {
	if (this->m_fileempty)
	{
		cout << "文件中没内容或者为空" << endl;
	}
	else
	{
		//int num = this->getnum();
		int num = this->m_empnum;
		for (int i = 0; i < num; i++)
		{
         //其他效果  利用多态调用接口
			this->m_emparr[i]->showinfo();
		 
			//cout << "职工编号：" << this->m_emparr[i]->m_id << "  姓名："
			//	<< this->m_emparr[i]->m_name << "  部门编号："
			//	<< this->m_emparr[i]->m_deptid << endl;
		}

	}
	system("pause");
	system("cls");

}

void workmanager::del_emp() {
	int che_id;
	//判断文件存不存在
	if (this->m_fileempty)
	{
		cout << ".txt文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入删除的职工编号：";
		cin >> che_id;  //右移id
		//check 如果存在，用来表示这个删除id所在的位置，如果不存在得到-1
		int check = this->isexist(che_id);
		cout << "输出当前check在：" << check << "：位置上" << endl;
		if (check != -1) {
			for (int i = check; i < this->m_empnum-1; i++)//最后一个倒数一个 ！！！ 警告
			{
				//int j = i + 1;
				this->m_emparr[i] = this->m_emparr[i+1];//后一个把前一个代替，直到最后算删除 数据千亿
			}
			//this->m_emparr[i] = NULL;
			this->m_empnum--;
			//上述二维数组已经搞定了 现在要将数据同步更新到文件中
			this->save();//直接可以更新到文件中
			cout << "删除职员:" << che_id << "成功" << endl;
		}
		else
		{
			cout << "不存在此职员id" << endl;
		}
	}
	system("pause");
	system("cls");
}
//根据id判断是否存在
int workmanager::isexist(int id)
{
	for (int  i = 0; i <this->m_empnum  ; i++)
	{
		if (id == this->m_emparr[i]->m_id)
			return i;
	}
	return -1;//-1表示没找到
}

void workmanager::mod_emp() {
	//自己根据职员编号进行员工信息修改
	int che_id;
	cout << "请输入修改职员的id" << endl;
	cin >> che_id;
	int check = this->isexist(che_id);
	if (check!=-1) {
		for (int i = 0; i < this->m_empnum; i++)
		{
			if (che_id == this->m_emparr[i]->m_id)
			{
				cout << "请输入修改的名字：";
				string mod_name;
				cin >> mod_name;
				int mod_deptid;
				cout << "请输入修改的部门编号：";
				cout << "1.普职  2.经理  3.Boss" << endl;
				cin >> mod_deptid;

				worker* emp = NULL;
				switch (mod_deptid)
				{
				case 1:
					emp = new employee(che_id, mod_name, mod_deptid);
					break;
				case 2:
					emp = new manger(che_id, mod_name, mod_deptid);
					break;
				case 3:
					emp = new boss(che_id, mod_name, mod_deptid);
					break;
				default:
					break;
				}
				this->m_emparr[i] = emp;//把对象进行复制进取为佳

				//this->m_emparr[i]->m_name = mod_name;
				//this->m_emparr[i]->m_deptid = mod_deptid; //还是不要着急覆盖

				cout << "修改职员：" << che_id << " 信息成功" << endl;
				this->save();//进行将数据进行保存
			}
		}
	}
	else
	{
		cout << "想要修改的职员id不存在" << endl;
	}
	system("pause");
	system("cls");
}


void workmanager::search() {
	int chc_id;
	//判断文件是否有内容
	if (!this->m_fileempty)
	{
		cout << "输入搜寻职员的id：";
		cin >> chc_id;
		for (int i = 0; i < this->m_empnum; i++)
		{
			if (chc_id == this->m_emparr[i]->m_id)
			{
				this->m_emparr[i]->showinfo();
		//	cout << "此职员的编号：" << chc_id <<
		//		"  此职工姓名：" << this->m_emparr[i]->m_name <<
		//		"  此职工的部门编号" << this->m_emparr[i]->m_deptid << endl;

			}
		}


	}
	else
	{
		cout << "此文件为空或者没有数据" << endl;
	}
	system("pause");
	system("cls");

}

void workmanager::sort1() {
	if (!this->m_fileempty)
	{
		cout << "请选择排序方法：" << endl;
		cout << "1:按职工工号升序排列" << endl;
		cout << "2:按职工工号降序排列" << endl;
		int select;
		cin >> select;

		for (int  i = 0; i <this->m_empnum; i++)
		{
			int mins = i;//自动默认i为最小值 最小值最大值下标
			for (int j = i+1; j <this-> m_empnum; j++)
			{
				if (select == 1)
				{
					if (this->m_emparr[mins]->m_id >this-> m_emparr[j]->m_id)
					{
						mins = j;
					}
				}
				else
				{
					if (this->m_emparr[mins]->m_id <this-> m_emparr[j]->m_id)
						mins = j;
				}
				if (i != mins)
				{
					worker* temp = m_emparr[i];
					m_emparr[i] = m_emparr[mins];
					m_emparr[mins] = temp;
				}
			}
		}
		cout << "排序成功，排序结果为:" << endl;
		this->save();
		this->show();
	}
	else
	{
		cout << "文件不存在或者文件中无内容" << endl;
		system("pause");
		system("cls");
	}


}

void  workmanager::clearfile() {
	cout << "确定清空数据？" << endl;
	cout << "1.确定   2.返回" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ios::trunc 如果存在 删除文件并重新创建
		ofs.close();//先把文件解决掉
		if (this->m_emparr != NULL)
		{
			for (int i = 0;i < this->m_empnum;i++)
			{
				if (this->m_emparr[i] != NULL)
				{
					delete this->m_emparr[i];
				}
			}
			this->m_empnum = 0;
			delete[] this->m_emparr;
			this->m_fileempty = true;
			this->m_emparr = NULL;
		}

		cout << "清空成功---over" << endl;

	}
	else
	{
		cout << "拜拜了您勒！" << endl;
	}
}

