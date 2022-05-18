#include "ordinary.h"

Ordinary::Ordinary()
{

}

QString Ordinary::to_string() {
    return("Name: " + nameLes + "Auditorium: " + QString::number(auditorium) + "Length: " + QString::number(length));
}
