import serial

ser = serial.Serial('COM3')  # open serial port
print(ser.name)         # check which port was really used

text = ""
while True:
    text = input().replace("\\n", "\n")
    if text == "exit": break
    text += "/"
    print(text)
    ser.write(text.encode("utf-8"))

ser.close()             # close port