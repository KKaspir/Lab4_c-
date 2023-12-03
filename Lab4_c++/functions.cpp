#include "structs.cpp"
#include <iostream>
#include <vector>
#include <numeric>



// ������
// ����� � �������
void printGrade(const std::vector<Grade>& grades) {
    for (const Grade grade : grades) {
        std::cout << "�������: " << grade.subject << std::endl;
        std::cout << "������: " << grade.score << std::endl;
        std::cout << "����: " << grade.date << std::endl;
        std::cout << std::endl;
    }
}

Grade initializeGrade(
    const std::string& subject,
    double score,
    const std::string& date
) {
    Grade grade;
    grade.subject = subject;
    grade.score = score;
    grade.date = date;

    return grade;
}

// ����� ������ �� ��������
void printGradeBySubject(const std::vector<Grade>& grades, const std::string& subject) {
    bool found = false;

    for (const Grade& grade : grades) {
        if (grade.subject == subject) {
            std::cout << "������ �� �������� \"" << subject << "\":" << std::endl;
            std::cout << "������: " << grade.score << std::endl;
            std::cout << "����: " << grade.date << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "������ �� �������� \"" << subject << "\" �� �������." << std::endl;
    }
}

void initializeGrades(Student& student, const std::vector<Grade>& initialGrades) {
    student.grades = initialGrades;
}

Grade inputGradeFromConsole() {
    Grade grade;
    std::cout << "������� �������: ";
    std::cin >> grade.subject;
    std::cout << "������� ������: ";
    std::cin >> grade.score;
    std::cout << "������� ����: ";
    std::cin >> grade.date;
    return grade;
}

// �������
// ������� ������� ������
double avgGrade(Student structure) {
    if (structure.grades.empty()) {
        return 0.0; // ���� ��� ������, ������� ���� ����� 0
    }
    double totalScore = 0.0;
    for (const Grade grade : structure.grades) {
        totalScore += grade.score;
    }
    return totalScore / structure.grades.size();
}

// ������� �������������
Student initializeStudent(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& dateOfBirth,
    const std::string& studentID,
    const std::string& email,
    const std::vector<Grade>& grades
) {
    Student student;
    student.firstName = firstName;
    student.lastName = lastName;
    student.dateOfBirth = dateOfBirth;
    student.studentID = studentID;
    student.email = email;
    student.grades = grades;

    return student;
}

// ����� � �������
void printStudent(Student student) {
    std::cout << "���: " << student.firstName << std::endl;
    std::cout << "�������: " << student.lastName << std::endl;
    std::cout << "���� ��������: " << student.dateOfBirth << std::endl;
    std::cout << "����� ������������� ������: " << student.studentID << std::endl;
    std::cout << "Email: " << student.email << std::endl;

    std::cout << "\n������:" << std::endl;
    for (const Grade grade : student.grades) {
        std::cout << "�������: " << grade.subject << std::endl;
        std::cout << "������: " << grade.score << std::endl;
        std::cout << "����: " << grade.date << std::endl;
        std::cout << std::endl; // ������ ������ ��� ���������� ������
    }
}

Student inputStudentFromConsole() {
    Student student;
    std::cout << "������� ���: ";
    std::cin >> student.firstName;
    std::cout << "������� �������: ";
    std::cin >> student.lastName;
    std::cout << "������� ���� ��������: ";
    std::cin >> student.dateOfBirth;
    std::cout << "������� ����� ������������� ������: ";
    std::cin >> student.studentID;
    std::cout << "������� email: ";
    std::cin >> student.email;

    // ��������� ������
    int numGrades;
    std::cout << "������� ���������� ������: ";
    std::cin >> numGrades;
    student.grades.clear(); // ������� ������������ ������
    for (int i = 0; i < numGrades; ++i) {
        std::cout << "������� ������ ��� ������ #" << i + 1 << ":" << std::endl;
        Grade grade = inputGradeFromConsole();
        student.grades.push_back(grade);
    }

    return student;
}

// EVENT
// ����� � �������
void printEvent(Event event) {
    std::cout << "�������� �����������: " << event.eventName << std::endl;
    std::cout << "����: " << event.date << std::endl;
    std::cout << "����� ����������: " << event.location << std::endl;

    std::cout << "\n���������:" << std::endl;
    for (const Student student : event.eventMembers) {
        std::cout << "���: " << student.firstName << " " << student.lastName << std::endl;
    }
}

Event initializeEvent(
    const std::string& eventName,
    const std::string& date,
    const std::string& location,
    const std::vector<Student>& eventMembers) {
    Event event;
    event.eventName = eventName;
    event.date = date;
    event.location = location;
    event.eventMembers = eventMembers;

    return event;
}

// ������� ��� ���������� ��������� � �����������
void addParticipantToEvent(Event& event, const Student& student) {
    event.eventMembers.push_back(student);
}

Event inputEventFromConsole() {
    Event event;
    std::cout << "������� �������� �����������: ";
    std::cin >> event.eventName;
    std::cout << "������� ����: ";
    std::cin >> event.date;
    std::cout << "������� ����� ����������: ";
    std::cin >> event.location;

    // ��������� ���������� �����������
    int numEventMembers;
    std::cout << "������� ���������� ���������� �����������: ";
    std::cin >> numEventMembers;
    event.eventMembers.clear(); // ������� ������������ ����������
    for (int i = 0; i < numEventMembers; ++i) {
        std::cout << "������� ������ ��� ��������� #" << i + 1 << ":" << std::endl;
        Student student = inputStudentFromConsole();
        event.eventMembers.push_back(student);
    }

    return event;
}

// ����
// ����� � �������
void printCourse(Course course) {
    std::cout << "�������� �����: " << course.courseName << std::endl;
    std::cout << "���� ������: " << course.startDate << std::endl;
    std::cout << "���� ���������: " << course.endDate << std::endl;
    std::cout << "��������������: " << course.instructor << std::endl;

    std::cout << "�����������: " << std::endl;
    for (const Event event : course.events) {
        std::cout << "��������: " << event.eventName << std::endl;
    }
}

Course initializeCourse(
    const std::string& courseName,
    const std::string& startDate,
    const std::string& endDate,
    const std::string& instructor,
    const std::vector<Event>& events
) {
    Course course;
    course.courseName = courseName;
    course.startDate = startDate;
    course.endDate = endDate;
    course.instructor = instructor;
    course.events = events;

    return course;
}

void addEventToCourse(Course& course, const Event& event) {
    course.events.push_back(event);
}

Course inputCourseFromConsole() {
    Course course;
    std::cout << "������� �������� �����: ";
    std::cin >> course.courseName;
    std::cout << "������� ���� ������: ";
    std::cin >> course.startDate;
    std::cout << "������� ���� ���������: ";
    std::cin >> course.endDate;
    std::cout << "������� ��� �������������: ";
    std::cin >> course.instructor;

    // ��������� �����������
    int numEvents;
    std::cout << "������� ���������� �����������: ";
    std::cin >> numEvents;
    course.events.clear(); // ������� ������������ �����������
    for (int i = 0; i < numEvents; ++i) {
        std::cout << "������� ������ ��� ����������� #" << i + 1 << ":" << std::endl;
        Event event = inputEventFromConsole();
        course.events.push_back(event);
    }

    return course;
}

// ������
// ����� � �������
void printProject(Project project) {
    std::cout << "�������� �������: " << project.projectName << std::endl;
    std::cout << "��������: " << project.description << std::endl;
    std::cout << "���� ������: " << project.startDate << std::endl;
    std::cout << "���� ���������: " << project.endDate << std::endl;

    std::cout << "\n���������:" << std::endl;
    for (const Student student : project.teamMembers) {
        std::cout << "���: " << student.firstName << " " << student.lastName << std::endl;
    }
}

Project initializeProject(
    const std::string& projectName,
    const std::string& description,
    const std::string& startDate,
    const std::string& endDate,
    const std::vector<Student> teamMembers
) {
    Project project;
    project.projectName = projectName;
    project.startDate = startDate;
    project.endDate = endDate;
    project.description = description;
    project.teamMembers = teamMembers;

    return project;
}

// ���������� �������� � ������
void addTeamMember(Project& project, const Student& student) {
    project.teamMembers.push_back(student);
}

Project inputProjectFromConsole() {
    Project project;
    std::cout << "������� �������� �������: ";
    std::cin >> project.projectName;
    std::cout << "������� ��������: ";
    std::cin >> project.description;
    std::cout << "������� ���� ������: ";
    std::cin >> project.startDate;
    std::cout << "������� ���� ���������: ";
    std::cin >> project.endDate;

    // ��������� ���������� �������
    int numTeamMembers;
    std::cout << "������� ���������� ���������� �������: ";
    std::cin >> numTeamMembers;
    project.teamMembers.clear(); // ������� ������������ ����������
    for (int i = 0; i < numTeamMembers; ++i) {
        std::cout << "������� ������ ��� ��������� #" << i + 1 << ":" << std::endl;
        Student student = inputStudentFromConsole();
        project.teamMembers.push_back(student);
    }

    return project;
}

