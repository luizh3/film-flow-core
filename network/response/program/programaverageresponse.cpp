#include "programaverageresponse.h"

#include <QJsonObject>

ProgramAverageResponse::ProgramAverageResponse( const QJsonObject& jsonObject ) :
    _nrRating( "" ){
    fromJson( jsonObject );
}

void ProgramAverageResponse::fromJson( const QJsonObject& jsonObject ) {
    const double nrAverage = jsonObject[DS_AVERAGE_TAG].toDouble();
    _nrRating = QString::number( nrAverage, 'f', 1 );
}

QString ProgramAverageResponse::nrRating() const {
    return _nrRating;
}
