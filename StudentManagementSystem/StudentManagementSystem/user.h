#ifndef USER_H_
#define USER_H_
#include "ofenuse.h"


//用户类的定义
class CUser
{

public:
	CUser(){}
	~CUser(){}
	void SearchUser()const;//查询用户

public:
	string name;//用户名
	char gend;//用户性别
};




#endif