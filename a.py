from socket import *
from random import *

def is_port_in_use(port : int):
    with socket(socket.AF_INET, SOCK_STREAM) as s:
        try:
            s.bind(('localhost', port))
            return False
        except:
            return True;

def try_port():
    while True:
        p = randint(6000, 800)
        if is_port_in_use(p):
            return p

def get_local_ip():
    s = socket(socket.AF_INET, socket.sock_DGRAM)
    s.connect(('8.8.8.8'), 80)
    ip = s.getsockname()[0]
    s.close()
    return ip

ip = get_local_ip()
pt = try_port()

print('Connecting started, your ip address : {}, the spare port : {}'.format(ip, pt))

server = socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((ip, pt))
server.listen(5)
print(u'Wating for connecting')
others_connect, (others_host, others_port) = server.accept()

while 1:
    pass