# SSCC Validator

A small C++17 console application for validating SSCC barcode data according to the GS1-128 specification.

The application was created for the supplied TSX GmbH examples, using the GS1 company prefix:

`34260311`

This prefix is fixed intentionally to match the requirements of the assignment.

## Validation

The validator checks the scanned value in the following order:

1. Total length must be exactly 20 characters:

   * 2 digits for the Application Identifier
   * 18 digits for the SSCC
2. All characters must be numeric.
3. Application Identifier must be `00`.
4. GS1 company prefix must be `34260311`.
5. The GS1 check digit must be correct.

Validation stops on the first detected error and prints a descriptive message.

The FNC1 character is not expected in the input because it is interpreted by the barcode scanner and is not displayed in the scanned Notepad value.

## SSCC Structure

For this task, the scanned value has the following structure:

```text
AI | Extension Digit | Company Prefix | Serial Reference | Check Digit

00 |        0        |    34260311    |     13077659     |     4
```

The SSCC check digit is calculated using the GS1 Modulo 10 algorithm.

## Running the Application

After starting the application, all six examples supplied in the assignment are validated automatically.

The expected results are:

| Example | Scanned value | Result | Reason |
| --- | --- | --- | --- |
| 1 | `00034260311130776594` | Valid | — |
| 2 | `02044260311130776512` | Invalid | `Invalid AI: expected 00, got 02` |
| 3 | `00034260311130776144` | Invalid | `Invalid check digit: expected 3, got 4` |
| 4 | `00034260311130776570` | Valid | — |
| 5 | `0003426031113077646` | Invalid | `Invalid length: expected 20 characters, got 19` |
| 6 | `00034260321130774636` | Invalid | `Invalid company prefix: expected 34260311, got 34260321` |

The application then switches to interactive CLI mode:

```text
Enter SSCC code (or q to quit):
```

Enter an SSCC value to validate it.

Enter `q` to exit.

## Build Requirements

* C++17 compatible compiler
* CMake
* Tested with Microsoft Visual C++ / Visual Studio

## Windows Quick Start

If CMake is not installed or the `cmake` command is not available, install it from PowerShell or Windows Terminal:

```powershell
winget install --id Kitware.CMake -e
```

Close and reopen the terminal after installation, then verify that CMake is available:

```powershell
cmake --version
```

From the project root, configure and build the Debug version:

```powershell
cmake -S . -B build
cmake --build build --config Debug
```

Run the automated tests:

```powershell
ctest --test-dir build -C Debug --output-on-failure
```

A successful run should report:

```text
100% tests passed, 0 tests failed
```

Run the application:

```powershell
.\build\Debug\SSCC_validator.exe
```

If CMake cannot find the C++ compiler, open **Developer PowerShell for VS 2022**, navigate to the project directory, and repeat the configure and build commands.

## Tests

The project includes tests for:

* valid SSCC values
* invalid Application Identifier
* invalid check digit
* invalid input length
* invalid GS1 company prefix
* non-numeric characters

Tests are registered with CTest.

## Project Structure

```text
SSCC_validator/
├── main.cpp
├── SsccValidator.h
├── SsccValidator.cpp
├── CMakeLists.txt
└── tests/
    └── SsccValidatorTests.cpp
```
