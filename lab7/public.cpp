#include "public.h"

Public::Public()
{

}

QString Public::to_string() {
    return("Name: " + nameLes + "Auditorium: " + QString::number(auditorium) + "Date: " + QString::number(date));
}
