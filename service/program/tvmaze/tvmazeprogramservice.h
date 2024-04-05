#ifndef TVMAZEPROGRAMSERVICE_H
#define TVMAZEPROGRAMSERVICE_H

#include <service/program/programservice.h>
#include <network/endpoint/program/tvmaze/tvmazeendpoint.h>

class TvMazeProgramService : public ProgramService {
public:
    QList<ProgramModel*> findOnTheRise() const override;
    QList<ProgramModel*> findByName( const QString& dsQuery ) const override;
private:
    ProgramModel* findByIdProgram( const QString& idProgram ) const;
    ProgramModel* findBySingleSearch( const QString& dsQuery ) const;

    TvMazeEndpoint _tvMazeEndpoint;
};

#endif // TVMAZEPROGRAMSERVICE_H
