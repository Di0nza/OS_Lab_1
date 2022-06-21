#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <cstdlib>
#include "Employee.h"

int comparator(const void* p1, const void* p2) {
    employee* e1 = (employee*)p1;
    employee* e2 = (employee*)p2;
    return strcmp(e1->name, e2->name);
}

int main(int argc, char** argv) {
    std::string FileName = argv[1];
    std::string reportFileName = argv[2];
    int salary = atoi(argv[3]);

    std::ifstream in(FileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
    in.seekg(0, std::ios::end);
    int n = in.tellg() / sizeof(employee);
    in.seekg(0, std::ios::beg);
    employee* allEmployees = new employee[n];
    in.read((char*)allEmployees, n * sizeof(employee));

    qsort(allEmployees, n, sizeof(employee), comparator);

    std::ofstream out(reportFileName.c_str());
    out << "Input file name: " << FileName << std::endl << "Number" << std::setw(10) << "Name" << std::setw(10)
    << "Hours" << std::setw(10) << "Salary" << std::endl;
    for (int i = 0; i < n; i++) {
        out << allEmployees[i].num << std::setw(10) << allEmployees[i].name << std::setw(10) << allEmployees[i].hours
        << std::setw(10) << allEmployees[i].hours * salary << std::endl;
    }
    out.close();
}