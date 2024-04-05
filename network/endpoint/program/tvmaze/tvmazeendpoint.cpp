#include "tvmazeendpoint.h"

namespace {
    constexpr const char* BASE_URL = "https://api.tvmaze.com";
    constexpr const char* PREFIX_QUERY = "?q=%0";
}

ProgramResponse* TvMazeEndpoint::findByIdProgram( const QString& idProgram ) const {
    return _httpRequestManager.get<ProgramResponse>( BASE_URL, { "shows", idProgram } );
}

ProgramResponse* TvMazeEndpoint::findBySingleSearch( const QString& dsQuery ) const {
    return _httpRequestManager.get<ProgramResponse>( BASE_URL, { "singlesearch", "shows", QString( PREFIX_QUERY ).arg( dsQuery ) } );
}

ProgramsResponse* TvMazeEndpoint::findByName( const QString& dsQuery ) const {
    return _httpRequestManager.get<ProgramsResponse>( BASE_URL, { "search", "shows", QString( PREFIX_QUERY ).arg( dsQuery ) } );
}

