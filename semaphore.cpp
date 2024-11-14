#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <random>
using namespace std;

const int NUM_PHILOSOPHERS = 5;
const int MAX_MEALS = 5; 
mutex forks[NUM_PHILOSOPHERS]; 

mutex coutMutex;

void think(int philosopher) {
    unique_lock<mutex> lock(coutMutex);
    cout << "Philosopher " << philosopher << " is thinking...\n";
    lock.unlock();
    sleep(rand() % 3 + 1);  
}

void eat(int philosopher) {
    unique_lock<mutex> lock(coutMutex);
    cout << "Philosopher " << philosopher << " is eating...\n";
    lock.unlock();
    sleep(rand() % 3 + 1); 
}

void philosopher(int id) {
    int leftFork = id;  
    int rightFork = (id + 1) % NUM_PHILOSOPHERS;  
    int mealsEaten = 0; 

    while (mealsEaten < MAX_MEALS) { 
        think(id);

        if (id % 2 == 0) {  
            forks[leftFork].lock();
            forks[rightFork].lock();
        } else {  
            forks[rightFork].lock();
            forks[leftFork].lock();
        }

        eat(id);
        mealsEaten++;

        forks[leftFork].unlock();
        forks[rightFork].unlock();
    }

    unique_lock<mutex> lock(coutMutex);
    cout << "Philosopher " << id << " has finished eating " << MAX_MEALS << " meals.\n";
}

int main() {
    thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = thread(philosopher, i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}
