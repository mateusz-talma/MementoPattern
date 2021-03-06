#include "School.hpp"
#include <algorithm>
#include <memory>
#include "SchoolBackup.hpp"
#include "TextTable.h"

auto School::GetStudentById(unsigned int id) {
    return std::find_if(students_.begin(), students_.end(),
                        [&](Student& s) { return s.GetId() == id; });
}

void School::AddStudent(std::string firstName, std::string lastName, unsigned int id) {
    students_.emplace_back(Student(firstName, lastName, id));
}

void School::DeleteStudent(unsigned int id) {
    auto it = GetStudentById(id);

    if (it != students_.end()) {
        students_.erase(it);
    }
}

void School::ChangeFirstName(unsigned int id, std::string firstName) {
    auto it = GetStudentById(id);

    if (it != students_.end()) {
        it->SetFirstName(firstName);
    }
}
void School::ChangeLastName(unsigned int id, std::string lastName) {
    auto it = GetStudentById(id);

    if (it != students_.end()) {
        it->SetLastName(lastName);
    }
}

std::string School::GetFirstName(unsigned int id) {
    auto it = GetStudentById(id);
    if (it != students_.end()) {
        return it->GetFirstName();
    }
    return "";
}

std::string School::GetLastName(unsigned int id) {
    auto it = GetStudentById(id);
    if (it != students_.end()) {
        return it->GetLastName();
    }
    return "";
}

// Memento methods

std::unique_ptr<SchoolBackup> School::CreateBackup() {
    return std::make_unique<SchoolBackup>(*this);
}

void School::RestoreBackup(std::unique_ptr<SchoolBackup> backup) {
    if (backup) {
        *this = backup->GetSchool();
    }
}

void School::PrintAllStudents() {
    std::system("clear");

    TextTable t('-', '|', '+');

    t.add("Id");
    t.add("First Name");
    t.add("Last Name");
    t.endOfRow();

    for (const auto& student : students_) {
        t.add(std::to_string(student.GetId()));
        t.add(student.GetFirstName());
        t.add(student.GetLastName());
        t.endOfRow();
    }

    std::cout << t;
}