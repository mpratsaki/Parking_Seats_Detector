# Parking Space Control in ARM Assembly

## Overview

This project implements a parking space control system using **ARM Assembly**, developed in **Keil** for the **Cortex-M0+** microcontroller. The system simulates a microcontroller managing parking spaces by detecting incoming cars and controlling a barrier based on availability.

## Features

- **Car Detection**: A simulated weight sensor detects vehicles.
- **Parking Space Check**: The system monitors available parking spaces.
- **Barrier Control**: The entrance barrier opens if parking is available.
- **LED Notification**: An LED indicator signals a full parking lot.
- **Paper Ticket System**: A ticket with an entry number is issued upon entry.

## Implementation Details

- **Development Environment**:  
  - Keil µVision  
  - ARM Cortex-M0+  

- **Sensors Used**:
  - `weightSensor`: Detects an incoming car.
  - `parkingSpots`: Tracks available spaces.
  - `motorControl`: Controls the entrance barrier.
  - `ledState`: Manages the LED indicator.

### Logic Flow

1. **Car arrives & spots available**:
   - Barrier opens.
   - Parking space count decrements.
   - Ticket issued to the driver.
   - Barrier closes after entry.

2. **Car arrives & no spots available**:
   - LED indicator turns on.
   - "Parking Full" message displayed.

3. **No car detected**:
   - No action taken, system remains idle.
