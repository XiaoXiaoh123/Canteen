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
		cout << "1--��Ӵ���" <<  endl;
		cout << "2--��ѯ����" << endl;
		cout << "3--���ѧ��" << endl;
		cout << "4--�鿴����ʳ��״̬" << endl;
		cout << "5--ʱ�俪ʼ����" << endl;
		cout << "9--�˳�" << endl;
		cin >> operateFlag;
		if (operateFlag > 5 || operateFlag < 1)
		{
			cout << "�������,������ȷ������"<<endl;
		}
		//���죺���������״̬���Ż������if_else
		if (operateFlag == 1)
		{
			cout << "���봰������:";
			cin >> Window_name;
			cout << "���봰�ڵļ۸�:";
			cin >> Window_price;
			newCanteenWindow.SetCanteenWindow(Window_name, Window_price);
			ListWindows.Append(newCanteenWindow);
			cout << "��ӳɹ�"<<endl;
		}
		else if (operateFlag == 2)
		{
			cout << "�����ѯ�Ĵ�������" << endl;
			cin >> Window_name;
			
			newCanteenWindow.SetCanteenWindow(Window_name);
			PtrWindow = ListWindows.Locate(string(newCanteenWindow), true);
			if (PtrWindow == NULL)
			{
				cout << "δ��ѯ���ô���,�˳����β���" << endl;
			}
			else
			{
				cout << "��ѯ���˴���" << endl;
				cout << ListWindows.CurData();
			}
		}
		else if (operateFlag == 3)
		{
			cout << "������ѧ������:";
			cin >> Student_name;
			cout << "������ѧ���˻����:";
			cin >> Student_Account;
		    newStudent.Set(Student_name, Student_Account);
			cout << "��ѧ��Ҫȥ�ĸ������Ŷ�:";
			cin >> Window_name;
			newCanteenWindow.SetCanteenWindow(Window_name);
			PtrWindow = ListWindows.Locate(string(newCanteenWindow), true);//���Ҵ˴���
			while (PtrWindow == NULL)
			{
				cout << "�ô��ڲ����ڣ����������봰��";
				cin >> Window_name;
				PtrWindow = ListWindows.Locate(string(newCanteenWindow), true);
			}
			ListWindows.CurData().Append(newStudent);
			cout << "��ӳɹ�"<<endl;
			
		}
		else if (operateFlag == 4)
		{
			cout << ListWindows;
		}
		else if (operateFlag == 5)
		{
			//ʱ������1��λʱ�䲢�Ҵ�ӡʳ��״̬
			CurrentTime += 1;
			
			//ɾ�� ���������� ÿ�����ڵ�ѧ������ �� ͷ�ڵ�
			ListWindows.CurData().AfterTime();//���ֻ����ɾ�� ��ǰ���ڽڵ� �� ѧ������ �� ��һ����
			cout << CurrentTime<<endl;
			cout << ListWindows;
		}
		else if (operateFlag == 9) break;
	}
	
	
};