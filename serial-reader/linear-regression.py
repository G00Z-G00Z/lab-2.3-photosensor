from utils import file_exists, exit_error
import pandas as pd
import matplotlib.pyplot as plt


SENSOR_DATA_FILENAME = "sensor_data.csv"

def main():
    if (not file_exists(SENSOR_DATA_FILENAME)):
       print(f"{SENSOR_DATA_FILENAME} doesnt exit")
       exit_error()
       
    sensor_table = pd.read_csv(SENSOR_DATA_FILENAME)
    
    plt.figure(1)
    sensor_table.plot(x="distance", y="voltage")
    plt.savefig("figura.png")

    
    
    



        

if __name__ == '__main__':
   main()
    