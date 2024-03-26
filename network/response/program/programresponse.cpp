#include "programresponse.h"

#include <QJsonObject>
#include <QJsonArray>

namespace {
constexpr const char* DS_NAME_TAG = "name";

constexpr const char* DS_IMAGE_TAG = "image";
constexpr const char* DS_IMAGE_URL_TAG = "original";

constexpr const char* DS_SUMMARY_TAG = "summary";
constexpr const char* DS_GENRES_TAG = "genres";
}

ProgramResponse::ProgramResponse() :
    _average( nullptr ),
    _dsName( "" ),
    _dsImageUrl( "" ),
    _dsSummary( "" ),
    _genres( {} ){
}

ProgramResponse::~ProgramResponse() {
    delete _average;
}

void ProgramResponse::fromJson( QJsonDocument& document ){

    qInfo() << "ProgramResponse::fromJson";

    QJsonObject jsonObject = document.object();

    _dsName = document[DS_NAME_TAG].toString();

    _dsSummary = document[DS_SUMMARY_TAG].toString();

    QJsonArray genresArray = document[DS_GENRES_TAG].toArray();

    for ( const QJsonValue& genreValue : genresArray ) {
        _genres.append( genreValue.toString() );
    }

    QJsonObject imageObject = document[DS_IMAGE_TAG].toObject();

    if( !imageObject.isEmpty() ){
        _dsImageUrl = imageObject[DS_IMAGE_URL_TAG].toString();
    }

    QJsonObject averageObject = document[ProgramAverageResponse::DS_RATING_TAG].toObject();

    if( !averageObject.isEmpty() && !averageObject[ProgramAverageResponse::DS_AVERAGE_TAG].isNull() ) {
        _average = new ProgramAverageResponse( averageObject );
    }

    qInfo() << "ProgramResponse::fromJson";

}

ProgramAverageResponse* ProgramResponse::average() const {
    return _average;
}

QString ProgramResponse::dsName() const {
    return _dsName;
}

QString ProgramResponse::dsImageUrl() const {
    return _dsImageUrl;
}

QString ProgramResponse::dsSummary() const {
    return _dsSummary;
}

QStringList ProgramResponse::genres() const {
    return _genres;
}
