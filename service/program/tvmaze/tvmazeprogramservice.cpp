#include "tvmazeprogramservice.h"

#include <memory>

#include <utils/retrytask.h>
#include <utils/listconverter.h>

#include <repository/program/programrepository.h>
#include <converter/program/programconverter.h>

namespace {
    constexpr const int NR_MAX_RETRY = 3;
}

QList<ProgramModel*> TvMazeProgramService::findOnTheRise() const {

    qInfo() << "TvMazeProgramService::findOnTheRise";

    // TODO revisar uma maneira melhor de fazer essa rotina
    QList<ProgramModel*> programs = {};

    std::unique_ptr<ProgramSearchModel> programSearch( ProgramRepository().findProgramsSearch() );

    qInfo() << "TvMazeProgramService::findOnTheRise [IS_SEARCH_BY_NAME]" << programSearch->isSearchByName();

    if( programSearch->isSearchByName() ) {

        programs = ListConverter<ProgramModel*,QString>::toList( programSearch->names(), [&]( const QString& dsName ){
            return findBySingleSearch( dsName );
        } );

        qInfo() << "TvMazeProgramService::findOnTheRise [PROGRAMS_COUNT]" << programs.count();

        return programs;
    }

    programs = ListConverter<ProgramModel*,QString>::toList( programSearch->ids(), [&]( const QString& dsId ){
        return findByIdProgram( dsId );
    } );


    qInfo() << "TvMazeProgramService::findOnTheRise [PROGRAMS_COUNT]" << programs.count();

    return programs;

}

QList<ProgramModel*> TvMazeProgramService::findByName( const QString& dsQuery ) const {

    qInfo() << "TvMazeProgramService::findByName [DS_QUERY]" << dsQuery;

    QList<ProgramModel*> programs = {};

    RetryTask::exec( [&]() {

        std::unique_ptr<ProgramsResponse> response ( _tvMazeEndpoint.findByName( dsQuery ) );

        if( !response || !response->isSuccess() ){
            qCritical() << "TvMazeProgramService::findByName falha ao buscar o [DS_QUERY]" << dsQuery;
            return false;
        }

        programs = ListConverter<ProgramModel*,ProgramResponse*>::toList( response->programs(), &ProgramConverter::toModel );

        return true;

    }, NR_MAX_RETRY );

    return programs;
}

ProgramModel* TvMazeProgramService::findByIdProgram( const QString& idProgram ) const {

    qInfo() << "TvMazeProgramService::findByIdProgram [ID_PROGRAM]" << idProgram;

    ProgramModel* program = nullptr;

    RetryTask::exec( [&]() {

        std::unique_ptr<ProgramResponse> response ( _tvMazeEndpoint.findByIdProgram( idProgram ) );

        if( !response || !response->isSuccess() ){
            qCritical() << "TvMazeProgramService::findById falha ao buscar o [ID_PROGRAMA]" << idProgram;
            return false;
        }

        program = ProgramConverter::toModel( response.get() );

        return true;

    }, NR_MAX_RETRY );

    qInfo() << "TvMazeProgramService::findById [HAS_PROGRAM]" << ( program != nullptr );

    return program;

}

ProgramModel* TvMazeProgramService::findBySingleSearch( const QString& dsQuery ) const {

    qInfo() << "TvMazeProgramService::findBySingleSearch [DS_QUERY]" << dsQuery;

    ProgramModel* program = nullptr;

    RetryTask::exec( [&]() {

        std::unique_ptr<ProgramResponse> response ( _tvMazeEndpoint.findBySingleSearch( dsQuery ) );

        if( !response || !response->isSuccess() ){
            qCritical() << "TvMazeProgramService::findBySingleSearch falha ao buscar o [ID_PROGRAMA]" << dsQuery;
            return false;
        }

        program = ProgramConverter::toModel( response.get() );

        return true;

    }, NR_MAX_RETRY );

    qInfo() << "TvMazeProgramService::findBySingleSearch [HAS_PROGRAM]" << ( program != nullptr );

    return program;

}
