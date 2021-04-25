import socket                   # Import socket module

s = socket.socket()             # Create a socket object
host = socket.gethostname()     # Get local machine name
port = 1234                   # Reserve a port for your service.

s.connect((host, port))
s.send("Hello server!".encode())

data = s.recv(1024)
print(data)

s.close()
print('Connection Closed')