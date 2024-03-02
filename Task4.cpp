#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks);
void removeTask(vector<Task> &tasks);

int main() {
    vector<Task> tasks;
    char choice;

    do {
        cout << "\n===== To-Do List Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                markTaskCompleted(tasks);
                break;
            case '4':
                removeTask(tasks);
                break;
            case '5':
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

// Function to add a task to the list
void addTask(vector<Task> &tasks) {
    Task newTask;
    cin.ignore(); // Ignore newline character left in the buffer
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully." << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << "===== Tasks =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << " - ";
        cout << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid index." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);
    cout << "Enter the index of the task to remove: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid index." << endl;
    }
}

