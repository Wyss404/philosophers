Philosopher
42 School — Threads & Mutexes
by hdruel

Description
Philosopher is a concurrency project from the 42 curriculum. Its goal is to introduce the concepts of threads, mutexes, and synchronization by solving the classic Dining Philosophers Problem.

The simulation features philosophers sitting at a round table, alternating between eating, thinking, and sleeping. Each philosopher must pick up two forks (shared with neighbors) to eat, and must not starve.

The project includes:
    • A simulation of N philosophers sitting around a table
    • Each philosopher is a thread running concurrently
    • Each fork between philosophers is protected by a mutex
    • A monitoring thread that detects death or end conditions
    • Strict time management using gettimeofday

Project Architecture and Design Choices
The Problem
The Dining Philosophers Problem is a classic concurrency challenge originally formulated by Edsger Dijkstra. It demonstrates fundamental issues in concurrent programming:
    • Resource sharing (forks shared between adjacent philosophers
    • Deadlock (all philosophers grab one fork and wait forever)
    • Starvation (a philosopher never gets to eat)
    • Race conditions (unsynchronized access to shared data)

Threads vs Processes

Threads (used here)
Processes (bonus)
Share memory space
Independent memory
Lightweight to create
Heavier to create
Fast context switch
Slower context switch
Communicate via shared data
Communicate via IPC
Require mutexes for safety
Require semaphores for safety

Threads are used in the mandatory part because philosophers need to share state (fork availability, death flag) efficiently. Processes are used in the bonus using semaphores.

Mutexes
A mutex (mutual exclusion lock) ensures that only one thread accesses a shared resource at a time. In this project, mutexes protect:
    • Each fork — only one philosopher can hold it at a time
    • The print function — prevents interleaved output
    • The death flag — safely read and written across threads
    • Meal tracking variables — for accurate starvation checks

Deadlock Prevention
To prevent deadlock (all philosophers holding one fork and waiting for the other), philosophers with an even index pick up the right fork first, while those with an odd index pick up the left fork first. This breaks the circular wait condition.

Time Management
All timing is handled with gettimeofday(), which provides microsecond precision. This is critical for accurately enforcing time_to_die, time_to_eat, and time_to_sleep thresholds.

Instructions
Prerequisites
    • GCC / Clang compiler
    • make
    • POSIX-compatible OS (Linux or macOS)

Compilation
make

Launch the simulation
Usage:
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep
        [number_of_times_each_philosopher_must_eat]

Arguments:
    • number_of_philosophers — Number of philosophers (and forks)
    • time_to_die (ms) — Time before a philosopher dies if they haven't eaten
    • time_to_eat (ms) — Time it takes to eat
    • time_to_sleep (ms) — Time spent sleeping
    • [number_of_times_each_philosopher_must_eat] (optional) — Simulation ends when all reach this count

Examples
# 5 philosophers, must not die
./philo 5 800 200 200
 
# 5 philosophers, each must eat at least 7 times
./philo 5 800 200 200 7
 
# 1 philosopher — must die (only 1 fork)
./philo 1 800 200 200

Expected output
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
200 2 has taken a fork
...
800 3 died

Stop the simulation
The simulation ends automatically when:
    • A philosopher dies
    • All philosophers have eaten the required number of times (if specified)
You can also stop it manually with Ctrl+C.

Resources
Documentation
    • POSIX Threads (pthreads) — man7.org
    • Dining Philosophers Problem — Wikipedia
    • pthread_mutex — man7.org
    • 42 Philosophers Guide — harm-smits.github.io

Use of AI
Artificial Intelligence tools were used to:
    • Understand thread synchronization concepts
    • Clarify the differences between mutexes and semaphores
    • Review the logic of deadlock prevention strategies
    • Improve documentation clarity

AI was not used to generate the project automatically. All C source files, the Makefile, and the synchronization logic were implemented, tested, and debugged manually.
