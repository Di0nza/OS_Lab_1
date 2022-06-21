#ifndef OS_LAB_1_EMPLOYEE_H
#define OS_LAB_1_EMPLOYEE_H
#include <cstring>

struct employee{
public:
    int num;
    char name[10];
    double hours;

    employee() {
        num = 0;
        strcpy(name, "Unknown");
        hours = 0;
    }

    employee(int num, const char nametmp[], double hours) {
        this->num = num;
        strcpy(name, nametmp);
        this->hours = hours;
    }
};
#endif //OS_LAB_1_EMPLOYEE_H
