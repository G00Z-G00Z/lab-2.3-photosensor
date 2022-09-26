import sys
import time
import serial

PORT_FILE_NAME = "arduino.port.txt"
BAUD_RATE = 9600


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
        ser =  serial.Serial(port_name, BAUD_RATE, timeout=0)
        time.sleep(2)
        for _ in range(100):
            byte_ = ser.readline()
            if not byte_:
                continue
            try: 
                string = byte_.decode()
                stripped = string.strip()
                print(string)
                print(stripped)

            except UnicodeDecodeError:
                print(f'Couldn decode {byte_}')
    except serial.SerialException:
        print("No se pudo leer el serial")
        print("Quiza no esta conectado a la compu")
        exit_error()
    finally:
        ser.close()
        

def main():
    port_name = get_port_name_from_text_file()
    print(f"Your selected port was {port_name}")
    read_port(port_name)
    pass

if __name__ == '__main__':
    main()



    











    