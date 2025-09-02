#include <iostream>
#include <iomanip>
#include <vector>

#include "Task.h"
#include "Utils.h"


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

