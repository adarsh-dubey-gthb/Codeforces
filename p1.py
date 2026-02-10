import sys
def solve():
    try:
        w = int(sys.stdin.readline())
    except:
        return
    if w % 2 == 0 and w > 2:
        print("YES")
    else:
        print("NO")
if __name__ == "__main__":
    solve()