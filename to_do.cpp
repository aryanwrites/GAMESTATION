#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Task class to represent individual tasks
class Task {
private:
    string description;
    bool completed;

public:
    Task(string desc) : description(desc), completed(false) {}

    // Get the description of the task
    string getDescription() const {
        return description;
    }

    // Check if the task is completed
    bool isCompleted() const {
        return completed;
    }

    // Mark the task as completed
    void markCompleted() {
        completed = true;
    }

    // Display the task
    void displayTask(int index) const {
        cout << index << ". " << (completed ? "[X] " : "[ ] ") << description << endl;
    }
};

// To-Do List class to manage tasks
class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a new task to the list
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully." << endl;
    }

    // Display all tasks in the list
    void displayTasks() const {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }

        cout << "Your To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            tasks[i].displayTask(i + 1);
        }
    }

    // Mark a task as completed
    void markTaskCompleted(int taskNumber) {
        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[taskNumber - 1].markCompleted();
        cout << "Task marked as completed." << endl;
    }

    // Delete a task from the list
    void deleteTask(int taskNumber) {
        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted successfully." << endl;
    }

    // Save the tasks to a file
    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error: Could not open file for writing." << endl;
            return;
        }

        for (const Task& task : tasks) {
            outFile << task.getDescription() << "|" << task.isCompleted() << endl;
        }

        outFile.close();
        cout << "Tasks saved to file successfully." << endl;
    }

    // Load tasks from a file
    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "No saved tasks found." << endl;
            return;
        }

        tasks.clear();
        string line;
        while (getline(inFile, line)) {
            size_t delimiterPos = line.find('|');
            if (delimiterPos != string::npos) {
                string desc = line.substr(0, delimiterPos);
                bool completed = (line.substr(delimiterPos + 1) == "1");
                Task task(desc);
                if (completed) task.markCompleted();
                tasks.push_back(task);
            }
        }

        inFile.close();
        cout << "Tasks loaded from file successfully." << endl;
    }
};

// Main function to manage user interaction
int main() {
    ToDoList toDoList;
    toDoList.loadFromFile("tasks.txt");

    int choice;
    do {
        cout << "\n========== To-Do List Menu ==========" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Save and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore newline after entering choice

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.displayTasks();
                break;
            case 3: {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                toDoList.markTaskCompleted(taskNumber);
                break;
            }
            case 4: {
                int taskNumber;
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                toDoList.deleteTask(taskNumber);
                break;
            }
            case 5:
                toDoList.saveToFile("tasks.txt");
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
