# Analog Circuit Weighing Scale Using Load Cell

This project implements a weighing scale using a load cell, analog signal conditioning circuitry, and a microcontroller for data acquisition and display. The project includes a custom-designed PCB and a 3D-printed enclosure.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [Software](#software)
- [PCB Design](#pcb-design)
- [Enclosure](#enclosure)
- [Circuit Description](#circuit-description)
- [Usage](#usage)
- [Installation](#installation)
- [License](#license)

## Overview

This project is designed to measure weight using a load cell sensor. The output of the load cell is amplified using an instrumentation amplifier and fed into an ADC (Analog-to-Digital Converter) of a microcontroller for further processing. The measured weight is displayed on a digital display or transmitted for further processing.

## Features

- High-precision weight measurement using a load cell.
- Analog signal conditioning and amplification.
- Custom PCB design for the entire circuitry.
- Compact and durable enclosure.
- Real-time weight display on an LCD or OLED display.
- Optional data logging via UART or wireless communication.
  
## Hardware Components

- **Load Cell**: Converts force into an electrical signal.
- **HX711 Amplifier**: A 24-bit ADC amplifier module designed for load cells.
- **Microcontroller**: For reading the data from the load cell and controlling the display.
- **Custom PCB**: Houses the signal conditioning and microcontroller circuitry.
- **Power Supply**: 5V DC supply.
- **Display**: OLED or LCD for displaying the weight.
- **Enclosure**: 3D-printed to house the electronics and load cell securely.

## Software

The microcontroller reads the amplified signal from the load cell using the ADC, processes the data, and displays the weight on an LCD or OLED. The software is written in C++ and can be uploaded to the microcontroller (such as Arduino, ESP32, STM32, etc.).

The main software functionalities are:
- Reading data from the load cell.
- Calibrating the scale.
- Displaying the weight on the screen.

## PCB Design

The custom PCB design includes:
- **Analog Signal Conditioning**: Amplifies and filters the small signal from the load cell.
- **Microcontroller Interface**: Reads the processed signal and displays the weight.
- **Power Management**: Includes power regulation for stable operation.

The PCB was designed using [Altium](https://www.altium.com/) and can be found in the `PCB` folder of this repository.

## Enclosure

The enclosure is designed using [Fusion 360](https://www.autodesk.com/products/fusion-360/overview) and 3D-printed using PLA filament. It provides a sturdy housing for the load cell and electronics, with cutouts for the display and buttons. You can find the design files in the `Enclosure` folder.

## Circuit Description

1. **Load Cell**: The primary sensor that converts the applied weight into a voltage signal.
2. **Amplifier (HX711)**: Amplifies the low signal from the load cell for the microcontroller's ADC.
3. **Microcontroller**: Reads the amplified signal and converts it into a weight reading.
4. **Power Regulation**: Ensures a stable 5V power supply to the circuitry.
5. **Display**: Shows the calculated weight.

## Usage

### Calibration

1. Place a known weight on the scale.
2. Use the calibration function in the software to adjust the readings.
3. Store the calibration factor for future measurements.

### Weighing

1. Power on the device.
2. Place the object on the load cell platform.
3. The weight will be displayed on the screen.

### Data Logging (Optional)

You can modify the code to log the weight data through UART, Bluetooth, or Wi-Fi.

## Installation

1. **Hardware Setup**: 
    - Connect the load cell to the HX711 module.
    - Wire the HX711 to the microcontroller.
    - Attach the display to the microcontroller.
    - Mount everything on the custom PCB.

2. **Software**:
    - Install [Arduino IDE](https://www.arduino.cc/en/software) (if using Arduino/ESP32).
    - Upload the code from the `Software` folder to the microcontroller.

3. **Calibration**:
    - Run the calibration script and follow the on-screen instructions.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

