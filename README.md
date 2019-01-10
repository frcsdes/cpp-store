# cpp-store

> A prototype for sharing state in a C++ application through a variables store

## Disclaimer

This is an experiment with various C++ patterns; their usage might neither be correct nor required. Usage in an application of yours should be **for testing purposes only**.

The idea is to let a *singleton* class `Store` manage variables that can be reused everywhere in the code. A custom store should inherit from `Store<MyStore>` using *CRTP* and be populated with proxy variables that hold a value. The value can be retrieved, changed, and the new value dispatched to subscribing *functors*.

## Test the Qt demo
* Qt5 is required as the demo uses the new signal / slot syntax
* Build using CMake and run

## Use in your application
* Standalone headers are in `include/`
* Have `MyStore` inherit `Store<MyStore>`
* Add `Variable<T>` members in `MyStore`
* Get the value through the implicit conversion to `const T`
* Set the value through `setter()(T)`
* Subscribe to modifications using `subscribe(void(T))`
