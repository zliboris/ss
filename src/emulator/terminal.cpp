#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <thread>
#include <atomic>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Memorijski mapirani registri
std::atomic<uint32_t> term_out = 0;
std::atomic<uint32_t> term_in = 0;

// Prekidna zastavica
std::atomic<bool> terminal_interrupt_pending = false;
std::atomic<bool> running = true;

// Funkcija za podešavanje terminala u "raw mode"
void set_terminal_raw_mode(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);        // čuvamo stare postavke
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);      // isključi kanonski mod i echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // non-blocking read
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // vrati stare postavke
    }
}

// Funkcija koja simulira upis u term_out registar
void write_term_out(uint32_t value) {
    term_out = value & 0xFF;  // čuvamo samo jedan bajt
    std::cout << static_cast<char>(term_out);
    std::cout.flush();
}

uint32_t read_term_in(){
	return term_in;
}

// Funkcija koja proverava tastaturu i upisuje u term_in
void poll_keyboard() {
    char c;
    int n = read(STDIN_FILENO, &c, 1);
    if (n > 0) {
        term_in = static_cast<uint8_t>(c);
		//std::cout << c;
    	//std::cout.flush();
        terminal_interrupt_pending = true; // generiši prekid
    }
}

// Ovo je funkcija za novi thread
void terminal_thread() {
    set_terminal_raw_mode(true);

    std::cout << "Terminal emulator thread running. Type keys, CTRL+C to exit.\n";

    while (running) {
        poll_keyboard();
    }

    set_terminal_raw_mode(false);
}
