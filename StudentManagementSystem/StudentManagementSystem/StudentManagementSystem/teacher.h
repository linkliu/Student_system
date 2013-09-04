#ifndef TEACHER_H_
#define TEACHER_H_
#include "user.h"

//using namespace user;

namespace teacher
{

	//老师类的定义
	class CTeacher:public CUser
	{
		/*************函数的定义**********/
	public:
		CTeacher(){};
		~CTeacher(){};
		void SearchUser();//查询学生信息(外部接口)
		void CreateClass();//新的班级信息(外部接口)
		bool InsertInfo();//插入学生信息(外部接口)
		int ChangeInfo();//修改学生信息(外部接口)
		bool DeleteInfo();//删除学生信息(外部接口)
		void ShowInfo();//显示学生信息(外部接口)

		/*************成员变量的定义**********/
	public:
		string teacherId;//老师的教职工号

	};

}


#endif