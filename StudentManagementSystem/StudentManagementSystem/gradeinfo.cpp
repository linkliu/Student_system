#include"gradeinfo.h"

namespace gradeinfo{

	void CGradeinfo::GetClass()//��ð༶��Ϣ
	{
		cout<<"������༶��Ϣ:"<<endl;
		cin>>this->str_class;
	}


	//���һ���༶�Ŀγ̷���ͳ�ƣ��ⲿ�ӿڣ�
	void CGradeinfo::CreateGradeInfo()
	{
		ofstream fout;
		fout.open("g"+this->str_class+".txt");//�½���һ���γ̷���
		if(!fout.is_open())
		{
			cerr<<"�½�ʧ��!"<<endl;
			fout.clear();
			return ;
		}
		//	course = new string [nCourse];//Ϊÿ���γ�������洢�ռ�
		//���ǵ��ͷſγ���������Ķ�̬�ڴ�ռ�

		int m=0;
		course = GetCourseInfo(m);//��ÿγ̵�����

		fout<<"  Sno  ";

		for(int firdex = 0;firdex<m;firdex++)//�½��γ̷����ı�ͷ(�����ǵ������ݿ�ģ���ʵ�ı��ļ����������ģ�ֻ��Ϊ�˷���˵��)
		{
			fout<<course[firdex]+"  ";//����Ŀ
		}

		fout<<"\n";//��ͷ�������
		fout.close();//�ر��ļ�

		delete [] course;//�ͷſ�Ŀ������ռ�õĶ�̬�ڴ�
	}

	//��ÿγ���Ϣ(�ڲ�����)
	string* CGradeinfo::GetCourseInfo(int &m)
	{
		cout<<"������γ̵�������(0-20)"<<endl;
		cin>>m;//��ÿγ̵�����
		//	grade = new double[nCourse];
		string * pCourse = new string [m];//��������γ̵�������Ϣ

		for(int firdex = 0;firdex<m;firdex++)
		{
			cout<<"������γ� "<<firdex<<" ������"<<endl;
			cin>>pCourse[firdex];
		}

		for(int secdex = 0;secdex < m;secdex++)
			cout<<pCourse[secdex]<<endl;

		return pCourse;
	}



	double ** CGradeinfo::ExchangeData(string strClass,ifstream & fin,string ** str_Sno, int & n_Row,int & n_Column)//�ļ����ݽ�������
	{

		string strHeadInfo;//��ͷ��Ϣ
		getline(fin,strHeadInfo);//��ÿγ̳ɼ��ı�ͷ��Ϣ
		istringstream sin(strHeadInfo);//��istringstream ����ָ��string����ʹ֮������C++������������strHeadInfo���������ַ�
		int nColumn;//��¼������
		int nRow;//��¼������
		string strCourse;
		for(nColumn = 0;sin>>strCourse;nColumn++);//��ÿγ̷���������

		nRow = GetRecord();

		(*str_Sno) = new string [nRow];//Ϊÿ����¼����һ��ѧ��

		double **nClassGrade;//�༶����Ϊ������һ����άָ�룬�ڴ涯̬����
		//�ǵ�Ҫ�ں����ͷ��ڴ�
		nClassGrade = new double* [nRow];//Ϊ�༶�γ̷����ά��̬�ڴ棬
		for(int firdex = 0;firdex < nRow;firdex++ )
			nClassGrade[firdex] = new double [nColumn-1];//ѧ�Ų���������
		//��ʱ��ǵ��ͷ��ڴ�
		string strGrade;

		//������ļ��еĿγ̷�����Ϣװ���ڴ�
		for(int firdex = 0;getline(fin,strGrade) && firdex< nRow;firdex++)
		{
			istringstream sin(strGrade);
			sin>>(*str_Sno)[firdex];//ѧ�ŷֿ��洢
			for(int secdex = 0;secdex<nColumn-1;secdex++)//����secdex��1��ʼ������Ϊѧ����һ�в��Ƿ����ķ�Χ
			{
				sin>>nClassGrade[firdex][secdex];
				int m = 0;
			}
		}

		n_Row = nRow;//��������
		n_Column = nColumn;//��������������������ѧ�ŵ�����
		int m =0;
		return nClassGrade;//ͨ���ɼ��Ķ�άָ�뷵�سɼ���Ϣ;

		//���ǵ��ڵ������ĵط��ͷŶ�̬�ڴ�

	}



	//ɾ���ɼ���¼
	bool CGradeinfo::Delete(string strClass )
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

		pn_ClassGrade=ExchangeData(strClass,fin,&pstr_Sno,nRow,nColumn);
		fin.clear();//���������Ϣ
		fin.close();//�ر��ļ�


		fin.open("g"+strClass+".txt");
		string strHeadInfo;//��ͷ��Ϣ
		getline(fin,strHeadInfo);
		Display(strHeadInfo,pn_ClassGrade,pstr_Sno,nRow,nColumn);





		cout<<"��������Ҫɾ����ѧ�ţ�"<<endl;
		cin>>this->sno;//����ѧ��

		int m=0;//������¼����ѧ�����ڵļ�¼��λ��

		if(SearchStu(this->sno,pstr_Sno,nRow,m))
		{
			cout<<"��������Ҫɾ������Ϣ��"<<endl;
			cout<<setw(pstr_Sno[m].length())<<pstr_Sno[m]<<"  ";//ѧ�ŵ������
			for(int firdex = 0;firdex < nColumn-1;firdex++)//��ʾҪɾ������Ϣ
			{
				cout<<pn_ClassGrade[m][firdex];
				cout<<"  ";
			}
			cout<<endl;
			char sure;
			cout<<"�Ƿ�Ҫɾ����(Y/N)"<<endl;
			cin>>sure;
			if(sure=='y' || sure=='Y')
			{
				//�ڵ���PutInfoFile�����������ʱ����Ҫ��Ҫɾ����������¼���ǵ�
				for(int firdex = m;firdex < nRow-1;firdex++)
				{
					pstr_Sno[firdex] = pstr_Sno[firdex+1];//ѧ�ŵĸ���
					for(int secdex = 0;secdex < nColumn;secdex++)//���ǿγ̷���
						pn_ClassGrade[firdex][secdex] = pn_ClassGrade[firdex+1][secdex]; 

				}

				PutIntoFile(strClass,pn_ClassGrade,pstr_Sno,strHeadInfo,nRow,nColumn);//���ڴ��е�����д���ļ�
				cout<<"��¼��ɾ��"<<endl;
				return true;

			}
			else
			{
				cout<<"ɾ���Ѿ�ȡ��"<<endl;
				return false;
			}
		}
		else
		{
			cout<<"û�иü�¼"<<endl;
			return false;
		}



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


	bool CGradeinfo::DeleteGradeInfo()
	{
		if(Delete(this->str_class)) return true;
		return false;
	}

	//��ÿγ̷�����¼�ĸ���

	int CGradeinfo::GetRecord()
	{
		ifstream fin;
		fin.open("g"+this->str_class+".txt");//���ļ�
		string strHead;
		getline(fin,strHead);//ȡ�߱�ͷ����Ϊ��ͷ�����������Ҫ���ص���Ϣ
		int nRecord=0;
		for(;getline(fin,strHead);nRecord++);//�Լ�¼���м���
		fin.close();//�ر��ļ�
		return nRecord;//���ؼ�¼�����������������
	}




	//��γ̳ɼ���Ϣ���в����µ���Ϣ���ⲿ�ӿڣ�
	bool CGradeinfo::InsertGradeInfo()
	{
		ifstream fin;//���ļ�
		fin.open("g"+this->str_class+".txt");
		if(!fin.is_open())
		{
			fin.clear();
			cerr<<"�ļ����ܴ򿪻��ļ�������.";
			return false;
		}

		string strInfo;//��ͷ��Ϣ
		getline(fin,strInfo);//���ļ��л�ñ�ͷ��Ϣ

		fin.clear();//���������Ϣ
		fin.close();//�ر��ļ�

		istringstream sin1(strInfo);//�ӱ�ͷ�ַ����ж�
		int nCourseNum=0;

		for(string base;sin1>>base;nCourseNum++);//��ÿγ̵���Ŀ
		course = new string [nCourseNum-1];//Ϊÿ���γ�������һ���ռ�(��Ϊ�����ѧ������Ҫ��ȥ1)
		istringstream sin2(strInfo);
		string te;
		sin2>>te;//���˵�ѧ����Ϣ���Ӷ������ȷ�ı�ͷ��Ϣ
		for(int i = 0;sin2>>course[i];i++);
		//	grade = new double [nCourseNum];//Ϊÿÿһ�ſγ̷�������洢�Ŀռ�
		//ע����ʹ�ú�Ҫ�ͷ��ڴ棬�����ڴ�й©
		string strSno;
		cout<<"������ѧ����ѧ�ţ�"<<endl;
		cin>>strSno;
		rewind(stdin);
		ofstream fout("g"+this->str_class+".txt",ios_base::app);//���ļ�
		fout<<strSno+"   ";
		for(int firdex = 0;firdex < nCourseNum-1;firdex++)
		{
			cout<<"\n������"<<course[firdex]<<"�ĳɼ���"<<endl;
			double nGrade= 0.0;
			cin>>nGrade;
			fout<<nGrade;//���ļ�������γ̷�����Ϣ
			fout<<"  ";
		}

		fout<<"\n";//ÿ����¼��һ��
		fout.clear();//���������Ϣ
		fout.close();//�ر��ļ�

		cout<<"�����Ѿ���¼!"<<endl;

		delete [] course;//�ͷſγ���������Ķ�̬�ڴ�

		return true;


	}


	//��ͷ�ĸ�ʽ�����(�ڲ�����)

	void CGradeinfo::Display(string strHead,double ** nClassGrade,string * pSno,int nRow,int nColumn)
	{


		string * pstr_Head = new string[nColumn];//��ñ�ͷ��Ϣ
		//�ǵ��ͷ��ڴ���Ϣ
		istringstream sin(strHead);
		for(int firdex = 0;firdex<nColumn && sin>>pstr_Head[firdex];firdex++);

		//���������ͷ
		cout<<setw(pSno[0].length())<<pstr_Head[0]<<"  ";//ѧ����һ�бȽ�����
		for(int secdex = 1;secdex < nColumn;secdex++)
			cout<<pstr_Head[secdex]<<"  ";
		cout<<endl;

		//��������γ̷�����Ϣ

		for(int firdex = 0;firdex < nRow;firdex++)
		{
			cout<<pSno[firdex];
			for(int secdex = 0;secdex < nColumn-1;secdex++)//ѧ��Ҫ�����������Ϊ�����洢��nClassGrade�У�����pSno��
			{
				cout<<setw(pstr_Head[secdex+1].length()+2)<<nClassGrade[firdex][secdex];
			}
			cout<<endl;
		}

		delete [] pstr_Head;



	}


	//����һ��ѧ���Ƿ�����ڼ�¼����(�ⲿ�ӿ�)
	bool CGradeinfo::SearchStu(string & sno,string * pstr_Sno,int nRow,int & m)
	{
		for(int firdex = 0;firdex < nRow;firdex++)
		{
			if(pstr_Sno[firdex]==sno)
			{
				m = firdex;//�����к�
				return true;
			}

		}
		return false;
	}

	//���ڴ��е��������뵽�ļ�
	void CGradeinfo::PutIntoFile(string strClass,double ** nClassGrade,string * strSno,string strHead,int nRow,int nColumn)
	{

		ofstream fout;
		fout.open("g"+strClass+".txt");//�򿪿γ���Ϣ�ļ�
		if(!fout.is_open())
		{
			cerr<<"�γ��ļ������ڻ��ߴ�ʧ��"<<endl;
			fout.clear();
			return ;
		}
		fout<<strHead<<"\n";//�ѱ�ͷд���ļ�
		//������ڴ��е�����д���ļ�
		for(int firdex  = 0; firdex < nRow-1;firdex++)
		{
			fout<<strSno[firdex]<<"  ";
			for(int secdex = 0;secdex < nColumn-1;secdex++)
			{
				fout<<nClassGrade[firdex][secdex]<<" ";
			}
			fout<<"\n";
		}

		fout.clear();
		fout.close();//�ر��ļ�


	}


}