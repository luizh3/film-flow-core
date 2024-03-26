#include "programsearchmodel.h"

ProgramSearchModel::ProgramSearchModel() :
    _fgSearchByName( false ),
    _ids( { } ),
    _names( {} ){ }

bool ProgramSearchModel::isSearchByName() const {
    return _fgSearchByName;
}

void ProgramSearchModel::setFgSearchByName( const bool isSearchByName ) {
    _fgSearchByName = isSearchByName;
}

QList<QString> ProgramSearchModel::ids() const {
    return _ids;
}

void ProgramSearchModel::setIds( const QList<QString>& ids ) {
    _ids = ids;
}

QList<QString> ProgramSearchModel::names() const {
    return _names;
}

void ProgramSearchModel::setNames( const QList<QString>& names ) {
    _names = names;
}
