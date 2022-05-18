#include "csvreader.h"
#include <iostream>
#include <QString>
#include <vector>
#include <lesson.h>
#include <fstream>
#include <string>
#include "split.cpp"

//constructor
CSVReader::CSVReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());

}

//destructor
CSVReader::~CSVReader()
{
    fin.close();

}

std::vector<std::string> split(std::string str, std::string delim);

// read file and return vector
std::vector<Lesson> CSVReader::readAll()
{
    std::vector<Lesson> result;
    if (fin.is_open())
        {
            std::string line;
            Lesson Tlesson;
            while (!fin.eof())
            {
                getline(fin, line);
                if (line.empty()) {
                    break;
                }
                auto p = split(line, ";"); //{"1", "model", "enum", "year"}

                Tlesson.number = stoi(p[0]); //преобразование целочисленного типа в строку
                Tlesson.nameLes = QString::fromStdString(p[1]);
                Tlesson.type = QString::fromStdString(p[2]);
                Tlesson.auditorium = stoi(p[3]);

                result.push_back(Tlesson);
            }
    }
    return result;
}

CSVReader& CSVReader::operator=(CSVReader&& other){
    fin = std::move(other.fin);
    return *this; //на текущий объект
}

CSVReader::CSVReader(CSVReader&& other){
    fin = std::move(other.fin); //:всё "переместить" и исп в др месте, ведь скоро будет уничтожен
}

AbstractReader& CSVReader::operator>> (Lesson &em){

    if (fin.is_open() && !fin.eof()) {
        std::string line;
        getline(fin, line);

        if (!line.empty()){
            auto v = split(line, ';');

            em.number = std::stoi(v[0]);
            em.nameLes = QString::fromStdString(v[1]);
            em.auditorium = std::stoi(v[2]);
            em.type =  QString::fromStdString(v[2]);
        }

    }
    return *this;
}

// splitter
std::vector<std::string> split(std::string str, std::string delim)
{
    std::vector<std::string> arr;
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while ((next = str.find(delim, prev)) != std::string::npos) {
        arr.push_back(str.substr(prev, next - prev));
        prev = next + delta;
    }
    arr.push_back(str.substr(prev));
    return arr;
}

