#include <list>
#include <memory>
#include <functional>
#include "SchoolBackup.hpp"

namespace Command {
	constexpr char ADD_STUDENT = 'a';
	constexpr char PRINT_STUDENTS = 'p';
	constexpr char CHANGE_FIRST_NAME = 'f';
	constexpr char CHANGE_LAST_NAME = 'l';
	constexpr char DELETE_STUDENT = 'd';
	constexpr char PRINT_HELP = 'h';
	constexpr char UNDO = 'u';
	constexpr char QUIT = 'q';

}  // namespace Command


class Office {
public:
	void CreateSchoolBackup(std::unique_ptr<SchoolBackup> backup);
	std::unique_ptr<SchoolBackup> GetSchoolBackup();
	void ExecuteCommand(char cmd, School& school);
	void PrintInfoScreen();

private:
	std::list<std::unique_ptr<SchoolBackup>> schoolBackups;

	void AddNewStudent(School& school);
	void ChangeFirstName(School& school);
	void ChangeLastName(School& school);
	void DeleteStudent(School& school);
	void PrintStudents(School& school);
	void Undo(School& school);
};