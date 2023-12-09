#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
	string name;
	double balance;
public:
	BankAccount(string nameAcc, double accBalance)
		:name(nameAcc), balance(accBalance) {}

	void deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
		}
		else
		{
			cout << "Invalid amount" << endl;
		}

	}

	void withdraw(double amount)
	{
		if (amount > 0 && amount <= balance)
		{
			balance -= amount;
			cout << "Withdrawal successful " << "Ur new Amount is " << balance << endl;
		}
		else
		{
			cout << "Invalid amount" << endl;
		}
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Balance: " << balance << endl;
	}
};




int main()
{
	string name;
	double balance;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "Enter balance: ";
	cin >> balance;
	BankAccount account(name, balance);

	int choice;
	double amount;

	do
	{
		cout << "1. Deposit" << endl;
		cout << "2. Withdraw" << endl;
		cout << "3. Display" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter amount to deposit: ";
			cin >> amount;
			account.deposit(amount);
			break;
		case 2:
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			account.withdraw(amount);
			break;
		case 3:
			account.display();
			break;
		case 4:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 4);


}

