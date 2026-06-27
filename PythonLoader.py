import os
import subprocess
import sys
import time

TARGET_DIR = r"C:\NicCent\Python"

def main():
    if not os.path.isdir(TARGET_DIR):
        print(f"Directory not found: {TARGET_DIR}")
        sys.exit(1)

    py_files = [f for f in os.listdir(TARGET_DIR) if f.endswith(".py")]

    if not py_files:
        print("No .py files found in", TARGET_DIR)
        sys.exit(0)

    print(f"Found {len(py_files)} Python file(s), launching...\n")

    processes = []
    for file in py_files:
        filepath = os.path.join(TARGET_DIR, file)
        print(f"[Start] {file}")
        p = subprocess.Popen(
            [sys.executable, filepath],
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
        )
        processes.append((file, p))

    print("\nAll processes launched. Collecting output...\n")

    while processes:
        for name, proc in processes[:]:
            ret = proc.poll()
            if ret is not None:
                for line in proc.stdout:
                    print(f"[{name}] {line}", end="")
                print(f"[Exit] {name} (code {ret})\n")
                processes.remove((name, proc))

        for name, proc in processes:
            try:
                for line in iter(proc.stdout.readline, ""):
                    print(f"[{name}] {line}", end="")
            except ValueError:
                pass

        time.sleep(0.05)

    print("All Python scripts finished.")

if __name__ == "__main__":
    main()