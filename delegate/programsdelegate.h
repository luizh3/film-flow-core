#ifndef PROGRAMSDELEGATE_H
#define PROGRAMSDELEGATE_H

#include <film-flow-core/film-flow-core_global.h>

#include <service/programs/programsservice.h>

class FILMFLOWCORE_EXPORT ProgramsDelegate {
public:
    ProgramsDelegate();
    ~ProgramsDelegate();

    QList<ProgramModel*> findOnTheRise() const;
    QList<ProgramModel*> findByName( const QString& dsQuery ) const;

private:
    ProgramsService* _programService;
};

#endif // PROGRAMSDELEGATE_H
