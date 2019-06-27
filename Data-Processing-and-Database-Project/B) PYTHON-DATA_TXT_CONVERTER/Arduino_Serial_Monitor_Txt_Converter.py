import serial #This module will establish a direct connection with the Arduino board
import time #We need this module to assign a timestamp to each data point (recorded temperature)
import re #This module will serve the function of identifying the few printed lines with errors (undesired results with commas)

ser = serial.Serial('/dev/tty.usbmodem1411',baudrate=9600,timeout=1) #Arguments within 'ser' match the circuit's info
ser.flushInput()

while True:
    try: #The 'try:' compiles how the raw data will be displayed
        ser_bytes = ser.readline() #ser_bytes reads the circuit sensor's data
        decoded_bytes_c = str(ser_bytes[0:5].decode("utf-8")) #This compiles temperature in Celsius
        decoded_bytes_f = str(ser_bytes[6:11].decode("utf-8")) #This compiles temperature in Fahrenheit
        date = str(time.strftime("%m/%d/%Y,%H:%M:%S")) #as ':try' goes over temperature lines recorded, each gets a timestamp assigned
        result = decoded_bytes_c + "," + decoded_bytes_f + "," + date + " " #results get separated by commas (which will serve as delimiter)
        if result == "," or result.startswith(",,"): #the temperature sensor rarely produces garbage data, this if-statement ignores those results
            pass
        else:
            print(result) #As data gets recorded and printed in PyCharm (Python/Anaconda platform) it gets stored in a text file too!
            f = open('Arduino_Temperature_Raw_Data.txt', 'a') #'f' creates/append data to a txt file in my Documents folder any time we run this code
            f.write(result)
            f.close()

    except: #Data will stop getting recorded if we unplug the device/thermometer or if stop the code
        print("Keyboard Interrupt")
        break
