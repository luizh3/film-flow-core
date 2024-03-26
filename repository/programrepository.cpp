#include "programrepository.h"

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QSettings>
#include <QRegularExpression>

ProgramSearchModel* ProgramRepository::findProgramsSearch() const {

    qInfo() << "ProgramRepository::findProgramsSearch";

    const QString pathFile = QDir::toNativeSeparators( QString( "%0%1").arg( PROJECT_PATH, "/data/programs/search.ini" ) );

    if( !QFile::exists( pathFile ) ){
        qCritical() << "ProgramRepository::findProgramsSearch arquivo que contem os programas a serem procurados não foi encontrado.";
        return nullptr;
    }

    QSettings settings( pathFile, QSettings::IniFormat );

    settings.beginGroup("PROGRAMS");

    ProgramSearchModel* programSearchModel = new ProgramSearchModel();

    programSearchModel->setFgSearchByName( settings.value( "FG_SEARCH_BY_NAME" ).toBool() );

    const QRegularExpression expression = QRegularExpression("\\s+");

    if( programSearchModel->isSearchByName() ) {
        QString names = settings.value( "NAME" ).toString().trimmed();
        programSearchModel->setNames( names.replace( expression, "" ).split( "," ) );
    } else {
        QString ids = settings.value( "IDS" ).toString().trimmed();
        programSearchModel->setIds( ids.replace( expression, "" ).split(",") );
    }

    settings.endGroup();

    qInfo() << "ProgramRepository::findProgramsSearch";

    return programSearchModel;

}
