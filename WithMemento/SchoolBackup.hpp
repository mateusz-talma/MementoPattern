#pragma once
#include "School.hpp"

class SchoolBackup {
    friend class School;
    friend class Office;

public:
    SchoolBackup(School school);

private:
    School GetSchool() { return school_; }

    School school_;
};