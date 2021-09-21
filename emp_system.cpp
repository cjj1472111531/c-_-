
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
		cout << "请输入clown的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: wm.exitt(); break;//退出系统
		/* 
		因为用户批量创建 会有不同工种
		将不同工种的员工放入一个数组中，可以将所有员工维护到一个数组
		如果想在程序中维护这个不定长的数组，可以将数组创建在堆中
		用二重指针进行维护 worker **
		  worker**=new worker*[];
		  第一个*号访问new 中的空间数据 例如 第几个员工
		  第二个*号访问数组中的内容
		*/
		case 1:  wm.add_emp(); break;//添加
		case 2: wm.show_emp();break; //显示职员编号 和姓名，以及部门编号
		case 3:wm.del_emp();break;//删除
		case 4:wm.mod_emp();break;//修改 
		case 5:wm.search();break;//查找
		case 6:wm.sort1();break;//排序
		case 7://清空
			wm.clearfile();break;
		default:
			system("cls");
			break;
		}


	}
		return 0;
}




