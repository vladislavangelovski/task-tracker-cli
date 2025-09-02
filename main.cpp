#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

#include "Task.h"

void transformToLower(std::string& string);
Task createTask(std::string description);
Task& updateTask(std::vector<Task> tasks, std::size_t id, std::string description);
Task& updateTask(std::vector<Task> tasks, std::size_t id, std::string description, Status status);
Task& updateTask(std::vector<Task> tasks, std::size_t id, Status status);
void deleteTaskById(std::vector<Task>& tasks, std::size_t id);

int main() {
    std::string description;
    std::string choice;
    std::vector<Task> tasks;
    size_t id;

    std::cout << "Welcome to the Task Tracker Application\n";
    std::cout << "Please enter a task description:"<< std::endl;
    std::getline(std::cin, description);
    tasks.push_back(createTask(description));

    std::cout << "Please enter a task description:"<< std::endl;
    std::getline(std::cin, description);
    tasks.push_back(createTask(description));

    std::cout << "Please enter a task description:"<< std::endl;
    std::getline(std::cin, description);
    tasks.push_back(createTask(description));

    std::cout << "Enter id of task to delete";
    std::cin >> id;
    deleteTaskById(tasks, id);

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << tasks[i] << '\n';
    }
    return 0;
}

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

Task createTask(std::string description) {
    return Task(description);
}


Task& updateTask(std::vector<Task> tasks, std::size_t id, std::string description) {
    Task t = tasks.at(id);
    t.set_description(description);
    return t;
}

Task& updateTask(std::vector<Task> tasks, std::size_t id, std::string description, Status status) {
    Task t = tasks.at(id);
    t.set_description(description);
    t.set_status(status);
    return t;
}

Task& updateTask(std::vector<Task> tasks, std::size_t id, Status status) {
    Task t = tasks.at(id);
    t.set_status(status);
    return t;
}

void deleteTaskById(std::vector<Task>& tasks, std::size_t id) {
    tasks.erase(tasks.begin() + id - 1);
}
