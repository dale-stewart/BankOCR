BankOCR
=======

Bank OCR Kata

This project uses the waf build system.

https://code.google.com/p/waf/

To build the project for the first time, type:

```
  waf configure build
```

Subsequent builds just require:

```
  waf build
```
To erase all build artifacts, type:

```
  waf distclean
```

For further guidance, type:

```
  waf --help
```

This project also uses Google Mock as test framework, which also includes Google Test in its entirety.

https://code.google.com/p/googlemock/
https://code.google.com/p/googletest/

All build artifacts are created in the build/ subdiirectory.

The build executes the unit tests and indicates pass/fail status.

To see the full output from the unit tests, type:

```
    build/test
```

To see output for the first story in the kata:

```
    build/story1
```

To see output for the third story in the kata:

```
    build/story3
```

Likewise for story 4:

```
    build/story4
```
