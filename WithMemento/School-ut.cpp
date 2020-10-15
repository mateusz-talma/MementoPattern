#include <gtest/gtest.h>

#include "School.hpp"
#include "Student.hpp"

struct SchoolTest : ::testing::Test {
    std::vector<Student> students{
        Student("Adam", "Nowak", 100000),
        Student("Marek", "Kowalski", 110000),
        Student("Mateusz", "Ptak", 120000)};

    School school;
};

TEST_F(SchoolTest, ShouldAddNewStudent) {
    for (const auto& student : students) {
        school.AddStudent(student.GetFirstName(), student.GetLastName(), student.GetId());
    }

    ASSERT_EQ(school.GetStudentAmount(), students.size());
}

TEST_F(SchoolTest, ShouldDeleteStudent) {
    for (const auto& student : students) {
        school.AddStudent(student.GetFirstName(), student.GetLastName(), student.GetId());
    }

    school.DeleteStudent(students[2].GetId());
    ASSERT_EQ(school.GetStudentAmount(), students.size() - 1);
}

