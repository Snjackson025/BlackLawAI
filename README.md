# BlackLawAI

**BlackLawAI9 — a legal intelligence and case-analysis engine (v9.0).**

Organize a case into facts, issues, evidence, and timelines — then analyze
it. Jurisdiction defaults to Michigan / United States and can be changed
from the menu.

## What it does

- Create case files with a name, number, and jurisdiction
- Add legal issues (tracked as Under Review), evidence items, and timeline events
- Analyze the latest case: issues, evidence, and timeline in one report
- A legal research framework (identify the question, find the law, compare the facts, record what is missing)
- An assistant that answers questions about rights, evidence, and cases — with a clear note that this is legal information, not a verified legal opinion

Menu: `1` introduce, `2` change jurisdiction, `3` create case file,
`4` add legal issue, `5` add evidence, `6` add timeline event,
`7` analyze latest case, `8` legal research framework, `9` ask BlackLawAI9,
`0` exit.

## Build and run

Requires C++17. With Visual Studio, open `BlackLawAI.sln` and build
Debug x64. Or with g++:

```sh
g++ -std=c++17 -Wall -Wextra -o BlackLawAI BlackLawAI.cpp
./BlackLawAI
```

## Continuous integration

`.github/workflows/build-and-test.yml` builds Debug x64 with MSBuild and
runs a scripted menu session, checking the banner, case creation,
analysis, and clean shutdown. It also runs daily at 06:00 UTC.
