/**
 * Two shoppers adding garlic and potatoes to a shared notepad
 * solved by using mutex and mutual exclusion
 */
#include <cstdio>
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

std::recursive_mutex rm_pencil;
unsigned int garlic_count = 0;
unsigned int potato_count = 0;
std::mutex m_pencil;
unsigned int m_garlic_count = 0;
unsigned int m_potato_count = 0;
std::atomic<unsigned int> atomic_garlic_count;
std::atomic<unsigned int> atomic_potato_count;

const unsigned int N_TIMES = 10000000;

void add_garlic() {
    rm_pencil.lock();
    garlic_count++;
    rm_pencil.unlock();
}

void add_potato() {
    rm_pencil.lock();
    potato_count++;
    add_garlic();
    rm_pencil.unlock();
}

void shopper() {
    for (int i=0; i<N_TIMES; i++) {
        add_garlic();
        add_potato();
    }
}

void add_garlic_under_lock() {
    m_garlic_count++;
}

void add_potato_under_lock() {
    m_potato_count++;
    add_garlic_under_lock();
}

void shopper_under_lock() {
    for (int i=0; i<N_TIMES; i++) {
        m_pencil.lock();
        add_garlic_under_lock();
        m_pencil.unlock();

        m_pencil.lock();
        add_potato_under_lock();
        m_pencil.unlock();
    }
}

void add_garlic_using_atomic() {
    atomic_garlic_count++;
}

void add_potato_using_atomic() {
    atomic_potato_count++;
    add_garlic_using_atomic();
}

void shopper_atomic() {
    for (int i=0; i<N_TIMES; i++) {
        add_garlic_using_atomic();
        add_potato_using_atomic();
    }
}

int main() {
    // using recursive mutex for a recursive problem
    printf("Using recursive mutex for a recursive problem:\n");
    std::thread barron(shopper);
    std::thread olivia(shopper);
    auto t1 = std::chrono::high_resolution_clock::now();
    barron.join();
    olivia.join();
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
    std::cout << "Recursive mutex took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    // using mutex for a recursive problem
    printf("Using mutex for a recursive problem:\n");
    std::thread carlos(shopper_under_lock);
    std::thread raquel(shopper_under_lock);
    t1 = std::chrono::high_resolution_clock::now();
    carlos.join();
    raquel.join();
    t2 = std::chrono::high_resolution_clock::now();
    printf("We should buy %u garlic.\n", m_garlic_count);
    printf("We should buy %u potatoes.\n", m_potato_count);
    std::cout << "Mutex took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    // using atomic for a recursive problem
    printf("Using atomic for a recursive problem:\n");
    std::thread mariano(shopper_atomic);
    std::thread maria(shopper_atomic);
    t1 = std::chrono::high_resolution_clock::now();
    mariano.join();
    maria.join();
    t2 = std::chrono::high_resolution_clock::now();
    printf("We should buy %u garlic.\n", atomic_garlic_count.load());
    printf("We should buy %u potatoes.\n", atomic_potato_count.load());
    std::cout << "Atomic took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
}