// Copyright 2019 Kutovoi Vadim

#include <unordered_map>
#include <vector>
#include <ctime>
#include <string>


struct subject {
    std::string subject_name;
    std::vector<int> marks;
};

struct student {
    std::string first_name;
    std::vector<subject> subjects;
};


#ifndef MODULES_STUDENTS_DATABASE_INCLUDE_SDB_H_
#define MODULES_STUDENTS_DATABASE_INCLUDE_SDB_H_


class Sdb {
 public:
     using uint = unsigned int;

     Sdb() = default;
     Sdb(Sdb&&) = default;

     bool AddStudent(const std::string& first_name,
         const std::string& last_name);
     bool RemoveStudent(const std::string& last_name);
     bool AddMark(const std::string& last_name,
         const std::string& subject_name, const uint&);

     float GetAvgMark(const std::string& last_name);

     uint GetNumberOfStudents();
     uint GetNumberOfGoodStudents();
     uint GetNumberOfBadStudents();

 private:
     std::unordered_map<std::string, student> table_;
};

#endif  // MODULES_STUDENTS_DATABASE_INCLUDE_SDB_H_
