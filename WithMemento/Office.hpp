#include <list>
#include <memory>
#include "SchoolBackup.hpp"

namespace Command {
constexpr char QUIT = 'q';
}

class Office {
public:
    void CreateSchoolBackup(std::unique_ptr<SchoolBackup> backup);
    std::unique_ptr<SchoolBackup> GetSchoolBackup();

private:
    std::list<std::unique_ptr<SchoolBackup>> schoolBackups;
};