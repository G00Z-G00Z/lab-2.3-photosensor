# Read serial data with python

This program reads the data from your serial ports, in this case arduino, and
generates a csv file with the data of a sensor

## Python installed

1. Make an enviroment and install the requirements using the following commands:

```bash
python3 -m venv arduino-serial-enviroment
source arduino-serial-enviroment/bin/activate
pip3 --disable-pip-version-check --no-cache-dir install -r requirements.txt
```

2. Run the files using python.
3. When finished, just run "deactivate" to get out of the enviroment.

## Docker

With docker, you can just run the dameon with some special indication

todo: put the indications

# How to run the program

You must detect the port in wich the arduino is found, and then run the program:

For detecting the ports use:

```
python -m serial.tools.list_ports -v
```

Then, put the name of the port in a arduino.port.txt file

Then run the main program
