#ifndef PROGRAMCONVERTER_H
#define PROGRAMCONVERTER_H

#include <film-flow-core/film-flow-core_global.h>

#include <model/program/programmodel.h>

#include <network/response/program/programresponse.h>

class Q_DECL_EXPORT ProgramConverter {
public:
    static ProgramModel* toModel( const ProgramResponse* programResponse );
};

#endif // PROGRAMCONVERTER_H
