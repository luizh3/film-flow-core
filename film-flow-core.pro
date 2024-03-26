QT -= gui

QT += network concurrent

TEMPLATE = lib
DEFINES += FILMFLOWCORE_LIBRARY

DEFINES += PROJECT_PATH=\"\\\"$${_PRO_FILE_PWD_}\\\"\"

CONFIG += c++17

SOURCES += \
    controller/programscontroller.cpp \
    converter/programconverter.cpp \
    delegate/programsdelegate.cpp \
    filmflowcore.cpp \
    model/program/programaveragemodel.cpp \
    model/program/programmodel.cpp \
    model/program/programsearchmodel.cpp \
    network/endpoint/tvmaze/tzmazeendpoint.cpp \
    network/response/program/programaverageresponse.cpp \
    network/response/program/programresponse.cpp \
    network/response/program/programsresponse.cpp \
    repository/programrepository.cpp \
    service/factory/programsservicefactory.cpp \
    service/programs/programsservice.cpp \
    service/programs/tvmaze/tvmazeprogramsservice.cpp \
    utils/retrytask.cpp \
    utils/synctask.cpp

HEADERS += \
    controller/programscontroller.h \
    converter/programconverter.h \
    delegate/programsdelegate.h \
    film-flow-core_global.h \
    filmflowcore.h \
    model/program/programaveragemodel.h \
    model/program/programsearchmodel.h \
    network/response/program/programaverageresponse.h \
    network/response/program/programsresponse.h \
    repository/programrepository.h \
    utils/listconverter.h \
    model/program/programmodel.h \
    model/program/typeapiprogramenum.h \
    network/endpoint/tvmaze/tzmazeendpoint.h \
    network/response/program/programresponse.h \
    service/factory/programsservicefactory.h \
    service/programs/programsservice.h \
    service/programs/tvmaze/tvmazeprogramsservice.h \
    utils/retrytask.h \
    utils/synctask.h

LIBRARY_DEPENDENCIES = \
    HTTP-REQUEST

CONFIG( debug, debug|release ) {
    DESTDIR = build/debug
}

CONFIG( release, debug|release ) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

unix {
    target.path = /usr/bin
    INSTALLS += target
}

include( $$PWD/film-flow-core-dependencies.pri )


