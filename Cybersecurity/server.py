from tls import create_secure_server

server_socket = create_secure_server("localhost", 8443, "server.crt", "server.key")
print("Secure server started on port 8443")

while True:
    client_conn, addr = server_socket.accept()
    print(f"Secure connection from {addr}")
    client_conn.send(b"Hello client!")
    client_conn.close()