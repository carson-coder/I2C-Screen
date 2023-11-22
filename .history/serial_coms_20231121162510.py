import serial

ser = serial.Serial('COM3')  # open serial port
print(ser.name)         # check which port was really used

text = ""
while text.lower() != "exit":
    text = input().replace("\\n", "\n")
    ser.write(text)

ser.close()             # close port