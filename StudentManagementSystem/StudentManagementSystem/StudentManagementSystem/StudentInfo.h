#ifndef STUINFO_H_
#define STUINFO_H_
#include "ofenuse.h"

namespace teacher
{
	class CTeacher;
}

namespace studentinfo
{
	// ��Ϣ�������Ľṹ��
	typedef struct BaseData
	{
		string name;
		string sno;
		char gend; 
		string birth;
		string phone;
		string adress; 
	public:
		BaseData  operator = (const BaseData data)
		{

			this->name  = data.name;
			this->sno = data.sno;
			this->gend = data.gend;
			this->birth = data.birth;
			this->phone = data.phone;
			this->adress = data.adress;
			return  *this;

		}

	}BaseData;

	//ѧ��������Ϣ��Ķ���
	class CStuinfo
	{

		/*********�ӿ�*********/
	public:
		CStuinfo(){}
		~CStuinfo(){}
		void GetClass();//��ð༶��Ϣ
		void InsertStuInfo();//ѧ��������Ϣ�Ĳ��루�ⲿ�ӿڣ�
		void ChangeStuInfo();//�޸�ѧ��������Ϣ���ⲿ�ӿڣ�
		void DeleteStuInfo();//ɾ���༶ѧ����Ϣ���ⲿ�ӿڣ�
		bool DisplayStuInfo();//��ʾѧ���Ļ�����Ϣ���ⲿ�ӿڣ�
		BaseData * ExchangeData(ifstream &fin,string Class,int & m);//�ļ����ݽ�������(�ⲿ�ӿ�)
		friend class teacher::CTeacher;//��CTeacher������Ϊ��CStuinfo���һ�����࣬����Ϊ��CTeacher����Ҫ�õ����CStuinfo��ĳ�Ա����
		/*********����*********/
	protected:
		void Insert();//����
	private:
		bool Change();//ѧ��������Ϣ���޸�
		bool Delete(string strClass);//ѧ��������Ϣ��ɾ��



		/*********��Ա����*********/
	public:
		string name;        //ѧ��������
		string birth;       //ѧ���ĳ�������
		char gend;          //ѧ���Ա�
	protected:
		string sno;         //ѧ��ѧ��
	private:
		string phone;       //ѧ������ϵ��ʽ
		string adress;      //ѧ����סַ

	public:
		string str_class;    //�༶��Ϣ

	};


}

#endif
