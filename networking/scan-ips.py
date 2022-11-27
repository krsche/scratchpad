import http.client
from threading import Thread

def test(ip):
    conn = http.client.HTTPConnection(ip, timeout=2)
    try:
        conn.request("GET", "/")
    except Exception as e:
        print(ip, "timeout")
        return
    r = conn.getresponse()
    print(ip, r.status, r.reason)

threads = []
for i in range (0, 255):
    ip = f"192.168.2.{i+1}"
    threads.append(Thread(target=test, args=[ip]))
    threads[i].start()

for t in threads:
    t.join()
