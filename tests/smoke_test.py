"""Integration checks using isolated temporary data and a C compiler."""
from pathlib import Path
import subprocess
import tempfile
ROOT = Path(__file__).resolve().parents[1]
with tempfile.TemporaryDirectory() as folder:
    work = Path(folder)
    exe = work / 'launch'
    subprocess.run(['gcc', '-std=c11', '-Wall', '-Wextra', '-Werror', '-pedantic', str(ROOT/'src/main.c'), '-o', str(exe)], check=True)
    def run(text):
        return subprocess.run([str(exe)], input=text, text=True, capture_output=True, cwd=work, timeout=5)
    first = run('1\nDemo User\n22\n00000000000\ndemo123\n2\n1\ndemo123\n3\n1\n1\n1\n0\n101\n7\n500\n3\n1\n1\n1\n7\n5\n4\n3\n')
    assert first.returncode == 0, first.stderr
    assert 'Booking confirmed:' in first.stdout
    assert 'Seat already booked' in first.stdout
    assert 'Total bill: BDT 500' in first.stdout
    assert 'Enter a whole number from 1 to 100' in first.stdout
    second = run('x\n2\n1\nwrong\n2\n100\nwrong\n2\n1\ndemo123\n5\n3\n2\n2\n2\n8\n500\n3\n2\n2\n2\n8\n900\n5\n4\n3\n')
    assert 'Invalid account number or password' in second.stdout
    assert 'Incorrect amount; booking not made.' in second.stdout
    assert 'Bhola-Barishal-Dhaka | 21/12/22 | Business | Seat 8' in second.stdout
    assert 'Total bill: BDT 1400' in second.stdout
    assert run('2\n1\ndemo123\n5\n4\n3\n').stdout.count('Total bill: BDT 1400') == 1
    assert run('').returncode == 0
    (work/'launch_data.txt').write_text('broken file\n')
    assert run('3\n').returncode == 1
print('PASS: signup, login, invalid input, booking, duplicate prevention, payment, bills, restart persistence, EOF, corrupt data.')
