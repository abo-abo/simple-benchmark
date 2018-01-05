import time
start_time = 0

def tic():
    global start_time
    start_time = time.time()

def toc():
    end = time.time()
    print("%dms" % int((end - start_time)*1000))

def main():
    a = list(range(int(1e7)))
    b = list(range(int(1e7)))
    tic()
    c = b + a
    toc()
    tic()
    s = sum(c)
    toc()
    print("sum:", s)

print("Python:")
main()
