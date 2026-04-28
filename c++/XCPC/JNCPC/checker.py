import random
import sys

# ===== 常量 =====
LIMIT = 1 << 1023   # 允许最大值（包含）
MAX_STEP = 6666
VALID = {"a", "b", "c", "d", "r0", "r1", "r2", "r3"}

# ===== 初始化寄存器 =====
reg = {}

# ===== 构造极限斐波那契数据 =====

fib = [1, 1]

# 生成直到超过范围
while fib[-1] <= LIMIT:
    fib.append(fib[-1] + fib[-2])

# 找最大合法 i，使 fib[i+2] 仍在范围内
i = len(fib) - 3
while fib[i+2] > LIMIT:
    i -= 1

# 构造“最坏情况”数据
reg["a"] = random.randint(1,LIMIT-1)
reg["b"] = random.randint(1,LIMIT-1)
reg["c"] = random.randint(1,LIMIT-1)
reg["d"] = random.randint(1,LIMIT-1)

# 打印调试信息（stderr，不影响交互）


# 初始化寄存器
for name in ["r0", "r1", "r2", "r3"]:
    reg[name] = 0
step = 0

# ===== 工具函数 =====
def die(reason=None, step_no=None):
    # Keep protocol on stdout, send human-readable diagnostics to stderr.
    if reason:
        if step_no is None:
            step_no = step
        print(f"{reason}（第{step_no}步）", file=sys.stderr)
        sys.stderr.flush()
    print("err")
    sys.stdout.flush()
    sys.exit(0)

def _short_num(x, keep=24):
    s = str(x)
    if len(s) <= keep * 2 + 3:
        return s
    return f"{s[:keep]}...{s[-keep:]}"

def _num_meta(x):
    ax = abs(x)
    bits = ax.bit_length()
    digits = len(str(ax)) if ax != 0 else 1
    sign = "-" if x < 0 else "+"
    return sign, bits, digits

def dump_abcd_sizes(extra_name=None, extra_value=None):
    print("[overflow] 寄存器快照:", file=sys.stderr)
    for k in ["a", "b", "c", "d"]:
        v = reg[k]
        sign, bits, digits = _num_meta(v)
        print(
            f"  {k}: sign={sign}, bits={bits}, digits={digits}, val={_short_num(v)}",
            file=sys.stderr,
        )
    if extra_name is not None:
        sign, bits, digits = _num_meta(extra_value)
        print(
            f"  {extra_name}: sign={sign}, bits={bits}, digits={digits}, val={_short_num(extra_value)}",
            file=sys.stderr,
        )
    sys.stderr.flush()

def check_range(x):
    if x < -LIMIT or x > LIMIT:
        dump_abcd_sizes("overflow_value", x)
        die("数据溢出")
    return x

def trunc_div(x, y):
    if y == 0:
        die()
    return int(x / y)  # 向 0 取整

# ===== 开始 =====

while True:
    try:
        line = input()
    except EOFError:
        break

    line = line.strip()
    if not line:
        continue

    parts = line.split()
    op = parts[0]

    # ===== 步数统计（! 不算）=====
    if op != "!":
        global_step = step + 1
        if global_step > MAX_STEP:
            die("超出步数", step_no=global_step)
        step = global_step

    # ===== 算术操作 =====
    if op in ["+", "-", "*", "/"]:
        if len(parts) != 4:
            die()

        _, x, y, z = parts

        if x not in VALID or y not in VALID or z not in VALID:
            die()

        try:
            if op == "+":
                reg[x] = check_range(reg[y] + reg[z])
            elif op == "-":
                reg[x] = check_range(reg[y] - reg[z])
            elif op == "*":
                reg[x] = check_range(reg[y] * reg[z])
            elif op == "/":
                reg[x] = check_range(trunc_div(reg[y], reg[z]))
        except SystemExit:
            raise
        except Exception:
            die()

        print("ok")
        sys.stdout.flush()

    # ===== 比较操作 =====
    elif op == "?":
        if len(parts) != 3:
            die()

        _, x, y = parts

        if x not in VALID or y not in VALID:
            die()

        if reg[x] > reg[y]:
            print(">")
        elif reg[x] < reg[y]:
            print("<")
        else:
            print("=")

        sys.stdout.flush()

    # ===== 最终答案 =====
    elif op == "!":
        if len(parts) != 2:
            die()

        rel = parts[1]
        if rel not in [">", "<", "="]:
            die()

        lhs = reg["a"] * reg["d"]
        rhs = reg["c"] * reg["b"]

        if lhs > rhs:
            real = ">"
        elif lhs < rhs:
            real = "<"
        else:
            real = "="

        if rel == real:
            print("ok")
        else:
            print("err")

        sys.stdout.flush()
        break

    # ===== 非法指令 =====
    else:
        die()