#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
private:
    string description;
    bool isCompleted;

public:
    Task(string desc) : description(desc), isCompleted(false) {}

    string getDescription() const {
        return description;
    }

    bool getStatus() const {
        return isCompleted;
    }

    void markAsCompleted() {
        isCompleted = true;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string &taskDesc) {
        tasks.push_back(Task(taskDesc));
        cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
            return;
        }

        cout << "\nTo-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getDescription()
                 << " [" << (tasks[i].getStatus() ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskAsCompleted(size_t taskNumber) {
        if (taskNumber == 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }
        tasks[taskNumber - 1].markAsCompleted();
        cout << "Task marked as completed.\n";
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber == 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully.\n";
    }
};

int main() {
    ToDoList myToDoList;
    int choice;

    do {
        cout << "\nTo-Do List Manager:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore(); // To clear the input buffer
            string taskDesc;
            cout << "Enter task description: ";
            getline(cin, taskDesc);
            myToDoList.addTask(taskDesc);
            break;
        }
        case 2:
            myToDoList.viewTasks();
            break;
        case 3: {
            size_t taskNumber;
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            myToDoList.markTaskAsCompleted(taskNumber);
            break;
        }
        case 4: {
            size_t taskNumber;
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            myToDoList.removeTask(taskNumber);
            break;
        }
        case 5:
            cout << "Exiting To-Do List Manager. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
