#include "Task.h"

int main() {
    std::vector<Task> tasks;
    int choice;
    int unique_num_task = 0;
    int delete_num_task;
    while (true) {
        std::cout << "What do you want to do?\n"
                     "1 - Add Task\n"
                     "2 - See all Tasks\n"
                     "3 - Delete Task\n"
                     "4 - Exit" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                addTask(tasks, unique_num_task);
                unique_num_task++;
                break;

            case 2:
                if (tasks.empty())
                    std::cout << "No tasks exist." << std::endl;
                else {
                    for (auto& task : tasks) {
                        std::cout << "Unique num and Name: " << task.unique_num << " " << task.Name << std::endl
                                  << task.Description << std::endl;
                        std::cout << task.Day << "." << task.Month << "." << task.Year << std::endl;
                        std::cout << task.Hour << ":" << task.Minute << std::endl;
                    }
                }
                break;

            case 3:
                if (tasks.empty())
                    std::cout << "No tasks exist." << std::endl;
                else {
                    std::cout << "Num of task you want to delete: ";
                    std::cin >> delete_num_task;
                    std::cin.ignore();
                    for (auto i = tasks.begin(); i != tasks.end(); ++i) {
                        if (i->unique_num == delete_num_task) {
                            tasks.erase(i);
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
