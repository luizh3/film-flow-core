#ifndef TVMAZEPROGRAMSSERVICE_H
#define TVMAZEPROGRAMSSERVICE_H

#include <film-flow-core/film-flow-core_global.h>

#include <service/programs/programsservice.h>
#include <network/endpoint/tvmaze/tzmazeendpoint.h>

class FILMFLOWCORE_EXPORT TvMazeProgramsService : public ProgramsService {
public:
    QList<ProgramModel*> findOnTheRise() const override;
    QList<ProgramModel*> findByName( const QString& dsQuery ) const override;
private:
    ProgramModel* findByIdProgram( const QString& idProgram ) const;
    ProgramModel* findBySingleSearch( const QString& dsQuery ) const;

    TzMazeEndpoint _tvMazeEndpoint;
};

#endif // TVMAZEPROGRAMSSERVICE_H
