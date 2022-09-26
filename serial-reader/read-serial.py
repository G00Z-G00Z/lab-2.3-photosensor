import serial
import serial.tools.list_ports

SERIAL_PORT = "COM4"

def list_serial_ports():
    print(list(serial.tools.list_ports.comports()))
    


def main():
    
    list_serial_ports()

    # with serial.Serial(SERIAL_PORT, 9600, timeout=1) as ser:
        # line = ser.readline()
        # print(line)





if __name__ == '__main__':
    main()



    











    