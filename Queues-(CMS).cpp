#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class customer
{
public:
	string name;
	int sno;
	string address;
	int age;
	int bill;

	customer()
	{
		name = "Noname";
		sno = 0;
		address = "Noaddress";
		bill = -1;
	}

	void input()
	{
		int v = 1;
		cout << "\n********************************************";
		SetConsoleTextAttribute(h, 10);
		cout << " \n\t\t Enter customer's Record\n";
		SetConsoleTextAttribute(h, 6);
		cout << " Customer ID : ";
		cin>>sno;
		cout << " Name        : ";
		cin >> name;
		cout << " Address     : ";
		cin >> address;
		cout << " Age         : ";
		cin >> age;
		cout << " Bill        : ";
		cin >> bill;
		SetConsoleTextAttribute(h, 7);
		cout << "************************************************\n";
		SetConsoleTextAttribute(h, 4);
		cout << "\n Customer ADDED to QUEUE !!! \n";
		SetConsoleTextAttribute(h, 7);
	}

	void display_customer()
	{
		
		SetConsoleTextAttribute(h, 10);
		cout << "\n******************************************************\n";
		cout << " Customer ID           : " << sno << endl;
		cout << " NAME                  : " << name << endl;
		cout << " ADDRESS of CUSTOMER   : " << address << endl;
		cout << " AGE                   : " << age << endl;
		cout << " BILL                  : " << bill << endl;
		cout << "******************************************************\n\n\n";
		SetConsoleTextAttribute(h, 7);
	}
};

class Queue
{
public:
	customer* arr;
	customer* served;
	int front, front2;
	int rear,rear2;
	int size,ttl=0;

	Queue()
	{
		SetConsoleTextAttribute(h, 2);
		cout << "\n\n\t\t\t\t-----> Enter Size of the Queue : <--------\n\n\n\n\n";
		SetConsoleTextAttribute(h, 7);
		cin >> size;
		system("cls");
		arr = new customer[size];
		served = new customer[size];
		front = rear = -1;
		front2 = rear2 = -1;
	}

	bool isfull()
	{
		if (rear== size - 1)
			return true;
		else return false;
	}

	bool isempty()
	{
		if (front == -1 && rear==-1)
			return true;
		else return false;
	}

	bool isempty2()
	{
		if (rear2 == -1 && front2 == -1)
			return true;
		else return false;
	}

	void enqueue(customer c)
	{
		if (isfull())
		{
			SetConsoleTextAttribute(h, 4);
			cout << " The Queue is FUll, You have to wait !!! "<<endl;
			SetConsoleTextAttribute(h, 7);
			return;
		}
		else
		{
			if (isempty())
			{
				front++;
				rear++;
				arr[rear] = c;
			}
			else
			{
				rear++;
				arr[rear] = c;
			}
		}
	}
	
	
	void dequeue()
	{
		if (isempty())
		{
			SetConsoleTextAttribute(h, 4);
			cout << " The Queue is Empty ! Nothing to Delete !!!" << endl;
			SetConsoleTextAttribute(h, 7);
			return;
		}
		else
		{
			if (isempty2())
			{
				ttl++;
				front2++;
				rear2++;
				served[rear2] = arr[front];
				cout << "\n******************************************************************************";
				SetConsoleTextAttribute(h, 4);
				cout << "\n Customer named '" << arr[front].name << "' Left the Queue ! \n";
				SetConsoleTextAttribute(h, 7);
				cout << "******************************************************************************\n";
				front++;
			}
			else
			{
				ttl++;
				rear2++;
				served[rear2] = arr[front];
				cout << "\n******************************************************************************";
				SetConsoleTextAttribute(h, 4);
				cout << "\n Customer named '" << arr[front].name << "' Left the Queue ! \n";
				SetConsoleTextAttribute(h, 7);
				cout << "******************************************************************************\n";
				front++;
			}
			
		}
	}


	void display()
	{
		if (isempty())
		{
			SetConsoleTextAttribute(h, 4);
			cout << " Currently No Customer's Record Exists in the Queue\n";
			SetConsoleTextAttribute(h, 7);
		}
		else
		{
			for (int i = front; i <= rear; i++)
			{
				cout << " Displaying Customer " << i + 1 << "'s Record";
				arr[i].display_customer();
			}
		}
	}

	void display_served()
	{
		if (isempty2())
		{
			SetConsoleTextAttribute(h, 4);
			cout << " No Customer is Served Uptill Now!!! \n";
			SetConsoleTextAttribute(h, 7);
		}
		else
		{
			cout << " \n\n\t\t Customers Served \n\n";
			for (int i = front2; i <= rear2; i++)
			{
				served[i].display_customer();
			}
		}
	}


	int getttl()
	{
		return ttl;
	}

	

	int getaged()
	{
		int z = 0;
		for (int i = front; i <= rear; i++)
		{
			if (arr[i].age > 50)
			{
				z++;
			}
		}
		return z;
	}

	void priortize()
	{
		
		int tage, tbill, tsno,ch;
		string tname, taddress;
		system("cls");
		cout << "\n****************************************************";
		SetConsoleTextAttribute(h, 6);
		cout << "\n 1. No of Customers with AGE>50                    *";
		cout << "\n 2. Priortize all the Elder Customers              *";
		cout << "\n 0. Return to Menu                                 *\n";
		SetConsoleTextAttribute(h, 7);
		cout << "*****************************************************\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("cls");
			SetConsoleTextAttribute(h, 3);
			cout << " \n\n\t\t Total Customers with AGE>50 : " << getaged() << endl << endl;
			SetConsoleTextAttribute(h, 7);
			break;
		case 2:
			system("cls");
			for (int i = front; i <= rear; i++)
			{
				for (int j = i + 1; j <= rear; j++)
				{
					if (arr[j].age > arr[i].age)
					{
						tsno = arr[j].sno;
						arr[j].sno = arr[i].sno;
						arr[i].sno = tsno;


						tname = arr[j].name;
						arr[j].name = arr[i].name;
						arr[i].name = tname;

						taddress = arr[j].address;
						arr[j].address = arr[i].address;
						arr[i].address = taddress;
						
						tage=arr[j].age;
						arr[j].age = arr[i].age;
						arr[i].age = tage;

						tbill = arr[j].bill;
						arr[j].bill = arr[i].bill;
						arr[i].bill = tbill;
					}
				}
			}

			SetConsoleTextAttribute(h, 10);
			cout << " \n All the elder Customers have given the Priorty in the QUEUE !!!\n";
			SetConsoleTextAttribute(h, 7);
			break;
		case 0:
			return;
			break;
		default : 
			SetConsoleTextAttribute(h, 4);
			cout << "\n Invalid Input !! Please Select from the Given !!!\n";
			SetConsoleTextAttribute(h, 7);
		}
	}

	void search(int id)
	{
		int ch;
		for (int i = front; i <= rear; i++)
		{
			if (arr[i].sno == id)
			{
				SetConsoleTextAttribute(h, 12);
				cout << "\n\n \t Customer with ID :   " << id << "     Found !!";
				cout << "\n Press 1 for Details ";
				cout << "\n Press 2 To Exit \n";
				SetConsoleTextAttribute(h, 7);
				cin >> ch;
				if (ch == 1)
				{
					arr[i].display_customer();
				}
				else
				{
					return;
				}
			}
		}
	}

	void billgreaterthan5000()
	{
		int c = 0;
		SetConsoleTextAttribute(h, 6);
		cout << " \n\n  Record of Customers with bill Greater than 5000 : \n";
		SetConsoleTextAttribute(h, 7);
		for (int i = front; i <= rear; i++)
		{
			if (arr[i].bill>5000)
			{	
				c++;
				cout << " \n Mr/Ms." << arr[i].name << endl;
				arr[i].display_customer();
			}
		}
		if (c == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\n No Customers with bill greater than 5000 found !!! \n ";
			SetConsoleTextAttribute(h, 7);
		}
	}

	void appearsmorethanonce()
	{
		int c = 0;
		for (int i = front; i <= rear; i++)
		{
			for (int j = i + 1; j <= rear; j++)
			{
				if (arr[i].sno == arr[j].sno)
				{
					c++;
					cout << " \n Mr/Ms." << arr[i].name << " Appeared More than once \n";
					cout << "\n\t\t Details: \n\n";
					arr[i].display_customer();
				}
			}
		}
		if (c == 0)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\n No Customers Appeared more tha once !!! \n ";
			SetConsoleTextAttribute(h, 7);
		}
	}


	void operations()
	{
		int ch,id;
		SetConsoleTextAttribute(h, 12);
		cout << "\n\n\t\t\t  SELECT From THE FOLLOWING OPERATIONS \n\n";
		SetConsoleTextAttribute(h, 7);
		cout << "\n *****************************************************";
		SetConsoleTextAttribute(h, 6);
		cout << "\n 1. Total Number of Customers Served                *";
		cout << "\n 2. Details of  the customers Served                *";
		cout << "\n 3. Find The Customer by Customer ID                *";
		cout << "\n 4. Show Customers with Bill Greater than 5000      *";
		cout << "\n 5. Customer which Appears more than once           *";
		cout << "\n 0. Return to Main Menu                             *\n";
		SetConsoleTextAttribute(h, 7);

		cout << "**********************************************************\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("cls");
			SetConsoleTextAttribute(h, 12);
			cout << " \n\n Total Number of Customer Served : " << getttl() << endl << endl;
			SetConsoleTextAttribute(h, 7);
			break;
		case 2:
			system("cls");
			display_served();
			break;
		case 3:
			system("cls");
			SetConsoleTextAttribute(h, 6);
			cout << "\n\t Enter Customer ID to Search : ";
			SetConsoleTextAttribute(h, 7);
			cin >> id;
			search(id);
			break;
		case 4:
			system("cls");
			billgreaterthan5000();
			break;
		case 5:
			system("cls");
			appearsmorethanonce();
			break;
		case 0:
			return;
			break;
		default:
			cout << "\n Inavlid Input ! Choose from te given options \n ";

		}


	}

};

int main()
{

	int ch,x, repeat;
	customer c;
	Queue q;

	do{
		SetConsoleTextAttribute(h, 4);
		cout << " \n\t\t\t MENU\t\n";
		SetConsoleTextAttribute(h, 7);
		cout << "**********************************************************\n";
		SetConsoleTextAttribute(h, 6);
		cout << " 1. EnQUEUE                                               *\n";
		cout << " 2. DeQUEUE                                               *\n";
		cout << " 3. Display                                               *\n";
		cout << " 4. Priortize                                             *\n";
		cout << " 5. Opertations                                           *\n";
		cout << " 0. Exit                                                  *\n";
		SetConsoleTextAttribute(h, 7);
		cout << "**********************************************************\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("cls");
			c.input();
			q.enqueue(c);
			break;
		case 2:
			system("cls");
			q.dequeue();
			break;
		case 3:
			system("cls");
			q.display();
			break;
		case 4:
			system("cls");
			q.priortize();
			break;
		case 5:
			system("cls");
			q.operations();
			break;

		case 0:
			return 0;
			break;
		default:
			cout << " INVALID INPUT ! Coose from the given options !!!\n";
		}

		cout << " Press 1 to Return to MENU \n";
		cin >> x;
		system("cls");
	} while (x == 1);


	system("pause");
	return 0;
}