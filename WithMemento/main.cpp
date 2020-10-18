#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include "Office.hpp"
#include "School.hpp"
#include "Student.hpp"
#include "TextTable.h"

namespace Command {
constexpr char ADD_STUDENT = 'a';
constexpr char PRINT_STUDENTS = 'p';
constexpr char CHANGE_FIRST_NAME = 'f';
constexpr char CHANGE_LAST_NAME = 'l';
constexpr char DELETE_STUDENT = 'd';
constexpr char PRINT_HELP = 'h';
constexpr char QUIT = 'q';

}  // namespace Command

void AddNewStudent(School& school) {
    std::string firstName, lastName;
    unsigned int id = 0;

    std::cin >> firstName;
    std::cin >> lastName;
    std::cin >> id;

    school.AddStudent(firstName, lastName, id);
}

void ChangeFirstName(School& school) {
    std::string firstName;
    unsigned int id = 0;

    std::cin >> firstName;
    std::cin >> id;

    school.ChangeFirstName(id, firstName);
}

void ChangeLastName(School& school) {
    std::string lastName;
    unsigned int id = 0;

    std::cin >> lastName;
    std::cin >> id;

    school.ChangeFirstName(id, lastName);
}

void DeleteStudent(School& school) {
    unsigned int id = 0;
    std::cin >> id;

    school.DeleteStudent(id);
}

void PrintStudents(School& school) {
    school.PrintAllStudents();
}

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

    t.add("(d)elete)");
    t.add("Delete student (<id>)");
    t.endOfRow();

    t.add("(h)elp");
    t.add("Print help screen");
    t.endOfRow();

    t.add("(q)uit");
    t.add("Exit");
    t.endOfRow();

    std::cout << t;
}

std::map<char, std::function<void(School&)>> functionsMap{
    {Command::ADD_STUDENT, AddNewStudent},
    {Command::PRINT_STUDENTS, PrintStudents},
    {Command::CHANGE_FIRST_NAME, ChangeFirstName},
    {Command::CHANGE_LAST_NAME, ChangeLastName},
    {Command::DELETE_STUDENT, DeleteStudent}};

void ExecuteCommand(char cmd, School& school) {
    auto it = functionsMap.find(cmd);
    if (it != functionsMap.end()) {
        functionsMap[cmd](school);
    } else if (cmd == Command::PRINT_HELP) {
        PrintInfoScreen();
    }
}

int main() {
    School school;
    Office office;
    char cmd;
    PrintInfoScreen();
    do {
        std::cout << "Type key...";
        std::cin >> cmd;
        ExecuteCommand(cmd, school);
    } while (cmd != Command::QUIT);

    return 0;
}