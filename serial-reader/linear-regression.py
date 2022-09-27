from utils import file_exists, exit_error
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression


SENSOR_DATA_FILENAME = "sensor_data.csv"

def main():
    if (not file_exists(SENSOR_DATA_FILENAME)):
       print(f"{SENSOR_DATA_FILENAME} doesnt exit")
       exit_error()
       
    sensor_table = pd.read_csv(SENSOR_DATA_FILENAME)
    
    plt.figure(1)
    sensor_table.plot( x="voltage", y="distance",grid=True, title="distance vs voltage")
    
    distance = sensor_table.loc[:, "distance"] .to_numpy().reshape(-1,1)
    voltage = sensor_table.loc[:, "voltage"] .to_numpy().reshape(-1,1)

    linear_model = LinearRegression()
    linear_model.fit(voltage, distance)

    distance_predicts = linear_model.predict(voltage)  
    R2 = linear_model.score(distance, distance_predicts)
    print(f"R2 = {R2}")
    coeffs = linear_model.coef_
    print(f"Coeefs = {coeffs}")
    print(f"inter = {linear_model.intercept_}")
    plt.plot(voltage, distance_predicts)
    plt.savefig("figura.png")
     


    
    
    



        

if __name__ == '__main__':
   main()
    