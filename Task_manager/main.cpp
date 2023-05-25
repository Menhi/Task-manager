#include "Task.h"

int main() {
    std::vector<Task> tasks;
    loadTasksFromFile(tasks); // Load tasks from the file (if any)

    int choice;
    int unique_num_task = tasks.empty() ? 0 : tasks.back().unique_num + 1;
    int delete_num;
    while (true) {
        std::cout << "What do you want to do?\n"
                     "1 - Add Task\n"
                     "2 - See all Tasks\n"
                     "3 - Delete Task\n"
                     "4 - Save and Exit" << std::endl;
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character after reading choice
        switch (choice) {
            case 1:
                addTask(tasks, unique_num_task);
                unique_num_task++;
                std::cout << std::endl;
                break;

            case 2:
                if (tasks.empty())
                    std::cout << "No tasks exist." << std::endl;
                else {
                    for (const auto& task : tasks) {
                        std::cout << "Unique num and Name: " << task.unique_num << " " << task.Name << std::endl
                                  << task.Description << std::endl;
                        ascribe_zero (task.Day);
                        std::cout<<".";
                        ascribe_zero (task.Month);
                        std::cout<<".";
                        std::cout << task.Year << std::endl;
                        ascribe_zero (task.Hour);
                        std::cout<<":";
                        ascribe_zero (task.Minute);
                        std::cout << std::endl;
                    }
                }
                std::cout << std::endl;
                break;

            case 3:
                if (tasks.empty())
                    std::cout << "No tasks exist." << std::endl;
                else {
                    std::cout << "Num of task you want to delete: ";
                    std::cin >> delete_num;
                    std::cin.ignore(); // Ignore newline character after reading delete_num
                    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                        if (it->unique_num == delete_num) {
                            tasks.erase(it);
                            break;
                        }
                    }
                }
                std::cout << std::endl;
                break;

            case 4:
                saveTasksToFile(tasks); // Save tasks to the file
                return 0;
        }
    }
    return 0;
}
