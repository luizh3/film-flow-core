#ifndef PROGRAMSERVICEFACTORY_H
#define PROGRAMSERVICEFACTORY_H

#include <model/program/typeapiprogramenum.h>

class ProgramService;
class ProgramServiceFactory {
public:
    static ProgramService* create( const TypeApiProgramEnum tpApiProgram );
};

#endif // PROGRAMSERVICEFACTORY_H
