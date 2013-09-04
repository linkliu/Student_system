#include"student.h"
#include"StudentInfo.h"
#include"teacher.h"
#include"gradeinfo.h"



int main(void)
{
	/***********测试用例************/
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
	cout<<"    ------------------------欢迎使用学生信息管理系统------------------------"<<endl;
	cout<<endl<<endl<<endl<<endl;
	while(1)
	{
		cout<<"                请您选择操作:1)老师登录  2)学生登录  3)退出系统"<<endl;
		int m_identity;
		cin>>m_identity;//获得身份类型
		system("cls");//清屏操作
		if(m_identity == 1)//老师登录系统
		{
			system("cls");//清屏操作

			while(1)
			{
				system("cls");//清屏操作
				cout<<"                               欢迎你登陆该系统"<<endl<<endl<<endl;
				cout<<"请输入你想要的操作类型:1)插入  2)删除  3)修改  4)查询  5)显示  6)新建 7)退出登录"<<endl;
				int m_type;
				cin>>m_type;
				switch(m_type)
				{
				case 1:
					{
						using teacher::CTeacher;//引用老师类
						CTeacher teacher;//定义一个CTeacher类的对象
						teacher.InsertInfo();//插入
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 2:
					{
						using teacher::CTeacher;//引用老师类
						CTeacher teacher;//定义一个CTeacher类的对象
						teacher.DeleteInfo();//删除
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 3:
					{
						using teacher::CTeacher;//引用老师类
						CTeacher teacher;//定义一个CTeacher类的对象
						teacher.ChangeInfo();//修改
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 4:
					{
						using teacher::CTeacher;//引用老师类
						CTeacher teacher;//定义一个CTeacher类的对象
						teacher.SearchUser();//查询
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 5:
					{
						using teacher::CTeacher;//引用老师类
						CTeacher teacher;//定义一个CTeacher类的对象
						teacher.ShowInfo();//显示
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;
					}
				case 6:
					{
						using teacher::CTeacher;//引用老师类
						CTeacher teacher;//定义一个CTeacher类的对象
						teacher.CreateClass();//新建
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;

					}
				case 7://退出登录
					{
						cout<<"已退出登录"<<endl;
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;
					}
				default:
					{
						cout<<"操作选择错误，请重新选择操作！"<<endl;
						cout<<"回车键继续"<<endl;
						cin.get();
						getchar();
						break;
					}
				}
				if(m_type == 7) break;//退出登录
			}

		}
		else if(m_identity == 2)//学生登录系统
		{
			cout<<"                               欢迎你登陆该系统"<<endl<<endl<<endl;
			cout<<"                          声明：学生只有查询的操作!"<<endl;
			cout<<"回车键继续"<<endl;
			cin.get();
			getchar();
			while(1)
			{
				system("cls");//清屏操作
				cout<<"请输入操作类型:1)查询  2)退出登录"<<endl;
				int m_type;
				cin>>m_type;
				if(m_type == 1)
				{
					using student::CStudent;
					CStudent stu;//定义一个CStudent的对象
					stu.SearchUser();//查询
					cout<<"回车键继续"<<endl;
					cin.get();
					getchar();
				}
				else if(m_type == 2)
				{
					cout<<"已退出登录"<<endl;
					cout<<"回车键继续"<<endl;
					cin.get();
					getchar();
					break;
				}
				else
				{
					cout<<"操作选择错误，请重新选择操作！"<<endl;
					cout<<"回车键继续"<<endl;
					cin.get();
					getchar();
				}
			}


		}
		else if(m_identity == 3)//退出系统
		{
			cout<<"系统已退出"<<endl;
			break;
		}
		else
		{
			cout<<"身份认证失败，请重新选择!"<<endl;
		}
	}



	return 0;
}