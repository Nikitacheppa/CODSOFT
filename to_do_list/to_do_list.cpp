#include <iostream>
#include <vector>
#include <string>

class Task {
        public:
                 Task(const std::string& description) : description(description), completed(false) {}
    
    void markCompleted() { completed = true; }
    bool isCompleted() const { return completed; }
    std::string getDescription() const { return description; }

private:
    std::string description;
    bool completed;
};

class ToDoListManager {
public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". [" << (tasks[i].isCompleted() ? "X" : " ") << "] " << tasks[i].getDescription() << '\n';
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }
        tasks[index - 1].markCompleted();
    }

    void removeTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
    }

private:
    std::vector<Task> tasks;
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ToDoListManager manager;
    int choice;
    std::string description;
    size_t taskNumber;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // To ignore any leftover newline character in the input buffer
                std::getline(std::cin, description);
                manager.addTask(description);
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskNumber;
                manager.markTaskAsCompleted(taskNumber);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNumber;
                manager.removeTask(taskNumber);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
