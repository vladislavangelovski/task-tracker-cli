#ifndef TASK_TRACKER_CLI_UTILS_H
#define TASK_TRACKER_CLI_UTILS_H
#include <list>
#include <vector>

#include "Task.h"

static int findIndexById(const std::vector<Task> &tasks, Task::Id id);
void transformToLower(std::string& str);
Task createTask(const std::string& description);
Task& updateTask(std::vector<Task>& tasks, Task::Id id, const std::string& description);
Task& markInProgress(std::vector<Task> &tasks, Task::Id id);
Task& markDone(std::vector<Task> &tasks, Task::Id id);
void deleteTaskById(std::vector<Task>& tasks, Task::Id id);
void listAllToDo(const std::vector<Task> &tasks);
void listAllInProgress(const std::vector<Task> &tasks);
void listAllDone(const std::vector<Task> &tasks);
#endif //TASK_TRACKER_CLI_UTILS_H