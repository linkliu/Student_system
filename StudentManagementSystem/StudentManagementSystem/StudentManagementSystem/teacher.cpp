#include"teacher.h"
#include"StudentInfo.h"
#include"gradeinfo.h"
#include"student.h"


namespace teacher
{
	//查询学生信息(外部接口)
	void CTeacher::SearchUser()
	{
		using student::CStudent;
		CStudent stu;
		//调用student的SearchUser()函数
		stu.SearchUser();
	}

	//新的班级信息(外部接口)

	void CTeacher::CreateClass()
	{
		ofstream fout;
		cout<<"请输入要创建的班级号:"<<endl;
		string strClass;
		cin>>strClass;
		bool judge1 = false;//判断是否存在该班级的基本信息
		bool judge2 = false;//判断是否存在该班级的课程成绩信息
		ifstream fin;

		//班级基本信息的判断
		fin.open(strClass+".txt");
		if(fin.is_open())
		{
			judge1 = true;//可以打开
			fin.clear();
			fin.close();
		}

		//班级课程成绩信息的判断
		fin.open("g"+strClass+".txt");
		if(fin.is_open())
		{
			judge2 = true;//可以打开
			fin.clear();
			fin.close();
		}

		if(judge1||judge2)//如果已经存在该班级的信息，就不用新建了
		{
			cout<<"该班级信息已存在"<<endl;
		}
		else
		{
			fout.open(strClass+".txt");//新建该班级的基本信息
			fout.clear();
			fout.close();
			fout.open("g"+strClass+".txt");//新建该班级的课程成绩信息
			fout.clear();
			fout.close();
			cout<<"班级已经新建"<<endl;
		}

	}

	//插入学生信息(外部接口)
	bool CTeacher::InsertInfo()
	{
		int m_choice;//插入的信息的类型
		cout<<"输入要插入的信息类型:1.学生基本信息 | 2.学生课程分数信息"<<endl;
		cin>>m_choice;
		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//定义一个CStuinfo的对象
			stu.GetClass();//获得班级信息
			stu.InsertStuInfo();//向班级插入学生基本信息
			return true;
		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//定义一个CGradeinfo类的对象
			gradeinfo.GetClass();//获得班级信息
			gradeinfo.InsertGradeInfo();//向班级插入课程分数信息
			return true;

		}
		else
		{
			cout<<"操作选择有误"<<endl;
			return false;
		}

	}


	//修改学生信息(外部接口)

	int CTeacher::ChangeInfo()
	{
		//这里要说明一下，
		cout<<"为了给信息系统提供一个安全的环境，\"2.学生课程分数信息\"没有提供修改操作!"<<endl;
		int m_choice;//插入的信息的类型
		cout<<"输入要修改的信息类型:1.学生基本信息 | 2.学生课程分数信息"<<endl;
		cin>>m_choice;

		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//定义一个CStuinfo的对象
			stu.GetClass();//获得班级信息
			stu.DisplayStuInfo();//显示班级基本信息
			stu.ChangeStuInfo();//修改班级基本信息

			return 1;//表示操作为1类型
		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//定义一个CGradeinfo的对象
			gradeinfo.GetClass();//获得班级信息
			cout<<"对不起，课程信息的修改只能先删除再添加!"<<endl;
			if(gradeinfo.DeleteGradeInfo())//删除要修改的课程分数信息记录
			{
				gradeinfo.InsertGradeInfo();//插入要目标课程分数信息记录
				return 2;
			}
			else
			{   
				cout<<"没有删除，无法修改！"<<endl;
				return 0;//表示错误的操作类型
			}
		}
		else
		{
			cout<<"操作选择有误"<<endl;
			return 0;//表示错误的操作类型
		}

	}


	//删除学生信息(外部接口)

	bool CTeacher::DeleteInfo()
	{
		int m_choice;//插入的信息的类型
		cout<<"输入要删除的信息类型:1.学生基本信息 | 2.学生课程分数信息"<<endl;
		cin>>m_choice;
		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//定义一个CStuinfo的对象
			stu.GetClass();//获得班级信息
			stu.DeleteStuInfo();//删除学生基本信息
			return true;
		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//定义一个CGradeinfo类的对象
			gradeinfo.GetClass();//获得班级信息
			gradeinfo.DeleteGradeInfo();//删除学生课程分数信息
			return true;

		}
		else
		{
			cout<<"操作选择有误"<<endl;
			return false;
		}

	}

	//显示学生信息(外部接口)
	void CTeacher::ShowInfo()
	{
		int m_choice;//要显示的信息的类型
		cout<<"输入要显示的信息类型:1.学生基本信息 | 2.学生课程分数信息"<<endl;
		cin>>m_choice;
		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//定义一个CStuinfo的对象
			stu.GetClass();//获得班级信息
			stu.DisplayStuInfo();//显示学生基本信息

		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//定义一个CGradeinfo类的对象
			gradeinfo.GetClass();//获得班级信息
			//gradeinfo.InsertGradeInfo();//删除学生课程分数信息
			ifstream fin;//打开strClass班级的成绩文件
			fin.open("g"+gradeinfo.str_class+".txt");
			if(!fin.is_open())
			{
				cerr<<"不存在该班级，请检查班级名称是否正确："<<endl;
				fin.clear();//清除错误信息，以便后来可以的读取不受影响
				return ;
			}

			double **pn_ClassGrade=NULL;//班级分数为它分配一个二维指针，内存动态分配
			string *pstr_Sno=NULL;//学号信息
			int nColumn;//记录多少列
			int nRow;//记录多少行

			pn_ClassGrade=gradeinfo.ExchangeData(gradeinfo.str_class,fin,&pstr_Sno,nRow,nColumn);
			fin.clear();//清除错误信息
			fin.close();//关闭文件


			fin.open("g"+gradeinfo.str_class+".txt");
			string strHeadInfo;//表头信息
			getline(fin,strHeadInfo);
			gradeinfo.Display(strHeadInfo,pn_ClassGrade,pstr_Sno,nRow,nColumn);

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


		}
		else
		{
			cout<<"操作选择有误"<<endl;

		}

	}


}


