#ifndef PROGRAMAVERAGERESPONSE_H
#define PROGRAMAVERAGERESPONSE_H

#include <QString>
#include <QJsonObject>

class ProgramAverageResponse {
public:
    ProgramAverageResponse( const QJsonObject& jsonObject );

    QString nrRating() const;

    static constexpr const char* DS_AVERAGE_TAG = "average";
    static constexpr const char* DS_RATING_TAG = "rating";

private:
    void fromJson( const QJsonObject& jsonObject );

    QString _nrRating;
};

#endif // PROGRAMAVERAGERESPONSE_H
