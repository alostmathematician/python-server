
from server.server import Server,MAX_CONNECTION,threading

server=Server('127.0.0.1',9999)
for _ in range(MAX_CONNECTION):
    t=threading.Thread(target=server.start)
    t.daemon=True
    t.start()
server.start()