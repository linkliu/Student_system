#include"student.h"
#include"StudentInfo.h"
#include"teacher.h"
#include"gradeinfo.h"



int main(void)
{
	/***********��������************/
	//	studentinfo::CStuinfo stu;
	//	stu.GetClass();
	//	stu.InsertStuInfo();
	//	stu.ChangeStuInfo();
	//	stu.DeleteStuInfo();
	//	stu.DisplayStuInfo();
	//	gradeinfo::CGradeinfo info;
	//	info.GetClass();
	//	info.CreateGradeInfo();
	//	info.InsertGradeInfo(4);
	//	int m = info.GetRecord();

	//	info.DeleteGradeInfo();

	//	student::CStudent stu;
	//	stu.SearchUser();


	//	using teacher::CTeacher;
	//	CTeacher tea;
	//	tea.SearchUser();
	//	tea.CreateClass();

	cout<<"��ӭʹ��ѧ����Ϣ����ϵͳ(^_^)"<<endl;
	while(1)
	{
		cout<<"����ѡ�����:1)��ʦ��¼  2)ѧ����¼  3)�˳�ϵͳ"<<endl;
		int m_identity;
		cin>>m_identity;//����������
		if(m_identity == 1)//��ʦ��¼ϵͳ
		{
			while(1)
			{
				cout<<"��ӭ���½��ϵͳ"<<endl;
				cout<<"����������Ҫ�Ĳ�������:1)����  2)ɾ��  3)�޸�  4)��ѯ  5)��ʾ  6)�½� 7)�˳���¼"<<endl;
				int m_type;
				cin>>m_type;
				switch(m_type)
				{
				case 1:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.InsertInfo();//����
						break;
					}
				case 2:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.DeleteInfo();//ɾ��
						break;
					}
				case 3:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.ChangeInfo();//�޸�
						break;
					}
				case 4:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.SearchUser();//��ѯ
						break;
					}
				case 5:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.ShowInfo();//��ʾ
						break;
					}
				case 6:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.CreateClass();//�½�
						break;

					}
				case 7://�˳���¼
					{
						cout<<"���˳���¼"<<endl;
						break;
					}
				default:
					{
						cout<<"����ѡ�����������ѡ�������"<<endl;
						break;
					}
				}
				if(m_type == 7) break;//�˳���¼
			}

		}
		else if(m_identity == 2)//ѧ����¼ϵͳ
		{

				cout<<"������ѧ��ֻ�в�ѯ�Ĳ���!"<<endl;
				while(1)
				{
					cout<<"�������������:1)��ѯ  2)�˳���¼"<<endl;
					int m_type;
					cin>>m_type;
					if(m_type == 1)
					{
					using student::CStudent;
					CStudent stu;//����һ��CStudent�Ķ���
					stu.SearchUser();//��ѯ
					}
					else if(m_type == 2)
					{
						cout<<"���˳���¼"<<endl;
						break;
					}
					else
					{
						cout<<"����ѡ�����������ѡ�������"<<endl;
					}
				}
	

		}
		else if(m_identity == 3)//�˳�ϵͳ
		{
			cout<<"ϵͳ���˳�"<<endl;
			break;
		}
		else
		{
			cout<<"�����֤ʧ�ܣ�������ѡ��!"<<endl;
		}
	}



	return 0;
}