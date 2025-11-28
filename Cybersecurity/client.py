from tls import create_secure_client, analyze_connection_security

def main():
    # Connect to the TLS server
    client_socket = create_secure_client("localhost", 8443, "ca.crt")

    # Receive server message FIRST (before analysis)
    # This avoids race conditions where server closes early.
    try:
        data = client_socket.recv(1024)
        if data:
            print("Server response:", data.decode())
        else:
            print("Server closed the connection cleanly.")
    except ConnectionResetError:
        print("Server closed the connection before client finished reading.")
    except Exception as e:
        print("Read error:", e)

    # Now safely analyze the connection
    security_info = analyze_connection_security(client_socket)
    print("Connection Security:", security_info)

    # Clean close
    try:
        client_socket.shutdown(2)   # SHUT_RDWR
    except Exception:
        pass

    client_socket.close()


if __name__ == "__main__":
    main()