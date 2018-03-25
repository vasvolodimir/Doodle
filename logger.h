#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>

#define LOG_D(expr) qDebug() << __TIME__ << "(Name:" << __FUNCTION__  << ":" << __LINE__ \
    << ") Message:" << expr;

#endif // LOGGER_H
