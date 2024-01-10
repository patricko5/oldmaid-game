#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* Exception when the game cannot start.
*/
class game_init_error: public std::runtime_error {
 public:
    /**
    * @param errMessage An error message.
    */
    explicit game_init_error(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

#endif // EXCEPTIONS_H_INCLUDED
