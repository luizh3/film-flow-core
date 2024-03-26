#ifndef PROGRAMSSERVICEFACTORY_H
#define PROGRAMSSERVICEFACTORY_H

#include <model/program/typeapiprogramenum.h>

class ProgramsService;
class ProgramsServiceFactory {
public:
    static ProgramsService* create( const TypeApiProgramEnum tpApiProgram );
};

#endif // PROGRAMSSERVICEFACTORY_H
