#!/bin/bash
# This script runs cppcheck on all hpp, tpp, cpp files
# in the project and outputs an xml report file in the
# reports folder. Lastly it prints how many errors were found.

CPPCHECK_REPORT_FILE="reports/cppcheck_report.xml"

# Make sure reports directory exists
mkdir reports -p

# Run cppcheck
cppcheck \
    --enable=all `# Enable all possible errors` \
    -I include/ `# Custom include directory path` \
    --inconclusive \
    --std=c++14 `# Use the C++14 standard` \
    --suppress-xml=./scripts/assessments/cppcheck_suspressions.xml \
    -q `# No output in the terminal` \
    --xml-version=2 \
    --xml \
    src/ include/ main.cpp `# Places to look for code` \
    2> "$CPPCHECK_REPORT_FILE" `# Output result to a file`

ERROR_COUNT=$(grep -c "<error id" "$CPPCHECK_REPORT_FILE")
echo "cppcheck found '$ERROR_COUNT' errors"
