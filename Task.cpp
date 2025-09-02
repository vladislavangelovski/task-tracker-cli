#include "Task.h"

Task::Task(const std::string &description)
    : id(nextId++),
      description(description),
      status(Status::todo),
      createdAt(std::time(nullptr)),
      updatedAt(createdAt) {}

Task::Id Task::get_id() const {
    return id;
}

void Task::set_description(const std::string &desc) {
    description = desc;
    updatedAt = std::time(nullptr);
}

void Task::set_status(Status s) {
    status = s;
    updatedAt = std::time(nullptr);
}

Status Task::get_status() const {
    return status;
}

std::string Task::statusToString(Status status) {
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

std::ostream & operator<<(std::ostream &os, const Task &task) {
    return os << "Task ID: " << task.id << '\n'
    << "Description: " << task.description << '\n'
    << "Status: " << Task::statusToString(task.status) << '\n'
    << "Created At: " << std::put_time(std::localtime(&task.createdAt), "%c") << "\n"
    << "Updated At: " << std::put_time(std::localtime(&task.updatedAt), "%c") << std::endl;
}