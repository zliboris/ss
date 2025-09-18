#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <unordered_map>

// Memorijski mapirani registar tajmera
std::atomic<uint32_t> tim_cfg = 0x0; // inicijalno 0
std::atomic<bool> timer_interrupt_pending = false;
extern std::atomic<bool> running;

// Mapa koja povezuje vrednost tim_cfg sa periodom
std::unordered_map<uint32_t, std::chrono::milliseconds> timer_periods = {
    {0x0, std::chrono::milliseconds(500)},
    {0x1, std::chrono::milliseconds(1000)},
    {0x2, std::chrono::milliseconds(1500)},
    {0x3, std::chrono::milliseconds(2000)},
    {0x4, std::chrono::milliseconds(5000)},
    {0x5, std::chrono::milliseconds(10000)},
    {0x6, std::chrono::milliseconds(30000)},
    {0x7, std::chrono::milliseconds(60000)},
};

void write_tim_cfg(uint32_t value){
	tim_cfg = value;
}

uint32_t read_tim_cfg(){
	return tim_cfg;
}


// Funkcija tajmer periferije
void timer_thread() {
    std::cout << "[Timer] Thread started, default period = 500ms\n";

    while (running) {
        uint32_t cfg = tim_cfg.load(); 

        auto it = timer_periods.find(cfg);
        std::chrono::milliseconds period(500); // default
        if (it != timer_periods.end()) {
            period = it->second;
        }

        std::this_thread::sleep_for(period);

        // generiši prekid
        timer_interrupt_pending = true;
    }
}
