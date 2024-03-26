#include "tvmazeprogramsservice.h"

#include <memory>

#include <utils/retrytask.h>
#include <utils/listconverter.h>

#include <repository/programrepository.h>

#include <converter/programconverter.h>

namespace {
    constexpr const int NR_MAX_RETRY = 3;
}

QList<ProgramModel*> TvMazeProgramsService::findOnTheRise() const {

    qInfo() << "TvMazeProgramsService::findOnTheRise";

    // TODO revisar uma maneira melhor de fazer essa rotina
    QList<ProgramModel*> programs = {};

    std::unique_ptr<ProgramSearchModel> programSearch( ProgramRepository().findProgramsSearch() );

    qInfo() << "TvMazeProgramsService::findOnTheRise [IS_SEARCH_BY_NAME]" << programSearch->isSearchByName();

    if( programSearch->isSearchByName() ) {

        programs = ListConverter<ProgramModel*,QString>::toList( programSearch->names(), [&]( const QString& dsName ){
            return findBySingleSearch( dsName );
        } );

        qInfo() << "TvMazeProgramsService::findOnTheRise [PROGRAMS_COUNT]" << programs.count();

        return programs;
    }

    programs = ListConverter<ProgramModel*,QString>::toList( programSearch->ids(), [&]( const QString& dsId ){
        return findByIdProgram( dsId );
    } );


    qInfo() << "TvMazeProgramsService::findOnTheRise [PROGRAMS_COUNT]" << programs.count();

    return programs;

}

QList<ProgramModel*> TvMazeProgramsService::findByName( const QString& dsQuery ) const {

    qInfo() << "TvMazeProgramsService::findByName [DS_QUERY]" << dsQuery;

    QList<ProgramModel*> programs = {};

    RetryTask::exec( [&]() {

        std::unique_ptr<ProgramsResponse> response ( _tvMazeEndpoint.findByName( dsQuery ) );

        if( !response || !response->isSuccess() ){
            qCritical() << "TvMazeProgramsService::findByName falha ao buscar o [DS_QUERY]" << dsQuery;
            return false;
        }

        programs = ListConverter<ProgramModel*,ProgramResponse*>::toList( response->programs(), &ProgramConverter::toModel );

        return true;

    }, NR_MAX_RETRY );

    return programs;
}

ProgramModel* TvMazeProgramsService::findByIdProgram( const QString& idProgram ) const {

    qInfo() << "TvMazeProgramsService::findByIdProgram [ID_PROGRAM]" << idProgram;

    ProgramModel* program = nullptr;

    RetryTask::exec( [&]() {

        std::unique_ptr<ProgramResponse> response ( _tvMazeEndpoint.findByIdProgram( idProgram ) );

        if( !response || !response->isSuccess() ){
            qCritical() << "TvMazeProgramsService::findById falha ao buscar o [ID_PROGRAMA]" << idProgram;
            return false;
        }

        program = ProgramConverter::toModel( response.get() );

        return true;

    }, NR_MAX_RETRY );

    qInfo() << "TvMazeProgramsService::findById [HAS_PROGRAM]" << ( program != nullptr );

    return program;

}

ProgramModel* TvMazeProgramsService::findBySingleSearch( const QString& dsQuery ) const {

    qInfo() << "TvMazeProgramsService::findBySingleSearch [DS_QUERY]" << dsQuery;

    ProgramModel* program = nullptr;

    RetryTask::exec( [&]() {

        std::unique_ptr<ProgramResponse> response ( _tvMazeEndpoint.findBySingleSearch( dsQuery ) );

        if( !response || !response->isSuccess() ){
            qCritical() << "TvMazeProgramsService::findBySingleSearch falha ao buscar o [ID_PROGRAMA]" << dsQuery;
            return false;
        }

        program = ProgramConverter::toModel( response.get() );

        return true;

    }, NR_MAX_RETRY );

    qInfo() << "TvMazeProgramsService::findBySingleSearch [HAS_PROGRAM]" << ( program != nullptr );

    return program;

}
