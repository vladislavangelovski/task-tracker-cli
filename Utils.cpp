#include "Utils.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iostream>


int findIndexById(const std::vector<Task> &tasks, const Task::Id id) {
    for (std::size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].get_id() == id) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void transformToLower(std::string& str) {
    std::transform(
        str.begin(),
        str.end(),
        str.begin(),
        [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        }
        );
}

Task createTask(const std::string& description) {
    return Task(description);
}


Task& updateTask(std::vector<Task> &tasks, const Task::Id id, const std::string& description) {
    const int idx = findIndexById(tasks, id);

    if (idx < 0) {
        throw std::out_of_range("No task with ID " + std::to_string(id));
    }

    Task& t = tasks[static_cast<std::size_t>(idx)];
    t.set_description(description);
    return t;
}

Task & markInProgress(std::vector<Task> &tasks, const Task::Id id) {
    const int idx = findIndexById(tasks, id);

    if (idx < 0) {
        throw std::out_of_range("No task with ID " + std::to_string(id));
    }

    Task& t = tasks[static_cast<std::size_t>(idx)];
    t.set_status(Status::in_progress);
    return t;
}

Task & markDone(std::vector<Task> &tasks, const Task::Id id) {
    const int idx = findIndexById(tasks, id);

    if (idx < 0) {
        throw std::out_of_range("No task with ID " + std::to_string(id));
    }

    Task& t = tasks[static_cast<std::size_t>(idx)];
    t.set_status(Status::done);
    return t;
}

void deleteTaskById(std::vector<Task>& tasks, const Task::Id id) {
    const int idx = findIndexById(tasks, id);

    if (idx < 0) {
        throw std::out_of_range("No task with ID " + std::to_string(id));
    }

    tasks.erase(tasks.begin() + static_cast<std::size_t>(idx));
}

void listAllToDo(const std::vector<Task> &tasks) {
    for (const Task& t : tasks) {
        if (t.get_status() == Status::todo) {
            std::cout << t;
        }
    }
}

void listAllInProgress(const std::vector<Task> &tasks) {
    for (const Task& t : tasks) {
        if (t.get_status() == Status::in_progress) {
            std::cout << t;
        }
    }
}

void listAllDone(const std::vector<Task> &tasks) {
    for (const Task& t : tasks) {
        if (t.get_status() == Status::done) {
            std::cout << t;
        }
    }
}