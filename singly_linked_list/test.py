#!/usr/bin/env python3
import subprocess
import os
import sys

def run_comprehensive_tests():
    executable_path = os.path.join(".", "build", "list")
    
    if not os.path.exists(executable_path):
        print(f" Error: Executable not found at {executable_path}. Compile first!")
        sys.exit(1)
        
    print(f" Launching Extended Test Suite...\n")
    
    try:
        result = subprocess.run([executable_path], capture_output=True, text=True, check=True)
        actual_output = result.stdout
        
        # This matches the strict outputs of main.cpp segments
        expected_lines = [
            "[Test 1: Core Operations]",
            "initial size : 0",
            "peek front : 91",
            "size after pop : 1",
            "[Test 2: Bounds Checking]",
            "Caught expected exception: pop_front attempted on an empty list.",
            "[Test 3: Deep Copying]",
            "Original size: 2, Copied size: 2",
            "After modifying copy - Original peek: Python, Copied peek: C++",
            "[Test 4: Move Semantics]",
            "Moved-to size: 2, Moved-from empty: true"
        ]
        
        print("--- Executable Output Log ---")
        print(actual_output.strip())
        print("-----------------------------\n")
        
        # Verify if every expected milestone line exists in the output
        passed = True
        for line in expected_lines:
            if line not in actual_output:
                print(f" MISSING EXPECTED OUTPUT: '{line}'")
                passed = False
                
        if passed:
            print(" ALL CAPABILITY TESTS PASSED: Deep copy, move semantics, exceptions, and size metrics are perfect!")
            return True
        else:
            print(" TEST SUITE FAILED: Content validation error.")
            return False
            
    except subprocess.CalledProcessError as error:
        print(f" Test Crash! Process failure: {error.returncode}")
        return False

if __name__ == "__main__":
    success = run_comprehensive_tests()
    sys.exit(0 if success else 1)
