#!/bin/bash

CPPCHECK_REPORT_FILE="cppcheck_report.xml"

# Run cppcheck
cppcheck \
    --enable=all `# Enable all possible errors` \
    -I include/ `# Custom include directory path` \
    --inconclusive \
    --std=c++14 `# Use the C++14 standard` \
    --suppress=missingIncludeSystem `# Ignore missing system files` \
    -q `# No output in the terminal` \
    --xml-version=2 \
    --xml \
    src/ include/ main.cpp `# Places to look for code` \
    2> "$CPPCHECK_REPORT_FILE" `# Output result to a file`

ERROR_COUNT=$(grep -c "<error" "$CPPCHECK_REPORT_FILE")
echo "cppcheck found '$ERROR_COUNT' errors"

# if [ "$ERROR_COUNT" -gt 0 ] ; then
#     echo "See file './$CPPCHECK_REPORT_FILE' for details"
# fi
