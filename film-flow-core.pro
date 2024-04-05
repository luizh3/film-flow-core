QT -= gui

QT += network concurrent

TEMPLATE = lib
DEFINES += FILMFLOWCORE_LIBRARY

DEFINES += PROJECT_PATH=\"\\\"$${_PRO_FILE_PWD_}\\\"\"

CONFIG += c++17

SOURCES += \
    controller/program/programcontroller.cpp \
    converter/program/programconverter.cpp \
    delegate/program/programdelegate.cpp \
    model/program/programaveragemodel.cpp \
    model/program/programmodel.cpp \
    model/program/programsearchmodel.cpp \
    network/endpoint/program/tvmaze/tvmazeendpoint.cpp \
    network/response/program/programaverageresponse.cpp \
    network/response/program/programresponse.cpp \
    network/response/program/programsresponse.cpp \
    repository/program/programrepository.cpp \
    service/factory/program/programservicefactory.cpp \
    service/program/tvmaze/tvmazeprogramservice.cpp \
    utils/retrytask.cpp \
    utils/synctask.cpp

HEADERS += \
    controller/program/programcontroller.h \
    converter/program/programconverter.h \
    delegate/program/programdelegate.h \
    film-flow-core_global.h \
    model/program/programaveragemodel.h \
    model/program/programsearchmodel.h \
    network/endpoint/program/tvmaze/tvmazeendpoint.h \
    network/response/program/programaverageresponse.h \
    network/response/program/programsresponse.h \
    repository/program/programrepository.h \
    service/factory/program/programservicefactory.h \
    service/program/programservice.h \
    service/program/tvmaze/tvmazeprogramservice.h \
    utils/listconverter.h \
    model/program/programmodel.h \
    model/program/typeapiprogramenum.h \
    network/response/program/programresponse.h \
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


