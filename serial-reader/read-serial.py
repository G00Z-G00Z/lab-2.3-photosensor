import sys

PORT_FILE_NAME = "arduino.port.txt"


def exit_error():
    sys.exit(1)

def get_port_name_from_text_file():
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

        

def main():
    port_name = get_port_name_from_text_file()
    print(f"Your selected port was {port_name}")
    pass

if __name__ == '__main__':
    main()



    











    