#include <iostream>
#include <memory>
#include "Office.hpp"
#include "School.hpp"
#include "Student.hpp"
#include "TextTable.h"



void PrintInfoScreen() {
    std::cout << "Use one of the commands below:\n";
    TextTable t('-', '|', '+');
    t.add("Command");
    t.add("Description");
    t.endOfRow();

    t.add("(p)rint");
    t.add("Print list of students");
    t.endOfRow();

    t.add("(a)dd");
    t.add("Add new student (<name> <last name> <id>");
    t.endOfRow();

    t.add("change (f)irst name");
    t.add("Change first name (<name> <id>)");
    t.endOfRow();

    t.add("change (l)ast name");
    t.add("Change last name (<last name> <id>)");
    t.endOfRow();

    t.add("(q)uit");
    t.add("Exit");
    t.endOfRow();

    std::cout << t;
}

int main() {
    char cmd;
    School school;
    Office office;
    do {
        PrintInfoScreen();
        std::cin >> cmd;
    } while (cmd != Command::QUIT);

    return 0;
}