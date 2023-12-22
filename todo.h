#ifndef TODO_H
#define TODO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TodoList {
   private:
    vector<string> todoList;
    vector<bool> doneList;

   public:
    TodoList();

    vector<string> getRawTodoList();
    int getTodoListSize();
    void addToTodoList(string item);
    void removeFromTodoList(int index);
    void toggleTodoDone(int index);
    void renameItem(int index, string name);

    void printTodoList();
    int printMenu();
};

#endif  // TODO_H