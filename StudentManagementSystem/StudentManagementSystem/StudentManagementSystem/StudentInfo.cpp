#include "StudentInfo.h"
//#include<string.h>
//插入函数

namespace studentinfo
{
	//获得班级信息
	void CStuinfo::GetClass()
	{
		cout<<"请输入班级信息:"<<endl;
		cin>>this->str_class;
	}

	//插入
	void CStuinfo::Insert()
	{

		cout<<"请输入姓名:"<<endl;
		cin>>name;
		cout<<"请输入性别:"<<endl;
		cin>>gend;
		cout<<"请输入学学号:"<<endl;
		cin>>sno;
		cout<<"请输入出生日期(如1991-02-12):"<<endl;
		cin>>birth;
		cout<<"请输入家庭住址:"<<endl;
		cin>>adress;
		cout<<"请输入联系电话:"<<endl;
		cin>>phone;

	}

	//向班级插入学生的基本信息
	void CStuinfo::InsertStuInfo()
	{
		ofstream fout(this->str_class+".txt",ios_base::app);
		Insert();
		string inform =name+" "+gend +" "+sno+" "+birth+" "+adress+" "+phone+"\n";

		fout<<inform;
		fout.clear();
		fout.close();

		cout<<"记录已经记录"<<endl;

	}


	//修改学生基本信息（外部接口）
	void CStuinfo::ChangeStuInfo()
	{
		Change();
	}


	//修改学生的基本信息函数(private)
	bool CStuinfo::Change()
	{
		ifstream fin;
		fin.open(this->str_class+".txt");
		if(!fin.is_open())
		{
			cerr<<"修改错误，请检查班级名称是否正确："<<endl;
			fin.clear();//清除错误信息，以便后来可以的读取不受影响
			return false;
		}
		int m = 0;//用来记录记录的条数
		BaseData * re  =  ExchangeData(fin,this->str_class,m);//获得所有记录
		cout<<"请输入要修改的学生的学号"<<endl;

		string nSno ;
		cin>>nSno;
		int i =0;
		while(i<m)
		{
			if(re[i].sno == nSno)//在记录中找到要修改的学生的记录
			{
				cout<<"下面是你要修改的记录："<<endl;
				cout<<"      1.姓名  2.性别        3.学号     4.出生日期         5.地址     6.联系方式\n";
				cout<<setfill(' ')<<setw(12)<<re[i].name
					<<setfill(' ')<<setw(7)<<re[i].gend
					<<setfill(' ')<<setw(15)<<re[i].sno
					<<setfill(' ')<<setw(15)<<re[i].birth
					<<setfill(' ')<<setw(15)<<re[i].adress
					<<setfill(' ')<<setw(15)<<re[i].phone<<"\n";
				cout<<"请输入你要修改部分的序号:"<<endl;
				int nchange;
				cin>>nchange;
				switch(nchange)
				{
				case 1:
					cout<<"请输入新的名字：";
					cin>>re[i].name;
					cout<<"记录已经重新修改"<<endl;
					break;
				case 2:
					cout<<"请输入新的性别：";
					cin>>re[i].gend;
					cout<<"记录已经成功修改"<<endl;
					break;
				case 3:
					cout<<"请输入新的学号：";
					cin>>re[i].sno;
					cout<<"记录已经重新修改"<<endl;
					break;
				case 4:
					cout<<"请输入新的出生日期:";
					cin>>re[i].birth;
					cout<<"记录已经重新修改"<<endl;
					break;
				case 5:
					cout<<"请输入新的地址:";
					cin>>re[i].adress;
					cout<<"记录已经重新修改"<<endl;
					break;
				case 6:
					cout<<"请输入新的联系电话：";
					cin>>re[i].phone;
					cout<<"记录已经重新修改"<<endl;
					break;
				default:
					cout<<"你输入的序号不正确"<<endl;
					break;
				}
				break;
			}
			i++;
		}

		fin.clear();
		fin.close();

		if(i > m-1)
		{
			cout<<"没有该记录"<<endl;
			return false;
		}
		else
		{
			//接下来要把修改过的数据重新放回文件中
			ofstream chanfout;
			chanfout.open(this->str_class+".txt");
			for(int firdex = 0;firdex < m;firdex++)
			{
				chanfout<<re[firdex].name+" "+re[firdex].gend +" "+re[firdex].sno+" "+re[firdex].birth+" "+re[firdex].adress+" "+re[firdex].phone+"\n";
			}
			chanfout.close();//关闭文件

		}

		delete [] re;//释放内存

		return true;



	}

	//文件数据交换函数
	BaseData *  CStuinfo::ExchangeData(ifstream &fin,string Class,int & m)
	{
		int num = 0;//记录该班级的学生个数（即记录的个数）
		string base;
		//打开文件，开始对文件中的记录进行计数
		while(getline(fin,base))  num++;
		//在内存中分配空间，为处理记录分配空间
		BaseData * record = new BaseData[num];//这个地方非常危险，在最后要记得释放内存
		fin.clear();
		fin.close();
		fin.open(Class+".txt");//从新打开文件，从头开始读取记录
		for(int firdex = 0;firdex<num;firdex++)//将文件中的记录转到内存
		{
			getline(fin,base);
			istringstream sin(base);
			sin>>record[firdex].name;
			sin>>record[firdex].gend;
			sin>>record[firdex].sno;
			sin>>record[firdex].birth;
			sin>>record[firdex].adress;
			sin>>record[firdex].phone;
		}
		m = num;//获得记录的个数
		return record;//获得所有记录

	}




	//删除学生记录(内部函数)
	bool CStuinfo::Delete(string strClass)
	{
		//打开学生信息文件
		ifstream fin;
		fin.open(strClass+".txt");
		if(!fin.is_open())
		{
			cerr<<"删除错误，请检查班级名称是否正确："<<endl;
			fin.clear();//清除错误信息，
			return false;
		}
		int m = 0;//用来记录记录的条数
		BaseData * re  =  ExchangeData(fin,strClass,m);//获得所有记录
		cout<<"请输入要删除的学生的学号"<<endl;
		string nSno ;
		cin>>nSno;

		int i = 0;
		while(i<m)
		{
			if(re[i].sno == nSno)
			{
				cout<<"下面是你要删除的记录："<<endl;
				cout<<"        姓名    性别          学号       出生日期           地址       联系方式 \n";
				cout<<setfill(' ')<<setw(12)<<re[i].sno
					<<setfill(' ')<<setw(7)<<re[i].gend
					<<setfill(' ')<<setw(15)<<re[i].sno
					<<setfill(' ')<<setw(15)<<re[i].birth
					<<setfill(' ')<<setw(15)<<re[i].adress
					<<setfill(' ')<<setw(15)<<re[i].phone<<"\n";
				cout<<"是否要删除(Y/N)"<<endl;
				char sure;
				cin>>sure;
				if(sure=='Y' || sure=='y')
				{
					for(int firdex = i;firdex<m-1;firdex++)//复制信息，覆盖要删除的记录；
					{
						re[firdex] = re[firdex+1];//这个位置有问题。还要改进
					}
				}
				else
				{
					cout<<"删除已取消"<<endl;
					return false;
				}

				break;

			}
			i++;
		}


		if(i > m-1)
		{
			cout<<"删除错误，没有该记录"<<endl;
			return false;
		}
		else
		{
			//接下来要把修改过的数据重新放回文件中
			ofstream chanfout;
			chanfout.open(strClass+".txt");
			for(int firdex = 0;firdex < m-1;firdex++)
			{
				chanfout<<re[firdex].name+" "+re[firdex].gend +" "+re[firdex].sno+" "+re[firdex].birth+" "+re[firdex].adress+" "+re[firdex].phone+"\n";
			}
			chanfout.close();
			cout<<"记录已删除"<<endl;

		}

		delete [] re;//释放内存

		return true;

	}



	//删除学生信息(接口)

	void CStuinfo::DeleteStuInfo()
	{
	
		Delete(this->str_class);
	}


	bool CStuinfo::DisplayStuInfo()
	{
		ifstream fin;
		fin.open(this->str_class+".txt");
		if(!fin.is_open())
		{
			cerr<<"显示错误，请检查班级名称是否正确："<<endl;
			fin.clear();//清除错误信息，
			return false;
		}

		int m = 0;//用来记录记录的条数
		BaseData * re  =  ExchangeData(fin,this->str_class,m);//获得所有记录
		cout<<this->str_class<<"班级的基本信息如下：\n"<<endl;
		cout<<"        姓名    性别          学号       出生日期           地址       联系方式 \n";
		for(int firdex = 0;firdex<m;firdex++)//显示所有的学生基本信息
		{
			cout<<setfill(' ')<<setw(12)<<re[firdex].name
				<<setfill(' ')<<setw(7)<<re[firdex].gend
				<<setfill(' ')<<setw(15)<<re[firdex].sno
				<<setfill(' ')<<setw(15)<<re[firdex].birth
				<<setfill(' ')<<setw(15)<<re[firdex].adress
				<<setfill(' ')<<setw(15)<<re[firdex].phone<<endl<<endl;

		}
		delete [] re;
		return true;
	}

}