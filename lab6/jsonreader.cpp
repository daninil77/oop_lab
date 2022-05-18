#include "jsonreader.h"

#include <json.hpp>

#include <QString>

#include <iostream>

JSONReader::JSONReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
}

std::vector<Lesson> JSONReader::readAll(){

    std::vector<Lesson> result;
    nlohmann::json json;

    fin >> json;

    for (auto& e: json){
        Lesson c;
               e.at("number").get_to(c.number);
               e.at("auditorium").get_to(c.auditorium);

               std::string str;
               e.at("nameLes").get_to(str);
               e.at("type").get_to(str);
               e.at("nameLes").get_to(str);
               c.nameLes = QString::fromStdString(str);

               result.push_back(c);
    }

    return result;
}
AbstractReader& JSONReader::operator>>(Lesson &em){
    if (!(this->json[index].empty())){
            std::string tempStr;

            json[index].at("number").get_to(em.number);
            json[index].at("auditorium").get_to(em.auditorium);
            json[index].at("nameLes").get_to(tempStr);
            em.nameLes = QString::fromStdString(tempStr);

            index++;
        }else {
            fin.close();
        }

        return *this;
}
