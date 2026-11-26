# BlackLawAI — Workflow

## What it is
BlackLawAI9 is a legal intelligence and case-analysis engine (v9.0).
It organizes case files — legal issues, evidence, and timelines — and
analyzes the latest case, with a research framework and a question
assistant. Jurisdiction defaults to Michigan / United States and can be
changed from the menu. Menu: 1 introduce, 2 change jurisdiction,
3 create case file, 4 add legal issue, 5 add evidence, 6 add timeline
event, 7 analyze latest case, 8 legal research framework,
9 ask BlackLawAI9, 0 exit.

Note: the repo previously held a tensor-memory version of BlackLawAI.
Saul chose BlackLawAI9 to replace it on 2026-11-26; the tensor version
remains in the repo's git history.

## Files
- `BlackLawAI.cpp` — the program (BlackLawAI9Engine, menu-driven)
- `BlackLawAI.vcxproj` — builds only `BlackLawAI.cpp`, C++17, v143 toolset

## Workflow
`.github/workflows/build-and-test.yml` builds Debug x64 with MSBuild (no
`|| echo` — a failed build fails the run) and runs a scripted session
through the menu, failing unless the output contains the engine banner,
"Case created successfully.", "ANALYSIS STATUS: ORGANIZED", and
"BlackLawAI9 shutting down.". It also runs daily at 06:00 UTC.

Muse cannot write workflow files to GitHub directly, so Saul replaces
`.github/workflows/build-and-test.yml` via the GitHub web UI.

## Local check
`scripts/blacklaw-check.sh` compiles with g++ and runs the same scripted
session, checking the banner, case creation, analysis, and shutdown.
