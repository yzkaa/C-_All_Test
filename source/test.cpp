#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h>
using namespace std;

const int A=2;
const int B=4;
int a,b,c,d,s;

class employee{
protected:
	string name;
	int jobnumber;
	int age;
	string gender;	
	double salary;
public:
	employee()					{name="\0";		jobnumber=0;		age=0;		gender="\0"	;	salary=0;}
	void Add()
	{
		cout<<"请输入该职员的名字：";		cin>>name;			cout<<endl;
		cout<<"请输入该职员的年龄：";		cin>>age;			cout<<endl;
		cout<<"请输入该职员的性别：";		cin>>gender;		cout<<endl;
	}
};
/*********************技术员***************************/
class technician:public employee{
protected:
	double workhour;
	int hoursalary;
public:
	 void Add()			
	{
		cout<<"请输入技术员的工号：";			cin>>jobnumber;				cout<<endl;
		employee::Add();
		cout<<"请输入技术员的工作时长：";		cin>>workhour;
		salary=workhour*hoursalary;
		cout<<jobnumber<<"的薪水是："<<salary<<"元"<<endl;
	}
};technician te[A]; 
/**********************经理**************************/
class manager:virtual public employee{
public:
	virtual void Add()
	{
		cout<<"请输入经理的工号：";				cin>>jobnumber;				cout<<endl;
		employee::Add();
		cout<<"jobnumber"<<"的薪水是：100000元"<<endl;
	}
};
/******************* 行政人员************************/
class administrator:virtual public employee{
public:
	  void Add()
	{
		cout<<"请输入行政人员的工号：";			cin>>jobnumber;				cout<<endl;
		employee::Add();
		cout<<"jobnumber"<<"的薪水是：3000元"<<endl;
	}
};
/**********************主管***********************/
class supervisor:public manager,public administrator{
private:
    string name;
	int jobnumber;
	int age;
	string gender;	
	double salary;
	double sale;
public:
	supervisor(){sale=0;}
	void Add()
	{
		cout<<"请输入主管的工号：";			cin>>jobnumber;				cout<<endl;
		cout<<"请输入该职员的名字：";		cin>>name;			cout<<endl;
		cout<<"请输入该职员的年龄：";		cin>>age;			cout<<endl;
		cout<<"请输入该职员的性别：";		cin>>gender;		cout<<endl;
		cout<<"请输入主管的销售额：";			cin>>sale;
		salary=5000+sale*0.005;
		cout<<jobnumber<<"的薪水是："<<salary<<"元"<<endl;
	}

};
/************************************************/
void menu()

{ 
	cout<<"         【***WELCOME***】         "<<endl; 
	cout<<"   【The Employee Sysytem Menu】   "<<endl; 
	cout<<endl;
	cout<<"************************"<<endl;
	cout<<"  ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"<<endl;
	cout<<"  ┃ 信息录入：  ① 并按回车键  ┃"<<endl;
	cout<<"  ┃ 删除人员：  ② 并按回车键  ┃"<<endl; 
	cout<<"  ┃ 存档资料：  ③ 并按回车键  ┃"<<endl; 
	cout<<"  ┃ 退出系统：  ④ 并按回车键  ┃"<<endl; 
	cout<<"  ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"<<endl;
	cout<<endl;
	cout<<"************************"<<endl;
	cout<<" Please choose a operand:\a  "<<endl; 
	cin>>c;
	cout<<endl; 
}
void Write()
{	
	cout<<"【The submenu】        "<<endl; 
	cout<<endl;
	cout<<"************************"<<endl;
	cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"<<endl;
	cout<<"┃经理信息录入：    ① 并按回车键 ┃"<<endl; 
	cout<<"┃主管信息录入：    ② 并按回车键 ┃"<<endl; 
	cout<<"┃技术员信息录入：  ③ 并按回车键 ┃"<<endl; 
	cout<<"┃行政人员信息录入：④ 并按回车键 ┃"<<endl; 
	cout<<"┃返回 上一级：     ⑥ 并按回车键 ┃"<<endl; 
	cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"<<endl;
	cout<<"************************"<<endl;
	cout<<" Please chose a operand:      "<<endl;
	cout<<endl;
	cin>>d; 
	cout<<endl;
}
void delete1()
{	
	cout<<"【The submenu】        "<<endl; 
	cout<<endl;
	cout<<"************************"<<endl;
	cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"<<endl;
	cout<<"┃经理信息删除：    ① 并按回车键 ┃"<<endl; 
	cout<<"┃主管信息删除：    ② 并按回车键 ┃"<<endl; 
	cout<<"┃技术员信息删除：  ③ 并按回车键 ┃"<<endl; 
	cout<<"┃行政人员信息删除：④ 并按回车键 ┃"<<endl; 
	cout<<"┃返回 上一级：     ⑥ 并按回车键 ┃"<<endl; 
	cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃"<<endl;
	cout<<"************************"<<endl;
	cout<<" Please chose a operand:      "<<endl;
	cout<<endl;
	cin>>d; 
	cout<<endl;
}
int main()
{   
	FILE *fp;
	fp = fopen("/home/yzk/1.txt","w");
	if(fp)
		cout<<"创建成功"<<endl;
	technician A1[100];//技术员容量
	manager A2[100];//经理容量
	administrator A3[100];//行政人员容量
	supervisor A4[100];//主管容量
	int b1=0,b2=0,b3=0,b4=0;
//	cout<<"************************"<<endl;
	while(1)
{
	menu();
	switch(c){
	case 1: Write();break;
	case 2: break;
	case 3: {break;}
	case 4: break;
	}
	switch(d){
 	case 1: {
		
		A2[b2].Add();

			}
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	}
}
//	cout<<"************************"<<endl;
}