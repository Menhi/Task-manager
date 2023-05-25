#include "Task.h"

#include <fstream>

void saveTasksToFile(const std::vector<Task>& tasks) {
    std::ofstream outputFile("tasks.txt");
    if (outputFile.is_open()) {
        for (const Task& task : tasks) {
            outputFile << task.unique_num << "\n";
            outputFile << task.Name << "\n";
            outputFile << task.Description << "\n";
            outputFile << task.Day << " " << task.Month << " " << task.Year << "\n";
            outputFile << task.Hour << " " << task.Minute << "\n";
        }
        outputFile.close();
        std::cout << "Tasks have been saved to the file." << std::endl;
    } else {
        std::cout << "Unable to open the file for saving tasks." << std::endl;
    }
}

void loadTasksFromFile(std::vector<Task>& tasks) {
    std::ifstream inputFile("tasks.txt");
    if (inputFile.is_open()) {
        tasks.clear();
        Task task;
        while (inputFile >> task.unique_num) {
            inputFile.ignore();
            std::getline(inputFile, task.Name);
            std::getline(inputFile, task.Description);
            inputFile >> task.Day >> task.Month >> task.Year;
            inputFile >> task.Hour >> task.Minute;
            inputFile.ignore();
            tasks.push_back(task);
        }
        inputFile.close();
        std::cout << "Tasks have been loaded from the file." << std::endl;
    } else {
        std::cout << "No saved tasks found or unable to open the file." << std::endl;
    }
}
