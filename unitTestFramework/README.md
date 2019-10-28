### UnitTestFramework properties ###

1) If an assertion is triggered, its arguments are displayed in the console.
2) Test output does not mix with main program output.
3) Each time the program starts, all unit tests are performed.
4) If at least one unit test crashes, the program terminates with a zero return code.

Ho to use Unit Test Framework?
```objectivec
void TestAll() {
    TestRunner tr;
}

int main() {
    TestAll();
}
```

Ho to add Unit Test?
```objectivec
void TestSomething() {
    AssertEqual(..., ...);
}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestSomething, "TestSomething");
}

int main() {
    TestAll();
}
```