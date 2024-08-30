import socket

data = ""

HOST = input("ESP8266 Ip (Shown on screen): ")
PORT = 80

with open("data.csv", "r") as f:
    data = f.read().replace(","," - ")
    "".join(data.split("\n")[1:])

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall((data + "\0").encode("utf-8"))
    while True: pass