#include <iostream>
#include <vector>
#include <numeric>


// ################ ��������� ################
// ������
struct Grade {
    std::string subject;
    double score;
    std::string date;
};

// �������
struct Student {
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string studentID;
    std::string email;
    std::vector<Grade> grades;
};


// ������
struct Project {
    std::string projectName;
    std::string description;
    std::string startDate;
    std::string endDate;
    std::vector<Student> teamMembers; // ������ ���������, ����������� � �������
};

// EVENT
struct Event {
    std::string eventName;
    std::string date;
    std::string location;
    std::vector<Student> eventMembers;
};

// ����
struct Course {
    std::string courseName;
    std::string startDate;
    std::string endDate;
    std::string instructor;
    std::vector<Event> events;
};