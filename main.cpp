#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <iomanip>
#include "Employee.h"

int main(int argc, char *argv[]) {

    std::string fileName;
    int recordsNumber;
    std::ofstream out;

    std::cout << "Enter file name: ";
    std::cin >> fileName;
    std::cout << "Enter number of records in file: ";
    std::cin >> recordsNumber;

    STARTUPINFO siC;
    PROCESS_INFORMATION piAppC;
    ZeroMemory(&siC, sizeof(STARTUPINFO));
    siC.cb = sizeof(STARTUPINFO);
    char num[10];
    itoa(recordsNumber, num, 10);
    std::string arg = "Creator.exe " + std::string(num) + " " + fileName;
    char args[255];
    strcpy(args, arg.c_str());
    bool isStarted = CreateProcess(nullptr, args, nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr, &siC,
                                   &piAppC);
    WaitForSingleObject(piAppC.hProcess, INFINITE);
    CloseHandle(piAppC.hThread);
    CloseHandle(piAppC.hProcess);

    if (isStarted) {
        system("cls");
        std::cout << "File " << fileName << " created." << std::endl;
        std::ifstream in(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
        in.seekg(0, std::ios::end);
        int n = in.tellg() / sizeof(employee);
        in.seekg(0, std::ios::beg);
        employee *allEmployees = new employee[n];
        in.read((char *) allEmployees, n * sizeof(employee));
        in.close();
        for (int i = 0; i < n; i++) {
            std::cout << allEmployees[i].num << std::setw(10) << allEmployees[i].name << std::setw(10)
                      << allEmployees[i].hours << std::endl;
        }
        std::string reporterFileName;
        int salary;
        std::cout << "Input reporter file name: ";
        std::cin >> reporterFileName;
        std::cout << "Input salary per hour: ";
        std::cin >> salary;

        STARTUPINFO siR;
        PROCESS_INFORMATION piAppR;
        ZeroMemory(&siC, sizeof(STARTUPINFO));
        siC.cb = sizeof(STARTUPINFO);
        char sal[15];
        itoa(salary, sal, 15);
        std::string argg = "Reporter.exe " + fileName + " " + reporterFileName + " " + std::string(sal);
        char argss[256];
        strcpy(argss, argg.c_str());
        isStarted = CreateProcess(nullptr, argss, nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr, &siR,
                                  &piAppR);
        WaitForSingleObject(piAppR.hProcess, INFINITE);
        CloseHandle(piAppR.hThread);
        CloseHandle(piAppR.hProcess);
        if (isStarted) {
            std::cout << "Report file created.";
        }
    }

    system("pause");
    return 0;
}