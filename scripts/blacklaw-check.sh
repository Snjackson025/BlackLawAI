#!/bin/bash
# Local check for BlackLawAI9: compile and run a scripted session.
# Usage: run from the repo root (where BlackLawAI.cpp lives).
set -e
cd "$(dirname "$0")/.."
echo "== Compile =="
g++ -std=c++17 -Wall -Wextra -o /tmp/blacklaw-check/blacklaw9-local BlackLawAI.cpp
echo "== Run =="
printf '1\n3\nTest Case\nTC-001\nMichigan\n4\nContract\nBreach of contract claim\nMichigan\n5\nSigned Agreement\nWritten contract dated Jan 2025\n2025-01-15\nClient files\n6\n2025-01-15\nContract signed\n7\n8\n9\nWhat are my rights?\n0\n' | /tmp/blacklaw-check/blacklaw9-local > /tmp/blacklaw-check/blacklaw9-output.txt
cat /tmp/blacklaw-check/blacklaw9-output.txt
grep -q "BLACKLAWAI9 LEGAL INTELLIGENCE ENGINE" /tmp/blacklaw-check/blacklaw9-output.txt || { echo "FAIL: missing banner"; exit 1; }
grep -q "Case created successfully." /tmp/blacklaw-check/blacklaw9-output.txt || { echo "FAIL: case not created"; exit 1; }
grep -q "ANALYSIS STATUS: ORGANIZED" /tmp/blacklaw-check/blacklaw9-output.txt || { echo "FAIL: analysis missing"; exit 1; }
grep -q "BlackLawAI9 shutting down." /tmp/blacklaw-check/blacklaw9-output.txt || { echo "FAIL: no clean shutdown"; exit 1; }
echo "ALL CHECKS PASSED"
