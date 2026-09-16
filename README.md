# Packet Queue and Congestion Simulator

## What is it 

- The purpose of the C++ simulator project is to explore and visualise how in real life, data packets can move through the network and pile up in queues as well as exploring consequences such as delay in response/network traffic or data losses when the traffic exceeds the maximum capacity.

## How does it work

- First of all, in the project, the user configures and sets 6 information: buffer capacity, service capacity, maximum packet arrivals per tick, simulation duration, congestion threshold and output preference.

- Once the user does that, basically a random number of packets arrive and if there's a buffer space available then for a certain amount of space, some packets are accepted into the buffer while the remaining gets left behind.

- According to the configured service capacity, that's where the router starts transmitting packets accordingly.

- The remaining queue occupancy gets recorded and the simulator checks whether the queue has reached the congestion threshold or not.

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
'''text
 
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

## Building and Running the program

