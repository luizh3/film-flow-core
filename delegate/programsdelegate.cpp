#include "programsdelegate.h"

#include <service/factory/programsservicefactory.h>

ProgramsDelegate::ProgramsDelegate() :
    _programService( ProgramsServiceFactory::create( TypeApiProgramEnum::TV_MAZE ) ) {}

ProgramsDelegate::~ProgramsDelegate() {
    delete _programService;
}

QList<ProgramModel*> ProgramsDelegate::findOnTheRise() const {
    return _programService->findOnTheRise();
}

QList<ProgramModel*> ProgramsDelegate::findByName( const QString& dsQuery ) const {
    return _programService->findByName( dsQuery );
}
