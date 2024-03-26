#include "programscontroller.h"

QList<ProgramModel*> ProgramsController::findOnTheRise() const {
    return _programsDelegate.findOnTheRise();
}

QList<ProgramModel *> ProgramsController::findByName( const QString& dsQuery ) const {
    return _programsDelegate.findByName( dsQuery );
}
