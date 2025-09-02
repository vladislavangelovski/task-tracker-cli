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

Task & markInProgress(std::vector<Task> &tasks, Task::Id id, Status status) {
    Task& t = tasks.at(id);
    t.set_status(Status::in_progress);
    return t;
}

Task & markDone(std::vector<Task> &tasks, Task::Id id, Status status) {
    Task& t = tasks.at(id);
    t.set_status(Status::done);
    return t;
}

void deleteTaskById(std::vector<Task>& tasks, Task::Id id) {
    tasks.erase(tasks.begin() + id - 1);
}

void listAllToDo(const std::vector<Task>& tasks, Status status) {
    for (const Task& t : tasks) {
        if (statusToString(t.get_status()) == "todo") {
            std::cout << t;
            std::cout << '\n';
        }
    }
}

void listAllInProgress(const std::vector<Task>& tasks, Status status) {
    std::vector<Task> inProgress;
    for (const Task& t : tasks) {
        if (statusToString(t.get_status()) == "in_progress") {
            std::cout << t;
        }
    }
}

void listAllDone(const std::vector<Task>& tasks, Status status) {
    std::vector<Task> done;
    for (const Task& t : tasks) {
        if (statusToString(t.get_status()) == "done") {
            std::cout << t;
            std::cout << std::endl;
        }
    }
}

std::string statusToString(Status status) {
    switch (status) {
        case Status::todo:
            return "todo";

        case Status::in_progress:
            return "in_progress";

        case Status::done:
            return "done";

        default:
            return "unknown";
    }
}
