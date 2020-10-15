#pragma once
#include <memory>
#include <vector>
#include "Student.hpp"

class School {
public:
    void AddStudent(std::string firstName, std::string lastName, unsigned int id);
    void DeleteStudent(unsigned int id);
    void ChangeFirstName(unsigned int id);
    void ChangeLastName(unsigned int id);
    void ChangeFirstName(unsigned int id, std::string firstName);
    void ChangeLastName(unsigned int id, std::string lastName);

    std::string GetFirstName(unsigned int id);
    std::string GetLastName(unsigned int id);
    size_t GetStudentAmount() { return students_.size();}

private:
    auto GetStudentById(unsigned int id);

    std::vector<std::shared_ptr<Student>> students_;
};