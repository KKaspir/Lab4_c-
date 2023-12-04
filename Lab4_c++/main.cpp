#include "classes.cpp"









int main()
{
    // Примеры использования добавленных функций и операторов
    Grade grade1("Math", 90.0, "2023-01-01");
    Student student1("John", "Doe", "2000-01-01", "12345", "john@example.com", {grade1});

    std::cout << "Score before: " << *student1.getGradeReference().getScorePointer() << std::endl;
    *student1.getGradeReference().getScorePointer() += 5.0; // Увеличение оценки на 5 через указатель
    std::cout << "Score after: " << *student1.getGradeReference().getScorePointer() << std::endl;

    std::cout << "Full Name: " << student1.getFullName() << std::endl;

    //printStudent123(student1); // Использование дружественной функции

    Event event1("Event1", "2023-02-01", "Location1", {student1});
    Event event2("Event2", "2023-03-01", "Location2", {student1});

    Event combinedEvent = event1;

}























