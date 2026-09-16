# Packet Queue and Congestion Simulator

## What is it?

The purpose of this C++ simulator is to explore and visualise how data packets move through a finite network buffer and how queues can build up when packet traffic increases.

The simulator demonstrates concepts such as packet queuing, packet loss and congestion when incoming traffic exceeds the available buffer and service capacity.

## How does it work?

- First, the user configures six simulation settings: buffer capacity, service capacity, maximum packet arrivals per tick, simulation duration, congestion threshold and detailed output preference.

- During each simulation tick, a random number of packets arrives between 0 and the maximum arrival value configured by the user.

- The simulator checks how much space is available in the buffer. Packets are accepted while space is available, while packets that cannot fit are dropped.

- The router then transmits packets according to the configured service capacity.

- Any packets that are not transmitted remain in the queue and are carried over to the next simulation tick.

- The simulator records the queue occupancy and checks whether the configured congestion threshold has been reached.

- After all simulation ticks have completed, the program displays the final packet statistics and calculated metrics.
  
## Example run

Example configuration:

```text
Buffer capacity: 100
Service capacity: 20
Maximum arrivals per tick: 50
Simulation duration: 5
Congestion threshold: 75
Detailed output: y

--- Simulation Tick 1 ---
Arrivals: 34
Accepted: 34
Dropped: 0
Transmitted: 20
Queue remaining: 14

--- Simulation Tick 2 ---
Arrivals: 47
Accepted: 47
Dropped: 0
Transmitted: 20
Queue remaining: 41

--- Simulation Tick 3 ---
Arrivals: 50
Accepted: 50
Dropped: 0
Transmitted: 20
Queue remaining: 71

--- Simulation Tick 4 ---
Arrivals: 42
Accepted: 29
Dropped: 13
Transmitted: 20
Queue remaining: 80

--- Simulation Tick 5 ---
Arrivals: 18
Accepted: 18
Dropped: 0
Transmitted: 20
Queue remaining: 78

--- Final Simulation Results ---
Total generated: 191
Total accepted: 178
Total dropped: 13
Total transmitted: 100
Packets remaining: 78
Maximum queue: 80
Congested ticks: 2
Average queue: 56.8
Drop percentage: 6.81%
Congestion percentage: 40%
Average occupancy percentage: 56.8%

Here the packet arrivals are randomly generated so as a result, the result can vary
```
## Features

- Configurable buffer capacity
- Configurable service capacity per simulation tick
- Random packet arrivals up to a user-defined maximum
- Packet acceptance and dropping when the buffer is full
- Persistent queue state across multiple simulation ticks
- Congestion detection using a user-defined threshold
- Tracking of total generated, accepted, dropped, and transmitted packets
- Maximum queue occupancy tracking
- Average queue occupancy calculation
- Drop percentage calculation
- Congestion percentage calculation
- Average buffer occupancy percentage calculation
- Optional detailed tick-by-tick output
- Final simulation summary
- Option to run another simulation without restarting the program
- Input validation with limited retry attempts
- Assertion-based tests for constants, inputs, simulation logic, and metrics

## Project Structure

```text
Packet-Queue-And-Congestion-Simulator/
│
├── src/
│   ├── main.cpp
│   ├── constants.h
│   │
│   ├── bufferCapacityInput.h
│   ├── bufferCapacityInput.cpp
│   ├── serviceCapacityInput.h
│   ├── serviceCapacityInput.cpp
│   ├── arrivalCapacityInput.h
│   ├── arrivalCapacityInput.cpp
│   ├── simulationDurationInput.h
│   ├── simulationDurationInput.cpp
│   ├── congestionThresholdInput.h
│   ├── congestionThresholdInput.cpp
│   ├── detailedOutputChoose.h
│   ├── detailedOutputChoose.cpp
│   │
│   ├── simulation.h
│   ├── simulation.cpp
│   ├── metrics.h
│   ├── metrics.cpp
│   ├── display.h
│   ├── display.cpp
│   ├── simulateAgain.h
│   └── simulateAgain.cpp
│
├── tests/
│   ├── test_constants.cpp
│   ├── test_inputs.cpp
│   ├── test_simulation.cpp
│   └── test_metrics.cpp
│
└── README.md
```

## Building and Running the program

1. Make sure you have a C++17-compatible compiler installed, such as `g++`.

2. Open a terminal in the project folder.

3. Compile the program:

```bash
g++ -std=c++17 src/*.cpp -o packet_simulator
```
4. Run the program:

For Linux/macOS:

```bash
./packet_simulator
```
5. Follow the prompts to enter the simulation settings.

## How to Run the Tests

The project contains separate tests for the constants, simulation logic, metrics, and user input.

Open a terminal in the main project folder before running the commands below.

### Constants Test

This test checks that the minimum and maximum values used by the simulator are set correctly.

Compile:

```bash
g++ -std=c++17 tests/test_constants.cpp -o test_constants
```

Run:

```bash
./test_constants
```

### Simulation Test

This test checks the main packet queue rules, including packet acceptance, packet dropping, transmission, buffer capacity, and congestion behaviour.

Compile:

```bash
g++ -std=c++17 tests/test_simulation.cpp -o test_simulation
```

Run:

```bash
./test_simulation
```

### Metrics Test

This test checks the calculations used for the drop percentage, congestion percentage, and average buffer occupancy percentage.

Compile:

```bash
g++ -std=c++17 tests/test_metrics.cpp src/metrics.cpp -o test_metrics
```

Run:

```bash
./test_metrics
```

### Input Test

This test checks the different input functions used to collect and validate the simulation settings.

Compile:

```bash
g++ -std=c++17 tests/test_inputs.cpp src/bufferCapacityInput.cpp src/serviceCapacityInput.cpp src/arrivalCapacityInput.cpp src/simulationDurationInput.cpp src/congestionThresholdInput.cpp src/detailedOutputChoose.cpp -o test_inputs
```

Run:

```bash
./test_inputs
```

The input test is interactive, so values need to be entered while the test is running.

If all assertions pass, the tests will complete successfully.

## Time taken to complete the project

9-10 hours approximately 
