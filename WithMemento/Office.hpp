#include <list>
#include <memory>
#include "StudentsBackup.hpp"

class Office {
public:
    void CreateSchoolBackup(std::unique_ptr<StudentsBackup> backup);
    std::unique_ptr<StudentsBackup> GetStudentsBackup();

private:
    std::list<std::unique_ptr<StudentsBackup>> schoolBackups;
};