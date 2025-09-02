#ifndef TASK_TRACKER_CLI_UTILS_H
#define TASK_TRACKER_CLI_UTILS_H
#include <list>
#include <vector>

#include "Task.h"

void transformToLower(std::string& string);
Task createTask(const std::string& description);
Task& updateTask(std::vector<Task>& tasks, Task::Id id, const std::string& description);
Task& markInProgress(std::vector<Task>& tasks, Task::Id id, Status status);
Task& markDone(std::vector<Task>& tasks, Task::Id id, Status status);
void deleteTaskById(std::vector<Task>& tasks, Task::Id id);
void listAllToDo(const std::vector<Task>& tasks, Status status);
void listAllInProgress(const std::vector<Task>& tasks, Status status);
void listAllDone(const std::vector<Task>& tasks, Status status);
std::string statusToString(Status status);
#endif //TASK_TRACKER_CLI_UTILS_H