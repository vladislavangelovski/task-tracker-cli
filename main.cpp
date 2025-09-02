#include <iostream>
#include <iomanip>
#include <vector>

#include "Task.h"
#include "Utils.h"


int main() {
    std::string description;
    std::string choice;
    std::vector<Task> tasks;
    Task::Id id;
    std::string status;

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


    std::cout << "List tasks by user input: " << std::endl;
    std::cin >> status;

    if (status == "todo") {
        listAllToDo(tasks, Status::todo);
    }
    else if (status == "in progress") {
        listAllInProgress(tasks, Status::in_progress);
    }
    else if (status == "done") {
        listAllDone(tasks, Status::done);
    }

    return 0;
}

