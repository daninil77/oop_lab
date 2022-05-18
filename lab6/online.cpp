#include "online.h"

Online::Online()
{

}

QString Online::to_string() {
    return("Name: " + nameLes + "Auditorium: " + QString::number(auditorium) + "Password: " + QString::number(password));
}
