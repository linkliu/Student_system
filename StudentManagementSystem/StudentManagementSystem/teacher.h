#ifndef TEACHER_H_
#define TEACHER_H_
#include "user.h"

//using namespace user;

namespace teacher
{

	//��ʦ��Ķ���
	class CTeacher:public CUser
	{
		/*************�����Ķ���**********/
	public:
		CTeacher(){};
		~CTeacher(){};
		void SearchUser();//��ѯѧ����Ϣ(�ⲿ�ӿ�)
		void CreateClass();//�µİ༶��Ϣ(�ⲿ�ӿ�)
		bool InsertInfo();//����ѧ����Ϣ(�ⲿ�ӿ�)
		int ChangeInfo();//�޸�ѧ����Ϣ(�ⲿ�ӿ�)
		bool DeleteInfo();//ɾ��ѧ����Ϣ(�ⲿ�ӿ�)
		void ShowInfo();//��ʾѧ����Ϣ(�ⲿ�ӿ�)

		/*************��Ա�����Ķ���**********/
	public:
		string teacherId;//��ʦ�Ľ�ְ����

	};

}


#endif