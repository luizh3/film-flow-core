#ifndef TVMAZEENDPOINT_H
#define TVMAZEENDPOINT_H

#include <http-request/httprequestmanager.h>

#include <network/response/program/programresponse.h>
#include <network/response/program/programsresponse.h>

class TvMazeEndpoint {
public:
    ProgramResponse* findByIdProgram( const QString& idProgram ) const;
    ProgramResponse* findBySingleSearch( const QString& dsQuery ) const;

    ProgramsResponse* findByName( const QString& dsQuery ) const;
private:
    HttpRequestManager _httpRequestManager;
};

#endif // TVMAZEENDPOINT_H
