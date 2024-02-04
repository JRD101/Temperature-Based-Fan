# Temperature-Based-Fan

// Download the DHT22 library on the Arduino IDE
// Open the .ino file in the folder and upload it to 
the ESP32
--------------------------------------------------------

Components:
--------------------------------------------------------
L298N Motor Driver
5v Relay
Esp32
Temp & Humid Sensor
Bluetooth Module
Fan x2
---------------------------------------------------------
L298N Motor Driver -------- Esp32

12v----------------
GND----------------GND
5v-----------------5v

EnA----------------G19
In1----------------G18
In2----------------G5
EnB----------------G4
In3----------------G17
In4----------------G16
----------------------------------------------------------
DHt22 Sensor -------------- Esp32
+    --------------5v
Out  --------------G2   // remove the pin when uploading 
-    --------------GND
----------------------------------------------------------
