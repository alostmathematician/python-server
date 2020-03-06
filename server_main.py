
from server.server import TcpServer,MAX_CONNECTION,threading

if __name__ == '__main__':
    server=TcpServer('127.0.0.1',9999)
    for _ in range(MAX_CONNECTION):
        t=threading.Thread(target=server.start)
        t.daemon=True
        t.start()
    server.start()