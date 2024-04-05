#include "programconverter.h"

ProgramModel* ProgramConverter::toModel( const ProgramResponse* programResponse ) {

    ProgramModel* programModel = new ProgramModel();
    programModel->setDsImageUrl( programResponse->dsImageUrl() );
    programModel->setDsName( programResponse->dsName() );
    programModel->setDsSummary( programResponse->dsSummary() );
    programModel->setGenres( programResponse->genres() );

    if( programResponse->average() ){
        programModel->setAverage( new ProgramAverageModel( programResponse->average()->nrRating() ) );
    }

    return programModel;
}
