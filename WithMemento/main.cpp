#include <iostream>
#include <map>
#include <memory>
#include "Office.hpp"
#include "School.hpp"
#include "Student.hpp"
#include "TextTable.h"



int main() {
    School school;
    Office office;

    school.AddStudent("Mariusz", "Nowak", 101);
    school.AddStudent("Jan", "Kowalski", 102);
    school.AddStudent("Piotr", "Nowak", 103);
    school.AddStudent("Adam", "Malysz", 104);

    char cmd;
    office.PrintInfoScreen();
    do {
        std::cout << "Type the key...";
        std::cin >> cmd;
        office.ExecuteCommand(cmd, school);
    } while (cmd != Command::QUIT);

    return 0;
}