#include "StudentInfo.h"
//#include<string.h>
//���뺯��

namespace studentinfo
{
	//��ð༶��Ϣ
	void CStuinfo::GetClass()
	{
		cout<<"������༶��Ϣ:"<<endl;
		cin>>this->str_class;
	}

	//����
	void CStuinfo::Insert()
	{

		cout<<"����������:"<<endl;
		cin>>name;
		cout<<"�������Ա�:"<<endl;
		cin>>gend;
		cout<<"������ѧѧ��:"<<endl;
		cin>>sno;
		cout<<"�������������(��1991-02-12):"<<endl;
		cin>>birth;
		cout<<"�������ͥסַ:"<<endl;
		cin>>adress;
		cout<<"��������ϵ�绰:"<<endl;
		cin>>phone;

	}

	//��༶����ѧ���Ļ�����Ϣ
	void CStuinfo::InsertStuInfo()
	{
		ofstream fout(this->str_class+".txt",ios_base::app);
		Insert();
		string inform =name+" "+gend +" "+sno+" "+birth+" "+adress+" "+phone+"\n";

		fout<<inform;
		fout.clear();
		fout.close();

		cout<<"��¼�Ѿ���¼"<<endl;

	}


	//�޸�ѧ��������Ϣ���ⲿ�ӿڣ�
	void CStuinfo::ChangeStuInfo()
	{
		Change();
	}


	//�޸�ѧ���Ļ�����Ϣ����(private)
	bool CStuinfo::Change()
	{
		ifstream fin;
		fin.open(this->str_class+".txt");
		if(!fin.is_open())
		{
			cerr<<"�޸Ĵ�������༶�����Ƿ���ȷ��"<<endl;
			fin.clear();//���������Ϣ���Ա�������ԵĶ�ȡ����Ӱ��
			return false;
		}
		int m = 0;//������¼��¼������
		BaseData * re  =  ExchangeData(fin,this->str_class,m);//������м�¼
		cout<<"������Ҫ�޸ĵ�ѧ����ѧ��"<<endl;

		string nSno ;
		cin>>nSno;
		int i =0;
		while(i<m)
		{
			if(re[i].sno == nSno)//�ڼ�¼���ҵ�Ҫ�޸ĵ�ѧ���ļ�¼
			{
				cout<<"��������Ҫ�޸ĵļ�¼��"<<endl;
				cout<<"      1.����  2.�Ա�        3.ѧ��     4.��������         5.��ַ     6.��ϵ��ʽ\n";
				cout<<setfill(' ')<<setw(12)<<re[i].name
					<<setfill(' ')<<setw(7)<<re[i].gend
					<<setfill(' ')<<setw(15)<<re[i].sno
					<<setfill(' ')<<setw(15)<<re[i].birth
					<<setfill(' ')<<setw(15)<<re[i].adress
					<<setfill(' ')<<setw(15)<<re[i].phone<<"\n";
				cout<<"��������Ҫ�޸Ĳ��ֵ����:"<<endl;
				int nchange;
				cin>>nchange;
				switch(nchange)
				{
				case 1:
					cout<<"�������µ����֣�";
					cin>>re[i].name;
					cout<<"��¼�Ѿ������޸�"<<endl;
					break;
				case 2:
					cout<<"�������µ��Ա�";
					cin>>re[i].gend;
					cout<<"��¼�Ѿ��ɹ��޸�"<<endl;
					break;
				case 3:
					cout<<"�������µ�ѧ�ţ�";
					cin>>re[i].sno;
					cout<<"��¼�Ѿ������޸�"<<endl;
					break;
				case 4:
					cout<<"�������µĳ�������:";
					cin>>re[i].birth;
					cout<<"��¼�Ѿ������޸�"<<endl;
					break;
				case 5:
					cout<<"�������µĵ�ַ:";
					cin>>re[i].adress;
					cout<<"��¼�Ѿ������޸�"<<endl;
					break;
				case 6:
					cout<<"�������µ���ϵ�绰��";
					cin>>re[i].phone;
					cout<<"��¼�Ѿ������޸�"<<endl;
					break;
				default:
					cout<<"���������Ų���ȷ"<<endl;
					break;
				}
				break;
			}
			i++;
		}

		fin.clear();
		fin.close();

		if(i > m-1)
		{
			cout<<"û�иü�¼"<<endl;
			return false;
		}
		else
		{
			//������Ҫ���޸Ĺ����������·Ż��ļ���
			ofstream chanfout;
			chanfout.open(this->str_class+".txt");
			for(int firdex = 0;firdex < m;firdex++)
			{
				chanfout<<re[firdex].name+" "+re[firdex].gend +" "+re[firdex].sno+" "+re[firdex].birth+" "+re[firdex].adress+" "+re[firdex].phone+"\n";
			}
			chanfout.close();//�ر��ļ�

		}

		delete [] re;//�ͷ��ڴ�

		return true;



	}

	//�ļ����ݽ�������
	BaseData *  CStuinfo::ExchangeData(ifstream &fin,string Class,int & m)
	{
		int num = 0;//��¼�ð༶��ѧ������������¼�ĸ�����
		string base;
		//���ļ�����ʼ���ļ��еļ�¼���м���
		while(getline(fin,base))  num++;
		//���ڴ��з���ռ䣬Ϊ�����¼����ռ�
		BaseData * record = new BaseData[num];//����ط��ǳ�Σ�գ������Ҫ�ǵ��ͷ��ڴ�
		fin.clear();
		fin.close();
		fin.open(Class+".txt");//���´��ļ�����ͷ��ʼ��ȡ��¼
		for(int firdex = 0;firdex<num;firdex++)//���ļ��еļ�¼ת���ڴ�
		{
			getline(fin,base);
			istringstream sin(base);
			sin>>record[firdex].name;
			sin>>record[firdex].gend;
			sin>>record[firdex].sno;
			sin>>record[firdex].birth;
			sin>>record[firdex].adress;
			sin>>record[firdex].phone;
		}
		m = num;//��ü�¼�ĸ���
		return record;//������м�¼

	}




	//ɾ��ѧ����¼(�ڲ�����)
	bool CStuinfo::Delete(string strClass)
	{
		//��ѧ����Ϣ�ļ�
		ifstream fin;
		fin.open(strClass+".txt");
		if(!fin.is_open())
		{
			cerr<<"ɾ����������༶�����Ƿ���ȷ��"<<endl;
			fin.clear();//���������Ϣ��
			return false;
		}
		int m = 0;//������¼��¼������
		BaseData * re  =  ExchangeData(fin,strClass,m);//������м�¼
		cout<<"������Ҫɾ����ѧ����ѧ��"<<endl;
		string nSno ;
		cin>>nSno;

		int i = 0;
		while(i<m)
		{
			if(re[i].sno == nSno)
			{
				cout<<"��������Ҫɾ���ļ�¼��"<<endl;
				cout<<"        ����    �Ա�          ѧ��       ��������           ��ַ       ��ϵ��ʽ \n";
				cout<<setfill(' ')<<setw(12)<<re[i].sno
					<<setfill(' ')<<setw(7)<<re[i].gend
					<<setfill(' ')<<setw(15)<<re[i].sno
					<<setfill(' ')<<setw(15)<<re[i].birth
					<<setfill(' ')<<setw(15)<<re[i].adress
					<<setfill(' ')<<setw(15)<<re[i].phone<<"\n";
				cout<<"�Ƿ�Ҫɾ��(Y/N)"<<endl;
				char sure;
				cin>>sure;
				if(sure=='Y' || sure=='y')
				{
					for(int firdex = i;firdex<m-1;firdex++)//������Ϣ������Ҫɾ���ļ�¼��
					{
						re[firdex] = re[firdex+1];//���λ�������⡣��Ҫ�Ľ�
					}
				}
				else
				{
					cout<<"ɾ����ȡ��"<<endl;
					return false;
				}

				break;

			}
			i++;
		}


		if(i > m-1)
		{
			cout<<"ɾ������û�иü�¼"<<endl;
			return false;
		}
		else
		{
			//������Ҫ���޸Ĺ����������·Ż��ļ���
			ofstream chanfout;
			chanfout.open(strClass+".txt");
			for(int firdex = 0;firdex < m-1;firdex++)
			{
				chanfout<<re[firdex].name+" "+re[firdex].gend +" "+re[firdex].sno+" "+re[firdex].birth+" "+re[firdex].adress+" "+re[firdex].phone+"\n";
			}
			chanfout.close();
			cout<<"��¼��ɾ��"<<endl;

		}

		delete [] re;//�ͷ��ڴ�

		return true;

	}



	//ɾ��ѧ����Ϣ(�ӿ�)

	void CStuinfo::DeleteStuInfo()
	{
	
		Delete(this->str_class);
	}


	bool CStuinfo::DisplayStuInfo()
	{
		ifstream fin;
		fin.open(this->str_class+".txt");
		if(!fin.is_open())
		{
			cerr<<"��ʾ��������༶�����Ƿ���ȷ��"<<endl;
			fin.clear();//���������Ϣ��
			return false;
		}

		int m = 0;//������¼��¼������
		BaseData * re  =  ExchangeData(fin,this->str_class,m);//������м�¼
		cout<<this->str_class<<"�༶�Ļ�����Ϣ���£�\n"<<endl;
		cout<<"        ����    �Ա�          ѧ��       ��������           ��ַ       ��ϵ��ʽ \n";
		for(int firdex = 0;firdex<m;firdex++)//��ʾ���е�ѧ��������Ϣ
		{
			cout<<setfill(' ')<<setw(12)<<re[firdex].name
				<<setfill(' ')<<setw(7)<<re[firdex].gend
				<<setfill(' ')<<setw(15)<<re[firdex].sno
				<<setfill(' ')<<setw(15)<<re[firdex].birth
				<<setfill(' ')<<setw(15)<<re[firdex].adress
				<<setfill(' ')<<setw(15)<<re[firdex].phone<<endl<<endl;

		}
		delete [] re;
		return true;
	}

}