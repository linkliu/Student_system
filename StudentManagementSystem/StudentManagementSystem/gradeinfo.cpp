#include"gradeinfo.h"

namespace gradeinfo{

	void CGradeinfo::GetClass()//获得班级信息
	{
		cout<<"请输入班级信息:"<<endl;
		cin>>this->str_class;
	}


	//添加一个班级的课程分数统计（外部接口）
	void CGradeinfo::CreateGradeInfo()
	{
		ofstream fout;
		fout.open("g"+this->str_class+".txt");//新建了一个课程分数
		if(!fout.is_open())
		{
			cerr<<"新建失败!"<<endl;
			fout.clear();
			return ;
		}
		//	course = new string [nCourse];//为每个课程名分配存储空间
		//最后记得释放课程名所申请的动态内存空间

		int m=0;
		course = GetCourseInfo(m);//获得课程的门数

		fout<<"  Sno  ";

		for(int firdex = 0;firdex<m;firdex++)//新建课程分数的表头(我这是盗版数据库的，其实文本文件不是这样的，只是为了方便说明)
		{
			fout<<course[firdex]+"  ";//输入目
		}

		fout<<"\n";//表头输入完毕
		fout.close();//关闭文件

		delete [] course;//释放科目名称所占用的动态内存
	}

	//获得课程信息(内部函数)
	string* CGradeinfo::GetCourseInfo(int &m)
	{
		cout<<"请输入课程的门数：(0-20)"<<endl;
		cin>>m;//获得课程的门数
		//	grade = new double[nCourse];
		string * pCourse = new string [m];//用来保存课程的名字信息

		for(int firdex = 0;firdex<m;firdex++)
		{
			cout<<"请输入课程 "<<firdex<<" 的名字"<<endl;
			cin>>pCourse[firdex];
		}

		for(int secdex = 0;secdex < m;secdex++)
			cout<<pCourse[secdex]<<endl;

		return pCourse;
	}



	double ** CGradeinfo::ExchangeData(string strClass,ifstream & fin,string ** str_Sno, int & n_Row,int & n_Column)//文件数据交换函数
	{

		string strHeadInfo;//表头信息
		getline(fin,strHeadInfo);//获得课程成绩的表头信息
		istringstream sin(strHeadInfo);//用istringstream 对象指向string对象，使之可以像C++输入流那样从strHeadInfo哪里输入字符
		int nColumn;//记录多少列
		int nRow;//记录多少行
		string strCourse;
		for(nColumn = 0;sin>>strCourse;nColumn++);//获得课程分数列数量

		nRow = GetRecord();

		(*str_Sno) = new string [nRow];//为每条记录分配一个学号

		double **nClassGrade;//班级分数为它分配一个二维指针，内存动态分配
		//记得要在后面释放内存
		nClassGrade = new double* [nRow];//为班级课程分配二维动态内存，
		for(int firdex = 0;firdex < nRow;firdex++ )
			nClassGrade[firdex] = new double [nColumn-1];//学号不算在里面
		//到时候记得释放内存
		string strGrade;

		//下面把文件中的课程分数信息装入内存
		for(int firdex = 0;getline(fin,strGrade) && firdex< nRow;firdex++)
		{
			istringstream sin(strGrade);
			sin>>(*str_Sno)[firdex];//学号分开存储
			for(int secdex = 0;secdex<nColumn-1;secdex++)//这里secdex从1开始，是因为学好那一列不是分数的范围
			{
				sin>>nClassGrade[firdex][secdex];
				int m = 0;
			}
		}

		n_Row = nRow;//返回行数
		n_Column = nColumn;//返回列数，这里算上了学号的列数
		int m =0;
		return nClassGrade;//通过成绩的二维指针返回成绩信息;

		//最后记得在调用它的地方释放动态内存

	}



	//删除成绩记录
	bool CGradeinfo::Delete(string strClass )
	{

		ifstream fin;//打开strClass班级的成绩文件
		fin.open("g"+strClass+".txt");
		if(!fin.is_open())
		{
			cerr<<"不存在该班级，请检查班级名称是否正确："<<endl;
			fin.clear();//清除错误信息，以便后来可以的读取不受影响
			return false;
		}

		double **pn_ClassGrade=NULL;//班级分数为它分配一个二维指针，内存动态分配
		string *pstr_Sno=NULL;//学号信息
		int nColumn;//记录多少列
		int nRow;//记录多少行

		pn_ClassGrade=ExchangeData(strClass,fin,&pstr_Sno,nRow,nColumn);
		fin.clear();//清除错误信息
		fin.close();//关闭文件


		fin.open("g"+strClass+".txt");
		string strHeadInfo;//表头信息
		getline(fin,strHeadInfo);
		Display(strHeadInfo,pn_ClassGrade,pstr_Sno,nRow,nColumn);





		cout<<"请输入你要删除的学号："<<endl;
		cin>>this->sno;//输入学号

		int m=0;//用来记录所查学生所在的记录的位置

		if(SearchStu(this->sno,pstr_Sno,nRow,m))
		{
			cout<<"下面是你要删除的信息："<<endl;
			cout<<setw(pstr_Sno[m].length())<<pstr_Sno[m]<<"  ";//学号单独输出
			for(int firdex = 0;firdex < nColumn-1;firdex++)//显示要删除的信息
			{
				cout<<pn_ClassGrade[m][firdex];
				cout<<"  ";
			}
			cout<<endl;
			char sure;
			cout<<"是否要删除：(Y/N)"<<endl;
			cin>>sure;
			if(sure=='y' || sure=='Y')
			{
				//在调用PutInfoFile（）这个函数时，先要把要删除的那条记录覆盖掉
				for(int firdex = m;firdex < nRow-1;firdex++)
				{
					pstr_Sno[firdex] = pstr_Sno[firdex+1];//学号的覆盖
					for(int secdex = 0;secdex < nColumn;secdex++)//覆盖课程分数
						pn_ClassGrade[firdex][secdex] = pn_ClassGrade[firdex+1][secdex]; 

				}

				PutIntoFile(strClass,pn_ClassGrade,pstr_Sno,strHeadInfo,nRow,nColumn);//吧内存中的数据写入文件
				cout<<"记录已删除"<<endl;
				return true;

			}
			else
			{
				cout<<"删除已经取消"<<endl;
				return false;
			}
		}
		else
		{
			cout<<"没有该记录"<<endl;
			return false;
		}



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


	bool CGradeinfo::DeleteGradeInfo()
	{
		if(Delete(this->str_class)) return true;
		return false;
	}

	//获得课程分数记录的个数

	int CGradeinfo::GetRecord()
	{
		ifstream fin;
		fin.open("g"+this->str_class+".txt");//打开文件
		string strHead;
		getline(fin,strHead);//取走表头，因为表头不是这个函数要返回的信息
		int nRecord=0;
		for(;getline(fin,strHead);nRecord++);//对记录进行计数
		fin.close();//关闭文件
		return nRecord;//返回记录的条数，（即结果）
	}




	//向课程成绩信息表中插入新的信息（外部接口）
	bool CGradeinfo::InsertGradeInfo()
	{
		ifstream fin;//打开文件
		fin.open("g"+this->str_class+".txt");
		if(!fin.is_open())
		{
			fin.clear();
			cerr<<"文件不能打开或文件不存在.";
			return false;
		}

		string strInfo;//表头信息
		getline(fin,strInfo);//从文件中获得表头信息

		fin.clear();//清除错误信息
		fin.close();//关闭文件

		istringstream sin1(strInfo);//从表头字符串中读
		int nCourseNum=0;

		for(string base;sin1>>base;nCourseNum++);//获得课程的数目
		course = new string [nCourseNum-1];//为每个课程名分配一个空间(因为多读了学号所以要减去1)
		istringstream sin2(strInfo);
		string te;
		sin2>>te;//过滤掉学好信息，从而获得真确的表头信息
		for(int i = 0;sin2>>course[i];i++);
		//	grade = new double [nCourseNum];//为每每一门课程分配分数存储的空间
		//注意在使用后要释放内存，以免内存泄漏
		string strSno;
		cout<<"请输入学生的学号："<<endl;
		cin>>strSno;
		rewind(stdin);
		ofstream fout("g"+this->str_class+".txt",ios_base::app);//打开文件
		fout<<strSno+"   ";
		for(int firdex = 0;firdex < nCourseNum-1;firdex++)
		{
			cout<<"\n请输入"<<course[firdex]<<"的成绩："<<endl;
			double nGrade= 0.0;
			cin>>nGrade;
			fout<<nGrade;//向文件中输入课程分数信息
			fout<<"  ";
		}

		fout<<"\n";//每条记录换一行
		fout.clear();//清除错误信息
		fout.close();//关闭文件

		cout<<"分数已经记录!"<<endl;

		delete [] course;//释放课程名所分配的动态内存

		return true;


	}


	//表头的格式化输出(内部函数)

	void CGradeinfo::Display(string strHead,double ** nClassGrade,string * pSno,int nRow,int nColumn)
	{


		string * pstr_Head = new string[nColumn];//获得表头信息
		//记得释放内存信息
		istringstream sin(strHead);
		for(int firdex = 0;firdex<nColumn && sin>>pstr_Head[firdex];firdex++);

		//下面输出表头
		cout<<setw(pSno[0].length())<<pstr_Head[0]<<"  ";//学号这一列比较特殊
		for(int secdex = 1;secdex < nColumn;secdex++)
			cout<<pstr_Head[secdex]<<"  ";
		cout<<endl;

		//下面输出课程分数信息

		for(int firdex = 0;firdex < nRow;firdex++)
		{
			cout<<pSno[firdex];
			for(int secdex = 0;secdex < nColumn-1;secdex++)//学好要单独输出，因为它不存储在nClassGrade中，而在pSno中
			{
				cout<<setw(pstr_Head[secdex+1].length()+2)<<nClassGrade[firdex][secdex];
			}
			cout<<endl;
		}

		delete [] pstr_Head;



	}


	//搜索一个学生是否存在在记录当中(外部接口)
	bool CGradeinfo::SearchStu(string & sno,string * pstr_Sno,int nRow,int & m)
	{
		for(int firdex = 0;firdex < nRow;firdex++)
		{
			if(pstr_Sno[firdex]==sno)
			{
				m = firdex;//所在行号
				return true;
			}

		}
		return false;
	}

	//把内存中的数据输入到文件
	void CGradeinfo::PutIntoFile(string strClass,double ** nClassGrade,string * strSno,string strHead,int nRow,int nColumn)
	{

		ofstream fout;
		fout.open("g"+strClass+".txt");//打开课程信息文件
		if(!fout.is_open())
		{
			cerr<<"课程文件不存在或者打开失败"<<endl;
			fout.clear();
			return ;
		}
		fout<<strHead<<"\n";//把表头写入文件
		//下面把内存中的数据写入文件
		for(int firdex  = 0; firdex < nRow-1;firdex++)
		{
			fout<<strSno[firdex]<<"  ";
			for(int secdex = 0;secdex < nColumn-1;secdex++)
			{
				fout<<nClassGrade[firdex][secdex]<<" ";
			}
			fout<<"\n";
		}

		fout.clear();
		fout.close();//关闭文件


	}


}