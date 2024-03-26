#ifndef PROGRAMSRESPONSE_H
#define PROGRAMSRESPONSE_H

#include <QList>

#include <film-flow-core/film-flow-core_global.h>

#include "programresponse.h"

class FILMFLOWCORE_EXPORT ProgramsResponse : public HttpStubResponse {
public:
    ProgramsResponse();
    ~ProgramsResponse();
    void fromJson( QJsonDocument& document ) override;
    QList<ProgramResponse*> programs() const;
private:
    QList<ProgramResponse*> _programs;
};

#endif // PROGRAMSRESPONSE_H
