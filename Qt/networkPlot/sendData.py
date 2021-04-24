import socket
import json
from random import randint
import time

def send_data(conn):
	x = [1,2,3,4,5]
	y = [1,2,3,4,5]
	data = json.dumps([{"X":x,"Y":y}])
	conn.send(data.encode())

def send_data_stream(conn):
	print("Sending Stream")
	x = [1,2,3,4,5]
	y = []
	for _ in range(5):
		y.append(randint(0, 30)*5.9878)
	data = json.dumps([{"X":x,"Y":y}])
	print(data.encode())
	conn.send(data.encode())
	print("Sent")

TCP_IP = '192.168.56.1'
TCP_PORT = 65040
BUFFER_SIZE = 1024
MESSAGE = "Hello, World!"
# s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s = socket.socket()			 # Create a socket object

s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((TCP_IP, TCP_PORT))			# Bind to the port
s.listen(5)					 # Now wait for client connection.


print ('Server listening....')

while True:
	conn, addr = s.accept()	 # Establish connection with client.
	print ('Got connection from', addr)
	while True:
		
		data = conn.recv(1024)
		# print('Server received', repr(data))
		dataJson = json.loads(data.decode('utf-8'))
		print(dataJson)
		if dataJson[0]["Send_Data"]==1:
			send_data(conn)
		elif dataJson[0]["Send_Data"]==2:
			while True:
				
				send_data_stream(conn)
				time.sleep(1)
		elif dataJson[0]["Send_Data"]==0:
			conn.close()
			break
	conn.close()
		