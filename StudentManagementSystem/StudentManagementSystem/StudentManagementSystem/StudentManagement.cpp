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
	cout<<"    ________________________________________________________________________"<<endl;
	cout<<"                                                                        "<<endl;
	cout<<"    ------------------------��ӭʹ��ѧ����Ϣ����ϵͳ------------------------"<<endl;
	cout<<endl<<endl<<endl<<endl;
	while(1)
	{
		cout<<"                ����ѡ�����:1)��ʦ��¼  2)ѧ����¼  3)�˳�ϵͳ"<<endl;
		int m_identity;
		cin>>m_identity;//����������
		system("cls");//��������
		if(m_identity == 1)//��ʦ��¼ϵͳ
		{
			system("cls");//��������

			while(1)
			{
				system("cls");//��������
				cout<<"                               ��ӭ���½��ϵͳ"<<endl<<endl<<endl;
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
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 2:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.DeleteInfo();//ɾ��
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 3:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.ChangeInfo();//�޸�
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 4:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.SearchUser();//��ѯ
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 5:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.ShowInfo();//��ʾ
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 6:
					{
						using teacher::CTeacher;//������ʦ��
						CTeacher teacher;//����һ��CTeacher��Ķ���
						teacher.CreateClass();//�½�
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;

					}
				case 7://�˳���¼
					{
						cout<<"���˳���¼"<<endl;
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;
					}
				default:
					{
						cout<<"����ѡ�����������ѡ�������"<<endl;
						cout<<"�س�������"<<endl;
						cin.get();
						getchar();
						break;
					}
				}
				if(m_type == 7) break;//�˳���¼
			}

		}
		else if(m_identity == 2)//ѧ����¼ϵͳ
		{
			cout<<"                               ��ӭ���½��ϵͳ"<<endl<<endl<<endl;
			cout<<"                          ������ѧ��ֻ�в�ѯ�Ĳ���!"<<endl;
			cout<<"�س�������"<<endl;
			cin.get();
			getchar();
			while(1)
			{
				system("cls");//��������
				cout<<"�������������:1)��ѯ  2)�˳���¼"<<endl;
				int m_type;
				cin>>m_type;
				if(m_type == 1)
				{
					using student::CStudent;
					CStudent stu;//����һ��CStudent�Ķ���
					stu.SearchUser();//��ѯ
					cout<<"�س�������"<<endl;
					cin.get();
					getchar();
				}
				else if(m_type == 2)
				{
					cout<<"���˳���¼"<<endl;
					cout<<"�س�������"<<endl;
					cin.get();
					getchar();
					break;
				}
				else
				{
					cout<<"����ѡ�����������ѡ�������"<<endl;
					cout<<"�س�������"<<endl;
					cin.get();
					getchar();
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