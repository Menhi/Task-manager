#include "Task.h"


void addTask(std::vector<Task>& tasks, int unique_num) {
    Task task;
    task.unique_num = unique_num;
    std::cout << "Enter task name: ";
    std::getline(std::cin, task.Name);
    std::cout << "Enter task description: ";
    std::getline(std::cin, task.Description);
    std::cout << "Enter due date (dd mm yyyy): ";
    std::cin >> task.Day >> task.Month >> task.Year;
    std::cout << "Enter due time (hh mm): ";
    std::cin >> task.Hour >> task.Minute;
    std::cin.ignore();
    tasks.push_back(task);
}
