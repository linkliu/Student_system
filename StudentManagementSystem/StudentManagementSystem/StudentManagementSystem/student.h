#ifndef STUDENT_H_
#define STUDENT_H_
#include"user.h"
#include"gradeinfo.h"

namespace student
{
	//学生类的定义
	class CStudent:public CUser
	{
//		friend class CGradeinfo;

		/**********函数的定义**********/
	public:
		CStudent(){}
		~CStudent(){}
		void SearchUser();//查询学生
		

		/**********成员变量的定义**********/
	private:
		void GetSno();//设置学号
		bool SearchStuInfo(string strClass);//查询学生基本信息
		bool searchGradeInfo(string strClass);//查询学生课程分数信息
		
		string sno;//学生的学号
	};

}


#endif