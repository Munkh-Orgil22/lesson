#include <iostream>
using namespace std;

class Bank {
	private:
		char name[30];
	
	public:
		void bvrtgel();
		void openAccount();
		 
};

class Customer{
	private:
		char name[20];
		int address;
		
	public:
		void bvrtgel()
		{
			cout << "Ta neree oruulna uu:";
			cin >> name;
			cout << "Ta geriin haygaa oruulna uu:";
			cin >> address;
		}
		void showBvrtgel()
		{
			cout << "Ner:" << name << endl;
			cout << "Hayg:" << address << endl;
		}
		
		
};

class Account {
	public:
    	int acno;
    	long balance;
	public:
    	void OpenAccount()
    	{	
        	cout << "Dansnii dugaaraa bvrtgvvlne vv: ";
        	cin >> acno;
        	cout << "Dansandaa bairshuulah mongon dvngee oruulna uu: ";
        	cin >> balance;
    	}
    	void ShowAccount()
    	{
        	cout << "Dansnii dugaar: " << acno << endl;
        	cout << "Vldegdel: " << balance << endl;
    	}
		void Deposit()
    	{
        	long income;
        	cout << "Orlogiin hemjeeg oruulna uu: ";
        	cin >> income;
        	balance = balance + income;
    	}
    	void Withdrawal()
    	{
        	long zar;
        	cout << "Zarlagiin hemjeeg oruulna uu: ";
        	cin >> zar;
        	if (zar <= balance)
            	balance = balance - zar;
        	else
            	cout << "Vldegdelgvi baina..." << endl;
    	}	
		
	int Search(int);
    
};

int Account::Search(int a)
{
    if (acno == a) {
        ShowAccount();
        return (1);
    }
    return (0);
}


int main()
{
    Account A;
    Customer C; 

    int found = 0, a, ch;
    
    	C.bvrtgel();
        A.OpenAccount();
    

    do {
        // hereglegchtei haritsah heseg
        cout << "\n\n1:Display All\n2:information of account\n3:Deposit\n4:Withdraw\n5:Exit" << endl;

    
        cout << "Umnuh dugaariig songono uu: ";
        cin >> ch;

        switch (ch) {
        case 1: 
            C.showBvrtgel();
            A.ShowAccount();
            
            break;
        case 2: //dansnii medeelel
            cout << "Dansnii dugaar? ";
            cin >> a;
            found = A.Search(a);
            if (found)
                break;
            
            if (!found)
                cout << "Dans oldsongvi." << endl;
            break;
        case 3: // orlogo hiih
            cout << "Orlogo hiih dansnii dugaaraa oruulna uu? ";
            cin >> a;
                found = A.Search(a);
                if (found) {
                    A.Deposit();
                    break;
                }
            if (!found)
                cout << "Dans oldsongvi." << endl;
            break;
        case 4: // zarlaga
            cout << "Zarlaga hiih dansnii dugaaraa oruulna uu? ";
            cin >> a;
                found = A.Search(a);
                if (found) {
                    A.Withdrawal();
                    break;
                }
            if (!found)
                cout << "Dans oldosongvi." << endl;
            break;
        case 5: // exit
            cout << "Have a nice day!" << endl;
            break;
        default:
            cout << "Wrong Option" << endl;
        }
    } while (ch != 5);
    return 0;
}
