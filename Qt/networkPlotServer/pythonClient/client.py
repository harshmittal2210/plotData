import socket                   # Import socket module
import json
from random import randint
import time

def send_data_stream(conn,n):
	# print("Sending Stream")
	x = list(range(0,n))
	y = []
	for _ in range(n):
		y.append(randint(0, 30)*5.9878)
	data = json.dumps([{"X":x,"Y":y}])
	print(data.encode())
	s.send(data.encode())
	# print("Sent")

s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
port = 1234                   # Reserve a port for your service.

s.connect((host, port))

while True:
	send_data_stream(s,10)
	time.sleep(1)
# s.send("Hello server!".encode())

# data = s.recv(1024)
# print(data)

s.close()
print('Connection Closed')