#include "programsservicefactory.h"

#include <QDebug>

#include <service/programs/tvmaze/tvmazeprogramsservice.h>

ProgramsService *ProgramsServiceFactory::create( const TypeApiProgramEnum tpApiProgram ) {

    qInfo() << "ProgramsServiceFactory::create [TP_API_PROGRAM]" << static_cast<int>( tpApiProgram );

    switch ( tpApiProgram ) {
        case TypeApiProgramEnum::TV_MAZE:
            qInfo() << "ProgramsServiceFactory::create return TvMaze";
            return new TvMazeProgramsService();
        default:
            qCritical() << "ProgramsServiceFactory::create return nullptr";
            return nullptr;
    }

}
