import socket
import ssl
from typing import Optional, Tuple, Dict, Any


class SecureServerSocket:
    def __init__(self, sock: socket.socket, ssl_context: ssl.SSLContext):
        self._sock = sock
        self._context = ssl_context

    def accept(self) -> Tuple[ssl.SSLSocket, Tuple[str, int]]:
        raw_conn, addr = self._sock.accept()
        # Wrap the raw connection in an SSLSocket (perform TLS handshake here)
        ssl_conn = self._context.wrap_socket(raw_conn, server_side=True)
        return ssl_conn, addr

    def bind(self, addr):
        return self._sock.bind(addr)

    def listen(self, backlog=5):
        return self._sock.listen(backlog)

    def settimeout(self, t):
        return self._sock.settimeout(t)

    def getsockname(self):
        return self._sock.getsockname()

    def close(self):
        return self._sock.close()


def create_secure_server(host: str, port: int, certfile: str, keyfile: str) -> SecureServerSocket:
    # Create SSL context for server side
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    # Restrict to secure options
    context.options |= ssl.OP_NO_SSLv2 | ssl.OP_NO_SSLv3 | ssl.OP_NO_COMPRESSION
    context.load_cert_chain(certfile=certfile, keyfile=keyfile)

    # Create TCP listening socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind((host, port))
    sock.listen(5)

    return SecureServerSocket(sock, context)

def create_secure_client(host: str, port: int, ca_cert_file: Optional[str] = None) -> ssl.SSLSocket:
    # Create client context that verifies server certs
    context = ssl.create_default_context(ssl.Purpose.SERVER_AUTH)
    # Enforce strong TLS settings
    context.options |= ssl.OP_NO_SSLv2 | ssl.OP_NO_SSLv3 | ssl.OP_NO_COMPRESSION

    if ca_cert_file:
        # Use the provided CA bundle to validate the server certificate
        context.load_verify_locations(cafile=ca_cert_file)
    # Always require certificate validation
    context.verify_mode = ssl.CERT_REQUIRED

    # Create TCP connection
    raw_sock = socket.create_connection((host, port))
    ssl_sock = context.wrap_socket(raw_sock, server_hostname=host)

    return ssl_sock


def analyze_connection_security(ssl_socket: ssl.SSLSocket) -> Dict[str, Any]:
    protocol = ssl_socket.version()  
    cipher = ssl_socket.cipher()

    peer_cert = ssl_socket.getpeercert() 
    peer_subject = None
    if peer_cert:
        subject = peer_cert.get('subject', ())
        parts = []
        for rdn in subject:
            for name, value in rdn:
                parts.append(f"{name}={value}")
        peer_subject = ",".join(parts) if parts else None

    certificate_verified = bool(peer_cert)

    return {
        "protocol": protocol,
        "cipher": cipher,
        "peer_cert_subject": peer_subject,
        "certificate_verified": certificate_verified
    }