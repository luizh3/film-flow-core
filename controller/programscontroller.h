#ifndef PROGRAMSCONTROLLER_H
#define PROGRAMSCONTROLLER_H

#include <delegate/programsdelegate.h>

#include <film-flow-core/film-flow-core_global.h>

class FILMFLOWCORE_EXPORT ProgramsController {
public:
    QList<ProgramModel*> findOnTheRise() const;
    QList<ProgramModel*> findByName( const QString& dsQuery ) const;
private:
    ProgramsDelegate _programsDelegate;
};

#endif // PROGRAMSCONTROLLER_H
