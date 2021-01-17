# LSG-4Scales-calibration

LSG-4Scales-calibration is an Arduino sketch to calibrate your [LSG-4Scales](https://github.com/FrancoMaxime/lsg-4scales).

## Installation

- Use the library manager [Arduino](https://www.arduino.cc/en/software) to install [HX711](https://github.com/bogde/HX711)
- Use the Boards manager [Arduino](https://www.arduino.cc/en/software) to install Atmel AVR Xplained-minis

## Hardware support
- [ATmega328](https://en.wikipedia.org/wiki/ATmega328): Arduino Uno

## Usage

- 9 key: Taring the LSG-4Scales.
- 0 key: print the actual calibration factor for each load cell.

- a key: increase the calibration factor by 10 for the first load cell.
- z key: increase the calibration factor by 1 for the first load cell.
- e key: decrease the calibration factor by 1 for the first load cell.
- r key: decrease the calibration factor by 10 for the first load cell.

- q key: increase the calibration factor by 10 for the second load cell.
- s key: increase the calibration factor by 1 for the second load cell.
- d key: decrease the calibration factor by 1 for the second load cell.
- f key: decrease the calibration factor by 10 for the second load cell.

- w key: increase the calibration factor by 10 for the third load cell.
- x key: increase the calibration factor by 1 for the third load cell.
- c key: decrease the calibration factor by 1 for the third load cell.
- v key: decrease the calibration factor by 10 for the third load cell.

- a key: increase the calibration factor by 10 for the fourth load cell.
- z key: increase the calibration factor by 1 for the fourth load cell.
- e key: decrease the calibration factor by 1 for the fourth load cell.
- r key: decrease the calibration factor by 10 for the fourth load cell.


## Documentation 
[See DOC.md](https://github.com/FrancoMaxime/lsg-4scales-calibration/blob/main/doc/DOC.md)

## Calibrate the [LSG-4Scales](https://github.com/FrancoMaxime/lsg-4scales)
To calibrate a LSG-4Scales, you should calibrate the load cells one by one to avoid bias.
Use a reference mass, deposited on the load cell.
By increasing or decreasing the calibration factor, try match the value of the load cell with the known mass.  

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
