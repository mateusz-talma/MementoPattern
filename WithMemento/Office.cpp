#include "Office.hpp"

void Office::CreateSchoolBackup(std::unique_ptr<SchoolBackup> backup) {
    schoolBackups.emplace_back(std::move(backup));
}

std::unique_ptr<SchoolBackup> Office::GetSchoolBackup() {
    std::unique_ptr<SchoolBackup> lastBackup = nullptr;
    if (!schoolBackups.empty()) {
        lastBackup = std::move(schoolBackups.back());
        schoolBackups.pop_back();
    }
    return lastBackup;
}
