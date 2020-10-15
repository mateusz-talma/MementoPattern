#include <list>
#include <memory>
#include "StudentsBackup.hpp"

class Office {
public:
    void SetStudentsBackup(std::unique_ptr<StudentsBackup> backup);
    std::unique_ptr<StudentsBackup> GetStudentsBackup();

private:
    std::list<std::unique_ptr<StudentsBackup>> studentBackups_;
};