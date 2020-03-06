import socket
from utils.log import Logger
from server.server import WELCOME_MSG,FAIL_MESSAGE

LOG_TYPE_CLIENT=False
SUCCESS_LOG="Login successfully"
FAIL_LOG="Failed to login,please try again"

class BaseClient:
    def __init__(self,ip,port):
        if not isinstance(ip,str):
            raise TypeError("ip address must be string")
        if not isinstance(port,int):
            raise TypeError("port number must be integers")
        self._socket=None
        self._logger=Logger("server log",file_log=LOG_TYPE_CLIENT)
    def ask(self):
        pass

    @staticmethod
    def login(client_socket):
        user_name=input("Please enter your user name:")
        client_socket.sendall(user_name.encode())
        password=input("please enter your password:")
        client_socket.sendall(password.encode())
        msg=client_socket.recv(1024).decode('utf-8')
        if msg==WELCOME_MSG:
            return True
        else:
            return False

class TcpClient(BaseClient):
    def __init__(self,ip,port):
        super().__init__(ip,port)
        self._socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)
        self._socket.connect((ip,port))
    def ask(self):
        msg=self._socket.recv(1024)
        print(msg.decode('utf-8'))
        if self.login(self._socket):
            self._logger.info(SUCCESS_LOG)
        else:
            self._logger.warning(FAIL_LOG)
        self._socket.close()