#ifndef TASK_TRACKER_CLI_UTILS_H
#define TASK_TRACKER_CLI_UTILS_H
#include <vector>

#include "Task.h"

void transformToLower(std::string& string);
Task createTask(const std::string& description);
Task& updateTask(std::vector<Task>& tasks, Task::Id, const std::string& description);
Task& updateTask(std::vector<Task>& tasks, Task::Id, const std::string& description, Status status);
Task& updateTask(std::vector<Task>& tasks, Task::Id, Status status);
void deleteTaskById(std::vector<Task>& tasks, Task::Id);

#endif //TASK_TRACKER_CLI_UTILS_H