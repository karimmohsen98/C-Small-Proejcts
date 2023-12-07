// To_Do_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Task
{
	string task;
	string date;
	string time;
};

void showTask(const vector<Task> &task)
{
	cout << "Task List: " << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < task.size(); ++i)
	{
		cout << i + 1 << ". Description: " << task[i].task << " | Date: " << task[i].date << " | Time: " << task[i].time << endl;
	}
	
}
void searchTask(const vector<Task>& tasks, const string& searchTerm)
{
	cout << "Search Results: " << endl;
	cout << "---------------------" << endl;
	for (int i = 0; i < tasks.size(); ++i)
	{
		if (tasks[i].task.find(searchTerm) != string::npos ||
			tasks[i].date.find(searchTerm) != string::npos ||
			tasks[i].time.find(searchTerm) != string::npos)
		{
			cout << "Description: " << tasks[i].task << " | Date: " << tasks[i].date << " | Time: " << tasks[i].time << endl;
		}
	}
}

int main()
{
	vector<Task> tasks;
	vector<Task> newTasks; 
	Task task;
	char choice;

	ifstream inputFile("task.txt");
	while (inputFile >> task.task >> task.date >> task.time)
	{
		tasks.push_back(task);
	}
	inputFile.close();

	string searchTerm;

	ofstream outputFile("task.txt", ios::app);

	do
	{
		cout << "Menu: " << endl;
		cout << "---------------------" << endl;
		cout << "1. Show Task List" << endl;
		cout << "2. Add Task" << endl;
		cout << "3. Search for Task" << endl;
		cout << "4. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
			case '1':
			    showTask(tasks);
			    break;
			case '2':
				cout << "Enter a task: ";
				cin.ignore();
				getline(cin, task.task);
				cout << "Enter a date: ";
				cin >> task.date;
				cout << "Enter a time: ";
				cin >> task.time;
				newTasks.push_back(task);
				tasks.push_back(task);
				break;
			case '3':
				cout << "Enter a search term: ";
				cin.ignore();
				getline(cin, searchTerm);
				searchTask(tasks, searchTerm);
				break;
         
		default:
			break;
		}

	} while (choice != '4');

	tasks.insert(tasks.end(), newTasks.begin(), newTasks.end());
	//ofstream outputFile("task.txt",ios::app);
	for (const auto& t : tasks)
	{
		outputFile << t.task << " " << t.date << " " << t.time << endl;
	}
	outputFile.close();
	return 0;
}


