#ifndef CANTEEN_H
#define CANTEEN_H
#include "LinkList.h"
#include <iomanip>
//ѧ��****************************************************************************************************
class Student
{
private:
	string name;
	int CurAccount;//��ǰ�˻����


public:
	Student(string _name = "������", int _curAccount = 200)
	{
		this->name = _name;
		this->CurAccount = _curAccount;
	}
	void Set(string _name = "������", int _curAccount = 200)
	{
		this->name = _name;
		this->CurAccount = _curAccount;
	}
	friend ostream& operator<<(ostream& out, const Student& s);
	friend class CanteenWindow;

};




//����***************************************************************************************************
//��ʵ����������ں���û���õ��������ȷ������
class Canteen
{
public:
	Canteen(string _name="�ϴ�ʳ��")
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
	LinkList<CanteenWindow> CanteenWindowsList;//ʳ�õĴ�������
};


//����*****************************************************************************************************
class CanteenWindow
{
private:
	int CurIncome;//��ǰ����
	int useTime;//ÿ���˻��ѵ�ʱ��/��λʱ��
	int useMonney;//ÿ���˻��ѵĽ�Ǯ
	string windowName;
	LinkList<Student> StudentsList;//��ǰ����ѧ���Ŷ����
	Node<Student>* PtrStudent;
public:
	
	CanteenWindow(string _windowName = "����", int _useTime = 1, int _useMonney=5,int _curIncome=0):windowName(_windowName),useTime(_useTime),useMonney(_useMonney),CurIncome(_curIncome),PtrStudent(NULL)
	{
	}
	void SetCanteenWindow(string _windowName = "����", int _useMonney=5)
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
//������һЩ�����������
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
