#include "programdelegate.h"

#include <service/factory/program/programservicefactory.h>

ProgramDelegate::ProgramDelegate() :
    _programService( ProgramServiceFactory::create( TypeApiProgramEnum::TV_MAZE ) ) {}

ProgramDelegate::~ProgramDelegate() {
    delete _programService;
}

QList<ProgramModel*> ProgramDelegate::findOnTheRise() const {
    return _programService->findOnTheRise();
}

QList<ProgramModel*> ProgramDelegate::findByName( const QString& dsQuery ) const {
    return _programService->findByName( dsQuery );
}
