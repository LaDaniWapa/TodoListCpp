
/*
 * TODOLIST APP FOR C++20
 *
 * Add a todo
 * Delete a todo
 * Mark as done
 * Rename a todo
 * Save everythin in a file?
 * Load everything from a file?
 * What kind of file? JSON? XML? TXT?
 *
 * by Daniela :)
 */

/*
 * Newbie comments
 * Compile with g++ (v11) in proyect dir
 * g++ -std=c++20 -I . -g *.cpp -o main && ./main
 *
 * -std=c++20 : Use c++20
 * -I .       : get .h files from current dir
 * -g *.cpp   : compile every .cpp file
 * -o main    : the output executable file is main
 *
 * Clang formatter config
 * https://clang.llvm.org/docs/ClangFormatStyleOptions.html
 */

#include "todo.h"

using namespace std;

void waitForEnter() {
    printf("\nPress enter to continue...");
    cin.get();
    cin.get();
}

int main() {
    TodoList todolist;
    int input, index;
    string newItem = "";

    do {
        input = todolist.printMenu();

        switch (input) {
            case 1:
                if (todolist.getTodoListSize() < 1) {
                    printf("You don't have anything to do!");
                    waitForEnter();
                } else {
                    todolist.printTodoList();
                    waitForEnter();
                }
                break;

            case 2:
                printf("Name for the new item: ");
                cin.get();
                getline(cin, newItem);
                todolist.addToTodoList(newItem);
                break;

            case 3:
                if (todolist.getTodoListSize() < 1) {
                    printf("You don't have anything to remove!");
                    waitForEnter();
                } else {
                    todolist.printTodoList();
                    printf("What item you'd like to remove? ");
                    cin >> index;
                    todolist.removeFromTodoList(index);
                }
                break;

            case 4:
                if (todolist.getTodoListSize() < 1) {
                    printf("You don't have anything to mark as done!");
                    waitForEnter();
                } else {
                    todolist.printTodoList();
                    printf("What item you'd like to toggle? ");
                    cin >> index;
                    todolist.toggleTodoDone(--index);
                }
                break;

            case 5:
                if (todolist.getTodoListSize() < 1) {
                    printf("You don't have anything to rename!");
                    waitForEnter();
                } else {
                    todolist.printTodoList();
                    printf("What item you'd like to rename? ");
                    cin >> index;
                    cin.get();
                    printf("What's the new name? ");
                    getline(cin, newItem);
                    todolist.renameItem(index, newItem);
                }
                break;

            default:
                printf("Bye ^^/\n");
                break;
        }

    } while (input != 7);

    return EXIT_SUCCESS;
}