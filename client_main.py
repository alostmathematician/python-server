from client.client import TcpClient

if __name__ == '__main__':
    client=TcpClient('127.0.0.1',9999)
    client.ask()
    