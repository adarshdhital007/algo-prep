@echo off

for /D %%F in (*) do (
    rd /s /q "%%F"
    mkdir "%%F"
)
