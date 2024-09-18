# Weighing Scale with Load Cell and Instrumentation Amplifier

This project is a high-precision weighing scale using a load cell sensor, a custom analog circuit employing an instrumentation amplifier with ADA4062-2BRZ op-amps, and a microcontroller for data acquisition and display. The system also includes a custom-designed PCB and a linear power supply for noise-free operation.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [Circuit Description](#circuit-description)
- [Power Supply Design](#power-supply-design)
- [Microcontroller and ADC](#microcontroller-and-adc)
- [PCB Design](#pcb-design)
- [Enclosure](#enclosure)
- [Usage](#usage)

## Overview

This weighing scale project integrates a load cell, signal conditioning circuit using ADA4062-2BRZ op-amps, and a microcontroller (ESP32 WROOM 32E) for high-accuracy weight measurement. The project features a linear power supply and custom PCB. The system also utilizes a 16-bit ADS1115 ADC for precise analog-to-digital conversion.
![Overview](https://github.com/user-attachments/assets/d698b48f-1f75-4c4d-b3cb-948ee52c0d75)

## Features

- High-precision weight measurement using a load cell.
- ADA4062-2BRZ-based instrumentation amplifier for high gain and low noise.
- Integrated voltage adder for offset correction.
- Linear power supply for stable +12V and -12V, minimizing noise.
- Digital weight display using a 16x2 LCD.
- Custom PCB design for the analog circuitry and power management.
- 3D-printed enclosure for housing the electronics.

## Hardware Components

- **Load Cell**: Measures the weight.
- **ADA4062-2BRZ Instrumentation Amplifier**: Amplifies the differential signal from the load cell with a gain of 401.
- **ADS1115 16-bit ADC**: High-precision analog-to-digital conversion.
- **ESP32 WROOM 32E**: Microcontroller for data processing and display control.
- **Custom PCB**: Contains the amplifier circuit and power management.
- **Linear Power Supply PCB**: Provides +12V, -12V, and +5V DC.
- **16x2 LCD Display**: For displaying the measured weight.

## Circuit Description

### Instrumentation Amplifier

The heart of this project is an instrumentation amplifier based on three ADA4062-2BRZ operational amplifiers configured to achieve a gain of 401. Key features of the amplifier include:
- **High Input Impedance**: Prevents current draw from the load cell, preserving accuracy.
- **Differential Input**: Amplifies only the voltage difference, rejecting common-mode noise.
- **Low Drift and Noise**: Ensures precision even with small load cell signals and environmental variations.
- **Offset Correction**: A voltage adder circuit corrects any offset voltage for improved accuracy.
![Instrumentatin_amp](https://github.com/user-attachments/assets/9eac9449-94fa-45c8-ad5c-d5521a85c1b7)

### Why an Instrumentation Amplifier?

1. **High Input Impedance**: Ensures minimal loading on the load cell, preserving measurement accuracy.
2. **Noise Rejection**: Differential input cancels out noise common to both input terminals.
3. **Precision**: Low drift and low offset ensure stable readings under varying environmental conditions.

## Power Supply Design

The weighing scale is powered by a dual supply (+12V and -12V), designed using a center-tapped transformer:
- **AC Conversion**: A 15V AC supply is generated using a step-down transformer.
- **Rectification**: A full-bridge rectifier converts the AC supply to DC, and a 1000uF capacitor smooths the output.
- **Voltage Regulation**: +12V is regulated using an L7812 IC, and -12V is regulated using an L7912 IC.
- **Additional 5V Output**: A +5V regulated output is provided using an L7805 IC for the microcontroller and peripherals.
- **Noise Filtering**: 10uF/25V and 0.1uF capacitors are used to filter ripples and high-frequency noise.

## Microcontroller and ADC

The digital aspect of the system is handled by:
- **ESP32 WROOM 32E Module**: Reads the output from the ADC and controls the display.
- **ADS1115 ADC**: Converts the amplified load cell output into a digital signal for the ESP32. The high-resolution 16-bit ADC ensures precise weight measurements.
- **Display**: A 16x2 LCD is used to show the real-time weight.

### Software

1. Install the required libraries for ESP32 and ADS1115.
2. Upload the code to the ESP32 WROOM 32E.

## PCB Design

The custom PCB integrates:
- The instrumentation amplifier circuit.
- Power management system (linear regulators and filtering components).
- Connections for the microcontroller, ADC, load cell, and display.
- Design files and schematics can be found in the `PCB` folder.

### Power supply schematic
![Powersupply](https://github.com/user-attachments/assets/b88f1e6c-8fe4-4010-84fc-17b506153d99)

### Amplifier schematic
![Amplifier](https://github.com/user-attachments/assets/41c8d8d0-486a-4b6f-8ce2-c2d31a5eb8cf)

### MCU schematic
![MCU](https://github.com/user-attachments/assets/55a7ada3-b12c-425a-a6f7-0a18aae2b186)

## Enclosure

A custom 3D-printed enclosure houses the entire system, providing protection and ease of use. The enclosure design files can be found in the `Enclosure_solidworks` folder.

![Enclosure1](https://github.com/user-attachments/assets/39b95471-ac18-46af-a85f-018c489dc6d8)

### Prototype
![Prototype](https://github.com/user-attachments/assets/207119bc-76a1-4a57-96be-38e1c85803c5)


## Usage

### Calibration

1. Connect the load cell to the PCB.
2. Place a known weight on the load cell platform.
3. Use the calibration script provided to set the zero offset and calibration factor.

### Weighing

1. Power on the system.
2. Place an object on the load cell.
3. The weight will be displayed on the LCD screen in real time.


