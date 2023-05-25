#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <vector>

class DateAndTime {
public:
    int Day;
    int Month;
    int Year;
    int Hour;
    int Minute;
};

class Task : public DateAndTime {
public:
    int unique_num;
    std::string Name;
    std::string Description;
};

void addTask(std::vector<Task>& tasks, int unique_num);

#endif // TASK_H
