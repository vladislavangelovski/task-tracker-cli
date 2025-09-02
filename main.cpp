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

    void set_description(const std::string &description) {
        this->description = description;
        updatedAt = std::time(nullptr);
    }

    void set_status(Status status) {
        this->status = status;
        updatedAt = std::time(nullptr);
    }
};

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
