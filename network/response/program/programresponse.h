#ifndef PROGRAMRESPONSE_H
#define PROGRAMRESPONSE_H

#include <http-request/response/httpstubresponse.h>

#include "programaverageresponse.h"

class ProgramResponse : public HttpStubResponse {
public:
    ProgramResponse();
    ~ProgramResponse();

    void fromJson( QJsonDocument& document ) override;

    ProgramAverageResponse* average() const;

    QString dsName() const;
    QString dsImageUrl() const;
    QString dsSummary() const;
    QStringList genres() const;

private:
    ProgramAverageResponse* _average;

    QString _dsName;
    QString _dsImageUrl;
    QString _dsSummary;
    QStringList _genres;
};

#endif // PROGRAMRESPONSE_H
