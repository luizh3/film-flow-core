#ifndef TZMAZEENDPOINT_H
#define TZMAZEENDPOINT_H

#include <http-request/httprequestmanager.h>

#include <network/response/program/programresponse.h>
#include <network/response/program/programsresponse.h>

#include <film-flow-core/film-flow-core_global.h>

class FILMFLOWCORE_EXPORT TzMazeEndpoint {
public:
    ProgramResponse* findByIdProgram( const QString& idProgram ) const;
    ProgramResponse* findBySingleSearch( const QString& dsQuery ) const;

    ProgramsResponse* findByName( const QString& dsQuery ) const;
private:
    HttpRequestManager _httpRequestManager;
};

#endif // TZMAZEENDPOINT_H
