#pragma once
#include <string>

class Student {
public:
    Student(std::string firstName, std::string lastName, unsigned int id);
    std::string GetFirstName() const { return firstName_; }
    std::string GetLastName() const { return lastName_; }
    void SetFirstName(std::string firstName) { firstName_ = firstName; }
    void SetLastName(std::string lastName) { lastName_ = lastName; }
    unsigned int GetId() const { return id_; }

private:
    std::string firstName_;
    std::string lastName_;
    unsigned int id_;
};