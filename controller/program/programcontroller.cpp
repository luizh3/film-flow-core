#include "programcontroller.h"

QList<ProgramModel*> ProgramController::findOnTheRise() const {
    return _programDelegate.findOnTheRise();
}

QList<ProgramModel*> ProgramController::findByName( const QString& dsQuery ) const {
    return _programDelegate.findByName( dsQuery );
}
