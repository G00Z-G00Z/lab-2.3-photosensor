from utils import file_exists, exit_error
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures


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

    # Regresion 
    polyModel = PolynomialFeatures(degree = 2, include_bias=False)
    poly_features_train = polyModel.fit_transform(voltage)
    poly_model = LinearRegression()
    poly_model.fit(poly_features_train, distance)

    distance_predicts = poly_model.predict(poly_features_train)  
    R2 = poly_model.score(poly_features_train, distance)
    print(f"R2 = {R2}")
    coeffs = poly_model.coef_
    print(f"Coeefs = {coeffs}")
    print(f"inter = {poly_model.intercept_}")
    plt.plot(voltage, distance_predicts)
    plt.savefig("figura.png")
     


    
    
    



        

if __name__ == '__main__':
   main()
    