
#ifndef TASK_TRACKER_CLI_TASK_H
#define TASK_TRACKER_CLI_TASK_H
#include <string>
#include <ctime>
#include <iostream>
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
    explicit Task(const std::string &description);

    Task(const Task &other) = default;

    Task(Task &&other) noexcept = default;

    Task & operator=(const Task &other) = default;

    Task & operator=(Task &&other) noexcept = default;

    static std::string statusToString(Status status);

    friend std::ostream & operator<<(std::ostream &os, const Task &task);

    void set_description(const std::string &description);

    void set_status(Status status);

    [[nodiscard]] Id get_id() const;

    [[nodiscard]] Status get_status() const;
};


#endif //TASK_TRACKER_CLI_TASK_H