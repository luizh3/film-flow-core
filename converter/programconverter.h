#ifndef PROGRAMCONVERTER_H
#define PROGRAMCONVERTER_H

#include <model/program/programmodel.h>

#include <network/response/program/programresponse.h>

class ProgramConverter {
public:
    static ProgramModel* toModel( const ProgramResponse* programResponse );
};

#endif // PROGRAMCONVERTER_H
