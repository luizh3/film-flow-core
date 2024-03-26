#ifndef PROGRAMSSERVICEFACTORY_H
#define PROGRAMSSERVICEFACTORY_H

#include <film-flow-core/film-flow-core_global.h>

#include <model/program/typeapiprogramenum.h>

class ProgramsService;
class FILMFLOWCORE_EXPORT ProgramsServiceFactory {
public:
    static ProgramsService* create( const TypeApiProgramEnum tpApiProgram );
};

#endif // PROGRAMSSERVICEFACTORY_H
