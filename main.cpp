#include <iostream>
#include <ctime>
#include <iomanip>

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
        updatedAt(std::time(nullptr)){
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
            case todo:
                return "todo";
            case in_progress:
                return "in_progress";
            case done:
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
};


int main() {
    std::string description;
    std::cout << "Welcome to the Task Tracker Application\n";
    std::cout << "Please enter a task description:"<< std::endl;
    std::getline(std::cin, description);
    Task task = Task(description);
    std::cout << task;
    return 0;
}