#ifndef CANTEEN_H
#define CANTEEN_H
#include "LinkList.h"
#include <iomanip>
//学生****************************************************************************************************
class Student
{
private:
	string name;
	int CurAccount;//当前账户余额


public:
	Student(string _name = "无名氏", int _curAccount = 200)
	{
		this->name = _name;
		this->CurAccount = _curAccount;
	}
	void Set(string _name = "无名氏", int _curAccount = 200)
	{
		this->name = _name;
		this->CurAccount = _curAccount;
	}
	friend ostream& operator<<(ostream& out, const Student& s);
	friend class CanteenWindow;

};




//餐厅***************************************************************************************************
//其实这个餐厅类在后面没有用到，不过先放这里吧
class Canteen
{
public:
	Canteen(string _name="上大食堂")
	{
		CanteenName = _name;
	}
	
	~Canteen()
	{

	}
	void ShowCanteen()
	{
		
	}

private:
	string CanteenName;
	LinkList<CanteenWindow> CanteenWindowsList;//食堂的窗口链表
};


//窗口*****************************************************************************************************
class CanteenWindow
{
private:
	int CurIncome;//当前收入
	int useTime;//每个人花费的时间/单位时间
	int useMonney;//每个人花费的金钱
	string windowName;
	LinkList<Student> StudentsList;//当前窗口学生排队情况
	Node<Student>* PtrStudent;
public:
	
	CanteenWindow(string _windowName = "窗口", int _useTime = 1, int _useMonney=5,int _curIncome=0):windowName(_windowName),useTime(_useTime),useMonney(_useMonney),CurIncome(_curIncome),PtrStudent(NULL)
	{
	}
	void SetCanteenWindow(string _windowName = "窗口", int _useMonney=5)
	{
		this->windowName = _windowName;
		this->useMonney = _useMonney;
	}
	string Name()
	{
		return windowName;
	}
	
	void Append(Student newStudent)
	{
		StudentsList.Append(newStudent);
	}
	operator string() const
	{
		return windowName;
	}
	void Show(ostream& out) const
	{
		out << windowName;
	}
	void AfterTime()
	{
		StudentsList.DeleteHead();
	}
	friend ostream& operator<<(ostream& out, const CanteenWindow &c);
	

};

//************************************************************************************************************
//下面是一些运算符的重载
ostream& operator<<(ostream& out, const CanteenWindow& c)
{
	c.Show(out);
	c.StudentsList.PutList(out);
	return out;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << "->"<<s.name;
	return out;
}

#endif 
