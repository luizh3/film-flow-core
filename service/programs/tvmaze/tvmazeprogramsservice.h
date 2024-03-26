#ifndef TVMAZEPROGRAMSSERVICE_H
#define TVMAZEPROGRAMSSERVICE_H

#include <service/programs/programsservice.h>
#include <network/endpoint/tvmaze/tvmazeendpoint.h>

class TvMazeProgramsService : public ProgramsService {
public:
    QList<ProgramModel*> findOnTheRise() const override;
    QList<ProgramModel*> findByName( const QString& dsQuery ) const override;
private:
    ProgramModel* findByIdProgram( const QString& idProgram ) const;
    ProgramModel* findBySingleSearch( const QString& dsQuery ) const;

    TvMazeEndpoint _tvMazeEndpoint;
};

#endif // TVMAZEPROGRAMSSERVICE_H
