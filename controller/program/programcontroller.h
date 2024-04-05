#ifndef PROGRAMCONTROLLER_H
#define PROGRAMCONTROLLER_H

#include <film-flow-core/film-flow-core_global.h>

#include <delegate/program/programdelegate.h>

class FILMFLOWCORE_EXPORT ProgramController {
public:
    QList<ProgramModel*> findOnTheRise() const;
    QList<ProgramModel*> findByName( const QString& dsQuery ) const;
private:
    ProgramDelegate _programDelegate;
};

#endif // PROGRAMCONTROLLER_H
