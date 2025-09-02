#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

enum Status {
    todo,
    in_progress,
    done
};

class Task {
public:
    using Id = std::size_t;
private:
    inline static std::size_t nextId = 1;
    Id id;
    std::string description;
    Status status;
    time_t createdAt;
    time_t updatedAt;

public:
    Task(const std::string &description)
        : id(nextId++),
        description(description),
        status(Status::todo),
        createdAt(std::time(nullptr)),
        updatedAt(createdAt){
    }

    [[nodiscard]] Id get_id() const {
        return id;
    }

    Task(const Task &other) = default;

    Task(Task &&other) noexcept = default;

    Task & operator=(const Task &other) = default;

    Task & operator=(Task &&other) noexcept = default;

    static std::string statusToString(Status status) {
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

    friend std::ostream & operator<<(std::ostream &os, const Task &task) {
        return os << "Task ID: " << task.id << '\n'
        << "Description: " << task.description << '\n'
        << "Status: " << statusToString(task.status) << '\n'
        << "Created At: " << std::put_time(std::localtime(&task.createdAt), "%c") << "\n"
        << "Updated At: " << std::put_time(std::localtime(&task.updatedAt), "%c");
    }

    Task& updateTask(std::string d, Status s) {
        description = d;
        status = s;
        updatedAt = std::time(nullptr);
        return *this;
    }

    Task& updateTask(std::string d) {
        description = d;
        updatedAt = std::time(nullptr);
        return *this;
    }
};

void transformToLower(std::string& string);

int main() {
    std::string description;
    std::string choice;
    std::cout << "Welcome to the Task Tracker Application\n";
    std::cout << "Please enter a task description:"<< std::endl;
    std::getline(std::cin, description);
    Task task = Task(description);
    std::cout << "Would you like to update this task?" << std::endl;
    getline(std::cin, choice);
    transformToLower(choice);
    if (choice == "yes") {
        std::cout << "Please enter a task description:"<< std::endl;
        getline(std::cin, description);
        task.updateTask(description);
    }
    std::cout << task;
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