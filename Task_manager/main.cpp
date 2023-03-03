#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>


using namespace std;



class Task{
public:
    int unique_num;
    string Name;
    string Description;
    int Day;
    int Month;
    int Year;
    int Hour;
    int Minute;
};

void addTask (vector<Task> &tasks, int unique_num){
    Task task;
    task.unique_num=unique_num;
    cout << "Enter task name: ";
    getline(cin, task.Name);
    cout << "Enter task description: ";
    getline(cin, task.Description);
    cout << "Enter due date (dd mm yyyy): ";
    cin >> task.Day>>task.Month>>task.Year;
    cout << "Enter due time (hh mm): ";
    cin >> task.Hour>>task.Minute;
    tasks.push_back(task);
}

int main()
{
    vector<Task> tasks;
    int choice;
    int unique_num_task=0;
    int delete_num;
    while (1)
    {
        delete_num = -1;
        cout<<"What you want to do?\n"
              "1 - add Task\n"
              "2 - see all Tasks\n"
              "3 - delete Task\n"
              "4 - exit"<<endl;
        cin>>choice;
        cin.get();
        switch (choice) {
        case 1:
            addTask(tasks, unique_num_task);
            unique_num_task++;
            break;

        case 2:
            if (tasks.empty())
                cout << "No one task exist.\n";
            else {
                for (auto& x:tasks){
                    cout<<"Unique num and Name: "<<x.unique_num<<" "<<x.Name<<endl<<x.Description<<endl;
                    cout<<x.Day<<"."<<x.Month<<"."<<x.Year<<endl;
                    cout<<x.Hour<<":"<<x.Minute<<endl;
                }
            }
            break;

        case 3:
            if (tasks.empty())
                cout << "No one task exist.\n";
            else {
                cout<<"Num of task you want to delete: ";
                cin>>delete_num;
                for (auto& obj : tasks) {
                    if (obj.unique_num == delete_num){
                        obj = tasks.back();
                        tasks.pop_back();
                        break;
                    }
                }
            }
            break;

        case 4:
            return 0;
        }
    }
    return 0;
}
