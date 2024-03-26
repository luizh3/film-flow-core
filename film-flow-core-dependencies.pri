BASE_PATH = $$PWD/..

INCLUDEPATH += $$BASE_PATH

win32 {
    LIBS += -L$$BASE_PATH/shared/dll -llibcrypto-1_1-x64
}

unix {
    # No unix se tiver o openssl 1.1.1 instalado isso se torna desnecessário
    LIBS += -L$$BASE_PATH/shared/lib -libcrypto.lib
}

contains( LIBRARY_DEPENDENCIES, HTTP-REQUEST ) {

    message( "HTTP_REQUEST dependencie including...")

    HTTP_REQUEST_DIR = $$BASE_PATH/http-request

    INCLUDEPATH += $$BASE_PATH/http-request

    LIBS += -L$$HTTP_REQUEST_DIR/$$DESTDIR -lhttp-request

    unix {
        QMAKE_RPATHDIR += $$HTTP_REQUEST_DIR/$$DESTDIR
    }

}
