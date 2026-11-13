"""Self-contained regression inputs for the eight independently built programs."""
import argparse
from pathlib import Path
import subprocess


CASES = [
    ("A", "4\n2\n0 0\n5\n7 7 1 3 2\n4\n8 2 7 1\n2\n1000000000 1000000000\n", "0\n14\n15\n2000000000\n"),
    ("B", "CACtus\nacac-end\nstus\nxxCACTUSyy\nplain   CAC-id\nflower", "4\n"),
    ("C", "2\n4\n-50000 -50000\n-50000 50000\n50000 50000\n50000 -50000\n6\n0 0\n0 3\n1 3\n1 1\n3 1\n3 0\n", "10000000000\n5\n"),
    ("D", "4 3 1\n1 2 2\n2 4 2\n1 3 5\n3\n", "14\n"),
    ("D", "3 5 2\n1 1 7\n1 2 9\n1 2 1\n2 3 2\n1 3 100\n1\n3\n", "3\n"),
    ("E", "6\n1 3 -2\n2\n1 -1 5\n2\n1 7 -4\n2\n", "3 -2\n-1 7\n3 7\n"),
    ("F", "FFFF\n2\n", "4\n"),
    ("F", "T\n1\n", "1\n"),
    ("F", "T\n2\n", "0\n"),
    ("F", "F" * 100 + "\n50\n", "100\n"),
    ("G", "7\n1 1\n1 16\n10 10\n2 4\n5 9\n10 7\n2305843009213693952 2305843009213693952\n",
     "1\n1\n10\n2\n5\n2\n2305843009213693952\n"),
    ("H", "0\n", " o\no o\n o\n"),
    ("H", "1\n", " o  o\no oo o\n o  o\n o  o\no oo o\n o  o\n"),
]


def run(directory, program, input_text):
    binary = (directory / program).resolve()
    result = subprocess.run([str(binary)], input=input_text.encode("ascii"),
                            stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=10)
    if result.returncode != 0:
        raise AssertionError(program + " failed: " + result.stderr.decode("utf-8", errors="replace"))
    return result.stdout.decode("ascii")


def normalize(text):
    return "\n".join(line.rstrip() for line in text.splitlines())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--bin-dir", type=Path, default=Path("build"))
    args = parser.parse_args()
    for index, (program, input_text, expected) in enumerate(CASES, 1):
        actual = run(args.bin_dir, program, input_text)
        if normalize(actual) != normalize(expected):
            raise AssertionError("Case %d (%s): expected %r, got %r" % (index, program, expected, actual))
    lines = run(args.bin_dir, "H", "6\n").splitlines()
    assert len(lines) == 562 and max(map(len, lines)) <= 562
    assert sum(line.count("o") for line in lines) == 4 ** 7
    padded = [line.ljust(562) for line in lines]
    assert all(line == line[::-1] for line in padded) and padded == padded[::-1]
    print("PASS: %d regression cases across 8 C programs" % (len(CASES) + 1))


if __name__ == "__main__":
    main()
