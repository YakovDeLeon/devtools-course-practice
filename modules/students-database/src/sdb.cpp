// Copyright 2019 Kutovoi Vadim

#include <string>

#include "include/sdb.h"


bool Sdb::AddStudent(const std::string& first_name,
    const std::string& last_name) {
    student st = { first_name };

    return table_.insert(std::make_pair(last_name, st)).second;
}

bool Sdb::RemoveStudent(const std::string& last_name) {
    auto rec = table_.find(last_name);

    if (rec == table_.end()) {
        return false;
    } else {
        table_.erase(rec);
        return true;
    }
}

bool Sdb::AddMark(const std::string& last_name,
                  const std::string& subject_name,
                  const uint& mark) {
    auto rec = table_.find(last_name);

    if (rec == table_.end()) {
        return false;
    } else {
        for (auto it = rec->second.subjects.begin();
            it != rec->second.subjects.end(); ++it) {
            if (subject_name == it->subject_name) {
                it->marks.push_back(mark);
                return true;
            }
        }
        subject sbj = { subject_name };
        sbj.marks.push_back(mark);

        rec->second.subjects.push_back(sbj);

        return true;
    }
}

float Sdb::GetAvgMark(const std::string& last_name) {
    auto rec = table_.find(last_name);

    if (rec == table_.end()) {
        return -1;
    } else {
        uint num_marks = 0, mark_sum = 0;

        for (auto sbj = rec->second.subjects.begin();
            sbj != rec->second.subjects.end(); sbj++) {
            for (auto mark = sbj->marks.begin();
                mark != sbj->marks.end(); mark++) {
                num_marks++;
                mark_sum += *mark;
            }
        }

        return mark_sum / static_cast<float>(num_marks);
    }
}

Sdb::uint Sdb::GetNumberOfStudents() {
    return table_.size();
}

Sdb::uint Sdb::GetNumberOfGoodStudents() {
    uint st_count = 0;

    for (auto it : table_) {
        std::string last_name = it.first;

        float avg_mark = 0;
        avg_mark = GetAvgMark(last_name);

        if (avg_mark > 3)
            st_count++;
    }

    return st_count;
}

Sdb::uint Sdb::GetNumberOfBadStudents() {
    uint st_count = 0;

    for (auto it : table_) {
        std::string last_name = it.first;

        float avg_mark = 0;
        avg_mark = GetAvgMark(last_name);

        if (avg_mark < 4)
            st_count++;
    }
    return st_count;
}
