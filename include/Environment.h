/*
 * $FU-Copyright$
 */

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include "Clock.h"

namespace ARA {

/**
 * The Environment class represents a static point of access to environment related
 * information objects like the concrete Clock for the time abstraction layer.
 *
 * It is implemented via the singleton pattern and can therefore never be instantiated directly.
 * Instead every user should use the public static methods that are declared in this header.
 */
class Environment {

public:

    /**
     * Returns the currently used system clock. Depending on the actual environment this might
     * be a UnixClock or it could be a OMNetClock.
     *
     * Note: This will default to a UnixClock implementation.
     * The Clock instance will be deleted by the environment when appropriate.
     */
    static Clock* getClock();

    static void setClock(Clock* newClock);

private:
    static Environment* instance;
    Clock* clock;

    /**
     * Private singleton constructor.
     */
    Environment();
    ~Environment();

    /**
     * The non static variant of Environment::setClock()
     */
    void setTheClock(Clock* newClock);

    /**
     * Access from the outside should always be directly through the static methods
     * like Environment::getClock() so there is no use in making getInstance public.
     */
    static Environment& getInstance();
};

} /* namespace ARA */
#endif // ENVIRONMENT_H_
