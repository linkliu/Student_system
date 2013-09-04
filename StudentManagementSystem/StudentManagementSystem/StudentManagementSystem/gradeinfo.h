#ifndef GRADEINFO_H_
#define GRADEINFO_H_
#include "ofenuse.h"
#include "student.h"
namespace student
{
	class CStudent;
}

namespace teacher
{
	class CTeacher;
}

namespace gradeinfo{

	class CGradeinfo
	{
		/*函数的定义*/
	public:
		void GetClass();//获得班级信息
		bool InsertGradeInfo();//向成绩信息中插入学生成绩记录（外部接口）
		bool DeleteGradeInfo();//删除成绩信息中的学生成绩记录（外部接口）
		void CreateGradeInfo();//添加一个班级的课程分数统计（外部接口）
		bool SearchStu(string & sno,string * pstr_Sno,int nRow,int & m);//搜索一个学生是否存在在记录当中(外部接口)
 //   	friend bool student::CStudent::searchGradeInfo(string strClass);//吧CStudent类中的SearchGradeInfo()函数定义为类CGradeinfo类的一个友元，这样就可以访问CGradeinfo类中的私有成员函数了
		friend class student::CStudent;//把CStudent类定义为CGradeinfo类的一个友类，因为在CStudent类中要用到类CGradeinfo类的许多成员函数
		friend class teacher::CTeacher;//吧CTeacher类定义为CGradeinfo类的一个友类，因为在CTeacher类中要用到类CGradeinfo类的许多成员函数

	private:
		void Display(string strHead,double ** nClassGrade,string * pSno,int nRow,int nColumn);//表头的格式化输出
		double ** ExchangeData(string strClass,ifstream & fin,string **str_Sno,int & nRow,int & nColumn);//文件数据交换函数
		bool Delete(string strClass);//删除成绩记录
		string * GetCourseInfo(int & m);//获得课程信息
		int GetRecord();//获得课程分数记录的个数
		void PutIntoFile(string strClass,double ** nClassGrade,string * strSno,string strHead,int endRow,int nColumn);//把内存中的数据输入到文件
		


		/*成员变量*/

	public:
		string sno;
	private:
		double * grade;
		string * course;

	public:
		string str_class;    //班级信息
	};

}

#endif


