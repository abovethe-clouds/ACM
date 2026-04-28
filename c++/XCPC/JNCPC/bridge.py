import os
import subprocess
import sys
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
A_CPP = BASE_DIR / "A.cpp"
A_EXE = BASE_DIR / "A.exe"


def build_a_exe():
    cxx = os.environ.get("CXX", "g++")
    cmd = [cxx, str(A_CPP), "-O2", "-std=c++17", "-o", str(A_EXE)]
    print("[build]", " ".join(cmd))
    res = subprocess.run(cmd, cwd=str(BASE_DIR), text=True, capture_output=True)
    if res.returncode != 0:
        print("[build] compile failed", file=sys.stderr)
        if res.stdout:
            print(res.stdout, file=sys.stderr, end="" if res.stdout.endswith("\n") else "\n")
        if res.stderr:
            print(res.stderr, file=sys.stderr, end="" if res.stderr.endswith("\n") else "\n")
        sys.exit(res.returncode)


build_a_exe()

proc_A = subprocess.Popen(
    [str(A_EXE)],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True,
    cwd=str(BASE_DIR),
)

proc_checker = subprocess.Popen(
    [sys.executable, str(BASE_DIR / "checker.py")],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True,
    cwd=str(BASE_DIR),
)

while True:
    # A 先说话
    line = proc_A.stdout.readline()
    if not line:
        proc_A.poll()
        print(f"A.exe exited (code={proc_A.returncode})")
        break

    print("[A]", line.strip())

    # 转发给 checker
    proc_checker.stdin.write(line)
    proc_checker.stdin.flush()

    # checker 回答
    reply = proc_checker.stdout.readline()
    if not reply:
        proc_checker.poll()
        print(f"checker exited (code={proc_checker.returncode})")
        break

    print("[checker]", reply.strip())

    # 再喂回 A
    proc_A.stdin.write(reply)
    proc_A.stdin.flush()

    if line.startswith("!"):
        break

# 尝试优雅收尾，避免残留子进程
for p in (proc_A, proc_checker):
    if p.poll() is None:
        p.terminate()
