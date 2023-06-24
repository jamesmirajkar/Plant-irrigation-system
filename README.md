# Plant Irrigation System Using ARM7TDMI

This project implements an automated plant irrigation system using the ARM7TDMI microcontroller. It aims to provide a solution for maintaining optimal moisture levels in a plant's soil and ensuring timely watering.

## Table of Contents
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [Code](#Code)

## Hardware Requirements
To replicate this project, you will need the following hardware components:
- ARM7TDMI microcontroller board
- Moisture sensor
- Water pump
- LCD display
- Buzzer
- LEDs
- Other necessary electronic components (resistors, capacitors, etc.)

Make sure to connect the hardware components properly according to the provided circuit diagram.

## Software Requirements
- Keil µVision IDE (or any other compatible IDE)
- ARM7TDMI microcontroller SDK
- Any required drivers or libraries for the microcontroller and peripherals

## Installation

1. Clone the repository.
2. Ensure that you have the required dependencies installed [e.g., Keil MDK, LPC214x library].
3. Build the project using your preferred compiler or integrated development environment.
4. Upload the compiled code to the LPC214x microcontroller.
5. Connect the necessary peripherals and devices [e.g., LCD display, ADC].
6. Power on the system and ensure all connections are correct.

## Usage

1. Power on the system.
2. The program will initialize and set up the peripherals and devices.
3. The LCD display will show relevant messages and information based on the ADC readings.
4. The system will continuously read ADC values and process them.
5. The external interrupt can be triggered to simulate filling the water tank.
6. Follow the LCD display instructions for any additional user interactions.

## Features

- Multitasking using the Keil RTX operating system.
- Reading ADC values and processing them in real-time.
- Displaying informative messages on an LCD screen.
- Handling an external interrupt for filling the water tank.

## Contributing

Contributions are welcome! If you would like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your changes to your forked repository.
5. Submit a pull request describing your changes.

## Code

```shell
   git clone https://github.com/your-username/plant-irrigation-arm7.git


