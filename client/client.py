import socket
 
if __name__ == '__main__':
    client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)
    client_socket.connect(('127.0.0.1',9999))
    msg=client_socket.recv(1024).decode('utf-8')
    print("message from server: %s"%msg)
    while True:
        msg=input("enter message to server:")
        client_socket.send(msg.encode())
        msg=client_socket.recv(1024)
        if not msg:
            print("connection is disable")
            break
        print("server message:%s"%msg.decode('utf-8'))
    client_socket.close()
    