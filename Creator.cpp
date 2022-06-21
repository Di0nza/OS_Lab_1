#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include "Employee.h"

int main(int argc, char** argv) {
    int n = atoi(argv[1]);
    employee* emps = new employee[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Enter number, name and hours of working of employee " << i + 1 << ": ";
        int num;
        std::string name;
        double hours;
        std::cin >> num;
        std::cin >> name;
        std::cin >> hours;
        emps[i] = employee(num, name.c_str(), hours);
    }

    std::ofstream out(argv[2], std::ios::binary);
    out.write((const char*)emps, sizeof(employee) * n);
    out.close();
}