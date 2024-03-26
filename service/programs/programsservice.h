#ifndef PROGRAMSSERVICE_H
#define PROGRAMSSERVICE_H

#include <QList>

#include <film-flow-core/film-flow-core_global.h>

#include <model/program/programmodel.h>

class FILMFLOWCORE_EXPORT ProgramsService {
public:
    virtual ~ProgramsService() = default;
    virtual QList<ProgramModel*> findOnTheRise() const = 0;
    virtual QList<ProgramModel*> findByName( const QString& dsQuery ) const = 0;
};

#endif // PROGRAMSSERVICE_H
