#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"work.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
//�ļ����� д�ļ�
#include<fstream>

#define FILENAME "clown.txt" //׼��Ҫд�뵽�ı�����

using namespace std;

class workmanager
{

public:
	//��¼�ļ��е���������
	int m_empnum;
	// Ա�������ָ��
	worker ** m_emparr;
	bool m_fileempty;//��һ������ֵ�ж�Ϊ��Ϊ0

	//��������
	workmanager() {
	/*
	��һ��ʹ�ã��ļ�û����
	�ڶ���ʹ�� �ļ����� �����ݱ����
	������ʹ�� �ļ����� ���ݴ���
	*/
		//�ļ����棺�ļ�������
		ifstream ifs;
		ifs.open(FILENAME, ios::in); 
		if (!ifs.is_open())    //��һ�����
		{
			cout << "�ļ�������" << endl;//��������� ��һЩ���ȵĲ���  ��ʼ��
			this->m_empnum = 0;
			this->m_emparr = NULL;
			this->m_fileempty = true;//Ϊ����
			ifs.close();
			return;
		}
		//�ڶ������:�ļ�������û�м�¼
		char ch;  //ifs���ƶ�һ���ַ� �������ַ���EOF ��˵���ļ�������
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "�ļ�Ϊ��" << endl;
			this->m_empnum = 0;
			this->m_fileempty = true;
			this->m_emparr = NULL;
			ifs.close();
			return ;//���ص��������
		}
		//�ļ����ڣ����Ҵ�������
		cout << "�ļ����ڶ���֮ǰ��������" << endl;
		int num = this->getnum();
		cout << "ְԱְ����:" << num <<"��" << endl;
		this->m_empnum = num;

		//���ٿռ�
		this->m_emparr = new worker * [this->m_empnum];
		this->init_emp();//���ݻ���ʼ��
		/*���Դ���
		for (int i = 0; i < this->m_empnum; i++)
		{
			cout << "ְ����ţ�" << this->m_emparr[i]->m_id << "  ������"
				<< this->m_emparr[i]->m_name << "  ���ű�ţ�"
				<< this->m_emparr[i]->m_deptid << endl;

		}
		*/
		cout << "-----------��ʼ����ְ����----------" << endl;
	}

	//�������� //������ �����ɾ��
	~workmanager() {
		cout << "------------��ʼɾ��ְ����---------" << endl;
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
	void save();//�������ݽ���clown.txt�ı��ļ���

	void add_emp();

	int getnum();
	void init_emp();

	void exitt() {
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		exit(0);
	}

	//show ��չʾ�˵�
	void show() {
			cout << "*************************************************" << endl;
			cout << "*************��ӭʹ��ְԱ����ϵͳ****************" << endl;
			cout << "************* 0.�˳�����ϵͳ ********************" << endl;
			cout << "************* 1.����ְ����Ϣ ********************" << endl;
			cout << "************* 2.��ʾְ����Ϣ ********************" << endl;
			cout << "************* 3.ɾ����ְԱ����Ϣ*****************" << endl;
			cout << "************* 4.�޸�ְ����Ϣ*********************" << endl;
			cout << "************* 5.����ְ����Ϣ*********************" << endl;
			cout << "************* 6.���ձ������*********************" << endl;
			cout << "************* 7.��������ĵ�*********************" << endl;
			cout << "*************************************************" << endl;
			cout << endl;
	}

	void show_emp();

	void del_emp();
	//��ɾ��֮ǰ�жϴ治����
	int isexist(int id);

	void mod_emp();//�޸ĵĻ����ܻ��õ��Ƿ���ڵĹ���

	void search();

	void sort1();

	void clearfile();
};

void workmanager::add_emp()
{
	cout << "����������Ա����������" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) {
		//�µ�Ա������
		int newsize = this->m_empnum + addnum;
		worker** newspace = new worker * [newsize];
		 //worker ** newspace = new worker*[newsize]; //�µ��ڴ�ռ� workerָ���¿ռ�������С

		//��ԭ�е��ڴ�����µ��ڴ���ȥ
		if (this->m_emparr != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparr[i];

			}
		}
		//�����µ�����
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int deptid;

	/*		cout << "�������" << i + 1 << " ����ְԱ�ı�ţ�" << endl;
			cin >> id;*/
			//��ֹͬ�����
			int k = 0;
			int check = 0;//check���ڼ���Ƿ���ͬid
		
				cout << "�������" << i + 1 << " ����ְԱ�ı�ţ�" << endl;
				cin >> id;
				for (int i = 0; i < this->m_empnum; i++)
				{
					if (this->m_emparr[i]->m_id == id)
					{
						cout << "�˱���Ѿ����룬�����ٴμ���" << endl;
						return;//ֱ���˻ؽӿ�
					}
				}


			cout << "�������" << i + 1 << " ����ְԱ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְԱ�ĸ�λ" << endl;
			cout << "1��Ա��   2������   3��BOSS" << endl;
			cin >> deptid;

			worker* worker = NULL;
			switch (deptid)
			{
			case 1://��ͨԱ��
				worker = new employee(id, name, 1);
				break;
			case 2:// ����
				worker = new manger(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new boss(id, name, 3);
				break;
			default:
				cout << "�����˼� �����Ĳ��ź�" << endl;
				break;
			}
			//���֮ǰ���ڴ� ֮�� ���������
			newspace[this->m_empnum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_emparr;
		//�����µ�ָ��
		this->m_emparr = newspace;
		//�����µ�����
		this->m_empnum = newsize;

		//˵��������Ϊ��
		this->m_fileempty = false;

		cout << "�ɹ���ӣ�" << addnum <<"����˾��Ա" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	//����ӵĹ��̾ͽ�����Ϣ�ı���
	this->save();

	//�����������
	system("pause");
	system("cls");
}

void workmanager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out|ios_base::binary);//д�뷽ʽ��  open(�ļ������򿪷�ʽ) out д in��
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparr[i]->m_id << "  " 
			<< this->m_emparr[i]->m_name << "  "
			<< this->m_emparr[i]->m_deptid << endl;
	}
	ofs.close();//ʹ����ǵùر�
}

int workmanager::getnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //in �Ƕ�����˼
	int id,num=0;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did) {
		//��¼����
		num++;
	}
	ifs.close();
	return num;


}

void workmanager::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//in �Ƕ�����˼
	int new_num = this->getnum();//֪����֪������
	int id, did;
	string name;
	int index=0;//��ǰָ���λ��
	while (ifs>>id&&ifs>>name&&ifs>>did)// >>��ʾ���Ʋ���
	{
		worker* emp = NULL;//�����ְ��
		//���ݲ�ͬ�Ĳ��� id������ͬ�Ķ���
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
		this->m_emparr[index] = emp;//����ȡ�����ݷ���m_emparr ά���������� �������ָ����ȥ
		index++;//��ͷ��ʼ���������Ӽ�
	}
	ifs.close();
}

void workmanager::show_emp() {
	if (this->m_fileempty)
	{
		cout << "�ļ���û���ݻ���Ϊ��" << endl;
	}
	else
	{
		//int num = this->getnum();
		int num = this->m_empnum;
		for (int i = 0; i < num; i++)
		{
         //����Ч��  ���ö�̬���ýӿ�
			this->m_emparr[i]->showinfo();
		 
			//cout << "ְ����ţ�" << this->m_emparr[i]->m_id << "  ������"
			//	<< this->m_emparr[i]->m_name << "  ���ű�ţ�"
			//	<< this->m_emparr[i]->m_deptid << endl;
		}

	}
	system("pause");
	system("cls");

}

void workmanager::del_emp() {
	int che_id;
	//�ж��ļ��治����
	if (this->m_fileempty)
	{
		cout << ".txt�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������ɾ����ְ����ţ�";
		cin >> che_id;  //����id
		//check ������ڣ�������ʾ���ɾ��id���ڵ�λ�ã���������ڵõ�-1
		int check = this->isexist(che_id);
		cout << "�����ǰcheck�ڣ�" << check << "��λ����" << endl;
		if (check != -1) {
			for (int i = check; i < this->m_empnum-1; i++)//���һ������һ�� ������ ����
			{
				//int j = i + 1;
				this->m_emparr[i] = this->m_emparr[i+1];//��һ����ǰһ�����棬ֱ�������ɾ�� ����ǧ��
			}
			//this->m_emparr[i] = NULL;
			this->m_empnum--;
			//������ά�����Ѿ��㶨�� ����Ҫ������ͬ�����µ��ļ���
			this->save();//ֱ�ӿ��Ը��µ��ļ���
			cout << "ɾ��ְԱ:" << che_id << "�ɹ�" << endl;
		}
		else
		{
			cout << "�����ڴ�ְԱid" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����id�ж��Ƿ����
int workmanager::isexist(int id)
{
	for (int  i = 0; i <this->m_empnum  ; i++)
	{
		if (id == this->m_emparr[i]->m_id)
			return i;
	}
	return -1;//-1��ʾû�ҵ�
}

void workmanager::mod_emp() {
	//�Լ�����ְԱ��Ž���Ա����Ϣ�޸�
	int che_id;
	cout << "�������޸�ְԱ��id" << endl;
	cin >> che_id;
	int check = this->isexist(che_id);
	if (check!=-1) {
		for (int i = 0; i < this->m_empnum; i++)
		{
			if (che_id == this->m_emparr[i]->m_id)
			{
				cout << "�������޸ĵ����֣�";
				string mod_name;
				cin >> mod_name;
				int mod_deptid;
				cout << "�������޸ĵĲ��ű�ţ�";
				cout << "1.��ְ  2.����  3.Boss" << endl;
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
				this->m_emparr[i] = emp;//�Ѷ�����и��ƽ�ȡΪ��

				//this->m_emparr[i]->m_name = mod_name;
				//this->m_emparr[i]->m_deptid = mod_deptid; //���ǲ�Ҫ�ż�����

				cout << "�޸�ְԱ��" << che_id << " ��Ϣ�ɹ�" << endl;
				this->save();//���н����ݽ��б���
			}
		}
	}
	else
	{
		cout << "��Ҫ�޸ĵ�ְԱid������" << endl;
	}
	system("pause");
	system("cls");
}


void workmanager::search() {
	int chc_id;
	//�ж��ļ��Ƿ�������
	if (!this->m_fileempty)
	{
		cout << "������ѰְԱ��id��";
		cin >> chc_id;
		for (int i = 0; i < this->m_empnum; i++)
		{
			if (chc_id == this->m_emparr[i]->m_id)
			{
				this->m_emparr[i]->showinfo();
		//	cout << "��ְԱ�ı�ţ�" << chc_id <<
		//		"  ��ְ��������" << this->m_emparr[i]->m_name <<
		//		"  ��ְ���Ĳ��ű��" << this->m_emparr[i]->m_deptid << endl;

			}
		}


	}
	else
	{
		cout << "���ļ�Ϊ�ջ���û������" << endl;
	}
	system("pause");
	system("cls");

}

void workmanager::sort1() {
	if (!this->m_fileempty)
	{
		cout << "��ѡ�����򷽷���" << endl;
		cout << "1:��ְ��������������" << endl;
		cout << "2:��ְ�����Ž�������" << endl;
		int select;
		cin >> select;

		for (int  i = 0; i <this->m_empnum; i++)
		{
			int mins = i;//�Զ�Ĭ��iΪ��Сֵ ��Сֵ���ֵ�±�
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
		cout << "����ɹ���������Ϊ:" << endl;
		this->save();
		this->show();
	}
	else
	{
		cout << "�ļ������ڻ����ļ���������" << endl;
		system("pause");
		system("cls");
	}


}

void  workmanager::clearfile() {
	cout << "ȷ��������ݣ�" << endl;
	cout << "1.ȷ��   2.����" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ios::trunc ������� ɾ���ļ������´���
		ofs.close();//�Ȱ��ļ������
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

		cout << "��ճɹ�---over" << endl;

	}
	else
	{
		cout << "�ݰ������գ�" << endl;
	}
}

