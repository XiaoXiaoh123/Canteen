#include"Canteen.h"

void CanteenTest()
{
	LinkList<CanteenWindow> ListWindows;
	Node<Student> *PtrStudent;
	Node<CanteenWindow> *PtrWindow;
	CanteenWindow newCanteenWindow;
	Student newStudent;
	string Window_name;
	string  Student_name;
	int Window_price;
	int Student_Account;
	int flag1;
	int operateFlag;
	int CurrentTime = 0;
	
	while (true)
	{
		printf("\n");
		cout << "1--添加窗口" <<  endl;
		cout << "2--查询窗口" << endl;
		cout << "3--添加学生" << endl;
		cout << "4--查看整个食堂状态" << endl;
		cout << "5--时间开始流动" << endl;
		cout << "9--退出" << endl;
		cin >> operateFlag;
		if (operateFlag > 5 || operateFlag < 1)
		{
			cout << "输入错误,请重新确定操作"<<endl;
		}
		//待办：或许可以用状态机优化下面的if_else
		if (operateFlag == 1)
		{
			cout << "输入窗口名字:";
			cin >> Window_name;
			cout << "输入窗口的价格:";
			cin >> Window_price;
			newCanteenWindow.SetCanteenWindow(Window_name, Window_price);
			ListWindows.Append(newCanteenWindow);
			cout << "添加成功"<<endl;
		}
		else if (operateFlag == 2)
		{
			cout << "输入查询的窗口名字" << endl;
			cin >> Window_name;
			
			newCanteenWindow.SetCanteenWindow(Window_name);
			PtrWindow = ListWindows.Locate(string(newCanteenWindow), true);
			if (PtrWindow == NULL)
			{
				cout << "未查询到该窗口,退出本次操作" << endl;
			}
			else
			{
				cout << "查询到此窗口" << endl;
				cout << ListWindows.CurData();
			}
		}
		else if (operateFlag == 3)
		{
			cout << "请输入学生名字:";
			cin >> Student_name;
			cout << "请输入学生账户余额:";
			cin >> Student_Account;
		    newStudent.Set(Student_name, Student_Account);
			cout << "该学生要去哪个窗口排队:";
			cin >> Window_name;
			newCanteenWindow.SetCanteenWindow(Window_name);
			PtrWindow = ListWindows.Locate(string(newCanteenWindow), true);//查找此窗口
			while (PtrWindow == NULL)
			{
				cout << "该窗口不存在，请重新输入窗口";
				cin >> Window_name;
				PtrWindow = ListWindows.Locate(string(newCanteenWindow), true);
			}
			ListWindows.CurData().Append(newStudent);
			cout << "添加成功"<<endl;
			
		}
		else if (operateFlag == 4)
		{
			cout << ListWindows;
		}
		else if (operateFlag == 5)
		{
			//时间流动1单位时间并且打印食堂状态
			CurrentTime += 1;
			
			//删除 窗口链表中 每个窗口的学生链表 的 头节点
			ListWindows.CurData().AfterTime();//这个只可以删除 当前窗口节点 的 学生链表 的 第一个人
			cout << CurrentTime<<endl;
			cout << ListWindows;
		}
		else if (operateFlag == 9) break;
	}
	
	
};