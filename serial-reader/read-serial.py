import sys
import time
import serial

PORT_FILE_NAME = "arduino.port.txt"
BAUD_RATE = 9600
SAMPLES_NO = 31


def exit_error():
    sys.exit(1)

def get_port_name_from_text_file() -> None:
    """
    Gets the port name from the file
    """

    try:
        with open(PORT_FILE_NAME, "r") as f:
            port = f.readline()
            
        return port
    
    except FileNotFoundError: 
        print(f"{PORT_FILE_NAME} was not found")
        print(f"Please make a file named {PORT_FILE_NAME} and put the port in which the arduino is connected")
        exit_error()

def read_port(port_name : str) -> None: 
    print("Ports")

    try:
        with serial.Serial(port_name, BAUD_RATE) as ser:
            time.sleep(2)
            for _ in range(SAMPLES_NO + 1):
                line = ser.readline()

                try: 
                    string = line.decode()
                    stripped = string.strip()
                    print(stripped)

                except UnicodeDecodeError:
                    print(f'Couldn decode {line}')

    except serial.SerialException:
        print("No se pudo leer el serial")
        print("Quiza no esta conectado a la compu")
        exit_error()
        

def main():
    port_name = get_port_name_from_text_file()
    print(f"Your selected port was {port_name}")
    read_port(port_name)
    pass

if __name__ == '__main__':
    main()



    











    