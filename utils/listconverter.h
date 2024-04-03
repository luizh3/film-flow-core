#ifndef LISTCONVERTER_H
#define LISTCONVERTER_H

#include <QList>

#include <film-flow-core/film-flow-core_global.h>

template<typename First, typename Second>
class FILMFLOWCORE_EXPORT ListConverter {
public:
    static QList<Second*> toList( QList<First*> values ) {
        // static_assert( std::is_base_of<Derived,Base>::value, "O Tipo atual precisa extender da base class");

        QList<Second*> seconds = {};

        for( Second* second : values ) {
            seconds.append( second );
        }

        return seconds;
    };

    static QList<First> toList( const QList<Second>& seconds, std::function<First( const Second second)> convertCallback) {

        QList<First> firsts = {};

        for( const Second second : seconds ) {
            const First first = convertCallback( second );
            if( first != nullptr ) {
                firsts.append( first );
            }
        }

        return firsts;
    }
};

#endif // LISTCONVERTER_H
