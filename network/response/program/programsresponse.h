#ifndef PROGRAMSRESPONSE_H
#define PROGRAMSRESPONSE_H

#include <QList>

#include "programresponse.h"

class ProgramsResponse : public HttpStubResponse {
public:
    ProgramsResponse();
    ~ProgramsResponse();
    void fromJson( QJsonDocument& document ) override;
    QList<ProgramResponse*> programs() const;
private:
    QList<ProgramResponse*> _programs;
};

#endif // PROGRAMSRESPONSE_H
