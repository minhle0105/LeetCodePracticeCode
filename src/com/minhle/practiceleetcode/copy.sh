#!/bin/bash

./GenerateFileName > output.txt

# Copy the contents of the temporary file to the clipboard
cat output.txt | pbcopy

# Clean up temporary files
rm output.txt
