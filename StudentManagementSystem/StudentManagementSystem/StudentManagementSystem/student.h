#ifndef STUDENT_H_
#define STUDENT_H_
#include"user.h"
#include"gradeinfo.h"

namespace student
{
	//ѧ����Ķ���
	class CStudent:public CUser
	{
//		friend class CGradeinfo;

		/**********�����Ķ���**********/
	public:
		CStudent(){}
		~CStudent(){}
		void SearchUser();//��ѯѧ��
		

		/**********��Ա�����Ķ���**********/
	private:
		void GetSno();//����ѧ��
		bool SearchStuInfo(string strClass);//��ѯѧ��������Ϣ
		bool searchGradeInfo(string strClass);//��ѯѧ���γ̷�����Ϣ
		
		string sno;//ѧ����ѧ��
	};

}


#endif