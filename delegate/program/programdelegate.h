#ifndef PROGRAMDELEGATE_H
#define PROGRAMDELEGATE_H

#include <film-flow-core/film-flow-core_global.h>

#include <service/program/programservice.h>

class FILMFLOWCORE_EXPORT ProgramDelegate {
public:
    ProgramDelegate();
    ~ProgramDelegate();

    QList<ProgramModel*> findOnTheRise() const;
    QList<ProgramModel*> findByName( const QString& dsQuery ) const;

private:
    ProgramService* _programService;
};

#endif // PROGRAMDELEGATE_H
