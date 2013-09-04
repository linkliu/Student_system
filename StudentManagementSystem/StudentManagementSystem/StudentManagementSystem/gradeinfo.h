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
		/*�����Ķ���*/
	public:
		void GetClass();//��ð༶��Ϣ
		bool InsertGradeInfo();//��ɼ���Ϣ�в���ѧ���ɼ���¼���ⲿ�ӿڣ�
		bool DeleteGradeInfo();//ɾ���ɼ���Ϣ�е�ѧ���ɼ���¼���ⲿ�ӿڣ�
		void CreateGradeInfo();//���һ���༶�Ŀγ̷���ͳ�ƣ��ⲿ�ӿڣ�
		bool SearchStu(string & sno,string * pstr_Sno,int nRow,int & m);//����һ��ѧ���Ƿ�����ڼ�¼����(�ⲿ�ӿ�)
 //   	friend bool student::CStudent::searchGradeInfo(string strClass);//��CStudent���е�SearchGradeInfo()��������Ϊ��CGradeinfo���һ����Ԫ�������Ϳ��Է���CGradeinfo���е�˽�г�Ա������
		friend class student::CStudent;//��CStudent�ඨ��ΪCGradeinfo���һ�����࣬��Ϊ��CStudent����Ҫ�õ���CGradeinfo�������Ա����
		friend class teacher::CTeacher;//��CTeacher�ඨ��ΪCGradeinfo���һ�����࣬��Ϊ��CTeacher����Ҫ�õ���CGradeinfo�������Ա����

	private:
		void Display(string strHead,double ** nClassGrade,string * pSno,int nRow,int nColumn);//��ͷ�ĸ�ʽ�����
		double ** ExchangeData(string strClass,ifstream & fin,string **str_Sno,int & nRow,int & nColumn);//�ļ����ݽ�������
		bool Delete(string strClass);//ɾ���ɼ���¼
		string * GetCourseInfo(int & m);//��ÿγ���Ϣ
		int GetRecord();//��ÿγ̷�����¼�ĸ���
		void PutIntoFile(string strClass,double ** nClassGrade,string * strSno,string strHead,int endRow,int nColumn);//���ڴ��е��������뵽�ļ�
		


		/*��Ա����*/

	public:
		string sno;
	private:
		double * grade;
		string * course;

	public:
		string str_class;    //�༶��Ϣ
	};

}

#endif


