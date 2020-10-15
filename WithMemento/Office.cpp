#include "Office.hpp"

void Office::SetStudentsBackup(std::unique_ptr<StudentsBackup> backup) {
    studentBackups_.push_back(std::move(backup));
}

std::unique_ptr<StudentsBackup> Office::GetStudentsBackup() {
    std::unique_ptr<StudentsBackup> lastBackup;
    lastBackup = std::move(studentBackups_.back());
    studentBackups_.pop_back();
    return lastBackup;
}
