#include <iostream>
#include <vector>
#include <numeric>


// ################ ÑÒĞÓÊÒÓĞÛ ################
// ÎÖÅÍÊÀ
struct Grade {
    std::string subject;
    double score;
    std::string date;
};

// ÑÒÓÄÅÍÒ
struct Student {
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string studentID;
    std::string email;
    std::vector<Grade> grades;
};


// ÏĞÎÅÊÒ
struct Project {
    std::string projectName;
    std::string description;
    std::string startDate;
    std::string endDate;
    std::vector<Student> teamMembers; // Ìàññèâ ñòóäåíòîâ, ó÷àñòâóşùèõ â ïğîåêòå
};

// EVENT
struct Event {
    std::string eventName;
    std::string date;
    std::string location;
    std::vector<Student> eventMembers;
};

// ÊÓĞÑ
struct Course {
    std::string courseName;
    std::string startDate;
    std::string endDate;
    std::string instructor;
    std::vector<Event> events;
};