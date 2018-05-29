if __name__ == "__main__":
    with open("bla.in", "r") as R, open("bbla.out", "w") as w:
        t = int(R.readline().strip())
        for _ in range(t):
            w.write("Case #%d: " % (_ + 1))
            n, r, o, y, g, b, v = map(int, R.readline().strip().split())
            if o != 0 or g != 0 or v != 0:
                w.write("ERROR\n")
                continue
            if r == 0:
                if y == b:
                    w.write("YB" * (n / 2) + "\n")
                else:
                    w.write("IMPOSSIBLE\n")
                continue
            if y == 0:
                if r == b:
                    w.write("RB" * (n / 2) + "\n")
                else:
                    w.write("IMPOSSIBLE\n")
                continue
            if b == 0:
                if r == y:
                    w.write("RY" * (n / 2) + "\n")
                else:
                    w.write("IMPOSSIBLE\n")
                continue
            if r == y == b:
                w.write("RYB" * (n / 3) + "\n")
                continue
            t = min(r, y, b)
            r -= t
            y -= t
            b -= t
            if r == y == 0:
                if b <= t:
                    w.write("BRBY" * b +"BRY" * (t - b) + "\n")
                else:
                    w.write("IMPOSSIBLE\n")
                continue
            if r == b == 0:
                if y <= t:
                    w.write("YRYB" * y + "YRB" * (t - y) + "\n")
                else:
                    w.write("IMPOSSIBLE\n")
                continue
            if y == b == 0:
                if r <= t:
                    w.write("RYRB" * r + "RYB" * (t - r) + "\n")
                else:
                    w.write("IMPOSSIBLE\n")
                continue
            if r == 0:
                if y < b:
                    if b - y <= t:
                        w.write("RBYB" * (b - y) + "RYB" * (t - b + y) + "YB" * y + "\n")
                    else:
                        w.write("IMPOSSIBLE\n")
                else:
                    if y - b <= t:
                        w.write("RYBY" * (y - b) + "RBY" * (t - y + b) + "BY" * b + "\n")
                    else:
                        w.write("IMPOSSIBLE\n")
                continue
            if y == 0:
                if r < b:
                    if b - r <= t:
                        w.write("YBRB" * (b - r) + "YRB" * (t - b + r) + "RB" * r + "\n")
                    else:
                        w.write("IMPOSSIBLE\n")
                else:
                    if r - b <= t:
                        w.write("YRBR" * (r - b) + "YBR" * (t - r + b) + "BR" * b + "\n")
                    else:
                        w.write("IMPOSSIBLE\n")
                continue
            if b == 0:
                if y < r:
                    if r - y <= t:
                        w.write("BRYR" * (r - y) + "BYR" * (t - r + y) + "YR" * y + "\n")
                    else:
                        w.write("IMPOSSIBLE\n")
                else:
                    if y - r <= t:
                        w.write("BYRY" * (y - r) + "BRY" * (t - y + r) + "RY" * r + "\n")
                    else:
                        w.write("IMPOSSIBLE\n")
                continue