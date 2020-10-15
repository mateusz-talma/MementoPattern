#include "Office.hpp"

void Office::CreateSchoolBackup(std::unique_ptr<SchoolBackup> backup) {
    schoolBackups.push_back(std::move(backup));
}

std::unique_ptr<SchoolBackup> Office::GetSchoolBackup() {
    std::unique_ptr<SchoolBackup> lastBackup;
    lastBackup = std::move(schoolBackups.back());
    schoolBackups.pop_back();
    return lastBackup;
}
