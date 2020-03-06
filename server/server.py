import socketserver
import socket
import threading
from log import Logger

MAX_CONNECTION=5
WELCOME_MSG="welcome board !!! Waiting for command..."
IDENT_MSG="Please enter username and password to connect!!!"
FAIL_MESSAGE="Failed to provide verification.Please try again"
class Server:
    def __init__(self,ip,port):
        if not isinstance(ip,str):
            raise TypeError("ip address must be string")
        if not isinstance(port,int):
            raise TypeError("port number must be integers")
        self._socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)
        self._socket.bind((ip,port))
        self._socket.listen(MAX_CONNECTION)
        self._logger=Logger("server log",file_log=False)
    def start(self):
        while True:
            conn_socket,client_addr=self._socket.accept()
            client_ip,client_port=client_addr
            self._logger.info("client %s:%s is connected,waiting for verification"%(str(client_ip),str(client_port)))
            msg=IDENT_MSG
            conn_socket.sendall(msg.encode())
            if self.login(conn_socket):
                self._serve(conn_socket,client_addr)
            else:
                self._retry(conn_socket,client_addr)
    def _serve(self,conn_socket,client_addr):
        self._logger.info("client %s:%s logged in"%(str(client_addr[0]),str(client_addr[1])))
        msg=WELCOME_MSG
        conn_socket.sendall(msg.encode())
        while True:
            msg=conn_socket.recv(1024).decode('utf-8')
            if not msg:
                self._logger.warning("The connection with client %s:%s may be disabled."%(str(client_addr[0]),str(client_addr[1])))
                break
            if msg=="check connection":
                msg="message received"
                conn_socket.sendall(msg.encode())
        conn_socket.close()
    def _retry(self,conn_socket,client_addr):
        self._logger.warning("client %s:%s has failed to logged in"%(str(client_addr[0]),str(client_addr[1])))
        msg=FAIL_MESSAGE
        conn_socket.sendall(msg.encode())
    @staticmethod
    def login(conn_socket):
        user_name="username:"
        conn_socket.sendall(user_name.encode())
        user_name=conn_socket.recv(1024).decode('utf-8')
        password="password:"
        conn_socket.sendall(password.encode())
        password=conn_socket.recv(1024).decode('utf-8')
        if user_name=='qin' and password=='87438366':
            return True
        else:
            return False




class Handler(socketserver.BaseRequestHandler):
    def handle(self):
        print("connected from ",self.client_address)
        msg="welcome board"
        self.request.sendall(msg.encode())
        while True:
            msg=self.request.recv(1024)
            if not msg:
                print("disconnected from ",self.client_address)
                break
            print("message from ",self.client_address,":",msg.decode('utf-8'))
            msg=input("message to:")
            self.request.sendall(msg.encode())
        
if __name__ == '__main__':
    # server=socketserver.TCPServer(('127.0.0.1',9999),Handler)
    # for _ in range(5):
    #     t=threading.Thread(target=server.serve_forever)
    #     t.daemon=True
    #     t.start()
    # server.serve_forever()
    server=Server('127.0.0.1',9999)
    for _ in range(MAX_CONNECTION):
        t=threading.Thread(target=server.start)
        t.daemon=True
        t.start()
    server.start()