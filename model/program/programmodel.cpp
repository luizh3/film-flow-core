#include "programmodel.h"

ProgramModel::ProgramModel() :
    _average( nullptr ),
    _dsName( "" ),
    _dsImageUrl( "" ){}

ProgramModel::~ProgramModel() {
    delete _average;
}

QString ProgramModel::dsName() const {
    return _dsName;
}

void ProgramModel::setDsName( const QString& dsName ) {
    _dsName = dsName;
}

QString ProgramModel::dsImageUrl() const {
    return _dsImageUrl;
}

void ProgramModel::setDsImageUrl( const QString& dsImageUrl ) {
    _dsImageUrl = dsImageUrl;
}

QString ProgramModel::dsSummary() const {
    return _dsSummary;
}

void ProgramModel::setDsSummary( const QString& dsSummary ) {
    _dsSummary = dsSummary;
}

QStringList ProgramModel::genres() const {
    return _genres;
}

void ProgramModel::setGenres( const QStringList& genres ) {
    _genres = genres;
}

ProgramAverageModel* ProgramModel::average() const {
    return _average;
}

void ProgramModel::setAverage( ProgramAverageModel* average ) {
    _average = average;
}
