#include "Office.hpp"

void Office::CreateSchoolBackup(std::unique_ptr<StudentsBackup> backup) {
    schoolBackups.push_back(std::move(backup));
}

std::unique_ptr<StudentsBackup> Office::GetStudentsBackup() {
    std::unique_ptr<StudentsBackup> lastBackup;
    lastBackup = std::move(schoolBackups.back());
    schoolBackups.pop_back();
    return lastBackup;
}
