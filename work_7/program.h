#pragma once

#include <string>

class Program {
private:
    std::string new_file_name = "output.txt";
    std::string old_file_name = "f.txt";

public:
    Program();
    virtual ~Program();

#pragma region accessors
public:
    std::string outputFileName();
    void outputFileName(std::string new_name);

#pragma endregion accessors
public:
    bool createFile();
};