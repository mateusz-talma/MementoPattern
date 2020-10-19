#include "Office.hpp"
#include "TextTable.h"
#include <iostream>

void Office::AddNewStudent(School& school) {
	CreateSchoolBackup(school.CreateBackup());
	std::string firstName, lastName;
	unsigned int id = 0;

	std::cin >> firstName;
	std::cin >> lastName;
	std::cin >> id;
	school.AddStudent(firstName, lastName, id);
}

void Office::ChangeFirstName(School& school) {
	CreateSchoolBackup(school.CreateBackup());

	std::string firstName;
	unsigned int id = 0;

	std::cin >> firstName;
	std::cin >> id;

	school.ChangeFirstName(id, firstName);
}

void Office::ChangeLastName(School& school) {
	CreateSchoolBackup(school.CreateBackup());

	std::string lastName;
	unsigned int id = 0;

	std::cin >> lastName;
	std::cin >> id;

	school.ChangeLastName(id, lastName);
}

void Office::DeleteStudent(School& school) {
	CreateSchoolBackup(school.CreateBackup());

	unsigned int id = 0;
	std::cin >> id;

	school.DeleteStudent(id);
}

void Office::PrintStudents(School& school) {
	school.PrintAllStudents();
}

void Office::PrintInfoScreen() {
	system("clear");

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

	t.add("(d)elete");
	t.add("Delete student (<id>)");
	t.endOfRow();

	t.add("(u)ndo");
	t.add("Undo last operation");
	t.endOfRow();

	t.add("(h)elp");
	t.add("Print help screen");
	t.endOfRow();

	t.add("(q)uit");
	t.add("Exit");
	t.endOfRow();

	std::cout << t;
}


void Office::ExecuteCommand(char cmd, School& school) {
	if (cmd == Command::ADD_STUDENT) {
		AddNewStudent(school);
	} else if (cmd == Command::CHANGE_FIRST_NAME) {
		ChangeFirstName(school);
	} else if (cmd == Command::CHANGE_LAST_NAME) {
		ChangeLastName(school);
	} else if (cmd == Command::DELETE_STUDENT) {
		DeleteStudent(school);
	} else if (cmd == Command::PRINT_STUDENTS) {
		school.PrintAllStudents();
	} else if (cmd == Command::PRINT_HELP) {
		PrintInfoScreen();
	} else if (cmd == Command::UNDO) {
		Undo(school);
	}
}


void Office::Undo(School& school) {
	school.RestoreBackup(GetSchoolBackup());
	school.PrintAllStudents();
}



void Office::CreateSchoolBackup(std::unique_ptr<SchoolBackup> backup) {
    schoolBackups.emplace_back(std::move(backup));
}

std::unique_ptr<SchoolBackup> Office::GetSchoolBackup() {
    std::unique_ptr<SchoolBackup> lastBackup = nullptr;
    if (!schoolBackups.empty()) {
        lastBackup = std::move(schoolBackups.back());
        schoolBackups.pop_back();
    }
    return lastBackup;
}
