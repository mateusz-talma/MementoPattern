#include "School.hpp"
#include <algorithm>
#include <memory>

auto School::GetStudentById(unsigned int id) {
    return std::find_if(students_.begin(), students_.end(),
                        [&](std::shared_ptr<Student> s) { return s->GetId() == id; });
}

void School::AddStudent(std::string firstName, std::string lastName, unsigned int id) {
    auto student = std::make_shared<Student>(firstName, lastName, id);
    students_.push_back(student);
}

void School::DeleteStudent(unsigned int id) {
    auto it = std::find_if(students_.begin(), students_.end(),
                           [&](std::shared_ptr<Student> s) { return s->GetId() == id; });

    if (it != students_.end()) {
        students_.erase(it);
    }
}

void School::ChangeFirstName(unsigned int id, std::string firstName) {
    auto it = std::find_if(students_.begin(), students_.end(),
                           [&](std::shared_ptr<Student> s) { return s->GetId() == id; });

    if (it != students_.end()) {
        (*it)->SetFirstName(firstName);
    }
}
void School::ChangeLastName(unsigned int id, std::string lastName) {
    auto it = std::find_if(students_.begin(), students_.end(),
                           [&](std::shared_ptr<Student> s) { return s->GetId() == id; });

    if (it != students_.end()) {
        (*it)->SetLastName(lastName);
    }
}

std::string School::GetFirstName(unsigned int id) {
    auto it = GetStudentById(id);
    if (it != students_.end()) {
        return (*it)->GetFirstName();
    }
    return "";
}

std::string School::GetLastName(unsigned int id) {
    auto it = GetStudentById(id);
    if (it != students_.end()) {
        return (*it)->GetLastName();
    }
    return "";
}