#include "../../inc/assembler/hex_print.hpp"


std::string to_hex_8(uint32_t value) {
    std::ostringstream oss;
    oss << std::setw(8)        // širina = 2 cifre
        << std::setfill('0')   // popuni nulama
        << std::hex
        << std::nouppercase    // koristi mala slova a–f
        << static_cast<int>(value); // cast jer bi se uint8_t ispisao kao char
    return oss.str();
}

std::string to_hex_2(uint8_t value) {
    std::ostringstream oss;
    oss << std::setw(2)        // širina = 2 cifre
        << std::setfill('0')   // popuni nulama
        << std::hex
        << std::nouppercase    // koristi mala slova a–f
        << static_cast<int>(value); // cast jer bi se uint8_t ispisao kao char
    return oss.str();
}
