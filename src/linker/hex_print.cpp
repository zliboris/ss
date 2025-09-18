#include "../../inc/linker/hex_print.hpp"


std::string to_hex_8(uint32_t value) {
    std::ostringstream oss;
    oss << std::setw(8)
        << std::setfill('0')
        << std::hex
        << std::nouppercase
        << static_cast<int>(value);
    return oss.str();
}

std::string to_hex_2(uint8_t value) {
    std::ostringstream oss;
    oss << std::setw(2)
        << std::setfill('0')
        << std::hex
        << std::nouppercase
        << static_cast<int>(value);
    return oss.str();
}

uint8_t from_hex_8(const std::string& s) {
    return static_cast<uint8_t>(std::stoi(s, nullptr, 16));
}

uint32_t parseHex(const std::string& s) {
    try {
        return static_cast<unsigned int>(std::stoul(s, nullptr, 16));
    } catch (const std::invalid_argument&) {
        throw std::runtime_error("Nevalidan broj: " + s);
    } catch (const std::out_of_range&) {
        throw std::runtime_error("Broj je prevelik: " + s);
    }
}
