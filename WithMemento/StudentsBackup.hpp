#pragma once
#include "School.hpp"
class StudentsBackup {
    friend class School;

public:
    StudentsBackup(School school);

private:
    School GetSchool() { return school_; }

    School school_;
};