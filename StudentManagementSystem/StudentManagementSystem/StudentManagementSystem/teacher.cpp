#include"teacher.h"
#include"StudentInfo.h"
#include"gradeinfo.h"
#include"student.h"


namespace teacher
{
	//��ѯѧ����Ϣ(�ⲿ�ӿ�)
	void CTeacher::SearchUser()
	{
		using student::CStudent;
		CStudent stu;
		//����student��SearchUser()����
		stu.SearchUser();
	}

	//�µİ༶��Ϣ(�ⲿ�ӿ�)

	void CTeacher::CreateClass()
	{
		ofstream fout;
		cout<<"������Ҫ�����İ༶��:"<<endl;
		string strClass;
		cin>>strClass;
		bool judge1 = false;//�ж��Ƿ���ڸð༶�Ļ�����Ϣ
		bool judge2 = false;//�ж��Ƿ���ڸð༶�Ŀγ̳ɼ���Ϣ
		ifstream fin;

		//�༶������Ϣ���ж�
		fin.open(strClass+".txt");
		if(fin.is_open())
		{
			judge1 = true;//���Դ�
			fin.clear();
			fin.close();
		}

		//�༶�γ̳ɼ���Ϣ���ж�
		fin.open("g"+strClass+".txt");
		if(fin.is_open())
		{
			judge2 = true;//���Դ�
			fin.clear();
			fin.close();
		}

		if(judge1||judge2)//����Ѿ����ڸð༶����Ϣ���Ͳ����½���
		{
			cout<<"�ð༶��Ϣ�Ѵ���"<<endl;
		}
		else
		{
			fout.open(strClass+".txt");//�½��ð༶�Ļ�����Ϣ
			fout.clear();
			fout.close();
			fout.open("g"+strClass+".txt");//�½��ð༶�Ŀγ̳ɼ���Ϣ
			fout.clear();
			fout.close();
			cout<<"�༶�Ѿ��½�"<<endl;
		}

	}

	//����ѧ����Ϣ(�ⲿ�ӿ�)
	bool CTeacher::InsertInfo()
	{
		int m_choice;//�������Ϣ������
		cout<<"����Ҫ�������Ϣ����:1.ѧ��������Ϣ | 2.ѧ���γ̷�����Ϣ"<<endl;
		cin>>m_choice;
		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//����һ��CStuinfo�Ķ���
			stu.GetClass();//��ð༶��Ϣ
			stu.InsertStuInfo();//��༶����ѧ��������Ϣ
			return true;
		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//����һ��CGradeinfo��Ķ���
			gradeinfo.GetClass();//��ð༶��Ϣ
			gradeinfo.InsertGradeInfo();//��༶����γ̷�����Ϣ
			return true;

		}
		else
		{
			cout<<"����ѡ������"<<endl;
			return false;
		}

	}


	//�޸�ѧ����Ϣ(�ⲿ�ӿ�)

	int CTeacher::ChangeInfo()
	{
		//����Ҫ˵��һ�£�
		cout<<"Ϊ�˸���Ϣϵͳ�ṩһ����ȫ�Ļ�����\"2.ѧ���γ̷�����Ϣ\"û���ṩ�޸Ĳ���!"<<endl;
		int m_choice;//�������Ϣ������
		cout<<"����Ҫ�޸ĵ���Ϣ����:1.ѧ��������Ϣ | 2.ѧ���γ̷�����Ϣ"<<endl;
		cin>>m_choice;

		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//����һ��CStuinfo�Ķ���
			stu.GetClass();//��ð༶��Ϣ
			stu.DisplayStuInfo();//��ʾ�༶������Ϣ
			stu.ChangeStuInfo();//�޸İ༶������Ϣ

			return 1;//��ʾ����Ϊ1����
		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//����һ��CGradeinfo�Ķ���
			gradeinfo.GetClass();//��ð༶��Ϣ
			cout<<"�Բ��𣬿γ���Ϣ���޸�ֻ����ɾ�������!"<<endl;
			if(gradeinfo.DeleteGradeInfo())//ɾ��Ҫ�޸ĵĿγ̷�����Ϣ��¼
			{
				gradeinfo.InsertGradeInfo();//����ҪĿ��γ̷�����Ϣ��¼
				return 2;
			}
			else
			{   
				cout<<"û��ɾ�����޷��޸ģ�"<<endl;
				return 0;//��ʾ����Ĳ�������
			}
		}
		else
		{
			cout<<"����ѡ������"<<endl;
			return 0;//��ʾ����Ĳ�������
		}

	}


	//ɾ��ѧ����Ϣ(�ⲿ�ӿ�)

	bool CTeacher::DeleteInfo()
	{
		int m_choice;//�������Ϣ������
		cout<<"����Ҫɾ������Ϣ����:1.ѧ��������Ϣ | 2.ѧ���γ̷�����Ϣ"<<endl;
		cin>>m_choice;
		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//����һ��CStuinfo�Ķ���
			stu.GetClass();//��ð༶��Ϣ
			stu.DeleteStuInfo();//ɾ��ѧ��������Ϣ
			return true;
		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//����һ��CGradeinfo��Ķ���
			gradeinfo.GetClass();//��ð༶��Ϣ
			gradeinfo.DeleteGradeInfo();//ɾ��ѧ���γ̷�����Ϣ
			return true;

		}
		else
		{
			cout<<"����ѡ������"<<endl;
			return false;
		}

	}

	//��ʾѧ����Ϣ(�ⲿ�ӿ�)
	void CTeacher::ShowInfo()
	{
		int m_choice;//Ҫ��ʾ����Ϣ������
		cout<<"����Ҫ��ʾ����Ϣ����:1.ѧ��������Ϣ | 2.ѧ���γ̷�����Ϣ"<<endl;
		cin>>m_choice;
		if(m_choice == 1)
		{
			using studentinfo::CStuinfo;
			CStuinfo stu;//����һ��CStuinfo�Ķ���
			stu.GetClass();//��ð༶��Ϣ
			stu.DisplayStuInfo();//��ʾѧ��������Ϣ

		}
		else if(m_choice == 2)
		{
			using gradeinfo::CGradeinfo;
			CGradeinfo gradeinfo;//����һ��CGradeinfo��Ķ���
			gradeinfo.GetClass();//��ð༶��Ϣ
			//gradeinfo.InsertGradeInfo();//ɾ��ѧ���γ̷�����Ϣ
			ifstream fin;//��strClass�༶�ĳɼ��ļ�
			fin.open("g"+gradeinfo.str_class+".txt");
			if(!fin.is_open())
			{
				cerr<<"�����ڸð༶������༶�����Ƿ���ȷ��"<<endl;
				fin.clear();//���������Ϣ���Ա�������ԵĶ�ȡ����Ӱ��
				return ;
			}

			double **pn_ClassGrade=NULL;//�༶����Ϊ������һ����άָ�룬�ڴ涯̬����
			string *pstr_Sno=NULL;//ѧ����Ϣ
			int nColumn;//��¼������
			int nRow;//��¼������

			pn_ClassGrade=gradeinfo.ExchangeData(gradeinfo.str_class,fin,&pstr_Sno,nRow,nColumn);
			fin.clear();//���������Ϣ
			fin.close();//�ر��ļ�


			fin.open("g"+gradeinfo.str_class+".txt");
			string strHeadInfo;//��ͷ��Ϣ
			getline(fin,strHeadInfo);
			gradeinfo.Display(strHeadInfo,pn_ClassGrade,pstr_Sno,nRow,nColumn);

			//�ڴ��ͷ�
			for(int firdex = 0;firdex < nRow;firdex++)
			{
				delete pn_ClassGrade[firdex];//�ͷ�ÿ����Ԫ�Ķ�̬�ڴ�
				pn_ClassGrade[firdex] = NULL;
			}
			delete [] pn_ClassGrade;

			delete [] pstr_Sno;
			pstr_Sno=NULL;
			pn_ClassGrade = NULL;


		}
		else
		{
			cout<<"����ѡ������"<<endl;

		}

	}


}


