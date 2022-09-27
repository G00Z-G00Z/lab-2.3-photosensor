from utils import file_exists, exit_error


SENSOR_DATA_FILENAME = "sensor_data.csv"

def main():
    if (not file_exists(SENSOR_DATA_FILENAME)):
       print(f"{SENSOR_DATA_FILENAME} doesnt exit")
       exit_error()
        

if __name__ == '__main__':
   main()
    