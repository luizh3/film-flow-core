#include "programservicefactory.h"

#include <QDebug>

#include <service/program/tvmaze/tvmazeprogramservice.h>

ProgramService* ProgramServiceFactory::create( const TypeApiProgramEnum tpApiProgram ) {

    qInfo() << "ProgramServiceFactory::create [TP_API_PROGRAM]" << static_cast<int>( tpApiProgram );

    switch ( tpApiProgram ) {
        case TypeApiProgramEnum::TV_MAZE:
            qInfo() << "ProgramServiceFactory::create return TvMaze";
            return new TvMazeProgramService();
        default:
            qCritical() << "ProgramServiceFactory::create return nullptr";
            return nullptr;
    }

}
