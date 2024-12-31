#include <iostream>
#include <vector>
#include <string>

class ToDoList {
private:
    struct Task {
        std::string description;
        bool completed;
    };

    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back({task, false});
        std::cout << "Task \"" << task << "\" added!" << std::endl;
    }

    void markCompleted(int taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task \"" << tasks[taskNumber - 1].description << "\" marked as completed!" << std::endl;
        } else {
            std::cout << "Invalid task number!" << std::endl;
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        std::cout << "\nCurrent Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::string status = tasks[i].completed ? "[Completed]" : "[Pending]";
            std::cout << i + 1 << ". " << tasks[i].description << " " << status << std::endl;
        }
    }

    void run() {
        while (true) {
            std::cout << "\n--- To-Do List Application ---" << std::endl;
            std::cout << "1. Add Task" << std::endl;
            std::cout << "2. Mark Task as Completed" << std::endl;
            std::cout << "3. View Tasks" << std::endl;
            std::cout << "4. Exit" << std::endl;

            int choice;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice == 1) {
                std::cin.ignore(); 
                std::string task;
                std::cout << "Enter the task: ";
                std::getline(std::cin, task);
                addTask(task);
            } else if (choice == 2) {
                int taskNumber;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskNumber;
                markCompleted(taskNumber);
            } else if (choice == 3) {
                viewTasks();
            } else if (choice == 4) {
                std::cout << "Exiting application. Goodbye!" << std::endl;
                break;
            } else {
                std::cout << "Invalid choice. Please try again!" << std::endl;
            }
        }
    }
};

int main() {
    ToDoList todoList;
    todoList.run();
    return 0;
}

