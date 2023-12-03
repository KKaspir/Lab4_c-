#include "structs.cpp"
#include <iostream>
#include <vector>
#include <numeric>



// ОЦЕНКА
// Вывод в консоль
void printGrade(const std::vector<Grade>& grades) {
    for (const Grade grade : grades) {
        std::cout << "Предмет: " << grade.subject << std::endl;
        std::cout << "Оценка: " << grade.score << std::endl;
        std::cout << "Дата: " << grade.date << std::endl;
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

// поиск оценки по предмету
void printGradeBySubject(const std::vector<Grade>& grades, const std::string& subject) {
    bool found = false;

    for (const Grade& grade : grades) {
        if (grade.subject == subject) {
            std::cout << "Оценка по предмету \"" << subject << "\":" << std::endl;
            std::cout << "Оценка: " << grade.score << std::endl;
            std::cout << "Дата: " << grade.date << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Оценка по предмету \"" << subject << "\" не найдена." << std::endl;
    }
}

void initializeGrades(Student& student, const std::vector<Grade>& initialGrades) {
    student.grades = initialGrades;
}

Grade inputGradeFromConsole() {
    Grade grade;
    std::cout << "Введите предмет: ";
    std::cin >> grade.subject;
    std::cout << "Введите оценку: ";
    std::cin >> grade.score;
    std::cout << "Введите дату: ";
    std::cin >> grade.date;
    return grade;
}

// СТУДЕНТ
// Рассчет средней оценки
double avgGrade(Student structure) {
    if (structure.grades.empty()) {
        return 0.0; // Если нет оценок, средний балл равен 0
    }
    double totalScore = 0.0;
    for (const Grade grade : structure.grades) {
        totalScore += grade.score;
    }
    return totalScore / structure.grades.size();
}

// Функуия инициализации
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

// Вывод в консоль
void printStudent(Student student) {
    std::cout << "Имя: " << student.firstName << std::endl;
    std::cout << "Фамилия: " << student.lastName << std::endl;
    std::cout << "Дата рождения: " << student.dateOfBirth << std::endl;
    std::cout << "Номер студенческого билета: " << student.studentID << std::endl;
    std::cout << "Email: " << student.email << std::endl;

    std::cout << "\nОценки:" << std::endl;
    for (const Grade grade : student.grades) {
        std::cout << "Предмет: " << grade.subject << std::endl;
        std::cout << "Оценка: " << grade.score << std::endl;
        std::cout << "Дата: " << grade.date << std::endl;
        std::cout << std::endl; // Пустая строка для разделения оценок
    }
}

Student inputStudentFromConsole() {
    Student student;
    std::cout << "Введите имя: ";
    std::cin >> student.firstName;
    std::cout << "Введите фамилию: ";
    std::cin >> student.lastName;
    std::cout << "Введите дату рождения: ";
    std::cin >> student.dateOfBirth;
    std::cout << "Введите номер студенческого билета: ";
    std::cin >> student.studentID;
    std::cout << "Введите email: ";
    std::cin >> student.email;

    // Считываем оценки
    int numGrades;
    std::cout << "Введите количество оценок: ";
    std::cin >> numGrades;
    student.grades.clear(); // Очищаем существующие оценки
    for (int i = 0; i < numGrades; ++i) {
        std::cout << "Введите данные для оценки #" << i + 1 << ":" << std::endl;
        Grade grade = inputGradeFromConsole();
        student.grades.push_back(grade);
    }

    return student;
}

// EVENT
// Вывод в консоль
void printEvent(Event event) {
    std::cout << "Название мероприятия: " << event.eventName << std::endl;
    std::cout << "Дата: " << event.date << std::endl;
    std::cout << "Место проведения: " << event.location << std::endl;

    std::cout << "\nУчастники:" << std::endl;
    for (const Student student : event.eventMembers) {
        std::cout << "Имя: " << student.firstName << " " << student.lastName << std::endl;
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

// Функция для добавления участника в мероприятие
void addParticipantToEvent(Event& event, const Student& student) {
    event.eventMembers.push_back(student);
}

Event inputEventFromConsole() {
    Event event;
    std::cout << "Введите название мероприятия: ";
    std::cin >> event.eventName;
    std::cout << "Введите дату: ";
    std::cin >> event.date;
    std::cout << "Введите место проведения: ";
    std::cin >> event.location;

    // Считываем участников мероприятия
    int numEventMembers;
    std::cout << "Введите количество участников мероприятия: ";
    std::cin >> numEventMembers;
    event.eventMembers.clear(); // Очищаем существующих участников
    for (int i = 0; i < numEventMembers; ++i) {
        std::cout << "Введите данные для участника #" << i + 1 << ":" << std::endl;
        Student student = inputStudentFromConsole();
        event.eventMembers.push_back(student);
    }

    return event;
}

// КУРС
// Вывод в консоль
void printCourse(Course course) {
    std::cout << "Название курса: " << course.courseName << std::endl;
    std::cout << "Дата начала: " << course.startDate << std::endl;
    std::cout << "Дата окончания: " << course.endDate << std::endl;
    std::cout << "Предподаватель: " << course.instructor << std::endl;

    std::cout << "Мероприятия: " << std::endl;
    for (const Event event : course.events) {
        std::cout << "Название: " << event.eventName << std::endl;
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
    std::cout << "Введите название курса: ";
    std::cin >> course.courseName;
    std::cout << "Введите дату начала: ";
    std::cin >> course.startDate;
    std::cout << "Введите дату окончания: ";
    std::cin >> course.endDate;
    std::cout << "Введите имя преподавателя: ";
    std::cin >> course.instructor;

    // Считываем мероприятия
    int numEvents;
    std::cout << "Введите количество мероприятий: ";
    std::cin >> numEvents;
    course.events.clear(); // Очищаем существующие мероприятия
    for (int i = 0; i < numEvents; ++i) {
        std::cout << "Введите данные для мероприятия #" << i + 1 << ":" << std::endl;
        Event event = inputEventFromConsole();
        course.events.push_back(event);
    }

    return course;
}

// ПРОЕКТ
// Вывод в консоль
void printProject(Project project) {
    std::cout << "Название проекта: " << project.projectName << std::endl;
    std::cout << "Описание: " << project.description << std::endl;
    std::cout << "Дата начала: " << project.startDate << std::endl;
    std::cout << "Дата окончания: " << project.endDate << std::endl;

    std::cout << "\nУчастники:" << std::endl;
    for (const Student student : project.teamMembers) {
        std::cout << "Имя: " << student.firstName << " " << student.lastName << std::endl;
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

// добавление студента в проект
void addTeamMember(Project& project, const Student& student) {
    project.teamMembers.push_back(student);
}

Project inputProjectFromConsole() {
    Project project;
    std::cout << "Введите название проекта: ";
    std::cin >> project.projectName;
    std::cout << "Введите описание: ";
    std::cin >> project.description;
    std::cout << "Введите дату начала: ";
    std::cin >> project.startDate;
    std::cout << "Введите дату окончания: ";
    std::cin >> project.endDate;

    // Считываем участников проекта
    int numTeamMembers;
    std::cout << "Введите количество участников проекта: ";
    std::cin >> numTeamMembers;
    project.teamMembers.clear(); // Очищаем существующих участников
    for (int i = 0; i < numTeamMembers; ++i) {
        std::cout << "Введите данные для участника #" << i + 1 << ":" << std::endl;
        Student student = inputStudentFromConsole();
        project.teamMembers.push_back(student);
    }

    return project;
}

