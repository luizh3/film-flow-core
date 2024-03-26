#include "programaveragemodel.h"

ProgramAverageModel::ProgramAverageModel( const QString& nrRating ) :
    _nrRating( nrRating ) {}

QString ProgramAverageModel::nrRating() const {
    return _nrRating;
}

void ProgramAverageModel::setNrRating( const QString& nrRating ) {
    _nrRating = nrRating;
}
