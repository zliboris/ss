#ifndef _toggleoutput_
#define _toggleoutput_

#include <iostream>
#include <sstream>

#define OUTPUT true

class ToggleOstream {
    static std::ostream& real_out;
    static std::ostringstream null_out;

public:

    static std::ostream& stream() {
        return OUTPUT ? real_out : null_out;
    }
};

std::ostream& ToggleOstream::real_out = std::cout;
std::ostringstream ToggleOstream::null_out;

#endif
