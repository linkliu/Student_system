#include"student.h"
#include"StudentInfo.h"
#include"gradeinfo.h"


namespace student
{
	void CStudent::GetSno()//����ѧ��
	{
		cin>>this->sno;
	}


	void CStudent::SearchUser()//����ѧ����Ϣ���ⲿ�ӿڣ�
	{
		cout<<"��������İ༶:"<<endl;
		string strClass;//��ð༶��Ϣ
		cin>>strClass;

		cout<<"��ѡ����Ҫ��ѯ�����ݣ�(1.ѧ��������Ϣ��ѯ;2.�γ̳ɼ���ѯ):\n";
		int judge = 0;//ѡ���������
		cin>>judge;
		if(judge == 1)//��ѯѧ��������Ϣ
		{
			SearchStuInfo(strClass);
		}
		else if(judge ==2)//��ѯѧ���γ���Ϣ
		{
			searchGradeInfo(strClass);
		}
		else
		{
			cout<<"�������"<<endl;
		}
	}


	//��ѯѧ��������Ϣ
	bool CStudent::SearchStuInfo(string strClass)
	{

		ifstream fin;//�򿪸ð༶��ѧ��������Ϣ�ļ�
		fin.open(strClass+".txt");
		{
			if(!fin.is_open())
			{
				cerr<<"�����ڸð༶������༶�����Ƿ���ȷ��"<<endl;
				fin.clear();//���������Ϣ��
				return false;
			}
		}
		using studentinfo::CStuinfo;
		CStuinfo stu;//����һ��CStuinfo�Ķ���
		stu.str_class = strClass;//��ð༶��Ϣ
		stu.DisplayStuInfo();

		using studentinfo::BaseData;//��ѧ��������Ϣװ���ڴ�
		int m = 0;//������¼��¼������
		BaseData * re = stu.ExchangeData(fin,strClass,m);//����һ��BaseData����(��CStuinfo����)

		//���ѧ����Ϣ
		cout<<"���������ѧ��:"<<endl;
		GetSno();

		//�ڼ�¼�в�ѯ
		int i = 0;
		while(i < m)
		{
			if(re[i].sno == this->sno)//�ڼ�¼���ҵ�Ҫ��ѯ��ѧ���ļ�¼
			{
				cout<<"��������Ҫ��ѯ�ļ�¼:\n";
				cout<<"1.ѧ��\t\t2.�Ա�\t3.ѧ��\t\t4.��������\t5.��ͥסַ\t6.��ϵ�绰\t\n";
				cout<<re[i].sno<<"\t"<<re[i].gend<<"\t"<<re[i].sno<<"\t"<<re[i].birth<<"\t"<<re[i].adress<<" \t"<<re[i].phone<<"\t\n";
				break;
			}
			i++;

		}

		if(i > m-1)
		{
			cout<<"û�иü�¼"<<endl;
			delete [] re;//�ͷ��ڴ�
			return false;
		}

		fin.close();//�ر��ļ�
		delete [] re;//�ͷ��ڴ�
		return true;
	}



	//��ѯѧ���γ̷�����Ϣ

	bool CStudent::searchGradeInfo(string strClass)
	{
		ifstream fin;//��strClass�༶�ĳɼ��ļ�
		fin.open("g"+strClass+".txt");
		if(!fin.is_open())
		{
			cerr<<"�����ڸð༶������༶�����Ƿ���ȷ��"<<endl;
			fin.clear();//���������Ϣ���Ա�������ԵĶ�ȡ����Ӱ��
			return false;
		}
		double **pn_ClassGrade=NULL;//�༶����Ϊ������һ����άָ�룬�ڴ涯̬����
		string *pstr_Sno=NULL;//ѧ����Ϣ
		int nColumn;//��¼������
		int nRow;//��¼������

		//gradeinfo::CGradeinfo info;//����һ��CGradeinfo�Ķ���
		using gradeinfo::CGradeinfo;
		CGradeinfo info;//����һ��CGradeinfo��Ķ�����Ϊ����Ҫ�õ��ܶ�CGradeinfo��ĳ�Ա����
		info.str_class = strClass;//��ð༶��Ϣ
		pn_ClassGrade=info.ExchangeData(info.str_class,fin,&pstr_Sno,nRow,nColumn);//���ļ��е����ݶ����ڴ�
		fin.clear();//���������Ϣ
		fin.close();//�ر��ļ�


		//��ʾ�ɼ���Ϣ
		fin.open("g"+info.str_class+".txt");
		string strHeadInfo;//��ͷ��Ϣ
		getline(fin,strHeadInfo);
		fin.close();
		info.Display(strHeadInfo,pn_ClassGrade,pstr_Sno,nRow,nColumn);



		cout<<"��������Ҫ��ѯ��ѧ�ţ�"<<endl;
		cin>>this->sno;//����ѧ��

		int m=0;//������¼����ѧ�����ڵļ�¼��λ��

		if(info.SearchStu(this->sno,pstr_Sno,nRow,m))
		{
			cout<<"��������Ҫ��ѯ����Ϣ��"<<endl;
			cout<<setw(pstr_Sno[m].length())<<pstr_Sno[m]<<"  ";//ѧ�ŵ������
			for(int firdex = 0;firdex < nColumn-1;firdex++)//��ʾҪ��ѯ����Ϣ
			{
				cout<<pn_ClassGrade[m][firdex];
				cout<<"  ";
			}
			cout<<endl;
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
			return true;
		}
		else
		{
			cout<<"����ѯ����Ϣ������"<<endl;

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
			return false;
		}

	}

}

