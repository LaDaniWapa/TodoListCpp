#include "todo.h"

TodoList::TodoList() {}

vector<string> TodoList::getRawTodoList() {
    return this->todoList;
}

int TodoList::getTodoListSize() {
    return this->todoList.size();
}

void TodoList::addToTodoList(string item) {
    todoList.push_back(item);
    doneList.push_back(false);
}

void TodoList::removeFromTodoList(int index) {
    if (index < 1) return;

    todoList.erase(todoList.begin() + index - 1);
}

void TodoList::toggleTodoDone(int index) {
    doneList[index] = !doneList[index];
}

void TodoList::renameItem(int index, string name) {
    todoList[index - 1] = name;
    doneList[index - 1] = false;
}

void TodoList::printTodoList() {
    printf("\x1B[2J\x1B[H");

    printf(" My Todos \n------------\n");
    for (int i = 0; i < todoList.size(); i++) {
        printf("%d   [%s] %s\n", i + 1, doneList[i] ? "✅" : "  ", todoList[i].c_str());
    }
}

int TodoList::printMenu() {
    int input = 0;

    do {
        printf("\x1B[2J\x1B[H");
        printf(" Main Menu\n-----------\n");
        printf("1) Print TodoList\n");
        printf("2) Add an item to the list\n");
        printf("3) Remove an item from the list\n");
        printf("4) Toggle an item as done / undone\n");
        printf("5) Rename an item\n");
        printf("6) Exit\n");
        printf(" > ");

        if (!(std::cin >> input)) {
            cin.clear();
            printf("Invalid input. Please enter a valid number.\n");
        }
    } while (input < 1 || input > 6);

    return input;
}
