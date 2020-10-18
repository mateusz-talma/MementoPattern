#pragma once
#include <memory>
#include <vector>
#include "Student.hpp"

class SchoolBackup;

class School {
public:
    void AddStudent(std::string firstName, std::string lastName, unsigned int id);
    void DeleteStudent(unsigned int id);
    void ChangeFirstName(unsigned int id, std::string firstName);
    void ChangeLastName(unsigned int id, std::string lastName);
    void PrintAllStudents();

    std::string GetFirstName(unsigned int id);
    std::string GetLastName(unsigned int id);
    size_t GetStudentAmount() { return students_.size(); }

    //Memento methods
    std::unique_ptr<SchoolBackup> CreateBackup();
    void RestoreBackup(std::unique_ptr<SchoolBackup> backup);

private:
    std::vector<Student> students_;

    auto GetStudentById(unsigned int id);
};