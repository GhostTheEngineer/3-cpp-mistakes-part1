#!/bin/bash

# Set script to UTF-8 encoding
export LANG=en_US.UTF-8

echo "============================="
echo "  5 C++ Misconceptions"
echo "============================="

# List all item_*.cpp files
count=0
declare -A files

for f in src/item*.cpp; do
    if [[ -f "$f" ]]; then
        ((count++))
        files[$count]="$f"
        echo "$count. $f"
    fi
done

exit_val=$((count + 1))
echo "$exit_val. Exit"

# If no files found, exit
if [[ $count -eq 0 ]]; then
    echo "No C++ source files found."
    read -p "Press enter to exit..."
    exit 1
fi

# Get user input
echo
read -p "Enter number of file to compile and run: " choice

if [[ "$choice" -eq "$exit_val" ]]; then
    echo "Exiting..."
    read -p "Press enter to exit..."
    clear
    exit 0
fi

# Validate input
if [[ -z "${files[$choice]}" ]]; then
    echo "Invalid choice. Exiting..."
    read -p "Press enter to exit..."
    exit 1
fi

filename="${files[$choice]}"

# Compile the selected file
echo "Compiling $filename..."
g++ -std=c++17 -o program "$filename"

# Check if compilation was successful
if [[ $? -ne 0 ]]; then
    echo "Compilation failed."
    read -p "Press enter to exit..."
    exit 1
fi

# Run the compiled program
echo "Running program..."
echo "------------------------------------------------"
./program
echo "------------------------------------------------"

# Pause before closing
read -p "Press enter to continue..."

# Clear screen
clear
