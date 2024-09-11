#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

extern "C" __declspec(dllexport) void ReplaceDigitsWithWord(const char* inputFilePath, const char* outputFilePath, int replaceCount);

void ReplaceDigitsWithWord(const char* inputFilePath, const char* outputFilePath, int replaceCount) {
    
    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        throw runtime_error("Не удалось открыть входной файл.");
    }

    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        throw runtime_error("Не удалось открыть выходной файл.");
    }

    string line;
    int count = 0;

    while (getline(inputFile, line)) {
        for (char& ch : line) {
            if (isdigit(ch) && count < replaceCount) {
                ch = ' ';
                count++;
            }
        }
        outputFile << line << endl;
    }

    // Проверка на выполнение замен
    if (count < replaceCount) {
        cerr << "Количество замен меньше запрошенного." << endl;
    }

    inputFile.close();
    outputFile.close();
}
