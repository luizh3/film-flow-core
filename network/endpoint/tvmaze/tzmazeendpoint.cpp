#include "tzmazeendpoint.h"

namespace {
    constexpr const char* BASE_URL = "https://api.tvmaze.com";
    constexpr const char* PREFIX_QUERY = "?q=%0";
}

//TODO ajustar o nome dessa class, ficou Tz...
ProgramResponse* TzMazeEndpoint::findByIdProgram( const QString& idProgram ) const {
    return _httpRequestManager.get<ProgramResponse>( BASE_URL, { "shows", idProgram } );
}

ProgramResponse *TzMazeEndpoint::findBySingleSearch( const QString& dsQuery ) const {
    return _httpRequestManager.get<ProgramResponse>( BASE_URL, { "singlesearch", "shows", QString( PREFIX_QUERY ).arg( dsQuery ) } );
}

ProgramsResponse* TzMazeEndpoint::findByName( const QString& dsQuery ) const {
    return _httpRequestManager.get<ProgramsResponse>( BASE_URL, { "search", "shows", QString( PREFIX_QUERY ).arg( dsQuery ) } );
}

