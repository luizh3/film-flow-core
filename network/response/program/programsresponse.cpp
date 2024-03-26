#include "programsresponse.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

namespace {
constexpr const char* DS_SHOW_TAG = "show";
}

ProgramsResponse::ProgramsResponse() :
    _programs( {} ) {}

ProgramsResponse::~ProgramsResponse() {
    qInfo() << "ProgramsResponse::~ProgramsResponse";
    qDeleteAll( _programs );
    qInfo() << "ProgramsResponse::~ProgramsResponse";
}

void ProgramsResponse::fromJson( QJsonDocument& document ) {

    QJsonArray programsArray = document.array();

    for( const QJsonValue& programJson : programsArray ) {

        QJsonDocument document = QJsonDocument( programJson[ DS_SHOW_TAG ].toObject() );

        // TODO talvez criar um objeto intermediario que so tenha os dados do response.
        // pois da forma que esta agora todo objeto vai ter um httpStatusCode
        ProgramResponse* programResponse = new ProgramResponse();
        programResponse->fromJson( document );

        _programs.append( programResponse );

    }
}

QList<ProgramResponse*> ProgramsResponse::programs() const {
    return _programs;
}
