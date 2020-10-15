#include <gtest/gtest.h>

#include "School.hpp"
#include "Student.hpp"

struct SchoolTest : ::testing::Test {
    std::vector<Student> students{
        Student("Adam", "Nowak", 100000),
        Student("Marek", "Kowalski", 110000),
        Student("Mateusz", "Ptak", 120000)};

    School school;

    void AddAllStudents() {
        for (const auto& student : students) {
            school.AddStudent(student.GetFirstName(), student.GetLastName(), student.GetId());
        }
    }
};

TEST_F(SchoolTest, ShouldAddNewStudent) {
    AddAllStudents();
    ASSERT_EQ(school.GetStudentAmount(), students.size());
}

TEST_F(SchoolTest, ShouldDeleteStudent) {
    AddAllStudents();
    school.DeleteStudent(students[2].GetId());
    ASSERT_EQ(school.GetStudentAmount(), students.size() - 1);
}

TEST_F(SchoolTest, ShouldSetNewFirstName) {
    AddAllStudents();
    std::string newName("Stefan");
    auto id = students[0].GetId();
    school.ChangeFirstName(id, newName);

    ASSERT_EQ(school.GetFirstName(id), newName);   
}

TEST_F(SchoolTest, ShouldSetNewLastName) {
    AddAllStudents();
    std::string newLastName("Hula");
    auto id = students[0].GetId();
    school.ChangeLastName(id, newLastName);

    ASSERT_EQ(school.GetLastName(id), newLastName);   
}