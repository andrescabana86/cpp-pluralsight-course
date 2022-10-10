/**
 * Two threads cooking soup
 * Thread life cycle C++ demo
 */
#include <thread>
#include <chrono>
#include <cstdio>

void chef_olivia() {
    printf("Olivia started & waiting for sausage to thaw...\n");
    std::this_thread::sleep_for(std::chrono::seconds(4));
    printf("Olivia is done cutting sausage.\n");
}

int main() {
    printf("Barron requests Olivia's help.\n");
    std::thread olivia(chef_olivia);
    // check if thread is joinable (meaning, can block the parent thread until it finishes)
    printf("  Olivia thread is joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron continues cooking soup.\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("  Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    // joining a thread means that the parent thread will be blocked until the joinable thread ends
    printf("Barron patiently waits for Olivia to finish and join...\n");
    olivia.join();
    printf("  Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron and Olivia are both done!\n");
}