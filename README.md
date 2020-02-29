# Data Processing and Database Project

### Introduction

Did you know that most of the time data needs to be prepared and/or modified prior to be released as a final product or presented to the user? The purpose of this project is to describe the steps required to obtain raw data from a source and convert the information into quality, presentable and understandable data available for Microsoft Excel, which will then get stored into a database. A digital thermometer (source) was compiled by wiring up an Arduino UNO R3 circuit board, a temperature sensor and a few electrical components with the purpose of recording room temperature data during several hours between two consecutive days. A python script was written afterwards; it's function is to interpret the thermometer's readings and then compiled the data into a plain text file. An Excel macro then takes care of importing and formatting the readings (text file) appropriately with the purpose of assuring that data will get stored into a SQL (relational) database without errors. Please note that there was no more than 2 day-worth of data since the goal of this project is to demonstrate how quality data was processed and stored, not to prove weather patterns.   

### What's included in this repository? (Click on the 'Data-Processing-and-Database-Project' folder)

(Points 5 and 6 represent writing sample and summary respectively)

1. A) ARDUINO-RAW_DATA_SOURCE (folder)
    * Arduino_Thermometer_Code_Sample.docx (Circuit's code in Word)
    * Thermometer.ino (Circuit's code)
2. B) PYTHON-DATA_TXT_CONVERTER (folder)
    * Arduino_Serial_Monitor_Txt_Converter.py (Python's script)
    * OUTPUT (folder)
          	1. Arduino_Temperature_Raw_Data.txt (Unprocessed readings)
    * Python_Arduino_Serial_Monitor_Txt_Converter_Code_Sample.docx (Python's script in Word)
3. C) EXCEL_MACRO-DATA_PROCESSOR (folder)
    * Arduino_Temperature_Processed_Data (with Macro).xlsm
    * Macro_Arduino_Raw_Data_Processing_Code_Sample.docx (Macro/VBA script written in Word)
    * OUTPUT (folder)
         	1. Arduino_Temperature_Processed_Data (Disabled Macro).xlsx (Excel file ready to get loaded in database)
4. D) POSTGRESQL-RECORDED_TEMPERATURE_DB (folder)
    * FILES_TO_LOAD_(CSV_ONLY) (folder)
    		1. Arduino_Temperature_Processed_Data.csv (comma delimited file)
    * RECORDED_ROOM_TEMPERATURE_(SQL_Table) Code_Sample.docx (SQL database script in Word)
    * RECORDED_ROOM_TEMPERATURE.sql
5. Data Processing and Database Project.docx (WRITING SAMPLE / TECHNICAL PAPER)
6. Data Processing and Database Project.pptx (SUMMARY)

### Technologies

1. C/C++ compiler (informally known as ‘Arduino language’) along with both Arduino circuit board and open-source Integrated Development Environment (IDE)
2. Python 3.6 via PyCharm CE open-source IDE
3. MacBook Pro – macOS Sierra Version 10.12.6
4. Microsoft Office:
	* Microsoft Excel
        	1. Microsoft Excel Macro and VBA Editor
	* Microsoft PowerPoint
	* Microsoft Word
5. PostgreSQL via open-source pgAdmin3
