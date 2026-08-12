import subprocess
import re
import csv
import os
import sys

EXECUTABLE_PATH = "./build/test"

def run_benchmark():
    if not os.path.exists(EXECUTABLE_PATH):
        print(f"Error: Executable '{EXECUTABLE_PATH}' not found. Please compile your C++ code first.")
        sys.exit(1)

    pattern = re.compile(r"result\s+<([^>]+)>\s*:\s*\d+\s*\|\s*duration\s*:\s*([\d.e+-]+)")
    results: list[dict[str, float | int]] = []

    # Terminal Header for Live Sampling (6 options)
    print(f"{'N':>3} | {'Recursion (µs)':>15} | {'Memo (µs)':>10} | {'Heap (µs)':>10} | {'Stack (µs)':>10} | {'Ints (µs)':>10} | {'CompileTime (µs)':>16}")
    print("-" * 93)

    for n in range(1, 41):
        process = subprocess.run(
            [EXECUTABLE_PATH],
            input=f"{n}\n",
            capture_output=True,
            text=True
        )

        matches = pattern.findall(process.stdout)
        if not matches:
            print(f"Warning: Could not parse output for N = {n}")
            continue

        row: dict[str, float | int] = {"N": n}
        for algo_name, duration_str in matches:
            row[algo_name.strip()] = float(duration_str)

        results.append(row)

        # Retrieve sampled timings for all 6 approaches
        rec = float(row.get("pure recursion", 0.0))
        memo = float(row.get("memoization", 0.0))
        heap = float(row.get("tabulation - heap", 0.0))
        stack = float(row.get("tabulation - stack", 0.0))
        ints = float(row.get("tabulation - ints", 0.0))
        constexpr_time = float(row.get("compile time", 0.0))

        # Print all 6 sampled timing metrics live to console
        print(f"{n:3d} | {rec:15.2f} | {memo:10.2f} | {heap:10.2f} | {stack:10.2f} | {ints:10.2f} | {constexpr_time:16.2f}")

    # Export to CSV for Excel plotting
    csv_filename = "benchmark_results.csv"
    fieldnames = [
        "N", 
        "pure recursion", 
        "memoization", 
        "tabulation - heap", 
        "tabulation - stack", 
        "tabulation - ints",
        "compile time"
    ]

    with open(csv_filename, mode="w", newline="") as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(results)

    print("-" * 93)
    print(f"SUCCESS: All 6 timing metrics saved to '{csv_filename}'")

if __name__ == "__main__":
    run_benchmark()
