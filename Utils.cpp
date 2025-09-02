#include "Utils.h"

#include <algorithm>


void transformToLower(std::string& string) {
    std::transform(
        string.begin(),
        string.end(),
        string.begin(),
        [](unsigned char c) {
            return std::tolower(c);
        }
        );
}

Task createTask(const std::string& description) {
    return Task(description);
}


Task& updateTask(std::vector<Task> &tasks, const Task::Id id, const std::string& description) {
    Task& t = tasks.at(id);
    t.set_description(description);
    return t;
}

Task& updateTask(std::vector<Task> &tasks, const Task::Id id, const std::string& description, const Status status) {
    Task& t = tasks.at(id);
    t.set_description(description);
    t.set_status(status);
    return t;
}

Task& updateTask(std::vector<Task> &tasks, const Task::Id id, const Status status) {
    Task& t = tasks.at(id);
    t.set_status(status);
    return t;
}

void deleteTaskById(std::vector<Task>& tasks, Task::Id id) {
    tasks.erase(tasks.begin() + id - 1);
}