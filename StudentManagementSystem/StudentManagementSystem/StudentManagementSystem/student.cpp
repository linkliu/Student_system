#include"student.h"
#include"StudentInfo.h"
#include"gradeinfo.h"


namespace student
{
	void CStudent::GetSno()//设置学号
	{
		cin>>this->sno;
	}


	void CStudent::SearchUser()//插叙学生信息（外部接口）
	{
		cout<<"请输入你的班级:"<<endl;
		string strClass;//获得班级信息
		cin>>strClass;

		cout<<"请选择你要查询的内容：(1.学生基本信息查询;2.课程成绩查询):\n";
		int judge = 0;//选择操作类型
		cin>>judge;
		if(judge == 1)//查询学生基本信息
		{
			SearchStuInfo(strClass);
		}
		else if(judge ==2)//查询学生课程信息
		{
			searchGradeInfo(strClass);
		}
		else
		{
			cout<<"选择错误，输入错误！"<<endl;
		}
	}


	//查询学生基本信息
	bool CStudent::SearchStuInfo(string strClass)
	{

		ifstream fin;//打开该班级的学生基本信息文件
		fin.open(strClass+".txt");
		{
			if(!fin.is_open())
			{
				cerr<<"查询错误，请检查班级名称是否正确："<<endl;
				fin.clear();//清除错误信息，
				return false;
			}
		}
		using studentinfo::CStuinfo;
		CStuinfo stu;//引用一个CStuinfo的对象
		stu.str_class = strClass;//获得班级信息
		stu.DisplayStuInfo();

		using studentinfo::BaseData;//把学生基本信息装入内存
		int m = 0;//用来记录记录的条数
		BaseData * re = stu.ExchangeData(fin,strClass,m);//引用一个BaseData对象(在CStuinfo类中)

		//获得学号信息
		cout<<"请输入你的学号:"<<endl;
		GetSno();

		//在记录中查询
		int i = 0;
		while(i < m)
		{
			if(re[i].sno == this->sno)//在记录中找到要查询的学生的记录
			{
				cout<<"下面是你要查询的记录："<<endl;
				cout<<"        姓名    性别          学号       出生日期           地址       联系方式 \n";
				cout<<setfill(' ')<<setw(12)<<re[i].sno
					<<setfill(' ')<<setw(7)<<re[i].gend
					<<setfill(' ')<<setw(15)<<re[i].sno
					<<setfill(' ')<<setw(15)<<re[i].birth
					<<setfill(' ')<<setw(15)<<re[i].adress
					<<setfill(' ')<<setw(15)<<re[i].phone<<"\n";
				break;
			}
			i++;

		}

		if(i > m-1)
		{
			cout<<"没有该记录"<<endl;
			delete [] re;//释放内存
			return false;
		}

		fin.close();//关闭文件
		delete [] re;//释放内存
		return true;
	}



	//查询学生课程分数信息

	bool CStudent::searchGradeInfo(string strClass)
	{
		ifstream fin;//打开strClass班级的成绩文件
		fin.open("g"+strClass+".txt");
		if(!fin.is_open())
		{
			cerr<<"查询错误，请检查班级名称是否正确："<<endl;
			fin.clear();//清除错误信息，以便后来可以的读取不受影响
			return false;
		}
		double **pn_ClassGrade=NULL;//班级分数为它分配一个二维指针，内存动态分配
		string *pstr_Sno=NULL;//学号信息
		int nColumn;//记录多少列
		int nRow;//记录多少行

		//gradeinfo::CGradeinfo info;//定义一个CGradeinfo的对象
		using gradeinfo::CGradeinfo;
		CGradeinfo info;//定义一个CGradeinfo类的对象，因为后面要用到很多CGradeinfo类的成员函数
		info.str_class = strClass;//获得班级信息
		pn_ClassGrade=info.ExchangeData(info.str_class,fin,&pstr_Sno,nRow,nColumn);//把文件中的数据读入内存
		fin.clear();//清除错误信息
		fin.close();//关闭文件


		//显示成绩信息
		fin.open("g"+info.str_class+".txt");
		string strHeadInfo;//表头信息
		getline(fin,strHeadInfo);
		fin.close();
		info.Display(strHeadInfo,pn_ClassGrade,pstr_Sno,nRow,nColumn);



		cout<<"请输入你要查询的学号："<<endl;
		cin>>this->sno;//输入学号

		int m=0;//用来记录所查学生所在的记录的位置

		if(info.SearchStu(this->sno,pstr_Sno,nRow,m))
		{
			cout<<"下面是你要查询的信息："<<endl;
			string * pstr_Head = new string[nColumn];//获得表头信息
			//记得释放内存信息
			istringstream sin(strHeadInfo);
			for(int firdex = 0;firdex<nColumn && sin>>pstr_Head[firdex];firdex++);

			//下面输出表头
			cout<<setw(pstr_Sno[0].length())<<pstr_Head[0]<<"  ";//学号这一列比较特殊
			for(int secdex = 1;secdex < nColumn;secdex++)
				cout<<pstr_Head[secdex]<<"  ";
			cout<<endl;
			


			cout<<setw(pstr_Sno[m].length())<<pstr_Sno[m];//学号单独输出
			for(int firdex = 0;firdex < nColumn-1;firdex++)//显示要删除的信息
			{
				cout<<setw(pstr_Head[firdex+1].length()+2)<<pn_ClassGrade[m][firdex];
			
			}
			cout<<endl;


			//内存释放
			delete [] pstr_Head;
			for(int firdex = 0;firdex < nRow;firdex++)
			{
				delete pn_ClassGrade[firdex];//释放每个单元的动态内存
				pn_ClassGrade[firdex] = NULL;
			}
			delete [] pn_ClassGrade;

			delete [] pstr_Sno;
			pstr_Sno=NULL;
			pn_ClassGrade = NULL;
			return true;
		}
		else
		{
			cout<<"您查询的信息不存在"<<endl;

			//内存释放
			for(int firdex = 0;firdex < nRow;firdex++)
			{
				delete pn_ClassGrade[firdex];//释放每个单元的动态内存
				pn_ClassGrade[firdex] = NULL;
			}
			delete [] pn_ClassGrade;

			delete [] pstr_Sno;
			pstr_Sno=NULL;
			pn_ClassGrade = NULL;
			return false;
		}

	}

}

