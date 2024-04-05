#ifndef PROGRAMSERVICE_H
#define PROGRAMSERVICE_H

#include <QList>

#include <model/program/programmodel.h>

class ProgramService {
public:
    virtual ~ProgramService() = default;
    virtual QList<ProgramModel*> findOnTheRise() const = 0;
    virtual QList<ProgramModel*> findByName( const QString& dsQuery ) const = 0;
};

#endif // PROGRAMSERVICE_H
