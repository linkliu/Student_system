#ifndef STUINFO_H_
#define STUINFO_H_
#include "ofenuse.h"

namespace teacher
{
	class CTeacher;
}

namespace studentinfo
{
	// 信息交换区的结构体
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

	//学生基本信息类的定义
	class CStuinfo
	{

		/*********接口*********/
	public:
		CStuinfo(){}
		~CStuinfo(){}
		void GetClass();//获得班级信息
		void InsertStuInfo();//学生基本信息的插入（外部接口）
		void ChangeStuInfo();//修改学生基本信息（外部接口）
		void DeleteStuInfo();//删除班级学生信息（外部接口）
		bool DisplayStuInfo();//显示学生的基本信息（外部接口）
		BaseData * ExchangeData(ifstream &fin,string Class,int & m);//文件数据交换函数(外部接口)
		friend class teacher::CTeacher;//把CTeacher类声明为类CStuinfo类的一个友类，是因为在CTeacher类中要用到许多CStuinfo类的成员函数
		/*********方法*********/
	protected:
		void Insert();//插入
	private:
		bool Change();//学生基本信息的修改
		bool Delete(string strClass);//学生基本信息的删除



		/*********成员变量*********/
	public:
		string name;        //学生的姓名
		string birth;       //学生的出生年月
		char gend;          //学生性别
	protected:
		string sno;         //学生学号
	private:
		string phone;       //学生的联系方式
		string adress;      //学生的住址

	public:
		string str_class;    //班级信息

	};


}

#endif
