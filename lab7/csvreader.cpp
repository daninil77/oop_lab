#include "csvreader.h"
#include <iostream>
#include <QString>
#include <vector>
#include <lesson.h>
#include <fstream>
#include <string>
#include "split.cpp"
#include "csvexception.h"
//constructor
CSVReader::CSVReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
    count_line = 0;
}

//destructor
CSVReader::~CSVReader()
{
    fin.close();

}
std::vector<Lesson> CSVReader::readAll(){

    std::vector<Lesson> result;


            while (!fin.eof())
            {

                std::string line;
                std::getline(fin, line);
                count_line += 1;

                if (line != "") {
                    auto v = split(line, ';');

                    Lesson Tlesson;
                    try {
                       Tlesson.number = std::stoi(v[0]);
                       Tlesson.nameLes = QString::fromStdString(v[1]);
                        if(std::stoi(v[3]) > 5360){
                            throw CSVException(count_line);
                        }
                        Tlesson.type = QString:: fromStdString(v[2]);
                        Tlesson.auditorium = std::stoi(v[3]);

                    }  catch (const std::logic_error &e) {
                        std::cerr << "Error: incorrect data" << std::endl;
                        std::vector<Lesson> res;
                        return res;
                    }


                    result.push_back(Tlesson);
                }



               }
            fin.clear();
            fin.seekg(0, ios::beg);
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

