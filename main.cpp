#include <iostream>
#include <iomanip>
#include <vector>

#include "Task.h"
#include "Utils.h"


int main(int argc, char** argv) {
    std::vector<Task> tasks;

    if (argc < 2) {
        std::cout << "Usage: task <command> [args]\n" "Commands: add <desc> | list [all]\n";
        return 0;
    }

    std::string cmd = argv[1];

    if (cmd == "add") {
        if (argc < 3) {
            std::cout << "Usage: task add <description>\n";
            return 1;
        }
        std::string desc = joinArgs(argv, 2, argc);
        Task t = createTask(desc);
        tasks.push_back(t);
        std::cout << "Added task with ID " << t.get_id() << '\n';
        return 0;
    }
    if (cmd == "list") {
        listAll(tasks);
        return 0;
    }

    std::cout << "Unknown command: " << cmd << '\n';
    return 1;
}

